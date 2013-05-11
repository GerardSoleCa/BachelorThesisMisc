using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            FileGPIO gpio = new FileGPIO();

            int flashes = 5;
            for (int i = 0; i < flashes; i++) //flash pin 17, 5 times on & off (1 second each)
            {
                //NO NEED TO SETUP OR INITIALIZE THE PINS, THATS ALL DONE FOR YOU, JUST USE OUTPUTPIN or INPUTPIN, AND USE CLEANUPALLPINS AT THE END!
                gpio.OutputPin(FileGPIO.enumPIN.gpio17, true);
                Thread.Sleep(1000);
                gpio.OutputPin(FileGPIO.enumPIN.gpio17, false);
                Thread.Sleep(1000);
            }
            gpio.OutputPin(FileGPIO.enumPIN.gpio17, true);
            Thread.Sleep(100000);
            //Console.WriteLine( "Value of pin 18 is " + gpio.InputPin(FileGPIO.enumPIN.gpio18) ); //UNTESTED!
            gpio.CleanUpAllPins();
        }
    }
}
