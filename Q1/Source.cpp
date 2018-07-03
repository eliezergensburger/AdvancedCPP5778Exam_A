#include <iostream>
using namespace std;
int main()
{
	int x = -1;
	try {
		cout << "Inside try \n";
		if (x < 0)
		{
			throw ('a' - x);
			cout << "After throw \n";
		}
		cout << "Oops" << endl;
	}
	catch (char c) {
		cout << "Exception char caught " << c << endl;
	}
	catch (int x) {
		cout << "Exception Caught " << x << endl;
	}

	cout << "After catch \n";
	system("pause");
	return 0;
}
