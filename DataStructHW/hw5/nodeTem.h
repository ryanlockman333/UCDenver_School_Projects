/*
Ryan Lockman: 101430670
CSCI 2421:001 Fall 2013
node.h
Description: Node, Iterators, and Linked List Tool-Kit template class prototypes.

Node Pre/Post Conditions:
// Typedefs
	typedef std::string value_type;
		Post: Creates a typedef to store the data
// Constructors
	Node(); // Default
		Post: Initializes the data and the Node link, Node is empty
	Node(const Type dataIn, Node *linkIn);
		Post: Initializes the data with data type and the link with linkIn, Node is not empty
// Get Member Functions
	Node* getLink() const;
		Post: Returns the link of the Node
	value_type getData() const;
		Post: Returns the data of the Node
// Set Member Functions
	void setLink(Node *linkIn);
		Post: Sets the link with linkIn
	void setData(Type dataIn);
		Post: Sets data with that of dataIn
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
	Node(const Type &dataIn = Type(), Node *linkIn = NULL) : data(dataIn), link(linkIn) {}
	
	// Get Member Functions
	Node* getLink() { return link; }
	Type& getData() { return data; }
	
	// Const Member Functions
	const Node* getLink() const { return link; }
	const Type&	getData() const { return data; }
	
	// Set Member Functions
	void setLink(Node *linkIn) { link = linkIn; }
	void setData(const Type &dataIn) { data = dataIn; }

private:
	// Data Members
	Type data;
	Node *link;
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

/* Linked-List Toolkit Pre/Post Conditions:
	size_t listLength(const Node<Type> *headIn);
		Pre:  headIn is the head pointer of a linked list
		Post: Value returned is the number of nodes in the linked list
	void listHeadInsert(Node<Type> *&headIn, const Type &entry);
		Pre:  headIn is the head pointer of a linked list
		Post: A new node containing the entry is inserted at the head of the linked list;
			  headIn now points to the head of the new linked list
	void listInsert(Node<Type> *previous, const Type &entry);
		Pre:  previous points to a node in the linked list
		Post: A new node containing the entry is inserted after the node that previous points to
	NodePtr listSearch(NodePtr headIn, const Type &target);
		Pre:  headIn is the head pointer of a linked list
		Post: Returned pointer points to the first node containing the target in its data field;
			  if no such node, a null pointer is returned
	NodePtr listLocate(NodePtr headIn, SizeType pos);
		Post: Returned pointer points to the node at the specified position in the linked list
		      if no such position then a null pointer is returned
	void listHeadRemove(Node<Type> *&head);
		Pre:  headIn is the head pointer of a linked list with at least one node
		Post: The head node is removed from the linked list and headIn is the new head
			  of the linked list
	void listRemove(Node<Type> *previous);
		Pre:  previous points to a node in the linked list, and this is not the tail end of the linked list
		Post: The node after previous is removed from the linked list
	void listClear(Node<Type> *&headIn);
		Pre:  headIn is the head pointer of a linked list
		Post: All nodes have been returned to the heap and headIn is now null
	void listCopy(const Node<Type> *source, Node<Type> *&headIn, Node<Type> *&tail);
		Pre:  source is the head pointer of a linked list
		Post: headIn and tailIn are the head and tail pointers for a new linked list that contains
		      the same items as the linked list pointed to by source
*/
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
void listClear(Node<Type> *&headIn);

template<class Type>
void listCopy(const Node<Type> *source, Node<Type> *&headIn, Node<Type> *&tail);

#include "nodeTem.tem"
#endif
