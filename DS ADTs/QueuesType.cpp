#include"QueuesType.h"
#include"NodeType.h"
#include<iostream>
template<class ItemType>
inline QueType<ItemType>::QueType()
{
	front = rear = NULL; 
}
template<class ItemType>
inline void QueType<ItemType>::MakeEmpty()
{
	if (IsEmpty())
		throw EmptyQueue();
	front = rear = NULL;
}
template<class ItemType>
inline bool QueType<ItemType>::IsEmpty() const
{
	return (front == rear == NULL) ;
}
template<class ItemType>
inline void QueType<ItemType>::Enqueue(ItemType item)
{
	NodeType<ItemType>* newItem;
	newItem->info = item; 
	if (IsEmpty()) {
		front = rear = newItem;
		size++;
	}
	rear->next = newItem; 
	rear = newItem;
	size++;
}
template<class ItemType>
inline void QueType<ItemType>::Dequeue()
{
	if (IsEmpty())
		throw EmptyQueue();
	if (front = rear)
		delete front; 
	front = rear = NULL; 
	size--;
	NodeType<ItemType>* temp = front; 
	front = front->next; 
	delete front; 
	size--;
}
template<class ItemType>
inline int QueType<ItemType>::length()
{
	return size;
}