#include "Program.h"
//#include "System/GC.h"
namespace raspberrypi {

	void Program::Main(){
		Program* p = new Program();
		p->Run();
	}

	void Program::Run(){
		InterruptPort* button = new InterruptPort(Cpu::Pin::GPIO_Pin3, false, Port::ResistorMode::Disabled, Port::InterruptMode::InterruptEdgeLow);
		button->addOnInterrupt(new GPIOManager::NativeEventHandler(DELEGATE_FUNC(Program::button_OnInterrupt, _1, _2, _3)));

		foo = new OutputPort(Cpu::Pin::GPIO_Pin11, false);

		Debug::Print(new String("Started"));
		Thread::Sleep(-1);

	}

	void Program::button_OnInterrupt(uint port, uint state, DateTime* time)
	{
//		Debug::Print(new String("START"));
		foo->Write(true);
		foo->Write(false);
		Debug::Print(new String("END"));
	}

}
