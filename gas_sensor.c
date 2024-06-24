/*
    Project name : ESP32 GAS Sensor
    Modified Date: 24-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/esp32-gas-sensor
*/

const int gasSensorPin = 34;       // Analog pin connected to the gas sensor
const int calibrationFactor = 100; // Adjust this based on your sensor and setup
const int gasThreshold = 100;      // Threshold value to detect gas presence

void setup() {
  Serial.begin(115200);             // Initialize serial communication
  pinMode(gasSensorPin, INPUT);     // Set gas sensor pin as input
}

void loop() {
  // Read analog value from the gas sensor
  int gasValue = analogRead(gasSensorPin);

  // Calculate gas concentration based on sensor reading and calibration factor
  float gasConcentration = map(gasValue, 0, 4095, 0, calibrationFactor);

  // Print gas concentration to Serial Monitor
  Serial.print("Gas Concentration: ");
  Serial.print(gasConcentration);
  Serial.println(" ppm");

  // Check if gas concentration exceeds threshold
  if (gasConcentration > gasThreshold) {
    Serial.println("Gas detected!");
  } else {
    Serial.println("No gas detected.");
  }

  delay(1000); // Add a delay before the next reading
}
