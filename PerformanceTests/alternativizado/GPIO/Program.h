#pragma once
#include "System/System.h"
#include "InterruptPort.h"
#include "Cpu.h"
#include "Port.h"
#include "NativeEventHandler.h"
#include "Debug.h"
#include "System/Threading/Thread.h"
#include "System/DateTime.h"
#include "OutputPort.h"

using namespace Microsoft::SPOT::Hardware;
using namespace System::Threading;
using namespace System;
namespace raspberrypi {
	class Program : public virtual Object
	{
		public:
			static void Main();
			void Run();
		private:
			void button_OnInterrupt(uint port, uint state, DateTime* time);
	};
}
