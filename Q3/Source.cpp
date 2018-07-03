/*1 */ #include <iostream>
/*2 */ #include <cstring>
/*3 */ using namespace std;
/*4 */ class Father
/*5 */ {
/*6 */       const char* name;
/*7 */ public:
/*8 */       Father(const char* _name) : name(_strdup(_name)) {}
/*9 */       virtual ~Father() { cout << "In Father::~Father\n"; delete[] name; }
/*10*/
/*11*/ };

/*12*/ class Son : public Father
/*13*/ {
/*14*/       const char* hobby;
/*15*/ public:
/*16*/        Son(const char* _name, const char* _hobby) : Father(_name), hobby(_strdup(_hobby)) {}
/*17*/       ~Son() { cout << "In Son::~Son\n"; delete[] hobby; }
/*18*/
/*19*/ };

/*20*/ int main()
/*21*/ {
/*21*/  Father* f = new Son("ben", "C++");
/*22*/  delete f;
/*23*/  system("pause");
/*24*/  return 0;
/*25*/ }
