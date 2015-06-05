using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestBaum
{
    class AVLTree<T> : BinaryTree<T>
        where T : IComparable
    {

        /// this is the constructor AVLTree()
        /// it declares only Root
        public AVLTree()
        {
            Root = null;
        }

        /// this method checks if the tree is balanced
        /// chekcs if the hight of the left side and the hight of the rigth side under bigger then 1
        /// then it looks if the left side is bigger then the right side -> left case
        /// RightRotation will be called
        /// and this for all cases
        public Node<T> BalanceTree(Node<T> current)
        {
            int b_factor = BalanceFactor(current); // differnce between left and right Child
            if (b_factor > 1)
            {
                if (BalanceFactor(current.LeftChild) > 0)
                {
                    current = RotateLL(current);
                }
                else
                {
                    current = RotateLR(current);
                }
            }
            else if (b_factor < -1)
            {
                if (BalanceFactor(current.RightChild) > 0)
                {
                    current = RotateRL(current);
                }
                else
                {
                    current = RotateRR(current);
                }
            }
            return current;
        }

        /// <summary>
        ///  Returns the Factor between the left and the right node
        /// </summary>
        /// <param name="current"></param>
        public int BalanceFactor(Node<T> current)
        {
            int l = GetHeight(current.LeftChild);
            int r = GetHeight(current.RightChild);
            int b_factor = l - r;
            return b_factor;
        }

        /// <summary>
        /// Rotate Right Right, goes through the rightChild parent 
        /// than through the LeftChild parent
        /// </summary>
        /// <param name="parent"></param>
        /// <returns>pivot</returns>
        public Node<T> RotateRR(Node<T> parent)
        {
            Node<T> pivot = parent.RightChild;
            parent.RightChild = pivot.LeftChild;
            pivot.LeftChild = parent;
            return pivot;
        }

        /// <summary>
        /// Rotate Left Left, goes through the leftChild parent
        /// than through the rightChild parent
        /// </summary>
        /// <param name="parent"></param>
        /// <returns>pivot</returns>
        public Node<T> RotateLL(Node<T> parent)
        {
            Node<T> pivot = parent.LeftChild;
            parent.LeftChild = pivot.RightChild;
            pivot.RightChild = parent;
            return pivot;
        }

        /// <summary>
        /// Rotate Left Right, goes through the leftChild parent
        /// and call the RotateRR
        /// </summary>
        /// <param name="parent"></param>
        /// <returns>RotateLL(parent)</returns>
        public Node<T> RotateLR(Node<T> parent)
        {
            Node<T> pivot = parent.LeftChild;
            parent.LeftChild = RotateRR(pivot);
            return RotateLL(parent);
        }

        /// <summary>
        /// Rotate Right Left, goes through the RightChild parent
        /// and call the RotateLL
        /// </summary>
        /// <param name="parent"></param>
        /// <returns>RotateRR(parent)</returns>
        public Node<T> RotateRL(Node<T> parent)
        {
            Node<T> pivot = parent.RightChild;
            parent.RightChild = RotateLL(pivot);
            return RotateRR(parent);
        }


        /*/// this method checks if the tree is balanced
        /// chekcs if the hight of the left side and the hight of the rigth side under bigger then 1
        /// then it looks if the left side is bigger then the right side -> left case
        /// RightRotation will be called
        /// and this for all cases
        /// <param name="root"></param>
        /// <returns></returns>
        public bool ReBanlance(Node<T> root)
        {
            try
            {
                int heightDiff = GetHeight(root.LeftChild) - GetHeight(root.RightChild);
                if (heightDiff > 1)//left case
                {
                    if (GetHeight(root.LeftChild.LeftChild) > GetHeight(root.LeftChild.RightChild))//left left case
                    {
                        RightRotation(root);
                    }
                    else// left right case
                    {
                        LeftRotation(root.LeftChild);
                        RightRotation(root);
                    }
                }
                else if (heightDiff < -1)//right case
                {
                    if (GetHeight(root.RightChild.LeftChild) > GetHeight(root.RightChild.RightChild))//right left case
                    {
                        RightRotation(root.RightChild);
                        LeftRotation(root);
                    }
                    else//right right case
                    {
                        LeftRotation(root.RightChild);
                        RightRotation(root);
                    }
                }

                return true;
            }
            catch (Exception)
            {
                return false;
            }
        }


        /// here beginns the left rotation
        /// <param name="root"></param>
        /// <returns></returns>
        public bool LeftRotation(Node<T> root)
        {
            try
            {
                // tie the root's old rightchild's left tree as the the root's new right tree
                Node<T> rootRight = root.RightChild;
                root.RightChild = rootRight.LeftChild;
                if (rootRight.LeftChild != null)
                {
                    rootRight.LeftChild.Parent = root;
                }
                rootRight.Parent = root.Parent;
                if (root.Parent == null)
                {
                    Root = rootRight; //the rotating root is the tree's root node
                }
                else if (root.Parent.LeftChild == root)
                {
                    root.Parent.LeftChild = rootRight;
                }
                else
                {
                    root.Parent.RightChild = rootRight;
                }
                rootRight.LeftChild = root;
                root.Parent = rootRight;

                return true;
            }
            catch (Exception)
            {
                return false;
            }
        }

        /// here beginns the right rotation
        /// <param name="root"></param>
        /// <returns></returns>
        public bool RightRotation(Node<T> root)
        {
            try
            {
                Node<T> rootLeft = root.LeftChild;
                root.LeftChild = rootLeft.RightChild;
                if (rootLeft.RightChild != null)
                {
                    rootLeft.RightChild.Parent = root;
                }
                rootLeft.Parent = Root.Parent;

                if (Root.Parent == null)
                {
                    Root = rootLeft; //root is the tree's root
                }
                else if (root.Parent.LeftChild == root)
                {
                    root.Parent.LeftChild = rootLeft;
                }
                else
                {
                    root.Parent.RightChild = rootLeft;
                }
                rootLeft.RightChild = root;
                root.Parent = rootLeft;

                return true;
            }
            catch (Exception)
            {
                return false;
            }
        }*/
    }
}
