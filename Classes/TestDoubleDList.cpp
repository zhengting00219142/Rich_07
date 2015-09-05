#include "DoubleDList.h"
#include <iostream>
using namespace std;

class Student {
public:
	int age;
	Student(int age) : age(age) {}
	Student() : age(0) {}
	~Student() {
		cout << "destroy student" << endl;
	}
};

void printList(DoubleDList<Student*>& list) {
	cout << "[";
	DoubleDList<Student*>::DDListIte<Student*> listIte = list.headIte();
	while (listIte.hasNextForUp()) {
		cout << listIte.getCurrent()->age << " , ";
		listIte.moveFront();
	}
	if(listIte.hasCurrent()) // when the list is empty , we must check the iterator is not empty
		cout << listIte.getCurrent()->age << " , ";
	cout << "]";
	listIte = list.tailIte();
	cout << "[";
	while (listIte.hasNextForBack()) {
		cout << listIte.getCurrent()->age << " , ";
		listIte.moveBack();
	}
	if (listIte.hasCurrent()) // when the list is empty , we must check the iterator is not empty
		cout << listIte.getCurrent()->age << " , ";
	cout << "]" << endl;
}

int main() {
	DoubleDList<Student*> list;
	Student* student = new Student(2) ;
	cout << "size:" << list.getSize() << endl;
	int b = 2;
	printList(list);
	cout << "empty : " << list.isEmpty() << endl;
	list.insertBefore(0,  student);
	cout << "empty : " << list.isEmpty() << endl;
	printList(list);

	student = new Student(4);
	list.insertBefore(0, student);
	printList(list);

	student = new Student(5);
	list.insertBefore(0, student);
	printList(list);

	student = new Student(3);
	list.insertBefore(1, student);

	cout << "head : " << list.getHead()->age << endl;
	cout << "tail : " << list.getTail()->age << endl;
	printList(list);

	student = new Student(1);
	list.insertAfter(0, student);
	printList(list);

	student = new Student(6);
	list.insertAfter(4, student);
	printList(list);

	cout << "size : " << list.getSize() << endl;
	cout << " 2 : " << list.getAt(2)->age << endl;
	cout << "empty : " << list.isEmpty() << endl;

	student = new Student(10);
	list.setAt(0, student);
	printList(list);

	student = new Student(9);
	list.setAt(1, student);
	printList(list);

	cout << "0 : " << list.removeAt(0)->age << endl;
	printList(list);

	student = new Student(15);
	list.pushFromHead(student);
	student = new Student(16);
	list.pushFromHead(student);
	printList(list);

	student = new Student(20);
	list.pushFromTail(student);
	student = new Student(21);
	list.pushFromTail(student);
	printList(list);


	cout << "head : " << list.popFromHead()->age << endl;
	printList(list);
	cout << "tail : " << list.popFromTail()->age << endl;
	printList(list);

	// ÈçºÎ±éÀú¡£
	cout << "ite : [";
	DoubleDList<Student*>::DDListIte<Student*> hIte = list.iteratorForNode(1);  // if call list.headIte then we can call moveBack or moveFront to visit from head to tail
	          // if we call list.tailIte , we can call moveBack or moveFront to visit from tail to head.
	while (hIte.hasNextForBack()) {
		cout << hIte.getCurrent()->age << " , ";
		hIte.moveBack();
	}
	if(hIte.hasCurrent())
		cout << hIte.getCurrent()->age << " , ";
	cout << "]" << endl;


	list.removeAll();
	printList(list);


	// test the reference

	DoubleDList<Student*> sList;
	Student* sP;
	int i = 0;
	while (i < 10) {
		sP = new Student(i);
		sList.pushFromHead(sP);
		i++;
	}

	cout << "[";
	DoubleDList<Student*>::DDListIte<Student*> ite = sList.headIte();
	while (ite.hasNextForUp()) {
		cout << ite.getCurrent()->age << " , ";
		ite.moveFront();
	}
	if (ite.hasCurrent()) // just for empyt iterator.
		cout << ite.getCurrent()->age << endl;
	cout << "]" << endl;

	int a = 0;
	cin >> a;
	return 0;
}

