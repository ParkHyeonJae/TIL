using System;
using System.Collections.Generic;
using System.Text;

namespace Study_C_Sharp
{
    class DataType
    {
        public static void Main(string[] args)
        {
            bool b = true;

            short sh = 100;
            int i = 100;
            long l = 10000L;        // signed integer
            ushort us = 111;
            uint ui = 110U;
            ulong ul = 1000UL;

            float f = 3.14f;        //32bit
            double d = 3.141592d;       // 64bit
            decimal dd = 3.14M;     //128bit

            char ch = '한'; //16bit  Unicode
            byte by = 0x46; // 8 bit

            object o = 123;

            string s = null;        //null은 reference 타입에서만 사용이 가능하다

            int? ix = null;         // 그래서 Value 타입에 null을 사용하려면 Type? <변수명> 형식으로 지정해 주면 null 사용이 가능해진다.      
            if (ix == null)
            {
                Console.WriteLine("ix is Null");
            }
            else
            {
                Console.WriteLine(ix.Value);
            }

            int result = ix ?? 0;
        }
    }
}
