#include "pch.h"
#include "../kadai1_2/DoublyLinkedList.h"
#include <string>

/**
* テスト用のデータをリスト先頭からリスト末尾に向けて挿入する関数．\n
* 先頭ダミーから後方に(0,test0),(1,test1), ... の順で挿入される．\n
*
* @param[in] DoublyLinkedList 双方向リスト
* @param[in] numElement リストに挿入する要素の数
*/
void createListHavingElements(DoublyLinkedList& list, int numElement) {

	DoublyLinkedList::Iterator it = list.getFirstIterator();
	for (int i = 0; i < numElement; i++) {
		ScoreData scoreData(std::to_string(i), "test" + std::to_string(i));
		ASSERT_TRUE(list.insert(it, scoreData));
	}
}

//=================================== データ数の取得 ===================================

/**
*	@brief		リストが空である場合のデータ数の取得テスト
*	@details	ID:リスト-0\n
*				データ数の取得機能のテストです.\n
*				リストが空である場合の戻り値を確認しています.\n
*				データ数が0であれば成功です.\n
*/
TEST(GetDataNumTest, WhenListIsEmpty) {
	DoublyLinkedList list;
	EXPECT_EQ(0, list.size());
}

/**
*	@brief		リスト末尾への挿入を行った際のデータ数の取得テスト
*	@details	ID:リスト-1\n
*				データ数の取得機能のテストです.\n
*				リスト末尾への挿入を行った際の戻り値を確認しています.\n
*				データ数が1であれば成功です.\n
*/
TEST(GetDataNumTest, WhenInsertLastIsSucceeded) {
	DoublyLinkedList list;
	ScoreData scoreData("1", "test");
	ASSERT_TRUE(list.insert(list.getLastIterator(), scoreData));
	EXPECT_EQ(1, list.size());
}

/**
*	@brief		リスト末尾への挿入が失敗した際のデータ数の取得テスト
*	@details	ID:リスト-2\n
*				データ数の取得機能のテストです.\n
*				リスト末尾への挿入が失敗した際の戻り値を確認しています.\n
*				データ数が0であれば成功です.\n
*/
TEST(GetDataNumTest, WhenInsertLastIsFailed) {
	DoublyLinkedList list;
	ScoreData scoreData("1", "test");
	//ASSERT_FALSE(list.insert(list.getLastIterator(), scoreData));	//ここが失敗する場合(テスト省略)
	EXPECT_EQ(0, list.size());

}

/**
*	@brief		データの挿入を行った際のデータ数の取得テスト
*	@details	ID:リスト-3\n
*				データ数の取得機能のテストです.\n
*				リストへの挿入を行った際の戻り値を確認しています.\n
*				データ数が増えていれば成功です.\n
*/
TEST(GetDataNumTest, WhenInsertIsSucceeded) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);	//３つの要素を持つリストを用意する
	int sizeBeforeInsert = list.size();

	ScoreData scoreData("1", "test1");
	ASSERT_TRUE(list.insert(list.getLastIterator(), scoreData));	//末尾に新しいデータを挿入
	EXPECT_EQ(sizeBeforeInsert + 1, list.size());
}

/**
*	@brief		データの挿入が失敗した際のデータ数の取得テスト
*	@details	ID:リスト-4\n
*				データ数の取得機能のテストです.\n
*				リストへの挿入が失敗した際の戻り値を確認しています.\n
*				データ数が増えていなければ成功です.\n
*/
TEST(GetDataNumTest, WhenInsertIsFailed) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);	//３つの要素を持つリストを用意する
	int sizeBeforeInsert = list.size();

	ScoreData scoreData("1", "test1");
	//ASSERT_FALSE(list.insert(list.getFirstIterator(), newScoreData));	//ここが失敗する場合(テスト省略)
	EXPECT_EQ(sizeBeforeInsert, list.size());
}

/**
*	@brief		データの削除を行った際のデータ数の取得テスト
*	@details	ID:リスト-5\n
*				データ数の取得機能のテストです.\n
*				データの削除を行った際の戻り値を確認しています.\n
*				データ数が減っていれば成功です．\n
*/
TEST(GetDataNumTest, WhenRemoveIsSucceeded) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);
	int sizeBeforeInsert = list.size();

	ASSERT_TRUE(list.remove(list.getFirstIterator()));
	EXPECT_EQ(sizeBeforeInsert - 1, list.size());
}

/**
*	@brief		データの削除に失敗した際のデータ数の取得テスト
*	@details	ID:リスト-6\n
*				データ数の取得機能のテストです.\n
*				データの削除が失敗した際の戻り値を確認しています.\n
*				データ数が減っていなければ成功です．\n
*/
TEST(GetDataNumTest, WhenRemoveIsFailed) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);
	int sizeBeforeInsert = list.size();

	//ASSERT_TRUE(list.remove(list.getFirstIterator()));	//ここが失敗する場合(テスト省略)
	EXPECT_EQ(sizeBeforeInsert, list.size());
}

/**
*	@brief		リストが空である場合に，データの削除を行った際のデータ数の取得テスト
*	@details	ID:リスト-7\n
*				データ数の取得機能のテストです.\n
*				リストが空である場合に，データの削除を行った際の戻り値を確認しています.\n
*				データ数が0であれば成功です．\n
*/
TEST(GetDataNumTest, WhenRemoveFromEmptyList) {
	DoublyLinkedList list;
	ASSERT_FALSE(list.remove(list.getFirstIterator()));
	EXPECT_EQ(0, list.size());
}


//=================================== データの挿入 ===================================

