#include <TinyGPS++.h>

// Define GPS RX/TX pins (connect GPS TX to Teensy RX1, GPS RX to Teensy TX1)
#define GPS_SERIAL Serial1  // Use Serial1 for hardware UART

TinyGPSPlus gps; // Create TinyGPS++ object

void setup() {
    Serial.begin(9600);  // Serial monitor for debugging
    GPS_SERIAL.begin(9600);  // Start communication with GPS module

    Serial.println("Waiting for GPS signal...");
}

void loop() {
    while (GPS_SERIAL.available()) {
        gps.encode(GPS_SERIAL.read()); // Feed GPS data to the parser

        if (gps.location.isUpdated()) { // Check if new data is available
            Serial.print("Latitude: ");
            Serial.print(gps.location.lat(), 6); // Print latitude with 6 decimal places
            Serial.print(" Longitude: ");
            Serial.println(gps.location.lng(), 6); // Print longitude with 6 decimal places
        }
    }
}
