using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.SPOT.Hardware;
using IOSharp.NETMF.RaspberryPi.Hardware;
using System.Threading;


namespace raspberrypi
{
    class Program
    {
        static OutputPort foo;
        public static void Main()
        {
            InterruptPort button = new InterruptPort(Pins.V2_GPIO3, false,
              Port.ResistorMode.Disabled, Port.InterruptMode.InterruptEdgeLow);

            button.OnInterrupt += new NativeEventHandler(button_OnInterrupt);

            foo = new OutputPort(Pins.V2_GPIO11, false);

            Debug.Print("Started");
            Thread.Sleep(-1);
        }

        static void button_OnInterrupt(uint port, uint state, DateTime time)
        {
            foo.Write(true);
            foo.Write(false);
            Debug.Print("END");
        }
    }
}
