/* 
                    UNIVERSIDAD TECNICA DEL NORTE
                            FICA CIERCOM
                       SISTEMAS MICROPROCESADOS
   
   Autor: Stalin Ibarra
   Fecha: 04-02-2020
   
   Realizar un ejercicio que cada 2 segundos el sistema se encuentre activado 
   y cada 10 segundos el sistema baje su consumo de corriente. 
   Envíe mensajes de comunicación serial para mostrar el resultado.
*/


#include<avr/sleep.h>
#include<avr/power.h>
#include <avr/wdt.h>
#include<TimerOne.h>
#include<EEPROM.h>

int cont = 0;
int memoria;

void setup() {
  Serial.begin(9600);
  memoria = EEPROM.read(0);
  EEPROM.write(0, 1);
  
  attachInterrupt(0, wakeup1, LOW);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(conteo);
  
  set_sleep_mode(SLEEP_MODE_IDLE);  
  Serial.println(memoria);
}

void loop() {
  if (cont == 2 ) {              //Se activa y desactiva cada 2 seg
    Serial.println("ACTIVADO");      
    Serial.println(cont);
  }
  if (cont == 4) {                 
    Serial.println("DESACTIVADO");  //Se activa y desactiva cada 2 seg
    EEPROM.update(0, 0);
    sleep_mode();
    sleep_enable();
  } 
  if (cont == 10) {               // Alos 10 seg entra en modo de ahorro de energía
    sleep_disable();
    cont = 0;
  }
}

void conteo() {
  cont++;

}

void wakeup1() {
  sleep_disable();
  Serial.println("DESPERTE");
  cont = 0;
}
