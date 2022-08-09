#include "DoublyLinkedList.h"
#include <cassert>


DoublyLinkedList::ConstIterator& DoublyLinkedList::ConstIterator::operator--() {
	assert(this->_it->preNode);					//先頭ダミーをデクリメントしようとした場合
	assert(this->_it != this->_it->preNode);	//空のリストの末尾ダミーをデクリメントしようとした場合
	this->_it = this->_it->preNode;
	return *this;
}


DoublyLinkedList::ConstIterator DoublyLinkedList::ConstIterator::operator--(int) {
	ConstIterator tmp = *this;
	--* this;
	return tmp;
}


DoublyLinkedList::ConstIterator& DoublyLinkedList::ConstIterator::operator++() {
	assert(this->_it != this->_it->nextNode);	//空のリストの先頭ダミーをインクリメントしようとした場合
	assert(this->_it->nextNode);				//末尾ダミーをインクリメントしようとした場合
	this->_it = this->_it->nextNode;
	return *this;
}


DoublyLinkedList::ConstIterator DoublyLinkedList::ConstIterator::operator++(int) {
	ConstIterator tmp = *this;
	++* this;
	return tmp;
}


const ScoreData& DoublyLinkedList::ConstIterator::operator*() const {
	assert(this->_it);				//リストへの参照を持たないコンストイテレータの要素を参照しようとした場合
	assert(this->_it->preNode);		//先頭ダミーの要素を参照しようとした場合
	assert(this->_it->nextNode);	//末尾ダミーの要素を参照しようとした場合
	return this->_it->scoreData;
}


DoublyLinkedList::ConstIterator& DoublyLinkedList::ConstIterator::operator=(const ConstIterator& rhs) {
	this->referenceToList = rhs.referenceToList;
	this->_it = rhs._it;
	return *this;
}


bool DoublyLinkedList::ConstIterator::operator==(const ConstIterator& rhs) const {
	return this->_it == rhs._it;
}


bool DoublyLinkedList::ConstIterator::operator!=(const ConstIterator& rhs) const {
	return this->_it != rhs._it;
}