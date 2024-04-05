#define BUZZER_PIN 3

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set the buzzer pin as an output
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // Read analog values from pins A5, A4, A3, A2, and A1
  int signal_A5 = analogRead(A5);
  int signal_A4 = analogRead(A4);
  int signal_A3 = analogRead(A3);
  int signal_A2 = analogRead(A2);
  int signal_A1 = analogRead(A1);

  // Print the name of the analog pin if value is > 1020
  if (signal_A5 > 1020) {
    Serial.println("A5 HIGH");
    playSoundEffect();
  }
  if (signal_A4 > 1020) {
    Serial.println("A4 HIGH");
    playSoundEffect();
  }
  if (signal_A3 > 1020) {
    Serial.println("A3 HIGH");
    playSoundEffect();
  }
  if (signal_A2 > 1020) {
    Serial.println("A2 HIGH");
    playSoundEffect();
  }
  if (signal_A1 > 1020) {
    Serial.println("A1 HIGH");
    playSoundEffect();
  }

  // Add some delay to prevent overwhelming the serial output
  delay(100);
}

void playSoundEffect() {
  // Play a cool sound effect using the buzzer
  tone(BUZZER_PIN, 1000, 200); // You can adjust the frequency and duration as per your preference
  delay(200); // Add a small delay between tones for a better effect
}
