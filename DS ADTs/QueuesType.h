#pragma once
#include"NodeType.h"
class EmptyQueue
	// Exception class used by Pop and Top when stack is empty.
{};
template<class ItemType>
class QueType
{
public:
	QueType(); 
	void MakeEmpty();
	bool IsEmpty() const;
	void Enqueue(ItemType item);
	void Dequeue();
	int length();
private:
	NodeType<ItemType>* front;
	NodeType<ItemType>* rear;
	int size = 0;
};