/**
*	@brief		リストが空である場合に，リスト先頭のダミー後方へのデータ挿入テスト
*	@details	ID:リスト-9-1\n
*				データの挿入機能のテストです.\n
*				リストが空である場合に，リスト先頭のダミーの後方にデータを挿入した際の挙動を確認しています.\n
*				データ挿入後，先頭要素の後方が末尾ダミーであれば成功です．\n
*/
TEST(InsertDataTest, WhenInsertToBackOfFirstIterator) {
	DoublyLinkedList list;

	ScoreData scoreData("1", "test");

	ASSERT_TRUE(list.insert(list.getFirstIterator(), scoreData));

	DoublyLinkedList::Iterator itFirstElement = list.getFirstIterator();	//先頭要素を指すイテレータ
	++itFirstElement;	//末尾ダミーへ移動
	bool isEqual = (itFirstElement == list.getLastIterator());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		リストが空である場合に，リスト末尾のダミー前方へのデータ挿入テスト
*	@details	ID:リスト-9-2\n
*				データの挿入機能のテストです.\n
*				リストが空である場合に，リスト末尾のダミーの前方にデータを挿入した際の挙動を確認しています.\n
*				データ挿入後，先頭要素の後方が末尾ダミーであれば成功です．\n
*/
TEST(InsertDataTest, WhenInsertToFrontOfLastIterator) {
	DoublyLinkedList list;

	ScoreData scoreData("1", "test");
	ASSERT_TRUE(list.insert(list.getLastIterator(), scoreData));

	DoublyLinkedList::Iterator itFirst = list.getFirstIterator();	//先頭要素を指すイテレータ
	++itFirst;	//末尾ダミーへ移動
	bool isEqual = (itFirst == list.getLastIterator());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		リストに複数の要素がある場合に，先頭要素の前方へのデータ挿入テスト
*	@details	ID:リスト-10\n
*				データの挿入機能のテストです.\n
*				リストに複数の要素がある場合に，先頭要素の前方へデータ挿入した際の挙動を確認しています.\n
*				データ挿入後，挿入前の先頭要素の前方と先頭要素が同じであれば成功です．\n
*/
TEST(InsertDataTest, WhenInsertToFrontOfElements) {
	DoublyLinkedList list;

	createListHavingElements(list, 3);

	DoublyLinkedList::Iterator itFirstElement = list.getFirstIterator();	//データ挿入前の先頭要素を指すイテレータ
	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(list.getFirstIterator(), newScoreData));
	--itFirstElement;	//前方へ移動

	bool isEqual = (list.getFirstIterator() == itFirstElement);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		リストに複数の要素がある場合に，末尾要素の後方へのデータ挿入テスト
*	@details	ID:リスト-11\n
*				データの挿入機能のテストです.\n
*				リストに複数の要素がある場合に，末尾要素の後方へデータ挿入した際の挙動を確認しています.\n
*				データ挿入後，挿入前の末尾要素を指すイテレータの2つ後方が末尾ダミーであれば成功です．\n
*/
TEST(InsertDataTest, WhenInsertToBackOfElements) {
	DoublyLinkedList list;

	createListHavingElements(list, 3);

	DoublyLinkedList::Iterator itLastElement = list.getLastIterator();	//データ挿入前の末尾要素を指すイテレータ
	--itLastElement;	//末尾要素へ移動

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(list.getLastIterator(), newScoreData));
	
	++itLastElement;	//挿入後の末尾要素へ移動
	++itLastElement;	//末尾ダミーへ移動
	bool isEqual = (itLastElement == list.getLastIterator());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		リストに複数の要素がある場合に，先頭でも末尾でもないイテレータを渡した際のデータ挿入テスト
*	@details	ID:リスト-12-1\n
*				データの挿入機能のテストです.\n
*				リストに複数の要素がある場合に，先頭要素を指すイテレータを渡してデータ挿入した際の挙動を確認しています．\n
*				データ挿入後，挿入したデータの前方が先頭要素を指すイテレータであれば成功です．\n
*/
TEST(InsertDataTest, WhenInsertToFirstElementWithIterator) {
	DoublyLinkedList list;

	createListHavingElements(list, 3);

	DoublyLinkedList::Iterator itFirstElement = list.getFirstIterator();	//挿入前の先頭要素を指すイテレータ
	
	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(list.getFirstIterator(), newScoreData));	//先頭要素の前方へ挿入
	--itFirstElement;	//前方へ移動

	bool isEqual = (list.getFirstIterator() == itFirstElement);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		リストに複数の要素がある場合に，先頭でも末尾でもないイテレータを渡した際のデータ挿入テスト
*	@details	ID:リスト-12-2\n
*				データの挿入機能のテストです.\n
*				リストに複数の要素がある場合に，中央の要素を指すイテレータを渡してデータ挿入した際の挙動を確認しています．\n
*				データ挿入後，先頭要素の２つ後方が挿入前の中央の要素であれば成功です．\n
*/
TEST(InsertDataTest, WhenInsertToCenterElementWithIterator) {
	DoublyLinkedList list;

	createListHavingElements(list, 3);

	DoublyLinkedList::Iterator itFirstElement = list.getFirstIterator();	//先頭要素を指すイテレータ

	DoublyLinkedList::Iterator itCenterElement = list.getFirstIterator();	//挿入前の中央の要素を指すイテレータ
	++itCenterElement;	//中央の要素へ移動

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(itCenterElement, newScoreData));	//中央の要素の前方へ挿入
	
	++itFirstElement;	//挿入したデータへ移動
	++itFirstElement;	//挿入前の中央の要素
	bool isEqual = (itFirstElement == itCenterElement);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		リストに複数の要素がある場合に，先頭でも末尾でもないイテレータを渡した際のデータ挿入テスト
*	@details	ID:リスト-12-3\n
*				データの挿入機能のテストです.\n
*				リストに複数の要素がある場合に，末尾要素を指すイテレータを渡してデータ挿入した際の挙動を確認しています．\n
*				データ挿入後，挿入前の末尾要素の２つ後方が末尾ダミーであれば成功です．\n
*/
TEST(InsertDataTest, WhenInsertToLastElementWithIterator) {
	DoublyLinkedList list;

	createListHavingElements(list, 3);

	DoublyLinkedList::Iterator itLastElement = list.getLastIterator();	//挿入前の末尾要素を指すイテレータ
	--itLastElement;	//末尾要素へ移動

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(list.getLastIterator(), newScoreData));

	++itLastElement;	//挿入したデータへ移動
	++itLastElement;	//末尾ダミーへ移動
	bool isEqual = (itLastElement == list.getLastIterator());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		リストに複数の要素がある場合に，先頭でも末尾でもないコンストイテレータを渡した際のデータ挿入テスト
*	@details	ID:リスト-13-1\n
*				データの挿入機能のテストです.\n
*				リストに複数の要素がある場合に，先頭要素を指すコンストイテレータを渡してデータ挿入した際の挙動を確認しています．\n
*				データ挿入後，挿入したデータの前方が先頭要素を指すコンストイテレータであれば成功です．\n
*/
TEST(InsertDataTest, WhenInsertToFirstElementWithConstIterator) {
	DoublyLinkedList list;

	createListHavingElements(list, 3);

	DoublyLinkedList::ConstIterator cItFirstElement = list.getFirstConstIterator();	//挿入前の先頭要素を指すコンストイテレータ

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(list.getFirstConstIterator(), newScoreData));	//先頭要素の前方へ挿入
	--cItFirstElement;	//前方へ移動

	bool isEqual = (list.getFirstConstIterator() == cItFirstElement);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		リストに複数の要素がある場合に，先頭でも末尾でもないコンストイテレータを渡した際のデータ挿入テスト
*	@details	ID:リスト-13-2\n
*				データの挿入機能のテストです.\n
*				リストに複数の要素がある場合に，中央の要素を指すコンストイテレータを渡してデータ挿入した際の挙動を確認しています．\n
*				データ挿入後，先頭要素の２つ後方が挿入前の中央の要素であれば成功です．\n
*/
TEST(InsertDataTest, WhenInsertToCenterElementWithConstIterator) {
	DoublyLinkedList list;

	createListHavingElements(list, 3);

	DoublyLinkedList::ConstIterator cItFirstElement = list.getFirstConstIterator();	//先頭要素を指すコンストイテレータ

	DoublyLinkedList::ConstIterator cItCenterElement = list.getFirstConstIterator();	//挿入前の中央の要素を指すコンストイテレータ
	++cItCenterElement;	//中央の要素へ移動

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(cItCenterElement, newScoreData));	//中央の要素の前方へ挿入

	++cItFirstElement;	//挿入したデータへ移動
	++cItFirstElement;	//挿入前の中央の要素
	bool isEqual = (cItCenterElement == cItFirstElement);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		リストに複数の要素がある場合に，先頭でも末尾でもないコンストイテレータを渡した際のデータ挿入テスト
*	@details	ID:リスト-13-3\n
*				データの挿入機能のテストです.\n
*				リストに複数の要素がある場合に，末尾要素を指すイテレータを渡してデータ挿入した際の挙動を確認しています．\n
*				データ挿入後，挿入前の末尾要素の２つ後方が末尾ダミーであれば成功です．\n
*/
TEST(InsertDataTest, WhenInsertToLastElementWithConstIterator) {
	DoublyLinkedList list;

	createListHavingElements(list, 3);

	DoublyLinkedList::ConstIterator cItLastElement = list.getLastConstIterator();	//挿入前の末尾要素を指すコンストイテレータ
	--cItLastElement;	//末尾要素へ移動

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(list.getLastConstIterator(), newScoreData));

	++cItLastElement;	//挿入したデータへ移動
	++cItLastElement;	//末尾ダミーへ移動
	bool isEqual = (cItLastElement == list.getLastConstIterator());
	EXPECT_TRUE(isEqual);
}
/**
*	@brief		不正なイテレータを渡した際のデータ挿入テスト
*	@details	ID:リスト-14\n
*				データの挿入機能のテストです.\n
*				不正なイテレータを渡した際の挙動を確認しています．\n
*				何も起こらなければ成功です．\n
*/
TEST(InsertDataTest, WhenInsertWithNotAvailableIterator) {
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it;

	ScoreData scoreData("1", "test");
	EXPECT_FALSE(list.insert(it, scoreData));	//リストへの参照がないイテレータを渡した場合

	DoublyLinkedList listOther;
	DoublyLinkedList::Iterator itOther = listOther.getFirstIterator();
	EXPECT_FALSE(list.insert(itOther, scoreData));	//別のリストのイテレータを渡した場合
}


//=================================== データの削除 ===================================

/**
*	@brief		リストが空である場合に，削除を行った際のテスト
*	@details	ID:リスト-16-1\n
*				データの削除機能のテストです.\n
*				リストが空である場合に，リスト先頭のダミーを削除した際の挙動を確認しています.\n
*				何も起こらなければ成功です．\n
*/
TEST(RemoveDataTest, WhenRemoveFirstOfEmptyList) {
	DoublyLinkedList list;
	DoublyLinkedList::Iterator itFirst = list.getFirstIterator();
	EXPECT_FALSE(list.remove(itFirst));
}

/**
*	@brief		リストが空である場合に，削除を行った際のテスト
*	@details	ID:リスト-16-2\n
*				データの削除機能のテストです.\n
*				リストが空である場合に，リスト末尾のダミーを削除した際の挙動を確認しています.\n
*				何も起こらなければ成功です．\n
*/
TEST(RemoveDataTest, WhenRemoveLastOfEmptyList) {
	DoublyLinkedList list;
	DoublyLinkedList::Iterator itLast = list.getLastIterator();
	EXPECT_FALSE(list.remove(itLast));
}

/**
*	@brief		リストに複数の要素がある場合に，リストの先頭要素を渡して削除を行った際のテスト
*	@details	ID:リスト-17\n
*				データの削除機能のテストです.\n
*				リストに複数の要素がある場合に，リストの先頭要素を渡して削除した際の挙動を確認しています.\n
*				データ削除後，リストの先頭要素が削除前の中央の要素であれば成功です．\n
*/
TEST(RemoveDataTest, WhenRemoveFirstOfListHavingElements) {
	DoublyLinkedList list;

	createListHavingElements(list, 3);

	DoublyLinkedList::Iterator itCenterElement = list.getFirstIterator();	//中央の要素を指すイテレータ
	++itCenterElement;	//中央の要素へ移動

	ASSERT_TRUE(list.remove(list.getFirstIterator()));

	bool isEqual = (list.getFirstIterator() == itCenterElement);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		リストに複数の要素がある場合に，リスト末尾のイテレータを渡して削除を行った際のテスト
*	@details	ID:リスト-18\n
*				データの削除機能のテストです.\n
*				リストに複数の要素がある場合に，リスト末尾のイテレータを削除した際の挙動を確認しています.\n
*				何も起こらなければ成功です．\n
*/
TEST(RemoveDataTest, WhenRemoveLastOfListHavingElements) {
	DoublyLinkedList list;

	createListHavingElements(list, 3);

	EXPECT_FALSE(list.remove(list.getLastIterator()));
}

/**
*	@brief		リストに複数の要素がある場合に，リスト先頭でもリスト末尾でもないイテレータを渡して削除を行った際のテスト
*	@details	ID:リスト-19\n
*				データの削除機能のテストです.\n
*				リストに複数の要素がある場合に，リスト先頭でもリスト末尾でもない要素を削除した際の挙動を確認しています.\n
*				渡したイテレータが指す要素が削除されていれば成功です．\n
*/
TEST(RemoveDataTest, WhenRemoveCenterElementOfListHavingElements) {
	DoublyLinkedList list;

	createListHavingElements(list, 3);

	DoublyLinkedList::Iterator itFirstElement = list.getFirstIterator();	//先頭要素を指すイテレータ
	DoublyLinkedList::Iterator itCenterElement = list.getFirstIterator();	//中央の要素を指すイテレータ
	++itCenterElement;	//中央の要素へ移動
	DoublyLinkedList::Iterator itLastElement = list.getLastIterator();	//末尾要素を指すイテレータ
	--itLastElement;	//末尾要素へ移動
	
	ASSERT_TRUE(list.remove(itCenterElement));	//中央の要素を削除
	
	++itFirstElement;	//削除前に先頭要素を指していたイテレータを後方へ移動
	bool isEqual = (itFirstElement == itLastElement);	//中央の要素が削除されていれば，先頭要素の後方は末尾要素になるはず
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		コンストイテレータを渡して削除を行った際のテスト
*	@details	ID:リスト-20\n
*				データの削除機能のテストです.\n
*				コンストイテレータが指す要素を削除した際の挙動を確認しています.\n
*				渡したコンストイテレータが指す要素が削除されていれば成功です．\n
*/
TEST(RemoveDataTest, WhenRemoveWithConstIterator) {
	DoublyLinkedList list;

	createListHavingElements(list, 3);

	DoublyLinkedList::ConstIterator cItFirstElement = list.getFirstConstIterator();	//先頭要素を指すイテレータ
	DoublyLinkedList::ConstIterator cItCenterElement = list.getFirstConstIterator();	//中央の要素を指すイテレータ
	++cItCenterElement;	//中央の要素へ移動
	DoublyLinkedList::ConstIterator cItLastElement = list.getLastConstIterator();	//末尾要素を指すイテレータ
	--cItLastElement;	//末尾要素へ移動

	ASSERT_TRUE(list.remove(cItCenterElement));	//中央の要素を削除

	++cItFirstElement;	//削除前に先頭要素を指していたイテレータを後方へ移動
	bool isEqual = (cItFirstElement == cItLastElement);	//中央の要素が削除されていれば，先頭要素の後方は末尾要素になるはず
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		不正なイテレータを渡した際のデータ削除テスト
*	@details	ID:リスト-21\n
*				データの削除機能のテストです.\n
*				不正なイテレータを渡した際の挙動を確認しています．\n
*				何も起こらなければ成功です．\n
*/
TEST(RemoveDataTest, WhenRemoveWithNotAvailableIterator) {
	DoublyLinkedList list;
	createListHavingElements(list, 1);
	
	DoublyLinkedList::Iterator it;
	EXPECT_FALSE(list.remove(it));	//リストへの参照がないイテレータを渡した場合

	DoublyLinkedList listOther;
	DoublyLinkedList::Iterator itOther = listOther.getFirstIterator();
	EXPECT_FALSE(list.remove(itOther));	//別のリストのイテレータを渡した場合
}


//=================================== 先頭イテレータの取得 ===================================

/**
*	@brief		リストが空である場合に，先頭イテレータを取得した際のテスト
*	@details	ID:リスト-23\n
*				先頭イテレータの取得機能のテストです.\n
*				リストが空である場合に，先頭イテレータを取得した際の挙動を確認しています.\n
*				リスト先頭のダミーを指すイテレータが返れば成功です．\n
*/
TEST(GetFirstIteratorTest, WhenGetFirstIteratorFromEmptyList) {
	DoublyLinkedList list;
	DoublyLinkedList::Iterator itFirst = list.getFirstIterator();
	
	bool isEqual = (itFirst == list.getFirstIterator());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		リストに要素が1つある場合に，先頭イテレータを取得した際のテスト
*	@details	ID:リスト-24\n
*				先頭イテレータの取得機能のテストです.\n
*				リストに要素が1つある場合に，先頭イテレータを取得した際の挙動を確認しています.\n
*				リストの先頭要素を指すイテレータが返れば成功です．\n
*/
TEST(GetFirstIteratorTest, WhenGetFirstIteratorFromListHavingAElement) {
	DoublyLinkedList list;
	createListHavingElements(list, 1);

	DoublyLinkedList::Iterator itFirstElement = list.getFirstIterator();

	bool isEqual = (itFirstElement == list.getFirstIterator());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		リストに2つ以上の要素がある場合に，先頭イテレータを取得した際のテスト
*	@details	ID:リスト-25\n
*				先頭イテレータの取得機能のテストです.\n
*				リストに2つ以上の要素がある場合に，先頭イテレータを取得した際の挙動を確認しています.\n
*				リストの先頭要素を指すイテレータが返れば成功です．\n
*/
TEST(GetFirstIteratorTest, WhenGetFirstIteratorFromListHavingElements) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);

	DoublyLinkedList::Iterator itFirst = list.getFirstIterator();

	bool isEqual = (itFirst == list.getFirstIterator());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		データ挿入を行った後に，先頭イテレータを取得した際のテスト
*	@details	ID:リスト-26-1\n
*				先頭イテレータの取得機能のテストです.\n
*				先頭要素の後方へデータ挿入行った後に，先頭イテレータを取得した際の挙動を確認しています.\n
*				リストの先頭要素を指すイテレータが返れば成功です．\n
*/
TEST(GetFirstIteratorTest, WhenGetFirstIteratorFromListInsertedElementBackOfFirstElement) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);

	DoublyLinkedList::Iterator itFirstElement = list.getFirstIterator();	//挿入前の先頭要素を指すイテレータ
	DoublyLinkedList::Iterator itInsert = list.getFirstIterator();	//挿入場所を指すイテレータ
	++itInsert;

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(itInsert, newScoreData));

	bool isEqual = (itFirstElement == list.getFirstIterator());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		データ挿入を行った後に，先頭イテレータを取得した際のテスト
*	@details	ID:リスト-26-2\n
*				先頭イテレータの取得機能のテストです.\n
*				中央の要素の後方へデータ挿入行った後に，先頭イテレータを取得した際の挙動を確認しています.\n
*				リストの先頭要素を指すイテレータが返れば成功です．\n
*/
TEST(GetFirstIteratorTest, WhenGetFirstIteratorFromListInsertedElementBackOfCenterElement) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);

	DoublyLinkedList::Iterator itFirstElement = list.getFirstIterator();	//挿入前の先頭要素を指すイテレータ
	DoublyLinkedList::Iterator itInsert = list.getFirstIterator();	//挿入場所を指すイテレータ
	++itInsert;	//中央の要素へ移動
	++itInsert;	//末尾要素へ移動

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(itInsert, newScoreData));

	bool isEqual = (itFirstElement == list.getFirstIterator());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		データ挿入を行った後に，先頭イテレータを取得した際のテスト
*	@details	ID:リスト-26-3\n
*				先頭イテレータの取得機能のテストです.\n
*				末尾要素の後方へデータ挿入行った後に，先頭イテレータを取得した際の挙動を確認しています.\n
*				リストの先頭要素を指すイテレータが返れば成功です．\n
*/
TEST(GetFirstIteratorTest, WhenGetFirstIteratorFromListInsertedElementBackOfLastElement) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);

	DoublyLinkedList::Iterator itFirstElement = list.getFirstIterator();	//挿入前の先頭要素を指すイテレータ
	DoublyLinkedList::Iterator itInsert = list.getLastIterator();	//挿入場所を指すイテレータ

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(itInsert, newScoreData));

	bool isEqual = (itFirstElement == list.getFirstIterator());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		データ削除を行った後に，先頭イテレータを取得した際のテスト
