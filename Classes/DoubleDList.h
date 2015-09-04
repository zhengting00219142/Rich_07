#pragma once

/*
 * DoubleDList.h
 *
 *  Created on: 2015年9月3日
 *      Author: m1820
 */

#ifndef DOUBLEDLIST_H_
#define DOUBLEDLIST_H_

#include <iostream>
using namespace std;
#include <assert.h>

template <typename T>
class DoubleDList {
    
public:

	DoubleDList() {
		currentSize = 0;
		head = NULL;
	}

	template <class A>
	/**
	* the node
	*/
	class Node {
	public:
		A& value;
		Node * prevNode;
		Node * nextNode;
		Node(A& a) : value(a), prevNode(NULL), nextNode(NULL) {}
	};

	/**
	* the iterator
	*/
	template <typename B>
	class DDListIte {

	public:

		/**
		* Function: constructor : DDListIte(node)
		* Description: create a iterator from the current node;
		* Return:
		*/
		DDListIte(Node<B>* pNode) : currentNode(pNode), temp(pNode) {

		}

		~DDListIte() {

		}

		/**
		* Function: moveBack
		* Description: move back one step;
		* Return:
		*/
		void moveBack() {
			currentNode = currentNode->prevNode;
		}

		/**
		* Function: moveFront
		* Description: move up one step
		* Return:
		*/
		void moveFront() {
			currentNode = currentNode->nextNode;
		}

		/**
		* Function: getCurrent
		* Description: return the current value
		* Return:
			current value
		*/
		B& getCurrent() {
			return currentNode->value;
		}

		/**
		* Function: hasNextForUp
		* Description: when we always move front then this method will check whether we have move back from the beginning
		* point for one circle.
		* Return:
			true
			false
		*/
		bool hasNextForUp() {
			return currentNode->nextNode != temp;
		}

		/**
		* Function: hasNextForBack
		* Description: when we always move back then this method will check whether we have move up from beginning point
		* for one circle.
		* Return:
			true
			false
		*/
		bool hasNextForBack() {
			return currentNode->prevNode != temp;
		}

	private:

		Node<B>* currentNode;

		Node<B>* temp;

	};

	/**
	* Function: insertBefore
	* Description: insert a element into the specific position(from 0) and the pos must be realiable(pos >= 0 && pos < currentSize)
		or the program will terminal.
	* Return:
	* 		true  --- insert success
	* 		false --- insert defeat
	*/
	bool insertBefore(int pos, const T& t){
		if (currentSize == 0 && pos == 0) { // while it's empty
			PNode n = new Node<T>((T&) t);
			n->nextNode = n;
			n->prevNode = n;
			head = n;
			currentSize++;
			return true;
		}
		if (pos == 0)
			return pushFromHead(t);
		assert(pos < currentSize && pos > 0);
		PNode temp = head;
		int i = 0;
		while (i < pos) {
			temp = temp->nextNode;
			i++;
		}
		PNode node = new Node<T>((T&) t);
		temp->prevNode->nextNode = node;
		node->nextNode = temp;
		node->prevNode = temp->prevNode;
		temp->prevNode = node;
		currentSize++;
		return true;
	}


	/**
	* Function: insertAfter
	* Description: insert a element behind the specific position(from 0)
	* Return:
	* 		true  --- insert success
	* 		false --- insert defeat
	*/
	bool insertAfter(int pos, const T& t) {
		assert(pos < currentSize && pos >= 0);
		if (pos == currentSize - 1) {
			return pushFromTail(t);
		}
		return insertBefore(pos + 1, t);
	}

	/**
	* Function: getAt
	* Description: get the element at pos
	* Return: the element at pos , NULL if the pos is not reliable.
	*/
	T& getAt(int pos) {
		PNode n = this->getNode(pos);
		assert(n != NULL);
		return (T&) n->value;
	}

	/**
	* Function: getTop
	* Description: get the head element
	* Return: return the head element or NULL
	*/
	T& getHead() {
		return this->getAt(0);
	}

	/**
	* Function: getTail
	* Description: get the tail element
	* Return: return the tail element or NULL
	*/
	T& getTail() {
		return this->getAt(currentSize - 1);
	}

	/**
	* Function: setAt
	* Description: change the element at pos
	* Return:
	* 		true  -- set success
	* 		fasle -- set defeat
	*/

	bool setAt(int pos, const T& t) {
		PNode node = this->getNode(pos);
		assert(node != NULL);
		node->value = t;
		return true;
	}

	/**
	* Function: popFromHead
	* Description: get a element from Head and remove it from the list
	* Return: return the head element
	*/
	T& popFromHead() {
		PNode node = head;
		assert(node != NULL);
		if (currentSize == 1) {
			T& t = (T&) node->value;
			head = NULL;
			delete node;
			currentSize--;
			return t;
		}
		T& t = (T&) node->value;
		head = node->nextNode;
		node->prevNode->nextNode = node->nextNode;
		node->nextNode->prevNode = node->prevNode;
		delete node;
		currentSize--;
		return t;
	}

