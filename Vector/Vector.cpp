#include <iostream>
#include "CustomVectorLib.h"

using std::cout;
using std::endl;

int main()
{
	CustomVector<int> v1(3, 100);

	cout << v1.begin() << endl;
	cout << v1._element;
}
