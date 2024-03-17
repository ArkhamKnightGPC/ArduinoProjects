// Define the input pin for LDR and output pin for Buzzer
#define LDR A0
#define BUZZER 3

#define time_unit 75

void setup(){
  pinMode(BUZZER, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  
  int analogVoltage = analogRead(LDR);
  float voltage = (analogVoltage / 1023.0);

  float toneBuzzer = 100 + 1000*voltage;
  tone(BUZZER, toneBuzzer);

  Serial.print("Buzzer tone: "); //check buzzer control value
  Serial.println(toneBuzzer);

  delay(2*time_unit);
  noTone(BUZZER);
  delay(time_unit);
}
