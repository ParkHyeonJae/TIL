using System;
using System.Collections.Generic;
using System.Text;

namespace Study_C_Sharp
{
    class ReadOnlyDictionary
    {

        static readonly Dictionary<Int32, String> readonlyDict = new Dictionary<int, string>()
        {
            {0, "안녕" },
            {1, "반가워" },
            {2, "나의 이름은" },
            {3, "박현재야" },
        };


        static void Main(string[] args)
        {

            for (int i = 0; i < readonlyDict.Count; i++)
            {
                Console.WriteLine(readonlyDict[i]);
            }


            foreach (var pair in readonlyDict)
            {
                Console.WriteLine(pair.Value);
            }
        }
    }
}
