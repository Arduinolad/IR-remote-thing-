
#include "IRremote.h"
int led = 9;
int y = 0;
const int RECV_PIN = 4;
 
IRrecv irrecv(RECV_PIN);
decode_results results;
 
void setup(){
  Serial.begin(9600);
  // Enable the IR Receiver
  irrecv.enableIRIn();
}
void loop(){
  if (irrecv.decode(&results)){
        Serial.println(results.value, HEX);
        delay(10);
        switch(results.value)
        case 0xFFA25D:
        if(y==0){
        digitalWrite(led,HIGH);
        y = 1;
        }
        else {
          digitalWrite(led,LOW);
          y = 0;
        }
        irrecv.resume();

        
  }
}