#include "MCV.h"
#include <iostream>

using namespace std;

int main()
{
	mcv <char> a;
	a.set('*');
	cout << a.get();
	return 0;
}
