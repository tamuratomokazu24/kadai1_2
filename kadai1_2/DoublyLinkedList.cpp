#include "DoublyLinkedList.h"


DoublyLinkedList::DoublyLinkedList() {

	//�擪�Ɩ����̃_�~�[���쐬
	this->_dummyFirstNode = new Node(nullptr, nullptr);
	this->_dummyLastNode = new Node(nullptr, nullptr);
	this->_dummyFirstNode->nextNode = this->_dummyLastNode;
	this->_dummyLastNode->preNode = this->_dummyFirstNode;

	this->_size = 0;
}


int DoublyLinkedList::size() const {
	return this->_size;
}


bool DoublyLinkedList::insert(Iterator iterator, const ScoreData& scoreData) {
	//**********	�f�[�^�̑}���Ɏ��s	**********//
	
	//���̃��X�g�̃C�e���[�^�����X�g�ւ̎Q�Ƃ��Ȃ��C�e���[�^���n���ꂽ�ꍇ
	if (iterator.referenceToList != this) {
		return false;
	}

	//********************************************//
	
	Node* newNode = new Node(iterator._it->preNode, iterator._it, scoreData);
	iterator._it->preNode->nextNode = newNode;
	iterator._it->preNode = newNode;

	_size++;

	return true;
}


bool DoublyLinkedList::insert(ConstIterator cIterator, const ScoreData& scoreData) {
	//**********	�f�[�^�̑}���Ɏ��s	**********//

	//���̃��X�g�̃R���X�g�C�e���[�^�����X�g�ւ̎Q�Ƃ��Ȃ��R���X�g�C�e���[�^���n���ꂽ�ꍇ
	if (cIterator.referenceToList != this) {
		return false;
	}

	//********************************************//

	Node* newNode = new Node(cIterator._it->preNode, cIterator._it, scoreData);
	cIterator._it->preNode->nextNode = newNode;
	cIterator._it->preNode = newNode;

	_size++;

	return true;
}


bool DoublyLinkedList::remove(Iterator iterator) {

	//**********	�f�[�^�̍폜�Ɏ��s	**********//
	//���̃��X�g�̃C�e���[�^�����X�g�ւ̎Q�Ƃ��Ȃ��C�e���[�^���n���ꂽ�ꍇ
	if (iterator.referenceToList != this) {
		return false;
	}
	if (iterator._it == this->_dummyFirstNode || iterator._it == this->_dummyLastNode) {
		return false;	//�擪�_�~�[�܂��͖����_�~�[���폜���悤�Ƃ����ꍇ
	}

	//*******************************************//

	iterator._it->preNode->nextNode = iterator._it->nextNode;
	iterator._it->nextNode->preNode = iterator._it->preNode;

	--_size;

	return true;
}


bool DoublyLinkedList::remove(ConstIterator cIterator) {

	//**********	�f�[�^�̍폜�Ɏ��s	**********//
	//���̃��X�g�̃R���X�g�C�e���[�^�����X�g�ւ̎Q�Ƃ��Ȃ��R���X�g�C�e���[�^���n���ꂽ�ꍇ
	if (cIterator.referenceToList != this) {
		return false;
	}
	if (cIterator._it == this->_dummyFirstNode || cIterator._it == this->_dummyLastNode) {
		return false;	//�擪�_�~�[�܂��͖����_�~�[���폜���悤�Ƃ����ꍇ
	}

	//*******************************************//

	cIterator._it->preNode->nextNode = cIterator._it->nextNode;
	cIterator._it->nextNode->preNode = cIterator._it->preNode;

	--_size;

	return true;
}


DoublyLinkedList::ConstIterator DoublyLinkedList::getFirstConstIterator() const {
	ConstIterator ret;
	if (_size == 0) {
		ret._it = _dummyLastNode;
	}
	else {
		ret._it = _dummyFirstNode->nextNode;
	}
	ret.referenceToList = this;
	return ret;

}


DoublyLinkedList::ConstIterator DoublyLinkedList::getReverseFirstConstIterator() const {
	ConstIterator ret;
	if (_size == 0) {
		ret._it = _dummyFirstNode;
	}
	else {
		ret._it = _dummyLastNode->preNode;
	}
	ret.referenceToList = this;
	return ret;

}


DoublyLinkedList::ConstIterator DoublyLinkedList::getLastConstIterator() const {
	ConstIterator ret;
	ret._it = _dummyLastNode;
	ret.referenceToList = this;
	return ret;
}


DoublyLinkedList::ConstIterator DoublyLinkedList::getReverseLastConstIterator() const {
	ConstIterator ret;
	ret._it = _dummyFirstNode;
	ret.referenceToList = this;
	return ret;

}


DoublyLinkedList::Iterator DoublyLinkedList::getFirstIterator() {
	Iterator ret;
	if (_size == 0) {
		ret._it = _dummyLastNode;
	}
	else {
		ret._it = _dummyFirstNode->nextNode;
	}
	ret.referenceToList = this;
	return ret;

}


DoublyLinkedList::Iterator DoublyLinkedList::getReverseFirstIterator() {
	Iterator ret;
	if (_size == 0) {
		ret._it = _dummyFirstNode;
	}
	else {
		ret._it = _dummyLastNode->preNode;
	}
	ret.referenceToList = this;
	return ret;

}


DoublyLinkedList::Iterator DoublyLinkedList::getLastIterator() {
	Iterator ret;
	ret._it = _dummyLastNode;
	ret.referenceToList = this;
	return ret;
}


DoublyLinkedList::Iterator DoublyLinkedList::getReverseLastIterator() {
	Iterator ret;
	ret._it = _dummyFirstNode;
	ret.referenceToList = this;
	return ret;

}
