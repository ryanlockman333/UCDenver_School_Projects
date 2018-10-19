/* 
 * Ryan
 * set.h Class Prototypes
*/

#ifndef SET_H
#define SET_H

// Headers
#include <cstdlib>
#include "binNode.h"

template<class Type> class Set {
public:
	// Typedefs
	typedef std::size_t size_type;

	// Constructors
	Set() : root(NULL), used(0) {} // default
	Set(const Set &rhs); // copy
	
	// Assignment Operator
	void operator=(const Set &rhs);
	
	// Destructor
	~Set() { free(); }
	
	// Modification Member Functions
	void insert(const Type &entry);
	void remove(const Type &target);
	
	// Constant Member Functions
	size_type size() const { return used; }
	bool contains(const Type &target) const;
	Type grab(const Type &target) const;
	
	// Other Member Functions
	bool isEmpty() const { return root == NULL; }
	void display() const;
	
private:
	// Data Members
	BinNode<Type> *root;
	size_type used;
	
	// Helper Functions
	void free();
	void copySet(const Set &rhs);
};

/*// Non-Member Functions
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
*/

#include "set.tem"
#endif

