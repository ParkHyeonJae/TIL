using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace Study_C_Sharp
{
    class Span_Code
    {
        //unsafe public static void CallByPointer(int* ptr)
        //{
        //    ptr[5] = 200;
        //}


        //unsafe static void Main(string[] args)
        //{



        //    int[] t = new int[256];

        //    fixed (int* t1 = &t[0])
        //    {
        //        CallByPointer(t1);
        //    }

        //    Console.WriteLine(t[5]);

        //}


        unsafe public static void CallByPointer(int* ptr)
        {
            ptr[5] = 20;
        }
        public static void CallByPointer(Span<int> ptr)
        {
            ptr[5] = 20;
        }
        public static void CallByPointer(int[] ptr)
        {
            ptr[5] = 20;
        }



        static void Main(string[] args)
        {

            
            Span<int> spanArr = stackalloc int[256];
            ReadOnlySpan<char> st = stackalloc char[] { 'h', 'a' };


            
            //unsafe
            //{
            //    fixed (int* a = &spanArr[0])
            //    {
            //        CallByPointer(a);
            //    }
            //}

            CallByPointer(spanArr);

            Console.WriteLine(spanArr[5]);          // 20

        }

    }
}
