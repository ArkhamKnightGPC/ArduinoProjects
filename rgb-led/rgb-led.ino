// Define the output pin for each LED
#define BLUE 3
#define GREEN 5
#define RED 6

void setRed(){
  digitalWrite(RED    , HIGH);
  digitalWrite(GREEN  , LOW);
  digitalWrite(BLUE   , LOW);
}

void setGreen(){
  digitalWrite(RED    , LOW);
  digitalWrite(GREEN  , HIGH);
  digitalWrite(BLUE   , LOW);
}

void setBlue(){
  digitalWrite(RED    , LOW);
  digitalWrite(GREEN  , LOW);
  digitalWrite(BLUE   , HIGH);
}

//we represent the LED state using a state machine
enum ledState{
  red, green, blue
};
ledState state;

//at each loop, we perform a transition to the next state
void updateState(){
  switch(state){
    case red:
      setRed();
      state = green;
      break;
    case green:
      setGreen();
      state = blue;
      break;
    case blue:
      setBlue();
      state = red;
      break;
  }
}

void setup() {
  // put your setup code here, to run once:

  //set all pins to output
  pinMode(RED   , OUTPUT);
  pinMode(GREEN , OUTPUT);
  pinMode(BLUE  , OUTPUT);

  //set initial state value
  state = red;
}

void loop() {
  // put your main code here, to run repeatedly:

  updateState();//change the LED color

  delay(2000);//each color shines for 2s, then changes again
}
