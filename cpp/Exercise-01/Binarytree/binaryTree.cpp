//Binary Tree

#include <iostream>

using namespace std;

class node{
	private:
		int index;
	node* nodeleft;
	node* noderight;
	public:
		void in_index(int x){
			index = x;
		}

		void in_nodeleft(node* n){
			nodeleft = n;
		}

		void in_noderight(node* n){
			noderight = n;
		}

		int out_index(void){
			return index;
		}

		node* out_nodeleft(void){
			return nodeleft;
		}

		node* out_noderight(void){
			return noderight;
		}
};

class tree{
	private:
		node* root;
		int number;
		// number of nodes
		bool available(node*, int);
		node* searching(node*, int);
		void pre(node*);

	public:
		tree(void){
			root = 0;
			number = 0;
		}

		bool isEmpty(void){
			return (root == 0);
		}

		bool isAvailable(int);
		//rekursiv
		node* search(int);
		void add(int);
		//iterativ
		void delet(int);
		void preOrder(void);
		//rekursiv
		int out_number(void){
			return number;
		}
};

bool tree::isAvailable(int x){
	if (!(isEmpty())){
		return available(root, x);
	}
	else{
		return false;
	}
}

bool tree::available(node* n, int x){
	if (x == n->out_index()){
		return true;
	}
	else if (x < n->out_index()){
		if (n->out_nodeleft() != 0){
			return available(n->out_nodeleft(), x);
		}
		else{
			return false;
		}
	}
	else{
		if (n->out_noderight()){
			return available(n->out_noderight(), x);
		}
		else{
			return false;
		}
	}
}

void tree::add(int x){
	node* newNode = 0;
	newNode = new node;
	newNode->in_index(x);
	newNode->in_nodeleft(0);
	newNode->in_noderight(0);

	bool stop = false;
	node* help = root;
	if (!(isEmpty()) && !(isAvailable(x))){
		while (!(stop)){
			if (x < help->out_index()){
				if (help->out_nodeleft() != 0){
					help = help->out_nodeleft();
				}
				else{
					stop = true;
				}
			}
			else{
				if (help->out_noderight() != 0){
					help = help->out_noderight();
				}
				else{
					stop = true;
				}
			}
		}
		if (x < help->out_index()){
			help->in_nodeleft(newNode); //add left
		}
		else{
			help->in_noderight(newNode); //add right
		}
		cout << " -> " << x << "would be added." << endl;
		number++;
	}
	else if (isEmpty()){
		//add to root
		root = newNode;
		cout << " -> " << x << "would be added." << endl;
		number++;
	}
	else{
		cout << " -> " << x << " is availible." << endl;
	}
}

void tree::delet(int x){
	node* h1 = root;
	node* h2 = root;
	node* h3 = root; 
	node* h4 = root;
	int change;
	if (isAvailable(x)){
		if (!(isEmpty())){
			if (x == root->out_index()){
				//delet root
				if ((root->out_nodeleft() == 0) && (root->out_noderight() == 0)){
					root = 0;
				}
				else if ((root->out_nodeleft() != 0) && (root->out_noderight() == 0)){
					root = root->out_nodeleft();
				}
				else if ((root->out_nodeleft() == 0) && (root->out_noderight() != 0)){
					root = root->out_noderight();
				}
				else{
					//setze h3 auf den bzgl.der wurzel nächstgrösseren knoten(blatt!)
					h3 = root->out_noderight();
					while (h3->out_nodeleft() != 0){
						h3 = h3->out_nodeleft();
					}
					//set h4 on the father from h3
					h4 = root;
					while ((h4->out_nodeleft() != h3) && (h4->out_noderight() != h3)){
						if (h4->out_index() < h3->out_index()){
							h4 = h4->out_noderight();
						}
						else{
							h4 = h4->out_nodeleft();
						}
					}
					change = root->out_index();
					root->in_index(h3->out_index());
					h3->in_index(change);
					if (h3 == h4->out_nodeleft()){
						h4->in_nodeleft(0);
					}
					else{
						h4->in_noderight(0);
					}
				}
			}
			else{
				//inneren Knoten löschen
				h1 = search(x);
				//setze h1 auf den zu löschenden Knoten
				//setze h2 auf vater von h1
				while ((h2->out_nodeleft() != h1) && (h2->out_noderight() != h1)){
					if (x < h2->out_index()){
						h2 = h2->out_nodeleft();
					}
					else{
						h2 = h2->out_noderight();
					}
				}
				if ((h1->out_nodeleft() == 0) && (h1->out_noderight() == 0)){
					if (h1 == h2->out_nodeleft()){
						h2->in_nodeleft(0);
					}
					else{
						h2->in_noderight(0);
					}
				}
				else if ((h1->out_nodeleft() != 0) && (h1->out_noderight() == 0)){
					if (h1 == h2->out_nodeleft()){
						h2->in_nodeleft(h1->out_nodeleft());
					}
					else{
						h2->in_noderight(h1->out_nodeleft());
					}
				}
				else if ((h1->out_nodeleft() == 0) && (h1->out_noderight() != 0)){
					if (h1 == h2->out_nodeleft()){
						h2->in_nodeleft(h1->out_noderight());
					}
					else{
						h2->in_noderight(h1->out_noderight());
					}
				}
				else{
					//setze h3 auf den bzgl. h1 nächstgrösseren knoten (blatt!)
					h3 = h1->out_noderight();
					while (h3->out_nodeleft() != 0){
						h3 = h3->out_nodeleft();
					}
					//setze h4 auf den vater von h3
					h4 = h1;
					while ((h4->out_nodeleft() != h3) && (h4->out_noderight() != h3)){
						if (h4->out_index() < h3->out_index()){
							h4 = h4->out_noderight();
						}
						else{
							h4 = h4->out_nodeleft();
						}
					}
					//change
					change = h1->out_index();
					h1->in_index(h3->out_index());
					h3->in_index(change);
					if (h3 == h4->out_nodeleft()){
						h4->in_nodeleft(0);
					}
					else{
						h4->in_noderight(0);
					}
				}
			}
			cout << " -> " << x << " would be deleted." << endl;
			number--;
		}
		else{
			cout << " -> the tree is empty." << endl;
		}
	}
	else{
		cout << " -> " << x << " is not available." << endl;
	}
}

void tree::preOrder(void){
	if (!(isEmpty())){
		cout << "PreOrder:\t";
		pre(root);
		cout << endl;
	}
	else{
		cout << " -> the tree is empty" << endl;
	}
}

void tree::pre(node* n){
	cout << n->out_index() << " ";
	if (n->out_nodeleft() != 0){
		pre(n->out_nodeleft());
	}
	if (n->out_noderight() != 0){
		pre(n->out_noderight());
	}
}

int main(){
	int write = -1;
	int x = 0;
	tree t; 

	while (write != 0){
		cout << "1 - search" << endl;
		cout << "2 - add" << endl;
		cout << "3 - delet" << endl;
		cout << "4 - preOrder" << endl;

		cin >> write;
		cout << endl;
		
		switch (write){
		case 1: 
			cout << "search: ";
			cin >> x;
			if (t.isAvailable(x)){
				cout << x << " is available." << endl;
			}
			else{
				cout << x << " is not available" << endl;
			}
			break;
		case 2:
			cout << "add: ";
			cin >> x;
			t.add(x);
			break;
		case 3:
			cout << "delet: ";
			cin >> x;
			t.delet(x);
			break;
		case 4:
			t.preOrder();
			break;
		}
	}
	return 0;
}