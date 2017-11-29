/*
   Práctica 7 segmentos y keypad
   Arduino nano
   Alvaro
*/

// keypad ------------------------------------
#include <Keypad.h>
const byte kRows= 4; 
const byte kCols= 4; 
char kMap[kRows][kCols]={
   { '1','2','3','A' },
   { '4','5','6','B' },
   { '7','8','9','C' },
   { '#','0','*','D' }  
};
byte rPins[kRows]= {A0,A1,A2,2}; //Rows 0 to 3
byte cPins[kCols]= {A3,A4,A5,3}; //Cols 0 to 3
Keypad kpad= Keypad(makeKeymap(kMap), rPins, cPins, kRows, kCols);

bool dLSD(byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte h) {
  digitalWrite (5,a);   //Se reciben 7 variables y se asignan
  digitalWrite (6,b);   //a cada una de las salidas
  digitalWrite (7,c);
  digitalWrite (8,d);
  digitalWrite (9,e);
  digitalWrite (10,f);
  digitalWrite (11,g);
  digitalWrite (12,h);
}
bool displayLSD(char n) {
  switch (n) {
  case '0':
    dLSD(1,1,1,1,1,1,0,0); // 0
    break;
  case '1':
    dLSD(0,1,1,0,0,0,0,0); // 1
    break;
  case '2':
    dLSD(1,1,0,1,1,0,1,0); // 2
    break;
  case '3':
    dLSD(1,1,1,1,0,0,1,0); // 3
    break;
  case '4':
    dLSD(0,1,1,0,0,1,1,0); // 4
    break;
  case '5':
    dLSD(1,0,1,1,0,1,1,0); // 5
    break;
  case '6':
    dLSD(1,0,1,1,1,1,1,0); // 6
    break;
  case '7':
    dLSD(1,1,1,0,0,0,0,0); // 7
    break;
  case '8':
    dLSD(1,1,1,1,1,1,1,0); // 8
    break;
  case '9':
    dLSD(1,1,1,0,0,1,1,0); // 9
    break;
  default :
    dLSD(0,0,0,0,0,0,0,0); // nada
    break;
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);  
  pinMode(6, OUTPUT);  
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop()
{
  char kpress = kpad.getKey();
  if (kpress != NO_KEY) { 
   displayLSD(kpress);     // Muestra en LSD la tecla
   Serial.println(kpress); // Mostrar serial la tecla
  }
}