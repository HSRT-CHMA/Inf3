using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinaryTree
    // Shared namespace
{
    delegate bool Predikat<T>(T data);
    // Keyword , creates an allias of a method 

        abstract class AbstractTree<T>
            where T : IComparable<T>
            // Sets a condition for T, which must inherit from IComparable
        {
            /// <summary>
            /// This abstarct Method organises the insertion of new nodes
            /// </summary>
            /// <param name="data"> The value to be inserted</param>
            abstract public void insert(T data);
           /// <summary>
           /// This abstarct Method organises the Removal of nodes 
           /// </summary>
           /// <param name="data"></param>
           /// <returns>Wheter or not a value is deleted</returns>
            abstract public Boolean delete(T data);
            /// <summary>
            /// 
            /// </summary>
            /// <param name="data"></param>
            /// <returns></returns>
            abstract public bool hasNode(T data);
            /// <summary>
            /// Filter-Method receives a Predicate (Lambda) and checks tree for matches
            /// </summary>
            /// <param name="pred">The Lambda-Expression which the method receives</param>
            /// <returns>The Container which conatains the values matched by the Lambda-Expressions</returns>
            abstract public T[] Filter(Predikat<T> pred);
   

        }
}
