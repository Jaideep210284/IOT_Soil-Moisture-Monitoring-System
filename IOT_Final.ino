#include <Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int sensor_pin = A0;       //Sensor Pin
int relay_pin = 7;         //Relay Pin

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  lcd.begin(20,4);
  lcd.backlight();
  lcd.setBacklight(HIGH);
  pinMode(sensor_pin, INPUT);
  pinMode(relay_pin, OUTPUT);
}

void loop()
{
  int sensor_data = analogRead(sensor_pin);
 Serial.print("Sensor_data:");
 Serial.print(sensor_data);
 Serial.print("\t | ");
  
  if(sensor_data > 950)
  {
    Serial.println("No moisture, Soil is dry");
    digitalWrite(relay_pin, LOW);
    lcd.setCursor(0,0);
    lcd.print("Soil_Dry");
    lcd.setCursor(0,1);
    lcd.print("Motor  ON");
  }
  else if(sensor_data >= 400 && sensor_data <= 950)
  {
   // Serial.println(" Soil moisture is medium");
    digitalWrite(relay_pin, HIGH);
    lcd.setCursor(0,20);
    lcd.print("Soil_Medium");
    lcd.setCursor(1,10);
    lcd.print("Motor_OFF");
  }
  else if(sensor_data < 400)
  {
    Serial.println("Soil_is_wet");
    digitalWrite(relay_pin, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Soil Wet");
    lcd.setCursor(0,1);
    lcd.print("Motor OFF");
  }

  delay(100);
}
