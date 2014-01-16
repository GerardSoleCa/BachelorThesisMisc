#pragma once
#include "System/System.h"
#include "Port.h"
#include "Cpu.h"
#include "GPIOManager.h"
#include "PortType.h"
#include "System/Exception/SystemException/NotImplementedException.h"

using namespace Microsoft::SPOT::Manager;
using namespace System;
namespace Microsoft {
	namespace SPOT {
		namespace Hardware {
			class InputPort : public virtual Port, public virtual Object
			{
				public:
					Port::ResistorMode getResistor();
				public:
					void setResistor(Port::ResistorMode value);
				public:
					bool getGlitchFilter();
				public:
					void setGlitchFilter(bool value);
				public:
					InputPort(Cpu::Pin portId, bool glitchFilter, Port::ResistorMode resistor);
				protected:
					InputPort(Cpu::Pin portId, bool glitchFilter, Port::ResistorMode resistor, Port::InterruptMode interruptMode);
				protected:
					InputPort(Cpu::Pin portId, bool initialState, bool glitchFilter, Port::ResistorMode resistor);
				public:
					Port::ResistorMode Resistor_var;
				public:
					bool GlitchFilter_var;
			};
		}
	}
}
