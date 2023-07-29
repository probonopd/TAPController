# TAPController Library

![License](https://img.shields.io/github/license/yourusername/TAPController)
![Version](https://img.shields.io/github/v/release/yourusername/TAPController)

Control Bose Acoustimass module over serial port using TAP commands.

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

### Class: TAPController

- `TAPController(Stream& serial);`: Constructor to initialize the TAPController with the provided `Stream` object for serial communication.

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
