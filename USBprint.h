/*
 *	USBprint.h
 *	
 *	Author: Andrew D. Horchler, horchler @ gmail . com
 *	Created: 8-24-14, modified: 5-8-16
 */
 
#ifndef USBPRINT_H_
#define USBPRINT_H_

#include "HardwareSerial.h"
#include "Print.h"

#ifndef USBPRINT_BUFFER_SIZE
	#define USBPRINT_BUFFER_SIZE (8*80)
#endif

/*
 *  Return 1 if USB serial is connected and configured, 0 otherwise.
 *	TODO: Check that Serial.begin() has been called and USB serial connection is active.
 */
inline int USBprintReady() __attribute__((always_inline));
inline int USBprintReady()
{
	return 1;
}

/*
 *	Fast general print functions without floating-point support using vsniprintf to
 *	replace Serial.print(). These functions require about 6,320 additional bytes compared
 *	to Serial.print(). The number of bytes written is returned.
 */
int USBprint(const char *fmt, ...);
int USBprintln(const char *fmt, ...);
int USBsprint(char *str, size_t n, const char *fmt, ...);

/*
 *	Fast general print functions using vsnprintf to replace Serial.print(). These
 *	functions require a considerable amount of memory to support floating-point: about 
 *	14,684 additional bytes compared to Serial.printf(). The number of bytes written is
 *	returned.
 */
int USBprintf(const char *fmt, ...);
int USBprintfln(const char *fmt, ...);
int USBsprintf(char *str, size_t n, const char *fmt, ...);

/*
 *	Fast print functions using ee_vsprint() to replace Serial.print(). These functions
 *  use much less memory than USBprint() and only about 1,280 bytes more than
 *	Serial.print(). However, not all format specifications are supported. The number of
 *	bytes written is returned.
 */
int USBprintLite(const char *fmt, ...);
int USBsprintLite(char *str, const char *fmt, ...);

/*
 *	Fast print functions using ee_vsprintf() to replace Serial.print(). These functions
 *  use less memory than USBprintf() and about 9,840 bytes more than Serial.print().
 *	However, not all format specifications are supported. The number of bytes written is
 *	returned.
 */
int USBprintfLite(const char *fmt, ...);
int USBsprintfLite(char *str, const char *fmt, ...);

/*
 *	Fast string-only print function to replace Serial.print(). This very lightweight
 *  function only supports character string inputs. The number of bytes written is
 *	returned.
 */
inline int USBprintStr(const char *str)
{
	int len;
	
	len = strlen(str);
	if (USBprintReady() && len > 0) {
		Serial.write((const uint8_t*)str, len);
		return len;
	} else {
		return 0;
	}
}

/*
 *	Print single raw uint8_t byte. This low-level function only supports character input
 *	that has already been converted to raw unsigned 8-bit data. The number of bytes
 *	successfully written is returned (0 or 1).
 */
inline int USBprintRaw(const uint8_t dat)
{
	if (USBprintReady()) {
		Serial.write(&dat, 1);
		return 1;
	} else {
		return 0;
	}
}

/*
 *	Print array of raw uint8_t bytes of given length. This low-level function only
 *	supports character string inputs that have already been converted to raw unsigned 
 *	8-bit data. The number of bytes successfully written is returned.
 */
inline int USBprintRaw(const uint8_t *dat, const int datlen)
{
	if (USBprintReady() && datlen > 0) {
		Serial.write(dat, datlen);
		return datlen;
	} else {
		return 0;
	}
}

#endif /* USBPRINT_H_ */