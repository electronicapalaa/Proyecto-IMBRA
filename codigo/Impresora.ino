#define _caracteresX 20
#include <LiquidCrystal_I2C.h>
#include <PS2Keyboard.h>

LiquidCrystal_I2C lcd(0x27,16,2);
PS2Keyboard keyboard;


byte _enie[8]={
  0b01110,
  0b00000,
  0b10110,
  0b11001,
  0b10001,
  0b10001,
  0b10001,
  0b00000,
};

byte _esc1[8]={
  0b00000,
  0b11111,
  0b11001,
  0b11011,
  0b11001,
  0b11011,
  0b11001,
  0b11111,
};
byte _esc2[8]={
  0b00000,
  0b11111,
  0b10011,
  0b10111,
  0b10011,
  0b10111,
  0b10011,
  0b11111,
};
byte _esc3[8]={
  0b11111,
  0b11001,
  0b11011,
  0b11001,
  0b01101,
  0b01001,
  0b00111,
  0b00000,
};
byte _esc4[8]={
  0b11111,
  0b10001,
  0b11011,
  0b11011,
  0b11010,
  0b11010,
  0b11100,
  0b00000,
};

byte testBra[8]={
  0b00000,
  0b01010,
  0b00000,
  0b01010,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
};

const PROGMEM PS2Keymap_t PS2Keymap_Spanish = {
    // without shift
    {0, PS2_F9, 0, PS2_F5, PS2_F3, PS2_F1, PS2_F2, PS2_F12,
     0, PS2_F10, PS2_F8, PS2_F6, PS2_F4, PS2_TAB, 0 /*|*/, 0,
     0, 0 /*Lalt*/, 0 /*Lshift*/, 0, 0 /*Lctrl*/, 'q', '1', 0,
     0, 0, 'z', 's', 'a', 'w', '2', 0,
     0, 'c', 'x', 'd', 'e', '4', '3', 0,
     0, ' ', 'v', 'f', 't', 'r', '5', 0,
     0, 'n', 'b', 'h', 'g', 'y', '6', 0,
     0, 0, 'm', 'j', 'u', '7', '8', 0,
     0, ',', 'k', 'i', 'o', '0', '9', 0,
     0, '.', '-', 'l', '|'/*ñ*/, 'p', 0, 0,
     0, 0, '(', 0, '(', '!', 0, 0,
     0 /*CapsLock*/, 0 /*Rshift*/, PS2_ENTER /*Enter*/, '*', 0, ')', 0, 0,
     0, 0, 0, 0, 0, 0, PS2_BACKSPACE, 0,
     0, '1', 0, '4', '7', 0, 0, 0,
     '0', '.', '2', '5', '6', '8', PS2_ESC, 0 /*NumLock*/,
     PS2_F11, 0, '3', '-', '*', '9', PS2_SCROLL, 0,
     0, 0, 0, PS2_F7 },
    // with shift
    {0, PS2_F9, 0, PS2_F5, PS2_F3, '=', PS2_F2, PS2_F12,
     0, PS2_F10, PS2_F8, PS2_F6, PS2_F4, PS2_TAB, 0, 0,
     0, 0 /*Lalt*/, 0 /*Lshift*/, 0, 0 /*Lctrl*/, 'q', '!', 0,
     0, 0, 'z', 's', 'a', 'w', '\"', 0,
     0, 'c', 'x', 'd', 'e', 0, 0, 0,
     0, ' ', 'v', 'f', 't', 'r', 0, 0,
     0, 'n', 'b', 'h', 'g', 'y', '&', 0,
     0, 0, 'm', 'j', 'u', 0, '(', 0,
     0, ';', 'k', 'i', 'o', '-', ')', 0,
     0, ':', '-', 'l', '|'/*ñ*/, 'p', '?', 0,
     0, 0, '(', 0, '(', 0, 0, 0,
     0 /*CapsLock*/, 0 /*Rshift*/, PS2_ENTER /*Enter*/, ')', 0, ')', 0, 0,
     0, 0, 0, 0, 0, 0, PS2_BACKSPACE, 0,
     0, '1', 0, '4', '7', 0, 0, 0,
     '0', '.', '2', '5', '6', '8', PS2_ESC, 0 /*NumLock*/,
     PS2_F11, 0, '3', '-', '*', '9', PS2_SCROLL, 0,
     0, 0, 0, PS2_F7 },
         1,
    // with altgr
    {0, PS2_F9, 0, PS2_F5, PS2_F3, PS2_F1, PS2_F2, PS2_F12,
     0, PS2_F10, PS2_F8, PS2_F6, PS2_F4, PS2_TAB, 0, 0,
     0, 0 /*Lalt*/, 0 /*Lshift*/, 0, 0 /*Lctrl*/, 'q', 0, 0,
     0, 0, 'z', 's', 'a', 'w', 0, 0,
     0, 'c', 'x', 'd', 0, 0, 0, 0,
     0, ' ', 'v', 'f', 't', 'r', '5', 0,
     0, 'n', 'b', 'h', 'g', 'y', 0, 0,
     0, 0, 'm', 'j', 'u', '7', '8', 0,
     0, ',', 'k', 'i', 'o', '0', '9', 0,
     0, '.', '-', 'l', '|'/*ñ*/, 'p', '\"', 0,
     0, 0, '(', 0, '(', '!', 0, 0,
     0 /*CapsLock*/, 0 /*Rshift*/, PS2_ENTER /*Enter*/, ')', 0, ')', 0, 0,
     0, 0, 0, 0, 0, 0, PS2_BACKSPACE, 0,
     0, '1', 0, '4', '7', 0, 0, 0,
     '0', '.', '2', '5', '6', '8', PS2_ESC, 0 /*NumLock*/,
     PS2_F11, 0, '3', '-', '*', '9', PS2_SCROLL, 0,
     0, 0, 0, PS2_F7 }
};


