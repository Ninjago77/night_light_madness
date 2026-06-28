#include <TM1637Display.h>

#define CLK 3
#define DIO 4

#define SPDT1 7
#define SPDT2 2
#define MODEBTN 8

#define LIGHT A3
#define POT A6

#define ACRYLIC_R 9
#define ACRYLIC_G 10
#define ACRYLIC_B 11

#define MODE_R A0
#define MODE_G A1
#define MODE_B A2

// const int RED[] = {255,0,0};
// const int GREEN[] = {0,255,0};
// const int BLUE[] = {0,0,255};
// const int MAGENTA[] = {127,0,127};
// const int YELLOW[] = {127,127,0};
// const int CYAN[] = {0,127,127};
// const int WHITE[] = {255,255,255};
// const int OFF[] = {0,0,0};

TM1637Display display = TM1637Display(CLK, DIO);
double interval = 10000.0; // ms
bool prevBtn = 0;
int mode = 0;
int hours_offset = 0;
int minutes_offset = 0;

int pwmC(int val, int mul) {
  int res = (val*mul)-1;
  if (res <= 0) {res = 0;}
  return res;
}

double mapExponential(double x, double in_min, double in_max, double out_min, double out_max) {
  double expValue = (double)(x - in_min) / (in_max - in_min);
  double mappedValue = pow(expValue, 2);
  return out_min + (mappedValue * (out_max - out_min));
}

double cycleStepGenerator(signed long ms, double interval) {
  int numerator = int(ms % long(interval));
  return numerator/interval;
}
double biDirectionalStepGenerator(signed long ms, double interval) {
  int numerator = int(ms % long(interval*2));
  return abs((numerator-interval)/interval);
}

void lerp(float color1[],float color2[],float value,float result[]){
  result[0] = color1[0] + (color2[0] - color1[0]) * value;
  result[1] = color1[1] + (color2[1] - color1[1]) * value;
  result[2] = color1[2] + (color2[2] - color1[2]) * value;
}

// void linearGradient(float stops[][3],float value,float result[]) { 
//     float stopLength = 1 / (sizeof(stops) - 1);
//     float valueRatio = value / stopLength;
//     int stopIndex = floor(valueRatio);
//     if (stopIndex == (sizeof(stops) - 1)) {
//         return stops[sizeof(stops) - 1];
//     }
//     float stopFraction = valueRatio-int(valueRatio);
//     lerp(stops[stopIndex], stops[stopIndex + 1], stopFraction,result);
// }

