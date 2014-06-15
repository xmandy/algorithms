#include <iostream>
#include <iomanip>
#include <stack>

using namespace std;

#ifndef _BST_H
#define _BST_H

template <typename T>
class BST
{
	public:
		BST();

		bool empty() const;

		void inorder(ostream& out) const;

		void preorder(ostream& out) const;

		void postorder(ostream& out) const;

		void inorder_loop(ostream& out) const;

		void preorder_loop(ostream& out) const;

		void postorder_loop(ostream& out) const;

		void graph(ostream& out) const;

		bool search(const T& item) const;

		bool search_loop(const T& item) const;

		void insert_loop(const T& item);

		void insert(const T& item);

		void remove(const T& item);

		void remove_loop(const T& item);

	private:

		class BinNode
		{
			public:
				T data;
				BinNode *left;
				BinNode *right;

				BinNode(): left(0), right(0) {};
				BinNode(T item): data(item), left(0), right(0) {};
		};

		class pair
		{
			public:
				BinNode* node;
				bool unUsed;

				pair(BinNode* n, bool used): node(n), unUsed(used) {};
		};

		typedef BinNode * BinNodeP;

		BinNodeP root;

		void inorderAux(ostream& out, BinNodeP subtreeRoot) const;

		void preAux(ostream& out, BinNodeP subtreeRoot) const;

		void postAux(ostream& out, BinNodeP subtreeRoot) const;

		void graphAux(ostream& out, int indent, BinNodeP subtreeRoot) const;

		bool searchAux(const T& item, BinNodeP subtreeRoot) const;

		void insertAux(const T& item, BinNodeP& subtreeRoot);

		void removeAux(const T& item, BinNodeP &subtreeRoot);

		void searchWithParent(T& item, bool& found, BinNodeP& x, BinNodeP& parent);

		
	
};

template <typename T>
void BST<T>::inorderAux(ostream& out, BST<T>::BinNodeP subtreeRoot) const
{
	if(subtreeRoot != NULL)
	{
		inorderAux(out, subtreeRoot->left);
		out << subtreeRoot->data <<" ";
		inorderAux(out, subtreeRoot->right);
	}
}

template <typename T>
void BST<T>::preAux(ostream& out, BinNodeP subtreeRoot) const
{
	if(subtreeRoot != NULL)
	{
		out << subtreeRoot->data << " ";
		preAux(out, subtreeRoot->left);
		preAux(out, subtreeRoot->right);
	}
}

template <typename T>
void BST<T>::postAux(ostream& out, BinNodeP subtreeRoot) const
{
	if(subtreeRoot != NULL)
	{
		postAux(out, subtreeRoot->left);
		postAux(out, subtreeRoot->right);
		out << subtreeRoot->data << " ";
	}
}


template <typename T>
inline void BST<T>::remove(const T& item)
{
	removeAux(item, root);
}

template <typename T>
void BST<T>::searchWithParent(T& item, bool& found, BST<T>::BinNodeP& x, BST<T>::BinNodeP& parent)
{
	x = root;
	parent = NULL;
	found = false;
	while(!found && x)
	{
		if(item < x->data)
		{
			parent = x;
			x = x->left;
		}
		else if(item > x->data)
		{
			parent = x;
			x = x->right;
		}
		else
		{
			found = true;
		}
	}
}

template <typename T>
inline void BST<T>::remove_loop(const T& item)
{
	bool found;
	BST<T>::BinNodeP x, parent;
	searchWithParent(item, found, x, parent);

	if(!found)
		cout << "item to be deleted is not in the tree" <<endl;

	if(x->left && x->right)
	{
		BST<T>::BinNodeP xSuc = x->right;  // find the success node in middle order,
		while(xSuc->left)
		{
			parent = xSuc;
			xSuc = xSuc->left;
		}
		x->data = xSuc->data;
		x = xSuc;
	}
	//after the find success node, the x node must be a node has no child or only has
	//right child.

	// the node has only one not null subtree node.

	BST<T>::BinNodeP subtree = x->left;
	if(subtree == NULL)
		subtree = x->right;
	if(root == NULL)
		root = subtree;
	else if(parent->left == x)
		parent->left = subtree;
	else
		parent->right = subtree;
	delete x;
}

template <typename T>
inline void BST<T>::insert(const T& item)
{
	insertAux(item, root);
}


template <typename T>
inline bool BST<T>::search(const T& item) const
{
	return searchAux(item, root);
}

template <typename T>
inline void BST<T>::graph(ostream& out) const
{
	graphAux(out, 0, root);
}

