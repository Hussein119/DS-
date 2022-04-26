#pragma once
class FullQueue
	// Exception class used by Push when stack is full.
{};
class EmptyQueue
	// Exception class used by Pop and Top when stack is empty.
{};
template<class ItemType>
class QueTypeArray
{
public:
	QueTypeArray(int max); // max is the size of the queue.
	QueTypeArray(); // Default size of 500.
	~QueTypeArray();
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	void Enqueue(ItemType item);
	void Dequeue(ItemType& item);
	int length();
private:
	int front;
	int rear;
	ItemType* items;
	int maxQue;
	int size = 0 ; 
};