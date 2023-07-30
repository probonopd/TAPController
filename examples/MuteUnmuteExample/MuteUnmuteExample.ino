#include <SoftwareSerial.h>
#include "TAPController.h"

// Define SoftwareSerial object with RX and TX pins
// Use pin 2 for RX (receive) and pin 3 for TX (transmit) for TAP communication
SoftwareSerial tapSerial(2, 3);

void setup() {
  Serial.begin(115200); // Initialize normal serial communication at 115200 baud for debugging
  tapSerial.begin(4800); // Set the baud rate to 4800 for SoftwareSerial communication
  delay(1000); // Wait for the TAPController to initialize
}

void loop() {
  // Mute the audio
  tapController.muteAudio();
  Serial.println("Audio muted");
  delay(3000); // Wait for 3 seconds

  // Unmute the audio
  tapController.unmuteAudio();
  Serial.println("Audio unmuted");
  delay(3000); // Wait for 3 seconds
}
