#include <string.h>
#include <time.h>

//data core
char cmp_donald[10] = "donald";
char cmp_david[10] = "david";
char cmp_unknown[10] = "unknown";
char data;

//output LEDs
int green1 = 8;
int green2 = 9;
int red = 10;

int donald_idx = 0;
int david_idx = 0;
int unknown_idx = 0;

bool greenLight = false;
bool redLight = false;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(green1, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(red, OUTPUT);

  for (int i = 8; i < 11; i++)
  {
    digitalWrite(i, HIGH);
    delay(200);
    digitalWrite(i, LOW);
  }
  
  delay(1000);
  

  Serial.println("Setup complete");
  

}


void loop() {
  // put your main code here, to run repeatedly:
  char data;

  
  while (Serial.available() > 0)
  {
    long time0 = millis();
    long time1 = time0+10;
    
    while (time1 - time0 < 1000)
    {
    data = Serial.read();
    if (data == cmp_donald[donald_idx])
      donald_idx++;

    if (data == cmp_david[david_idx])
      david_idx++;
      
    if (data == cmp_unknown[unknown_idx])
      unknown_idx++;

      time1 = millis();
    
    }
    triggered();
    light_em_up();
  }
 
}

//checks if our indices have grown enough that we've detected a keyword
void triggered()
{
  
  if (donald_idx == 6 || david_idx == 5)
  {
    greenLight = true;
    donald_idx = 0;
    david_idx = 0;
  }

  if (unknown_idx == 7)
  {
    redLight = true;
    unknown_idx = 0;
  }
}

void light_em_up()
{
  if (redLight && greenLight)
  {
    digitalWrite(green1, HIGH);
    digitalWrite(red, HIGH);
    delay(100);
    digitalWrite(green1, LOW);
    digitalWrite(red, LOW);

    redLight = false;
    greenLight = false;
    
    return;
  }

  if (redLight)
  {
    digitalWrite(red, HIGH);
    delay(100);
    digitalWrite(red, LOW);
    redLight = false;
  }

  if(greenLight)
  {
    digitalWrite(green1, HIGH);
    delay(100);
    digitalWrite(green1, LOW);
    greenLight = false;
  }
  
}

//this functions updates the relevant of the three idx counters
//if a char in the data core is found
void search_serialData()
{
    if (data == cmp_donald[donald_idx])
      donald_idx++;

    if (data == cmp_david[david_idx])
      david_idx++;
      
    if (data == cmp_unknown[unknown_idx])
      unknown_idx++;
}
