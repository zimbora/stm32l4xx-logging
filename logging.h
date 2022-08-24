/*
 * eeprom.h
 *
 *  Created on: May 20, 2018
 *      Author: jsilva
 */

#ifndef __LOGGING_H
#define __LOGGING_H

//#include <user.hpp>
#include "stm32l4xx_hal.h"
#include "string.h"
//#include "queue"
#include "strstream" // to use string import this
#include "package.h"
using namespace std;

#define VERBOSE_DEBUG_LEVEL	    1
#define INFO_DEBUG_LEVEL 				2
#define IMPORTANT_DEBUG_LEVEL 	3
#define WARNING_DEBUG_LEVEL 		4
#define ERROR_DEBUG_LEVEL 			5

#ifdef DEVELOPING
  #define DEBUG_MODEM 									VERBOSE_DEBUG_LEVEL
  #define DEBUG_NETWORK                 INFO_DEBUG_LEVEL
  #define DEBUG_MQTT                    INFO_DEBUG_LEVEL
#else
  #define DEBUG_MODEM 									IMPORTANT_DEBUG_LEVEL
  #define DEBUG_NETWORK                 IMPORTANT_DEBUG_LEVEL
  #define DEBUG_MQTT                    IMPORTANT_DEBUG_LEVEL
#endif


#ifdef DEVELOPING
  #define   DEBUG_SETTINGS
  #define   DEBUG_ALARMS
  #define   DEBUG_SENSORS
  #define   DEBUG_SENSORS_HIGH
  //#define   DEBUG_I2C
  //#define   DEBUG_RS485
  #define   DEBUG_MAIN
  //#define   DEBUG_MESSAGE
  //#define   DEBUG_MODBUS
  #define   DEBUG_AUTOREQUEST
  #define   DEBUG_TASKS
  //#define   DEBUG_MODEM_MESSAGE
  #define   DEBUG_MODEM_INFO
  //#define   DEBUG_MEMORY
  //#define   DEBUG_FLASH
  #define   DEBUG_HARDWARE
#endif

//#define logging_MEMORY_READ
//#define logging_MEMORY_WRITE
//#define logging_MEMORY_CONTEXT


#define logging_HARDWARE          0x04

#ifdef __cplusplus
 extern "C" {
#endif


//#define LOG_MEMORY  // comment to hide log memory

class LOGGING {

public:
  LOGGING();
	char log_msg[256];
	void init(uint8_t uart, uint32_t baudrate) ;
  void end(uint8_t uart);
  void log_arr( uint8_t* data, uint16_t size);
	void log( const char* data, const char* dev);
	void log_nnl( const char* data, const char* dev);  // no new line
	void log_nnl( const char* data);  // no new line
	void log( char* data, const char* dev, const char* flow);
	void log_hex( char* data, const char* dev, const char* flow);
  void log_hex( const char* dev, uint8_t* hex, uint16_t len);
	//void log( string data, const char* dev);
	bool print(char* data,int value);
	bool print(char* data,double value);
	bool print(char* data,long value);
	bool print(char* data,float value);
	bool println(const char *log,const char* data,int value);
	bool println(const char *log,const char* data,uint16_t value);
	bool println(const char *log,const char* data,double value);
  bool println(const char *log,const char* data,uint32_t value);
	bool println(const char *log,const char* data,long value);
	bool println(const char *log,const char* data,float value);
  bool println(const char *log,const char* data,string value);
private:
};

extern LOGGING logging;

#ifdef __cplusplus
}
#endif

#endif /* __LOG_H */
