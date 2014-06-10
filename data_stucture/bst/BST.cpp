#include "BST.h"

template <typename T>
void BST<T>::inorderAux(ostream& out, BinNodeP subtreeRoot) const
{
	if(subtreeRoot != NULL)
	{
		inorderAux(out, subtreeRoot->left);
		out << subtreeRoot->data <<" ";
		inorderAux(out, subtreeRoot->right);
	}
}

template <typename T>
void BST<T>::graphAux(ostream& out, int indent, BinNodeP subtreeRoot) const
{
	if(BinNodeP != NULL)
	{
		graphAux(out, indent + 8, subtreeRoot->right);
		out << setw(indent) << " " << subtreeRoot->data << endl;
		graphAux(out, indent + 8, subtreeRoot->left);
	}

}

template <typename T>
void BST<T>::insertAux(const T& item, BinNodeP subtreeRoot)
{
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
bool BST<T>::searchAux(const T& item, BinNodeP subtreeRoot) const
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
