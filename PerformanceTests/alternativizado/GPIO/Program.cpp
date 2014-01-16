#include "Program.h"
namespace raspberrypi {

	void Program::Main(){
		Program* p = new Program();
		p->Run();
	}

	void Program::Run(){
		/*InterruptPort* button = new InterruptPort(Cpu::Pin::GPIO_Pin2, false, Port::ResistorMode::Disabled, Port::InterruptMode::InterruptEdgeBoth);
		button->addOnInterrupt(new GPIOManager::NativeEventHandler(DELEGATE_FUNC(Program::button_OnInterrupt, _1, _2, _3)));
		//button->addOnInterrupt(new NativeEventHandler(boost::bind(&Program::button_OnInterrupt, Program,_1,_2,_3)));
		Debug::Print(new String("Started"));
		Thread::Sleep(-1);*/
		Debug::Print(new String("Interruption"));
		//Console::WriteLine(new String("ola k ase 1"));
		OutputPort* bar = new OutputPort(Cpu::Pin::GPIO_Pin17, false);
		//Console::WriteLine(new String("ola k ase 2"));
	
		bar->Write(false);
		//Console::WriteLine(new String("ola k ase 3"));
		bool foo = false;
		OutputPort* o = new OutputPort(Cpu::Pin::GPIO_Pin11, false);
		//Console::WriteLine(new String("ola k ase 4"));
		bar->Write(true);
		//Console::WriteLine(new String("ola k ase 5"));
		for (int i = 0; i < 10000; i += 1) {
			//Debug::Print(new String(i));
			foo = !foo;
			o->Write(foo);
		}
		bar->Write(false);
		Debug::Print(new String("END"));


	}

	void Program::button_OnInterrupt(uint port, uint state, DateTime* time)
	{
		Debug::Print(new String("Interruption"));
		OutputPort* bar = new OutputPort(Cpu::Pin::GPIO_Pin17, false);
		bar->Write(false);
		bool foo = false;
		OutputPort* o = new OutputPort(Cpu::Pin::GPIO_Pin11, false);
		bar->Write(true);
		for (int i = 0; i < 200; i += 1) {
			//Debug::Print(new String(i));
			foo = !foo;
			o->Write(foo);
		}
		bar->Write(false);
		Debug::Print(new String("END"));
	}

}
