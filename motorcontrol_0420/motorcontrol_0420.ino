#include <VNH3SP30.h>
VNH3SP30 Motor1;
#define RECV_PULSE_LENGTH_MIN  1000
#define RECV_PULSE_LENGTH_MAX 2000

//r3006sb pins
//#define CH1_PIN A0
#define CH2_PIN A1
// #define CH3_PIN A2
//#define CH4_PIN A3

// motor pins
#define M1_PWM 3    // pwm pin motor
#define M1_INA 4    // control pin INA
#define M1_INB 5    // control pin INB
#define M1_DIAG 6   // diagnose pins (combined DIAGA/ENA and DIAGB/ENB)
#define M1_CS A5    // current sense pin

//int CH1_value = 0;
int CH2_value = 0;
// int CH3_value = 0;
//int CH4_value = 0;

void setup() {
  //pinMode(CH1_PIN, INPUT);
  pinMode(CH2_PIN, INPUT);
  //   pinMode(CH3_PIN, INPUT);
  //pinMode(CH4_PIN, INPUT);

  Motor1.begin(M1_PWM, M1_INA, M1_INB, M1_DIAG, M1_CS);    // Motor 1 object connected through specified pins
  //pinMode(Mswi, INPUT);

  Serial.begin(38400);
}

void loop() {
  //CH1_value = pulseIn(CH1_PIN,HIGH);
  CH2_value = pulseIn(CH2_PIN, HIGH);
  // CH3_value = pulseIn(CH3_PIN,HIGH);
  //CH4_value = pulseIn(CH4_PIN,HIGH);


  // Serial.print("CH1 value = ");
  // Serial.print(CH1_value);
  // int Ch1_percent = map(CH1_value, RECV_PULSE_LENGTH_MIN, RECV_PULSE_LENGTH_MAX, 0, 100);
  // Serial.print(" ( ");
  // Serial.print(Ch1_percent);
  // Serial.print(" %) ");

//  Serial.print("CH2 value = ");
//  Serial.print(CH2_value);
  int Ch2 = map(CH2_value, RECV_PULSE_LENGTH_MIN, RECV_PULSE_LENGTH_MAX, -400, 400);
  //Ch2 = constrain(Ch2, -400, 400);
//  Serial.print(" ( ");
//  //Serial.print(Ch2_percent);
//  Serial.print(" %) ");

  // Serial.print("CH3 value = ");
  // Serial.print(CH3_value);
  // int Ch3 = map(CH3_value, RECV_PULSE_LENGTH_MIN, RECV_PULSE_LENGTH_MAX, -400, 400);
  // Serial.print(" ( ");
  // Serial.print(Ch3_percent);
  // Serial.print(" %) ");

  // Serial.print("CH4 value = ");
  // Serial.print(CH4_value);
  // int Ch4_percent = map(CH4_value, RECV_PULSE_LENGTH_MIN, RECV_PULSE_LENGTH_MAX, 0, 100);
  // Serial.print(" ( ");
  // Serial.print(Ch4_percent);
  // Serial.println(" %) ");
  // delay(100);

  Serial.println(Ch2);
  //Motor1.setSpeed(Ch2);
  delay(500); // wait for 2 seconds
  Serial.print("Current="); Serial.println(Motor1.motorCurrent());
}
