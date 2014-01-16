#include "OutputPort.h"
namespace Microsoft {
	namespace SPOT {
		namespace Hardware {
			bool OutputPort::getInitialState(){
				return InitialState_var;
			}
			void OutputPort::setInitialState(bool value)
			{
				InitialState_var = value;
			}
			OutputPort::OutputPort(Cpu::Pin portId, bool initialState) : Port(portId, initialState)
			{
                                //Console::WriteLine("moc moc 1");
				InitialState_var = false;
				GPIOManager::getInstance()->SetPortType(portId, PortType::OUTPUT);
                                //Console::WriteLine("moc moc 2");
			}
			OutputPort::OutputPort(Cpu::Pin portId, bool initialState, bool glitchFilter, Port::ResistorMode resistor) : Port(portId, initialState, glitchFilter, resistor)
			{
				throw new NotImplementedException();
			}
			void OutputPort::Write(bool state)
			{
				//Console::Write(new String("Write ID: "));
				//Console::WriteLine((int)Port::getId());
				GPIOManager::getInstance()->Write(Port::getId(), state);

				//Console::WriteLine("OutputPort -> Write -> OK");
			}

		}
	}
}
