#pragma once
#include "System/System.h"
#include "HardwareProvidedNotRegistered.h"
#include "Cpu.h"
#include "SPI.h"

using namespace Microsoft::SPOT::Exceptions;
using namespace System;
namespace Microsoft {
	namespace SPOT {
		namespace Hardware {
			//Forward Declaration
			//class SPI;

			class HardwareProvider : public virtual Object{
				private:
				static HardwareProvider* s_hwProvider;
				public:
				static HardwareProvider* getHwProvider();
				//Ignored empty method declaration
				public:
				static void Register(HardwareProvider* provider);
				public:
				virtual void GetSerialPins(String* comPort, Cpu::Pin& rxPin, Cpu::Pin& txPin, Cpu::Pin& ctsPin, Cpu::Pin& rtsPin);
				public:
				virtual int GetSerialPortsCount();
				public:
				virtual bool SupportsNonStandardBaudRate(int com);
				public:
				virtual void GetBaudRateBoundary(int com, uint& MaxBaudRate, uint& MinBaudRate);
				public:
				virtual bool IsSupportedBaudRate(int com, uint& baudrateHz);
				public:
				virtual void GetSpiPins(SPI::SPI_module spi_mod, Cpu::Pin& msk, Cpu::Pin& miso, Cpu::Pin& mosi);
				public:
				virtual int GetSpiPortsCount();
				public:
				virtual void GetI2CPins(Cpu::Pin& scl, Cpu::Pin& sda);
				public:
				virtual int GetPWMChannelsCount();
				public:
				virtual Cpu::Pin GetPwmPinForChannel(Cpu::PWMChannel channel);
				public:
				virtual int GetAnalogChannelsCount();
				public:
				virtual Cpu::Pin GetAnalogPinForChannel(Cpu::AnalogChannel channel);
				public:
				virtual Array<int>* GetAvailablePrecisionInBitsForChannel(Cpu::AnalogChannel channel);
				public:
				virtual int GetAnalogOutputChannelsCount();
				public:
				virtual Cpu::Pin GetAnalogOutputPinForChannel(Cpu::AnalogOutputChannel channel);
				public:
				virtual Array<int>* GetAvailableAnalogOutputPrecisionInBitsForChannel(Cpu::AnalogOutputChannel channel);
				public:
				virtual int GetPinsCount();
				public:
				virtual void GetPinsMap(Array<Cpu::PinUsage>* pins, int& PinCount);
				public:
				virtual Cpu::PinUsage GetPinsUsage(Cpu::Pin pin);
				public:
				virtual Cpu::PinValidResistorMode GetSupportedResistorModes(Cpu::Pin pin);
				public:
				virtual Cpu::PinValidInterruptMode GetSupportedInterruptModes(Cpu::Pin pin);
				public:
				virtual void GetLCDMetrics(int& width, int& height, int& bitsPerPixel, int& orientationDeg);
			};
		}
	}
}
