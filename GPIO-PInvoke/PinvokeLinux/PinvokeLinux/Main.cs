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

		public static void Main (string[] args)
		{

        	if(bcm2835_init()){ 
            	 bcm2835_gpio_fsel(17, (byte) Bcm2835FunctionSelect.BCM2835_GPIO_FSEL_OUTP);

				int i = 0;
				while(i!=10){
					bcm2835_gpio_write(17, HIGH);
					bcm2835_delay(500);
					bcm2835_gpio_write(17, LOW);
					bcm2835_delay(500);
					i++;
				}
				bcm2835_close();
           	}
            else {
            	Console.WriteLine ("Not working!");
           	}
			Console.WriteLine("Exit!");
        }

        [DllImport("bcm2835.so")]
        private static extern bool bcm2835_init();

		[DllImport("bcm2835.so")]
		private static extern void bcm2835_gpio_fsel(byte pin, byte mode);

		[DllImport("bcm2835.so")]
		private static extern void bcm2835_gpio_write(byte pin, byte on);

		[DllImport("bcm2835.so")]
		private static extern void bcm2835_delay(int millis);

		[DllImport("bcm2835.so")]
		private static extern void bcm2835_close();

	}
}
