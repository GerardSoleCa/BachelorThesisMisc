using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RaspberryPiAlterAid
{
    public class RPiGPIO
    {
        // RPi Version 1
        public static enum Pin : int 
        {
             // RPi Version 1
            V1_P1_03        =  0,  ///< Version 1, Pin P1-03
            V1_P1_05        =  1,  ///< Version 1, Pin P1-05
            V1_P1_07        =  4,  ///< Version 1, Pin P1-07
            V1_P1_08        = 14,  ///< Version 1, Pin P1-08, defaults to alt function 0 UART0_TXD
            V1_P1_10        = 15,  ///< Version 1, Pin P1-10, defaults to alt function 0 UART0_RXD
            V1_P1_11        = 17,  ///< Version 1, Pin P1-11
            V1_P1_12        = 18,  ///< Version 1, Pin P1-12
            V1_P1_13        = 21,  ///< Version 1, Pin P1-13
            V1_P1_15        = 22,  ///< Version 1, Pin P1-15
            V1_P1_16        = 23,  ///< Version 1, Pin P1-16
            V1_P1_18        = 24,  ///< Version 1, Pin P1-18
            V1_P1_19        = 10,  ///< Version 1, Pin P1-19, MOSI when SPI0 in use
            V1_P1_21        =  9,  ///< Version 1, Pin P1-21, MISO when SPI0 in use
            V1_P1_22        = 25,  ///< Version 1, Pin P1-22
            V1_P1_23        = 11,  ///< Version 1, Pin P1-23, CLK when SPI0 in use
            V1_P1_24        =  8,  ///< Version 1, Pin P1-24, CE0 when SPI0 in use
            V1_P1_26        =  7,  ///< Version 1, Pin P1-26, CE1 when SPI0 in use
        
            // RPi Version 2
            V2_P1_03 = 2,  ///< Version 2, Pin P1-03
            V2_P1_05 = 3,  ///< Version 2, Pin P1-05
            V2_P1_07 = 4,  ///< Version 2, Pin P1-07
            V2_P1_08 = 14,  ///< Version 2, Pin P1-08, defaults to alt function 0 UART0_TXD
            V2_P1_10 = 15,  ///< Version 2, Pin P1-10, defaults to alt function 0 UART0_RXD
            V2_P1_11 = 17,  ///< Version 2, Pin P1-11
            V2_P1_12 = 18,  ///< Version 2, Pin P1-12
            V2_P1_13 = 27,  ///< Version 2, Pin P1-13
            V2_P1_15 = 22,  ///< Version 2, Pin P1-15
            V2_P1_16 = 23,  ///< Version 2, Pin P1-16
            V2_P1_18 = 24,  ///< Version 2, Pin P1-18
            V2_P1_19 = 10,  ///< Version 2, Pin P1-19, MOSI when SPI0 in use
            V2_P1_21 = 9,  ///< Version 2, Pin P1-21, MISO when SPI0 in use
            V2_P1_22 = 25,  ///< Version 2, Pin P1-22
            V2_P1_23 = 11,  ///< Version 2, Pin P1-23, CLK when SPI0 in use
            V2_P1_24 = 8,  ///< Version 2, Pin P1-24, CE0 when SPI0 in use
            V2_P1_26 = 7,  ///< Version 2, Pin P1-26, CE1 when SPI0 in use

            // RPi Version 2, new plug P5
            V2_P5_03 = 28,  ///< Version 2, Pin P5-03
            V2_P5_04 = 29,  ///< Version 2, Pin P5-04
            V2_P5_05 = 30,  ///< Version 2, Pin P5-05
            V2_P5_06 = 31,  ///< Version 2, Pin P5-06
        };

        public static enum Direction { IN, OUT };

        private const string GPIO_PATH = "/sys/class/gpio/";

        //contains list of pins exported with an OUT direction
        private List<Pin> _out = new List<Pin>();

        //contains list of pins exported with an IN direction
        private List<Pin> _in = new List<Pin>();

        //set to true to write whats happening to the screen
        private const bool DEBUG = true;

        //this gets called automatically when we try and output to, or input from, a pin
        private void InitPin(Pin pin, Direction direction)
        {
            //unexport if it we're using it already
            if (_out.Contains(pin) || _in.Contains(pin)) UnexportPin(pin);

            //export
            File.WriteAllText(GPIO_PATH + "export", pin);

            if (DEBUG) Console.WriteLine("exporting pin " + pin + " as " + direction);

            // set i/o direction
            File.WriteAllText(GPIO_PATH + pin.ToString() + "/direction", direction.ToString().ToLower());

            //record the fact that we've setup that pin
            if (direction == enumDirection.OUT)
                _OutExported.Add(pin);
            else
                _InExported.Add(pin);
        }

        //no need to setup pin this is done for you
        public void OutputPin(enumPIN pin, bool value)
        {
            //if we havent used the pin before,  or if we used it as an input before, set it up
            if (!_OutExported.Contains(pin) || _InExported.Contains(pin)) SetupPin(pin, enumDirection.OUT);

            string writeValue = "0";
            if (value) writeValue = "1";
            File.WriteAllText(GPIO_PATH + pin.ToString() + "/value", writeValue);

            if (DEBUG) Console.WriteLine("output to pin " + pin + ", value was " + value);
        }

        //no need to setup pin this is done for you
        public bool InputPin(enumPIN pin)
        {
            bool returnValue = false;

            //if we havent used the pin before, or if we used it as an output before, set it up
            if (!_InExported.Contains(pin) || _OutExported.Contains(pin)) SetupPin(pin, enumDirection.IN);

            string filename = GPIO_PATH + pin.ToString() + "/value";
            if (File.Exists(filename))
            {
                string readValue = File.ReadAllText(filename);
                if (readValue != null && readValue.Length > 0 && readValue[0] == '1') returnValue = true;
            }
            else
                throw new Exception(string.Format("Cannot read from {0}. File does not exist", pin));

            if (DEBUG) Console.WriteLine("input from pin " + pin + ", value was " + returnValue);

            return returnValue;
        }

        //if for any reason you want to unexport a particular pin use this, otherwise just call CleanUpAllPins when you're done
        public void UnexportPin(enumPIN pin)
        {
            bool found = false;
            if (_OutExported.Contains(pin))
            {
                found = true;
                _OutExported.Remove(pin);
            }
            if (_InExported.Contains(pin))
            {
                found = true;
                _InExported.Remove(pin);
            }

            if (found)
            {
                File.WriteAllText(GPIO_PATH + "unexport", GetPinNumber(pin));
                if (DEBUG) Console.WriteLine("unexporting  pin " + pin);
            }
        }

        public void CleanUpAllPins()
        {
            for (int p = _OutExported.Count - 1; p >= 0; p--) UnexportPin(_OutExported[p]); //unexport in reverse order
            for (int p = _InExported.Count - 1; p >= 0; p--) UnexportPin(_InExported[p]);
        }

        private string GetPinNumber(enumPIN pin)
        {
            return ((int)pin).ToString(); //e.g. returns 17 for enum value of gpio17
        }

        static void Main(string[] args){
            Console.WriteLine("Hola uqe tal");
        }

    }

}
