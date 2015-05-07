using Exercise01.System.Diagnostics.Contracts;
using System;
using System.Collections.Generic;
using System.Diagnostics.Contracts;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercise01
{
    public abstract class DivisibleProblem<Solution> : Problem<Solution>
    {
        
        /*
         * Variables of Divisable Problem
         * Directly Solvable is initialized with false 
         * BinaryTree is initalizied with null
         */
        protected bool directlySolvable = false;
        protected BinaryTree tree = null;

        /*
         * Abstract Methods 
         * CheckSolvable -> If there is a trivial Solution available
         * GetSum -> Method for calculating the summary of the BinaryTree
         */
        public abstract void CheckSolvable(Node node);
        protected abstract void GetSum(Node node);

        /*
         * Setter for BinaryTree with Assert if
         * the tree is set to the given value
         */
        public void SetBinaryTree(BinaryTree tree)
        {
            this.tree = tree;
            Contract.Assert(this.tree == tree);
        }

        /*
         * Getter of BinaryTree
         */
        public BinaryTree GetBinaryTree()
        {
            return tree;
        }

        public virtual void ComputeSolution()
        {
            CheckSolvable(tree.GetRoot());
            if (directlySolvable)
            {
                Console.WriteLine("BinaryTree is trivial and directly Solvable");

            }
            else
            {
                GetSum(tree.GetRoot());
            }
        }
    }
}
