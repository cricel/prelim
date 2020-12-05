// Spring 2017 - Question 3
// BST
// Suphanut Jamonnak


#include <iostream>
#include <iomanip>

// Node need to change to Struct
class Node {
public:
	Node * left;
	Node * right;
	int val;

	Node () {
		left = nullptr;
		right = nullptr;
	}

	Node(int v, Node * l, Node * r) {
		val = v;
		left = l;
		right = r;
	}
};

class BST {
public:

	// constructor
	BST() {
		root = nullptr;
	}
	// destructor
	~BST() {
		destroy(root);
	}
	// copy constructor
	BST(const BST& c) {
		root = copy(c.root);
	}
	// recursive insert
	void assign(Node* r, int item) {
		if (root == nullptr) {
			root = new Node(item, nullptr, nullptr);
			return;
		}

		if (item < r->val) {
			if (r->left == nullptr)
				r->left = new Node(item, nullptr, nullptr);
			else
				assign(r->left, item);
		}
		else {
			if (r->right == nullptr)
				r->right = new Node(item, nullptr, nullptr);
			else
				assign(r->right, item);
		}
	}

	// take integer parameter
	void insert(int item) {
		assign(root, item);
	}

	// for testing
	void print(int indent) {
		printInOrder(root, indent);
	}

private:
	Node * root;

	void destroy(Node * root) {
		if (root != nullptr) {
			destroy(root->left);
			destroy(root->right);

			delete root;
			root = nullptr;
		}
	}

	// pre-order node copy
	Node * copy(Node * root) {
		if (root != nullptr) {
			Node * r = new Node(root->val, nullptr, nullptr);
			r->left = copy(root->left);
			r->right = copy(root->right);
			return r;
		}
		return nullptr;
	}

	// for testing
	void printInOrder(Node* p, int indent)
	{
	    if(p != NULL) {
	        if(p->right) {
	            printInOrder(p->right, indent+4);
	        }
	        if (indent) {
	            std::cout << std::setw(indent) << ' ';
	        }
	        if (p->right) std::cout<<" /\n" << std::setw(indent) << ' ';
	        std::cout<< p->val << "\n ";
	        if(p->left) {
	            std::cout << std::setw(indent) << ' ' <<" \\\n";
	            printInOrder(p->left, indent+4);
	        }
	    }
	}
};

int main() {

	// create new BST b
	BST b;
	b.insert(10);
	b.insert(5);
	b.insert(15);

	// copy b to c
	BST c(b);

	// This insert is not copy to BST c
	b.insert(4);
	b.insert(8);
	b.insert(14);
	b.insert(16);

	// show 2 bst
	std::cerr << "-------------" << std::endl;
	b.print(5);
	std::cerr << "-------------" << std::endl;
	c.print(5);
	std::cerr << "-------------" << std::endl;
}
