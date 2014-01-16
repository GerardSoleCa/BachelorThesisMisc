#include "InterruptPort.h"
namespace Microsoft {
	namespace SPOT {
		namespace Hardware {
			void InterruptPort::addOnInterrupt(NativeEventHandler* value){
				GPIOManager::getInstance()->Listen_events(Port::getId(), value);
			}
			void InterruptPort::removeOnInterrupt(NativeEventHandler* value)
			{
				Console::WriteLine(new String("Adeu"));
			}

			Port::InterruptMode InterruptPort::getInterrupt()
			{
				return Interrupt_var;
			}
			void InterruptPort::setInterrupt(Port::InterruptMode value)
			{
				Interrupt_var = value;
			}
			InterruptPort::InterruptPort(Cpu::Pin portId, bool glitchFilter, Port::ResistorMode resistor, Port::InterruptMode interrupt) : InputPort(portId, glitchFilter, resistor, interrupt)
			{
//				Console::WriteLine("Interrupt port constructor");
				Interrupt_var = (Port::InterruptMode)(0);
				GPIOManager::getInstance()->SetPortType(portId, PortType::INTERRUPT);
				GPIOManager::getInstance()->SetEdge(portId, interrupt);
//				Console::WriteLine("Interrupt port constructor OK");
			}
			void InterruptPort::ClearInterrupt()
			{
			}
			void InterruptPort::EnableInterrupt()
			{
			}
			void InterruptPort::DisableInterrupt()
			{
			}

		}
	}
}
