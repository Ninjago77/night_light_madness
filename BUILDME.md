# Build Guide - Night Light Madness
## Project Hierachy 
 - [`hardware/case`](./hardware/case): Contains all the 2d AutoCAD (*.dwg*) Design files to laser cut & glue together for making the case & the Acrylic Light Sheet.
 - [`hardware/pcb`](./hardware/pcb): Contains all the Electronics Fusion360 (*.f3z* imports to schematics & pcbs) to put on a pcb & attach/solder components & wires to.
 - [`software/`](./software/): Contains the Arduino Nano's Code to allow the inputs, RTC & Sensors to interact with the LEDs, Display & Buzzer via the Nano.
 - [`images/`](./images/): Contains all the Images taken of the Project or its components/parts.
 - [`README.md`](./README.md): Provides the introduction, features, usage & overview of the project as well as a gallery of pictures.
 - [`BUILDME.md`](./BUILDME.md): Provides the list of materials & the step-by-step guide to recreate the project / customize it for yourself.
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
## Build Gallery
<img width="300" alt="WhatsApp Image 2026-06-29 at 01 42 47 (5)" src="https://github.com/user-attachments/assets/5ba1ce1e-3cd5-4ab5-adbe-26150fbdd77b" /><img width="300" alt="WhatsApp Image 2026-06-29 at 01 42 47 (4)" src="https://github.com/user-attachments/assets/6972bbcf-f809-4977-94e7-3122fec6e59e" /><img width="300" alt="WhatsApp Image 2026-06-29 at 01 42 47 (3)" src="https://github.com/user-attachments/assets/c385a259-dc06-4e08-8422-ea3386b635c6" />
<img width="300" alt="WhatsApp Image 2026-06-29 at 01 42 47 (2)" src="https://github.com/user-attachments/assets/ae2fda05-c0a7-4c35-8a25-8f137bb8c360" /><img width="300" alt="WhatsApp Image 2026-06-29 at 01 42 47 (1)" src="https://github.com/user-attachments/assets/829cf177-f107-497f-ab09-4dc4380441e6" /><img width="300" alt="WhatsApp Image 2026-06-29 at 01 42 47" src="https://github.com/user-attachments/assets/b7eaec2f-dc8e-4d4d-892e-b805d10089be" />
## Screenshot Gallery
<img width="300" alt="Screenshot 2026-06-29 014729" src="https://github.com/user-attachments/assets/1077f443-e8e0-4aa8-8302-67ad88e8b3f0" /><img width="300" alt="Screenshot 2026-06-29 014659" src="https://github.com/user-attachments/assets/7b6fd6ea-82e5-4c28-9545-0349b1d35156" /><img width="300" alt="Screenshot 2026-06-29 014647" src="https://github.com/user-attachments/assets/0800a5f0-a7dd-476c-be52-ccdfff739cec" />
<img width="300" alt="Screenshot 2026-06-29 015546" src="https://github.com/user-attachments/assets/e98ef020-e1d7-4c9b-ab31-91619d9fb240" /><img width="300" alt="Screenshot 2026-06-29 015536" src="https://github.com/user-attachments/assets/ab4ac06c-b857-481c-be0e-897458b848ac" /><img width="300" alt="Screenshot 2026-06-29 015512" src="https://github.com/user-attachments/assets/9d1514be-d836-42f0-86b6-896f30d8d05e" />
<img width="300" alt="Screenshot 2026-06-29 015504" src="https://github.com/user-attachments/assets/02bc869c-8bac-4db5-9586-e0064ad1e76a" /><img width="300" alt="Screenshot 2026-06-29 015451" src="https://github.com/user-attachments/assets/09dfdd05-bf8d-4d71-a959-46692938582f" /><img width="300" alt="Screenshot 2026-06-29 015241" src="https://github.com/user-attachments/assets/d838be15-f07c-445a-8102-44132a2ade96" />
<img width="300" alt="Screenshot 2026-06-29 015300" src="https://github.com/user-attachments/assets/d86ecc83-8e15-42d3-88b3-4787b5db404c" /><img width="300" alt="Screenshot 2026-06-29 015154" src="https://github.com/user-attachments/assets/861de0e1-2531-4f73-96f2-b9999e28e0c8" /><img width="300" alt="Screenshot 2026-06-29 015133" src="https://github.com/user-attachments/assets/994ffd2e-51d3-4610-9760-dcc0efb248b6" />
