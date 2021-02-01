
#define SAGGERI    2
#define SOLILERI   3
#define SAGILERI   4
#define SOLGERI    5

#include <VirtualWire.h> // Kütüphaneyi ekledik.
byte message[VW_MAX_MESSAGE_LEN]; // gelen mesajları tutmak için 
byte msgLength = VW_MAX_MESSAGE_LEN; // mesaj boyutu
void setup()
{
Serial.begin(9600);
 
vw_setup(2000); /*2sn’de bir çalıştırmak için (edit okoman: yaklaşık veri trahasfer hızıdır hatalı açıklama yapılmış)virtualwire’ı başlatır.*/ 
vw_rx_start(); // Alıcı başlat 
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
} 

void sagileri()
{
digitalWrite(SAGGERI,LOW);//SAĞ GERİ 
digitalWrite(SOLILERI,HIGH);//SOL  İLERİ
digitalWrite(SAGILERI,LOW);//SAĞ İLERİ
digitalWrite(SOLGERI,LOW);//SOL GERİ
}
void saggeri()
{
digitalWrite(SAGGERI,LOW);//SAĞ GERİ 
digitalWrite(SOLILERI,LOW);//SOL  İLERİ
digitalWrite(SAGILERI,LOW);//SAĞ İLERİ
digitalWrite(SOLGERI,HIGH);//SOL GERİ
}
void solileri()
{
digitalWrite(SAGGERI,LOW);//SAĞ GERİ 
digitalWrite(SOLILERI,LOW);//SOL  İLERİ
digitalWrite(SAGILERI,HIGH);//SAĞ İLERİ
digitalWrite(SOLGERI,LOW);//SOL GERİ
}
void solgeri()
{
digitalWrite(SAGGERI,HIGH);//SAĞ GERİ 
digitalWrite(SOLILERI,LOW);//SOL  İLERİ
digitalWrite(SAGILERI,LOW);//SAĞ İLERİ
digitalWrite(SOLGERI,LOW);//SOL GERİ
}
void dur()
{
digitalWrite(SAGGERI,LOW);//SAĞ GERİ 
digitalWrite(SOLILERI,LOW);//SOL  İLERİ
digitalWrite(SAGILERI,LOW);//SAĞ İLERİ
digitalWrite(SOLGERI,LOW);//SOL GERİ
}
void ileri()
{
digitalWrite(SAGGERI,LOW);//SAĞ GERİ 
digitalWrite(SOLILERI,HIGH);//SOL  İLERİ
digitalWrite(SAGILERI,HIGH);//SAĞ İLERİ
digitalWrite(SOLGERI,LOW);//SOL GERİ
}
void geri()
{
digitalWrite(SAGGERI,HIGH);//SAĞ GERİ 
digitalWrite(SOLILERI,LOW);//SOL  İLERİ
digitalWrite(SAGILERI,LOW);//SAĞ İLERİ
digitalWrite(SOLGERI,HIGH);//SOL GERİ
}


void loop()
{ 
if (vw_get_message(message, &msgLength)) /*mesaj hazır ise tamam ve mesaj serial monitorde gözükür*/ 

{
if(message[0] == 'A'){ileri();} 
if(message[0] == 'B'){geri();} 
if(message[0] == 'C'){solileri();} 
if(message[0] == 'D'){sagileri();} 
if(message[0] == 'E'){dur();} 
}
}

