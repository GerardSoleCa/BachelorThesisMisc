#pragma once
#include "System/System.h"
#include "OutputPort.h"
#include "GPIOManager.h"
#include "PortType.h"
#include "Port.h"
#include "Cpu.h"

using namespace Microsoft::SPOT::Manager;
using namespace System;
namespace Microsoft {
	namespace SPOT {
		namespace Hardware {
			class TristatePort : public virtual OutputPort, public virtual Object
			{
				private:
					bool active;
				private:
					bool firstTimeOutput;
				public:
					bool getActive();
				public:
					void setActive(bool value);
				public:
					Port::ResistorMode getResistor();
				public:
					void setResistor(Port::ResistorMode value);
				public:
					bool getGlitchFilter();
				public:
					void setGlitchFilter(bool value);
				public:
					TristatePort(Cpu::Pin portId, bool initialState, bool glitchFilter, Port::ResistorMode resistor);
				public:
					Port::ResistorMode Resistor_var;
				public:
					bool GlitchFilter_var;
			};
		}
	}
}