*	@details	ID:リスト-27-1\n
*				先頭イテレータの取得機能のテストです.\n
*				先頭要素の削除を行った後に，先頭イテレータを取得した際の挙動を確認しています.\n
*				リストの先頭要素を指すイテレータが返れば成功です．\n
*/
TEST(GetFirstIteratorTest, WhenGetFirstIteratorFromListRemovedFirstElement) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);

	DoublyLinkedList::Iterator itCenterElement = list.getFirstIterator();	//削除前の中央の要素を指すイテレータ
	++itCenterElement;	//中央の要素へ移動
	DoublyLinkedList::Iterator itRemove = list.getFirstIterator();	//削除場所を指すイテレータ

	ASSERT_TRUE(list.remove(itRemove));

	bool isEqual = (itCenterElement == list.getFirstIterator());	//先頭要素が削除されていれば，削除前の中央の要素が先頭になるはず
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		データ削除を行った後に，先頭イテレータを取得した際のテスト
*	@details	ID:リスト-27-2\n
*				先頭イテレータの取得機能のテストです.\n
*				中央の要素の削除を行った後に，先頭イテレータを取得した際の挙動を確認しています.\n
*				リストの先頭要素を指すイテレータが返れば成功です．\n
*/
TEST(GetFirstIteratorTest, WhenGetFirstIteratorFromListRemovedCenterElement) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);

	DoublyLinkedList::Iterator itFirstElement = list.getFirstIterator();	//削除前の先頭要素を指すイテレータ
	DoublyLinkedList::Iterator itRemove = list.getFirstIterator();	//削除場所を指すイテレータ
	++itRemove;	//中央の要素へ移動

	ASSERT_TRUE(list.remove(itRemove));

	bool isEqual = (itFirstElement == list.getFirstIterator());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		データ削除を行った後に，先頭イテレータを取得した際のテスト
*	@details	ID:リスト-27-3\n
*				先頭イテレータの取得機能のテストです.\n
*				末尾要素の削除を行った後に，先頭イテレータを取得した際の挙動を確認しています.\n
*				リストの先頭要素を指すイテレータが返れば成功です．\n
*/
TEST(GetFirstIteratorTest, WhenGetFirstIteratorFromListRemovedLastElement) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);

	DoublyLinkedList::Iterator itFirst = list.getFirstIterator();	//削除前の先頭要素を指すイテレータ
	DoublyLinkedList::Iterator itRemove = list.getLastIterator();	//削除場所を指すイテレータ
	--itRemove;	//末尾要素へ移動

	ASSERT_TRUE(list.remove(itRemove));

	bool isEqual = (itFirst == list.getFirstIterator());
	EXPECT_TRUE(isEqual);
}

//=================================== 先頭コンストイテレータの取得 ===================================

/**
*	@brief		リストが空である場合に，先頭コンストイテレータを取得した際のテスト
*	@details	ID:リスト-29\n
*				先頭コンストイテレータの取得機能のテストです.\n
*				リストが空である場合に，先頭コンストイテレータを取得した際の挙動を確認しています.\n
*				リスト先頭のダミーを指すコンストイテレータが返れば成功です．\n
*/
TEST(GetFirstConstIteratorTest, WhenGetFirstConstIteratorFromEmptyList) {
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator cItFirst = list.getFirstConstIterator();

	bool isEqual = (cItFirst == list.getFirstConstIterator());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		リストに要素が1つある場合に，先頭コンストイテレータを取得した際のテスト
*	@details	ID:リスト-30\n
*				先頭コンストイテレータの取得機能のテストです.\n
*				リストに要素が1つある場合に，先頭コンストイテレータを取得した際の挙動を確認しています.\n
*				リストの先頭要素を指すコンストイテレータが返れば成功です．\n
*/
TEST(GetFirstConstIteratorTest, WhenGetFirstConstIteratorFromListHavingAElement) {
	DoublyLinkedList list;
	createListHavingElements(list, 1);

	DoublyLinkedList::ConstIterator cItFirstElement = list.getFirstConstIterator();

	bool isEqual = (cItFirstElement == list.getFirstConstIterator());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		リストに2つ以上の要素がある場合に，先頭コンストイテレータを取得した際のテスト
*	@details	ID:リスト-31\n
*				先頭コンストイテレータの取得機能のテストです.\n
*				リストに2つ以上の要素がある場合に，先頭コンストイテレータを取得した際の挙動を確認しています.\n
*				リストの先頭要素を指すコンストイテレータが返れば成功です．\n
*/
TEST(GetFirstConstIteratorTest, WhenGetFirstConstIteratorFromListHavingElements) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);

	DoublyLinkedList::ConstIterator cItFirstElement = list.getFirstConstIterator();

	bool isEqual = (cItFirstElement == list.getFirstConstIterator());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		データ挿入を行った後に，先頭コンストイテレータを取得した際のテスト
*	@details	ID:リスト-32-1\n
*				先頭コンストイテレータの取得機能のテストです.\n
*				先頭要素の後方へデータ挿入行った後に，先頭コンストイテレータを取得した際の挙動を確認しています.\n
*				リストの先頭要素を指すコンストイテレータが返れば成功です．\n
*/
TEST(GetFirstConstIteratorTest, WhenGetFirstConstIteratorFromListInsertedElementBackOfFirstElement) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);

	DoublyLinkedList::ConstIterator cItFirstElement = list.getFirstConstIterator();	//挿入前の先頭要素を指すコンストイテレータ
	DoublyLinkedList::ConstIterator cItInsert = list.getFirstConstIterator();	//挿入場所を指すコンストイテレータ
	++cItInsert;	//中央の要素へ移動

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(cItInsert, newScoreData));

	bool isEqual = (cItFirstElement == list.getFirstConstIterator());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		データ挿入を行った後に，先頭コンストイテレータを取得した際のテスト
*	@details	ID:リスト-32-2\n
*				先頭コンストイテレータの取得機能のテストです.\n
*				中央の要素の後方へデータ挿入行った後に，先頭コンストイテレータを取得した際の挙動を確認しています.\n
*				リストの先頭要素を指すコンストイテレータが返れば成功です．\n
*/
TEST(GetFirstConstIteratorTest, WhenGetFirstConstIteratorFromListInsertedElementBackOfCenterElement) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);

	DoublyLinkedList::ConstIterator cItFirstElement = list.getFirstConstIterator();	//挿入前の先頭要素を指すコンストイテレータ
	DoublyLinkedList::ConstIterator cItInsert = list.getFirstConstIterator();	//挿入場所を指すコンストイテレータ
	++cItInsert;	//中央の要素へ移動
	++cItInsert;	//末尾要素へ移動

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(cItInsert, newScoreData));

	bool isEqual = (cItFirstElement == list.getFirstConstIterator());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		データ挿入を行った後に，先頭コンストイテレータを取得した際のテスト
