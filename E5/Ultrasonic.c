#define TRIG_PIN 9
#define ECHO_PIN 8

#define LED1 4
#define LED2 5
#define LED3 6
#define PIEZO 7  // LED4 is now piezo

void setup() {
  Serial.begin(9600);

  // LED pins
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(PIEZO, OUTPUT);

  // Ultrasonic pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  long duration, cm;

  // Trigger the ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo
  duration = pulseIn(ECHO_PIN, HIGH);
  cm = microsecondsToCentimeters(duration);

  Serial.print("Mesafe: ");
  Serial.print(cm);
  Serial.println(" cm");

  // LED & Piezo logic
  if (cm <= 15) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);

    // Simple beep for piezo
    tone(PIEZO, 1000); // 1 kHz tone
  } else if (cm > 15 && cm <= 30) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);

    noTone(PIEZO); // stop piezo
  } else if (cm > 30) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);

    noTone(PIEZO);
  } else {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);

    noTone(PIEZO);
  }

  delay(100);
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
