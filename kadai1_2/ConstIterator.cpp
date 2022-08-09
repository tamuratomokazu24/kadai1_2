#include "DoublyLinkedList.h"
#include <cassert>


DoublyLinkedList::ConstIterator& DoublyLinkedList::ConstIterator::operator--() {
	assert(this->_it->preNode);					//�擪�_�~�[���f�N�������g���悤�Ƃ����ꍇ
	assert(this->_it != this->_it->preNode);	//��̃��X�g�̖����_�~�[���f�N�������g���悤�Ƃ����ꍇ
	this->_it = this->_it->preNode;
	return *this;
}


DoublyLinkedList::ConstIterator DoublyLinkedList::ConstIterator::operator--(int) {
	ConstIterator tmp = *this;
	--* this;
	return tmp;
}


DoublyLinkedList::ConstIterator& DoublyLinkedList::ConstIterator::operator++() {
	assert(this->_it != this->_it->nextNode);	//��̃��X�g�̐擪�_�~�[���C���N�������g���悤�Ƃ����ꍇ
	assert(this->_it->nextNode);				//�����_�~�[���C���N�������g���悤�Ƃ����ꍇ
	this->_it = this->_it->nextNode;
	return *this;
}


DoublyLinkedList::ConstIterator DoublyLinkedList::ConstIterator::operator++(int) {
	ConstIterator tmp = *this;
	++* this;
	return tmp;
}


const ScoreData& DoublyLinkedList::ConstIterator::operator*() const {
	assert(this->_it);				//���X�g�ւ̎Q�Ƃ������Ȃ��R���X�g�C�e���[�^�̗v�f���Q�Ƃ��悤�Ƃ����ꍇ
	assert(this->_it->preNode);		//�擪�_�~�[�̗v�f���Q�Ƃ��悤�Ƃ����ꍇ
	assert(this->_it->nextNode);	//�����_�~�[�̗v�f���Q�Ƃ��悤�Ƃ����ꍇ
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