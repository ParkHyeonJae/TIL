using System;
using System.Collections.Generic;
using System.Text;

namespace Study_C_Sharp
{
    class Switch문
    {
        
        public static void Main(string[] args)
        {
            //switch 문
            for (int i = 0; i < args.Length; i++)
            {
                string option = args[i];

                switch (option)
                {
                    case "/p":
                        //...
                        Console.WriteLine("Phone");
                        break;
                    case "/s":
                        Console.WriteLine("SNS");
                        break;
                    case "/k":
                        Console.WriteLine("Kakao");
                        break;
                    default:
                        Console.WriteLine("N/A");
                        break;
                }
            }
        }
    }
}
