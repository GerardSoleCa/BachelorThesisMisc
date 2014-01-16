#include "RaspberryPiHWProvider.h"
namespace IOSharp {
	namespace NETMF {
		namespace RaspberryPi {
			namespace Hardware {
				int RaspberryPiHWProvider::GetAnalogChannelsCount(){
					throw new NotImplementedException();
				}
				int RaspberryPiHWProvider::GetAnalogOutputChannelsCount()
				{
					throw new NotImplementedException();
				}
				Cpu::Pin RaspberryPiHWProvider::GetAnalogOutputPinForChannel(Cpu::AnalogOutputChannel channel)
				{
					throw new NotImplementedException();
				}
				Cpu::Pin RaspberryPiHWProvider::GetAnalogPinForChannel(Cpu::AnalogChannel channel)
				{
					throw new NotImplementedException();
				}
				Array<int>* RaspberryPiHWProvider::GetAvailableAnalogOutputPrecisionInBitsForChannel(Cpu::AnalogOutputChannel channel)
				{
					throw new NotImplementedException();
				}
				Array<int>* RaspberryPiHWProvider::GetAvailablePrecisionInBitsForChannel(Cpu::AnalogChannel channel)
				{
					throw new NotImplementedException();
				}
				void RaspberryPiHWProvider::GetBaudRateBoundary(int com, uint& MaxBaudRate, uint& MinBaudRate)
				{
					throw new NotImplementedException();
				}
				void RaspberryPiHWProvider::GetI2CPins(Cpu::Pin& scl, Cpu::Pin& sda)
				{
					throw new NotImplementedException();
				}
				void RaspberryPiHWProvider::GetLCDMetrics(int& width, int& height, int& bitsPerPixel, int& orientationDeg)
				{
					throw new NotImplementedException();
				}
				int RaspberryPiHWProvider::GetPinsCount()
				{
					throw new NotImplementedException();
				}
				void RaspberryPiHWProvider::GetPinsMap(Array<Cpu::PinUsage>* pins, int& PinCount)
				{
					throw new NotImplementedException();
				}
				Cpu::PinUsage RaspberryPiHWProvider::GetPinsUsage(Cpu::Pin pin)
				{
					throw new NotImplementedException();
				}
				int RaspberryPiHWProvider::GetPWMChannelsCount()
				{
					throw new NotImplementedException();
				}
				Cpu::Pin RaspberryPiHWProvider::GetPwmPinForChannel(Cpu::PWMChannel channel)
				{
					throw new NotImplementedException();
				}
				void RaspberryPiHWProvider::GetSerialPins(String* comPort, Cpu::Pin& rxPin, Cpu::Pin& txPin, Cpu::Pin& ctsPin, Cpu::Pin& rtsPin)
				{
					throw new NotImplementedException();
				}
				int RaspberryPiHWProvider::GetSerialPortsCount()
				{
					throw new NotImplementedException();
				}
				void RaspberryPiHWProvider::GetSpiPins(SPI::SPI_module spi_mod, Cpu::Pin& msk, Cpu::Pin& miso, Cpu::Pin& mosi)
				{
					if (spi_mod == SPI::SPI_module::SPI1) {
						msk = Cpu::Pin::GPIO_Pin11;
						miso = Cpu::Pin::GPIO_Pin9;
						mosi = Cpu::Pin::GPIO_Pin10;
						return;
					}
					throw new NotImplementedException();
				}
				int RaspberryPiHWProvider::GetSpiPortsCount()
				{
					throw new NotImplementedException();
				}
				Cpu::PinValidInterruptMode RaspberryPiHWProvider::GetSupportedInterruptModes(Cpu::Pin pin)
				{
					throw new NotImplementedException();
				}
				Cpu::PinValidResistorMode RaspberryPiHWProvider::GetSupportedResistorModes(Cpu::Pin pin)
				{
					throw new NotImplementedException();
				}
				bool RaspberryPiHWProvider::IsSupportedBaudRate(int com,  uint& baudrateHz)
				{
					throw new NotImplementedException();
				}
				bool RaspberryPiHWProvider::SupportsNonStandardBaudRate(int com)
				{
					throw new NotImplementedException();
				}

			}
		}
	}
}
