#include <iostream>

using namespace std;

#ifdef _BST_H
#define _BST_H

template <typename T>
class BinNode
{
	public:
		T data;
		BinNode *left;
		BinNode *right;

		BinNode(): left(0), right(0) {};
		BinNode(T item): data(item), left(0), right(0) {};
}

typedef BinNode * BinNodeP;

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

	private:
		BinNodeP root;

		void inorderAux(ostream& out) const;

		void graphAux(ostream& out, int indent, BinNodeP subtreeRoot) const;

		bool searchAux(const T& item, BinNodeP subtreeRoot) const;

		void insertAux(const T& item, BinNodeP subtreeRoot);

		
	
}

template <typename T>
inline void insert(const T& item)
{
	return insertAux(item, root);
}


template <typename T>
inline bool search(const T& item) const
{
	return searchAux(item, root);
}

template <typename T>
inline void graph(ostream& out) const
{
	graphAux(out, 0, root);
}

template <typename T>
inline void BST<T>::inorder(ostream& out) const
{
	inorderAux(out, root);
}

template <typename T>
inline BST<T>::BST(): root(0)
{}

template <typename T>
inline BST<T>::empty() const
{ return 0 == root; }

#endif
