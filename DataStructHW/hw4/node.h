/*
Ryan Lockman: 101430670
CSCI 2421:001 Fall 2013
node.h
Description: Node class prototypes.

Pre/Post Conditions:
// Typedefs
	typedef std::string value_type;
		Pre:  none
		Post: Creates a typedef for std::string to store the data
// Constructors
	Node(); // Default
		Pre:  none
		Post: Initializes the data and the Node link, Node is empty
	Node(const value_type dataIn, Node *linkIn);
		Pre:  dataIn and linkIn are the right type
		Post: Initializes the data with value_type and the link with linkIn, Node is not empty
// Get Member Functions
	Node* getLink() const;
		Pre:  none
		Post: Returns the link of the Node
	value_type getData() const;
		Pre:  none
		Post: Returns the data of the Node
// Set Member Functions
	void setLink(Node *linkIn);
		Pre:  linkIn is of type *Node
		Post: Sets the link with linkIn
	void setData(value_type dataIn);
		Pre:  dataIn is the right type
		Post: Sets data with that of dataIn
		
// Linked-List Toolkit Functions
	size_t listLength(const Node *headIn);
		Pre:  headIn is the head pointer of a linked list
		Post: Value returned is the number of nodes in the linked list
	void listHeadInsert(Node *&headIn, const Node::value_type &entry);
		Pre:  headIn is the head pointer of a linked list
		Post: A new node containing the entry is inserted at the head of the linked list;
			  headIn now points the head of the new, longer linked list
	void listInsert(Node *previous, const Node::value_type &entry);
		Pre:  previous points to a node in the linked list
		Post: A new node containing the entry is inserted after the node that previous points to
	Node* listSearch(Node *headIn, const Node::value_type &target);
		Pre:  headIn is the head pointer of a linked list
		Post: The pointer returned points to the first node containing the target in its data field;
			  if their is no such node, a null pointer is returned
	const Node* listLocate(const Node *headIn, const size_t pos);
		Pre:  headIn is the head pointer of a linked list and position > 0
		Post: The pointer returned points to the node at the specified position in the linked list;
		      if their is no such position then a null pointer is returned
	void listHeadRemove(Node *&head);
		Pre:  headIn is the head pointer of a linked list with at least one node
		Post: The head node is removed from the linked list and headIn is the new head
			  of the new, shorter linked list
	void listRemove(Node *previous);
		Pre:  previous points to a node in the linked list, and this is not the tail end of the linked list
		Post: The node after previous is removed from the linked list
	void listClear(Node *&headIn);
		Pre:  headIn is the head pointer of a linked list
		Post: All nodes have been returned to the heap and headIn is now null
	void listCopy(const Node *source, Node *&headIn, Node *&tail);
		Pre:  source is the head pointer of a linked list
		Post: headIn and tailIn are the head and tail pointers for a new linked list that contains
		      the same items as the linked list pointed to be source
*/

#ifndef NODE_H
#define NODE_H

// Headers
#include <cstdlib>
#include <string>

class Node {
public:
	// Typedefs
	typedef std::string value_type;
	
	// Constructors
	Node() : link(NULL) { } // Default
	Node(const value_type dataIn, Node *linkIn) : data(dataIn), link(linkIn) {}
	
	// Get Member Functions
	Node* getLink()      const { return link; }
	value_type getData() const { return data; }
	
	// Set Member Functions
	void setLink(Node *linkIn)      { link = linkIn; }
	void setData(value_type dataIn) { data = dataIn; }

private:
	// Data Members
	value_type data;
	Node *link;
};

// Linked-List Toolkit Functions
size_t listLength(const Node *headIn);
void listHeadInsert(Node *&headIn, const Node::value_type &entry);
void listInsert(Node *previous, const Node::value_type &entry);
Node* listSearch(Node *headIn, const Node::value_type &target);
const Node* listLocate(const Node *headIn, const size_t pos);
void listHeadRemove(Node *&head);
void listRemove(Node *previous);
void listClear(Node *&headIn);
void listCopy(const Node *source, Node *&headIn, Node *&tail);

#endif