*	@details	ID:リスト-32-3\n
*				先頭コンストイテレータの取得機能のテストです.\n
*				末尾要素の後方へデータ挿入行った後に，先頭コンストイテレータを取得した際の挙動を確認しています.\n
*				リストの先頭要素を指すコンストイテレータが返れば成功です．\n
*/
TEST(GetFirstConstIteratorTest, WhenGetFirstConstIteratorFromListInsertedElementBackOfLastElement) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);

	DoublyLinkedList::ConstIterator cItFirstElement = list.getFirstConstIterator();	//挿入前の先頭要素を指すコンストイテレータ
	DoublyLinkedList::ConstIterator cItInsert = list.getLastConstIterator();	//挿入場所を指すコンストイテレータ

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(cItInsert, newScoreData));

	bool isEqual = (cItFirstElement == list.getFirstConstIterator());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		データ削除を行った後に，先頭コンストイテレータを取得した際のテスト
*	@details	ID:リスト-33-1\n
*				先頭コンストイテレータの取得機能のテストです.\n
*				先頭要素の削除を行った後に，先頭コンストイテレータを取得した際の挙動を確認しています.\n
*				リストの先頭要素を指すコンストイテレータが返れば成功です．\n
*/
TEST(GetFirstConstIteratorTest, WhenGetFirstConstIteratorFromListRemovedFirstElement) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);

	DoublyLinkedList::ConstIterator cItCenterElement = list.getFirstConstIterator();	//削除前の中央の要素を指すコンストイテレータ
	++cItCenterElement;	//中央の要素へ移動
	DoublyLinkedList::ConstIterator cItRemove = list.getFirstConstIterator();	//削除場所を指すコンストイテレータ

	ASSERT_TRUE(list.remove(cItRemove));

	bool isEqual = (cItCenterElement == list.getFirstConstIterator());	//先頭要素が削除されていれば，削除前の中央の要素が先頭になるはず
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		データ削除を行った後に，先頭コンストイテレータを取得した際のテスト
*	@details	ID:リスト-33-2\n
*				先頭コンストイテレータの取得機能のテストです.\n
*				中央の要素の削除を行った後に，先頭コンストイテレータを取得した際の挙動を確認しています.\n
*				リストの先頭要素を指すコンストイテレータが返れば成功です．\n
*/
TEST(GetFirstConstIteratorTest, WhenGetFirstConstIteratorFromListRemovedCenterElement) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);

	DoublyLinkedList::ConstIterator cItFirstElement = list.getFirstConstIterator();	//削除前の先頭要素を指すコンストイテレータ
	DoublyLinkedList::ConstIterator cItRemove = list.getFirstConstIterator();	//削除場所を指すコンストイテレータ
	++cItRemove;	//中央の要素へ移動

	ASSERT_TRUE(list.remove(cItRemove));

	bool isEqual = (cItFirstElement == list.getFirstConstIterator());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		データ削除を行った後に，先頭コンストイテレータを取得した際のテスト
*	@details	ID:リスト-33-3\n
*				先頭コンストイテレータの取得機能のテストです.\n
*				末尾要素の削除を行った後に，先頭コンストイテレータを取得した際の挙動を確認しています.\n
*				リストの先頭要素を指すコンストイテレータが返れば成功です．\n
*/
TEST(GetFirstConstIteratorTest, WhenGetFirstConstIteratorFromListRemovedLastElement) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);

	DoublyLinkedList::ConstIterator cItFirstElement = list.getFirstConstIterator();	//削除前の先頭要素を指すコンストイテレータ
	DoublyLinkedList::ConstIterator cItRemove = list.getLastConstIterator();	//削除場所を指すコンストイテレータ
	--cItRemove;	//末尾要素へ移動

	ASSERT_TRUE(list.remove(cItRemove));

	bool isEqual = (cItFirstElement == list.getFirstConstIterator());
	EXPECT_TRUE(isEqual);
}


//=================================== 末尾イテレータの取得 ===================================

/**
*	@brief		リストが空である場合に，末尾イテレータを取得した際のテスト
*	@details	ID:リスト-35\n
*				末尾イテレータの取得機能のテストです.\n
*				リストが空である場合に，末尾イテレータを取得した際の挙動を確認しています.\n
*				リスト末尾のダミーを指すイテレータが返れば成功です．\n
*/
TEST(GetLastIteratorTest, WhenGetLastIteratorFromEmptyList) {
	DoublyLinkedList list;
	DoublyLinkedList::Iterator itLast = list.getLastIterator();

	bool isEqual = (itLast == list.getLastIterator());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		リストに要素が1つある場合に，末尾イテレータを取得した際のテスト
*	@details	ID:リスト-36\n
*				末尾イテレータの取得機能のテストです.\n
*				リストに要素が1つある場合に，末尾イテレータを取得した際の挙動を確認しています.\n
*				リストの末尾要素を指すイテレータが返れば成功です．\n
*/
TEST(GetLastIteratorTest, WhenGetLastIteratorFromListHavingAElement) {
	DoublyLinkedList list;
	createListHavingElements(list, 1);

	DoublyLinkedList::Iterator itLastElement = list.getLastIterator();
	--itLastElement;	//末尾要素へ移動

	ScoreData lastElement("0", "test0");	//末尾要素
	bool isEqual = (*(itLastElement) == lastElement);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		リストに2つ以上の要素がある場合に，末尾イテレータを取得した際のテスト
*	@details	ID:リスト-37\n
*				末尾イテレータの取得機能のテストです.\n
*				リストに2つ以上の要素がある場合に，末尾イテレータを取得した際の挙動を確認しています.\n
*				リストの末尾要素を指すイテレータが返れば成功です．\n
*/
TEST(GetLastIteratorTest, WhenGetLastIteratorFromListHavingElements) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);

	DoublyLinkedList::Iterator itLastElement = list.getLastIterator();
	--itLastElement;	//末尾要素へ移動

	ScoreData lastElement("2", "test2");	//末尾要素
	bool isEqual = ((*itLastElement) == lastElement);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		データ挿入を行った後に，末尾イテレータを取得した際のテスト
*	@details	ID:リスト-38-1\n
*				末尾イテレータの取得機能のテストです.\n
*				先頭要素の後方へデータ挿入行った後に，末尾イテレータを取得した際の挙動を確認しています.\n
*				リストの末尾要素を指すイテレータが返れば成功です．\n
*/
TEST(GetLastIteratorTest, WhenGetLastIteratorFromListInsertedElementBackOfFirstElement) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);

	DoublyLinkedList::Iterator itLast = list.getLastIterator();	//挿入前の末尾ダミーを指すイテレータ
	DoublyLinkedList::Iterator itInsert = list.getFirstIterator();	//挿入場所を指すイテレータ
	++itInsert;	//後方へ移動

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(itInsert, newScoreData));


	bool isEqual = (itLast == list.getLastIterator());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		データ挿入を行った後に，末尾イテレータを取得した際のテスト
*	@details	ID:リスト-38-2\n
*				末尾イテレータの取得機能のテストです.\n
*				中央の要素の後方へデータ挿入行った後に，末尾イテレータを取得した際の挙動を確認しています.\n
*				リストの末尾要素を指すイテレータが返れば成功です．\n
*/
TEST(GetLastIteratorTest, WhenGetLastIteratorFromListInsertedElementBackOfCenterElement) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);

	DoublyLinkedList::Iterator itLast = list.getLastIterator();	//挿入前の末尾ダミーを指すイテレータ
	DoublyLinkedList::Iterator itInsert = list.getFirstIterator();	//挿入場所を指すイテレータ
	++itInsert;	//中央の要素へ移動
	++itInsert;	//後方へ移動

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(itInsert, newScoreData));

	bool isEqual = (itLast == list.getLastIterator());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		データ挿入を行った後に，末尾イテレータを取得した際のテスト
*	@details	ID:リスト-38-3\n
*				末尾イテレータの取得機能のテストです.\n
*				末尾要素の後方へデータ挿入行った後に，末尾イテレータを取得した際の挙動を確認しています.\n
*				リストの末尾要素を指すイテレータが返れば成功です．\n
*/
TEST(GetLastIteratorTest, WhenGetLastIteratorFromListInsertedElementBackOfLastElement) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);

	DoublyLinkedList::Iterator itLast = list.getLastIterator();	//挿入前の末尾ダミーを指すイテレータ
	DoublyLinkedList::Iterator itInsert = list.getLastIterator();	//挿入場所を指すイテレータ

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(itInsert, newScoreData));

	bool isEqual = (itLast == list.getLastIterator());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		データ削除を行った後に，末尾イテレータを取得した際のテスト
*	@details	ID:リスト-39-1\n
*				末尾イテレータの取得機能のテストです.\n
*				先頭要素の削除を行った後に，末尾イテレータを取得した際の挙動を確認しています.\n
*				リストの末尾要素を指すイテレータが返れば成功です．\n
*/
TEST(GetLastIteratorTest, WhenGetLastIteratorFromListRemovedFirstElement) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);

	DoublyLinkedList::Iterator itLast = list.getLastIterator();	//削除前の末尾ダミーを指すイテレータ
	DoublyLinkedList::Iterator itRemove = list.getFirstIterator();	//削除場所を指すイテレータ

	ASSERT_TRUE(list.remove(itRemove));

	bool isEqual = (itLast == list.getLastIterator());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		データ削除を行った後に，末尾イテレータを取得した際のテスト
*	@details	ID:リスト-39-2\n
*				末尾イテレータの取得機能のテストです.\n
*				中央の要素の削除を行った後に，末尾イテレータを取得した際の挙動を確認しています.\n
*				リストの末尾要素を指すイテレータが返れば成功です．\n
*/
TEST(GetLastIteratorTest, WhenGetLastIteratorFromListRemovedCenterElement) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);

	DoublyLinkedList::Iterator itLast = list.getLastIterator();	//削除前の末尾ダミーを指すイテレータ
	DoublyLinkedList::Iterator itRemove = list.getFirstIterator();	//削除場所を指すイテレータ
	++itRemove;	//中央の要素へ移動

	ASSERT_TRUE(list.remove(itRemove));

	bool isEqual = (itLast == list.getLastIterator());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		データ削除を行った後に，末尾イテレータを取得した際のテスト
*	@details	ID:リスト-39-3\n
*				末尾イテレータの取得機能のテストです.\n
*				末尾要素の削除を行った後に，末尾イテレータを取得した際の挙動を確認しています.\n
*				リストの末尾要素を指すイテレータが返れば成功です．\n
*/
TEST(GetLastIteratorTest, WhenGetLastIteratorFromListRemovedLastElement) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);

	DoublyLinkedList::Iterator itLast = list.getLastIterator();	//削除前の末尾ダミーを指すイテレータ
	DoublyLinkedList::Iterator itRemove = list.getLastIterator();	//削除場所を指すイテレータ
	--itRemove;	//末尾要素へ移動

	ASSERT_TRUE(list.remove(itRemove));

	bool isEqual = (itLast == list.getLastIterator());
	EXPECT_TRUE(isEqual);
}

//=================================== 末尾コンストイテレータの取得 ===================================

