/*
 * UNIVERSIDAD TECNICA DEL NORTE
 * EJERCICIO LCD
 * AUTOR: STALIN IBARRA
 * 
 */
#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8); 
String dato;
String palabra;
int i=0;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
}
void loop() {
  lcd.setCursor(0, 0);
  lcd.print("INGRESE PALABRA");
  if (Serial.available() > 0) {
    dato = Serial.readString();
    lcd.setCursor(0, 0);
    lcd.print("               ");
    lcd.setCursor(0, 0);
    for (i = 0; i < dato.length(); i++) {
      palabra = palabra + dato.substring(i, i + 1);
    }
    lcd.print(palabra);
    delay(2000);
    for (; i < 16 ; i++) {
      lcd.scrollDisplayRight();
      delay(500);
    }
    for (; i < 16 ; i++) {
      lcd.scrollDisplayLeft();
      delay(500);
    }
  }
  dato = "";
  palabra = "";
}
