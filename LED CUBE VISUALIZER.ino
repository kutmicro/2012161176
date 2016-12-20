#define countAmount 500
int x=1;
int y;
int temp;
  //initializing and declaring led rows
int column[16]={13,12,11,10,9,8,7,6,5,4,3,2,0,1,A5,A4};
  //initializing and declaring led layers
int layer[4]={A0,A1,A2,A3};
int counter=0;
int layerCount=0;
int time = 0;

void setup() {
  for(int i = 0; i<16; i++)
  {
    pinMode(column[i], OUTPUT);
  }
  //setting layers to output
  for(int i = 0; i<4; i++)
  {
    pinMode(layer[i], OUTPUT);
  }
}

void loop() {
    temp = analogRead(A15);
    x=map(temp, 0, 255, 0, 64);
    y=map(temp, 0, 255, 0, 3);
    if (x==0){
      //does nothing
    }
    else if(x<16){
      ledOnSingle(x-1,y,time);
    }
    else if(x>16 && x<=32){
      ledOnSingle(x-17,y,time);
    }
    else if(x>32 && x<=48){
      ledOnSingle(x-33,y,time);
    }
    else{
      ledOnSingle(x-49,y,time);
    }
        delay(time);
      turnEverythingOff();   
}

void ledOff(int x, int y, int t){
  digitalWrite(column[x], 1);
  digitalWrite(layer[y], 0); 
}

void ledOn(int x, int y, int t){
  for(int i=0; i<x; i++){
    digitalWrite(column[i], 0);
  }
  for(int i=0; i<y; i++){
    digitalWrite(layer[i], 1);  
  }
}


void ledOnSingle(int x, int y, int t){
    digitalWrite(column[x], 0);
    digitalWrite(layer[y], 1);  
}

void turnEverythingOff() {
   for(int i = 0; i<16; i++){
     digitalWrite(column[i], 1);
   }
   for(int i = 0; i<4; i++){
     digitalWrite(layer[i], 0);
   }
 }


void turnEverythingOn(){
  for(int i = 0; i<16; i++){
    digitalWrite(column[i], 0);
  }
  //turning on layers
  for(int i = 0; i<4; i++){
    digitalWrite(layer[i], 1);
  }
}

void turnOneOn(){
  for(int i = 0; i<16; i++){
    digitalWrite(column[i], 0);
  }
  //turning on layers
    digitalWrite(layer[3], 1);
}

void turnTwoOn(){
  for(int i = 0; i<16; i++){
    digitalWrite(column[i], 0);
  }
  //turning on layers
    digitalWrite(layer[2], 1);
}

void turnThreeOn(){
  for(int i = 0; i<16; i++){
    digitalWrite(column[i], 0);
  }
  //turning on layers
    digitalWrite(layer[1], 1);
}
