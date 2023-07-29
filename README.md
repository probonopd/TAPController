# TAPController Library for Arduino

![License](https://img.shields.io/github/license/probonopd/TAPController)
![Version](https://img.shields.io/github/v/release/probonopd/TAPController)

Control Bose Acoustimass modules over serial port using TAP commands.

__NOTE:__ There is a product recall for Bose Acoustimass modules. See [here](https://global.bose.com/en_us/bm_safety_contact_en.html) for details.

## Features

- Mute and unmute the audio.
- Control volume settings for different channels.
- Select input sources for the Bose Acoustimass module.
- Switch between different speaker configurations.
- Read ADC port voltages for specific parameters.
- Dump and modify EEPROM contents.

## Disclaimer

The TAPController library is provided as-is, without any guarantees or warranties. It is intended for educational and experimental purposes and shall be used at your own risk. The library provides control over the Bose Acoustimass module via a serial interface, and improper usage may lead to undesired behavior or potential damage to the hardware. Before using this library, we strongly advise you to read the service manual ("Troubleshooting Guide Powered Acoustimass® -25 and -30 Series II Speaker System AM-25P II/ AM-30P II Digital Bass Module", Part Number 199401-TG1) and fully understand the functionality and limitations of the hardware. The author and contributors of this library are not liable for any damages or issues that may arise from using this library with the Bose Acoustimass module. Always exercise caution and responsibility when interacting with hardware components.

## Installation

To use the TAPController library, you can install it through the Arduino Library Manager or PlatformIO.

### Arduino Library Manager (Arduino IDE)

1. Open the Arduino IDE.
2. Go to `Sketch` -> `Include Library` -> `Manage Libraries`.
3. Search for "TAPController" and click `Install`.

### PlatformIO (VSCode or Atom)

1. Add the following line to the `lib_deps` section in your `platformio.ini` file:
   ```ini
   lib_deps =
       TAPController

## Usage

```cpp
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
```

## API Reference

### TAPController(Stream &serial)

Constructor to create an instance of the TAPController class.

### General Control Functions

- `void printFirmwareRevisions()`: Print firmware revisions.
- `void printUCChecksum()`: Print uC checksum.
- `void resetPCB()`: Reset PCB.
- `void resetDSPs()`: Reset DSPs.
- `void resetCodec()`: Reset codec.
- `void dumpEEPROMContents()`: Dump the contents of EEPROM.
- `void writeEEPROMData(byte address, byte data)`: Write data "data" (hex) to EEPROM address "address" (hex).
- `void recalculateEEPROMChecksum()`: Re-calculate and store EEPROM checksum.
- `void fillEEPROMWithData(byte data)`: Fill EEPROM with data "data" (hex).
- `void selectInput(byte inputType, byte data1, byte data2)`: Select input type with custom data "inputType" (hex), "data1" (hex), and "data2" (hex).
- `void setVolume(byte volumeType, byte volumeValue)`: Set volume with "volumeType" (hex) and "volumeValue" (hex).
- `void muteAudio()`: Mute audio.
- `void unmuteAudio()`: Un-mute audio.
- `void selectAudioMode(byte mode)`: Select audio mode with "mode" (hex).
- `void turnOff()`: Turn off.

### ADC Functions

- `void printBassPotPosition()`: Print uC ADC port voltage for bass pot position.
- `void printTreblePotPosition()`: Print uC ADC port voltage for treble pot position.
- `void printThermistorVoltage()`: Print uC ADC port voltage for thermistor voltage.
- `void print3_3VSupplyVoltage()`: Print uC ADC port voltage for 3.3V supply.
- `void printSPDIFDetectVoltage()`: Print uC ADC port voltage for SPDIF detect.
- `void printCodecReferenceVoltage()`: Print uC ADC port voltage for codec reference voltage.
- `void printTwiddlerDCOffset()`: Print uC ADC port voltage for Twiddler DC offset.
- `void printTurnOnSignalVoltage()`: Print uC ADC port voltage for turn-on signal.

### Speaker Configurations

- `void selectAUXInput()`: Select AUX input (digital).
- `void selectVID1Input()`: Select VID1 input (analog).
- `void selectTAPEInput()`: Select TAPE input (analog).
- `void select2SpeakerMode()`: Select 2-speaker mode.
- `void select3SpeakerMode()`: Select 3-speaker mode.
- `void select5SpeakerMode()`: Select 5-speaker mode.
- `void setVolume(byte volumeValue)`: Set normal volume with "volumeValue" (hex).
- `void setCenterSurroundVolume(byte volumeValue)`: Set center/surround volume with "volumeValue" (hex).
- `void volumeUp()`: Volume up 1dB.
- `void volumeDown()`: Volume down 1dB.
- `void surroundVolumeUp()`: Center/surround volume up (3-speaker / 5-speaker).
- `void surroundVolumeDown()`: Center/surround volume down.

### **WARNINGS**:

- The functions `writeEEPROMData`, `recalculateEEPROMChecksum`, and `fillEEPROMWithData` modify the contents of the EEPROM. Be cautious while using them.
- This library interacts directly with hardware and can have potential risks. Use it at your own risk, and make sure to consult the service manual before making any changes to the hardware.

## TAP Commands

| TAP Command                  | Description                                                |
|-----------------------------|------------------------------------------------------------|
| tv                          | print firmware revisions                                   |
| vr                          | print uC checksum                                          |
| rs                          | reset pcb                                                  |
| rc                          | reset DSPs                                                 |
| rd                          | reset codec                                                |
| de                          | dump the contents of EEPROM                                |
| we xx,yy                    | Write data "xx" (hex) to EEPROM address "yy" (hex)          |
| ce 0                        | re-calculate and store EEPROM checksum                     |
| ef xx                       | fill EEPROM with data "xx" (hex)                            |
| sk 51,af,ff                 | select AUX input (digital)                                 |
| sk 61,af,ff                 | select VID1 input (analog)                                 |
| ad x                        | print uC ADC port voltage, where "x" equals:<br>0    bass pot position<br>1    treble pot position<br>2    thermistor voltage<br>3    3.3V supply<br>4    SPDIF detect<br>5    codec reference voltage<br>6    twddler DC offset<br>7    turn-on signal<br>(result is 8-bit, 0=0V, FF=5V)|
| sk 42,af,ff                 | select TAPE input (analog)                                 |
| sk 31,1f,ff                 | volume up 1dB                                             |
| sk 31,2f,ff                 | volume down 1dB                                           |
| sk 31,1x,xf                 | set volume to -xx volume<br>e.g.<br>sk 31,10,0f  00dB<br>sk 31,11,2f  -12dB<br>sk 31,13,4f  -34dB|
| sk 31,9f,ff                 | center/surround volume up (3-speaker / 5-speaker)          |
| sk 31,af,ff                 | center/surround volume down                                |
| sk 31,9x,xf                 | set center/surround volume<br>e.g.,<br>sk 31,90,0f  +7dB<br>sk 31,90,1f  +6dB<br>sk 31,90,7f   0dB<br>sk 31,91,4f  -7dB<br>sk 31,91,5f  -8dB|
| sk 31,4f,ff                 | mute                                                       |
| sk 31,3f,ff                 | un-mute                                                    |
| sk 31,d0,2f                 | select 2-speaker mode                                      |
| sk 31,d0,3f                 | select 3-speaker mode                                      |
| sk 31,d0,4f                 | select 5-speaker mode                                      |
| sk 3f,6f,ff                 | off                                                        |
| tn 3,0,0,0,0,0,0,0,0        | passthrough, with all signal processing                   |
| tn 6,0,0,0,0,0,0,0,0        | passthrough, with no signal processing                    |
| tn 0,0,0,0,0,0,0,0,0        | exit test mode, restore normal signal processing          |
| tn 4,0,0,0,0,0,0,0,0        | request DSP checksum calculation                           |
| dp 10,0,2,0,12              | fetch and print DSP checksum calculation                    |
| dp 10,0,0,0,0               | peek at DSP 1 address 0                                    |
| dp 20,0,0,0,0               | peek at DSP 2 address 0                                    |
| sk 31,ex,yf                 | x=8  2-speaker<br>x=9  3-speaker<br>x=A  5-speaker<br>y=4 single bits, as follows<br>DRC off/on<br>1_to_5 off/on|

Source: Bose manual Part Number 199401-TG1 pp. 80

## Contributing

We welcome contributions to the TAPController library and appreciate your interest in improving it. If you would like to contribute, please follow these guidelines:

1. Fork the repository and create a new branch for your contributions.
1. Make your changes or add new features to the library.
1. Ensure that your code adheres to the library's coding standards and conventions.
1. Submit a pull request to the main repository with a clear description of the changes you made.
1. Your pull request will be reviewed by the maintainers, and any necessary feedback will be provided.
1. Once your changes are approved, they will be merged into the main branch and become part of the library.

By contributing to the TAPController library, you're helping to make it better for everyone in the community. Thank you for your support!

## License

This project is licensed under the BSD 2-Clause License. See the [LICENSE](LICENSE) file for details.

## Credits

- Author: probono <probono@puredarwin.org>
- Repository: [https://github.com/probonopd/TAPController](https://github.com/probonopd/TAPController)
- Lifestyle: [https://github.com/probonopd/Lifestyle/](https://github.com/probonopd/Lifestyle/)
- Thanks to: @741Z for [pointing out](https://github.com/probonopd/Lifestyle/issues/2#issuecomment-1656711850) some initial commands
