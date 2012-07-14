//============================================================================
// Name        : CalcTimeOffset.cpp
// Author      : Stefan Naewe
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include <boost/date_time/posix_time/posix_time.hpp>

using namespace boost::posix_time;

struct TimeOffset
{
  unsigned int hour, minute;
};

ptime get_local_time(ptime, unsigned int, unsigned int);
ptime get_utc_time(ptime, unsigned int, unsigned int);

int main()
{
  TimeOffset offset = { 0, 20 };

  ptime basetime = second_clock::local_time();

  ptime local_start_time = get_local_time(basetime, offset.hour, offset.minute);
  ptime utc_start_time = get_utc_time(basetime, offset.hour, offset.minute);

  return 0;
}
