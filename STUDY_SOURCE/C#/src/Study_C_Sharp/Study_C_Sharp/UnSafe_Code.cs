using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.CompilerServices;

namespace Study_C_Sharp
{
    class UnSafe_Code
    {


        //unsafe static void Main(string[] args)
        //{
        //    const int Length = 1500;
        //    int* a = stackalloc int[Length];
        //    for (int i = 0; i < Length; i++)
        //        a[i] = i;

        //    for (int i = 0; i < Length; i++)
        //    {
        //        Console.WriteLine(a[i]);
        //    }


        //}

        class Point
        {
            public int x;
            public int y;

        }

        unsafe static void CallByPointer(int* ptr)
        {
            *ptr = 10;
        }

        static void Main(string[] args)
        {

            Point point = new Point();
            point.x = 200;

            unsafe
            {

                fixed(int* x = &point.x)
                {
                    CallByPointer(x);
                }


            }


            Console.WriteLine(point.x);


        }


    }
}
