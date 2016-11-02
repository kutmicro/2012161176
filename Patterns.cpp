//#include "LEDs.h"

#define DISPLAY_TIME 10000


/**
 * Tests all LEDs, x -> y -> z
 */
void allTest(int milli){
  for(int k = 0; k < LEDS_PER_ROW; k++){
    for(int i = 0; i < LEDS_PER_ROW; i++){
      for(int j = 0; j < LEDS_PER_ROW; j++){
        displayCoord(j, i, k);
        delay(milli);
      }
    }
  }
}

/**
 * Display a random and delay the given time value 
 */
void rand(int milli){
  cathode(random(5));
  displayNum(random(25));  
  delay(milli);
}

/**
 * Bounce a pyrimid of squares from top to bottom, flattening at each end
 */
void bounceSquare(int milli){
  milli = milli + 1;
  
   long t = millis();

  // cascade squares from z=0 to z=4
  // collects squares on the same plane at begnning and end
  for(int z = -2; z < LEDS_PER_ROW; t = millis(), z++){
     while(millis() < t + milli){
       displaySquare(constrain(z+2, 0, 4), 0);
       displaySquare(constrain(z+1, 0, 4), 1);
       displaySquare(constrain(z  , 0, 4), 2);
     }
  }
  
  // cascade squares from z=4 to z=0
  t = millis();
  for(int z = 4; z > -3; t = millis(), z--){
     while(millis() < t + milli){
       displaySquare(constrain(z+2, 0, 4), 2);
       displaySquare(constrain(z+1, 0, 4), 1);
       displaySquare(constrain(z  , 0, 4), 0);
     }
  }

}


/**
 * An infinate tunnel illusion, 
 * squuares progress upward, and wrap back around to the bottom
 */
void infiniteSquare(int milli){
  long t = millis();
  int i;
  for(i = 0; true ;t = millis(), i++){
    milli = (analogRead(A0)/4) + 1;
    while(millis() < t + milli){
      displaySquare(((i+2)%LEDS_PER_ROW), 0);
      displaySquare(((i+1)%LEDS_PER_ROW), 1);
      displaySquare(((i  )%LEDS_PER_ROW), 2);
    }
  }

}
