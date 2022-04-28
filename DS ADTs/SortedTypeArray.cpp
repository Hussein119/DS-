#include"SortedTypeArray.h"
template<class ItemType>
SortedTypeArray<ItemType>::SortedTypeArray() {
	MAX_ITEMS = 500; 
	info = new ItemType[MAX_ITEMS];
	length = 0; 
}
template<class ItemType>
SortedTypeArray<ItemType>::SortedTypeArray(int size) {
	MAX_ITEMS = size; 
	info = new ItemType[MAX_ITEMS];
	length = 0;
}
template<class ItemType>
inline bool SortedTypeArray<ItemType>::IsFull() const {
	return (length == MAX_ITEMS);
}
template<class ItemType>
bool SortedTypeArray<ItemType>::IsEmpty() const {
	return length == 0;
}
template<class ItemType>
inline int SortedTypeArray<ItemType>::LengthIs() const {
	return length;
}
template<class ItemType>
bool SortedTypeArray<ItemType>::IsFound(ItemType item) const {
	bool found = false; 
	for (int i = 0; i < length; i++) {
		if (info[i] == item)
			found = true; 
	}
	return found; 
}
template<class ItemType>
ItemType SortedTypeArray<ItemType>::RetrieveItem(int position) const {
	return info[position];
}
template<class ItemType>
int SortedTypeArray<ItemType>::GetPosition(ItemType item) const {
	if (IsFound(item)) {
		for (int i = 0; i < length; i++) {
			if (info[i] == item)
				return i;
		}
	}
	else
		throw NotFound();
}
template<class ItemType>
inline void SortedTypeArray<ItemType>::InsertItem(ItemType item) {
	if (IsFull())
		throw Fulllist();
	info[length++] = item;
	length++;
}
template<class ItemType>
inline void SortedTypeArray<ItemType>::DeleteItem(ItemType item) {
	if (IsEmpty())
		throw Emptylist();
	for (int i = 0; i < length; i++) {
		if (info[i] == item) {
			for (int j = i; j < length; j++)
				info[i] = info[i++];
		}
	}
	length--;
}
template<class ItemType>
inline void SortedTypeArray<ItemType>::ResetList() {
	currentPos = -1; 
}
template<class ItemType>
inline void SortedTypeArray<ItemType>::GetNextItem(ItemType& item) {
	currentPos++;
	item = info[currentPos];
}