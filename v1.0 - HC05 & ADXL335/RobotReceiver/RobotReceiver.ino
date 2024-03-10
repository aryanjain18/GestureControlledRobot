// Bluetooth HC-05 Connections
// HC-05 TX pin to Arduino RX pin (connects to pin 0 on most Arduino boards)
// HC-05 RX pin to Arduino TX pin (connects to pin 1 on most Arduino boards)
// HC-05 VCC pin to Arduino 5V
// HC-05 GND pin to Arduino GND

// L298N Motor Driver Connections ->ENA to 5V, ENB to 5V 
// 12V, 5V, GND
#define IN1 7 // Right Motor FWD
#define IN2 6 // Right Motor BCK
#define IN3 5 // Left Motor FWD
#define IN4 4 // Left Motor BCK

// LED Indicator Pin
#define led 13

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Set up pins for motor control and LED indicator
  pinMode(led, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  // Check if there is data available from Bluetooth
  if (Serial.available()) {
    // Read the received character
    char val = Serial.read();

    // Perform actions based on the received character
    if (val == 'F') {
      // Forward movement
      digitalWrite(led, HIGH); // Turn on LED indicator
      Serial.println("F");
      carForward();
    } 
    else if (val == 'L') {
      // Left movement
      digitalWrite(led, HIGH);
      Serial.println("L");
      carLeft();
    } 
    else if (val == 'B') {
      // Backward movement
      digitalWrite(led, HIGH);
      Serial.println("B");
      carBackward();
    } 
    else if (val == 'R') {
      // Right movement
      digitalWrite(led, HIGH);
      Serial.println("R");
      carRight();
    } 
    else if (val == 'S') {
      // Stop movement
      digitalWrite(led, LOW); // Turn off LED indicator
      Serial.println("S");
      carStop();
    }
  }
}

// Motor movement functions

void carForward() {
  // Set motor control pins for forward movement
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void carBackward() {
  // Set motor control pins for backward movement
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void carLeft() {
  // Set motor control pins for left movement
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void carRight() {
  // Set motor control pins for right movement
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void carStop() {
  // Stop the motors
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
