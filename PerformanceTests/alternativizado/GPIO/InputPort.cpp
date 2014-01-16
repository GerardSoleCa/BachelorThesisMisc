#include "InputPort.h"
namespace Microsoft {
	namespace SPOT {
		namespace Hardware {
			Port::ResistorMode InputPort::getResistor(){
				return Resistor_var;
			}
			void InputPort::setResistor(Port::ResistorMode value)
			{
				Resistor_var = value;
			}
			bool InputPort::getGlitchFilter()
			{
				return GlitchFilter_var;
			}
			void InputPort::setGlitchFilter(bool value)
			{
				GlitchFilter_var = value;
			}
			InputPort::InputPort(Cpu::Pin portId, bool glitchFilter, Port::ResistorMode resistor) : Port(portId, glitchFilter, resistor, Port::InterruptMode::InterruptNone)
			{
				GlitchFilter_var = (bool)(0);
				Resistor_var = (Port::ResistorMode)(0);
				GPIOManager::getInstance()->SetPortType(portId, PortType::INPUT);
			}
			InputPort::InputPort(Cpu::Pin portId, bool glitchFilter, Port::ResistorMode resistor, Port::InterruptMode interruptMode) : Port(portId, glitchFilter, resistor, interruptMode)
			{
				GPIOManager::getInstance()->SetPortType(portId, PortType::INPUT);
			}
			InputPort::InputPort(Cpu::Pin portId, bool initialState, bool glitchFilter, Port::ResistorMode resistor) : Port(portId, initialState, glitchFilter, resistor)
			{
				throw new NotImplementedException();
			}

		}
	}
}
