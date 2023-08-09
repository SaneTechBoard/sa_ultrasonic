const int TRIG_PIN = 7; 
const int ECHO_PIN = 8; 
const int LED_PIN1  = 3;
const int LED_PIN2  = 4;
const int LED_PIN3  = 5;
const int LED_PIN4  = 6;
float duration_us, distance_cm;

void setup() {
  Serial.begin (9600);       
  pinMode(TRIG_PIN, OUTPUT); 
  pinMode(ECHO_PIN, INPUT);  
  for (int i = 3; i < 7 ; i++){
    pinMode(i, OUTPUT);
  }  
}

void loop() {
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration_us = pulseIn(ECHO_PIN, HIGH);

  distance_cm = 0.017 * duration_us;

  if(distance_cm < 10)
    digitalWrite(LED_PIN1, HIGH);
  else
    digitalWrite(LED_PIN1, LOW);
  if(distance_cm < 8)
    digitalWrite(LED_PIN2, HIGH);
  else
    digitalWrite(LED_PIN2, LOW);
  if(distance_cm < 7)
    digitalWrite(LED_PIN3, HIGH);
  else
    digitalWrite(LED_PIN3, LOW);
  if(distance_cm < 5)
    digitalWrite(LED_PIN4, HIGH);
  else
    digitalWrite(LED_PIN4, LOW);
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
  delay(500);
}
