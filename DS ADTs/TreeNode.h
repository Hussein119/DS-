#pragma once
template <class ItemType>
struct TreeNode
{ 
	ItemType info;
	TreeNode<ItemType>* left;
	TreeNode<ItemType>* right;
};

