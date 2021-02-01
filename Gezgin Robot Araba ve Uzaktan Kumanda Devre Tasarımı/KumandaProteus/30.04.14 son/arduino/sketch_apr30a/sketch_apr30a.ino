int potansiyometre= A0; // pot'un portu
int motor=6,deger; // okuyup süreceğimiz değer
 
void setup() {
  Serial.begin(9600);
  pinMode(motor,OUTPUT);
}
 
void loop() {
deger= analogRead(potansiyometre);//pot'tan değer analog değer okuması
Serial.println(deger);
delay(500);
deger= map(deger, 0, 1023, 0, 225);//okunan değerin belirli değere oranlanması
analogWrite(motor, deger);//oranlanan değerin 5.Porttan PWM çıkışı olarak verilmesi
delay(10);//işlemin tamamlanabilmesi için gerekli bekleme süresi
}
