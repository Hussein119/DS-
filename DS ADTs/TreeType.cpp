#include"TreeNode.h"
#include"TreeType.h"
#include<iostream>
template <class ItemType>
bool TreeType<ItemType>::IsFull() const
// Returns true if the free store has no room for another node
// and false otherwise.
{
	TreeNode* location;
	try
	{
		location = new TreeNode;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}
template<class ItemType>
TreeType<ItemType>::TreeType()
{
	root = NULL; 
}
template<class ItemType>
TreeType<ItemType>::~TreeType()
// Calls recursive function Destroy to destroy the tree.
{
	Destroy(root);
}
template<class ItemType>
TreeType<ItemType>::TreeType(const TreeType& originalTree)
// Calls the recursive function CopyTree to copy originalTree
// into root.
{
	CopyTree(root, originalTree.root);
}
template<class ItemType>
void TreeType<ItemType>::operator=(TreeType& originalTree)
// Calls the recursive function CopyTree to copy originalTree
// into root.
{
	{
		if (&originalTree == this)
			return; // Ignore assigning self to self.
		Destroy(root); // Deallocate existing tree nodes.
		CopyTree(root, originalTree.root);
	}
}
template <class ItemType>
bool TreeType<ItemType>::IsEmpty() const
// Returns true if the tree is empty and false otherwise.
{
	return root == NULL;
}
template <class ItemType>
int TreeType<ItemType>::LengthIs() const
// Calls the recursive function CountNodes to count the
// nodes in the tree.
{
	return CountNodes(root);
}
template<class ItemType>
void TreeType<ItemType>::RetrieveItem(ItemType& item, bool& found) const
// Calls recursive function Retrieve to search the tree for item.
{
	Retrieve(root, item, found);
}
template<class ItemType>
void TreeType<ItemType>::InsertItem(ItemType item)
// Calls the recursive function Insert to insert item into tree.
{
	Insert(root, item);
}
template<class ItemType>
void TreeType<ItemType>::DeleteItem(ItemType item)
//Function Delete
//Definition: Removes someItem from tree where item equals someItem.
//Size: The number of nodes in the path from the root to the node to be deleted.
//Base Case: If item’s key matches key in Info(tree), delete node pointed to by tree.
//General Case: If item < Info(tree), Delete(Left(tree), item);else Delete(Right(tree), item).
// _____________________________________
// delete a node from BTS -> 2 children 
// replace the node you want to delete with 
// node minimum in right subtree , in order successor 
// Calls the recursive function Delete to delete item from tree.
{
	Delete(root, item);
}
template<class ItemType>
void TreeType<ItemType>::ResetTree(OrderType order)
// Calls a function to create a queue of the tree elements in
// the desired order.
{
	switch (order)
	{
	case PRE_ORDER: PreOrder(root, preQue);
		break;
	case IN_ORDER: InOrder(root, inQue);
		break;
	case POST_ORDER: PostOrder(root, postQue);
		break;
	}
}
template<class ItemType>
void TreeType<ItemType>::GetNextItem(ItemType& item, OrderType order, bool& finished)
// Returns the next item in the desired order.
// Post: For the desired order, item is the next item in the queue.
// If item is the last one in the queue, finished is true;
// otherwise, finished is false.
{
	finished = false;
	switch (order)
	{
	case PRE_ORDER: preQue.Dequeue(item);
		if (preQue.IsEmpty())
			finished = true;
		break;
	case IN_ORDER: inQue.Dequeue(item);
		if (inQue.IsEmpty())
			finished = true;
		break;
	case POST_ORDER: postQue.Dequeue(item);
		if (postQue.IsEmpty())
			finished = true;
		break;
	}
}
template<class ItemType>
void TreeType<ItemType>::Print() const
// Calls recursive function Print to print items in the tree.
{
	PrintTree(root);
}