/**
*	@brief		リストが空である場合に，末尾コンストイテレータを取得した際のテスト
*	@details	ID:リスト-41\n
*				末尾コンストイテレータの取得機能のテストです.\n
*				リストが空である場合に，末尾コンストイテレータを取得した際の挙動を確認しています.\n
*				リスト末尾のダミーを指すコンストイテレータが返れば成功です．\n
*/
TEST(GetLastConstIteratorTest, WhenGetLastConstIteratorFromEmptyList) {
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator cItLast = list.getLastConstIterator();

	bool isEqual = (cItLast == list.getLastConstIterator());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		リストに要素が1つある場合に，末尾コンストイテレータを取得した際のテスト
*	@details	ID:リスト-42\n
*				末尾コンストイテレータの取得機能のテストです.\n
*				リストに要素が1つある場合に，末尾コンストイテレータを取得した際の挙動を確認しています.\n
*				リストの末尾要素を指すコンストイテレータが返れば成功です．\n
*/
TEST(GetLastConstIteratorTest, WhenGetLastConstIteratorFromListHavingAElement) {
	DoublyLinkedList list;
	createListHavingElements(list, 1);

	DoublyLinkedList::ConstIterator cItLastElement = list.getLastConstIterator();
	--cItLastElement;

	ScoreData lastElement("0", "test0");	//末尾要素
	bool isEqual = ((*cItLastElement) == lastElement);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		リストに2つ以上の要素がある場合に，末尾コンストイテレータを取得した際のテスト
*	@details	ID:リスト-43\n
*				末尾コンストイテレータの取得機能のテストです.\n
*				リストに2つ以上の要素がある場合に，末尾コンストイテレータを取得した際の挙動を確認しています.\n
*				リストの末尾要素を指すコンストイテレータが返れば成功です．\n
*/
TEST(GetLastConstIteratorTest, WhenGetLastConstIteratorFromListHavingElements) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);

	DoublyLinkedList::ConstIterator cItLastElement = list.getLastConstIterator();
	--cItLastElement;

	ScoreData lastElement("2", "test2");	//末尾要素
	bool isEqual = ((*cItLastElement) == lastElement);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		データ挿入を行った後に，末尾コンストイテレータを取得した際のテスト
*	@details	ID:リスト-44-1\n
*				末尾コンストイテレータの取得機能のテストです.\n
*				先頭要素の後方へデータ挿入行った後に，末尾コンストイテレータを取得した際の挙動を確認しています.\n
*				リストの末尾要素を指すコンストイテレータが返れば成功です．\n
*/
TEST(GetLastConstIteratorTest, WhenGetLastConstIteratorFromListInsertedElementBackOfFirstElement) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);

	DoublyLinkedList::ConstIterator cItLast = list.getLastConstIterator();	//挿入前の末尾ダミーを指すコンストイテレータ
	DoublyLinkedList::ConstIterator cItInsert = list.getFirstConstIterator();	//挿入場所を指すコンストイテレータ
	++cItInsert;	//後方へ移動

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(cItInsert, newScoreData));

	bool isEqual = (cItLast == list.getLastConstIterator());
	EXPECT_TRUE(isEqual);

}

/**
*	@brief		データ挿入を行った後に，末尾コンストイテレータを取得した際のテスト
*	@details	ID:リスト-44-2\n
*				末尾コンストイテレータの取得機能のテストです.\n
*				中央の要素の後方へデータ挿入行った後に，末尾コンストイテレータを取得した際の挙動を確認しています.\n
*				リストの末尾要素を指すコンストイテレータが返れば成功です．\n
*/
TEST(GetLastConstIteratorTest, WhenGetLastConstIteratorFromListInsertedElementBackOfCenterElement) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);

	DoublyLinkedList::ConstIterator cItLastElement = list.getLastConstIterator();	//挿入前の末尾ダミーを指すコンストイテレータ
	DoublyLinkedList::ConstIterator cItInsert = list.getFirstConstIterator();	//挿入場所を指すコンストイテレータ
	++cItInsert;	//中央の要素へ移動
	++cItInsert;	//後方へ移動

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(cItInsert, newScoreData));

	bool isEqual = (cItLastElement == list.getLastConstIterator());
	EXPECT_TRUE(isEqual);

}

/**
*	@brief		データ挿入を行った後に，末尾コンストイテレータを取得した際のテスト
*	@details	ID:リスト-44-3\n
*				末尾コンストイテレータの取得機能のテストです.\n
*				末尾要素の後方へデータ挿入行った後に，末尾コンストイテレータを取得した際の挙動を確認しています.\n
*				リストの末尾要素を指すコンストイテレータが返れば成功です．\n
*/
TEST(GetLastConstIteratorTest, WhenGetLastConstIteratorFromListInsertedElementBackOfLastElement) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);

	DoublyLinkedList::ConstIterator cItLast = list.getLastConstIterator();	//挿入前の末尾ダミーを指すコンストイテレータ
	DoublyLinkedList::ConstIterator cItInsert = list.getLastConstIterator();	//挿入場所を指すコンストイテレータ

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(cItInsert, newScoreData));

	bool isEqual = (cItLast == list.getLastConstIterator());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		データ削除を行った後に，末尾コンストイテレータを取得した際のテスト
*	@details	ID:リスト-45-1\n
*				末尾コンストイテレータの取得機能のテストです.\n
*				先頭要素の削除を行った後に，末尾コンストイテレータを取得した際の挙動を確認しています.\n
*				リストの末尾要素を指すコンストイテレータが返れば成功です．\n
*/
TEST(GetLastConstIteratorTest, WhenGetLastConstIteratorFromListRemovedFirstElement) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);

	DoublyLinkedList::ConstIterator cItLast = list.getLastConstIterator();	//削除前の末尾ダミーを指すコンストイテレータ
	DoublyLinkedList::ConstIterator cItRemove = list.getFirstConstIterator();	//削除場所を指すコンストイテレータ

	ASSERT_TRUE(list.remove(cItRemove));

	bool isEqual = (cItLast == list.getLastConstIterator());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		データ削除を行った後に，末尾コンストイテレータを取得した際のテスト
*	@details	ID:リスト-45-2\n
*				末尾コンストイテレータの取得機能のテストです.\n
*				中央の要素の削除を行った後に，末尾コンストイテレータを取得した際の挙動を確認しています.\n
*				リストの末尾要素を指すコンストイテレータが返れば成功です．\n
*/
TEST(GetLastConstIteratorTest, WhenGetLastConstIteratorFromListRemovedCenterElement) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);

	DoublyLinkedList::ConstIterator cItLastElement = list.getLastConstIterator();	//削除前の末尾ダミーを指すコンストイテレータ
	DoublyLinkedList::ConstIterator cItRemove = list.getFirstConstIterator();	//削除場所を指すコンストイテレータ
	++cItRemove;	//中央の要素へ移動

	ASSERT_TRUE(list.remove(cItRemove));

	bool isEqual = (cItLastElement == list.getLastConstIterator());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		データ削除を行った後に，末尾コンストイテレータを取得した際のテスト
*	@details	ID:リスト-45-3\n
*				末尾コンストイテレータの取得機能のテストです.\n
*				末尾要素の削除を行った後に，末尾コンストイテレータを取得した際の挙動を確認しています.\n
*				リストの末尾要素を指すコンストイテレータが返れば成功です．\n
*/
TEST(GetLastConstIteratorTest, WhenGetLastConstIteratorFromListRemovedLastElement) {
	DoublyLinkedList list;
	createListHavingElements(list, 3);

	DoublyLinkedList::ConstIterator cItLast = list.getLastConstIterator();	//削除前の末尾ダミーを指すコンストイテレータ
	DoublyLinkedList::ConstIterator cItRemove = list.getLastConstIterator();	//削除場所を指すコンストイテレータ
	--cItRemove;	//末尾要素へ移動

	ASSERT_TRUE(list.remove(cItRemove));

	bool isEqual = (cItLast == list.getLastConstIterator());
	EXPECT_TRUE(isEqual);
}


//=================================== イテレータの指す要素の取得 ===================================

/**
*	@brief		リストの参照がない状態で要素を取得した際のテスト
*	@details	ID:Iterator-0-1\n
*				イテレータの指す要素の取得機能のテストです.\n
*				リストの参照がない状態でイテレータの要素を参照した際の挙動を確認しています.\n
*				Assertが発生すれば成功です．\n
*/
TEST(GetElementOfIteratorTest, WhenIteratorHaveNotReferenceToList) {
	DoublyLinkedList::Iterator it;
	EXPECT_DEATH((*it), ".*");
}

/**
*	@brief		リストの参照がない状態で要素を取得した際のテスト
*	@details	ID:Iterator-0-2\n
*				コンストイテレータの指す要素の取得機能のテストです.\n
*				リストの参照がない状態でコンストイテレータの要素を参照した際の挙動を確認しています.\n
*				Assertが発生すれば成功です．\n
*/
TEST(GetElementOfIteratorTest, WhenConstIteratorHaveNotReferenceToList) {
	DoublyLinkedList::ConstIterator cIt;
	EXPECT_DEATH((*cIt), ".*");
}

