#include <Time.h>  


int valor=0;
int bandera=0;
int tiempo=0;
int temporal=0;
int c=0;
int frecuencia=0;
int comparador=70;
void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  pinMode(13, OUTPUT); 
 //cont=0; 
}

void loop() {
  // send the value of analog input 0:
  valor=analogRead(A0);
  //Serial.println(valor);
  if(valor>=270)
  {
    digitalWrite(13,HIGH);
    bandera=1;
  }
  else
  {
    digitalWrite(13,LOW);
    if(bandera==1)
    {
      if(c==0)
      {
        tiempo=millis();
      }
      else
      {}
        
      c=c+1;
      bandera=0;
    } 
   else
  {} 
   
  }
  
  if(c>=5)
  {
    temporal=millis()-tiempo;
    frecuencia=(((float)c/(float)temporal)*60000);
    if(comparador-frecuencia>=10||frecuencia-comparador>=10)
     {
       c=0;
     }
    comparador=frecuencia;  
  }
  
    if(c>=5)
    {
      Serial.print("Frecuencia es: ");
      if(frecuencia>220)
         Serial.print("0");
      else
         Serial.print(frecuencia);
      Serial.println("");
      c=0;
    }
    
  // wait a bit for the analog-to-digital converter 
  // to stabilize after the last reading:
  delay(2);
}

