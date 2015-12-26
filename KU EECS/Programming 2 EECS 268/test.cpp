#include <iostream>

int getValue(int a, int b, int n)
{
	int returnValue = 0;
	std::cout << "Enter: a = " << a << " b = " << b <<'\n';
	int c = (a+b)/2;
	if(c*c<=n)
		returnValue = c;
	else
		returnValue = getValue(a, c-1, n);
	std::cout <<" Leave: a " <<a <<" b = " << b <<'\n';
	returnValue;
}
int main()
{
	std::cout << "RESULT: " << getValue(1,7, 7) <<'\n';
	std::cin.get();
	std::cin.get();
	return 0;
}
