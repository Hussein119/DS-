#pragma once
#include"TreeNode.h"
#include"QueuesType.h"
#include<iostream>
enum OrderType { PRE_ORDER, IN_ORDER, POST_ORDER };
template <class ItemType>
class TreeType {
public:
	TreeType(); // Constructor.
	//___________________________Destructor_______________________________________
	void Destroy(TreeNode*& tree)
		// Post: tree is empty; nodes have been deallocated.
	{
		if (tree != NULL)
		{
			Destroy(tree->left);
			Destroy(tree->right);
			delete tree;
		}
	}
	~TreeType(); // Destructor.
	//___________________________Copy constructor_________________________________________
	void CopyTree(TreeNode*& copy,const TreeNode* originalTree)
		// Post: copy is the root of a tree that is a duplicate
		// of originalTree.
	{
		if (originalTree == NULL)
			copy = NULL;
		else
		{
			copy = new TreeNode;
			copy->info = originalTree->info;
			CopyTree(copy->left, originalTree->left);
			CopyTree(copy->right, originalTree->right);
		}
	}
	TreeType(const TreeType& originalTree); // Copy constructor.
	//______________________________________________________________________________
	void operator = (TreeType& originalTree);
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	int CountNodes(TreeNode* tree)
		// Post: Returns the number of nodes in the tree.
	{
		if (tree == NULL)
			return 0;
		else
			return CountNodes(tree->left) + CountNodes(tree->right) + 1;
	}
	int LengthIs() const;
	//___________________________RetrieveItem_______________________________________
	void Retrieve(TreeNode* tree,ItemType& item, bool& found)
		// Recursively searches tree for item.
		// Post: If there is an element someItem whose key matches item's,
		// found is true and item is set to a copy of someItem;
		// otherwise, found is false and item is unchanged.
	{
		if (tree == NULL)
			found = false; // item is not found.
		else if (item < tree->info)
			Retrieve(tree->left, item, found); // Search left subtree.
		else if (item > tree->info)
			Retrieve(tree->right, item, found);// Search right subtree.
		else
		{
			item = tree->info; // item is found.
			found = true;
		}
	}
	void RetrieveItem(ItemType& item, bool& found) const;
	//___________________________InsertItem_______________________________________
	void Insert(TreeNode*& tree, ItemType item)
		// Inserts item into tree.
		// Post: item is in tree; search property is maintained.
	{
		if (tree == NULL)
		{// Insertion place found.
			tree = new TreeNode;
			tree->right = NULL;
			tree->left = NULL;
			tree->info = item;
		}
		else if (item < tree->info)
			Insert(tree->left, item); // Insert in left subtree.
		else
			Insert(tree->right, item); // Insert in right subtree.
	}
	void InsertItem(ItemType item);
	//___________________________DeleteItem________________________________________
	void Delete(TreeNode*& tree, ItemType item)
		// Deletes item from tree.
		// Post: item is not in tree.
	{
		if (item < tree->info)
			Delete(tree->left, item); // Look in left subtree.
		else if (item > tree->info)
			Delete(tree->right, item); // Look in right subtree.
		else
			DeleteNode(tree); // Node found; call DeleteNode.
	}
	void DeleteNode(TreeNode*& tree)
		// Deletes the node pointed to by tree.
		// Post: The user's data in the node pointed to by tree is no
		// longer in the tree. If tree is a leaf node or has only one
		// non-NULL child pointer, the node pointed to by tree is
		// deleted; otherwise, the user's data is replaced by its
		// logical predecessor and the predecessor's node is deleted.
	{
		ItemType data;
		TreeNode* tempPtr;
		tempPtr = tree;
		if (tree->left == NULL)
		{
			tree = tree->right;
			delete tempPtr;
		}
		else if (tree->right == NULL)
		{
			tree = tree->left;
			delete tempPtr;
		}
		else
		{
			GetPredecessor(tree->left, data);
			tree->info = data;
			Delete(tree->left, data); // Delete predecessor node.
		}
	}
	void GetPredecessor(TreeNode* tree, ItemType& data)
		// Sets data to the info member of the rightmost node in tree.
	{
		while (tree->right != NULL)
			tree = tree->right;
		    data = tree->info;
	}
	void DeleteItem(ItemType item);
	//____________________________________________________________________________
	void ResetTree(OrderType order);
	void GetNextItem(ItemType& item, OrderType order, bool& finished);
	//___________________________Print_______________________________________
	void PrintTree(TreeNode* tree)
		// Prints info member of items in tree in sorted order on outFile.
	{
		if (tree != NULL)
		{
			PrintTree(tree->left); // Print left subtree.
			cout << tree->info;
			PrintTree(tree->right); // Print right subtree.
		}
	}
	void Print() const;
	//____________________________________________________________________________
	void PreOrder(TreeNode* tree,QueType& preQue)
		// Post: preQue contains the tree items in preorder.
	{
		if (tree != NULL)
		{
			preQue.Enqueue(tree->info);
			PreOrder(tree->left, preQue);
			PreOrder(tree->right, preQue);
		}
	}
	void InOrder(TreeNode* tree,QueType& inQue)
		// Post: inQue contains the tree items in inorder.
	{
		if (tree != NULL)
		{
			InOrder(tree->left, inQue);
			inQue.Enqueue(tree->info);
			InOrder(tree->right, inQue);
		}
	}
	void PostOrder(TreeNode* tree,QueType& postQue)
		// Post: postQue contains the tree items in postorder.
	{
		if (tree != NULL)
		{
			PostOrder(tree->left, postQue);
			PostOrder(tree->right, postQue);
			postQue.Enqueue(tree->info);
		}
	}

private:
	TreeNode* root; 
	QueType preQue;
	QueType inQue;
	QueType postQue;
};