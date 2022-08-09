#include "DoublyLinkedList.h"
#include <cassert>


DoublyLinkedList::Iterator& DoublyLinkedList::Iterator::operator--() {
	assert(this->_it->preNode);					//先頭ダミーをデクリメントしようとした場合
	assert(this->_it != this->_it->preNode);	//空のリストの末尾ダミーをデクリメントしようとした場合
	this->_it = this->_it->preNode;
	return *this;
}


DoublyLinkedList::Iterator DoublyLinkedList::Iterator::operator--(int) {
	Iterator tmp = *this;
	--* this;
	return tmp;
}


DoublyLinkedList::Iterator& DoublyLinkedList::Iterator::operator++() {
	assert(this->_it != this->_it->nextNode);	//空のリストの先頭ダミーをインクリメントしようとした場合
	assert(this->_it->nextNode);				//末尾ダミーをインクリメントしようとした場合
	this->_it = this->_it->nextNode;
	return *this;
}


DoublyLinkedList::Iterator DoublyLinkedList::Iterator::operator++(int) {
	Iterator tmp = *this;
	++* this;
	return tmp;
}


ScoreData& DoublyLinkedList::Iterator::operator*() {
	assert(this->_it);				//リストへの参照を持たないイテレータの要素を参照しようとした場合
	assert(this->_it->preNode);		//先頭ダミーの要素を参照しようとした場合
	assert(this->_it->nextNode);	//末尾ダミーの要素を参照しようとした場合
	return this->_it->scoreData;
}


DoublyLinkedList::Iterator& DoublyLinkedList::Iterator::operator=(Iterator& rhs) {
	this->referenceToList = rhs.referenceToList;
	this->_it = rhs._it;
	return *this;
}


bool DoublyLinkedList::Iterator::operator==(const Iterator& rhs) const {
	return this->_it == rhs._it;
}


bool DoublyLinkedList::Iterator::operator!=(const Iterator& rhs) const {
	return this->_it != rhs._it;
}
