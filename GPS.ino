#include <TinyGPS++.h>
TinyGPSPlus gps;
#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 2);
unsigned long start;
double lat_val, lng_val;
int val;
bool loc_valid;

void setup() {
  mySerial.begin(9600);
  Serial.begin(57600);
}

byte x;
void loop() {
  gpsget();
}
void gpsget()
{
  GPSDelay(1000);
  lat_val = gps.location.lat();
  loc_valid = gps.location.isValid();
  lng_val = gps.location.lng();
  val = gps.satellites.value();
  if (!loc_valid)
  {

  }
  else
  {
    Serial.print("<A0"); Serial.print(lat_val, 6); Serial.print("A0>");
    Serial.print("<A1"); Serial.print(lng_val, 6); Serial.print("A1>");
    delay(300);
  }
}
static void GPSDelay(unsigned long ms)
{
  unsigned long start = millis();
  do
  {
    while (mySerial.available())
      gps.encode(mySerial.read());
  } while (millis() - start < ms);
}
