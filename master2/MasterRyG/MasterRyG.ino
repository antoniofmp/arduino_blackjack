#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int cartasJug1[21]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int cartasJug2[21]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

char *jugadores[2]={
"%^J1: *", //% simbolo para jug1
"&@J2: *"};  //& simbolo para jug2

int ind=3;
int ind2=3;

char valor1;
char valor2;
char valor3;
char valor4;

char resp, resp2, resp3, resp4, valorCarta, valorCarta2;
int j, j2, indjug1=2,indjug2=2;
int nuevaCarta, nuevaCarta2, total=0, total2=0, total3=0, total4=0;
bool paso=false;
bool paso2=false;
bool paso3=false;
bool fin1=false;
bool fin2=false;
char totalizacion;
char totalizacion2;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);  
  lcd.setCursor(0, 0); 

  if(ind==8){
    ind=3;
  }
  randomSeed(analogRead(ind));
  ind++;
  int carta1=random(1, 11); 
  int carta2=random(1, 11); 
  int carta3=random(1, 11); 
  int carta4=random(1, 11);

  if(carta1==1){
    valor1 = 'A';
  }
  else if(carta1==2){
    valor1 = 'B';
  }
  else if(carta1==3){
    valor1 = 'C';
  }
  else if(carta1==4){
    valor1 = 'D';
  }
  else if(carta1==5){
    valor1 = 'E';
  }
  else if(carta1==6){
    valor1 = 'F';
  }
  else if(carta1==7){
    valor1 = 'G';
  }
  else if(carta1==8){
    valor1 = 'H';
  }
  else if(carta1==9){
    valor1 = 'I';
  }
  else if(carta1==10){
    valor1 = 'K';
  }
  
  if(carta2==1){
    valor2 = 'A';
  }
  else if(carta2==2){
    valor2 = 'B';
  }
  else if(carta2==3){
    valor2 = 'C';
  }
  else if(carta2==4){
    valor2 = 'D';
  }
  else if(carta2==5){
    valor2 = 'E';
  }
  else if(carta2==6){
    valor2 = 'F';
  }
  else if(carta2==7){
    valor2 = 'G';
  }
  else if(carta2==8){
    valor2 = 'H';
  }
  else if(carta2==9){
    valor2 = 'I';
  }
  else if(carta2==10){
    valor2 = 'K';
  }
  

  if(carta3==1){
    valor3 = 'A';
  }
  else if(carta3==2){
    valor3 = 'B';
  }
  else if(carta3==3){
    valor3 = 'C';
  }
  else if(carta3==4){
    valor3 = 'D';
  }
  else if(carta3==5){
    valor3 = 'E';
  }
  else if(carta3==6){
    valor3 = 'F';
  }
  else if(carta3==7){
    valor3 = 'G';
  }
  else if(carta3==8){
    valor3 = 'H';
  }
  else if(carta3==9){
    valor3 = 'I';
  }
  else if(carta3==10){
    valor3 = 'K';
  }

  if(carta4==1){
    valor4 = 'A';
  }
  else if(carta4==2){
    valor4 = 'B';
  }
  else if(carta4==3){
    valor4 = 'C';
  }
  else if(carta4==4){
    valor4 = 'D';
  }
  else if(carta4==5){
    valor4 = 'E';
  }
  else if(carta4==6){
    valor4 = 'F';
  }
  else if(carta4==7){
    valor4 = 'G';
  }
  else if(carta4==8){
    valor4 = 'H';
  }
  else if(carta4==9){
    valor4 = 'I';
  }
  else if(carta4==10){
    valor4 = 'K';
  }
  
  
  cartasJug1[0] = carta1;
  cartasJug1[1] = carta2;
  cartasJug2[0] = carta3;
  cartasJug2[1] = carta4;

  lcd.setCursor(0,1);

  Serial.write(jugadores[0]);
  Serial.write(valor1);
  Serial.write(" ");
  Serial.write(valor2);
  Serial.write(" ");

  Serial.write(jugadores[1]);
  Serial.write(valor3);
  Serial.write(" ");
  Serial.write(valor4);
  Serial.write(']');//transmitio todo y llego al final

}

