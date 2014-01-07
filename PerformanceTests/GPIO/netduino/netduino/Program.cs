using System;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using Microsoft.SPOT;
using Microsoft.SPOT.Hardware;
using SecretLabs.NETMF.Hardware;
using SecretLabs.NETMF.Hardware.NetduinoPlus;

namespace netduino
{
    public class Program
    {
        public static void Main()
        {

            // Specify the GPIO pin we want to use as an interrupt 
            // source, specify the edges the interrupt should trigger on 
            InterruptPort button = new InterruptPort(Pins.ONBOARD_SW1, false,
              Port.ResistorMode.Disabled, Port.InterruptMode.InterruptEdgeLow);

            // Hook up an event handler (delegate) to the OnInterrupt event 
            button.OnInterrupt += new NativeEventHandler(button_OnInterrupt);
            Debug.Print("Started");
            Thread.Sleep(-1);
        }

        static void button_OnInterrupt(uint port, uint state, DateTime time)
        {
            // This method is called whenever an interrupt occurrs
            Debug.Print("Interruption");
            OutputPort bar = new OutputPort(Pins.GPIO_PIN_D7, false);
            bar.Write(false);
            bool foo = false;
            OutputPort o = new OutputPort(Pins.GPIO_PIN_D0, false);

            bar.Write(true);
            for (int i = 0; i < 200; i++)
            {
                foo = !foo;
                o.Write(foo);
            }
            bar.Write(false);
            Debug.Print("END");
        }
    }

}

