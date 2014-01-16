#include "Debug.h"
namespace Microsoft {
	namespace SPOT {
		namespace Hardware {
			void Debug::Print(String* s){
				Console::WriteLine(s);
			}

		}
	}
}
