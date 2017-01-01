int led1 = D0;
int led2 = D1;
int led3 = D2;
int led4 = D3;


void setup()
{

   pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);
   pinMode(led3, OUTPUT);
   pinMode(led4, OUTPUT);
   

   Particle.function("led", ledToggle);
   Particle.function("led1", ledToggle1);

   digitalWrite(led1, LOW);
   digitalWrite(led2, LOW);
   digitalWrite(led3, LOW);
   digitalWrite(led4, LOW);

}

void loop()
{
   // Nothing to do here
}

int onoff = false;
int ledToggle(String command) {


    if (command=="ping" && onoff==false) {
        digitalWrite(led1, HIGH);
        delay(500);
        digitalWrite(led1, LOW);
        onoff = true;
        return 1;
    }
    else {
        digitalWrite(led2, HIGH);
        delay(500);
        digitalWrite(led2, LOW);
        onoff = false;
        return 0;
    }
}

int onoff1 = false;
int ledToggle1(String command) {


    if (command=="ping" && onoff1==false) {
        digitalWrite(led3, HIGH);
        delay(500);
        digitalWrite(led3, LOW);
        onoff1 = true;
        return 1;
    }
    else {
        digitalWrite(led4, HIGH);
        delay(500);
        digitalWrite(led4, LOW);
        onoff1 = false;
        return 0;
    }
}
