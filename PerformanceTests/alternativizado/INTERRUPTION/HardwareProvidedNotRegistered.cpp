#include "HardwareProvidedNotRegistered.h"
namespace Microsoft {
	namespace SPOT {
		namespace Exceptions {
			HardwareProvidedNotRegistered::HardwareProvidedNotRegistered(){
			}

			HardwareProvidedNotRegistered::~HardwareProvidedNotRegistered() throw()
			{
			}
			HardwareProvidedNotRegistered::HardwareProvidedNotRegistered(String* message) : Exception(message)
			{
			}
			HardwareProvidedNotRegistered::HardwareProvidedNotRegistered(String* message, Exception* inner) : Exception(message, inner)
			{
			}
			HardwareProvidedNotRegistered::HardwareProvidedNotRegistered(SerializationInfo* info, StreamingContext* context)
			{
			}

		}
	}
}
