#pragma once
#include "System/System.h"
#include "System/System.h"
#include "System/IDisposable.h"
//#include "NativeEventHandler.h"
#include "System/Exception/SystemException/InvalidOperationException/ObjectDisposedException.h"
#include "System/Delegate.h"
#include "System/GC.h"
#include "System/DateTime.h"

using namespace System;
//using namespace System::Runtime::CompilerServices;
namespace Microsoft {
	namespace SPOT {
		namespace Hardware {
			DELEGATE(void, uint, uint, DateTime*) NativeEventHandler;

			class NativeEventDispatcher : public virtual IDisposable, public virtual Object
			{
				protected:
					NativeEventHandler* m_threadSpawn;
				protected:
					NativeEventHandler* m_callbacks;
				protected:
					bool m_disposed;
				private:
					Object* m_NativeEventDispatcher;
				public:
					void addOnInterrupt(NativeEventHandler* value);
				public:
					void removeOnInterrupt(NativeEventHandler* value);
				public:
					NativeEventDispatcher();
				public:
					NativeEventDispatcher(String* strDriverName, ulong drvData);
				public:
				virtual void EnableInterrupt();
				public:
				virtual void DisableInterrupt();
				public:
				virtual void Dispose(bool disposing);
				public:
					~NativeEventDispatcher();
				//Attribute: MethodImpl*(MethodImplOptions::Synchronized)
				public:
				virtual void Dispose();
				private:
					void MultiCastCase(uint port, uint state, DateTime* time);
				private:
					 an_init_sync();
			};
		}
	}
}
