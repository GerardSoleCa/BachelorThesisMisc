#pragma once
#include "System/System.h"
#include "Port.h"
#include "Cpu.h"
#include "GPIOManager.h"
#include "PortType.h"
#include "System/Exception/SystemException/NotImplementedException.h"
#include "System/Console.h"

using namespace Microsoft::SPOT::Manager;
using namespace System;
namespace Microsoft {
	namespace SPOT {
		namespace Hardware {
			class OutputPort : public virtual Port, public virtual Object
			{
				public:
					bool getInitialState();
				public:
					void setInitialState(bool value);
				public:
					OutputPort(Cpu::Pin portId, bool initialState);
				protected:
					OutputPort(Cpu::Pin portId, bool initialState, bool glitchFilter, Port::ResistorMode resistor);
				public:
					void Write(bool state);
				public:
					bool InitialState_var;
			};
		}
	}
}
