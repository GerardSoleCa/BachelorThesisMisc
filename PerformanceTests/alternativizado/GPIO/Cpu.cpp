#include "Cpu.h"
namespace Microsoft {
	namespace SPOT {
		namespace Hardware {
			uint Cpu::getSystemClock(){
				return SystemClock_var;
			}
			void Cpu::setSystemClock(uint value)
			{
				SystemClock_var = value;
			}
			uint Cpu::getSlowClock()
			{
				return SlowClock_var;
			}
			void Cpu::setSlowClock(uint value)
			{
				SlowClock_var = value;
			}
			TimeSpan* Cpu::getGlitchFilterTime()
			{
				return GlitchFilterTime_var;
			}
			void Cpu::setGlitchFilterTime(TimeSpan* value)
			{
				GlitchFilterTime_var = value;
			}
			uint Cpu::SystemClock_var;
			uint Cpu::SlowClock_var;
			TimeSpan* Cpu::GlitchFilterTime_var;
			Cpu::Cpu()
			{
				SystemClock_var = (uint)(0);
				SlowClock_var = (uint)(0);
				GlitchFilterTime_var = (TimeSpan*)(0);
			}

		}
	}
}
