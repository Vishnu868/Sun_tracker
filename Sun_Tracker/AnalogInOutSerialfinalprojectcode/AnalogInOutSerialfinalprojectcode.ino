#include <Wire.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

Servo horizontal;
Servo vertical;

int servoh = 200;
int servov = 220;

int servohLimitHigh = 360;
int servohLimitLow = 0;
int servovLimitHigh = 220;
int servovLimitLow = 0;

int ldrlt = A0; 
int ldrrt = A3; 
int ldrld = A1; 
int ldrrd = A2; 
void setup() {
  Serial.begin(9600);

  horizontal.attach(9); 
  vertical.attach(10); 

  horizontal.write(servoh);
  vertical.write(servov);
  delay(2500);

  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Voltage: ");
}

void loop() {
  int lt = analogRead(ldrlt);
  int rt = analogRead(ldrrt);
  int ld = analogRead(ldrld); 
  int rd = analogRead(ldrrd); 
  int dtime = 10; 
  int tol = 90; 
  int avt = (lt + rt) / 2;
  int avd = (ld + rd) / 2; 
  int avl = (lt + ld) / 2; 
  int avr = (rt + rd) / 2;
  int dvert = avt - avd;
  int dhoriz = avl - avr; 
  Serial.print("lt: "); Serial.print(lt);
  Serial.print(" rt: "); Serial.print(rt);
  Serial.print(" ld: "); Serial.print(ld);
  Serial.print(" rd: "); Serial.println(rd);

  if (-1 * tol > dvert || dvert > tol) {
    if (avt > avd) {
      servov = ++servov;
      if (servov > servovLimitHigh) {
        servov = servovLimitHigh;
      }
    } else if (avt < avd) {
      servov = --servov;
      if (servov < servovLimitLow) {
        servov = servovLimitLow;
      }
    }
    vertical.write(servov);
  }

  if (-1 * tol > dhoriz || dhoriz > tol) {
    if (avl > avr) {
      servoh = --servoh;
      if (servoh < servohLimitLow) {
        servoh = servohLimitLow;
      }
    } else if (avl < avr) {
      servoh = ++servoh;
      if (servoh > servohLimitHigh) {
        servoh = servohLimitHigh;
      }
    } else if (avl == avr) {
      delay(5000);
    }
    horizontal.write(servoh);
  }

  Serial.print("servoh: "); Serial.print(servoh);
  Serial.print(" servov: "); Serial.println(servov);

  int solarPanelVoltage = analogRead(A4); 
  float voltage = solarPanelVoltage * (5.0 / 1023.0);
  lcd.setCursor(9, 0);
  lcd.print(voltage);
  lcd.print("V  ");

  delay(10);
}
