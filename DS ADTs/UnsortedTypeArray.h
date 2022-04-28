#pragma once
class NotFound {};
class Fulllist {};
class Emptylist {};
template<class ItemType>
class UnSortedTypeArray
{
public:
	UnSortedTypeArray();
	UnSortedTypeArray(int size);
	bool IsFull() const;
	bool IsEmpty() const;
	int LengthIs() const;
	bool IsFound(ItemType item) const;
	void InsertItem(ItemType item);
	void DeleteItem(ItemType item);
	void ResetList();
	void GetNextItem(ItemType& item);
private:
	int length;
	ItemType* info;
	int currentPos;
	int MAX_ITEMS;
};


