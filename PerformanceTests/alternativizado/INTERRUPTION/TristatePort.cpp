#include "TristatePort.h"
namespace Microsoft {
	namespace SPOT {
		namespace Hardware {
			bool TristatePort::getActive(){
				return this->active;
			}
			void TristatePort::setActive(bool value)
			{
				if (this->getActive()) {
					GPIOManager::getInstance()->SetPortType(OutputPort::getId(), PortType::OUTPUT);
					if (this->firstTimeOutput) {
						OutputPort::Write(OutputPort::getInitialState());
						this->firstTimeOutput = false;
					}
				}
				else {
					GPIOManager::getInstance()->SetPortType(OutputPort::getId(), PortType::INPUT);
				}
				this->getActive();
			}
			Port::ResistorMode TristatePort::getResistor()
			{
				return Resistor_var;
			}
			void TristatePort::setResistor(Port::ResistorMode value)
			{
				Resistor_var = value;
			}
			bool TristatePort::getGlitchFilter()
			{
				return GlitchFilter_var;
			}
			void TristatePort::setGlitchFilter(bool value)
			{
				GlitchFilter_var = value;
			}
			TristatePort::TristatePort(Cpu::Pin portId, bool initialState, bool glitchFilter, Port::ResistorMode resistor) : OutputPort(portId, initialState, glitchFilter, resistor)
			{
				GlitchFilter_var = (bool)(0);
				Resistor_var = (Port::ResistorMode)(0);
				firstTimeOutput = false;
				active = false;
				GPIOManager::getInstance()->SetPortType(portId, PortType::INPUT);
				this->active = false;
				OutputPort::setInitialState(initialState);
				this->firstTimeOutput = true;
			}

		}
	}
}
