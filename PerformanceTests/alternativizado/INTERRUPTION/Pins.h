#pragma once
#include "System/System.h"
#include "Cpu.h"

using namespace Microsoft::SPOT::Hardware;
using namespace System;
namespace IOSharp {
	namespace NETMF {
		namespace RaspberryPi {
			namespace Hardware {
				class Pins : public virtual Object
				{
					public:
						Cpu::Pin V1_GPIO0;
					public:
						Cpu::Pin V1_GPIO1;
					public:
						Cpu::Pin V1_GPIO4;
					public:
						Cpu::Pin V1_GPIO14;
					public:
						Cpu::Pin V1_GPIO15;
					public:
						Cpu::Pin V1_GPIO17;
					public:
						Cpu::Pin V1_GPIO18;
					public:
						Cpu::Pin V1_GPIO21;
					public:
						Cpu::Pin V1_GPIO22;
					public:
						Cpu::Pin V1_GPIO23;
					public:
						Cpu::Pin V1_GPIO24;
					public:
						Cpu::Pin V1_GPIO10;
					public:
						Cpu::Pin V1_GPIO9;
					public:
						Cpu::Pin V1_GPIO25;
					public:
						Cpu::Pin V1_GPIO11;
					public:
						Cpu::Pin V1_GPIO8;
					public:
						Cpu::Pin V1_GPIO7;
					public:
						Cpu::Pin V2_GPIO2;
					public:
						Cpu::Pin V2_GPIO3;
					public:
						Cpu::Pin V2_GPIO4;
					public:
						Cpu::Pin V2_GPIO14;
					public:
						Cpu::Pin V2_GPIO15;
					public:
						Cpu::Pin V2_GPIO17;
					public:
						Cpu::Pin V2_GPIO27;
					public:
						Cpu::Pin V2_GPIO18;
					public:
						Cpu::Pin V2_GPIO22;
					public:
						Cpu::Pin V2_GPIO23;
					public:
						Cpu::Pin V2_GPIO24;
					public:
						Cpu::Pin V2_GPIO10;
					public:
						Cpu::Pin V2_GPIO9;
					public:
						Cpu::Pin V2_GPIO25;
					public:
						Cpu::Pin V2_GPIO11;
					public:
						Cpu::Pin V2_GPIO8;
					public:
						Cpu::Pin V2_GPIO7;
					public:
						Cpu::Pin GPCLK0;
					public:
						Cpu::Pin UART0_TXD;
					public:
						Cpu::Pin UART0_RXD;
					public:
						Cpu::Pin PCM_CLK;
					public:
						Cpu::Pin SPI0_MOSI;
					public:
						Cpu::Pin SPI0_MISO;
					public:
						Cpu::Pin SPI0_SCLK;
					public:
						Cpu::Pin SPI0_CE0_N;
					public:
						Cpu::Pin SPI0_CE1_N;
					public:
						Pins();
				};
			}
		}
	}
}
