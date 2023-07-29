#ifndef TAPController_h
#define TAPController_h

#include <Arduino.h>

class TAPController {
public:
  TAPController(Stream& serial);

  // General Control Functions
  void printFirmwareRevisions();
  void printUCChecksum();
  void resetPCB();
  void resetDSPs();
  void resetCodec();
  void dumpEEPROMContents();
  void writeEEPROMData(byte address, byte data);
  void recalculateEEPROMChecksum();
  void fillEEPROMWithData(byte data);
  void selectInput(byte inputType, byte data1, byte data2);
  void setVolume(byte volumeType, byte volumeValue);
  void muteAudio();
  void unmuteAudio();
  void selectAudioMode(byte mode);
  void turnOff();

  // ADC Functions
  // Individual functions for different ADC types
  void printBassPotPosition();
  void printTreblePotPosition();
  void printThermistorVoltage();
  void print3_3VSupplyVoltage();
  void printSPDIFDetectVoltage();
  void printCodecReferenceVoltage();
  void printTwiddlerDCOffset();
  void printTurnOnSignalVoltage();

  // Speaker Configurations
  void selectAUXInput(byte data1, byte data2);
  void selectVID1Input(byte data1, byte data2);
  void selectTAPEInput(byte data1, byte data2);
  void select2SpeakerMode();
  void select3SpeakerMode();
  void select5SpeakerMode();
  void setCenterSurroundVolume(byte volumeValue);
  void volumeUp(byte step);
  void volumeDown(byte step);
  void surroundVolumeUp(byte step);
  void surroundVolumeDown(byte step);

private:
  Stream& _serial;
};

#endif
