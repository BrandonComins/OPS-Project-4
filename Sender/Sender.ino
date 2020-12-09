#define buttonRed 3
#define buttonGreen 5

int buttonRedState = 0;
int buttonGreenState = 0;

char red = '1';
char green = '2';
char none = '3';

void setup() {
  Serial.begin(9600);
  pinMode(buttonRed, INPUT_PULLUP);
  pinMode(buttonGreen, INPUT_PULLUP);
}

void loop() {
  buttonRedState = digitalRead(buttonRed);
  buttonGreenState = digitalRead(buttonGreen);

  if(buttonRedState == 1){
    Serial.write(red);
  }else if(buttonGreenState == 1){
    Serial.write(green);
  }
  else{
    Serial.print(none);
  }
  delay(200);
}
