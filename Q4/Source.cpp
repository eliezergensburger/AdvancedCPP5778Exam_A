#include <iostream>
using namespace std;
class A {
public:
	void f() { cout << "at A" << endl; }
};

class B : public A {
public:
	void f() { cout << "at B" << endl; }
};

void g(A &a) { a.f(); }

int main() {
	B b;
	g(b);
	//system("pause");
	return 0;
}
