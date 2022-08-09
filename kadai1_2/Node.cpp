#include "DoublyLinkedList.h"

DoublyLinkedList::Node::Node(Node* preNode, Node* nextNode) {
	this->preNode = preNode;
	this->nextNode = nextNode;
}

DoublyLinkedList::Node::Node(Node* preNode, Node* nextNode, const ScoreData& scoreData) {
	this->preNode = preNode;
	this->nextNode = nextNode;
	this->scoreData = scoreData;
}