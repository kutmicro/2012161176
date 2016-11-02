#include "LEDs.h"

void setup() {
    for(int i =0; i < DECODER_BITS; i++){
        pinMode(decoderPins[i], OUTPUT);
        digitalWrite(decoderPins[i], LOW);
    }
    for(int i = 0; i < LEDS_PER_ROW; i++){
        pinMode(cathodePins[i], OUTPUT);
        digitalWrite(cathodePins[i], LOW);
    }
    
    //set up jumper pins for initialization sequence
    pinMode(j1, INPUT);
    pinMode(j2, OUTPUT);
    digitalWrite(j2, LOW);
    
    //enable decoders
    pinMode(pEN, OUTPUT);
    digitalWrite(pEN, HIGH);
    
    int pattern = getPattern();
    
    run(pattern);   
}

void run(int jump){
   switch(jump){
     case 0:
       while(true){
         rand(updatePot());
       }
     case 1:
       while(true){
         allTest(updatePot());
       }
     case 2:
       while(true){
         infiniteSquare(updatePot());
       }
     case 3:
       while(true){
         bounceSquare(updatePot());
       }
   }
}

void loop() {
  //bounceSquare(100);
  //infiniteSquare(analogRead(A0));
  //rand(updatePot());
  //allTest(updatePot());
}

int updatePot(){
  (analogRead(POT_PIN))/4;
}

int getPattern(){
  return analogRead(POT_PIN) / 256;
  
}
