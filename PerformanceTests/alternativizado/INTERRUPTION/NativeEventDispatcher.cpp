#include "NativeEventDispatcher.h"
namespace Microsoft {
	namespace SPOT {
		namespace Hardware {
			void NativeEventDispatcher::addOnInterrupt(NativeEventHandler* value){
				if (this->m_disposed){
					throw new ObjectDisposedException(new String(""));
				}
				NativeEventHandler* callbacksOld = this->m_callbacks;
				NativeEventHandler* callbacksNew = (NativeEventHandler*)(Delegate::Combine(callbacksOld, value));
				try {
					this->m_callbacks = callbacksNew;
					if (callbacksNew != null) {
						if (callbacksOld == null) {
							this->EnableInterrupt();
						}
						if (!callbacksNew->Equals(value)) {
							callbacksNew = new NativeEventHandler(DELEGATE_FUNC(NativeEventDispatcher::MultiCastCase, _1, _2, _3));
						}
					}
					this->m_threadSpawn = callbacksNew;
				}
				catch (Object* ex_78) {
					this->m_callbacks = callbacksOld;
					if (callbacksOld == null) {
						this->DisableInterrupt();
					}
					throw;
				}
			}
			void NativeEventDispatcher::removeOnInterrupt(NativeEventHandler* value)
			{
				if (this->m_disposed) {
					throw new ObjectDisposedException(new String(""));
				}
				NativeEventHandler* callbacksOld = this->m_callbacks;
				NativeEventHandler* callbacksNew = (NativeEventHandler*)(Delegate::Remove(callbacksOld, value));
				try {
					this->m_callbacks = callbacksNew;
					if (callbacksNew == null && callbacksOld != null) {
						this->DisableInterrupt();
					}
				}
				catch (Object* ex_51) {
					this->m_callbacks = callbacksOld;
					throw;
				}
			}

			NativeEventDispatcher::NativeEventDispatcher()
			{
				m_disposed = false;
				m_callbacks = null;
				m_threadSpawn = null;
			}
			NativeEventDispatcher::NativeEventDispatcher(String* strDriverName, ulong drvData)
			{
			}
			void NativeEventDispatcher::EnableInterrupt()
			{
			}
			void NativeEventDispatcher::DisableInterrupt()
			{
			}
			void NativeEventDispatcher::Dispose(bool disposing)
			{
			}
			NativeEventDispatcher::~NativeEventDispatcher()
			{
				this->Dispose(false);
			}
			//Attribute: MethodImpl*(MethodImplOptions::Synchronized)
			void NativeEventDispatcher::Dispose(){
				an_sync();
				if (!this->m_disposed){
					this->Dispose(true);
					GC::SuppressFinalize(this);
					this->m_disposed = true;
				}
				an_end_sync();
			}
			void NativeEventDispatcher::MultiCastCase(uint port, uint state, DateTime* time)
			{
				NativeEventHandler* callbacks = this->m_callbacks;
				if (callbacks != null) {
					DELEGATE_INVOKE(callbacks, port, state, time);
				}
			}

		}
	}
}
