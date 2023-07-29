#include "TAPController.h"

TAPController::TAPController(Stream& serial) : _serial(serial) {}

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

void TAPController::printUCADCVoltage(byte x) {
  _serial.print("ad ");
  _serial.println(x, HEX);
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
  _serial.print("sk 31,d0,");
  _serial.println(mode, HEX);
}

void TAPController::turnOff() {
  _serial.println("sk 3f,6f,ff");
}

void TAPController::selectAUXInput(byte data1, byte data2) {
  selectInput(0x51, data1, data2);
}

void TAPController::selectVID1Input(byte data1, byte data2) {
  selectInput(0x61, data1, data2);
}

void TAPController::selectTAPEInput(byte data1, byte data2) {
  selectInput(0x42, data1, data2);
}

void TAPController::select2SpeakerMode() {
  selectAudioMode(0x2F);
}

void TAPController::select3SpeakerMode() {
  selectAudioMode(0x3F);
}

void TAPController::select5SpeakerMode() {
  selectAudioMode(0x4F);
}

void TAPController::setCenterSurroundVolume(byte volumeValue) {
  setVolume(0x9F, volumeValue);
}

void TAPController::volumeUp(byte step) {
  setVolume(0x1F, step);
}

void TAPController::volumeDown(byte step) {
  setVolume(0x2F, step);
}

void TAPController::surroundVolumeUp(byte step) {
  setVolume(0xAF, step);
}

void TAPController::surroundVolumeDown(byte step) {
  setVolume(0xBF, step);
}
