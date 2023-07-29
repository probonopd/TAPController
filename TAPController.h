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
  void printBassPotPosition();
  void printTreblePotPosition();
  void printThermistorVoltage();
  void print3_3VSupplyVoltage();
  void printSPDIFDetectVoltage();
  void printCodecReferenceVoltage();
  void printTwiddlerDCOffset();
  void printTurnOnSignalVoltage();

  // Speaker Configurations
  void selectAUXInput();
  void selectVID1Input();
  void selectTAPEInput();
  void select2SpeakerMode();
  void select3SpeakerMode();
  void select5SpeakerMode();
  void setCenterSurroundVolume(byte volumeValue);
  void volumeUp();
  void volumeDown();
  void surroundVolumeUp();
  void surroundVolumeDown();

private:
  Stream& _serial;
};

#endif
