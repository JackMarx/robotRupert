int led = 13;
int light = 1;

void setup()
{
 pinMode(led, OUTPUT);
}



void loop()
{
 if (light == 0)
   digitalWrite(led, HIGH);
   delay(1000); 
}