template <typename T>
inline void BST<T>::inorder(ostream& out) const
{
	inorderAux(out, root);
	out << endl;
}

template <typename T>
inline void BST<T>::preorder(ostream& out) const
{
	preAux(out, root);
	out << endl;
}

template <typename T>
inline void BST<T>::postorder(ostream& out) const
{
	postAux(out, root);
	out << endl;
}

template <typename T>
void BST<T>::inorder_loop(ostream& out) const
{
	stack<BST<T>::pair> s;
	s.push(pair(root, true));
	pair *p;
	BST<T>::BinNodeP temp;
	int unUsed;
	while(!s.empty())
	{
		p = &s.top();
		s.pop();
		temp = p->node;
		unUsed = p->unUsed;

		if(unUsed)
		{
			if(temp->right)
				s.push(pair(temp->right, true));
			s.push(pair(temp, false));
			if(temp->left)
				s.push(pair(temp->left, true));
		}
		else
			cout << temp->data << " ";

	}
	cout << endl;

}

template <typename T>
void BST<T>::preorder_loop(ostream& out) const
{
	stack<BST<T>::BinNodeP> s;
	BST<T>::BinNodeP temp;
	s.push(root);
	while(!s.empty())
	{
		temp = s.top();
		s.pop();
		cout << temp->data << " ";
		if(temp->right)
			s.push(temp->right);
		if(temp->left)
			s.push(temp->left);
	}
	cout << endl;
}

template <typename T>
void BST<T>::postorder_loop(ostream& out) const
{
	stack<BST<T>::pair> s;
	pair *p;
	BST<T>::BinNodeP temp;
	int unUsed;
	s.push(pair(root, true));
	while(!s.empty())
	{
		p = &s.top();
		s.pop();
		temp = p->node;
		unUsed = p->unUsed;
		if(unUsed)
		{
			s.push(pair(temp, false));
			if(temp->right)
				s.push(pair(temp->right, true));
			if(temp->left)
				s.push(pair(temp->left, true));
		}
		else
			cout << temp->data << " ";
	}
	cout << endl;
}

template <typename T>
inline BST<T>::BST(): root(0)
{}

template <typename T>
inline bool BST<T>::empty() const
{ return 0 == root; }

template <typename T>
void BST<T>::removeAux(const T& item, BST<T>::BinNodeP &subtreeRoot)
{
	if(subtreeRoot == NULL)
	{
		cerr<< "not found" <<endl;
		return;
	}

	if(item > subtreeRoot->data)
		removeAux(item, subtreeRoot->right);
	else if(item < subtreeRoot->data)
		removeAux(item, subtreeRoot->left);
	else
	{
		if(subtreeRoot->left && subtreeRoot->right)
		{
			BST<T>::BinNodeP temp = subtreeRoot->right;
			while(temp->left != NULL)
				temp = temp->left;

			subtreeRoot->data = temp->data;
			removeAux(temp->data, subtreeRoot->right);
		}
		else
		{
			BST<T>::BinNodeP temp = subtreeRoot;
			if(subtreeRoot->left == NULL)
				subtreeRoot = subtreeRoot->right;
			else
				subtreeRoot = subtreeRoot->left;
			delete temp;
		}
	}
}


template <typename T>
void BST<T>::graphAux(ostream& out, int indent, BST<T>::BinNodeP subtreeRoot) const
{
	if(subtreeRoot != NULL)
	{
		graphAux(out, indent + 8, subtreeRoot->right);
		out << setw(indent) << " " << subtreeRoot->data << endl;
		graphAux(out, indent + 8, subtreeRoot->left);
	}

}

template <typename T>
void BST<T>::insertAux(const T& item, BST<T>::BinNodeP& subtreeRoot)
{
	if(subtreeRoot == NULL)		
		subtreeRoot = new BinNode(item);
	else if(subtreeRoot->data < item)
		insertAux(item, subtreeRoot->right);
	else if(subtreeRoot->data > item)
		insertAux(item, subtreeRoot->left);
	else
		cerr<<"already in the BST!"<<endl;
}

template <typename T>
void BST<T>::insert_loop(const T&item)
{
}

template <typename T>
bool BST<T>::search_loop(const T& item) const
{
	return true;
}

template <typename T>
bool BST<T>::searchAux(const T& item, BST<T>::BinNodeP subtreeRoot) const
{
	if(subtreeRoot == NULL)
		return false;

	if(subtreeRoot->data == item)
		return true;
	else if(subtreeRoot->data < item)
		return searchAux(item, subtreeRoot->right);
	else
		return searchAux(item, subtreeRoot->left);
}

#endif
