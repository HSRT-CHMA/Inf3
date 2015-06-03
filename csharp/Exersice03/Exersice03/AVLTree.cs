using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exersice03
{
    class AVLTree<T> : Tree<T>
        where T : IComparable
    {
        //constructor
        public AVLTree()
        {
            Root = null;
        }


        public bool IsBanlance(Node<T> root)
        {
            if (root == null) return true;
            else return Math.Abs(GetHeight(root.LeftChild) - GetHeight(root.RightChild)) < 2;
        }


        //Rebanlance the node
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


        //Left Rotation
        public bool LeftRotation(Node<T> root)
        {
            try
            {
                // tie the root's old rightchild's left tree as the the root's new right tree
                Node<T> rootRight = root.RightChild;
                root.RightChild = rootRight.LeftChild;
                if (rootRight.LeftChild != null) rootRight.LeftChild.Parent = root;

                rootRight.Parent = root.Parent;
                if (root.Parent == null)//the rotating root is the tree's root node
                    Root = rootRight;
                else if (root.Parent.LeftChild == root)
                    root.Parent.LeftChild = rootRight;
                else root.Parent.RightChild = rootRight;

                rootRight.LeftChild = root;
                root.Parent = rootRight;

                return true;
            }
            catch (Exception)
            {
                return false;
            }
        }

        //Right Rotation
        public bool RightRotation(Node<T> root)
        {
            try
            {
                Node<T> rootLeft = root.LeftChild;
                root.LeftChild = rootLeft.RightChild;
                if (rootLeft.RightChild != null) rootLeft.RightChild.Parent = root;

                rootLeft.Parent = Root.Parent;

                if (Root.Parent == null)//root is the tree's root
                    Root = rootLeft;
                else if (root.Parent.LeftChild == root)
                    root.Parent.LeftChild = rootLeft;
                else root.Parent.RightChild = rootLeft;

                rootLeft.RightChild = root;
                root.Parent = rootLeft;

                return true;
            }
            catch (Exception)
            {
                return false;
            }
        }
    }
}