int testIndex = 0;
bool testingChars = false;

struct braille{
  char letra;
  byte puntos;
  };
// 0b00543210
// 01
// 23
// 45
const braille caracteres[] {
        //543210
  {'a', 0b000001},
  {'b', 0b000101},
  {'c', 0b000011},
  {'d', 0b001011},
  {'e', 0b001001},
  {'f', 0b000111},
  {'g', 0b001111},
  {'h', 0b001101},
  {'i', 0b000110},
  {'j', 0b001110},
  {'k', 0b010001},
  {'l', 0b010101},
  {'m', 0b010011},
  {'n', 0b011011},
  {'|', 0b101111}, // Ñ
  {'o', 0b011001},
  {'p', 0b010111},
  {'q', 0b011111},
  {'r', 0b011101},
  {'s', 0b010110},
  {'t', 0b011110},
  {'u', 0b110001},
  {'v', 0b110101},
  {'w', 0b101110},
  {'x', 0b110011},
  {'y', 0b111011},
  {'z', 0b111001},
  {'#', 0b111010}, // Prefijo numérico.
  {'&', 0b110111},
  {'.', 0b010000},
  {',', 0b000100},
  {'?', 0b100100},
  {';', 0b010100},
  {'!', 0b011100},
  {'"', 0b110100},
  {'(', 0b100101},
  {')', 0b011010},
  {'-', 0b110000},
  {'*', 0b011000},
  {' ', 0b000000},
  {'1', 0b000001},
  {'2', 0b000101},
  {'3', 0b000011},
  {'4', 0b001011},
  {'5', 0b001001},
  {'6', 0b000111},
  {'7', 0b001111},
  {'8', 0b001101},
  {'9', 0b000110},
  {'0', 0b001110},
  };

braille texto[_caracteresX];

void inicializarTexto();
void agregarLetra(char c);
void borrarLetra();
void imprimirLinea();
void probarLetra(int index);
void creditos();

#define IRQpin  2
#define stpX 11
#define DataPin 4
#define dirX 12
#define stpZ 9
#define dirZ 10
#define punz 8

void setup() { 
  keyboard.begin(DataPin, IRQpin, PS2Keymap_Spanish);
  //Serial.begin(9600);
  lcd.init();  
  lcd.backlight();
  inicializarTexto();
  lcd.createChar(1,_enie);
  lcd.noBlink();
  pinMode(stpX, OUTPUT);
  pinMode(dirX, OUTPUT);
  pinMode(stpZ, OUTPUT);
  pinMode(dirZ, OUTPUT);
  pinMode(punz, OUTPUT);
  
  //while (true){
    //moverse(true, 100);
    //moverse(false, 100);
    //moverse(true, -100);
   // moverse(false, -100);
  //}
  
}

