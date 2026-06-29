# Build Guide - Night Light Madness
## Project Hierachy 
 - [`hardware/case`](./hardware/case): Contains all the 2d AutoCAD (*.dwg*) Design files to laser cut & glue together for making the case & the Acrylic Light Sheet.
 - [`hardware/pcb`](./hardware/pcb): Contains all the Electronics Fusion360 (*.f3z* imports to schematics & pcbs) to put on a pcb & attach/solder components & wires to.
 - [`software/`](./software/): Contains the Arduino Nano's Code to allow the inputs, RTC & Sensors to interact with the LEDs, Display & Buzzer via the Nano.
 - [`images/`](./images/): Contains all the Images taken of the Project or its components/parts.
 - [`README.md`](./README.md): Provides the introduction, features, usage & overview of the project as well as a gallery of pictures.
 - [`BUILDME.md`](./BUILDME.md): Provides the step-by-step guide to recreate the project / customize it for yourself.
 - [`List_of_Materials.md`](./List_of_Materials.md): Provides the components names required (&/or optional) for the making of the project.
## List of Materials
| Component Name | Quantity | Required + Note | Additional Notes |
| -------------- | -------- | --------------- | ---------------- |
| 1/4th Inch MDF | 1 Sheet  | Yes (but can be modified for other sizes in files) | To Laser Cut the Parts on the **Left** of [`hardware/case/nightlight.dwg`](./hardware/case/nightlight.dwg) |
| 1/8th Inch MDF | 1 Sheet  | Yes (but can be modified for other sizes in files) | To Laser Cut the Parts on the **Right** of [`hardware/case/nightlight.dwg`](./hardware/case/nightlight.dwg) |
| 1/4th Inch MDF | 3x ; 1 Sheet  | No (but suggested) | To Laser Cut [`hardware/case/guardrail.dwg`](./hardware/case/guardrail.dwg) |
| 1/4th Inch Acrylic | 1 Sheet  | Yes (but can be modified for taller sizes in files) | To Laser Cut a custom stencil of the size in [`hardware/case/lamp.dwg`](./hardware/case/lamp.dwg) |
| Potentiometer (& Dial) | 1x  | Yes (Dial optional) |
| TM1637 4-digit 7-segment Display | 1x | Yes |
| SPDT Switch | 2x | Yes |
| Pushbutton | 1x | Yes |
| Photoresistor | 1x | Yes |
| 10mm Diffused (or not) RGB LED | 1x | Yes |
| 5mm RGB LED | 7x +? | Yes | More/Less could be modified by changing a lot of files (also affects brightness!) |
| DS3231 RTC Module | 1x | No (however it could be present without the battery for shape) |
| CR2032 Lithium Coin Cell Battery | 1x | Not if RTC not present, or if not used |
| USB 2.0 A Male Breakout Board | 1x | No ( if C is present) | A minimum of one power input should be available |
| USB 2.0 C Male Breakout Board | 1x | No ( if A is present) | A minimum of one power input should be available |
| Buzzer Module | 1x | Not required if Alarm isn't needed |
| 10K Ohms Resistor | 4x | Yes |
| 180 Ohms Resistor | 2x | Yes |
| 100 Ohms Resistor | 4x | Yes |
| Arduino Nano | 1x | Yes | Knock-offs should be ok if they work |
## Build Guide
`TBD`
