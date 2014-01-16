#pragma once
#include "System/System.h"
#include "InputPort.h"
#include "NativeEventHandler.h"
#include "GPIOManager.h"
#include "System/Console.h"
#include "Port.h"
#include "Cpu.h"
#include "PortType.h"

using namespace Microsoft::SPOT::Manager;
using namespace System;
namespace Microsoft {
	namespace SPOT {
		namespace Hardware {
			class InterruptPort : public virtual InputPort, public virtual Object
			{
				public:
					void addOnInterrupt(NativeEventHandler* value);
				public:
					void removeOnInterrupt(NativeEventHandler* value);
				public:
					Port::InterruptMode getInterrupt();
				public:
					void setInterrupt(Port::InterruptMode value);
				public:
					InterruptPort(Cpu::Pin portId, bool glitchFilter, Port::ResistorMode resistor, Port::InterruptMode interrupt);
				public:
					void ClearInterrupt();
				public:
				virtual void EnableInterrupt();
				public:
				virtual void DisableInterrupt();
				public:
					Port::InterruptMode Interrupt_var;
			};
		}
	}
}
