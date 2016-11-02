#define MICRO 20

void displaySquare(int z, int square){
  switch(square){
    case 2:
      displaySquareBig(z);
      break;
    case 1:
      displaySquareSmall(z);
      break;
    case 0:
      displaySquareCenter(z);
  }
}

void displaySquareCenter(int z){
  cathode(z);
  displayNum(12);
}

void displaySquareSmall(int z){
  cathode(z);
  displayNum(6);
  displayNum(7);
  displayNum(8);
  
  displayNum(11);
  displayNum(13);
  
  displayNum(16);
  displayNum(17);
  displayNum(18);
}

void displaySquareBig(int z){
  cathode(z);
  displayCoord(0, 0);
  displayCoord(1, 0);
  displayCoord(2, 0);
  displayCoord(3, 0);
  displayCoord(4, 0);
  displayCoord(4, 1);
  displayCoord(4, 2);
  displayCoord(4, 3);
  displayCoord(4, 4);
  displayCoord(0, 4);
  displayCoord(1, 4);
  displayCoord(2, 4);
  displayCoord(3, 4);
  displayCoord(0, 1);
  displayCoord(0, 2);
  displayCoord(0, 3);
  
/*  
  int i=0, j=0;
  while(i < LEDS_PER_ROW)
    displayCoord(i++, j);
  while(j < LEDS_PER_ROW)
    displayCoord(i, ++j);
  i = 0;
  j = 0;
  while(j < LEDS_PER_ROW)
    displayCoord(i, j++);
  while(i < LEDS_PER_ROW)
    displayCoord(i++, j);
    */
}


//////// Utility Functions \\\\\\\\\\

/**
 * Displays the LED at the given x, y, z coordinate.
 */
void displayCoord(int x, int y, int z){
  cathode(z);
  displayNum(y * LEDS_PER_ROW + x);
}

/**
 * Displays the anode column at the given x, y coordiate. 
 * Cathode must be handled seperately.
 */
void displayCoord(int x, int y){
  //convert x, y coordinate to corrresponding number value
  displayNum(y * LEDS_PER_ROW + x);
}

/**
 * Displays the anode column with the given number value; [0, 24].
 * @author ajmontag
 */
void displayNum(int num){
  //constrain the argument to be between 0 and 24 inclusive.
  num = constrain(num, 0, 24);
  
  /*
   * AND: selects the bit, the bit at weight will be 1 if the pin is to be high
   * >>: shifts the selected bit to the end of the word, making the value a 0 or 1
   * first result is lsb
   * digitalWrite: write the approptiate result (HIGH or LOW) to the appropriate decoder pin
   */
  for(int weight=1, pin=0; pin < DECODER_BITS; weight*=2, pin++)
    digitalWrite(decoderPins[pin] ,(num & weight) >> pin);
  
  //delay, this is the absoloute minimum time the light will be displayed. 
  //ensures adiquate delay for decoders as well. 
  delayMicroseconds(MICRO);
}

/**
 * z < 0: no layers enabled
 * 0 < z < LEDS_PER_ROW : only the layer at z will be enabled
 * z >= LEDS_PER_ROW: all layers enabled
 */
void cathode(int z){
  for(int i = 0; i < LEDS_PER_ROW; i++){
    if(i == z || z >= LEDS_PER_ROW){
      digitalWrite(cathodePins[i], HIGH);
    }else{
       digitalWrite(cathodePins[i], LOW);
    }
  }
}


