#include "Pins.h"
namespace IOSharp {
	namespace NETMF {
		namespace RaspberryPi {
			namespace Hardware {
				Pins::Pins(){
					V1_GPIO0 = Cpu::Pin::GPIO_Pin0;
					V1_GPIO1 = Cpu::Pin::GPIO_Pin1;
					V1_GPIO4 = Cpu::Pin::GPIO_Pin4;
					V1_GPIO14 = Cpu::Pin::GPIO_Pin14;
					V1_GPIO15 = Cpu::Pin::GPIO_Pin15;
					V1_GPIO17 = Cpu::Pin::GPIO_Pin17;
					V1_GPIO18 = (Cpu::Pin)(18);
					V1_GPIO21 = (Cpu::Pin)(21);
					V1_GPIO22 = (Cpu::Pin)(22);
					V1_GPIO23 = (Cpu::Pin)(23);
					V1_GPIO24 = (Cpu::Pin)(24);
					V1_GPIO10 = Cpu::Pin::GPIO_Pin10;
					V1_GPIO9 = Cpu::Pin::GPIO_Pin9;
					V1_GPIO25 = (Cpu::Pin)(25);
					V1_GPIO11 = Cpu::Pin::GPIO_Pin11;
					V1_GPIO8 = Cpu::Pin::GPIO_Pin8;
					V1_GPIO7 = Cpu::Pin::GPIO_Pin7;
					V2_GPIO2 = Cpu::Pin::GPIO_Pin2;
					V2_GPIO3 = Cpu::Pin::GPIO_Pin3;
					V2_GPIO4 = Cpu::Pin::GPIO_Pin4;
					V2_GPIO14 = Cpu::Pin::GPIO_Pin14;
					V2_GPIO15 = Cpu::Pin::GPIO_Pin15;
					V2_GPIO17 = Cpu::Pin::GPIO_Pin17;
					V2_GPIO27 = (Cpu::Pin)(27);
					V2_GPIO18 = (Cpu::Pin)(18);
					V2_GPIO22 = (Cpu::Pin)(22);
					V2_GPIO23 = (Cpu::Pin)(23);
					V2_GPIO24 = (Cpu::Pin)(24);
					V2_GPIO10 = Cpu::Pin::GPIO_Pin10;
					V2_GPIO9 = Cpu::Pin::GPIO_Pin9;
					V2_GPIO25 = (Cpu::Pin)(25);
					V2_GPIO11 = Cpu::Pin::GPIO_Pin11;
					V2_GPIO8 = Cpu::Pin::GPIO_Pin8;
					V2_GPIO7 = Cpu::Pin::GPIO_Pin7;
					GPCLK0 = Cpu::Pin::GPIO_Pin4;
					UART0_TXD = Cpu::Pin::GPIO_Pin14;
					UART0_RXD = Cpu::Pin::GPIO_Pin15;
					PCM_CLK = (Cpu::Pin)(18);
					SPI0_MOSI = Cpu::Pin::GPIO_Pin10;
					SPI0_MISO = Cpu::Pin::GPIO_Pin9;
					SPI0_SCLK = Cpu::Pin::GPIO_Pin11;
					SPI0_CE0_N = Cpu::Pin::GPIO_Pin8;
					SPI0_CE1_N = Cpu::Pin::GPIO_Pin7;
				}

			}
		}
	}
}
