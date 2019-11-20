//LABORATORIO 1 
//AUTORES: CONDOR MAX, IBARRA STALIN, VINUEZA ISRAEL
//DOCENTE: PAUL ROSERO
// Realizar un sistema que realiCE un contador de personas al ingresar y salir del aula.
int led1;
int sensor1 = 3 ; //Pin de entrada que contabiliza el numero de estudiantes que ingresan a la aula
int sensor2 = 4 ; //Pin de entrada que contabiliza el numero de estudiantes que salen del Aula
int displayUnidad = 5 ; //Pin de entrada que activa el display que contabiliza las unidades del total de los estudiantes
int displayDecena = 6 ; //Pin de entrada que activa el display que contabiliza las unidades  del total de los estudiantes
int contadorSensores ; //Variable que almacena el numero de estudiantes que entran a la clase
int unidad ; //Variable que representa las unidades de los estudiantes que entran a la clase
int decena ; //Variable que representa las decenas de los estudiantes que entran a la clase
int estadoA = 7 ; //Pin de salida que representa la primera posicion del numero binario 
int estadoB = 8 ; //Pin de salida que representa la segunda posicion del numero binario 
int estadoC= 9 ;  //Pin de salida que representa la tercera posicion del numero binario 
int estadoD= 10 ; //Pin de salida que representa la cuarta posicion del numero binario 

void setup() {
  pinMode (12, OUTPUT);
  pinMode (11, OUTPUT);
  pinMode (3,INPUT) ; //Pin de entrada de la fotoresistencia que capta la entrada de los estudiantes
  pinMode (4,INPUT) ; //Pin de entrada de la fotosresitencia que capta la salida de los estudiantes
  pinMode (5,OUTPUT) ; //Pin de salida que permite encender el display de las unidades de la cantidad de estudiantes que se enecuentran en clase
  pinMode (6,OUTPUT) ;//Pin de salida que permite encender el display de las decenas de la cantidad de estudiantes que se enecuentran en clase
  pinMode (7,OUTPUT) ;//Pin de salida que representa el primer posicion del numero binario
  pinMode (8,OUTPUT) ;//Pin de salida que representa la segundo posicion del numero binario
  pinMode (9,OUTPUT) ;//Pin de salida que representa la tercera posicion del numero binario
  pinMode (10,OUTPUT) ;//Pin de salida que representa la cuarta posicion del numero binario
  Serial.begin(9600) ; //Comando para asignar el tiempo de procesamiento de bits
}


void loop() {
  
  int estadoSensor1 = digitalRead (sensor1); //Declaracion de la variable para la actinvacion de la primera fotoresistencia
  int estadoSensor2= digitalRead (sensor2) ; //Declaracion de la variable para la actinvacion de la segunda fotoresistencia
 if (estadoSensor1== LOW && estadoSensor2==HIGH){
   digitalWrite(11, HIGH);
 }else {
  digitalWrite(11,LOW);
 }
  if (estadoSensor1== LOW && estadoSensor2==HIGH){ //Activacion del sensor de entradda
    delay (100) ;
     
    if (contadorSensores<99){ //Condición para iniciar el conteo de las estudiantes que ingresan al aula
      contadorSensores++ ; //Conteo de las personas que ingresan al aula
      delay (500) ; //Velocidad de proccesamiento en la opera el contador
      Serial.println(contadorSensores) ; //Impresión de la variable "contadorSensores" a través del terminal
      decena= contadorSensores/10 ; //Variable que contabiliza las decenas 
      unidad= contadorSensores-decena*10 ; //Variable que contabiliza las unidades

      digitalWrite (displayDecena,HIGH) ; //Activación del display de las decenas
      digitalWrite (displayUnidad,LOW) ; //Pone en Cero al display de las unidades
      contador (decena) ; //Llamado del metodo contador con el valor de las decenas
      delay (100) ;

      digitalWrite (displayDecena, LOW) ; //Pone en cero al display de las decenas
      digitalWrite (displayUnidad, HIGH) ; //Activación del display de las unidades
      contador (unidad) ; //Llamado del metodo contador con el valor de las unidades
      delay (100) ;
    }
      delay (100) ;
      if (contadorSensores==99){//Si el contador llega hasta el valor de 99 este se mantiene en ese valor 
        contadorSensores= 99 ;
    }
  }
    if (estadoSensor1== HIGH && estadoSensor2==LOW){
      digitalWrite(12, HIGH);
    }else {
      digitalWrite(12, LOW);
    }
    if (estadoSensor1== HIGH && estadoSensor2==LOW){ //Activacion de la segunda fotoresistecia
      if (contadorSensores>0 && contadorSensores<=99){ //Condicion para contar los estudiantes que salen del aula
        contadorSensores-- ; //Variable que almacena los estudiantes que salen del aula
        delay (500) ; //Velocidad de proccesamiento en la opera el contador
        decena= contadorSensores/10 ; //Variable que contabiliza las decenas 
        unidad= contadorSensores - decena*10 ; //Variable que contabiliza las decenas 
        Serial.println (contadorSensores) ;
        digitalWrite (displayDecena,HIGH) ;  //Activación del display de las decenas
        digitalWrite (displayUnidad,LOW) ; //Pone en Cero al display de las unidades
        contador (decena) ; //Llamado del metodo contador con el valor de las decenas
        delay (100) ;
        digitalWrite (displayDecena, LOW) ;  //Pone en cero el display de las decenas
        digitalWrite (displayUnidad, HIGH) ; //Activación del display de las unidades
        contador (unidad) ; //Llamado del metodo contador con el valor de las unidades
        delay (100) ;
        Serial.println (contadorSensores) ;
     }
    } 
  }

