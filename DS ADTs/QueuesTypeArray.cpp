#include"QueuesTypeArray.h"
template<class ItemType>
QueTypeArray<ItemType>::QueTypeArray(int max)
// Parameterized class constructor.
// Post: maxQue, front, and rear have been initialized.
// The array to hold the queue elements has been dynamically
// allocated.
{
	maxQue = max + 1;
	front = maxQue - 1;
	rear = maxQue - 1;
	items = new ItemType[maxQue];
}
template<class ItemType>
QueTypeArray<ItemType>::QueTypeArray() // Default class constructor.
// Post: maxQue, front, and rear have been initialized.
// The array to hold the queue elements has been dynamically
// allocated.
{
	maxQue = 501;
	front = maxQue - 1;
	rear = maxQue - 1;
	items = new ItemType[maxQue];
}
template<class ItemType>
QueTypeArray<ItemType>::~QueTypeArray() // Class destructor.
{
	delete[] items;
}
template<class ItemType>
void QueTypeArray<ItemType>::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
	front = maxQue - 1;
	rear = maxQue - 1;
	size = 0; 
}
template<class ItemType>
bool QueTypeArray<ItemType>::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
	return (rear == front);
}
template<class ItemType>
bool QueTypeArray<ItemType>::IsFull() const
// Returns true if the queue is full; false otherwise.
{
	return ((rear + 1) % maxQue == front);
}
template<class ItemType>
void QueTypeArray<ItemType>::Enqueue(ItemType newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
// otherwise, a FullQueue exception is thrown.
{
	if (IsFull())
		throw FullQueue();
	else
	{
		rear = (rear + 1) % maxQue;
		items[rear] = newItem;
	}
	size++;
}
template<class ItemType>
void QueTypeArray<ItemType>::Dequeue(ItemType& item)
// Post: If (queue is not empty) the front of the queue has been
// removed and a copy returned in item;
// otherwise, an EmptyQueue exception is thrown.
{
	if (IsEmpty())
		throw EmptyQueue();
	else
	{
		front = (front + 1) % maxQue;
		item = items[front];
	}
	size--;
}
template<class ItemType>
int QueTypeArray<ItemType>::length() { return size;  }
