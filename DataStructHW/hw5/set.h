/*
Ryan Lockman: 101430670
CSCI 2421:001 Fall 2013
set.cpp
Description: Set template class prototypes.

Value Semantics: 	  The copy constructor and assignment operator can be used with the Set class.
Dynamic Memory Usage: Assignment operator, copy constructor, copySet(private function), and insert
					  use dynamic memory.
					  
Set Pre/Post Conditions:
// Typedefs
	typedef std::size_t size_type;
		Post: Creates a typedef for std::size_t that keeps track of total items
	typedef node_iterator<Type> iterator;
		Post: Create a typedef for a noda_iterator that steps through the data
	typedef const_node_iterator<Type> const_iterator;
		Post: Create a typedef for a const_nod_iterator that steps through the data	
// Constructors
	Set(); // Default
		Post: Initializes Node head and int used, Set is empty
// Copy Constructor
	Set(const Set &otherSet);
		Post: Initializes new Set with that of otherSet
// Assignment Operator
	Set& operator=(const Set &otherSet);
		Pre:  right hand sign is of Set
		Post: Assigns otherSet(rhs) to the left hand signed Set
// Destructor
	~Set();
		Post: Deallocates the memory used by Set
// Modification Member Functions
	void insert(const value_type &entry);
		Post: A new entry is inserted into the Set
	void erase(const value_type &target);
		Post: All copies of target are removed from the Set
// Constant Member Functions
	size_type size() const;
		Post: The return is the total number of items in the Set
	bool contains(const Type &target) const;
		Post: Returns true if the Set contains the target item, false otherwise
	value_type grab() const;
		Pre:  size() > 0
		Post: The return value is a randomly selected item from the Set
// Other Member Functions
	bool isEmpty();
		Post: The return is true or false, depending on weather the Set is empty or not
// Iterator Functions
	iterator begin()
		Post: Returns a pointer to the first Node of Set's data list
	iterator end()
		Post: Returns a pointer to the last Node of a Set's data list, which is NULL
	const_iterator begin() const;
		Post: Returns a constant pointer to the first Node of Set's data list
	const_iterator end() const;
		Post: Returns a pointer to the last Node of a Set's data list, which is NULL

Non-Member Pre/Post Conditions		
// Overloaded Operators
	template<class set_type>
	set_type operator+(const set_type &s1, const set_type &s2); // Union
		Post: Returned Set is the union of s1 and s2
	template<class set_type>
	set_type operator&(const set_type &s1, const set_type &s2); // Intersection
		Post: Returned Set is the intersection of s1 and s2
	template<class set_type>
	set_type operator-(const set_type &s1, const set_type &s2); // Difference
		Post: Returned Set is the difference of s1 and s2
	template<class set_type>
	bool operator==(const set_type &s1, const set_type &s2) const;
		Post: Returns true if Sets are equal, false otherwise
	template<class set_type>
	bool operator!=(const set_type &s1, const set_type &s2) const;
		Post: Returns true if Sets are not equal. false otherwise
*/

#ifndef SET_H
#define SET_H

// Headers
#include <cstdlib>
#include "nodeTem.h"

template<class Type> class Set {
public:
	// Typedefs
	typedef std::size_t size_type;
	typedef node_iterator<Type> iterator;
	typedef const_node_iterator<Type> const_iterator;

	// Constructors
	Set() : head(NULL), used(0) {} // Default
	
	// Copy Constructor
	Set(const Set &otherSet);
	
	// Assignment Operator
	void operator=(const Set &otherSet);
	
	// Destructor
	~Set() { free(); }
	
	// Modification Member Functions
	void insert(const Type &entry);
	void erase(const Type &target);
	
	// Constant Member Functions
	size_type size() const { return used; }
	bool contains(const Type &target) const;
	Type grab() const;
	
	// Other Member Functions
	bool isEmpty() const { return head == NULL; }
	
	// Friend Overloads
	template<typename U>
	friend std::ostream& operator<<(std::ostream &os, const Set<U> &rhs);

	// Iterator Functions
	iterator begin() { return iterator(head); }
	iterator end()   { return iterator(); }
	const_iterator begin() const { return const_iterator(head); }
	const_iterator end()   const { return const_iterator(); }
	
private:
	// Data Members
	Node<Type> *head;
	size_type used;
	
	// Private Member Functions
	void free();
	void copySet(const Set &otherSet);
};

// Non-Member Functions
template<class set_type> // Helper
void displayHelper(std::ostream &os, set_type &rhs);

template<class set_type>
void setUnion(const set_type &s1, const set_type &s2, set_type &result);

template<class set_type>
void setIntersection(const set_type &s1, const set_type &s2, set_type &result);

template<class set_type>
void setDifference(const set_type &s1, const set_type &s2, set_type &result);

template <class set_type>
void setSymmetricDiff(const set_type &s1, const set_type &s2, set_type &result);

// Overloaded Operators
template<class set_type>
set_type operator+(const set_type &s1, const set_type &s2); // Union

template<class set_type>
set_type operator&(const set_type &s1, const set_type &s2); // Intersection

template<class set_type>
set_type operator-(const set_type &s1, const set_type &s2); // Difference

template<class set_type>
bool operator==(const set_type &s1, const set_type &s2);

template<class set_type>
bool operator!=(const set_type &s1, const set_type &s2) { return !operator==(s1, s2); }

#include "set.tem"
#endif
