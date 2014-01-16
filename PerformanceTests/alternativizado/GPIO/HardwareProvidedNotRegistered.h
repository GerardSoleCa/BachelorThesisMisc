#pragma once
#include "System/System.h"
#include "System/Exception.h"
//#include "SerializationInfo.h"
//#include "StreamingContext.h"

using namespace System;

namespace System{
	namespace Runtime{
		namespace Serialization{
			class SerializationInfo;
			class StreamingContext;
		}
	}
}

using namespace System::Runtime::Serialization;
namespace Microsoft {
	namespace SPOT {
		namespace Exceptions {
			//Attribute: Serializable*
			class HardwareProvidedNotRegistered : public virtual Exception, public virtual Object{
				public:
					HardwareProvidedNotRegistered();
				public:
					~HardwareProvidedNotRegistered() throw();
				public:
					HardwareProvidedNotRegistered(String* message);
				public:
					HardwareProvidedNotRegistered(String* message, Exception* inner);
				protected:
					HardwareProvidedNotRegistered(SerializationInfo* info, StreamingContext* context);
			};
		}
	}
}
