#pragma once
const int MAX_ITEMS = 5;
template<class ItemType>
class UnsortedTypeArray
{
public:
	UnsortedTypeArray();
	bool IsFull() const;
	int LengthIs() const;
	void RetrieveItem(ItemType& item, bool& found);
	void InsertItem(ItemType item);
	void DeleteItem(ItemType item);
	void ResetList();
	void GetNextItem(ItemType& item);
private:
	int length;
	ItemType info[MAX_ITEMS];
	int currentPos;
};


