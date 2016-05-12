#include <iostream>
#include "BSTree.h"
using namespace std;

BSTree::BSTree(){
	root = NULL;
}


BSTree::Node* BSTree::CreateNode(int key_value){
            
            Node n = new Node();
            n->key_value = key_value;
            n->left = NULL;
            n->right = NULL;
            return n;
}

bool BSTree::insert(int val){

	return insertprivate(val, root);
}


bool BSTree::insertprivate(int val, Node* leaf){

	if(root == NULL)
	{
		root = CreateNode(val);
		return true;
	}
	else if(val < leaf->key_value)
	{
		if(leaf -> left != NULL)
		{
			return insertprivate(val,leaf->left);
		}
		else
		{
			return leaf->left = CreateNode(val);
		
		}
	}
	else if(val > leaf->key_value)
	{
		if(leaf -> right != NULL)
		{
			return insertprivate(val,leaf->right);
	
		}
		else
		{
			return leaf->right = CreateNode(val);
		}
	}
	else
	{
		cout<<"The key" << val << " has already been addes to the tree \n";
		return false;
	}
}

bool BSTree::find(int val){
	return findprivate(val, root);
}
bool BSTree::findprivate(int val, Node* leaf)
{
	if(root == NULL)
		return false;
	else if (val == this->key_value)
	{
		return true;
	}
    else if (val < this->key_value) 
    {
        if(leaf -> left != NULL)
        {
        	return findprivate(key_value, leaf->left);
        }
        else{
        	return false;
        }
    }
    else if (val > this->value) {

        if(leaf -> right != NULL)
        {
        	return findprivate(key_value, leaf->right);
        }
        else{
        	return false;
        }
	}
	else
	 return false;

}
bool BSTree::empty(){
	
	if(root == NULL)
		return true;
}

