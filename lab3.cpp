/*Alexander Howes 
820184866
this driver program will test the operators, it will print bad _ on all the statements which 
should not be true.*/
#include <iostream>
#include "point.cpp"
int main()
{
    Point p1(3.5, 5);
    Point p2(10, 10.5);
    Point p3(3.5, 5);
    if (p2 > p1) {
        cout << "1st" << endl;
    }
    if (p1 < p3) {
        cout << "bad1" << endl;
    }
    if (p1 <= p3) {
        cout << "2nd" << endl;
    }
    if (p1 >= p3) {
        cout << "3rd" << endl;
    }
    if (p1 <= p3) {
        cout << "fourth" << endl;
    }
    if (p1 != p3) {
        cout << "bad3" << endl;
    }
    if (p1 == p3) {
        cout << "fifth" << endl;
    }
    return 0;
}

