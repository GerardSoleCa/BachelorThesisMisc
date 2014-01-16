#include "HardwareProvider.h"
namespace Microsoft {
	namespace SPOT {
		namespace Hardware {
			HardwareProvider* HardwareProvider::s_hwProvider = null;
			HardwareProvider* HardwareProvider::getHwProvider(){
				if (HardwareProvider::s_hwProvider == null){
					throw new HardwareProvidedNotRegistered();
				}
				return HardwareProvider::s_hwProvider;
			}
			void HardwareProvider::Register(HardwareProvider* provider)
			{
				HardwareProvider::s_hwProvider = provider;
			}
			void HardwareProvider::GetSerialPins(String* comPort,Cpu::Pin& rxPin, Cpu::Pin& txPin, Cpu::Pin& ctsPin, Cpu::Pin& rtsPin)
			{
				throw new HardwareProvidedNotRegistered();
			}
			int HardwareProvider::GetSerialPortsCount()
			{
				throw new HardwareProvidedNotRegistered();
			}
			bool HardwareProvider::SupportsNonStandardBaudRate(int com)
			{
				throw new HardwareProvidedNotRegistered();
			}
			void HardwareProvider::GetBaudRateBoundary(int com, uint& MaxBaudRate, uint& MinBaudRate)
			{
				throw new HardwareProvidedNotRegistered();
			}
			bool HardwareProvider::IsSupportedBaudRate(int com, uint& baudrateHz)
			{
				throw new HardwareProvidedNotRegistered();
			}
			void HardwareProvider::GetSpiPins(SPI::SPI_module spi_mod, Cpu::Pin& msk, Cpu::Pin& miso, Cpu::Pin& mosi)
			{
				throw new HardwareProvidedNotRegistered();
			}
			int HardwareProvider::GetSpiPortsCount()
			{
				throw new HardwareProvidedNotRegistered();
			}
			void HardwareProvider::GetI2CPins(Cpu::Pin& scl, Cpu::Pin& sda)
			{
				throw new HardwareProvidedNotRegistered();
			}
			int HardwareProvider::GetPWMChannelsCount()
			{
				throw new HardwareProvidedNotRegistered();
			}
			Cpu::Pin HardwareProvider::GetPwmPinForChannel(Cpu::PWMChannel channel)
			{
				throw new HardwareProvidedNotRegistered();
			}
			int HardwareProvider::GetAnalogChannelsCount()
			{
				throw new HardwareProvidedNotRegistered();
			}
			Cpu::Pin HardwareProvider::GetAnalogPinForChannel(Cpu::AnalogChannel channel)
			{
				throw new HardwareProvidedNotRegistered();
			}
			Array<int>* HardwareProvider::GetAvailablePrecisionInBitsForChannel(Cpu::AnalogChannel channel)
			{
				throw new HardwareProvidedNotRegistered();
			}
			int HardwareProvider::GetAnalogOutputChannelsCount()
			{
				throw new HardwareProvidedNotRegistered();
			}
			Cpu::Pin HardwareProvider::GetAnalogOutputPinForChannel(Cpu::AnalogOutputChannel channel)
			{
				throw new HardwareProvidedNotRegistered();
			}
			Array<int>* HardwareProvider::GetAvailableAnalogOutputPrecisionInBitsForChannel(Cpu::AnalogOutputChannel channel)
			{
				throw new HardwareProvidedNotRegistered();
			}
			int HardwareProvider::GetPinsCount()
			{
				throw new HardwareProvidedNotRegistered();
			}
			void HardwareProvider::GetPinsMap(Array<Cpu::PinUsage>* pins, int& PinCount)
			{
				throw new HardwareProvidedNotRegistered();
			}
			Cpu::PinUsage HardwareProvider::GetPinsUsage(Cpu::Pin pin)
			{
				throw new HardwareProvidedNotRegistered();
			}
			Cpu::PinValidResistorMode HardwareProvider::GetSupportedResistorModes(Cpu::Pin pin)
			{
				throw new HardwareProvidedNotRegistered();
			}
			Cpu::PinValidInterruptMode HardwareProvider::GetSupportedInterruptModes(Cpu::Pin pin)
			{
				throw new HardwareProvidedNotRegistered();
			}
			void HardwareProvider::GetLCDMetrics(int& width, int& height, int& bitsPerPixel, int& orientationDeg)
			{
				throw new HardwareProvidedNotRegistered();
			}

		}
	}
}
