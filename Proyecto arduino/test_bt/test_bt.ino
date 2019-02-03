#include <SoftwareSerial.h>   // Incluimos la librerÃ­a  SoftwareSerial  
SoftwareSerial BT(11,10);    // Definimos los pines RX y TX del Arduino conectados al Bluetooth
 
void setup()
{
  BT.begin(9600);       // Inicializamos el puerto serie BT que hemos creado
  Serial.begin(9600);   // Inicializamos  el puerto serie  
}
 
void loop()
{
  if(BT.available())    // Si llega un dato por el puerto BT se envÃ­a al monitor serial
  {
    Serial.write(BT.read());
  }
 
  if(Serial.available())  // Si llega un dato por el monitor serial se envÃ­a al puerto BT
  {
     BT.write(Serial.read());
  }
}
