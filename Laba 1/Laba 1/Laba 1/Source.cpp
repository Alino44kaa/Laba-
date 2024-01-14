#include "Header.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    Stack<int> s1{ 1, 2, 3, 4, 6 };

    Stack <int> s2(s1);
    Stack <int> s3;

    s1.see();
    cout << "1 стек" << endl;

    s3 = foo(s2);

    s2.pop();
    s2.pop();
    s2.pop();

    s1.pop();

    s3.see();
    cout << "3 стек" << endl;
    s2.see();
    cout << "2 стек" << endl;
    s1.see();
    cout << "1 стек" << endl;

    cout << s2[1];

    return 0;
}