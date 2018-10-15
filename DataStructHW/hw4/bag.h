/*
Ryan Lockman: 101430670
CSCI 2421:001 Fall 2013
bag.cpp
Description: Bag class prototypes.

Value Semantics: 	  The copy constructor and assignment operator can be used with the bag class.
Dynamic Memory Usage: Assignment operator, copy constructor, copyBag(private function), and insert
					  use dynamic memory.
Pre/Post Conditions:
// Typedefs
	typedef std::size_t size_type;
		Pre:  none
		Post: Creates a typedef for std::size_t that keeps track of total items
	typedef Node::value_type value_type;
		Pre:  none
		Post: Creates a typedef for Node's value_type to store the data
// Constructors
	Bag(); // Default
		Pre:  none
		Post: Initializes Node head and int used, Bag is empty
// Copy Constructor
	Bag(const Bag &otherBag);
		Pre:  otherBag is of type Bag
		Post: Initializes new Bag with that of otherBag
// Assignment Operator
	Bag& operator=(const Bag &otherBag);
		Pre:  otherBag is of type Bag
		Post: Assigns otherBag(right hand sign) to the left hand signed Bag
// Destructor
	~Bag();
		Pre:  none
		Post: Deallocates the memory used by the Bag
// Modification Member Functions
	void insert(const value_type &entry);
		Pre:  none
		Post: A new entry is inserted into the Bag
	void erase(const value_type &target);
		Pre:  none
		Post: All copies of target are removed from the Bag
// Constant Member Functions
	size_type size() const;
		Pre:  none
		Post: The return is the total number of items in the Bag
	value_type grab() const;
		Pre:  size() > 0
		Post: The return value is a randomly selected item from the Bag
// Other Member Functions
	bool isEmpty();
		Pre:  none
		Post: The return is true or false, depending on weather the bag is empty or not
	void display() const;
		Pre:  none
		Post: Displays the contents within the Bag
*/

#ifndef BAG_H
#define BAG_H

// Headers
#include <cstdlib>
#include "node.h"

class Bag {
public:
	// Typedefs
	typedef std::size_t size_type;
	typedef Node::value_type value_type;

	// Constructors
	Bag() : head(NULL), used(0) {} // Default
	
	// Copy Constructor
	Bag(const Bag &otherBag) { copyBag(otherBag); }
	
	// Assignment Operator
	Bag& operator=(const Bag &otherBag);
	
	// Destructor
	~Bag() { free(); }
	
	// Modification Member Functions
	void insert(const value_type &entry);
	void erase(const value_type &target);
	
	// Constant Member Functions
	size_type  size() const { return used; }
	value_type grab() const;
	
	// Other Member Functions
	bool isEmpty() { return head == NULL; }
	void display() const;

private:
	// Data Members
	Node *head;
	size_type used;
	
	// Private Member Functions
	void free();
	void copyBag(const Bag &otherBag);
};

#endif
