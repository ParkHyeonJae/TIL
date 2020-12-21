using System;
using System.Collections.Generic;
using System.Text;

namespace Study_C_Sharp
{
    class String
    {
        public static void Main(string[] args)
        {
            //문자열(string)
            string s1 = "C#";
            string s2 = "Programming";


            //문자(char)
            char c1 = 'A';
            char c2 = 'B';

            char c = s2[0];     //P

            //문자열 결합
            string s4 = s2.Substring(1, 4);     //rogr

            //문자열 치환
            string s5 = s2.Replace("Pro", "PRO");


            //문자열 삭제
            string s6 = s2.Remove(3);

            //공백 삭제
            string s7 = "     Hello    ".Trim();


            //문자열 결합
            string s = s1 + " " + s2;       //C# Programming

            //문자열을 문자배열로
            char[] arr = s.ToCharArray();

            for (int i = 0; i < arr.Length; i++)
            {
                Console.WriteLine(arr[i]);
            }

            //문자배열을 문자열로
            string ss = new string(arr);

            // Mutable Type
            int j = 1;      //100번지
            j = 2;      //100번지

            // ImMutable Type : 객체를 생성을 하면 그 객체에 대한 내용을 변경할 수 없는 것
            string sA = "C#";
            sA = "F#";      // 값만 바뀌는 것처럼 보여도 실제로는 메모리 주소를 새로 다시 할당해서 값을 넣음.

            // 사용하면 안됨, 일반적인 string으로 결합하면 Immutable Type이기 때문에 과도한 연산을 하게 되서 문제가 발생할 수 있음.
            //string sss = "";
            //for (int i = 0; i < 10000000; i++)
            //{
            //    sss = sss + i.ToString();
            //}

            // 해결책 : StringBuilder를 사용한다.
            StringBuilder sb = new StringBuilder();         // Mutable Type

            for (int i = 0; i < 10000; i++)
            {
                sb.Append(i.ToString());
            }
            string result = sb.ToString();      // 즉 문자열 결합을 할때 반복문을 이용해서 결합할 일이 있다면 StringBuilder를 사용하자
        }
    }
}
