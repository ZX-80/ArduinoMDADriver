# ArduinoMDADriver

This is a modified version of [Christophe Diericxs CGA library](https://github.com/christophediericx/ArduinoCGADriver), designed to work on IBM Monochrome Display Adapter (MDA) monitors. It allows an Arduino (UNO) to directly drive an MDA monitor at a 104x115 resolution, without any additional hardware.

<p align="center">
  <img src="https://user-images.githubusercontent.com/44975876/158313708-475a7604-bca5-4a43-9bf0-4d510a553cd3.png" width="90%" />
</p>

> *Compatibility note: As with the CGA library, this has only been tested with an UNO (ATMega328P based) Arduino board.

## Limitations

MDA uses a pixel clock of 16.257 MHz, but due to the Arduino Uno's comparatively slow speed of 16 MHz, it can only generate a monochrome image with a resolution of 104x115. The MDA standard technically supports a 2-bit grayscale image with a resolution of 720x350 (though not all monitors will support that).

In future I'd like to use a more powerful microcontroller such as the Raspberry Pi Pico. Having two cores, one handling serial IO, and the other handling video generation using the PIOs, could allow for a Hercules Graphics Card clone built solely from a single microcontroller.

# Wiring the MDA Connector

Wiring the Arduino to the MDA connector is very straightforward. The MDA pinout has 6 pins in total: 2 grounds (GND), Hsync, VSync, Video and Intensity.

Wire digital 8 to Video, digital 11 to HSync, digital 12 to VSync, and digital 9 to Intensity. Connect GND to GND.
