#define _caracteresX 32
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

byte _enieMayus[8]={
  0b11111,
  0b00000,
  0b11001,
  0b10101,
  0b10011,
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
     0, 0 /*Lalt*/, 0 /*Lshift*/, 0, 0 /*Lctrl*/, 'Q', '!', 0,
     0, 0, 'Z', 'S', 'A', 'W', '\"', 0,
     0, 'C', 'X', 'D', 'E', 0, 0, 0,
     0, ' ', 'V', 'F', 'T', 'R', 0, 0,
     0, 'N', 'B', 'H', 'G', 'Y', '&', 0,
     0, 0, 'M', 'J', 'U', 0, '(', 0,
     0, ';', 'K', 'I', 'O', '-', ')', 0,
     0, ':', '-', 'L', '~' /*Ñ*/, 'P', '?', 0,
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

const int DataPin = 4;
const int IRQpin =  2;

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

void setup() { 
  keyboard.begin(DataPin, IRQpin, PS2Keymap_Spanish);
  Serial.begin(9600);
  Serial.println("Arrancando!");
  lcd.init();  
  lcd.backlight();
  inicializarTexto();
  lcd.createChar(1,_enie);
  lcd.createChar(2,_enieMayus);
  lcd.noBlink();
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
      Serial.println();
      imprimirLinea();
    } else if(c == PS2_TAB){
      probarLetra();
      testIndex++;
    } else if (c == PS2_ESC) {
      Serial.print("[ESC]");
    } else if (c == PS2_PAGEDOWN) {
      Serial.print("[PgDn]");
    } else if (c == PS2_PAGEUP) {
      Serial.print("[PgUp]");
    } else if (c == PS2_LEFTARROW) {
      Serial.print("[Left]");
    } else if (c == PS2_RIGHTARROW) {
      Serial.print("[Right]");
    } else if (c == PS2_UPARROW) {
      Serial.print("[Up]");
    } else if (c == PS2_DOWNARROW) {
      Serial.print("[Down]");
    } else if (c == PS2_DELETE) {
      Serial.print("[Del]");
      borrarLetra();
    } else if (c == '='){
      creditos();  
    }else {
      if (testingChars){
        inicializarTexto();  
      }
      Serial.print(c);
      agregarLetra(c);
    }
  }
}
                                                                                                                                                                         void creditos(){tecladoActivo(false);lcd.clear();lcd.setCursor(0,0);lcd.print("Proyecto 2022");lcd.setCursor(0,1);lcd.print("Electronica.");delay(2000);lcd.clear();lcd.print("Integrantes:");delay(2000);lcd.clear();lcd.print("Emiliano");lcd.setCursor(0,1);lcd.print("Steppuhn");delay(2000);lcd.clear();lcd.print("Joaquin"); lcd.setCursor(0,1);lcd.print("Los");delay(2000);lcd.clear();lcd.print("Angel"); lcd.setCursor(0,1);lcd.print("Reyes");delay(2000);lcd.clear();lcd.print("Lucas");lcd.setCursor(0,1);lcd.print("Scocier");delay(2000);lcd.clear();tecladoActivo(true);}
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
  lcd.createChar(2,_enieMayus);  
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

void imprimirLinea(){
  lcd.clear();
  dibujarEscudo();
  lcd.print("IMPRIMIENDO...");
  delay(1000);
  lcd.clear();
  tecladoActivo(false);
  
	// PROCESO DE IMPRESION


  }
  // Mover espacio grande (Y)
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
