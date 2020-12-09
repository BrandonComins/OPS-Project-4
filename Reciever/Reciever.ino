#define LED_Green 7
#define LED_Red 8
#define LED_White 9

char income;
char red = '1';
char green = '2';
int x;
int points = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_Green, OUTPUT);
  pinMode(LED_Red, OUTPUT);
  pinMode(LED_White, OUTPUT);
  Serial.println("Starting Game");
  allOff();
  
}

void loop() {
    x = random(1,10);
    //turn on green LED 50% of the time
    if(x%2==0){
      onlyGreen();
      Serial.println("Green");
      buttonWait();
      //If the button input button is green then add a point
      if(income == green){
        digitalWrite(LED_White, HIGH);
        points++;
        Serial.print("Total Points: ");
        Serial.println(points);
        delay(1000);
      //if the input button is red then lose the game 
      }else{
        reset();
      }
    //Turn on RED LED 50% of the time
    }else{
      onlyRed();
      Serial.println("red");
      buttonWait();
      //Of the button input is Red then add a point
      if(income == red){
        digitalWrite(LED_White, HIGH);
        points++;
        Serial.print("Total Points: ");
        Serial.println(points);
        delay(1000);
      //if the button is green then lose the game
      }else{
        reset();
      }
    }
    allOff();
    delay(random(1000, 3000));
}



void onlyGreen(){
  digitalWrite(LED_Green, HIGH);
  digitalWrite(LED_Red, LOW);
  digitalWrite(LED_White, LOW);
}

void onlyRed(){
  digitalWrite(LED_Green, LOW);
  digitalWrite(LED_Red, HIGH);
  digitalWrite(LED_White, LOW);
}

void onlyWhite(){
  digitalWrite(LED_Green, LOW);
  digitalWrite(LED_Red, LOW);
  digitalWrite(LED_White, HIGH);
}

void allOff(){
  digitalWrite(LED_Green, LOW);
  digitalWrite(LED_Red, LOW);
  digitalWrite(LED_White, LOW);
}

void reset(){
  onlyWhite();
  Serial.print("Total Points: ");
  Serial.println(points);
  Serial.println("You lose! Restarting game...");
  points = 0;
  delay(5000);
}

void buttonWait(){
  while(1){
    income = Serial.read();
    if(income == red || income == green){
      return;
    }
  }
}

//void checkPointTwo(){
//  if(Serial.available()){
//    income = Serial.read(); 
//    if(income == green){
//      digitalWrite(LED_Green, HIGH);
//    }else if(income == red ){
//      digitalWrite(LED_Red, HIGH);
//    }
//    delay(20);
//    digitalWrite(LED_Red, LOW);
//    digitalWrite(LED_Green, LOW);
//  }
//}
