#include <iostream>
using namespace std;

#include "BST.h"


//test data: 6 4 3 5 12 11 13 9

int main(int argc, const char *argv[])
{
	
	BST<int> intBST;

	cout<< "BST " << (intBST.empty() ? "is" : "is not") << " empty" <<endl;

	cout << "Inorder"<<endl;
	intBST.inorder(cout);

	//int number;
   /* for(;;)*/
	//{
		//cout << "input the number: ";
		//cin >> number;
		//if(number < 0)
			//break;
		//intBST.insert(number);
	/*}*/
	intBST.insert(50);
	intBST.insert(30);
	intBST.insert(70);
	intBST.insert(20);
	intBST.insert(40);
	intBST.insert(60);
	intBST.insert(80);

	intBST.graph(cout);

	intBST.search(9);
	intBST.search(100);


   /* intBST.remove(100);*/
	//intBST.remove(12);
	//intBST.graph(cout);
	//intBST.remove(3);
	/*intBST.graph(cout);*/

	intBST.remove(6);
	intBST.graph(cout);

	intBST.preorder(cout);
	intBST.inorder(cout);
	intBST.postorder(cout);

	intBST.preorder_loop(cout);
	intBST.inorder_loop(cout);
	intBST.postorder_loop(cout);

	return 0;
}
