#include "GPIOManager.h"
#include "Port.h"

using namespace Microsoft::SPOT::Manager;

namespace Microsoft {
	namespace SPOT {
		namespace Hardware {
			Cpu::Pin Port::getId(){
				return Id_var;
			}
			void Port::setId(Cpu::Pin value)
			{
				Id_var = value;
			}
			Port::Port(Cpu::Pin portId, bool glitchFilter, Port::ResistorMode resistor, Port::InterruptMode interruptMode)
			{
//                                Console::WriteLine("moc port 1");
				Id_var = (Cpu::Pin)(0);
				this->setId(portId);
				GPIOManager::getInstance()->Export(portId);
//                                Console::WriteLine("moc port 2");
			}
			Port::Port(Cpu::Pin portId, bool initialState)
			{
  //                              Console::WriteLine("moc port 3");
				this->setId(portId);
				GPIOManager::getInstance()->Export(portId);
    //                            Console::WriteLine("moc port 4");
			}
			Port::Port(Cpu::Pin portId, bool initialState, bool glitchFilter, Port::ResistorMode resistor)
			{
      //                          Console::WriteLine("moc port 5");
				this->setId(portId);
				throw new NotImplementedException();
        //                        Console::WriteLine("moc port 6");
			}

			void Port::Dispose()
			{
				Dispose(true);
			}

			void Port::Dispose(bool disposing)
			{
				if (disposing) {
					Console::Write(new String("Disposing "));
					Console::WriteLine((int)this->getId());
					GPIOManager::getInstance()->Unexport(this->getId());
				}
			}
			bool Port::Read()
			{
				Console::Write(new String("Reading "));
				Console::WriteLine((int)this->getId());
				return GPIOManager::getInstance()->Read(this->getId());
			}
			bool Port::ReservePin(Cpu::Pin pin, bool fReserve)
			{
				return GPIOManager::getInstance()->ReservePin(pin, fReserve);
			}

		}
	}
}
