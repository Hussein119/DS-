#pragma once
class FullStack
	// Exception class used by Push when stack is full.
{};
class EmptyStack
	// Exception class used by Pop and Top when stack is empty.
{};
#define MAX_ITEMS 500
template<class ItemType>
class StackTypeArray
{
public:
	StackTypeArray(int size);
	StackTypeArray();
	~StackTypeArray();
	bool IsEmpty() const;
	bool IsFull() const;
	void Push(ItemType item);
	void Pop();
	ItemType Top() const;
private:
	int top;
	int Stackcapacity;
	ItemType* items;
};