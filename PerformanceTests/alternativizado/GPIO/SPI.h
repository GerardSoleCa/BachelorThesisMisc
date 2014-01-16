#pragma once
#include "System/System.h"
#include "System/IDisposable.h"
#include "Cpu.h"
//#include "SPI.h"
#include "OutputPort.h"
//#include "HardwareProvider.h"
#include "Port.h"
#include "System/GC.h"
#include "System/Exception/SystemException/InvalidOperationException/ObjectDisposedException.h"
#include "System/Exception/SystemException/ArgumentException.h"

using namespace System;
//using namespace System::Runtime::InteropServices;
//using namespace System::Runtime::CompilerServices;
namespace Microsoft {
	namespace SPOT {
		namespace Hardware {
			//Forward Declaration
			//class HardwareProvider;

			class SPI : public virtual IDisposable, public virtual Object{
				public:
				enum class SPI_module{
					SPI1,
					SPI2,
					SPI3,
					SPI4
				};
				public:
				class Configuration : public virtual Object
				{
					public:
					Cpu::Pin ChipSelect_Port;
					public:
					bool ChipSelect_ActiveState;
					public:
					uint ChipSelect_SetupTime;
					public:
					uint ChipSelect_HoldTime;
					public:
					bool Clock_IdleState;
					public:
					bool Clock_Edge;
					public:
					uint Clock_RateKHz;
					public:
					SPI::SPI_module SPI_mod;
					public:
					Cpu::Pin BusyPin;
					public:
					bool BusyPin_ActiveState;
					public:
					//ADDED EXTRA CONSTRUCTOR: INITIALIZER WITH THE SAME CLASS DOES NOT WORK IN C++
					Configuration(Cpu::Pin ChipSelect_Port, bool ChipSelect_ActiveState, uint ChipSelect_SetupTime, uint ChipSelect_HoldTime, bool Clock_IdleState, bool Clock_Edge, uint Clock_RateKHz, SPI::SPI_module SPI_mod)
					{
						this->ChipSelect_Port = ChipSelect_Port;
						this->ChipSelect_ActiveState = ChipSelect_ActiveState;
						this->ChipSelect_SetupTime = ChipSelect_SetupTime;
						this->ChipSelect_HoldTime = ChipSelect_HoldTime;
						this->Clock_IdleState = Clock_IdleState;
						this->Clock_Edge = Clock_Edge;
						this->Clock_RateKHz = Clock_RateKHz;
						this->SPI_mod = SPI_mod;
						this->BusyPin = BusyPin;
						this->BusyPin_ActiveState = false;
					}
					public:
					Configuration(Cpu::Pin ChipSelect_Port, bool ChipSelect_ActiveState, uint ChipSelect_SetupTime, uint ChipSelect_HoldTime, bool Clock_IdleState, bool Clock_Edge, uint Clock_RateKHz, SPI::SPI_module SPI_mod, Cpu::Pin BusyPin, bool BusyPin_ActiveState)
					{
						this->ChipSelect_Port = ChipSelect_Port;
						this->ChipSelect_ActiveState = ChipSelect_ActiveState;
						this->ChipSelect_SetupTime = ChipSelect_SetupTime;
						this->ChipSelect_HoldTime = ChipSelect_HoldTime;
						this->Clock_IdleState = Clock_IdleState;
						this->Clock_Edge = Clock_Edge;
						this->Clock_RateKHz = Clock_RateKHz;
						this->SPI_mod = SPI_mod;
						this->BusyPin = BusyPin;
						this->BusyPin_ActiveState = BusyPin_ActiveState;
					}
				};
				public:
				struct spi_config : public virtual Object
				{
					int mode;
					uint speed;
					int cs_change;
					ushort delay;
					spi_config(SPI::Configuration* config)
					{
						this->cs_change = config->ChipSelect_ActiveState ? 1 : 0;
						this->delay = (ushort)(config->ChipSelect_HoldTime);
						if (config->Clock_Edge && !config->Clock_IdleState) {
							this->mode = 0;
						}
						else {
							if (!config->Clock_Edge && !config->Clock_IdleState) {
								this->mode = 1;
							}
							else {
								if (config->Clock_Edge && config->Clock_IdleState) {
									this->mode = 2;
								}
								else {
									this->mode = 3;
								}
							}
						}
						this->speed = config->Clock_RateKHz * 1000u;
					}
				};
				private:
					SPI::Configuration* m_config;
				private:
					OutputPort* m_cs;
				public:
					bool m_disposed;
				public:
					SPI::Configuration* getConfig();
				public:
					void setConfig(SPI::Configuration* value);
				public:
					SPI(SPI::Configuration* config);
				public:
					~SPI();
				//Attribute: MethodImpl*(MethodImplOptions::Synchronized)
				private:
					void Dispose(bool fDisposing);
				public:
					void Dispose();
				public:
					void WriteRead(Array<ushort>* writeBuffer, int writeOffset, int writeCount, Array<ushort>* readBuffer, int readOffset, int readCount, int startReadOffset);
				public:
					void WriteRead(Array<ushort>* writeBuffer, Array<ushort>* readBuffer, int startReadOffset);
				public:
					void WriteRead(Array<ushort>* writeBuffer, Array<ushort>* readBuffer);
				public:
					void Write(Array<ushort>* writeBuffer);
				public:
					void WriteRead(Array<char>* writeBuffer, int writeOffset, int writeCount, Array<char>* readBuffer, int readOffset, int readCount, int startReadOffset);
				public:
					void WriteRead(Array<char>* writeBuffer, Array<char>* readBuffer, int startReadOffset);
				public:
					void WriteRead(Array<char>* writeBuffer, Array<char>* readBuffer);
				public:
					void Write(Array<char>* writeBuffer);
				//Attribute: DllImport*(new String("libIOSharp-c.so"), CallingConvention = CallingConvention->StdCall, CharSet = CharSet->Ansi)
				private:
				static void InternalWriteReadShort(Array<ushort>* writeBuffer, int writeOffset, int writeCount, Array<ushort>* readBuffer, int readOffset, int readCount, int startReadOffset, SPI::spi_config* spi);
				//Attribute: DllImport*(new String("libIOSharp-c.so"), CallingConvention = CallingConvention->StdCall, CharSet = CharSet->Ansi)
				private:
				static void InternalWriteReadByte(Array<char>* writeBuffer, int writeOffset, int writeCount, Array<char>* readBuffer, int readOffset, int readCount, int startReadOffset, SPI::spi_config* spi);
				private:
					 an_init_sync();
			};
		}
	}
}

//Extern method of: Library: libIOSharp-c.so | method: InternalWriteReadShort | alias: InternalWriteReadShort
extern "C" void InternalWriteReadShort(ushort* writeBuffer, int writeOffset, int writeCount, ushort* readBuffer, int readOffset, int readCount, int startReadOffset, SPI::spi_config* spi);

//Extern method of: Library: libIOSharp-c.so | method: InternalWriteReadByte | alias: InternalWriteReadByte
extern "C" void InternalWriteReadByte(char* writeBuffer, int writeOffset, int writeCount, char* readBuffer, int readOffset, int readCount, int startReadOffset, SPI::spi_config* spi);

