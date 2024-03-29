/*
This sketch monitors and relays the state of inputPin to outputPin
A the high state can be maintained for a maximum of MAX_ACTIVATION_TIME.
Debounce can be commented in/out if (un)needed
*/



#define MAX_ACTIVATION_TIME 30000UL //miliseconds

const int inputPin = 2;
const int outputPin = 12;
unsigned long timeAtActivation=0;

void setup() {
 pinMode(inputPin, INPUT);
 pinMode(outputPin, OUTPUT);
 digitalWrite(outputPin,LOW); //start deactivated
}

void loop() {
	while(!digitalRead(inputPin)); //while low.
	//delay(20); //debounce ..
	timeAtActivation=millis();
	digitalWrite(outputPin,HIGH); //activate
	while(digitalRead(inputPin) && millis()<timeAtActivation+MAX_ACTIVATION_TIME); //while high && while MAX_ACTIVATION_TIME is not exceeded
	//delay(20); //debounce .. probably not needed
	digitalWrite(outputPin,LOW); //deactivate
	while(digitalRead(inputPin)); //wait for pin to go low... (only relevant if timer was maxed out)
	//delay(20); //debounce .. probably not needed
}
