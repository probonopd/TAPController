# TAPController Library

![License](https://img.shields.io/github/license/probonopd/TAPController)
![Version](https://img.shields.io/github/v/release/probonopd/TAPController)

Control Bose Acoustimass module over serial port using TAP commands.

## Features

- Mute and unmute the audio.
- Control volume settings for different channels.
- Select input sources for the Bose Acoustimass module.
- Switch between different speaker configurations.
- Read ADC port voltages for specific parameters.
- Dump and modify EEPROM contents.

## Disclaimer

The TAPController library is provided as-is, without any guarantees or warranties. It is intended for educational and experimental purposes and shall be used at your own risk. The library provides control over the Bose Acoustimass module via a serial interface, and improper usage may lead to undesired behavior or potential damage to the hardware. Before using this library, we strongly advise you to read the service manual of the Bose Acoustimass module and fully understand its functionality and limitations. The author and contributors of this library are not liable for any damages or issues that may arise from using this library with the Bose Acoustimass module. Always exercise caution and responsibility when interacting with hardware components.

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

- `serial`: The Stream object representing the serial port to communicate with the Bose Acoustimass module.

### void muteAudio()

Mutes the audio output of the Bose Acoustimass module.

### void unmuteAudio()

Unmutes the audio output of the Bose Acoustimass module.

### void selectInput(uint8_t inputCode)

Selects an input source for the Bose Acoustimass module.

- `inputCode`: The input code representing the desired input source.

### void setVolume(int8_t volume)

Sets the volume level for the Bose Acoustimass module.

- `volume`: The volume level to be set. Valid range: -80 to 12 (representing -80dB to +12dB).

### void setCenterSurroundVolume(int8_t centerVolume, int8_t surroundVolume)

Sets the volume levels for the center and surround channels.

- `centerVolume`: The volume level for the center channel. Valid range: -80 to 12 (representing -80dB to +12dB).
- `surroundVolume`: The volume level for the surround channel. Valid range: -80 to 12 (representing -80dB to +12dB).

### void setSpeakerMode(uint8_t speakerMode)

Sets the speaker mode for the Bose Acoustimass module.

- `speakerMode`: The speaker mode code representing the desired configuration.

### uint8_t readADC(uint8_t adcPort)

Reads the voltage from a specific ADC port of the Bose Acoustimass module.

- `adcPort`: The ADC port number to read voltage from.

Returns: The 8-bit ADC reading representing the voltage value (0 to 255).

### void dumpEEPROM()

Dumps the contents of the EEPROM from the Bose Acoustimass module over the serial port.

### void writeEEPROM(uint8_t address, uint8_t data)

Writes a single byte of data to a specific address in the EEPROM of the Bose Acoustimass module.

- `address`: The EEPROM address to write data to.
- `data`: The data byte to be written.

### void calculateEEPROMChecksum()

Recalculates and stores the checksum of the EEPROM data in the Bose Acoustimass module.

### void fillEEPROM(uint8_t data)

Fills the entire EEPROM of the Bose Acoustimass module with the specified data.

- `data`: The data byte to fill the EEPROM with.

### void resetPCB()

Resets the PCB (Printed Circuit Board) of the Bose Acoustimass module.

### void resetDSPs()

Resets the DSPs (Digital Signal Processors) of the Bose Acoustimass module.

### void resetCodec()

Resets the audio codec of the Bose Acoustimass module.

### void requestDSPChecksumCalculation()

Requests the DSP checksum calculation from the Bose Acoustimass module.

### void fetchDSPChecksum(uint8_t dspNumber, uint8_t address)

Fetches and prints the checksum calculation of a specific DSP.

- `dspNumber`: The DSP number (1 or 2) for which the checksum calculation is requested.
- `address`: The address to fetch the checksum calculation from.

### void select2SpeakerMode()

Selects the 2-speaker mode configuration.

### void select3SpeakerMode()

Selects the 3-speaker mode configuration.

### void select5SpeakerMode()

Selects the 5-speaker mode configuration.

### void selectOffMode()

Turns off the audio output of the Bose Acoustimass module.

### void passthroughAllSignalProcessing()

Sets the Bose Acoustimass module in passthrough mode with all signal processing enabled.

### void passthroughNoSignalProcessing()

Sets the Bose Acoustimass module in passthrough mode with no signal processing.

### void exitTestMode()

Exits the test mode and restores normal signal processing.

### void turnOnSignal()

Triggers the turn-on signal in the Bose Acoustimass module.

### void turnOffSignal()

Triggers the turn-off signal in the Bose Acoustimass module.

### void DRCOn()

Enables Dynamic Range Compression (DRC) in the Bose Acoustimass module.

### void DRCOff()

Disables Dynamic Range Compression (DRC) in the Bose Acoustimass module.

### void oneToFiveOn()

Enables the 1-to-5 mode in the Bose Acoustimass module.

### void oneToFiveOff()

Disables the 1-to-5 mode in the Bose Acoustimass module.

### void printStatus()

Prints the current status of the Bose Acoustimass module.

### void resetAll()

Resets all configurations in the Bose Acoustimass module to default values.

### void setBassPotPosition(uint8_t position)

Sets the position of the bass potentiometer.

- `position`: The position value for the bass potentiometer (0 to 255).

### void setTreblePotPosition(uint8_t position)

Sets the position of the treble potentiometer.

- `position`: The position value for the treble potentiometer (0 to 255).

### void setThermistorVoltage(uint8_t voltage)

Sets the voltage value for the thermistor.

- `voltage`: The voltage value for the thermistor (0 to 255).

### void setSupplyVoltage(uint8_t voltage)

Sets the voltage value for the 3.3V supply.

- `voltage`: The voltage value for the 3.3V supply (0 to 255).

### void setSPDIFDetectVoltage(uint8_t voltage)

Sets the voltage value for the SPDIF detect.

- `voltage`: The voltage

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
