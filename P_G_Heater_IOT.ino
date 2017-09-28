float tempC;
float reading;
float tempPin = 0;
float sum = 0;
float avg=0;
float power = 0;
int time = 0;

void setup() {
analogReference(INTERNAL);
Serial.begin(9600);
}

void loop() {
  if (Serial.available())
{
  if (Serial.read()=='F')
   { 
     
    for(int i=0;i<10;i++)
     { 
       delay ( 100);
       reading = analogRead(tempPin);
       delay ( 100 ); 
       tempC = reading / 9.31;
       delay ( 100 );
       sum = tempC + sum;
      }
            
    delay ( 100 );
    avg = sum / 10 ;
    delay ( 100 );
    power = ( 4.2 * 50 * (60 - avg) )/3600;
    delay ( 100 );
    power = power *60;
    delay ( 100 );
    time = power / 12;
    delay ( 100 );
    Serial.println(time);
    delay (100);
    reading = 0;
    tempC = 0;
    sum = 0;
    avg = 0;
  }
}
     }

