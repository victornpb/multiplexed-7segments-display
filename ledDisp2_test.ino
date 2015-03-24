
const uint8_t displayCount = 2;
const uint8_t displayCommonPins[2] = {A2, A3};
const uint8_t displayPins[8] = {
  11, //A
  10, //B
  8,  //C
  7,  //D
  6,  //E
  12, //F
  A0, //G
  9   //H (Point)
};


int num;


void setup() {
    
  sevenSeg_setup();
    
  sevenSeg_setNumber(100);
  sevenSeg_setDecimalPoint(false, 1);
  sevenSeg_setDecimalPoint(true, 0);
  
  num = 0;
}


void loop() {
  
  sevenSeg_displayHold(500);
  
  counting();
  
}


long previousMillis;
void counting(){
  
  unsigned long currentMillis = millis();
  
  if(currentMillis - previousMillis > 100){
    previousMillis = currentMillis;
    
    num = (num+1)%100;
    sevenSeg_setNumber(99-num);
  }
}

