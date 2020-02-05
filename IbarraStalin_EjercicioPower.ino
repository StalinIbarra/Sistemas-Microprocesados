/*
                    UNIVERSIDAD TECNICA DEL NORTE
                            FICA CIERCOM
                       SISTEMAS MICROPROCESADOS
   
   Autor: Stalin Ibarra
   Fecha: 04-02-2020
   
   Realizar un programa que cada 5 segundos el sistema desactiva 
   el conversor análogo digital, cada 8 segundos la comunicación 
   serial y cada 12 segundos un desactivación total.
   Esta información debe verse en una LCD. 
*/

#include <avr/wdt.h>
#include <avr/power.h>
#include <TimerOne.h>
#include <EEPROM.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int cont = 0;
int disp = 5;
int dato;
int dir = EEPROM.read(0);

void setup() {
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(conteo);            
  power_all_enable();                       //Activacion total
  lcd.begin(16, 2);
  dir = 0;
  
}

void loop() {
  Serial.println(dir);
  lcd.setCursor(12, 1);
  lcd.print("Tiempo:" + String(cont));
  dato = analogRead(0);
  lcd.setCursor(0, 1);
  lcd.print(dato);

  if (cont == 5) {                          //Apaga el conversor analogo digital
    dir = dir + 1;
    lcd.setCursor(0, 0);
    lcd.print("CAD OFF");
    power_adc_disable();
  }
  if (cont == 8) {                          //Apaga la comunicacion serial
    lcd.setCursor(0, 0);
    lcd.print("                     ");
    lcd.setCursor(0, 0);
    lcd.print("CX OFF");
    power_spi_disable();
  }
  if (cont == 12) {                        //Desactivacion total
    lcd.setCursor(0, 0);
    lcd.print("                    ");
    lcd.setCursor(0, 0);
    lcd.print("SIST DESACTIVADO");
    power_all_disable();
  }
  if (EEPROM.read(0) > 12) {
    dir = 0;
    power_all_enable();
    EEPROM.write(0, dir);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("REINICIO");
    digitalWrite(disp, HIGH);
    delay(10);
    wdt_enable(WDTO_1S);
  }  
}

void conteo() {
  cont++;
}
