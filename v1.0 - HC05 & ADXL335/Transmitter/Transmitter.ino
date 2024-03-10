// Connections for Bluetooth HC-05
// HC-05 TX pin to Arduino RX pin (connects to pin 0 on most Arduino boards)
// HC-05 RX pin to Arduino TX pin (connects to pin 1 on most Arduino boards)
// HC-05 VCC pin to Arduino 5V
// HC-05 GND pin to Arduino GND

// Define the analog pin connections for ADXL335 - 3.3v, GND
#define x A0 // X-axis to Arduino A0
#define y A1 // Y-axis to Arduino 5V

// Variables to store sensor values
int x_val;
int y_val;

// Initial sensor values for calibration
int x_valinit;
int y_valinit;

void setup() {
  // Set the pin modes for input
  pinMode(x, INPUT);
  pinMode(y, INPUT);

  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Read initial sensor values for calibration after 5 seconds
  delay(5000);
  x_valinit = analogRead(x);
  y_valinit = analogRead(y);
}

void loop() {
  // Read current sensor values
  x_val = analogRead(x);
  y_val = analogRead(y);

  // Calculate the difference between current and initial values for calibration
  int x_axis = x_val - x_valinit;
  int y_axis = y_val - y_valinit;

  // Check for movement in the X-axis
  if (x_axis >= 40) {
    Serial.println("Forward");
  } 
  else if (x_axis <= -40) {
    Serial.println("Backward");
    
  }

  // Check for movement in the Y-axis
  else if (y_axis >= 40) {
    Serial.println("Left");
  } 
  else if (y_axis <= -40) {
    Serial.println("Right");
  }
  
  // No significant movement
  else {
    Serial.println("Still");
    // Add Bluetooth code to send "S" for still over Bluetooth
  }

  // Delay for stability
  delay(200);
}
