#include<iostream>
#include<fstream>
#include<string>
#include<list>

#include "DoublyLinkedList.h"

int main() {
	std::string fileName = "Scores.txt";
	std::ifstream fileInput(fileName);

	DoublyLinkedList list;
	DoublyLinkedList::Iterator itInsert = list.getFirstIterator();

	while (!fileInput.eof()) {

		ScoreData scoreData;
		fileInput >> scoreData.score >> scoreData.name;
		list.insert(itInsert, scoreData);
	}

	DoublyLinkedList::Iterator itIncrement = list.getFirstIterator();
	DoublyLinkedList::Iterator itLast = list.getLastIterator();

	for (auto i = list.getFirstIterator(); i != list.getLastIterator(); i++) {
		std::cout << (*i).score << "," << (*i).name << std::endl;
	}

	return 0;
}