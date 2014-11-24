

#include <Wire.h>
#include <BMP085.h>

BMP085 dps = BMP085();
long Temperature = 0, Pressure = 0, Altitude = 0, Ambiant = 0;

void setup(void) {
  
  Serial.begin(9600);
  Wire.begin();
  delay(1000);
	
  dps.init();
  Serial.println("initialised");  
  delay(1000);
 
  dps.getPressure(&Ambiant);
   Serial.println("ambiant collected");
   for(int i=10;i>=0;i--){
     Serial.println(i);
     delay(1000);
   }
}
   
void loop(void) {
  
  dps.getTemperature(&Temperature); 
  dps.getPressure(&Pressure);
  
  Serial.print("Temp(C):");
  Serial.print(Temperature-273.14);
  Serial.print("   Depth(CmH20):");
  Serial.println((Pressure-Ambiant)*0.0101974428892);
  }
}