void loop() {
  lcd.setCursor(0 ,0);
  for (int i = 0; i < _caracteresX; i++){
    if (i == 16){
      lcd.setCursor(0, 1);  
    }
    if (texto[i].letra == '|'){
      lcd.write(1);
    }else if (texto[i].letra == '~'){
      lcd.write(2);
    }else if (texto[i].letra != '\0'){
      lcd.print(texto[i].letra);  
    }else{
      break;
    }
  }
  
  if (keyboard.available()) {
    
    // read the next key
    char c = keyboard.read();
    
    // check for some of the special keys
    if (c == PS2_ENTER) { // Imprimir línea
      //Serial.println();
      imprimirLinea();
    } else if(c == PS2_TAB){
      probarLetra();
      testIndex++;
    } else if (c == PS2_ESC) {
      //Serial.print("[ESC]");
    } else if (c == PS2_PAGEDOWN) {
      //Serial.print("[PgDn]");
    } else if (c == PS2_PAGEUP) {
      //Serial.print("[PgUp]");
    } else if (c == PS2_LEFTARROW) {
      //Serial.print("[Left]");
    } else if (c == PS2_RIGHTARROW) {
      //Serial.print("[Right]");
    } else if (c == PS2_UPARROW) {
      moverse(false, -280);
    } else if (c == PS2_DOWNARROW) {
      moverse(false, 280);
    } else if (c == PS2_DELETE) {
      //Serial.print("[Del]");
      borrarLetra();
    }else {
      if (testingChars){
        inicializarTexto();  
      }
      //Serial.print(c);
      agregarLetra(c);
    }
  }
}

void tecladoActivo(bool activo){
  // poner en alto el pin de reloj;  
}

void limpiarLetra(int index){
  texto[index].letra = '\0';
  texto[index].puntos = 255;
  lcd.setCursor(index % 16, index / 16);
  lcd.print(' ');
}

void borrarLetra(){
  if (texto[0].letra == '\0'){ // Texto vacío.
    return;
  }
  if (texto[_caracteresX - 1].letra != '\0'){ // Texto lleno.
    limpiarLetra(_caracteresX - 1);
    if (texto[_caracteresX - 2].letra == '#'){
        limpiarLetra(_caracteresX - 2);
      }
    return;
  }
      
  for (int i = 0; i < _caracteresX; i++){
  if (texto[i].letra == '\0'){
      limpiarLetra(i-1);
      if (i > 1 && texto[i-2].letra == '#'){
        limpiarLetra(i-2);
      }
    }
  }
}

braille charABraille(char c){
   for (int i = 0; i < sizeof(caracteres); i++){
     if (caracteres[i].letra == c){
       return caracteres[i];
      } 
   }
}

bool esNumeroOPrefijo(char c){
  return (c >= '0' && c <= '9') || c == '#';  
}

void agregarLetra(char c){  

  if (texto[_caracteresX - 1].letra != '\0'){ // texto lleno
    return;
  }   

  if (texto[_caracteresX - 2].letra != '\0' && !esNumeroOPrefijo(texto[_caracteresX - 2].letra) && esNumeroOPrefijo(c)){
      return;
    }
  
  for (int i = 0; i < _caracteresX; i++){
    if (texto[i].letra == '\0'){
        if ((i == 0 && esNumeroOPrefijo(c)) || (i > 0 && !esNumeroOPrefijo(texto[i-1].letra) && esNumeroOPrefijo(c)))
        {
          texto[i] = charABraille('#');
          agregarLetra(c);
        }else {
          texto[i] = charABraille(c);
        }
      break;
    }
  }
}


void inicializarTexto() {
  testingChars = false;
  testIndex = 0;
  lcd.clear();
  lcd.createChar(1,_enie);
  for (int i = 0; i < _caracteresX; i++){
    texto[i].letra = '\0';  
    texto[i].puntos = 255;
  }  
}

