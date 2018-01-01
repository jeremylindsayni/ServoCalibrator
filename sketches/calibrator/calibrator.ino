#include <Adafruit_PWMServoDriver.h>
#define analogIn A0

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int inputValue = 0;
int tmpPwmValue = 0;

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);
}

void loop() {
  inputValue = analogRead(analogIn);

  // inputValue will be between 0 and 1024
  // By observation, servo min and max PWM values are usually betwee 100 and 612
  // The formula below allows us to simply convert analog input to PWM
  int pwmValue = (int)(100 + (inputValue / 2));
  pwm.setPWM(0, 0, pwmValue);

  // Check to make sure we're not unnecessarily displaying duplicate data
  if (pwmValue != tmpPwmValue)
  {
    Serial.print("Potentiometer Input = ");
    Serial.print(inputValue);
    Serial.print(", PWM = ");
    Serial.println(pwmValue);
  }

  tmpPwmValue = pwmValue;

  delay(15);
}
