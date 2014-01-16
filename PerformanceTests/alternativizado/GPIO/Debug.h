#pragma once
#include "System/System.h"
#include "System/Console.h"

using namespace System;
namespace Microsoft {
	namespace SPOT {
		namespace Hardware {
			class Debug : public virtual Object
			{
				public:
				static void Print(String* s);
			};
		}
	}
}