void loop() {
  //-------------------------------
  if (Serial.available() > 0){
     lcd.setCursor(0, 0); 
     resp=Serial.read();
     
     if(resp == 'x'){
        paso=false;
     }

     if(resp == 'y'){
        paso2=false;
     }

     if(resp == '='){
        asm volatile ("  jmp 0");
     }

     if(resp == '#'){
        Serial.write("?&u");
     }

     if(resp == 'b'){
        Serial.write("&b");
     }

     if(resp == 's' && paso==false){ //respuesta si del jug 1
      paso = true;

     if(ind==10){
       ind=3;
     }
      
       randomSeed(analogRead(ind));
       nuevaCarta=random(1, 12);
       cartasJug1[indjug1] = nuevaCarta;

        if(cartasJug1[indjug1]==1){
          valorCarta = 'A';
        }
        else if(cartasJug1[indjug1]==2){
          valorCarta = 'B';
        }
        else if(cartasJug1[indjug1]==3){
          valorCarta = 'C';
        }
        else if(cartasJug1[indjug1]==4){
          valorCarta = 'D';
        }
        else if(cartasJug1[indjug1]==5){
          valorCarta = 'E';
        }
        else if(cartasJug1[indjug1]==6){
          valorCarta = 'F';
        }
        else if(cartasJug1[indjug1]==7){
          valorCarta = 'G';
        }
        else if(cartasJug1[indjug1]==8){
          valorCarta = 'H';
        }
        else if(cartasJug1[indjug1]==9){
          valorCarta = 'I';
        }
        else if(cartasJug1[indjug1]==10){
          valorCarta = 'K';
        }
      
        Serial.write('?'); //msj para jugador 1
        Serial.write('^');
        Serial.write('h');
        Serial.write('i');
        Serial.write('t');
        Serial.write(':');
        Serial.write(valorCarta);

        for (j=0;j<21;j++){//ver si calcular esto fuera del serial.available
          if(cartasJug1[j] != -1){
            delay(1000);
            total = total + cartasJug1[j];
           if(cartasJug1[j] == 1){
             if((total + 11) < 21){
               cartasJug1[j] = 11;
             }
           }
           
            
          }
          else{
            j = 21;  
          }
        }
        lcd.print(total);

        if(total==1){
          totalizacion = 'A';
        }
        else if(total==2){
          totalizacion = 'B';
        }
        else if(total==3){
          totalizacion = 'C';
        }
        else if(total==4){
          totalizacion = 'D';
        }
        else if(total==5){
          totalizacion = 'E';
        }
        else if(total==6){
          totalizacion = 'F';
        }
        else if(total==7){
          totalizacion = 'G';
        }
        else if(total==8){
          totalizacion = 'H';
        }
        else if(total==9){
          totalizacion = 'I';
        }
        else if(total==10){
          totalizacion = 'f';
        }
        else if(total==11){
          totalizacion = 's';
        }
        else if(total==12){
          totalizacion = 'L';
        }
        else if(total==13){
          totalizacion = 'M';
        }
        else if(total==14){
          totalizacion = 'O';
        }
        else if(total==15){
          totalizacion = 'P';
        }
        else if(total==16){
          totalizacion = 'Q';
        }
        else if(total==17){
          totalizacion = 'R';
        }
        else if(total==18){
          totalizacion = 'S';
        }
        else if(total==19){
          totalizacion = 'T';
        }
        else if(total==20){
          totalizacion = 'U';
        }
        else if(total==21){
          totalizacion = 'V';
        }
        else if(total==22){
          totalizacion = 'W';
        }
        else if(total==23){
          totalizacion = 'X';
        }
        else if(total==24){
          totalizacion = 'Y';
        }
        else if(total==25){
          totalizacion = 'Z';
        }
        else if(total==26){
          totalizacion = '<';
        }
        else if(total==27){
          totalizacion = '>';
        }
        else if(total==28){
          totalizacion = '-';
        }
        else if(total==29){
          totalizacion = '+';
        }
        else if(total==30){
          totalizacion = '{';
        }
        else if(total==31){
          totalizacion = '}';
        }

        Serial.write(' ');
        Serial.write('t');
        Serial.write('o');
        Serial.write('t');
        Serial.write('a');
        Serial.write('l');
        Serial.write(':');
        Serial.write(' ');
        Serial.write(totalizacion);

        if(total<=21){
           Serial.write(']'); //fin de envio a jug1
        }
        else if(total>21){
           Serial.write('!'); //perdio el jug1
        }
        
       indjug1++;
       total=0;
     }
     if(resp == 'n'){ //respuesta no del jug 1
        fin1=true;
     }
     if(resp == 'v' && paso2==false){ //respuesta si del jug 2
       paso2 = true;

     if(ind2==8){
       ind2=3;
     }
      
       randomSeed(analogRead(ind2));
       nuevaCarta2=random(1, 12);
       cartasJug2[indjug2] = nuevaCarta2;
      
        if(cartasJug2[indjug2]==1){
          valorCarta2 = 'A';
        }
        else if(cartasJug2[indjug2]==2){
          valorCarta2 = 'B';
        }
        else if(cartasJug2[indjug2]==3){
          valorCarta2 = 'C';
        }
        else if(cartasJug2[indjug2]==4){
          valorCarta2 = 'D';
        }
        else if(cartasJug2[indjug2]==5){
          valorCarta2 = 'E';
        }
        else if(cartasJug2[indjug2]==6){
          valorCarta2 = 'F';
        }
        else if(cartasJug2[indjug2]==7){
          valorCarta2 = 'G';
        }
        else if(cartasJug2[indjug2]==8){
          valorCarta2 = 'H';
        }
        else if(cartasJug2[indjug2]==9){
          valorCarta2 = 'I';
        }
        else if(cartasJug2[indjug2]==10){
          valorCarta2 = 'K';
        }
      
        Serial.write('&'); //msj para jugador 1
        Serial.write('^');
        Serial.write('h');
        Serial.write('i');
        Serial.write('t');
        Serial.write(':');
        Serial.write(valorCarta2);
     
        for (j2=0;j2<21;j2++){//ver si calcular esto fuera del serial.available
          if(cartasJug2[j2] != -1){
            delay(1000);
            total2 = total2 + cartasJug2[j2];
           if(cartasJug2[j2] == 1){
             if((total2 + 11) < 21){
               cartasJug2[j2] = 11;
             }
           }
           
            
          }
          else{
            j2 = 21;  
          }
        }
        lcd.print(total2);

        if(total2==1){
          totalizacion2 = 'A';
        }
        else if(total2==2){
          totalizacion2 = 'B';
        }
        else if(total2==3){
          totalizacion2 = 'C';
        }
        else if(total2==4){
          totalizacion2 = 'D';
        }
        else if(total2==5){
          totalizacion2 = 'E';
        }
        else if(total2==6){
          totalizacion2 = 'F';
        }
        else if(total2==7){
          totalizacion2 = 'G';
        }
        else if(total2==8){
          totalizacion2 = 'H';
        }
        else if(total2==9){
          totalizacion2 = 'I';
        }
        else if(total2==10){
          totalizacion2 = 'K';
        }
        else if(total2==11){
          totalizacion2 = 's';
        }
        else if(total2==12){
          totalizacion2 = 'L';
        }
        else if(total2==13){
          totalizacion2 = 'M';
        }
        else if(total2==14){
          totalizacion2 = 'O';
        }
        else if(total2==15){
          totalizacion2 = 'P';
        }
        else if(total2==16){
          totalizacion2 = 'Q';
        }
        else if(total2==17){
          totalizacion2 = 'R';
        }
        else if(total2==18){
          totalizacion2 = 'S';
        }
        else if(total2==19){
          totalizacion2 = 'T';
        }
        else if(total2==20){
          totalizacion2 = 'U';
        }
        else if(total2==21){
          totalizacion2 = 'V';
        }
        else if(total2==22){
          totalizacion2 = 'W';
        }
        else if(total2==23){
          totalizacion2 = 'X';
        }
        else if(total2==24){
          totalizacion2 = 'Y';
        }
        else if(total2==25){
          totalizacion2 = 'Z';
        }
        else if(total2==26){
          totalizacion2 = '<';
        }
        else if(total2==27){
          totalizacion2 = '>';
        }
        else if(total2==28){
          totalizacion2 = '-';
        }
        else if(total2==29){
          totalizacion2 = '+';
        }
        else if(total2==30){
          totalizacion2 = '{';
        }
        else if(total2==31){
          totalizacion2 = '}';
        }

        Serial.write(' ');
        Serial.write('t');
        Serial.write('o');
        Serial.write('t');
        Serial.write('a');
        Serial.write('l');
        Serial.write(':');
        Serial.write(' ');
        Serial.write(totalizacion2);

        if(total2<=21){
           Serial.write(']'); //fin de envio a jug2
        }
        else if(total2>21){
           Serial.write('g'); //perdio el jug2
        }
        
       indjug2++;
       total2=0;
     }
     if(resp == 'w'){ //respuesta no del jug 2
        fin2=true;          
     }

     if(fin1 == true && fin2 == true && paso3==false){
        paso3 = true;

        for (j=0;j<21;j++){//ver si calcular esto fuera del serial.available
          if(cartasJug1[j] != -1){
            delay(1000);
           if(cartasJug1[j] == 1){
             if((total3 + 11) <= 21){
               cartasJug1[j] = 11;
             }
           }
           
            total3 = total3 + cartasJug1[j];
          }
          else{
            j = 21;  
          }
        }

        for (j=0;j<21;j++){//ver si calcular esto fuera del serial.available
          if(cartasJug2[j] != -1){
            delay(1000);
           if(cartasJug2[j] == 1){
             if((total4 + 11) <= 21){
               cartasJug2[j] = 11;
             }
           }
           
            total4 = total4 + cartasJug2[j];
          }
          else{
            j = 21;  
          }
        }
        
         if(total3 > total4){
            Serial.write(";dk");//msj a jug 2
            Serial.write(";?j");//msj a jug 1
            delay(4000);
            Serial.write("?z");
            Serial.write("dz");
         }
         else if(total3 < total4){
            Serial.write(";dj");//msj a jug 2
            Serial.write(";?k");//msj a jug 1
            delay(4000);
            Serial.write("?z");
            Serial.write("dz");
         }
         else if(total3 == total4){
            Serial.write(";dr");//msj a jug 2
            Serial.write(";?r");//msj a jug 1
            delay(4000);
            Serial.write("?z");
            Serial.write("dz");
         }
      }
     
     ind++;
     ind2++;
  }
}
