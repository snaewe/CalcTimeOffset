//============================================================================
// Name        : CalcTimeOffset.cpp
// Author      : Stefan Naewe
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <sstream>

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/c_local_time_adjustor.hpp>

using namespace boost::posix_time;

struct TimeOffset
{
  TimeOffset(int theHour, int theMinute)
    :hour(theHour)
    ,minute(theMinute)
  {}

  int hour, minute;
};

ptime get_local_time(ptime utcTime)
{
  typedef boost::date_time::c_local_adjustor<ptime> local_adj;
  return local_adj::utc_to_local(utcTime);
}

ptime offset_time(ptime theTime, TimeOffset const& offs)
{
  return theTime + hours(offs.hour) + minutes(offs.minute);
}

TimeOffset get_offset(ptime timeOne, ptime timeTwo)
{
  time_duration d = timeTwo - timeOne;
  return TimeOffset(d.hours(), d.minutes());
}

std::ostream&
operator<<(std::ostream& ostr, TimeOffset const& offs)
{
  std::ostringstream sstr;
  sstr << offs.hour << ":" << std::setw(2) << std::setfill('0') << offs.minute << 'h';
  ostr << sstr.str();
  return ostr;
}

int main()
{
  TimeOffset offset(0, 20);

  ptime basetime = second_clock::universal_time();

  ptime local_start_time = get_local_time(basetime);

  ptime in_two_hours = offset_time(basetime, TimeOffset(2, 0));

  std::cout
    << to_simple_string(basetime) << " + 2:00h = " << to_simple_string(in_two_hours) << " (UTC) == "
    << to_simple_string(get_local_time(in_two_hours)) << " (LOCAL)"
    << std::endl;

  std::cout
    << to_simple_string(in_two_hours) << " - "
    << to_simple_string(basetime) << " = "
    << get_offset(basetime, in_two_hours)
    << std::endl;
  return 0;
}
