// include the library code:
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// Define constants and variables
const int inputPin = A0;  // buttons array analog input 
uint16_t inputValue = 0;   // value read from buttons array
//
const int ledPin = 13; // the pin that the LED is attached to
char incomingByte;      // a variable to read incoming serial data into
char respuesta;
bool booleano2=false;
bool primeraVez=true;
int i = 0,x=0,cursore,pr=0;

// initialize internal variables
unsigned int l;             // current line number displayed on the first row
// Initialization
void setup() 
{
  //----------------
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  //--------------
  lcd.begin(16, 2);              // set up the LCD's number of columns and rows
  lcd.write("   BLACKJACK!");  // Print a message on the LCD
  lcd.setCursor(0, 1);           // set the cursor to column 0, line 1
  lcd.write("  Juega ahora!");
}

// main loop
void loop() 
{
  // check buttons status------------------------------------------------
  inputValue = analogRead(inputPin);
  
  if(inputValue < 100 && inputValue >= 0) inputValue = 1;
  else if(inputValue < 250 && inputValue > 150) inputValue = 2;
  else if(inputValue < 470 && inputValue > 370) inputValue = 3;
  else if(inputValue < 670 && inputValue > 570) inputValue = 4;
  else if(inputValue < 870 && inputValue > 770) inputValue = 5;
  else if(inputValue <= 1023 && inputValue > 950) inputValue = 0;
  //---------------------------
  // Send answer
  if((inputValue == 1 || inputValue == 2 || inputValue == 3 || inputValue == 4 || inputValue == 5)&& pr>=0)
  {
    lcd.clear();
    lcd.setCursor(0,0);

    if(inputValue == 1){
       respuesta = 'v';//si del jugador 1
    }
    if(inputValue == 2){
       respuesta = 'w';//no del jugador 1
    }
    if(inputValue == 3){
       respuesta = '=' ;//quiero volver a jugar
    }
    if(inputValue == 4){
       respuesta = '#' ;//no quiero volver a jugar
    }
    Serial.write(respuesta);
  }

 //-----------------------------------------------------------------
 
 if (Serial.available() > 0){
  incomingByte = Serial.read();  
  if(incomingByte=='&' || incomingByte=='%' || incomingByte=='d'){ //si es para jug 2 
    booleano2 = true;
  }
   if(booleano2 == true){
    if(incomingByte=='^'){
      i=0; 
      cursore = 0;
      lcd.clear();
    }
    if(incomingByte=='@'){
      cursore = 1;
      i=0;
    }
    if(incomingByte=='*'){
      //x=0;
      pr++;
    }
    if(incomingByte=='$'){
      x=0;
      i=0;
      pr=0;   
    }
    if(incomingByte==']'){
      booleano2=false;
      delay(3000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Otra carta?");
      lcd.setCursor(0,1);
      lcd.print("1)Si 2)No");
      Serial.write('y'); //se le indica al master 
    }
    if(incomingByte==';'){
      booleano2=false;
    }
    if(incomingByte=='g'){
      booleano2=false;
      delay(3000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Perdiste!");
      
      delay(3000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Volver a jugar?");
      lcd.setCursor(0,1);
      lcd.print("3)Si 4)No");
    }
    if(incomingByte=='z'){
      booleano2=false;
      delay(3000);
      lcd.clear();
      lcd.setCursor(0,0);
      
      delay(3000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Volver a jugar?");
      lcd.setCursor(0,1);
      lcd.print("3)Si 4)No");
    }
    if(incomingByte=='b'){
      booleano2=false;
      delay(3000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Ganaste!");
      
      delay(3000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Volver a jugar?");
      lcd.setCursor(0,1);
      lcd.print("3)Si 4)No");
    }
    if(incomingByte=='u'){
      booleano2=false;
      delay(3000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Hasta luego!");
    }
    if(incomingByte=='#'){
      lcd.setCursor(0,0);
      lcd.write("opcion no valida");
      lcd.setCursor(0,1);
      lcd.write("intente de nuevo");
      delay(2000); 
    }
    //--------------------------
    lcd.setCursor(i,cursore);
    if(incomingByte=='A'){
        lcd.print('A');
        i++;
        x++;
    }
    else if(incomingByte=='B'){
        lcd.print('2');
        i++;
        x++;
    }
    else if(incomingByte=='C'){
        lcd.print('3');
        i++;
        x++;
    }
    else if(incomingByte=='D'){
        lcd.print('4');
        i++;
        x++;
    }
    else if(incomingByte=='E'){
        lcd.print('5');
        i++;
        x++;
    }
    else if(incomingByte=='F'){
        lcd.print('6');
        i++;
        x++;
    }
    else if(incomingByte=='G'){
        lcd.print('7');
        i++;
        x++;
    }
    else if(incomingByte=='H'){
        lcd.print('8');
        i++;
        x++;
    }
    else if(incomingByte=='I'){
        lcd.print('9');
        i++;
        x++;
    }
    else if(incomingByte=='K'){
        lcd.print('K');
        i++;
        x++;
    }
    else if(incomingByte=='s'){
        lcd.print("11");
        i++;
        x++;
    }
    else if(incomingByte==' '){
        lcd.print(' ');
        i++;
        x++;
    }
    else if(incomingByte=='J'){
        lcd.print('J');
        i++;
        x++;
    }
    else if(incomingByte=='1'){
        lcd.print('1');
        i++;
        x++;
    }
    else if(incomingByte=='2'){
        lcd.print('2');
        i++;
        x++;
    }
    else if(incomingByte==':'){
        lcd.print(':');
        i++;
        x++;
    }
    else if(incomingByte=='L'){
        lcd.print("12");
        i++;
        x++;
    }
    else if(incomingByte=='M'){
        lcd.print("13");
        i++;
        x++;
    }
    else if(incomingByte=='O'){
        lcd.print("14");
        i++;
        x++;
    }
    else if(incomingByte=='P'){
        lcd.print("15");
        i++;
        x++;
    }
    else if(incomingByte=='Q'){
        lcd.print("16");
        i++;
        x++;
    }
    else if(incomingByte=='R'){
        lcd.print("17");
        i++;
        x++;
    }
    else if(incomingByte=='S'){
        lcd.print("18");
        i++;
        x++;
    }
    else if(incomingByte=='T'){
        lcd.print("19");
        i++;
        x++;
    }
    else if(incomingByte=='U'){
        lcd.print("20");
        i++;
        x++;
    }
    else if(incomingByte=='V'){
        lcd.print("21");
        i++;
        x++;
    }
    else if(incomingByte=='W'){
        lcd.print("22");
        i++;
        x++;
    }
    else if(incomingByte=='X'){
        lcd.print("23");
        i++;
        x++;
    }
    else if(incomingByte=='Y'){
        lcd.print("24");
        i++;
        x++;
    }
    else if(incomingByte=='Z'){
        lcd.print("25");
        i++;
        x++;
    }
    else if(incomingByte=='<'){
        lcd.print("26");
        i++;
        x++;
    }
    else if(incomingByte=='>'){
        lcd.print("27");
        i++;
        x++;
    }
    else if(incomingByte=='-'){
        lcd.print("28");
        i++;
        x++;
    }
    else if(incomingByte=='+'){
        lcd.print("29");
        i++;
        x++;
    }
    else if(incomingByte=='{'){
        lcd.print("30");
        i++;
        x++;
    }
    else if(incomingByte=='}'){
        lcd.print("31");
        i++;
        x++;
    }
    else if(incomingByte=='h'){
        lcd.print('H');
        i++;
        x++;
    }
    else if(incomingByte=='i'){
        lcd.print('i');
        i++;
        x++;
    }
    else if(incomingByte=='t'){
        lcd.print('t');
        i++;
        x++;
    }
    else if(incomingByte=='o'){
        lcd.print('o');
        i++;
        x++;
    }
    else if(incomingByte=='a'){
        lcd.print('a');
        i++;
        x++;
    }
    else if(incomingByte=='l'){
        lcd.print('l');
        i++;
        x++;
    }
    else if(incomingByte=='j'){
        lcd.setCursor(0,0);
        lcd.print("Ganaste");
        i++;
        x++;
    }
    else if(incomingByte=='k'){
        lcd.setCursor(0,0);
        lcd.print("Perdiste");
        i++;
        x++;
    }
    else if(incomingByte=='r'){
        lcd.setCursor(0,0);
        lcd.print("Empate");
        i++;
        x++;
    }
  }
 }
}
