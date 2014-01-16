#pragma once
#include "System/System.h"
#include "System/TimeSpan.h"

using namespace System;
namespace Microsoft {
	namespace SPOT {
		namespace Hardware {
			class Cpu : public virtual Object
			{
				public:
				enum class PinUsage : char
				{
					NONE = 0,
					INPUT = 1,
					OUTPUT = 2,
					ALTERNATE_A = 4,
					ALTERNATE_B = 8
				};
				public:
				enum class PinValidResistorMode : char
				{
					NONE = 0,
					Disabled = 1,
					PullUp = 2,
					PullDown = 4
				};
				public:
				enum class PinValidInterruptMode : char
				{
					NONE = 0,
					InterruptEdgeLow = 2,
					InterruptEdgeHigh = 4,
					InterruptEdgeBoth = 8,
					InterruptEdgeLevelHigh = 16,
					InterruptEdgeLevelLow = 32
				};
				public:
				enum class Pin
				{
					GPIO_NONE = -1,
					GPIO_Pin0,
					GPIO_Pin1,
					GPIO_Pin2,
					GPIO_Pin3,
					GPIO_Pin4,
					GPIO_Pin5,
					GPIO_Pin6,
					GPIO_Pin7,
					GPIO_Pin8,
					GPIO_Pin9,
					GPIO_Pin10,
					GPIO_Pin11,
					GPIO_Pin12,
					GPIO_Pin13,
					GPIO_Pin14,
					GPIO_Pin15,
					GPIO_Pin17 = 17
				};
				public:
				enum class PWMChannel
				{
					PWM_NONE = -1,
					PWM_0,
					PWM_1,
					PWM_2,
					PWM_3,
					PWM_4,
					PWM_5,
					PWM_6,
					PWM_7
				};
				public:
				enum class AnalogChannel
				{
					ANALOG_NONE = -1,
					ANALOG_0,
					ANALOG_1,
					ANALOG_2,
					ANALOG_3,
					ANALOG_4,
					ANALOG_5,
					ANALOG_6,
					ANALOG_7
				};
				public:
				enum class AnalogOutputChannel
				{
					ANALOG_OUTPUT_NONE = -1,
					ANALOG_OUTPUT_0,
					ANALOG_OUTPUT_1,
					ANALOG_OUTPUT_2,
					ANALOG_OUTPUT_3,
					ANALOG_OUTPUT_4,
					ANALOG_OUTPUT_5,
					ANALOG_OUTPUT_6,
					ANALOG_OUTPUT_7
				};
				public:
				static uint getSystemClock();
				public:
				static void setSystemClock(uint value);
				public:
				static uint getSlowClock();
				public:
				static void setSlowClock(uint value);
				public:
				static TimeSpan* getGlitchFilterTime();
				public:
				static void setGlitchFilterTime(TimeSpan* value);
				public:
				static uint SystemClock_var;
				public:
				static uint SlowClock_var;
				public:
				static TimeSpan* GlitchFilterTime_var;
				public:
					Cpu();
			};
		}
	}
}
