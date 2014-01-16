#include "SPI.h"
#include "HardwareProvider.h"
namespace Microsoft {
	namespace SPOT {
		namespace Hardware {
			SPI::Configuration* SPI::getConfig(){
				return this->m_config;
			}
			void SPI::setConfig(SPI::Configuration* value)
			{
				this->m_config = value;
			}
			SPI::SPI(SPI::Configuration* config)
			{
				HardwareProvider* hwProvider = HardwareProvider::getHwProvider();
				if (hwProvider != null) {
					Cpu::Pin msk;
					Cpu::Pin miso;
					Cpu::Pin mosi;
					hwProvider->GetSpiPins(config->SPI_mod, msk, miso, mosi);
					if (msk != Cpu::Pin::GPIO_NONE) {
						Port::ReservePin(msk, true);
					}
					if (miso != Cpu::Pin::GPIO_NONE) {
						Port::ReservePin(miso, true);
					}
					if (mosi != Cpu::Pin::GPIO_NONE) {
						Port::ReservePin(mosi, true);
					}
				}
				if (config->ChipSelect_Port != Cpu::Pin::GPIO_NONE) {
					Port::ReservePin(config->ChipSelect_Port, true);
				}
				this->m_config = config;
				this->m_disposed = false;
			}
			SPI::~SPI()
			{
				this->Dispose(false);				
			}
			//Attribute: MethodImpl*(MethodImplOptions::Synchronized)
			void SPI::Dispose(bool fDisposing){
				an_sync();
				if (!this->m_disposed){

					//NEW SCOPE CREATED FOR FINALLY BLOCK!
					{						
						//Change finally block for BOOST_SCOPE_EXIT
						//finally(void){
						//	m_disposed = true;							
						//}
						//finally_end
						try {
							HardwareProvider* hwProvider = HardwareProvider::getHwProvider();
							if (hwProvider != null) {
								Cpu::Pin msk;
								Cpu::Pin miso;
								Cpu::Pin mosi;
								hwProvider->GetSpiPins(this->m_config->SPI_mod, msk, miso, mosi);
								if (msk != Cpu::Pin::GPIO_NONE) {
									Port::ReservePin(msk, false);
								}
								if (miso != Cpu::Pin::GPIO_NONE) {
									Port::ReservePin(miso, false);
								}
								if (mosi != Cpu::Pin::GPIO_NONE) {
									Port::ReservePin(mosi, false);
								}
							}
							if (this->m_config->ChipSelect_Port != Cpu::Pin::GPIO_NONE) {
								this->m_cs->Dispose();
							}
							this->m_disposed=true;
						}
						catch(...)
						{
							this->m_disposed=true;
						}
						//END OF TRY/CATCH/FINALLY SCOPE
					}
				}
				an_end_sync();
			}
			void SPI::Dispose()
			{
				this->Dispose(true);
				GC::SuppressFinalize(this);
			}
			void SPI::WriteRead(Array<ushort>* writeBuffer, int writeOffset, int writeCount, Array<ushort>* readBuffer, int readOffset, int readCount, int startReadOffset)
			{
				if (this->m_disposed) {
					throw new ObjectDisposedException(new String(""));
				}
				if (writeBuffer == null || writeOffset + writeCount > writeBuffer->Length || readBuffer != null && readOffset + readCount > readBuffer->Length) {
					throw new ArgumentException();
				}
				SPI::InternalWriteReadShort(writeBuffer, writeOffset, writeCount, readBuffer, readOffset, readCount, startReadOffset, new SPI::spi_config(this->m_config));
			}
			void SPI::WriteRead(Array<ushort>* writeBuffer, Array<ushort>* readBuffer, int startReadOffset)
			{
				if (this->m_disposed) {
					throw new ObjectDisposedException(new String(""));
				}
				if (writeBuffer == null) {
					throw new ArgumentException();
				}
				int readBufLen = 0;
				if (readBuffer != null) {
					readBufLen = readBuffer->Length;
				}
				SPI::InternalWriteReadShort(writeBuffer, 0, writeBuffer->Length, readBuffer, 0, readBufLen, startReadOffset, new SPI::spi_config(this->m_config));
			}
			void SPI::WriteRead(Array<ushort>* writeBuffer, Array<ushort>* readBuffer)
			{
				if (readBuffer == null) {
					throw new ArgumentException();
				}
				this->WriteRead(writeBuffer, readBuffer, 0);
			}
			void SPI::Write(Array<ushort>* writeBuffer)
			{
				this->WriteRead(writeBuffer, null, 0);
			}
			void SPI::WriteRead(Array<char>* writeBuffer, int writeOffset, int writeCount, Array<char>* readBuffer, int readOffset, int readCount, int startReadOffset)
			{
				if (this->m_disposed) {
					throw new ObjectDisposedException(new String(""));
				}
				if (writeBuffer == null || writeOffset + writeCount > writeBuffer->Length || readBuffer != null && readOffset + readCount > readBuffer->Length) {
					throw new ArgumentException();
				}
				SPI::InternalWriteReadByte(writeBuffer, writeOffset, writeCount, readBuffer, readOffset, readCount, startReadOffset, new SPI::spi_config(this->m_config));
			}
			void SPI::WriteRead(Array<char>* writeBuffer, Array<char>* readBuffer, int startReadOffset)
			{
				if (this->m_disposed) {
					throw new ObjectDisposedException(new String(""));
				}
				if (writeBuffer == null) {
					throw new ArgumentException();
				}
				if (readBuffer == null) {
					readBuffer = new Array<char>(writeBuffer->Length);
				}
				int readBufLen = readBuffer->Length;
				SPI::InternalWriteReadByte(writeBuffer, 0, writeBuffer->Length, readBuffer, 0, readBufLen, startReadOffset, new SPI::spi_config(this->m_config));
			}
			void SPI::WriteRead(Array<char>* writeBuffer, Array<char>* readBuffer)
			{
				if (readBuffer == null) {
					throw new ArgumentException();
				}
				this->WriteRead(writeBuffer, readBuffer, 0);
			}
			void SPI::Write(Array<char>* writeBuffer)
			{
				this->WriteRead(writeBuffer, null, 0);
			}
			//Attribute: DllImport*(new String("libIOSharp-c.so"), CallingConvention = CallingConvention->StdCall, CharSet = CharSet->Ansi)
			void SPI::InternalWriteReadShort(Array<ushort>* writeBuffer, int writeOffset, int writeCount, Array<ushort>* readBuffer, int readOffset, int readCount, int startReadOffset, SPI::spi_config* spi){
				return ::InternalWriteReadShort(*writeBuffer, writeOffset, writeCount, *readBuffer, readOffset, readCount, startReadOffset, spi);
			}
			//Attribute: DllImport*(new String("libIOSharp-c.so"), CallingConvention = CallingConvention->StdCall, CharSet = CharSet->Ansi)
			void SPI::InternalWriteReadByte(Array<char>* writeBuffer, int writeOffset, int writeCount, Array<char>* readBuffer, int readOffset, int readCount, int startReadOffset, SPI::spi_config* spi){
				return ::InternalWriteReadByte(*writeBuffer, writeOffset, writeCount, *readBuffer, readOffset, readCount, startReadOffset, spi);
			}

		}
	}
}
