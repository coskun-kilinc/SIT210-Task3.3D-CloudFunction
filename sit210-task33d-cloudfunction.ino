// This #include statement was automatically added by the Particle IDE.
#include "write_event.h"

int led = D7;

float elapsedTime = 0;

void doBlink( int numBlinks, int delayTime);

void readEvent(const char *event, const char *data);

void setup() {
    pinMode(led,OUTPUT);
    Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy",readEvent);
}


void readEvent(const char *event, const char *data)
{
    if (strcmp(data, "wave") == 0 ) 
    {
        writeEvent(String::format(event));
        doBlink(3, 200);
    }
    else if (strcmp(data, "pat") == 0 )
    {
        writeEvent(String::format(event));
        doBlink(8, 100);
    }
}

void doBlink( int numBlinks, int delayTime){
    for (int i = 0; i < numBlinks; i++){
        digitalWrite(led, HIGH);
        delay(delayTime);
        digitalWrite(led, LOW);
        delay(delayTime);
    }
}


void loop() {
    // Can be left empty, program will be triggered from subscribed event
}