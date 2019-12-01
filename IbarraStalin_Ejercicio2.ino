/*
 * UNIVERSIDAD TECNICA DEL NORTE
 * EJERCICIO DE REPASO
 * AUTOR: STALIN IBARRA
 * 
 */

int leds[8]={6,7,8,9,10,11,12,13};    //Pines de salida a los LED's
int i,j;                              //j será la variable con la que se hace las operaciones
int dato;                             //variable en la que se almacenará el dato ingresado

void setup() {
 
  Serial.begin(9600);
  for(i=0; i<=8;i++){
  pinMode(leds[i],OUTPUT);              
  }
  Serial.println("Ingrese un numero entre 0-255");
}

void loop() {
  
   if(Serial.available()>0){
    dato=Serial.readString().toInt();     //Conversion del dato ingresado por serial a entero
    Serial.println(dato);                 //Impresión por pantalla del dato ingresado
  }
   if(dato>=0 && dato<=255){              //Rango de conversion a binario con 8 bits 
    j=dato;
    for(i=0;i<8;i++){
      if(j%2==1){                         //Se toma el residuo de la division si es uno se enciende los leds
        digitalWrite(leds[i], HIGH);
      }
      else{
        digitalWrite(leds[i], LOW);       //Si el residuo es cero se apagan los leds
      }
      j=j/2; 
    }
  }
  else{
    Serial.println("Numero fuera de rango");
  }delay(2000);
}
