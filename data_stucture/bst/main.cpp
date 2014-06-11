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

	int number;
	for(;;)
	{
		cout << "input the number: ";
		cin >> number;
		if(number < 0)
			break;
		intBST.insert(number);
	}

	intBST.graph(cout);

	intBST.search(9);
	intBST.search(100);

	intBST.inorder(cout);

   /* intBST.remove(100);*/
	//intBST.remove(12);
	//intBST.graph(cout);
	//intBST.remove(3);
	/*intBST.graph(cout);*/

	intBST.remove(6);
	intBST.graph(cout);


	return 0;
}
