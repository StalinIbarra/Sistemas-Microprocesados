#include <MsTimer2.h>
#include <LiquidCrystal.h>
#include <Keypad.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); //RS, Enable, D4, D5, D6, D7

//////////////////TECLADO//////////////////    
const byte fil = 4;    
const byte col = 4;    
char keys[fil][col] = {    
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte pinFil[fil] = {A0, A1, A2, A3}; 
byte pinCol[col] = {7, 6, 5, 4}; 
Keypad teclado = Keypad(makeKeymap(keys), pinFil, pinCol, fil, col); 
///////////////////////////////////////////

char tec;
String dato ;
int num = 0, a=0;

void setup() {
  MsTimer2::set(1000, lectura);
  MsTimer2::start();
  lcd.begin(16, 2);
  lcd.print("INGRESE NUMERO");
}

void loop() {
  
  tec = teclado.getKey();
  if (tec) {
    if (tec == 'B' || tec == 'C' || tec == 'D' || tec == '#' || tec == '*') {
      a = 1 - a;
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(9, 1);
      lcd.print("       ");
      lcd.setCursor(0, 0);
      lcd.print("CUENTA REGRESIVA");
    }
    else if (tec == 'A') {
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(0, 0);
      lcd.print("RESET");
      delay(1000);
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 0);
      lcd.print("INGRESE NUMERO");
      lcd.setCursor(0, 1);
      tec = ' ';
      dato=" ";
      a = 0;
      num = 0;
    }
    else {
      lcd.print(tec);
      dato = dato + tec;
    }
    num = dato.toInt();
  }
}
void lectura() {
  if (a == 1 ) {
    if (num > 0) {
      lcd.setCursor(8, 1);
      lcd.print("      ");
      lcd.setCursor(8, 1);
      lcd.print(num);
      num--;
    }
    else if (num == 0) {
      lcd.setCursor(8, 1);
      lcd.print("    ");
      lcd.setCursor(8, 1);
      lcd.print(num);
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(0, 0);
      lcd.print("FIN CUENTA");
    }
  }
}
