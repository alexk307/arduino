
int startR = 0;
int startG = 0;
int startB = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

  int randomR = random(1, 255);
  int randomG = random(1, 255);
  int randomB = random(1, 255);

  int done = 0;
  while(!done){
    if(randomR != startR){
      delay(10);
      if(randomR > startR){
        startR += 1;
      }
      else{
        startR -= 1; 
      }
      analogWrite(3, startR);
    }
    if(randomG != startG){
      if(randomG > startG){
        startG += 1;
      }
      else{
        startG -= 1;
      }
      analogWrite(6, startG);
      
    }
    if(randomB != startB){
      if(randomB > startB){
        startB+=1;
      }
      else{
        startB-=1;
      }
      analogWrite(5, startB); 
      
    } 
    delay(10);  

    if((randomB == startB) && (randomR == startR) && (randomG == startG)){
        done = 1;
        delay(200);
        startR = randomR;
        startG = randomG;
        startB = randomB;
    }
  }
}
