/*
 *	USBprint_Timing.ino
 *	
 *      Compare speed and ease of use of USBprintf() to Serial.print().
 *      
 *	Change Serial Monitor baud rate to 115200 or adjust Serial.begin() baud rate below.
 *	
 *	Author: Andrew D. Horchler, horchler @ gmail .com
 *	Created: 4-29-16, modified: 5-8-16
 */


#include "USBprint.h"
#include "Timing.h"

void setup()
{
  Serial.begin(115200);
  
  delay(3000);
  USBprintf("Hello World!\n\n");
}

void loop()
{
  static unsigned long t_us1 = 0, t_us2 = 0;
  double t_sec1, t_ms1, t_sec2, t_ms2;
  
  t_sec1 = (double)t_us1/1000000.0;
  t_ms1 = (double)t_us1/1000.0;
  t_sec2 = (double)t_us2/1000000.0;
  t_ms2 = (double)t_us2/1000.0;
  
  // Time how long it takes to print previous times in sec and ms as doubles twice
  usElapsed();
  
  USBprintf("USBprintf: %.17f sec, %.17f ms, %.17f sec, %.17f ms\n", t_sec1, t_ms1, t_sec2, t_ms2);
  t_us1 = usElapsed();
  
  Serial.print("Serial.print: ");
  Serial.print(t_sec1, 17);
  Serial.print(" sec, ");
  Serial.print(t_ms1, 17);
  Serial.print(" ms, ");
  Serial.print(t_sec2, 17);
  Serial.print(" sec, ");
  Serial.print(t_ms2, 17);
  Serial.println(" ms");
  t_us2 = usElapsed();
  
  // Print how many microseconds previous print operations took
  USBprintf(" - Elapsed - USBprintf: %u us, Serial.print: %u us\n\n", t_us1, t_us2);
  
  delay(1000);
}