// pin tanımlamaları//
#define trigpin 13
#define echopin 2
#define ENBA     5
#define in1      3
#define in2      4
#define in3      9
#define in4      11
#define ENBB     12
//değişken tanımlaması//
int son,durum,i;




void setup() {
  Serial.begin(9600); 
  
  ////sensör pinlerinin ayarlanması//////
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ENBA, OUTPUT);
  pinMode(ENBB, OUTPUT);

  digitalWrite(ENBA, HIGH);
    digitalWrite(ENBB, HIGH);


}
/////sensör1 algılama fonksiyonu///
float sonarSensor ()
{  
  digitalWrite(trigpin, HIGH);
  delayMicroseconds (2);
  digitalWrite(trigpin,LOW);
  delayMicroseconds(10);
  son = pulseIn (echopin, HIGH);
  son = son/58.1;
  return(son);
 }
/////robot dur/////
  void robotdur()
{
    /*digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW); 
    */
    digitalWrite(ENBA, LOW);
    digitalWrite(ENBB, LOW);
    delay(500);
    digitalWrite(ENBA, HIGH);
    digitalWrite(ENBB, HIGH);
    
}
//////robot ileri fonksiyonu/////  
  void robotileri()
  {
    digitalWrite(in2, LOW);
    analogWrite(in1, 100);
    //digitalWrite(in1, HIGH);
    
    digitalWrite(in4, LOW);
    analogWrite(in3, 100);    
   // digitalWrite(in3, HIGH);
    

  }
  

/////robot ileri sağ////
  void robotsagileri()
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in4, LOW);
    analogWrite(in3, 100);
//digitalWrite(in3, HIGH);    
    
 }
/////robot sol ileri///////
void robotsolileri()
{
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}


void loop() 
{
  durum = sonarSensor ();
  Serial.println(durum);
 if(durum > 0 && durum< 20)
  {

    robotdur();
  
            durum = sonarSensor ();

    //for (i=0; i++; i<5)
   // {
    robotsagileri();
    //durum = sonarSensor ();
    delay(1000);
   // i++;

   // }
  }
    robotileri();

}
