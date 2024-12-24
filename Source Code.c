/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <DHT.h>

// Pin Definitions
#define DHTPIN 2        // Pin connected to the DHT sensor
#define DHTTYPE DHT22   // DHT 22 (AM2302) sensor
#define FAN_RELAY 3     // Pin connected to the fan relay
#define HEATER_RELAY 4  // Pin connected to the heater relay

// Thresholds
#define TEMP_HIGH_THRESHOLD 30.0  // Temperature in °C to turn ON the fan
#define TEMP_LOW_THRESHOLD 20.0   // Temperature in °C to turn ON the heater

// Initialize the DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Initialize the DHT sensor
  dht.begin();

  // Initialize the relay pins as outputs
  pinMode(FAN_RELAY, OUTPUT);
  pinMode(HEATER_RELAY, OUTPUT);

  // Turn off relays initially
  digitalWrite(FAN_RELAY, LOW);
  digitalWrite(HEATER_RELAY, LOW);
}

void loop() {
  // Read temperature and humidity from the DHT sensor
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check if the readings are valid
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print readings for debugging
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C ");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Control fan and heater based on temperature
  if (temperature > TEMP_HIGH_THRESHOLD) {
    digitalWrite(FAN_RELAY, HIGH);  // Turn ON fan
    digitalWrite(HEATER_RELAY, LOW); // Ensure heater is OFF
    Serial.println("Fan ON, Heater OFF");
  } else if (temperature < TEMP_LOW_THRESHOLD) {
    digitalWrite(HEATER_RELAY, HIGH); // Turn ON heater
    digitalWrite(FAN_RELAY, LOW);    // Ensure fan is OFF
    Serial.println("Heater ON, Fan OFF");
  } else {
    // Turn off both if within range
    digitalWrite(FAN_RELAY, LOW);
    digitalWrite(HEATER_RELAY, LOW);
    Serial.println("Fan OFF, Heater OFF");
  }

  // Delay before the next reading
  delay(7000);
}
