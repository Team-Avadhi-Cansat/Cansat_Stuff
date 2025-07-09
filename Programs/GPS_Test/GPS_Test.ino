#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// Define GPS RX/TX pins (Use software serial for communication)
SoftwareSerial gpsSerial(4, 3); // (GPS TX to Arduino 4, GPS RX to Arduino 3)
TinyGPSPlus gps; // Create TinyGPS++ object

void setup() {
    Serial.begin(9600);  // Serial monitor
    gpsSerial.begin(9600);  // GPS module baud rate

    Serial.println("Waiting for GPS signal...");
}

void loop() {
    while (gpsSerial.available()) {
        gps.encode(gpsSerial.read()); // Feed GPS data to the parser

        if (gps.location.isUpdated()) { // Check if new data is available
            Serial.print("Latitude: ");
            Serial.print(gps.location.lat(), 6); // Print latitude with 6 decimal places
            Serial.print(" Longitude: ");
            Serial.println(gps.location.lng(), 6); // Print longitude with 6 decimal places
        }
    }
}