	/**
	* Function: popFromTail
	* Description: pop a element from Tail and remove it
	* Return: the removed tail or NULL if the list is empty
	*/
	T& popFromTail() {
		return this->removeAt(currentSize - 1);
	}

	/**
	* Function: pushFromHead
	* Description: push a element to head
	* Return:
	* 		true  -- insert success
	* 		false -- insert defeat
	*/
	bool pushFromHead(const T& t) {
		PNode node = new Node<T>((T&) t);
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

	/**
	* Function: pushFromTail
	* Description: insert a element into the tail
	* Return:
	* 		true  --- insert success
	* 		false --- insert defeat
	*/
	bool pushFromTail(const T& t) {
		PNode node = this->getNode(currentSize - 1);
		PNode n = new Node<T>((T&)t);
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

	/**
	* Function: isEmpty
	* Description: whether the list is empty
	* Return:
	* 		true  --- empty
	* 		false --- not empty
	*/
	bool isEmpty() {
		return currentSize == 0;
	}


	/**
	* Function: getSize
	* Description: get the list's size
	* Return: the size of the list
	*/
	int getSize() {
		return currentSize;
	}


	/**
	* Function: removeAll
	* Description: remove all elements
	* Return:
	*/
	void removeAll() {
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

	/**
	* Function: removeAt
	* Description: remove a element at the specific position(from 0)
	* Return: the removed element or NULL if the pos is not reliable
	*/
	T& removeAt(int pos) {
		assert(pos >= 0 && pos < currentSize);
		if (currentSize == 1) {
			T& t = (T&) head->value;
			delete head;
			head = NULL;
			currentSize--;
			return t;
		}
		int i = 0;
		PNode temp = head;
		while (i < pos) {
			temp = temp->nextNode;
			i++;
		}
		if (pos == 0)
			head = temp->nextNode;
		T& t = (T&) temp->value;
		temp->prevNode->nextNode = temp->nextNode;
		temp->nextNode->prevNode = temp->prevNode;
		delete temp;
		currentSize--;
		return t;
	}

	/**
	* Function: iteratorForNode
	* Description: return a iterator for visit the list. when visit the list , you cannot add or remove element
		or you must call iteratorForNode to create a new iterator.
	* Return:
	*/
	DDListIte<T> iteratorForNode(int pos) {
		assert(pos >= 0 || pos < currentSize);
		DDListIte<T> a(this->getNode(pos));
		return a;
	}

	/**
	* Function: headIte
	* Description: return a iterator from head to visit. when visit the list , you cannot add or remove element
	or you must call iteratorForNode to create a new iterator.
	* Return:
	*/
	DDListIte<T> headIte() {
		assert(currentSize > 0);
		DDListIte<T> a(head);
		return a;
	}

	/**
	* Function: tailIte
	* Description: return a tail iterator from tail to visit. when visit the list , you cannot add or remove element
	or you must call iteratorForNode to create a new iterator.
	* Return:
	*/
	DDListIte<T> tailIte() {
		assert(currentSize > 0);
		return iteratorForNode(currentSize - 1);
	}

	/**
	* Function: ~DoubleDList
	* Description: virtual method
	* Return:
	*/
	virtual ~DoubleDList() {
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

	/**
	* Function: printList just for test.
	* Description: print list like [ele1 , ele2 , ele3 , ... elen , ] , [elen , elen-1 , ... , ele3 , ele2 , ele1]
	* Return:
	*/
	void printList() {
		PNode n = this->head;
		cout << "[";
		if (this->isEmpty()) {
			cout << ", ] , [ , ]" << endl;
			return;
		}
		else {
			cout << n->value << " , ";
			while (n->nextNode != head) {
				n = n->nextNode;
				cout << n->value << " , ";
			}
			cout << "] , [";
			PNode tail = n;
			do {
				cout << n->value << " , ";
				n = n->prevNode;
			} while (n != tail);
			cout << "]" << endl;
		}
	}

private:
    
    typedef Node<T>* PNode;
    
    int currentSize; // the number of the elements in the list
    PNode head;      // the head element
    
				/**
                 * Function: getNode
                 * Description: the private method for getNode at spec pos
                 * Return:
                 * 	PNode at the pos or NULL if the pos is not reliable
                 */
    PNode getNode(int pos) {
        PNode temp = head;
        if (pos < 0 || pos >= currentSize) {
            return NULL;
        }
        int i = 0;
        while (i < pos) {
            temp = temp->nextNode;
            i++;
        }
        return temp;
    }
    
    
};

#endif /* DOUBLEDLIST_H_ */
