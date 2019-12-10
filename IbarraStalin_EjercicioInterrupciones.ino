/*
 *     UNIVERSIDAD TECNICA DEL NORTE
 *            FICA-CIERCOM
 *       SISTEMAS MICROPROCESADOS
 *  
 *  Autor: Stalin Ibarra
 *  Docente: Ing. Paul Rosero
 */

int modos=0;
String dato;
int cont=0;
int option, j;
int i=0;

void setup() {
  attachInterrupt(0, on, LOW);                           // Interrupcion para activar el sistema
  attachInterrupt(1,seleccion,LOW);                      // Interrupcion par ingresar los numeros
  Serial.begin(9600);
  Serial.println("Presione el boton1 para encender el sistema");
}

void loop() {
  if((modos==1) && (cont==1)){
   if(Serial.available()>0){                             //Solo inicia si cumple las condiciones y se ha ingresado algo en el serial
      dato=Serial.readString();                         
      Serial.println("");
      Serial.println("Numeros ingresados:");
      Serial.println(String(dato));
      Serial.println("");
      Serial.println("Presione el boton1 para ordenar de menor a mayor");
   }
  }
  
  if((modos==2) && (dato !="")){                   //En caso de no haber ingresado nada no correra el programa 
     int vector[dato.length()];
     for(;i<dato.length();i++){
        int num=dato.substring(i,(i+1)).toInt();   // Los datos ingresados se convierten a enteros 
        vector[i]=num;                             // Y se guardan en un vector
     }
    do{
      option=0;                                  // Ciclo burbuja para ordenar de menor a mayor comparando los datos ingresados de 2 en 2
      for (i = 0; i < dato.length(); i++) {
        if(vector[i]>vector[i+1]){
          option=1;
          j=vector[i];
          vector[i]=vector[i+1];
          vector[i+1]=j;
        }
      }
    }
    while(option);
    for(i = 0; i < dato.length(); i++){
      Serial.print(vector[i]);
    }
    dato="";
  }
}

void on(){
  switch(modos){
    case 0:
      Serial.println("");
      Serial.println("SISTEMA ENCENDIDO");
      Serial.println("Para ingresar datos presione el boton2");
      modos++;
    break;
    case 1:
      Serial.println("");
      Serial.println("Numeros ordenados");
      modos++;
    break;
    case 2:
      Serial.println("");
      Serial.println("SISTEMA APAGADO");
      modos=0;
      cont=0;
      i=0;
    break;
  }
}

void seleccion(){
    if(modos==1){
      Serial.println("");
      Serial.println("Ingrese los numeros");
      cont++;
    }
    else{
      Serial.println("");
      Serial.println("Opcion no permitida");
    }
}
