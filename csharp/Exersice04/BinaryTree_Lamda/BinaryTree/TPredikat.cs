using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


delegate bool TPredikat<T>(T val);

namespace BinaryTree
{

    delegate bool Gerade(int val);
    interface TPredikat<T>
    {
        bool Matches(T value);
    }

    class Even<T> : TPredikat<T>
    {

        public bool Matches(T element)
        {
            return false;
        }
        public bool Gerade(int element)
        {
            bool res = false;
            if(element % 2 == 0) {
                res = true;
            }
            return res;
        }

    }

    class Negativ<T> : TPredikat<T>
    {

        private Comparison<IComparable> comparer = CompareElements;
        
        public bool Matches(T element)
        {
            Boolean result = false;
            if (comparer((IComparable)element, (IComparable)0.0) <= 0)
            {
                result = true;
            }
            return result;
        }
        public bool Neg(T val)
        {
            Boolean result = false;
            if (comparer((IComparable)val, (IComparable)0.0) <= 0)
            {
                result = true;
            }
            return result;
        }
        public static int CompareElements(IComparable x, IComparable y)
        {
            return x.CompareTo(y);
        }
    }

    class Smaller<T> : TPredikat<T>
    {

        private Comparison<IComparable> comparer = CompareElements;
        public bool Matches(T element)
        {
            Boolean result = false;
            if (comparer((IComparable)element, (IComparable)5.0) <= 0)
            {
                result = true;
            }
            return result;
        }

        public static int CompareElements(IComparable x, IComparable y)
        {
            return x.CompareTo(y);
        }
    }
}
