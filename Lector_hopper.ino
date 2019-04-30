/*
Projecto: Dosificador de agua 
Programador: Mario Peralta 
Placa: Arduino Uno
Modificación: 30 Abril 2019

*/

#define SENSOR  3
#define RELAY   7

int pulse=0;               
boolean sen;
int i=0;
unsigned long int timer;             

void setup()
{
  Serial.begin(9600);
  pinMode(SENSOR,INPUT_PULLUP);
  pinMode(19,INPUT_PULLUP);
  pinMode(RELAY,OUTPUT);
  digitalWrite(RELAY,HIGH);
  Serial.println("Coin Hopper ready");
  sen=digitalRead(SENSOR);
}
 
void loop()
{
  int estadoBoton = digitalRead(19);
  sen=digitalRead(SENSOR);
 
    

    if (estadoBoton == 1){
   
    timer=millis();
   i=1;
    }

    if(i==1){
      digitalWrite(RELAY,LOW);
      }
  
  if(sen==0)
  {
    timer=millis();
    pulse++;
    delay(100);
    Serial.println(pulse);
    if(pulse>=10)
    {
      digitalWrite(RELAY,HIGH);
      Serial.println("Monedas"+String(1.0*pulse,2));
      i=0;
        delay(500);
      pulse=0;
      
    }
  }

  if((digitalRead(RELAY)==LOW)&(millis()-timer>2000))
  {
    digitalWrite(RELAY,HIGH);
    Serial.println("No hay monedas"+String(1.0*pulse,2));
    i=0;
      delay(500);
    pulse=0;
   
  }
    
}
