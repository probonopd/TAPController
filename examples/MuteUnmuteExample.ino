#include <TAPController.h>

TAPController tap(Serial);

void setup() {
  Serial.begin(4800); // Start serial communication
}

void loop() {
  // Mute the audio
  tap.muteAudio();
  delay(5000); // Sleep for 5 seconds

  // Unmute the audio
  tap.unmuteAudio();
  delay(5000); // Sleep for 5 seconds
}