void modeColour(int curr_mode) {
  switch (curr_mode) {
    case (0):
      digitalWrite(MODE_R,HIGH);
      digitalWrite(MODE_G,HIGH);
      digitalWrite(MODE_B,HIGH);
      break;
    case (1):
      digitalWrite(MODE_R,HIGH);
      digitalWrite(MODE_G,HIGH);
      digitalWrite(MODE_B,LOW);
      break;
    case (2):
      digitalWrite(MODE_R,HIGH);
      digitalWrite(MODE_G,LOW);
      digitalWrite(MODE_B,HIGH);
      break;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  display.setBrightness(5);

  pinMode(SPDT1,INPUT);
  pinMode(SPDT2,INPUT);
  pinMode(MODEBTN,INPUT);

  pinMode(LIGHT,INPUT);
  pinMode(POT,INPUT);

  pinMode(ACRYLIC_R,OUTPUT);
  pinMode(ACRYLIC_G,OUTPUT);
  pinMode(ACRYLIC_B,OUTPUT);

  pinMode(MODE_R,OUTPUT);
  pinMode(MODE_G,OUTPUT);
  pinMode(MODE_B,OUTPUT);
}

void loop() {
  signed long milliseconds = (millis() % long(86400000))+(3600000*hours_offset)+(60000*minutes_offset);
  signed long math_only_ms = millis();
  int hours = milliseconds / 3600000;
  int minutes = (milliseconds % 3600000) / 60000;

  bool currbtn = digitalRead(MODEBTN);
  if (currbtn && !prevBtn) {
    mode++;
    if (mode >= 3) {mode = 0;}    
  }

  int pot = analogRead(POT); int intensity;
  // Serial.println(pot);
  if (mode != 0) {
    intensity = map(pot, 0, 1023, 0, 9);
    if (intensity >= 9) {intensity = 8;};
  }

  int light =  analogRead(LIGHT);

  bool spdt1 = digitalRead(SPDT1);
  bool spdt2 = digitalRead(SPDT2);

  // Serial.println(light);
  modeColour(mode);
  switch (mode) {
    case (0):
      analogWrite(ACRYLIC_R,0);
      analogWrite(ACRYLIC_G,0);
      analogWrite(ACRYLIC_B,0);
      if (spdt1 && spdt2) {
        intensity = map(pot, 0, 1023, 0, 24);
        if (intensity >= 24) {intensity = 23;};
        hours_offset = intensity;
      } else if (!spdt1 && !spdt2) {
        intensity = map(pot, 0, 1023, 0, 60);
        if (intensity >= 60) {intensity = 59;};
        minutes_offset = intensity;
      }
      break;
    case (1): // Pure Colours
      if (spdt1) {
        if (spdt2) {
          analogWrite(ACRYLIC_R,pwmC(32,intensity));
          analogWrite(ACRYLIC_G,pwmC(32,intensity));
          analogWrite(ACRYLIC_B,pwmC(32,intensity));
        } else {
          analogWrite(ACRYLIC_R,pwmC(32,intensity));
          analogWrite(ACRYLIC_G,0);
          analogWrite(ACRYLIC_B,0);
        }
      } else {
        if (spdt2) {
          analogWrite(ACRYLIC_R,0);
          analogWrite(ACRYLIC_G,pwmC(32,intensity));
          analogWrite(ACRYLIC_B,0);
        } else {
          analogWrite(ACRYLIC_R,0);
          analogWrite(ACRYLIC_G,0);
          analogWrite(ACRYLIC_B,pwmC(32,intensity));
        }
      }
      break;
    case (2):
      interval = double(mapExponential(int(pot/64), 0, 15, 100, 400)*10);
      Serial.println(interval);
      float color2[3]; // Declare color array here
      float startColor2[3] = {0};
      float endColor2[3] = {0};
      float step2 = biDirectionalStepGenerator(math_only_ms,interval);
      Serial.println(step2);
      if (spdt1) {
        if (spdt2) {
          startColor2[0] = 1.0;startColor2[1] = 1.0;startColor2[2] = 1.0;
          endColor2[0] = 0;endColor2[1] = 0;endColor2[2] = 0;
        } else {
          startColor2[0] = 1.0;startColor2[1] = 0;startColor2[2] = 0;
          endColor2[0] = 0;endColor2[1] = 1.0;endColor2[2] = 0;
        }
      } else {
        if (spdt2) {
          startColor2[0] = 0;startColor2[1] = 1.0;startColor2[2] = 0;
          endColor2[0] = 0;endColor2[1] = 0;endColor2[2] = 1.0;
        } else {
          startColor2[0] = 1.0;startColor2[1] = 0;startColor2[2] = 0;
          endColor2[0] = 0;endColor2[1] = 0;endColor2[2] = 1.0;
        }
      }
      lerp(startColor2, endColor2, step2, color2);
      analogWrite(ACRYLIC_R, color2[0] * 256);
      analogWrite(ACRYLIC_G, color2[1] * 256);
      analogWrite(ACRYLIC_B, color2[2] * 256);
      break;
    // case (3):
    //   interval = double(mapExponential(int(pot/64), 0, 15, 10, 300)*100);
    //   Serial.println(interval);
    //   float color3[3]; // Declare color array here
    //   float startColor3[3] = {0};
    //   float endColor3[3] = {0};
    //   float step3 = biDirectionalStepGenerator(math_only_ms,interval);
  }
  uint8_t dots;
  if ((millis()%1000) >= 500) {dots = 0;} else {dots = 0b01000000;}
  if ((mode == 0) && (spdt1 == spdt2)) {
    display.showNumberDecEx((hours*100)+minutes, dots, true, 4, 0);
  } else {
    display.showNumberDecEx((hours*100)+minutes, 0b01000000, true, 4, 0);
  }
  prevBtn = currbtn;
}

