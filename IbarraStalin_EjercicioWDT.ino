/*
                    UNIVERSIDAD TECNICA DEL NORTE
                            FICA CIERCOM
                       SISTEMAS MICROPROCESADOS
   
   Autor: Stalin Ibarra
   Fecha: 04-02-2020
     
   Realizar un programa que mediante comunicación serial ingrese 
   el tiempo de reset del arduino de la siguiente forma: 
   A-> 1 s B-> 2s C-> 4s D-> 8s
   Hay que tener en cuenta que el sistema puede ser re configurado 
   las veces necesarias(interrupciones) 
*/

#include <EEPROM.h>
#include <TimerOne.h>
#include <avr/wdt.h>

String tiempo;
int cont = 0;
int on = 0;
int in = 0;

void setup() {
  Serial.begin(9600);
  attachInterrupt(0, menu, LOW);
  attachInterrupt(1, inicio, LOW);
  Serial.println("Sistema Wdt");
  Serial.println("Presione la Interrupcion 2 para activar");
  Timer1.stop();
  cont = 0;
  in=0;
  tiempo=" ";

}

void loop() {
  if (on == 1) {
    if (Serial.available() > 0 ) {
      tiempo = Serial.readString();
      Timer1.initialize(1000000);
      Timer1.attachInterrupt(conteo);
    }
   
  }
}

void menu() {
  switch (on) {
    case 0:
      Serial.println("Ingrese el tiempo");
      on++;
      break;
    case 1:
      Serial.println(" ");
      on = 0;
      break;

  }
}
void conteo() {
  cont++;
 if(in==1){
 if(tiempo=="A"){
     Serial.println(String(2-cont));
    }
    if(tiempo=="B"){
     Serial.println(String(3-cont));
    }
    if(tiempo=="C"){
     Serial.println(String(5-cont));
    }
    if(tiempo=="D"){
     Serial.println(String(9-cont));
    }
 }
}
void inicio() {
  in++;
  if (tiempo == "A" && in == 1) {
    Serial.println("Reinicio 1S");
    wdt_enable(WDTO_1S);
  }
  if (tiempo == "B" && in == 1) {
    Serial.println("Reinicio 2S");
    wdt_enable(WDTO_2S);
  }
  if (tiempo == "C" && in == 1) {
    Serial.println("Reinicio 4S");
    wdt_enable(WDTO_4S);
  }
  if (tiempo == "D" && in == 1) {
    Serial.println("Reinicio 8S");
    wdt_enable(WDTO_8S);
  }
}
