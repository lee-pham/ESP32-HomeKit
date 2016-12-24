int led1 = D0;
int led2 = D1;


void setup()
{

   pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);


   Particle.function("led",ledToggle);

   digitalWrite(led1, LOW);
   digitalWrite(led2, LOW);

}



void loop()
{
   // Nothing to do here
}

int onoff = false;
int ledToggle(String command) {


    if (command=="ping" && onoff==false) {
        digitalWrite(led1,HIGH);
        delay(500);
        digitalWrite(led1,LOW);
        onoff = true;
        return 1;
    }
    else {
        digitalWrite(led2,HIGH);
        delay(500);
        digitalWrite(led2,LOW);
        onoff = false;
        return 0;
    }
}
