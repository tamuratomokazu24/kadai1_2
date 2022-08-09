#include "DoublyLinkedList.h"
#include <cassert>


DoublyLinkedList::Iterator& DoublyLinkedList::Iterator::operator--() {
	assert(this->_it->preNode);					//�擪�_�~�[���f�N�������g���悤�Ƃ����ꍇ
	assert(this->_it != this->_it->preNode);	//��̃��X�g�̖����_�~�[���f�N�������g���悤�Ƃ����ꍇ
	this->_it = this->_it->preNode;
	return *this;
}


DoublyLinkedList::Iterator DoublyLinkedList::Iterator::operator--(int) {
	Iterator tmp = *this;
	--* this;
	return tmp;
}


DoublyLinkedList::Iterator& DoublyLinkedList::Iterator::operator++() {
	assert(this->_it != this->_it->nextNode);	//��̃��X�g�̐擪�_�~�[���C���N�������g���悤�Ƃ����ꍇ
	assert(this->_it->nextNode);				//�����_�~�[���C���N�������g���悤�Ƃ����ꍇ
	this->_it = this->_it->nextNode;
	return *this;
}


DoublyLinkedList::Iterator DoublyLinkedList::Iterator::operator++(int) {
	Iterator tmp = *this;
	++* this;
	return tmp;
}


ScoreData& DoublyLinkedList::Iterator::operator*() {
	assert(this->_it);				//���X�g�ւ̎Q�Ƃ������Ȃ��C�e���[�^�̗v�f���Q�Ƃ��悤�Ƃ����ꍇ
	assert(this->_it->preNode);		//�擪�_�~�[�̗v�f���Q�Ƃ��悤�Ƃ����ꍇ
	assert(this->_it->nextNode);	//�����_�~�[�̗v�f���Q�Ƃ��悤�Ƃ����ꍇ
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
