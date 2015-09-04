/*
* DoubleDList.cpp

*
*  Created on: 2015Äê9ÔÂ3ÈÕ
*      Author: m1820
*/

#include "DoubleDList.h"
// #include <iostream>
// #include "assert.h"

/*


template <class T>
DoubleDList<T> ::DoubleDList(int initialSize) {
currentSize = 0;
head = NULL;
}

*/

/*
template <class T>
DoubleDList<T> ::DoubleDList() {
	currentSize = 0;
	head = NULL;
}

template <class T>
bool DoubleDList<T> ::insertBefore(int pos, T& t) {
	assert(pos < currentSize && pos > 0);
	if (currentSize == 0 && pos == 0) { // while it's empty
		PNode node = new Node();
		node->nextNode = &node;
		node->prevNode = &node;
		head = &node;
		currentSize++;
		return true;
	}
	if (pos == 0)
		return pushFromHead(t);
	PNode temp = head;
	int i = 0;
	while (i < pos) {
		temp = temp->nextNode;
		i++;
	}
	PNode node = new Node;
	temp->prevNode->nextNode = node;
	node->nextNode = temp;
	node->value = t;
	node->prevNode = temp->prevNode;
	temp->prevNode = node;
	currentSize++;
	return true;
}

template <class T>
bool DoubleDList<T> ::insertAfter(int pos, T& t) {
	assert(pos < currentSize && pos > 0);
	if (pos == currentSize - 1) {
		pushFromTail(t);
	}
	insertBefore(pos + 1, t);
}

template <class T>
T& DoubleDList<T> ::getAt(int pos) {
	PNode n = this->getNode(pos);
	if (n == NULL) {
		return n;
	}
	else {
		return n->value;
	}
}

template <class T>
T& DoubleDList<T> ::getHead() {
	return this->getAt(0);
}

template <class T>
T& DoubleDList<T> ::getTail() {
	return this->getAt(currentSize - 1);
}

template <class T>
bool DoubleDList<T> ::setAt(int pos, T& t) {
	PNode node = this->getNode(pos);
	assert(node != NULL);
	node->value = t;
	return true;
}

template <class T>
T& DoubleDList<T> ::popFromHead() {
	PNode node = head;
	assert(node != NULL);
	if (currentSize == 1) {
		T& t = node->value;
		head = NULL;
		delete node;
		currentSize--;
		return t;
	}
	T& t = node->value;
	head = node->prevNode;
	node->prevNode->nextNode = node->nextNode;
	node->nextNode->prevNode = node->prevNode;
	delete node;
	currentSize--;
	return t;
}

template <class T>
bool DoubleDList<T> ::pushFromHead(T& t) {
	PNode node = new Node;
	node->value = t;
	if (currentSize == 0) {
		node->prevNode = node->nextNode = node;
		head = node;
		currentSize++;
		return true;
	}
	node->prevNode = head->prevNode;
	node->nextNode = head;
	head->prevNode->nextNode = node;
	head->prevNode = node;
	head = node;
	currentSize++;
	return true;
}

template <class T>
bool DoubleDList<T> ::pushFromTail(T& t) {
	PNode node = this->getNode(currentSize - 1);
	PNode n = new Node;
	n->value = t;
	if (node == NULL) {
		n->prevNode = n->nextNode = n;
		head = n;
		currentSize++;
		return true;
	}
	node->nextNode->prevNode = n;
	n->nextNode = node->nextNode;
	node->nextNode = n;
	n->prevNode = node;
	currentSize++;
	return true;
}

template <class T>
T& DoubleDList<T> ::popFromTail(T& t) {
	this->removeAt(currentSize - 1);
}

template <class T>
bool DoubleDList<T> ::isEmpty() {
	return currentSize == 0;
}

template <class T>
int DoubleDList<T> ::getSize() {
	return currentSize;
}

template <class T>
void DoubleDList<T> ::removeAll() {
	this->~DoubleDList();
}

template <class T>
T& DoubleDList<T> ::removeAt(int pos) {
	assert(pos >= 0 && pos < currentSize);
	if (currentSize == 1) {
		T& t = head->value;
		delete head;
		head = NULL;
		currentSize--;
		return t;
	}
	int i = 0;
	PNode temp = head;
	while (i < currentSize) {
		temp = temp->nextNode;
		i++;
	}
	T& t = temp->value;
	temp->prevNode->nextNode = temp->nextNode;
	temp->nextNode->prevNode = temp->prevNode;
	delete temp;
	currentSize--;
	return t;
}


template <class T>
DoubleDList<T>::~DoubleDList() {
	PNode temp = head, t2 = NULL;
	int i = 0;
	while (i < currentSize) {
		t2 = temp;
		temp = temp->nextNode;
		delete t2;
		i++;
	}
	currentSize = 0;
}
*/