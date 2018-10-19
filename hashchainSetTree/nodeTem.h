/*
 * node.h Node, Iterators, and Linked List Tool-Kit class prototypes.
*/

#ifndef NODETEM_H
#define NODETEM_H

// Headers
#include <cstdlib>
#include <string>

template<class Type> class Node {
public:
	// Typedefs
	typedef Type value_type;
	
	// Constructors
	Node(const Type &dataIn = Type(), Node<Type> *linkIn = NULL) : data(dataIn), link(linkIn) {}
	
	// Get Member Functions
	Node<Type>* getLink() { return link; }
	Type& getData() { return data; }
	
	// Const Member Functions
	const Node<Type>* getLink() const { return link; }
	const Type&	getData() const { return data; }
	
	// Set Member Functions
	void setLink(Node<Type> *linkIn) { link = linkIn; }
	void setData(const Type &dataIn) { data = dataIn; }

private:
	// Data Members
	Type data;
	Node<Type> *link;
};

// node_iterator Class Prototypes
template<class Type>
class node_iterator : public std::iterator<std::forward_iterator_tag, Type> {
public:
	// Constructors
	node_iterator(Node<Type> *initial = NULL) : current(initial) {}
	
	// Overloaded Operators
	Type operator*() const { return current->getData(); }
	
    // ++Prefix
	node_iterator& operator++() { *this = current->getLink(); return *this; }
	// Postfix++
	const node_iterator operator++(int) { node_iterator oldValue = *this;
								          ++(*this); return oldValue; }
								  
	bool operator==(const node_iterator &rhs) const { return current == rhs.current; }
	bool operator!=(const node_iterator &rhs) const { return !(current == rhs.current); }
	
private:
	Node<Type> *current;
};

// const_node_iterator Class Prototypes
template<class Type>
class const_node_iterator : public std::iterator<std::forward_iterator_tag, const Type> {
public:
	// Constructors
	const_node_iterator(const Node<Type> *initial = NULL) : current(initial) {}
	
	// Overloaded Operators
	const Type operator*() const { return current->getData(); }
	
	// ++Prefix
	const_node_iterator& operator++() { *this = current->getLink(); return *this; }
	// Postfix++
	const const_node_iterator operator++(int) { const const_node_iterator oldValue = *this;
										        ++(*this); return oldValue; }
										  
	bool operator==(const const_node_iterator &rhs) const { return current == rhs.current; }
	bool operator!=(const const_node_iterator &rhs) const { return !(current == rhs.current); }
	
private:
	const Node<Type> *current;
};

// Linked-List Toolkit Function Prototypes
template<class Type>
size_t listLength(const Node<Type> *headIn);

template<class Type>
void listHeadInsert(Node<Type> *&headIn, const Type &entry);

template<class Type>
void listInsert(Node<Type> *previous, const Type &entry);

template<class NodePtr, class Type>
NodePtr listSearch(NodePtr headIn, const Type &target);

template<class NodePtr, class SizeType>
NodePtr listLocate(NodePtr headIn, SizeType pos);

template<class Type>
void listHeadRemove(Node<Type> *&head);

template<class Type>
void listRemove(Node<Type> *previous);

template<class Type>
bool is_empty(const Node<Type> *headIn);

template<class Type>
void listClear(Node<Type> *&headIn);

template<class Type>
void listCopy(const Node<Type> *source, Node<Type> *&headIn, Node<Type> *&tail);

#include "nodeTem.tem"
#endif

