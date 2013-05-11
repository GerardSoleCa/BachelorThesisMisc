using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace gpio_event_pinvoke
{
    class Program
    {
        static void Main(string[] args)
        {
            start_polling(17,new MyCallback(print));
        }

        static void print(String str)
        {
            Console.WriteLine("C#");
            Console.WriteLine(str);
        }

        public delegate void MyCallback(String i);

        [DllImport("libgpio.so", CallingConvention = CallingConvention.StdCall)]
        public static extern void start_polling(int gpio, MyCallback callback);
    }
}
