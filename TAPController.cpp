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

void TAPController::selectAUXInput(byte data1, byte data2) {
  _serial.print("sk 51,");
  _serial.print(data1, HEX);
  _serial.println("," + String(data2, HEX));
}

void TAPController::selectVID1Input(byte data1, byte data2) {
  _serial.print("sk 61,");
  _serial.print(data1, HEX);
  _serial.println("," + String(data2, HEX));
}

void TAPController::selectTAPEInput(byte data1, byte data2) {
  _serial.print("sk 42,");
  _serial.print(data1, HEX);
  _serial.println("," + String(data2, HEX));
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

void TAPController::setCenterSurroundVolume(byte volumeValue) {
  _serial.print("sk 31,9");
  _serial.println(volumeValue, HEX);
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
