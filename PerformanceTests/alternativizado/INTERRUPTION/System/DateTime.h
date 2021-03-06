#pragma once
#include "System.h"
#include <boost/date_time.hpp>
#include "Exception/SystemException/ArgumentException/ArgumentOutOfRangeException.h"
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/posix_time/posix_time_io.hpp>
#include "DateTimeKind.h"

using namespace boost::gregorian;
using namespace boost::posix_time;
namespace System{


	class DateTime : public virtual Object
	{
//		private:
//		static ptime DateTime::time_t_epoch;
	public:	
		DateTime();
		DateTime(long long ticks);
		DateTime(int year, int month, int day);
		DateTime* AddMilliseconds(int milliseconds);
		static DateTime* GetNow();
		static DateTime* GetUtcNow();
		void _init();
		String* ToString();

	private:		
		long long DateData;//Ticks
		long long TicksPerMillisecond;
		time_duration time_duration_from_ticks(time_duration::tick_type ticks);
		//static ptime time_t_epoch;
	};
}
