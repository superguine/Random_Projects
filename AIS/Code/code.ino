// Pin Definitions

const int moistureSensorPin = A0; // Analog pin connected to sensor
const int pumpPin = 8;            // Digital pin to control the pump (via transistor or relay)

// Threshold for dry soil
const int drySoilThreshold = 500; // Adjust this value based on your sensor readings

void setup() {
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, LOW);  // Start with pump OFF
  Serial.begin(9600);          // For debugging
}

void loop() {
  int moistureLevel = analogRead(moistureSensorPin);

  // Print the moisture level to Serial Monitor
  Serial.print("Moisture Level: ");
  Serial.println(moistureLevel);

  if (moistureLevel < drySoilThreshold) {
    // Soil is dry, turn ON the pump
    digitalWrite(pumpPin, HIGH);
    Serial.println("Pump ON - Soil is dry");
  } else {
    // Soil has enough moisture, turn OFF the pump
    digitalWrite(pumpPin, LOW);
    Serial.println("Pump OFF - Soil is wet");
  }

  delay(1000); // Wait 1 second before next reading
}
