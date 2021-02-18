using System;
using System.Collections.Generic;
using System.Linq.Expressions;
using System.Text;

namespace Study_C_Sharp
{
    class LamdaExpression
    {
        static void Main(string[] args)
        {
            // 1 + 2
            Expression constant01 = Expression.Constant(1);
            Expression constant02 = Expression.Constant(2);
            Expression exp = Expression.Add(constant01, constant02);

            Expression<Func<int>> lambda01 = Expression.Lambda<Func<int>>(exp);
            Func<int> l = lambda01.Compile();
            Console.WriteLine(l());


            Expression param1 = Expression.Parameter(typeof(int));
            Expression param2 = Expression.Parameter(typeof(int));
            Expression exp1 = Expression.Add(param1, param2);

            Expression<Func<int, int, int>> APlusBExpression 
                = Expression.Lambda<Func<int, int, int>>
                (exp1, new[] { (ParameterExpression)param1, (ParameterExpression)param2 });
            Func<int, int, int> APlusB = APlusBExpression.Compile();
            Console.WriteLine(APlusB(20, 90));
        }
    }
}
