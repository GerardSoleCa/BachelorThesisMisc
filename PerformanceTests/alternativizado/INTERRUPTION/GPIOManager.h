#pragma once
#include "System/System.h"
#include "Cpu.h"
//#include "NativeEventHandler.h"
#include "PortType.h"
#include "System/Collections/Generic/Dictionary.h"
#include "System/IO/File.h"
#include "System/Exception.h"
#include "System/Exception/SystemException/NotImplementedException.h"
#include "Port.h"
#include "System/Console.h"
#include "System/Threading/Thread.h"
#include "System/DateTime.h"
#include "System/DateTimeKind.h"



using namespace Microsoft::SPOT::Hardware;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Threading;
//using namespace System::Runtime::InteropServices;
namespace Microsoft {
	namespace SPOT {
		namespace Manager {
			//Forward Declaration
			//class Port;
			//DELEGATE(void, uint, uint, DateTime*) NativeEventHandler;


			class GPIOManager : public virtual Object{
				public:
				 DELEGATE(void, uint, uint, DateTime*) NativeEventHandler;

				public:
				class ThreadHelper : public Object{
					public:
					Cpu::Pin getPin(){
						return Pin_var;
					}
					void setPin(Cpu::Pin value)
					{
						Pin_var = value;
					}
					public:
					NativeEventHandler* getCallback()
					{
						return Callback_var;
					}
					void setCallback(NativeEventHandler* value)
					{
						Callback_var = value;
					}
					public:
					Cpu::Pin Pin_var;
					public:
					NativeEventHandler* Callback_var;
					public:
					ThreadHelper()
					{
						Pin_var = (Cpu::Pin)(0);
						Callback_var = (NativeEventHandler*)(0);
					}
				};
				public:
				struct callback_p : public Object
				{
					int pin;
					String* state;
					long poll_time;
				};
				private:
				static GPIOManager* instance;
				private:
				static Dictionary_T<Cpu::Pin, PortType>* _activePins;
				protected:
				//String* GPIO_PATH;
				public:
				static GPIOManager* getInstance();
					//Ignored empty method declaration
				private:
					GPIOManager();
				public:
					void Export(Cpu::Pin pin);
				public:
					void Unexport(Cpu::Pin pin);
				public:
					bool Read(Cpu::Pin pin);
				public:
					void Write(Cpu::Pin pin, bool state);
				public:
					void SetPortType(Cpu::Pin pin, PortType type);
				public:
					void SetEdge(Cpu::Pin pin, Port::InterruptMode interruptMode);
				public:
					bool ReservePin(Cpu::Pin pin, bool fReserve);
				public:
					void Listen_events(Cpu::Pin pin, NativeEventHandler* callback);
				private:
					void Listen(Object* obj);
				//Attribute: DllImport*(new String("libIOSharp-c.so"), CallingConvention = CallingConvention->StdCall)
				private:
				static GPIOManager::callback_p* start_polling(int gpio);
			};
		}
	}
}

//Extern method of: Library: libIOSharp-c.so | method: start_polling | alias: start_polling
extern "C" Microsoft::SPOT::Manager::GPIOManager::callback_p* start_polling(int gpio);
