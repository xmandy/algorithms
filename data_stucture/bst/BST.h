#include <iostream>
#include <iomanip>
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

		void graph(ostream& out) const;

		bool search(const T& item) const;

		bool search_loop(const T& item) const;

		void insert_loop(const T& item);

		void insert(const T& item);

		void remove(const T& item);

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

		typedef BinNode * BinNodeP;

		BinNodeP root;

		void inorderAux(ostream& out, BinNodeP subtreeRoot) const;

		void graphAux(ostream& out, int indent, BinNodeP subtreeRoot) const;

		bool searchAux(const T& item, BinNodeP subtreeRoot) const;

		void insertAux(const T& item, BinNodeP& subtreeRoot);

		void removeAux(const T& item, BinNodeP &subtreeRoot);

		
	
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
inline void BST<T>::remove(const T& item)
{
	removeAux(item, root);
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
