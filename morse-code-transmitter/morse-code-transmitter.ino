// Define the output pin for each LED and for buzzer
#define BLUE 3
#define GREEN 5
#define RED 6
#define BUZZER 9

//Define morse code terminology
#define DOT 1
#define DASH 2
#define SPACE_CHARS 3
#define SPACE_WORDS 4
#define MARK_NEXT 5
#define END 6

//Define the message to be transmitted in Morse
String message = "BOXE";
int message_length, position;

#define time_unit 500
/*
Short (dot): 1 unit
Long (dash): 3 units
Space between parts of the same letter: 1 unit
Space between letters within a word: 3 units
Space between words: 7 units
*/

void setRed(){
  digitalWrite(RED    , HIGH);
  digitalWrite(GREEN  , LOW);
  digitalWrite(BLUE   , LOW);
}

void setYellow(){
  digitalWrite(RED    , HIGH);
  digitalWrite(GREEN  , HIGH);
  digitalWrite(BLUE   , LOW);
}

void setNothing(){
  digitalWrite(RED    , LOW);
  digitalWrite(GREEN  , LOW);
  digitalWrite(BLUE   , LOW);
}


// Function to convert a character to Morse code
int* charToMorse(char c) {
  switch(c) {
    case 'A':
    case 'a':
      return new int[4]{DOT, DASH, SPACE_CHARS, MARK_NEXT};
    case 'B':
    case 'b':
      return new int[6]{DASH, DOT, DOT, DOT, SPACE_CHARS, MARK_NEXT};
    case 'C':
    case 'c':
      return new int[6]{DASH, DOT, DASH, DOT, SPACE_CHARS, MARK_NEXT};
    case 'D':
    case 'd':
      return new int[5]{DASH, DOT, DOT, SPACE_CHARS, MARK_NEXT};
    case 'E':
    case 'e':
      return new int[3]{DOT, SPACE_CHARS, MARK_NEXT};
    case 'F':
    case 'f':
      return new int[6]{DOT, DOT, DASH, DOT, SPACE_CHARS, MARK_NEXT};
    case 'G':
    case 'g':
      return new int[5]{DASH, DASH, DOT, SPACE_CHARS, MARK_NEXT};
    case 'H':
    case 'h':
      return new int[6]{DOT, DOT, DOT, DOT, SPACE_CHARS, MARK_NEXT};
    case 'I':
    case 'i':
      return new int[4]{DOT, DOT, SPACE_CHARS, MARK_NEXT};
    case 'J':
    case 'j':
      return new int[6]{DOT, DASH, DASH, DASH, SPACE_CHARS, MARK_NEXT};
    case 'K':
    case 'k':
      return new int[5]{DASH, DOT, DASH, SPACE_CHARS, MARK_NEXT};
    case 'L':
    case 'l':
      return new int[6]{DOT, DASH, DOT, DOT, SPACE_CHARS, MARK_NEXT};
    case 'M':
    case 'm':
      return new int[4]{DASH, DASH, SPACE_CHARS, MARK_NEXT};
    case 'N':
    case 'n':
      return new int[4]{DASH, DOT, SPACE_CHARS, MARK_NEXT};
    case 'O':
    case 'o':
      return new int[5]{DASH, DASH, DASH, SPACE_CHARS, MARK_NEXT};
    case 'P':
    case 'p':
      return new int[6]{DOT, DASH, DASH, DOT, SPACE_CHARS, MARK_NEXT};
    case 'Q':
    case 'q':
      return new int[6]{DASH, DASH, DOT, DASH, SPACE_CHARS, MARK_NEXT};
    case 'R':
    case 'r':
      return new int[5]{DOT, DASH, DOT, SPACE_CHARS, MARK_NEXT};
    case 'S':
    case 's':
      return new int[5]{DOT, DOT, DOT, SPACE_CHARS, MARK_NEXT};
    case 'T':
    case 't':
      return new int[3]{DASH, SPACE_CHARS, MARK_NEXT};
    case 'U':
    case 'u':
      return new int[5]{DOT, DOT, DASH, SPACE_CHARS, MARK_NEXT};
    case 'V':
    case 'v':
      return new int[6]{DOT, DOT, DOT, DASH, SPACE_CHARS, MARK_NEXT};
    case 'W':
    case 'w':
      return new int[5]{DOT, DASH, DASH, SPACE_CHARS, MARK_NEXT};
    case 'X':
    case 'x':
      return new int[6]{DASH, DOT, DOT, DASH, SPACE_CHARS, MARK_NEXT};
    case 'Y':
    case 'y':
      return new int[6]{DASH, DOT, DASH, DASH, SPACE_CHARS, MARK_NEXT};
    case 'Z':
    case 'z':
      return new int[6]{DASH, DASH, DOT, DOT, SPACE_CHARS, MARK_NEXT};
    case ' ':
      return new int[2]{SPACE_WORDS, MARK_NEXT};
    default:
      return new int[2]{END, MARK_NEXT}; // End of string
  }
}

void transmitDot(){
  setYellow();
  tone(BUZZER, 500);
  delay(time_unit);
  setNothing();
  noTone(BUZZER); 
  delay(time_unit);
}

void transmitDash(){
  setYellow();
  tone(BUZZER, 500);
  delay(3*time_unit);
  setNothing();
  noTone(BUZZER);
  delay(time_unit);
}

void transmitSpaceBetweenChars(){
  setNothing();
  delay(2*time_unit);//one was already done at the end of character
}

void transmitSpaceBetweenWords(){
  setNothing();
  delay(6*time_unit);//one was already done at the end of character
}

void transmitEnd(){
  setRed();
  delay(3*time_unit);
  setNothing();
  delay(3*time_unit);
}

void setup() {
  //set all pins to output
  pinMode(RED   , OUTPUT);
  pinMode(GREEN , OUTPUT);
  pinMode(BLUE  , OUTPUT);
  pinMode(BUZZER, OUTPUT);

  //initialize variables
  message_length = message.length();
  position = 0;
}

void loop(){

  int* morse = charToMorse(message[position]);

  for (int i = 0; morse[i] != MARK_NEXT; i++){
    int symbol = morse[i];
    if(symbol == DOT){
      transmitDot();
    }else if(symbol == DASH){
      transmitDash();
    }else if(symbol == SPACE_CHARS){
      transmitSpaceBetweenChars();
    }else if(symbol == SPACE_WORDS){
      transmitSpaceBetweenWords();
    }
  }

  position = (position + 1)%message_length;//move to next character

  if(position == 0){
    transmitEnd();
  }

  delete[] morse; // Deallocate memory
}