/**
*	@brief		イテレータから取得した要素に対して，値の代入をした際のテスト
*	@details	ID:Iterator-1\n
*				イテレータの指す要素の取得機能のテストです.\n
*				イテレータから取得した要素に対して，値の代入をした際の挙動を確認しています.\n
*				値が変更されていれば成功です，\n
*/
TEST(GetElementOfIteratorTest, WhenAssignToElementOfIterator) {
	DoublyLinkedList list;
	createListHavingElements(list, 1);

	DoublyLinkedList::Iterator it = list.getFirstIterator();

	ScoreData newScoreData("100", "newData");
	*it = newScoreData;

	bool isEqual = ((*it) == newScoreData);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		空のリストの先頭イテレータの要素を取得した際のテスト
*	@details	ID:Iterator-3-1\n
*				イテレータの指す要素の取得機能のテストです.\n
*				空のリストの先頭イテレータの要素を取得した際の挙動を確認しています.\n
*				Assertが発生すれば成功です．\n
*/
TEST(GetElementOfIteratorTest, WhenGetElementOfFirstIteratorOfEmptyList) {
	DoublyLinkedList list;
	DoublyLinkedList::Iterator itFirst = list.getFirstIterator();
	EXPECT_DEATH((*itFirst), "Assertion failed.*");
}

/**
*	@brief		空のリストの先頭コンストイテレータの要素を取得した際のテスト
*	@details	ID:Iterator-3-2\n
*				イテレータの指す要素の取得機能のテストです.\n
*				空のリストの先頭コンストイテレータの要素を取得した際の挙動を確認しています.\n
*				Assertが発生すれば成功です．\n
*/
TEST(GetElementOfIteratorTest, WhenGetElementOfFirstConstIteratorOfEmptyList) {
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator cItFirst = list.getFirstConstIterator();
	EXPECT_DEATH((*cItFirst), "Assertion failed.*");
}

/**
*	@brief		末尾イテレータの要素を取得した際のテスト
*	@details	ID:Iterator-4-1\n
*				イテレータの指す要素の取得機能のテストです.\n
*				末尾イテレータの要素を取得した際の挙動を確認しています.\n
*				Assertが発生すれば成功です．\n
*/
TEST(GetElementOfIteratorTest, WhenGetElementOfLastIteratorOfEmptyList) {
	DoublyLinkedList list;
	DoublyLinkedList::Iterator itLast = list.getLastIterator();
	EXPECT_DEATH((*itLast), "Assertion failed.*");
}

/**
*	@brief		末尾コンストイテレータの要素を取得した際のテスト
*	@details	ID:Iterator-4-2\n
*				イテレータの指す要素の取得機能のテストです.\n
*				末尾コンストイテレータの要素を取得した際の挙動を確認しています.\n
*				Assertが発生すれば成功です．\n
*/
TEST(GetElementOfIteratorTest, WhenGetElementOfLastConstIteratorOfEmptyList) {
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator cItLast = list.getLastConstIterator();
	EXPECT_DEATH((*cItLast), "Assertion failed.*");
}


//=================================== イテレータをリスト末尾に向かって１つ進める ===================================

/**
*	@brief		リストの参照がない状態でイテレータをリスト末尾に向かって１つ進める際のテスト
*	@details	ID:Iterator-5-1\n
*				イテレータをリスト末尾に向かって１つ進める機能のテストです.\n
*				リストの参照がない状態でイテレータをリスト末尾に向かって１つ進める際の挙動を確認しています.\n
*				Assertが発生すれば成功です．\n
*/
TEST(IncrementIteratorTest, WhenIncrementIteratorHaveNotReferenceToList) {
	DoublyLinkedList::Iterator it;
	EXPECT_DEATH(++it, ".*");
}

/**
*	@brief		リストの参照がない状態でコンストイテレータをリスト末尾に向かって１つ進める際のテスト
*	@details	ID:Iterator-5-2\n
*				イテレータをリスト末尾に向かって１つ進める機能のテストです.\n
*				リストの参照がない状態でコンストイテレータをリスト末尾に向かって１つ進める際の挙動を確認しています.\n
*				Assertが発生すれば成功です．\n
*/
TEST(IncrementIteratorTest, WhenIncrementConstIteratorHaveNotReferenceToList) {
	DoublyLinkedList::ConstIterator cIt;
	EXPECT_DEATH(++cIt, ".*");
}

/**
*	@brief		リストが空の状態で先頭イテレータをリスト末尾に向かって１つ進める際のテスト
*	@details	ID:Iterator-6-1\n
*				イテレータをリスト末尾に向かって１つ進める機能のテストです.\n
*				リストが空の状態で先頭イテレータをリスト末尾に向かって１つ進める際の挙動を確認しています.\n
*				Assertが発生すれば成功です．\n
*/
TEST(IncrementIteratorTest, WhenIncrementFirstIteratorOfEmptyList) {
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.getFirstIterator();
	EXPECT_DEATH(++it, "Assertion failed.*");
}

/**
*	@brief		リストが空の状態で先頭コンストイテレータをリスト末尾に向かって１つ進める際のテスト
*	@details	ID:Iterator-6-2\n
*				イテレータをリスト末尾に向かって１つ進める機能のテストです.\n
*				リストが空の状態で先頭コンストイテレータをリスト末尾に向かって１つ進める際の挙動を確認しています.\n
*				Assertが発生すれば成功です．\n
*/
TEST(IncrementIteratorTest, WhenIncrementFirstConstIteratorOfEmptyList) {
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator cIt = list.getFirstConstIterator();
	EXPECT_DEATH(++cIt, "Assertion failed.*");
}

/**
*	@brief		末尾イテレータを後方へ1つ進める際のテスト
*	@details	ID:Iterator-7-1\n
*				イテレータを後方へ１つ進める機能のテストです.\n
*				末尾イテレータを後方へ１つ進める際の挙動を確認しています.\n
*				Assertが発生すれば成功です．\n
*/
TEST(IncrementIteratorTest, WhenIncrementLastIterator) {
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.getLastIterator();
	EXPECT_DEATH(++it, "Assertion failed.*");
}

/**
*	@brief		末尾コンストイテレータを後方へ1つ進める際のテスト
*	@details	ID:Iterator-7-2\n
*				イテレータを後方へ１つ進める機能のテストです.\n
*				末尾コンストイテレータを後方へ１つ進める際の挙動を確認しています.\n
*				Assertが発生すれば成功です．\n
*/
TEST(IncrementIteratorTest, WhenIncrementLastConstIterator) {
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator cIt = list.getLastConstIterator();
	EXPECT_DEATH(++cIt, "Assertion failed.*");
}

/**
*	@brief		2つ以上の要素があるリストに対し，イテレータを先頭から末尾まで移動する際のテスト
*	@details	ID:Iterator-8-1\n
*				イテレータをリスト末尾に向かって１つ進める機能のテストです.\n
*				2つ以上の要素があるリストに対し，イテレータを先頭から末尾まで移動する際の挙動を確認しています.\n
*				リストの各要素に格納された値が正しければ成功です．\n
*/
TEST(IncrementIteratorTest, WhenIncrementIteratorOnListHaveElements) {
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.getFirstIterator();
	
	ScoreData scoreData1("1", "test1");
	ScoreData scoreData2("2", "test2");
	ScoreData scoreData3("3", "test3");
	ScoreData scores[] = { scoreData1,scoreData2,scoreData3 };

	for (int i = 0; i < 3; i++) {
		list.insert(it, scores[i]);
	}

	DoublyLinkedList::Iterator itIncrement = list.getFirstIterator();	//先頭から末尾へ移動するイテレータ
	DoublyLinkedList::Iterator itLast = list.getLastIterator();

	int i = 0;
	while (itIncrement != itLast) {
		bool isEqual = ((*itIncrement) == scores[i]);
		EXPECT_TRUE(isEqual);
		itIncrement++;
		i++;
	}
}

/**
*	@brief		2つ以上の要素があるリストに対し，コンストイテレータを先頭から末尾まで移動する際のテスト
*	@details	ID:Iterator-8-2\n
*				イテレータをリスト末尾に向かって１つ進める機能のテストです.\n
*				2つ以上の要素があるリストに対し，コンストイテレータを先頭から末尾まで移動する際の挙動を確認しています.\n
*				リストの各要素に格納された値が正しければ成功です．\n
*/
TEST(IncrementIteratorTest, WhenIncrementConstIteratorOnListHaveElements) {
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.getFirstIterator();

	ScoreData scoreData1("1", "test1");
	ScoreData scoreData2("2", "test2");
	ScoreData scoreData3("3", "test3");
	ScoreData scores[] = { scoreData1,scoreData2,scoreData3 };

	for (int i = 0; i < 3; i++) {
		list.insert(it, scores[i]);
	}

	DoublyLinkedList::ConstIterator cItIncrement = list.getFirstConstIterator();	//先頭から末尾へ移動するコンストイテレータ
	DoublyLinkedList::ConstIterator cItLast = list.getLastConstIterator();

	int i = 0;
	while (cItIncrement != cItLast) {
		bool isEqual = ((*cItIncrement) == scores[i]);
		EXPECT_TRUE(isEqual);
		cItIncrement++;
		i++;
	}
}

/**
*	@brief		前置インクリメントを行った際のテスト
*	@details	ID:Iterator-9-1\n
*				イテレータをリスト末尾に向かって１つ進める機能のテストです.\n
*				イテレータに対して，前置インクリメントを行った際の挙動を確認しています.\n
*				インクリメント呼び出し時とインクリメント実行後での両方で，末尾ダミーを指していれば成功です．\n
*/
TEST(IncrementIteratorTest, WhenPrefixIncrementIterator) {
	DoublyLinkedList list;
	createListHavingElements(list, 1);

	DoublyLinkedList::Iterator itIncrement = list.getFirstIterator();
	DoublyLinkedList::Iterator itLast = list.getLastIterator();

	bool isEqualWhenIncrement = ((++itIncrement) == itLast);
	bool isEqualAfterIncrement = (itIncrement == itLast);

	EXPECT_TRUE(isEqualWhenIncrement == true && isEqualAfterIncrement == true);
}

/**
*	@brief		前置インクリメントを行った際のテスト
*	@details	ID:Iterator-9-2\n
*				イテレータをリスト末尾に向かって１つ進める機能のテストです.\n
*				コンストイテレータに対して，前置インクリメントを行った際の挙動を確認しています.\n
*				インクリメント呼び出し時とインクリメント実行後の両方で，末尾ダミーを指していれば成功です．\n
*/
TEST(IncrementIteratorTest, WhenPrefixIncrementConstIterator) {
	DoublyLinkedList list;
	createListHavingElements(list, 1);

	DoublyLinkedList::ConstIterator cItIncrement = list.getFirstConstIterator();
	DoublyLinkedList::ConstIterator cItLast = list.getLastConstIterator();

	bool isEqualWhenIncrement = ((++cItIncrement) == cItLast);
	bool isEqualAfterIncrement = (cItIncrement == cItLast);

	EXPECT_TRUE(isEqualWhenIncrement == true && isEqualAfterIncrement == true);
}

/**
*	@brief		後置インクリメントを行った際のテスト
*	@details	ID:Iterator-10-1\n
*				イテレータをリスト末尾に向かって１つ進める機能のテストです.\n
*				イテレータに対して，後置インクリメントを行った際の挙動を確認しています.\n
*				インクリメント呼び出し時は先頭要素を，インクリメント実行後は末尾ダミーを指していれば成功です．\n
*/
TEST(IncrementIteratorTest, WhenPostfixIncrementIterator) {
	DoublyLinkedList list;
	createListHavingElements(list, 1);

	DoublyLinkedList::Iterator itIncrement = list.getFirstIterator();
	DoublyLinkedList::Iterator itFirstElement = list.getFirstIterator();
	DoublyLinkedList::Iterator itLast = list.getLastIterator();

	bool isEqualWhenIncrement = ((itIncrement++) == itFirstElement);
	bool isEqualAfterIncrement = (itIncrement == itLast);

	EXPECT_TRUE(isEqualWhenIncrement == true && isEqualAfterIncrement == true);
}

/**
*	@brief		後置インクリメントを行った際のテスト
*	@details	ID:Iterator-10-2\n
*				イテレータをリスト末尾に向かって１つ進める機能のテストです.\n
*				コンストイテレータに対して，後置インクリメントを行った際の挙動を確認しています.\n
*				インクリメント呼び出し時は先頭要素を，インクリメント実行後は末尾ダミーを指していれば成功です．\n
*/
TEST(IncrementIteratorTest, WhenPostfixIncrementConstIterator) {
	DoublyLinkedList list;
	createListHavingElements(list, 1);

	DoublyLinkedList::ConstIterator cItIncrement = list.getFirstConstIterator();
	DoublyLinkedList::ConstIterator cItFirstElement = list.getFirstConstIterator();
	DoublyLinkedList::ConstIterator cItLast = list.getLastConstIterator();

	bool isEqualWhenIncrement = ((cItIncrement++) == cItFirstElement);
	bool isEqualAfterIncrement = (cItIncrement == cItLast);

	EXPECT_TRUE(isEqualWhenIncrement == true && isEqualAfterIncrement == true);
}

//=================================== イテレータをリスト先頭に向かって１つ進める ===================================

/**
*	@brief		リストの参照がない状態でイテレータをリスト先頭に向かって１つ進める際のテスト
*	@details	ID:Iterator-11-1\n
*				イテレータをリスト先頭に向かって１つ進める機能のテストです.\n
*				リストの参照がない状態でイテレータをリスト先頭に向かって１つ進める際の挙動を確認しています.\n
*				Assertが発生すれば成功です．\n
*/
TEST(DecrementIteratorTest, WhenDecrementIteratorHaveNotReferenceToList) {
	DoublyLinkedList::Iterator it;
	EXPECT_DEATH(--it, ".*");
}

/**
*	@brief		リストの参照がない状態でコンストイテレータをリスト先頭に向かって１つ進める際のテスト
*	@details	ID:Iterator-11-2\n
*				イテレータをリスト先頭に向かって１つ進める機能のテストです.\n
*				リストの参照がない状態でコンストイテレータをリスト先頭に向かって１つ進める際の挙動を確認しています.\n
*				Assertが発生すれば成功です．\n
*/
TEST(DecrementIteratorTest, WhenDecrementConstIteratorHaveNotReferenceToList) {
	DoublyLinkedList::ConstIterator cIt;
	EXPECT_DEATH(--cIt, ".*");
}

/**
*	@brief		リストが空の状態で末尾イテレータをリスト先頭に向かって１つ進める際のテスト
*	@details	ID:Iterator-12-1\n
*				イテレータをリスト先頭に向かって１つ進める機能のテストです.\n
*				リストが空の状態で末尾イテレータをリスト先頭に向かって１つ進める際の挙動を確認しています.\n
*				Assertが発生すれば成功です．\n
*/
TEST(DecrementIteratorTest, WhenDecrementLastIteratorOfEmptyList) {
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.getReverseLastIterator();
	EXPECT_DEATH(--it, "Assertion failed.*");
}

/**
*	@brief		リストが空の状態で末尾コンストイテレータをリスト先頭に向かって１つ進める際のテスト
*	@details	ID:Iterator-12-2\n
*				イテレータをリスト先頭に向かって１つ進める機能のテストです.\n
*				リストが空の状態で末尾コンストイテレータをリスト先頭に向かって１つ進める際の挙動を確認しています.\n
*				Assertが発生すれば成功です．\n
*/
TEST(DecrementIteratorTest, WhenDecrementLastConstIteratorOfEmptyList) {
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator cIt = list.getReverseLastConstIterator();
	EXPECT_DEATH(--cIt, "Assertion failed.*");
}

/**
*	@brief		先頭イテレータを前方へ1つ進める際のテスト
*	@details	ID:Iterator-13-1\n
*				イテレータを前方へ１つ進める機能のテストです.\n
*				先頭イテレータを前方へ１つ進める際の挙動を確認しています.\n
*				Assertが発生すれば成功です．\n
*/
TEST(DecrementIteratorTest, WhenDecrementFirstIterator) {
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.getReverseFirstIterator();
	EXPECT_DEATH(--it, "Assertion failed.*");
}

/**
*	@brief		先頭コンストイテレータを前方へ1つ進める際のテスト
*	@details	ID:Iterator-13-2\n
*				イテレータを前方へ１つ進める機能のテストです.\n
*				先頭コンストイテレータを前方へ１つ進める際の挙動を確認しています.\n
*				Assertが発生すれば成功です．\n
*/
TEST(DecrementIteratorTest, WhenDecrementFirstConstIterator) {
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator cIt = list.getReverseFirstConstIterator();
	EXPECT_DEATH(--cIt, "Assertion failed.*");
}

/**
*	@brief		2つ以上の要素があるリストに対し，イテレータ末尾から先頭まで移動する際のテスト
*	@details	ID:Iterator-14-1\n
*				イテレータをリスト先頭に向かって１つ進める機能のテストです.\n
*				2つ以上の要素があるリストに対し，イテレータを末尾から先頭まで移動する際の挙動を確認しています.\n
*				リストの各要素に格納された値が正しければ成功です．\n
*/
TEST(DecrementIteratorTest, WhenDecrementIteratorOnListHaveElements) {
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.getFirstIterator();

	ScoreData scoreData1("1", "test1");
	ScoreData scoreData2("2", "test2");
	ScoreData scoreData3("3", "test3");
	ScoreData scores[] = { scoreData1,scoreData2,scoreData3 };

	for (int i = 0; i < 3; i++) {
		list.insert(it, scores[i]);
	}

	DoublyLinkedList::Iterator itDecrement = list.getReverseFirstIterator();	//末尾から先頭へ移動するイテレータ

	int i = 2;
	while (itDecrement != list.getReverseLastIterator()) {
		bool isEqual = ((*itDecrement) == scores[i]);
		EXPECT_TRUE(isEqual);
		itDecrement--;
		i--;
	}
}

/**
*	@brief		2つ以上の要素があるリストに対し，コンストイテレータを末尾から先頭まで移動する際のテスト
*	@details	ID:Iterator-14-2\n
*				イテレータをリスト先頭に向かって１つ進める機能のテストです.\n
*				2つ以上の要素があるリストに対し，コンストイテレータを末尾から先頭まで移動する際の挙動を確認しています.\n
*				リストの各要素に格納された値が正しければ成功です．\n
*/
TEST(DecrementIteratorTest, WhenDecrementConstIteratorOnListHaveElements) {
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.getFirstIterator();

	ScoreData scoreData1("1", "test1");
	ScoreData scoreData2("2", "test2");
	ScoreData scoreData3("3", "test3");
	ScoreData scores[] = { scoreData1,scoreData2,scoreData3 };

	for (int i = 0; i < 3; i++) {
		list.insert(it, scores[i]);
	}

	DoublyLinkedList::ConstIterator cItDecrement = list.getReverseFirstConstIterator();	//末尾から先頭へ移動するコンストイテレータ

	int i = 2;
	while (cItDecrement != list.getReverseLastConstIterator()) {
		bool isEqual = ((*cItDecrement) == scores[i]);
		EXPECT_TRUE(isEqual);
		cItDecrement--;
		i--;
	}
}

/**
*	@brief		前置デクリメントを行った際のテスト
*	@details	ID:Iterator-15-1\n
*				イテレータをリスト先頭に向かって１つ進める機能のテストです.\n
*				イテレータに対して，前置デクリメントを行った際の挙動を確認しています.\n
*				デクリメント呼び出し時とデクリメント実行後での両方で，先頭ダミーを指していれば成功です．\n
*/
TEST(DecrementIteratorTest, WhenPrefixDecrementIterator) {
	DoublyLinkedList list;
	createListHavingElements(list, 1);

	DoublyLinkedList::Iterator itDecrement = list.getReverseFirstIterator();
	DoublyLinkedList::Iterator itFirst = list.getReverseLastIterator();

	bool isEqualWhenDecrement = ((--itDecrement) == itFirst);
	bool isEqualAfterDecrement = (itDecrement == itFirst);

	EXPECT_TRUE(isEqualAfterDecrement == true && isEqualAfterDecrement == true);
}

/**
*	@brief		前置デクリメントを行った際のテスト
*	@details	ID:Iterator-15-2\n
*				イテレータをリスト先頭に向かって１つ進める機能のテストです.\n
*				コンストイテレータに対して，前置デクリメントを行った際の挙動を確認しています.\n
*				デクリメント呼び出し時とデクリメント実行後の両方で，先頭ダミーを指していれば成功です．\n
*/
TEST(DecrementIteratorTest, WhenPrefixDecrementConstIterator) {
	DoublyLinkedList list;
	createListHavingElements(list, 1);

	DoublyLinkedList::ConstIterator cItDecrement = list.getReverseFirstConstIterator();
	DoublyLinkedList::ConstIterator cItFirst = list.getReverseLastConstIterator();

	bool isEqualWhenDecrement = ((--cItDecrement) == cItFirst);
	bool isEqualAfterDecrement = (cItDecrement == cItFirst);

	EXPECT_TRUE(isEqualAfterDecrement == true && isEqualAfterDecrement == true);
}

/**
*	@brief		後置デクリメントを行った際のテスト
*	@details	ID:Iterator-16-1\n
*				イテレータをリスト先頭に向かって１つ進める機能のテストです.\n
*				イテレータに対して，後置デクリメントを行った際の挙動を確認しています.\n
*				デクリメント呼び出し時は末尾要素を，デクリメント実行後は先頭ダミーを指していれば成功です．\n
*/
TEST(DecrementIteratorTest, WhenPostfixDecrementIterator) {
	DoublyLinkedList list;
	createListHavingElements(list, 1);

	DoublyLinkedList::Iterator itDecrement = list.getReverseFirstIterator();
	DoublyLinkedList::Iterator itLast = list.getReverseFirstIterator();
	DoublyLinkedList::Iterator itFirst = list.getReverseLastIterator();

	bool isEqualWhenDecrement = ((itDecrement--) == itLast);
	bool isEqualAfterDecrement = (itDecrement == itFirst);

	EXPECT_TRUE(isEqualWhenDecrement == true && isEqualAfterDecrement == true);
}

/**
*	@brief		後置デクリメントを行った際のテスト
*	@details	ID:Iterator-16-2\n
*				イテレータをリスト先頭に向かって１つ進める機能のテストです.\n
*				コンストイテレータに対して，後置デクリメントを行った際の挙動を確認しています.\n
*				デクリメント呼び出し時は末尾要素を，デクリメント実行後は先頭ダミーを指していれば成功です．\n
*/
TEST(DecrementIteratorTest, WhenPostfixDecrementConstIterator) {
	DoublyLinkedList list;
	createListHavingElements(list, 1);

	DoublyLinkedList::ConstIterator cItDecrement = list.getReverseFirstConstIterator();
	DoublyLinkedList::ConstIterator cItLast = list.getReverseFirstConstIterator();
	DoublyLinkedList::ConstIterator cItFirst = list.getReverseLastConstIterator();

	bool isEqualWhenDecrement = ((cItDecrement--) == cItLast);
	bool isEqualAfterDecrement = (cItDecrement == cItFirst);

	EXPECT_TRUE(isEqualWhenDecrement == true && isEqualAfterDecrement == true);
}


//=================================== イテレータのコピーを行う ===================================

/**
*	@brief		イテレータのコピーコンストラクタを呼び出した際のテスト
*	@details	ID:Iterator-18-1\n
*				イテレータのコピー機能のテストです.\n
*				コピーコンストラクタを呼び出した際の挙動を確認しています.\n
*				コピーコンストラクト後の値がコピー元と等しければ成功です．\n
*/
TEST(CopyIteratorTest, WhenCallIteratorCopyConstructor) {
	DoublyLinkedList list;
	createListHavingElements(list, 1);

	DoublyLinkedList::Iterator itFrom = list.getFirstIterator();
	DoublyLinkedList::Iterator itTo = itFrom;

	bool isEqual = ((*itFrom) == (*itTo));
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		コンストイテレータのコピーコンストラクタを呼び出した際のテスト
*	@details	ID:Iterator-18-2\n
*				イテレータのコピー機能のテストです.\n
*				コピーコンストラクタを呼び出した際の挙動を確認しています.\n
*				コピーコンストラクト後の値がコピー元と等しければ成功です．\n
*/
TEST(CopyIteratorTest, WhenCallConstIteratorCopyConstructor) {
	DoublyLinkedList list;
	createListHavingElements(list, 1);

	DoublyLinkedList::ConstIterator cItFrom = list.getFirstConstIterator();
	DoublyLinkedList::ConstIterator cItTo = cItFrom;

	bool isEqual = ((*cItFrom) == (*cItTo));
	EXPECT_TRUE(isEqual);
}


//=================================== イテレータの代入を行う ===================================

/**
*	@brief		イテレータへ代入した際のテスト
*	@details	ID:Iterator-20-1\n
*				イテレータの代入機能のテストです.\n
*				イテレータへ代入した際の挙動を確認しています.\n
*				代入後の値がコピー元と等しければ成功です．\n
*/
TEST(AssignIteratorTest, WhenAssignIterator) {
	DoublyLinkedList list;
	createListHavingElements(list, 1);

	DoublyLinkedList::Iterator itFrom = list.getFirstIterator();
	DoublyLinkedList::Iterator itTo;
	itTo = itFrom;

	bool isEqual = ((*itFrom) == (*itTo));
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		コンストイテレータへ代入した際のテスト
*	@details	ID:Iterator-20-2\n
*				イテレータの代入機能のテストです.\n
*				コンストイテレータへ代入した際の挙動を確認しています.\n
*				代入後の値がコピー元と等しければ成功です．\n
*/
TEST(AssignIteratorTest, WhenAssignConstIterator) {
	DoublyLinkedList list;
	createListHavingElements(list, 1);

	DoublyLinkedList::ConstIterator itFrom = list.getFirstConstIterator();
	DoublyLinkedList::ConstIterator itTo;
	itTo = itFrom;

	bool isEqual = ((*itFrom) == (*itTo));
	EXPECT_TRUE(isEqual);
}


//=================================== 2つのイテレータが同一のものか比較 ===================================

/**
*	@brief		リストが空の状態で先頭イテレータと末尾イテレータを比較した際のテスト
*	@details	ID:Iterator-21-1\n
*				2つのイテレータが同一のものか比較する機能のテストです.\n
*				リストが空の状態で先頭イテレータと末尾イテレータを比較した際の挙動を確認しています.\n
*				2つのイテレータが等しければ成功です．\n
*/
TEST(CompareTwoIteratorsIsSameTest, WhenCompareFirstAndLastIteratorsOfemptyListIsSame) {
	DoublyLinkedList list;
	DoublyLinkedList::Iterator itFirst = list.getFirstIterator();
	DoublyLinkedList::Iterator itLast = list.getLastIterator();

	bool isEqual = (itFirst == itLast);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		リストが空の状態で先頭コンストイテレータと末尾コンストイテレータを比較した際のテスト
*	@details	ID:Iterator-21-2\n
*				2つのイテレータが同一のものか比較する機能のテストです.\n
*				リストが空の状態で先頭コンストイテレータと末尾コンストイテレータを比較した際の挙動を確認しています.\n
*				2つのコンストイテレータが等しければ成功です．\n
*/
TEST(CompareTwoIteratorsIsSameTest, WhenCompareFirstAndLastConstIteratorsOfemptyListIsSame) {
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator cItFirst = list.getFirstConstIterator();
	DoublyLinkedList::ConstIterator cItLast = list.getLastConstIterator();

	bool isEqual = (cItFirst == cItLast);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		同一のイテレータを比較した際のテスト
*	@details	ID:Iterator-22-1\n
*				2つのイテレータが同一のものか比較する機能のテストです.\n
*				同一のイテレータを比較した際の挙動を確認しています.\n
*				2つのイテレータが等しければ成功です．\n
*/
TEST(CompareTwoIteratorsIsSameTest, WhenCompareSameIteratorsIsSame) {
	DoublyLinkedList list;
	createListHavingElements(list, 1);

	DoublyLinkedList::Iterator it = list.getFirstIterator();

	bool isEqual = (it == it);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		同一のコンストイテレータを比較した際のテスト
*	@details	ID:Iterator-22-2\n
*				2つのイテレータが同一のものか比較する機能のテストです.\n
*				同一のコンストイテレータを比較した際の挙動を確認しています.\n
*				2つのコンストイテレータが等しければ成功です．\n
*/
TEST(CompareTwoIteratorsIsSameTest, WhenCompareSameConstIteratorsIsSame) {
	DoublyLinkedList list;
	createListHavingElements(list, 1);

	DoublyLinkedList::ConstIterator cIt = list.getFirstConstIterator();

	bool isEqual = (cIt == cIt);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		異なるイテレータを比較した際のテスト
*	@details	ID:Iterator-23-1\n
*				2つのイテレータが同一のものか比較する機能のテストです.\n
*				異なるイテレータを比較した際の挙動を確認しています.\n
*				2つのイテレータが異なれば成功です．\n
*/
TEST(CompareTwoIteratorsIsSameTest, WhenCompareNotSameIteratorsIsSame) {
	DoublyLinkedList list;
	createListHavingElements(list, 2);

	DoublyLinkedList::Iterator itFirstElement = list.getFirstIterator();	//先頭要素を指すイテレータ
	DoublyLinkedList::Iterator itCenterElement = list.getFirstIterator();	//中央の要素を指すイテレータ
	++itCenterElement;	//中央の要素へ移動

	bool isEqual = (itFirstElement == itCenterElement);
	EXPECT_FALSE(isEqual);
}

/**
*	@brief		異なるコンストイテレータを比較した際のテスト
*	@details	ID:Iterator-23-2\n
*				2つのイテレータが同一のものか比較する機能のテストです.\n
*				異なるコンストイテレータを比較した際の挙動を確認しています.\n
*				2つのコンストイテレータが異なれば成功です．\n
*/
TEST(CompareTwoIteratorsIsSameTest, WhenCompareNotSameConstIteratorsIsSame) {
	DoublyLinkedList list;
	createListHavingElements(list, 2);

	DoublyLinkedList::ConstIterator cItFirstElement = list.getFirstConstIterator();		//先頭要素を指すコンストイテレータ
	DoublyLinkedList::ConstIterator cItCenterElement = list.getFirstConstIterator();	//中央の要素を指すコンストイテレータ
	++cItCenterElement;	//中央の要素へ移動

	bool isEqual = (cItFirstElement == cItCenterElement);
	EXPECT_FALSE(isEqual);
}

//=================================== 2つのイテレータが異なるものか比較 ===================================

/**
*	@brief		リストが空の状態で先頭イテレータと末尾イテレータを比較した際のテスト
*	@details	ID:Iterator-24-1\n
*				2つのイテレータが異なるものか比較する機能のテストです.\n
*				リストが空の状態で先頭イテレータと末尾イテレータを比較した際の挙動を確認しています.\n
*				2つのイテレータが等しければ成功です．\n
*/
TEST(CompareTwoIteratorsIsNotSameTest, WhenCompareFirstAndLastIteratorsOfemptyListIsNotSame) {
	DoublyLinkedList list;
	DoublyLinkedList::Iterator itFirst = list.getFirstIterator();
	DoublyLinkedList::Iterator itLast = list.getLastIterator();

	bool isEqual = (itFirst != itLast);
	EXPECT_FALSE(isEqual);	//先頭ダミーと末尾ダミーを指しているため異なってしまう
}

/**
*	@brief		リストが空の状態で先頭コンストイテレータと末尾コンストイテレータを比較した際のテスト
*	@details	ID:Iterator-24-2\n
*				2つのイテレータが異なるものか比較する機能のテストです.\n
*				リストが空の状態で先頭コンストイテレータと末尾コンストイテレータを比較した際の挙動を確認しています.\n
*				2つのコンストイテレータが等しければ成功です．\n
*/
TEST(CompareTwoIteratorsIsNotSameTest, WhenCompareFirstAndLastConstIteratorsOfemptyListIsNotSame) {
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator cItFirst = list.getFirstConstIterator();
	DoublyLinkedList::ConstIterator cItLast = list.getLastConstIterator();

	bool isEqual = (cItFirst != cItLast);
	EXPECT_FALSE(isEqual);	//先頭ダミーと末尾ダミーを指しているため異なってしまう
}

/**
*	@brief		同一のイテレータを比較した際のテスト
*	@details	ID:Iterator-25-1\n
*				2つのイテレータが異なるものか比較する機能のテストです.\n
*				同一のイテレータを比較した際の挙動を確認しています.\n
*				2つのイテレータが等しければ成功です．\n
*/
TEST(CompareTwoIteratorsIsNotSameTest, WhenCompareSameIteratorsIsNotSame) {
	DoublyLinkedList list;
	createListHavingElements(list, 1);

	DoublyLinkedList::Iterator it = list.getFirstIterator();

	bool isEqual = (it != it);
	EXPECT_FALSE(isEqual);
}

/**
*	@brief		同一のコンストイテレータを比較した際のテスト
*	@details	ID:Iterator-25-2\n
*				2つのイテレータが異なるものか比較する機能のテストです.\n
*				同一のコンストイテレータを比較した際の挙動を確認しています.\n
*				2つのコンストイテレータが等しければ成功です．\n
*/
TEST(CompareTwoIteratorsIsNotSameTest, WhenCompareSameConstIteratorsIsNotSame) {
	DoublyLinkedList list;
	createListHavingElements(list, 1);

	DoublyLinkedList::ConstIterator cIt = list.getFirstConstIterator();

	bool isEqual = (cIt != cIt);
	EXPECT_FALSE(isEqual);
}

/**
*	@brief		異なるイテレータを比較した際のテスト
*	@details	ID:Iterator-26-1\n
*				2つのイテレータが異なるものか比較する機能のテストです.\n
*				異なるイテレータを比較した際の挙動を確認しています.\n
*				2つのイテレータが異なれば成功です．\n
*/
TEST(CompareTwoIteratorsIsNotSameTest, WhenCompareNotSameIteratorsIsNotSame) {
	DoublyLinkedList list;
	createListHavingElements(list, 2);

	DoublyLinkedList::Iterator itFirstElement = list.getFirstIterator();	//先頭要素を指すイテレータ
	DoublyLinkedList::Iterator itCenterElement = list.getFirstIterator();	//中央の要素を指すイテレータ
	++itCenterElement;	//中央の要素へ移動

	bool isEqual = (itFirstElement != itCenterElement);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		異なるコンストイテレータを比較した際のテスト
*	@details	ID:Iterator-26-2\n
*				2つのイテレータが異なるものか比較する機能のテストです.\n
*				異なるコンストイテレータを比較した際の挙動を確認しています.\n
*				2つのコンストイテレータが異なれば成功です．\n
*/
TEST(CompareTwoIteratorsIsSameTest, WhenCompareNotSameConstIteratorsIsNotSame) {
	DoublyLinkedList list;
	createListHavingElements(list, 2);

	DoublyLinkedList::ConstIterator cItFirstElement = list.getFirstConstIterator();		//先頭要素を指すコンストイテレータ
	DoublyLinkedList::ConstIterator cItCenterElement = list.getFirstConstIterator();	//中央の要素を指すコンストイテレータ
	++cItCenterElement;	//中央の要素へ移動

	bool isEqual = (cItFirstElement != cItCenterElement);
	EXPECT_TRUE(isEqual);
}
