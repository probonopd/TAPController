#include "TAPController.h"

TAPController::TAPController(Stream& serial) : _serial(serial) {}

// General Control Functions

void TAPController::printFirmwareRevisions() {
  _serial.println("tv");
}

void TAPController::printUCChecksum() {
  _serial.println("vr");
}

void TAPController::resetPCB() {
  _serial.println("rs");
}

void TAPController::resetDSPs() {
  _serial.println("rc");
}

void TAPController::resetCodec() {
  _serial.println("rd");
}

void TAPController::dumpEEPROMContents() {
  _serial.println("de");
}

void TAPController::writeEEPROMData(byte address, byte data) {
  _serial.print("we ");
  _serial.print(address, HEX);
  _serial.print(",");
  _serial.println(data, HEX);
}

void TAPController::recalculateEEPROMChecksum() {
  _serial.println("ce 0");
}

void TAPController::fillEEPROMWithData(byte data) {
  _serial.print("ef ");
  _serial.println(data, HEX);
}

void TAPController::selectInput(byte inputType, byte data1, byte data2) {
  _serial.print("sk ");
  _serial.print(inputType, HEX);
  _serial.print(",");
  _serial.print(data1, HEX);
  _serial.print(",");
  _serial.println(data2, HEX);
}

void TAPController::setVolume(byte volumeType, byte volumeValue) {
  _serial.print("sk 31,");
  _serial.print(volumeType, HEX);
  _serial.print(",");
  _serial.println(volumeValue, HEX);
}

void TAPController::muteAudio() {
  _serial.println("sk 31,4f,ff");
}

void TAPController::unmuteAudio() {
  _serial.println("sk 31,3f,ff");
}

void TAPController::selectAudioMode(byte mode) {
  _serial.print("tn ");
  _serial.print(mode, HEX);
  _serial.println(",0,0,0,0,0,0,0,0");
}

void TAPController::turnOff() {
  _serial.println("sk 3f,6f,ff");
}

// ADC Functions

void TAPController::printBassPotPosition() {
  _serial.println("ad 0");
}

void TAPController::printTreblePotPosition() {
  _serial.println("ad 1");
}

void TAPController::printThermistorVoltage() {
  _serial.println("ad 2");
}

void TAPController::print3_3VSupplyVoltage() {
  _serial.println("ad 3");
}

void TAPController::printSPDIFDetectVoltage() {
  _serial.println("ad 4");
}

void TAPController::printCodecReferenceVoltage() {
  _serial.println("ad 5");
}

void TAPController::printTwiddlerDCOffset() {
  _serial.println("ad 6");
}

void TAPController::printTurnOnSignalVoltage() {
  _serial.println("ad 7");
}

// Speaker Configurations

void TAPController::selectAUXInput() {
  _serial.println("sk 51,af,ff");
}

void TAPController::selectVID1Input() {
  _serial.println("sk 61,af,ff");
}

void TAPController::selectTAPEInput() {
  _serial.println("sk 42,af,ff");
}

void TAPController::select2SpeakerMode() {
  _serial.println("sk 31,d0,2f");
}

void TAPController::select3SpeakerMode() {
  _serial.println("sk 31,d0,3f");
}

void TAPController::select5SpeakerMode() {
  _serial.println("sk 31,d0,4f");
}

void TAPController::setVolume(byte volumeValue) {
  // Command format: sk 31,1x,xf
  // Set volume to -xx volume
  // Example: sk 31,10,0f  (00dB)
  //          sk 31,11,2f  (-12dB)
  //          sk 31,13,4f  (-34dB)

  // Convert the volume value to hexadecimal format
  String volumeHex = String(volumeValue, HEX);

  // Send the complete command to set the volume
  _serial.print("sk 31,1");
  _serial.println(volumeHex);
}

void TAPController::setCenterSurroundVolume(byte volumeValue) {
  // Command format: sk 31,9x,xf
  // Set center/surround volume
  // Example: sk 31,90,0f  (+7dB)
  //          sk 31,90,1f  (+6dB)
  //          sk 31,90,7f  (0dB)
  //          sk 31,91,4f  (-7dB)
  //          sk 31,91,5f  (-8dB)

  // Convert the volume value to hexadecimal format
  String volumeHex = String(volumeValue, HEX);

  // Send the complete command to set the center/surround volume
  _serial.print("sk 31,9");
  _serial.println(volumeHex);
}

void TAPController::volumeUp() {
  _serial.println("sk 31,1f,ff");
}

void TAPController::volumeDown() {
  _serial.println("sk 31,2f,ff");
}

void TAPController::surroundVolumeUp() {
  _serial.println("sk 31,9f,ff");
}

void TAPController::surroundVolumeDown() {
  _serial.println("sk 31,af,ff");
}
