#include <avr/io.h>
#include <util/delay.h>

#define sensor_pin 0  // A0
#define relay_pin 7

void init_ADC() {
    // Set reference voltage to AVcc, and enable ADC with a prescaler of 128
    ADMUX = (1 << REFS0);
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

int read_ADC() {
    // Start ADC conversion
    ADCSRA |= (1 << ADSC);
    
    // Wait for conversion to complete
    while (ADCSRA & (1 << ADSC));
    
    return ADC;
}

void init_GPIO() {
    // Set relay_pin as an output
    DDRD |= (1 << relay_pin);
}

void init_UART() {
    // Set baud rate to 9600
    UBRR0H = (unsigned char)(103 >> 8);
    UBRR0L = (unsigned char)103;
    
    // Enable transmitter
    UCSR0B = (1 << TXEN0);
    
    // Set frame format: 8 data bits, 1 stop bit, no parity
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void send_UART(char data) {
    // Wait for the empty transmit buffer
    while (!(UCSR0A & (1 << UDRE0)));
    
    // Put the data into the buffer
    UDR0 = data;
}

void send_str_UART(const char *str) {
    // Loop through each character in the string and send it
    while (*str != '\0') {
        send_UART(*str);
        str++;
    }
}

int main(void) {
    init_ADC();
    init_GPIO();
    init_UART();
    
    while (1) {
        int sensor_data = read_ADC();
        
        send_str_UART("Sensor_data: ");
        send_UART((char)(sensor_data / 1000) + '0');
        send_UART(((char)(sensor_data / 100) % 10) + '0');
        send_UART(((char)(sensor_data / 10) % 10) + '0');
        send_UART((char)(sensor_data % 10) + '0');
        send_str_UART("\t | ");
        
        if (sensor_data > 500) {
            send_str_UART("No moisture, Soil is dry\n");
            PORTD &= ~(1 << relay_pin);
            
        } else if (sensor_data < 500) {
            send_str_UART("Soil is wet\n");
            PORTD |= (1 << relay_pin);
            
        }

        _delay_ms(100);
    }
    
    return 0;
}
