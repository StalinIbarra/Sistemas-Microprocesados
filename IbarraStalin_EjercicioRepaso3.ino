/*
 *  UNIVERSIDAD TÉCNICA DEL NORTE
 *         FICA-CIERCOM
 *    Sistemas microprocesados
 *   
 *  Autor: Stalin Ibarra
 *  Docente: Ing.Paul Rosero
 *  Fecha: 2/12/2019
 */


String option;                // Variable para escoger una opcion

void setup() {
  
for(int i=5;i<=9;i++){
  pinMode(i, OUTPUT);          //pines de salida
}
Serial.begin(9600);            //Inicializa el serial
Serial.println("Escoga una opcion presionando la secuencia indicada:");
Serial.println("1. ACBF - Juego luces 1");
Serial.println("2. ACGF - Juego luces 2");
Serial.println("3. ADBF - Juego luces 3");
Serial.println("4. ADBH - Juego luces 4");

}

void loop() {
 
 if(Serial.available()>0){          //Condicion para que corra solo si lee algun dato 
   option=Serial.readString();
   Serial.println("Opcion escogida: " +option);
 if((option!="ACBF")&&(option!="ACGF")&&(option!="ADBF")&&(option!="ADBH")){ //Si la opcion es incorrrecta envia un mensaje
  Serial.println("Opcion incorrecta");
  delay(200);
  Serial.println("Elija una de las secuencias indicadas");
 }
 }
 if(option=="ACBF"){ //Llama al primer juego de luces
    secuencia1();
    delay(200);
 }
 if(option=="ACGF"){  //Llama al segundo juego de luces
    secuencia2();
    delay(200);
 }
 if(option=="ADBF"){   //Llama al tercer juego de luces
    secuencia3();
    delay(200);
 }
 if(option=="ADBH"){  //Llama al cuarto juego de luces
    secuencia4();
    delay(200);
 }
}

void secuencia1(){                 //primer juego de luces: enciende numeros impares
  for (int i=5; i<=9; i=i+2){ 
    digitalWrite(i,HIGH);
    delay(200);
    digitalWrite(i,LOW);
    delay(200);
  }
}

void secuencia2(){                 //segundo juego de luces: enciende mitad alternando
 int k=11;
  for(int i=2; i<=5;i++){
    digitalWrite(i,HIGH);
    digitalWrite(k-i,LOW);
  }
   delay(200);
  for(int i=2; i<=5;i++){
    digitalWrite(i,LOW);
    digitalWrite(k-i,HIGH);
  }
   delay(200);
}

void secuencia3(){                  //tercer juego de luces: enciende y apaga de forma ascendente
  int k=11; // inicializo una variable auxiliar K
  for(int i=6; i<=9;i++){ //leo de 6 a 9
    digitalWrite(i, HIGH); // prendo pin actual
    digitalWrite(k-i, HIGH); // prendo pin de la diferencia 11-6 = 5
    delay(100); //retardo
  }
  for(int i=9; i>=5;i--){ // Al contrario de lo anterior
    digitalWrite(i, LOW);
    digitalWrite(k-i, LOW);
    delay(100);
  }
}

void secuencia4(){                //cuatrto juego de luces: enciende numeros pares
  for(int i=8; i>=5; i=i-2){
   digitalWrite(i,HIGH);
    delay(200);
    digitalWrite(i,LOW);
    delay(200);
  }
}
