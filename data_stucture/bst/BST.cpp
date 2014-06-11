#include "BST.h"

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
