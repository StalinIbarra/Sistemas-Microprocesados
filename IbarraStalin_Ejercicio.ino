float dato;
int led=8;
int option=0;
int limite;

void setup() {
Serial.begin(9600);
pinMode(led, OUTPUT);
Serial.print("Ingrese el numero maximo");
}

void loop() {

  if(Serial.available()>0){
  limite=Serial.readString().toInt();
  Serial.println(limite);
  option=1;
  }
 
  if(option==1){
  dato = analogRead(0);
  Serial.println(String(analogRead(0)));
  delay(250);
      
    if(dato<limite){
      digitalWrite(led, LOW);
    }else{
      digitalWrite(led, HIGH);
    }
  }
}