void probarLetra(){
  if (testingChars == false){
    inicializarTexto();
    testingChars = true;  
  }
  
  if (testIndex >= 50)
  {
    inicializarTexto();
    return;
  }else{
    testBra[1] = ((caracteres[testIndex].puntos & (1 << 0)) ? 1 : 0) << 3;
    testBra[1] += ((caracteres[testIndex].puntos & (1 << 1)) ? 1 : 0) << 1;
    testBra[3] = ((caracteres[testIndex].puntos & (1 << 2)) ? 1 : 0) << 3;
    testBra[3] += ((caracteres[testIndex].puntos & (1 << 3)) ? 1 : 0) << 1;
    testBra[5] = ((caracteres[testIndex].puntos & (1 << 4)) ? 1 : 0) << 3;
    testBra[5] += ((caracteres[testIndex].puntos & (1 << 5)) ? 1 : 0) << 1;
    lcd.createChar(3,testBra);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.write(3);
    lcd.print(' ');
    switch (testIndex){
      case 14:
        lcd.write(1);
        break;
      case 39:
        lcd.print("Espacio");
        break;
      default:
        lcd.print(caracteres[testIndex].letra);
        break;  
      }
   } 
}
#define xCorto 13 //7 //4 //13
#define xLargo 17 //23 //26 //17
#define zCorto 35 //70
// 200 pasos equivalen a 18mm (AVANCE HOJA)
// 50 pasos equivalen a 10mm (CARRO)

#define zLargo 200

#define minTime 1100
#define maxTime 1500

int ubicacion = 0;

void moverse(bool motorX, int pasos){
  int stp = motorX ? stpX : stpZ;
  int dir = motorX ? dirX : dirZ;
  bool suma = true;


  if (pasos < 0){
    pasos *= -1;
    suma = false;
    digitalWrite(dir, LOW);
  }else{
    digitalWrite(dir, HIGH);
  }

  for (int i = 0; i < pasos; i++){
    //int delay = 4*(maxTime - minTime)/(float)(pasos * pasos) * (i - (pasos/2)) * (i - (pasos/2)) + minTime;

    digitalWrite(stp, HIGH);
    delay(1);//delayMicroseconds(delay);
    digitalWrite(stp, LOW);
    delay(1);//delayMicroseconds(delay);

    if (motorX) {
      if (suma)
        ubicacion++;
      else
        ubicacion--;
    }
  } 

}

void imprimirLinea(){
  lcd.clear();
  dibujarEscudo();
  lcd.print("IMPRIMIENDO");
  tecladoActivo(false);
  // Imprimir "IMPRIMIENDO..." en el lcd.
  for(int regla = 0; regla < 3; regla++){
    lcd.print(".");
    bool linea[_caracteresX * 2];
    for (int i = 0; i < _caracteresX; i++){
      if (texto[i].puntos != 255){
        linea[i*2+0] = texto[i].puntos & (1 << (regla*2+0));
        linea[i*2+1] = texto[i].puntos & (1 << (regla*2+1)); //linea[i*2+1] = texto[i].puntos & (2 << (regla*2));
      }else{
        linea[i*2+0] = false;
        linea[i*2+1] = false;
      }
    } 
    
    int distancia = 0;
    //for(int i = _caracteresX*2-1; i >= 0; i--){
    for (int i = 0; i < _caracteresX*2; i++){
        if (i & 0) // impar
          distancia += xCorto;
        else
          distancia += xLargo;

        if (linea[i] == true){
          moverse(true, distancia);
          delay(300);
          digitalWrite(punz, HIGH);
          delay(350);
          digitalWrite(punz, LOW);
          delay(350);
          
          digitalWrite(punz, HIGH);
          delay(350);
          digitalWrite(punz, LOW);
          delay(500);
          
          distancia = 0;
        }
    }
    moverse(true, -ubicacion);
    moverse(false, zCorto);
  }
  moverse(false, zLargo);

  lcd.clear();
  inicializarTexto();
  tecladoActivo(true);
}

void dibujarEscudo(){
  lcd.createChar(1,_esc1);
  lcd.createChar(2,_esc2);
  lcd.createChar(3,_esc3);
  lcd.createChar(4,_esc4);
  lcd.setCursor(0 ,0);
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(0 ,1);
  lcd.write(3);
  lcd.write(4);
  lcd.setCursor(2, 0);
}
