#include"StackTypeArray.h"
template<class ItemType>
StackTypeArray<ItemType>::StackTypeArray(int size) {
	items = new ItemType[size];
	Stackcapacity = size;
	top = -1;
}
template<class ItemType>
StackTypeArray<ItemType>::StackTypeArray() {
	items = new ItemType[MAX_ITEMS];
	Stackcapacity = MAX_ITEMS;
	top = -1;
}
template<class ItemType>
StackTypeArray<ItemType>::~StackTypeArray() {
	delete[] items;
}
template<class ItemType>
bool StackTypeArray<ItemType>::IsEmpty() const {
	return (top == -1);
}
template<class ItemType>
bool StackTypeArray<ItemType>::IsFull() const {
	return (top == MAX_ITEMS - 1);
}
template<class ItemType>
void StackTypeArray<ItemType>::Push(ItemType newItem) {
	if (IsFull())
		throw FullStack();
	top++;
	items[top] = newItem;
}
template<class ItemType>
void StackTypeArray<ItemType>::Pop() {
	if (IsEmpty())
		throw EmptyStack();
	top--;
}
template<class ItemType>
ItemType StackTypeArray<ItemType>::Top() const {
	if (IsEmpty())
		throw EmptyStack();
	return items[top];
}