void contador (int estado){ //Metodo que establece los estados del 0 al 9 en binario, 
    switch (estado) {
      delay (20);
      case 0 : //Representacion del numero 0 en binario
      digitalWrite (estadoA, LOW) ;
      digitalWrite (estadoB, LOW) ;
      digitalWrite (estadoC, LOW) ;
      digitalWrite (estadoD, LOW) ;
      break ;
      case 1 : //Representacion del numero 1 en binario
      digitalWrite (estadoA, HIGH) ;
      digitalWrite (estadoB, LOW) ;
      digitalWrite (estadoC, LOW) ;
      digitalWrite (estadoD, LOW) ;
      break ;
            case 2 : //Representacion del numero 2 en binario
      digitalWrite (estadoA, LOW) ;
      digitalWrite (estadoB, HIGH) ;
      digitalWrite (estadoC, LOW) ;
      digitalWrite (estadoD, LOW) ;
      break ;
            case 3: //Representacion del numero 3 en binario
      digitalWrite (estadoA, HIGH) ;
      digitalWrite (estadoB, HIGH) ;
      digitalWrite (estadoC, LOW) ;
      digitalWrite (estadoD, LOW) ;
      break ;
            case 4 : //Representacion del numero 4 en binario
      digitalWrite (estadoA, LOW) ;
      digitalWrite (estadoB, LOW) ;
      digitalWrite (estadoC, HIGH) ;
      digitalWrite (estadoD, LOW) ;
      break ;
            case 5 : //Representacion del numero 5 en binario
      digitalWrite (estadoA, HIGH) ;
      digitalWrite (estadoB, LOW) ;
      digitalWrite (estadoC, HIGH) ;
      digitalWrite (estadoD, LOW) ;
      break ;
             case 6 : //Representacion del numero 6 en binario
      digitalWrite (estadoA, LOW) ;
      digitalWrite (estadoB, HIGH) ;
      digitalWrite (estadoC, HIGH) ;
      digitalWrite (estadoD, LOW) ;
      break ;
               case 7: //Representacion del numero 7 en binario
      digitalWrite (estadoA, HIGH) ;
      digitalWrite (estadoB, HIGH) ;
      digitalWrite (estadoC, HIGH) ;
      digitalWrite (estadoD, LOW) ;
      break ;
               case 8 : //Representacion del numero 8 en binario
      digitalWrite (estadoA, LOW) ;
      digitalWrite (estadoB, LOW) ;
      digitalWrite (estadoC, LOW) ;
      digitalWrite (estadoD, HIGH) ;
      break ;
           case 9 : //Representacion del numero 9 en binario
      digitalWrite (estadoA, HIGH) ;
      digitalWrite (estadoB, LOW) ;
      digitalWrite (estadoC, LOW) ;
      digitalWrite (estadoD, HIGH) ;
      break ;
    }
}
