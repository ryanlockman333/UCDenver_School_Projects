/*
Ryan Lockman: 101430670
CSCI 2421:001 Fall 2013
bag.cpp
Description: Bag class definitions.
*/

// Headers
#include <iostream>
#include <cassert>
#include <algorithm>
#include "bag.h"
	
// Assignment Operator
Bag& Bag::operator=(const Bag &otherBag) {
	if(this != &otherBag)
		copyBag(otherBag);
	return *this;
}
	
// Modification Member Functions
void Bag::insert(const value_type &entry) {
	listHeadInsert(head, entry);
	++used;
}

void Bag::erase(const value_type &target) {
	Node *targetNode = listSearch(head, target);
	
	while(targetNode != NULL) {
		targetNode->setData(head->getData());
		targetNode = targetNode->getLink();
		targetNode = listSearch(targetNode, target);
		listHeadRemove(head);
		--used;
	}
}

// Constant Member Functions
Bag::value_type Bag::grab() const {
	assert(size() > 0);
	const Node *cursor = NULL;
	
	size_type pos = (rand() % size()) + 1;
	cursor        = listLocate(head, pos);
	
	return cursor->getData();
}

// Other Member Functions
void Bag::display() const {
	Node *cursor = NULL;
	
	std::cout << std::endl;
	for(cursor = head; cursor != NULL; cursor = cursor->getLink())
		std::cout << cursor->getData() << " ";
}
	
// Private Member Functions
void Bag::free() {
	listClear(head);
	head = NULL;
	used = 0;
}

void Bag::copyBag(const Bag &otherBag) {
	Node *tail = NULL;
	
	free();
	listCopy(otherBag.head, head, tail);
	used = otherBag.used;
}
