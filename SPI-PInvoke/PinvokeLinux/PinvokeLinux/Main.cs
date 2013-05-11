using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace PinvokeLinux
{
	class MainClass
	{

		private static byte HIGH = 1;
		private static byte LOW = 0;

		private enum Bcm2835FunctionSelect :byte {
			BCM2835_GPIO_FSEL_INPT  = 0,   ///< Input
		    BCM2835_GPIO_FSEL_OUTP  = 1,   ///< Output
		    BCM2835_GPIO_FSEL_ALT0  = 100,   ///< Alternate function 0
		    BCM2835_GPIO_FSEL_ALT1  = 101,   ///< Alternate function 1
		    BCM2835_GPIO_FSEL_ALT2  = 110,   ///< Alternate function 2
		    BCM2835_GPIO_FSEL_ALT3  = 111,   ///< Alternate function 3
		    BCM2835_GPIO_FSEL_ALT4  = 011,   ///< Alternate function 4
		    BCM2835_GPIO_FSEL_ALT5  = 010,   ///< Alternate function 5
		    BCM2835_GPIO_FSEL_MASK  = 111    ///< Function select bits mask
			};

        private enum Bcm2835SPIBitOrder : byte
        {
            BCM2835_SPI_BIT_ORDER_LSBFIRST = 0,  ///< LSB First
            BCM2835_SPI_BIT_ORDER_MSBFIRST = 1   ///< MSB First
        };

        private enum Bcm2835SPIMode : byte
        {
            BCM2835_SPI_MODE0 = 0,  ///< CPOL = 0, CPHA = 0
            BCM2835_SPI_MODE1 = 1,  ///< CPOL = 0, CPHA = 1
            BCM2835_SPI_MODE2 = 2,  ///< CPOL = 1, CPHA = 0
            BCM2835_SPI_MODE3 = 3,  ///< CPOL = 1, CPHA = 1
        };

        private enum Bcm2835SPIClockDivider : ushort
        {
            BCM2835_SPI_CLOCK_DIVIDER_65536 = 0,       ///< 65536 = 262.144us = 3.814697260kHz
            BCM2835_SPI_CLOCK_DIVIDER_32768 = 32768,   ///< 32768 = 131.072us = 7.629394531kHz
            BCM2835_SPI_CLOCK_DIVIDER_16384 = 16384,   ///< 16384 = 65.536us = 15.25878906kHz
            BCM2835_SPI_CLOCK_DIVIDER_8192 = 8192,    ///< 8192 = 32.768us = 30/51757813kHz
            BCM2835_SPI_CLOCK_DIVIDER_4096 = 4096,    ///< 4096 = 16.384us = 61.03515625kHz
            BCM2835_SPI_CLOCK_DIVIDER_2048 = 2048,    ///< 2048 = 8.192us = 122.0703125kHz
            BCM2835_SPI_CLOCK_DIVIDER_1024 = 1024,    ///< 1024 = 4.096us = 244.140625kHz
            BCM2835_SPI_CLOCK_DIVIDER_512 = 512,     ///< 512 = 2.048us = 488.28125kHz
            BCM2835_SPI_CLOCK_DIVIDER_256 = 256,     ///< 256 = 1.024us = 976.5625MHz
            BCM2835_SPI_CLOCK_DIVIDER_128 = 128,     ///< 128 = 512ns = = 1.953125MHz
            BCM2835_SPI_CLOCK_DIVIDER_64 = 64,      ///< 64 = 256ns = 3.90625MHz
            BCM2835_SPI_CLOCK_DIVIDER_32 = 32,      ///< 32 = 128ns = 7.8125MHz
            BCM2835_SPI_CLOCK_DIVIDER_16 = 16,      ///< 16 = 64ns = 15.625MHz
            BCM2835_SPI_CLOCK_DIVIDER_8 = 8,       ///< 8 = 32ns = 31.25MHz
            BCM2835_SPI_CLOCK_DIVIDER_4 = 4,       ///< 4 = 16ns = 62.5MHz
            BCM2835_SPI_CLOCK_DIVIDER_2 = 2,       ///< 2 = 8ns = 125MHz, fastest you can get
            BCM2835_SPI_CLOCK_DIVIDER_1 = 1,       ///< 0 = 262.144us = 3.814697260kHz, same as 0/65536
        };

        private enum Bcm2835SPIChipSelect : byte
        {
            BCM2835_SPI_CS0 = 0,     ///< Chip Select 0
            BCM2835_SPI_CS1 = 1,     ///< Chip Select 1
            BCM2835_SPI_CS2 = 2,     ///< Chip Select 2 (ie pins CS1 and CS2 are asserted)
            BCM2835_SPI_CS_NONE = 3, ///< No CS, control it yourself
        };

		public static void Main (string[] args)
		{
            Console.WriteLine("bcm2835_init()");
        	if(bcm2835_init()){ 
            	 bcm2835_gpio_fsel(17, (byte) Bcm2835FunctionSelect.BCM2835_GPIO_FSEL_OUTP);

				int i = 0;
				while(i!=3){
                    Console.WriteLine("Flash Led: "+ i);
					bcm2835_gpio_write(17, HIGH);
					bcm2835_delay(500);
					bcm2835_gpio_write(17, LOW);
					bcm2835_delay(500);
					i++;
				}
				//bcm2835_close();
           	}
            else {
            	Console.WriteLine ("Not working!");
           	}

            Console.WriteLine("Starting SPI");
          
            /* SPI */
            bcm2835_spi_begin();
            bcm2835_spi_setBitOrder((byte) Bcm2835SPIBitOrder.BCM2835_SPI_BIT_ORDER_MSBFIRST);      // The default
            bcm2835_spi_setDataMode((byte) Bcm2835SPIMode.BCM2835_SPI_MODE0);                   // The default
            bcm2835_spi_setClockDivider((ushort)Bcm2835SPIClockDivider.BCM2835_SPI_CLOCK_DIVIDER_65536); // The default
            bcm2835_spi_chipSelect((byte)Bcm2835SPIChipSelect.BCM2835_SPI_CS0);                      // The default
            bcm2835_spi_setChipSelectPolarity((byte)Bcm2835SPIChipSelect.BCM2835_SPI_CS0, LOW);

            // Send a byte to the slave and simultaneously read a byte back from the slave
            // If you tie MISO to MOSI, you should read back what was sent
            byte data = bcm2835_spi_transfer(0x58);
            Console.WriteLine("Read from SPI: "+ data);

            bcm2835_spi_end();
            bcm2835_close();
			Console.WriteLine("Exit!");
        }

        [DllImport("bcm2835.so")]
        private static extern bool bcm2835_init();

        [DllImport("bcm2835.so")]
        private static extern bool bcm2835_close();

		[DllImport("bcm2835.so")]
		private static extern void bcm2835_gpio_fsel(byte pin, byte mode);

		[DllImport("bcm2835.so")]
		private static extern void bcm2835_gpio_write(byte pin, byte on);

		[DllImport("bcm2835.so")]
		private static extern void bcm2835_delay(int millis);

        /* SPI */
        [DllImport("bcm2835.so")]
        private static extern void bcm2835_spi_begin();

        [DllImport("bcm2835.so")]
        private static extern void bcm2835_spi_setBitOrder(byte order);

        [DllImport("bcm2835.so")]
        private static extern void bcm2835_spi_setDataMode(byte mode);

        [DllImport("bcm2835.so")]
        private static extern void bcm2835_spi_setClockDivider(ushort divider);

        [DllImport("bcm2835.so")]
        private static extern void bcm2835_spi_chipSelect(byte cs);

        [DllImport("bcm2835.so")]
        private static extern void bcm2835_spi_setChipSelectPolarity(byte cs, byte active);

        [DllImport("bcm2835.so")]
        private static extern byte bcm2835_spi_transfer(byte value);

        [DllImport("bcm2835.so")]
        private static extern void bcm2835_spi_end();
	}
}
