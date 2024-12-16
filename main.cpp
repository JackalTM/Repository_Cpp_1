#include "main.h"

#define TIMEFORMAT_HOURS_MAX	6
#define TIMEFORMAT_MINUTES_MAX	6
#define TIMEFORMAT_SECONDS_MAX	6
#define TIMEFORMAT_MS_MAX 10
struct timeformat_t
{
	uint8_t hour;
	uint8_t minute;
	uint8_t second;
	uint16_t msec;
};

static struct timeformat_t _timeformat = {0,0,0,0};
struct timeformat_t* _p_timeformat = NULL;

void DateAndTime_IRQ_1ms_external(void)
{
	//if(_p_timeformat == NULL) return;
	//else{;}

	if( ++(_p_timeformat->msec) < TIMEFORMAT_MS_MAX) return;
	else{	_p_timeformat->msec = 0;	}

	if( ++(_p_timeformat->second) < TIMEFORMAT_SECONDS_MAX) return;
	else{	_p_timeformat->second = 0;	}

	if( ++(_p_timeformat->minute) < TIMEFORMAT_MINUTES_MAX) return;
	else{	_p_timeformat->minute = 0;	}

	if( ++(_p_timeformat->hour) < TIMEFORMAT_HOURS_MAX) return;
	else{	_p_timeformat->hour = 0;	}
}

int main()
{
  _p_timeformat = &_timeformat;
  for(int i=0; i<2159; i++)
  {
    DateAndTime_IRQ_1ms_external();
  }
  printf("-- H= %d \n", _p_timeformat->hour);
  printf("-- m= %d \n", _p_timeformat->minute);
  printf("-- s= %d \n", _p_timeformat->second);

  return 0;
}
