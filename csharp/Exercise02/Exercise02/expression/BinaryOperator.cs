using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercise02.expression
{
    class BinaryOperator<T,R> : Expression<R>
    {
        protected Expression<T> a = Expression<T>;
        protected Expression<R> b = Expression<R>;

        public void BinaryOperator<T,R>(Expression<T> a,Expression<R> b){
            
        }
    }
}
