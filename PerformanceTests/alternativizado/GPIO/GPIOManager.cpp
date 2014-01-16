#include "GPIOManager.h"

namespace Microsoft {
	namespace SPOT {
		namespace Manager {
			GPIOManager* GPIOManager::instance;
			Dictionary_T<Cpu::Pin, PortType>* GPIOManager::_activePins = new Dictionary_T<Cpu::Pin, PortType>();
		        //String* GPIOManager::GPIO_PATH = new String("/sys/class/gpio/");
			GPIOManager* GPIOManager::getInstance(){
                        //Console::WriteLine("getInstance GPIOMANAGER");
				if (GPIOManager::instance == null){
                                    //Console::WriteLine("creating instance");
					GPIOManager::instance = new GPIOManager();
                                        //Console::WriteLine("instance created");
				}
                                //Console::WriteLine("returning instance");
                                //Console::WriteLine(GPIOManager::instance->ToString());

				return GPIOManager::instance;
			}
			GPIOManager::GPIOManager()
			{				
				GPIO_PATH = new String("/sys/class/gpio/");
			}
			void GPIOManager::Export(Cpu::Pin pin)
			{
				if (!GPIOManager::_activePins->ContainsKey(pin)) {					

					Array<Object>* array = new Array<Object>(2);
					array->SetData(0, GPIO_PATH);
					array->SetData(1, new String("export"));
					String* arg_29_0 = String::Concat(array);


					int num = (int)(pin);
					File::WriteAllText(arg_29_0, new String(num));
					GPIOManager::_activePins->Add(pin, PortType::NONE);
				}
			}
			void GPIOManager::Unexport(Cpu::Pin pin)
			{
				if (GPIOManager::_activePins->ContainsKey(pin)) {
					Array<Object>* array = new Array<Object>(2);
					array->SetData(0, GPIO_PATH);
					array->SetData(1, new String("unexport"));


					String* arg_2C_0 = String::Concat(array);
					int num = (int)(pin);
					File::WriteAllText(arg_2C_0, new String(num));
					GPIOManager::_activePins->Remove(pin);
				}
			}
			bool GPIOManager::Read(Cpu::Pin pin)
			{
				if (GPIOManager::_activePins->ContainsKey(pin)) {
					Array<Object>* array = new Array<Object>(4);
					array->SetData(0, GPIO_PATH);
					array->SetData(1, new String("gpio"));
					array->SetData(2, BOX<int>((int)(pin)));
					array->SetData(3, new String("/value"));
					String* value = File::ReadAllText(String::Concat(array));
					return value == new String("1");
				}
				throw new Exception();
			}
			void GPIOManager::Write(Cpu::Pin pin, bool state)
			{	
//				Console::WriteLine("GPIOMANAGER::Write");

				if (!GPIOManager::_activePins->ContainsKey(pin)) {
					throw new Exception();
				}
				if ((*GPIOManager::_activePins)[pin] == PortType::OUTPUT) {
//					Console::WriteLine("GPIOMANAGER-> active pin output");

					int value = state ? 1 : 0;

					//Console::WriteLine("Creating array");

					Array<Object>* array = new Array<Object>(4);
					//Console::WriteLine("Array created");

					array->SetData(0, GPIO_PATH);
					//Console::WriteLine("set data 0");

					array->SetData(1, new String("gpio"));
					 //Console::WriteLine("set data 1");
					array->SetData(2, BOX<int>((int)(pin)));
					 //Console::WriteLine("set data 2");
					array->SetData(3, new String("/value"));
					 //Console::WriteLine("set data 3");
					String* tmp = new String(value);

					 //Console::WriteLine("concat");
					//String* concat__ = String::Concat(array);
					 //Console::WriteLine("concat ok");
					//Console::WriteLine(concat__);
					String* concatenated = String::Concat(array);
					File::WriteAllText(concatenated, tmp->ToLower());
					return;
				}
				if ((*GPIOManager::_activePins)[pin] == PortType::TRISTATE) {
					throw new NotImplementedException();
				}
				throw new Exception();
			}
			void GPIOManager::SetPortType(Cpu::Pin pin, PortType type)
			{
//				Console::WriteLine("GPIOMANAGER::SetPortType");
				//Console::WriteLine((int)pin);
				//Console::WriteLine((int)type);

				if (GPIOManager::_activePins->ContainsKey(pin)) {
					String* direction = new String("");
					type = PortType::OUTPUT;
					switch (type) {
					case PortType::NONE:
						GPIOManager::_activePins->SetData(pin, PortType::NONE);
						throw new NotImplementedException();

					case PortType::INPUT:
						direction = new String("in");
						GPIOManager::_activePins->SetData(pin, PortType::INPUT);
						break;

					case PortType::OUTPUT:
						direction = new String("out");
						GPIOManager::_activePins->SetData(pin, PortType::OUTPUT);
//						Console::WriteLine("GPIOMANAGER::SetPortType OUTPUT");

						break;

					case PortType::TRISTATE:
						GPIOManager::_activePins->SetData(pin, PortType::TRISTATE);
						throw new NotImplementedException();

					case PortType::INTERRUPT:
						direction = new String("in");
						GPIOManager::_activePins->SetData(pin, PortType::INTERRUPT);
						break;
					}
					//Console::WriteLine("changed direction");
					Array<Object>* array = new Array<Object>(4);
                                   //     array->SetData(3, new String("/direction"));
                                        //Console::WriteLine(GPIO_PATH);
					array->SetData(0, GPIO_PATH);
					array->SetData(1, new String("gpio"));
					array->SetData(2, BOX<int>((int)(pin)));
                                        //Console::WriteLine(GPIO_PATH);
					array->SetData(3, new String("/direction"));
					
				//	Array<Object>* array = new Array<Object>(4);
					/*array->SetData(0, GPIOManager::GPIO_PATH);
					array->SetData(1, new String("gpio"));
					array->SetData(2, BOX<int>((int)(pin)));
					array->SetData(3, new String("/direction"));*/
					//Console::WriteLine("SetPortType BEFORE concat");
					//String* tmp = String::Concat(array);
					//Console::WriteLine("SetPortType Concat");
					//Console::WriteLine(tmp);
					File::WriteAllText(String::Concat(array), direction->ToLower());
					
					//File::WriteAllText(new String("/sys/class/gpio/gpio17/direcion"), direction->ToLower());
					return;
				}
				throw new Exception();
			}
			void GPIOManager::SetEdge(Cpu::Pin pin, Port::InterruptMode interruptMode)
			{
				String* interrupt = new String("none");				
				Console::WriteLine(BOX<Port::InterruptMode>(interruptMode));
				switch (interruptMode) {
				case Port::InterruptMode::InterruptEdgeLow:
					interrupt = new String("falling");
					break;

				case Port::InterruptMode::InterruptEdgeHigh:
					interrupt = new String("rising");
					break;

				case Port::InterruptMode::InterruptEdgeBoth:
					interrupt = new String("both");
					break;

				case Port::InterruptMode::InterruptEdgeLevelHigh:
					throw new Exception();

				case Port::InterruptMode::InterruptEdgeLevelLow:
					throw new Exception();
				}
				Array<Object>* array = new Array<Object>(4);
				array->SetData(0, GPIO_PATH);
				array->SetData(1, new String("gpio"));
				array->SetData(2, BOX<int>((int)(pin)));
				array->SetData(3, new String("/edge"));
				File::WriteAllText(String::Concat(array), interrupt->ToLower());
			}
			bool GPIOManager::ReservePin(Cpu::Pin pin, bool fReserve)
			{
				bool result;
				if (GPIOManager::_activePins->ContainsKey(pin) && fReserve) {
					result = false;
				}
				else {
					if (GPIOManager::_activePins->ContainsKey(pin) && !fReserve) {
						GPIOManager::_activePins->Remove(pin);
						result = true;
					}
					else {
						if (!GPIOManager::_activePins->ContainsKey(pin) && fReserve) {
							GPIOManager::_activePins->Add(pin, PortType::RESERVED);
							result = true;
						}
						else {
							result = false;
						}
					}
				}
				return result;
			}
			void GPIOManager::Listen_events(Cpu::Pin pin, NativeEventHandler* callback)
			{
				Thread* t = new Thread(new ParameterizedThreadStart(DELEGATE_FUNC(GPIOManager::Listen, _1)));
				GPIOManager::ThreadHelper* th = new GPIOManager::ThreadHelper();
				th->setPin(pin);
				th->setCallback(callback);
				t->Start(th);
			}
			void GPIOManager::Listen(Object* obj)
			{
				GPIOManager::ThreadHelper* th = (GPIOManager::ThreadHelper*)(obj);
				while (true) {
					GPIOManager::callback_p* cback = GPIOManager::start_polling((int)(th->getPin()));
					DateTime* dt = DateTime::GetNow();
					DELEGATE_INVOKE(th->getCallback(), (uint)(cback->pin), (uint)0, dt);
				}
			}
			//Attribute: DllImport*(new String("libIOSharp-c.so"), CallingConvention = CallingConvention->StdCall)
			GPIOManager::callback_p* GPIOManager::start_polling(int gpio){
				return ::start_polling(gpio);
			}

		}
	}
}
