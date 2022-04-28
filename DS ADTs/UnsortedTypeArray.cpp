#include"UnSortedTypeArray.h"
template<class ItemType>
UnSortedTypeArray<ItemType>::UnSortedTypeArray() {
	MAX_ITEMS = 500;
	info = new ItemType[MAX_ITEMS];
	length = 0;
}
template<class ItemType>
UnSortedTypeArray<ItemType>::UnSortedTypeArray(int size) {
	MAX_ITEMS = size;
	info = new ItemType[MAX_ITEMS];
	length = 0;
}
template<class ItemType>
inline bool UnSortedTypeArray<ItemType>::IsFull() const {
	return (length == MAX_ITEMS);
}
template<class ItemType>
bool UnSortedTypeArray<ItemType>::IsEmpty() const {
	return length == 0;
}
template<class ItemType>
inline int UnSortedTypeArray<ItemType>::LengthIs() const {
	return length;
}
template<class ItemType>
bool UnSortedTypeArray<ItemType>::IsFound(ItemType item) const {
	bool found = false;
	for (int i = 0; i < length; i++) {
		if (info[i] == item)
			found = true;
	}
	return found;
}
template<class ItemType>
inline void UnSortedTypeArray<ItemType>::InsertItem(ItemType item) {
	if (IsFull())
		throw Fulllist();
	info[length++] = item;
	length++;
}
template<class ItemType>
inline void UnSortedTypeArray<ItemType>::DeleteItem(ItemType item) {
	if (IsEmpty())
		throw Emptylist();
	for (int i = 0; i < length; i++) {
		if (info[i] == item) {
			info[i] = info[length - 1];
		}
	}
	length--;
}
template<class ItemType>
inline void UnSortedTypeArray<ItemType>::ResetList() {
	currentPos = -1;
}
template<class ItemType>
inline void UnSortedTypeArray<ItemType>::GetNextItem(ItemType& item) {
	currentPos++;
	item = info[currentPos];
}