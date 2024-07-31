#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'A', 'B', 'C', 'D'},
  {'E', 'F', 'G', 'H'},
  {'I', 'J', 'K', 'L'},
  {'M', 'N', 'O', 'P'}
};
byte rowPins[ROWS] = {12, 11, 10, 9}; 
byte colPins[COLS] = {8, 7, 6, 5}; 
char alph[16] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};
float bluesScale[16] = {261.63, 311.13, 349.23, 369.99, 392.00, 466.16,523.25, 622.25, 698.46, 739.99, 783.99, 932.33,1046.50, 1244.50, 1396.91, 1479.98};
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup() {
  Serial.begin(9600);
  pinMode(4, OUTPUT);
}

void loop() {
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.println(customKey);
    for(int i = 0; i<16; i++){
      if(customKey == alph[i]){
        tone(4,bluesScale[i]);
        break;
      }
    }
  }
}
