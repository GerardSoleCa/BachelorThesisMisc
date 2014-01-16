#pragma once
#include "System/System.h"
#include "NativeEventDispatcher.h"
#include "Cpu.h"
#include "System/Exception/SystemException/NotImplementedException.h"
#include "System/Console.h"

using namespace System;
namespace Microsoft {
	namespace SPOT {
		namespace Hardware {
			//Forward Declaration
			//class GPIOManager;

			class Port : public virtual NativeEventDispatcher, public virtual Object{
				public:
				enum class ResistorMode{
					Disabled,
					PullDown,
					PullUp
				};
				public:
				enum class InterruptMode : int
				{
					InterruptNone,
					InterruptEdgeLow,
					InterruptEdgeHigh,
					InterruptEdgeBoth,
					InterruptEdgeLevelHigh,
					InterruptEdgeLevelLow
				};
				private:
					Port::InterruptMode m_interruptMode;
				private:
					Port::ResistorMode m_resistorMode;
				private:
					uint m_portId;
				private:
					uint m_flags;
				private:
					bool m_glitchFilterEnable;
				private:
					bool m_initialState;
				public:
					Cpu::Pin getId();
				public:
					void setId(Cpu::Pin value);
				protected:
					Port(){};
					Port(Cpu::Pin portId, bool glitchFilter, Port::ResistorMode resistor, Port::InterruptMode interruptMode);
				protected:
					Port(Cpu::Pin portId, bool initialState);
				protected:
					Port(Cpu::Pin portId, bool initialState, bool glitchFilter, Port::ResistorMode resistor);
				public:
				virtual void Dispose();
				virtual void Dispose(bool disposing);
				public:
					bool Read();
				public:
				static bool ReservePin(Cpu::Pin pin, bool fReserve);
				public:
					Cpu::Pin Id_var;
			};
		}
	}
}
