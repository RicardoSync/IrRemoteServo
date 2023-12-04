#include <IRremote.hpp>
#include <Servo.h>

#define IR_RECEIVE_PIN 2
Servo myservo;
int signal;
int pos = 0;
void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  myservo.attach(9);
}

void loop() {
  if (IrReceiver.decode()) {
    uint16_t command = IrReceiver.decodedIRData.command;
    Serial.println(command);
    signal = command;
    delay(100);  // wait a bit
    IrReceiver.resume();
  }
  if(signal == 22){
    myservo.write(180);
  }
  if(signal == 30){
    myservo.write(0);
    }
}
