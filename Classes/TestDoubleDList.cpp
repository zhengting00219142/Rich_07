/*#include "DoubleDList.h"
#include <iostream>
using namespace std;

class Student {
public:
    int age;
    Student(int age) : age(age) {}
    Student() : age(0) {}
};

template <class T>
void printDDList(DoubleDList<T> & list) {
    cout << "[";
    while (!list.isEmpty()) {
        cout << list.popFromHead() << " , ";
    }
    cout << "]" << endl;
}

int main() {
    DoubleDList<int> list;
    cout << "size:" << list.getSize() << endl;
    int b = 2;
    list.printList();
    cout << "empty : " << list.isEmpty() << endl;
    list.insertBefore(0, 2);
    cout << "empty : " << list.isEmpty() << endl;
    list.printList();
    list.insertBefore(0, 4);
    list.printList();
    list.insertBefore(0, 5);
    list.printList();
    list.insertBefore(1, 3);
    cout << "head : " << list.getHead() << endl;
    cout << "tail : " << list.getTail() << endl;
    list.printList();
    list.insertAfter(0, 1);
    list.printList();
    list.insertAfter(4, 6);
    list.printList();
    cout << "size : " << list.getSize() << endl;
    cout << " 2 : " << list.getAt(2) << endl;
    cout << "empty : " << list.isEmpty() << endl;
    
    list.setAt(0, 10);
    list.printList();
    list.setAt(1, 9);
    list.printList();
    cout << "0 : " << list.removeAt(0) << endl;
    list.printList();
    
    list.pushFromHead(15);
    list.printList();
    list.pushFromTail(20);
    list.printList();
    
    cout << "head : " << list.popFromHead() << endl;
    list.printList();
    cout << "tail : " << list.popFromTail() << endl;
    list.printList();
    
    // 如何遍历。
    cout << "ite : [";
    DoubleDList<int>::DDListIte<int> hIte = list.iteratorForNode(1);
    while (hIte.hasNextForBack()) {
        cout << hIte.getCurrent() << " , ";
        hIte.moveBack();
    }
    cout << hIte.getCurrent() << " , ";
    cout << "]" << endl;
    
    
    list.removeAll();
    list.printList();
    int a = 0;
    cin >> a;
    return 0;
}
*/
