#pragma once
#include "System/System.h"

using namespace System;
namespace Microsoft {
	namespace SPOT {
		namespace Manager {
			enum class PortType{
				NONE,
				INPUT,
				OUTPUT,
				TRISTATE,
				INTERRUPT,
				RESERVED
			};
		}
	}
}
