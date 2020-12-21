using System;

namespace Study_C_Sharp
{
    class if문
    {
        static void Main(string[] args)
        {
            // if문
            int score = 95;

            if (score >= 90)
            {
                if (score == 100)
                {
                    Console.WriteLine("만점");
                }
                else
                {
                    Console.WriteLine("수");
                }
            }
            else if (score >= 80)
            {
                Console.WriteLine("우");
            }
            else if (score >= 70)
            {
                Console.WriteLine("미");
            }
            else if (score >= 60)
            {
                Console.WriteLine("양");
            }
            else
            {
                Console.WriteLine("기");
            }

            //int a = -1;
            //int b;
            //if (a > 0)
            //{
            //    b = a;
            //}
            //else
            //{
            //    b = 0;
            //}
            int a = -1;
            int b = (a > 0) ? a : 0;        //조건 연산자
        }
    }
}