#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x27 for a 16x2 display

const int buzzer_Pin = 8;
const int led_Pin = 9;
char sleep_status = 0;

void setup() {
  Serial.begin(9600);  
  pinMode(buzzer_Pin, OUTPUT);
  pinMode(led_Pin, OUTPUT);
  lcd.init(); // Initialize the LCD
  lcd.backlight(); // Turn on the backlight
  lcd.print("Driver Sleep ");
  lcd.setCursor(0, 1);
  lcd.print("Detection SYSTEM");
  digitalWrite(buzzer_Pin, LOW); 
  digitalWrite(led_Pin, LOW);
}

void loop() {
  while (Serial.available() > 0) {
    sleep_status = Serial.read();
    if (sleep_status == 'a') { 
      lcd.clear();
      lcd.print("Please wake up");
      digitalWrite(buzzer_Pin, HIGH); 
      digitalWrite(led_Pin, HIGH);
      delay(2000);
      digitalWrite(buzzer_Pin, LOW); 
      digitalWrite(led_Pin, LOW);
      delay(100);
    } else if (sleep_status == 'b') {
      lcd.clear();
      lcd.print("All Ok");
      lcd.setCursor(0, 1);
      lcd.print("Drive Safe");
      digitalWrite(buzzer_Pin, LOW); 
      digitalWrite(led_Pin, LOW);
      delay(2000);
    } else {
      /* Do Nothing */
    }
  }
}
