void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
  

  Serial.println("hi im arduino");
  

}


void loop() {
  // put your main code here, to run repeatedly:
  char data;
   
  while (Serial.available())
  {
    data = Serial.read();
  }
  if (data == '1')
  {
    digitalWrite(13,1);
  }
  if (data == '0')
  {
    digitalWrite(13,0);
  }
 
}
