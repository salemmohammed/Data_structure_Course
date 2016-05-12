#include <iostream>
#include "BSTree.h"
#include "vector"
#include <cassert>

using namespace std;

BSTree::BSTree(){
    root = NULL;
}

// Copy-Constructor

BSTree::BSTree(const BSTree &toCopy){
    root = copyHelper(toCopy.root);
}


BSTree::Node* BSTree::copyHelper(const Node *toCopy){
    if (toCopy == NULL)
        return NULL;
    Node* preorder = new Node();
    preorder->key_value = toCopy->key_value;
    preorder->left = copyHelper(toCopy->left);
    preorder->right = copyHelper(toCopy->right);
    return preorder;
}

// Destructor
BSTree::~BSTree(){
    removesubtree(root);
}

void BSTree::removesubtree(Node* ptr)
{
    if(ptr != NULL)
    {
        if(ptr->left != NULL)
        {
            removesubtree(ptr->left);
        }
        if(ptr->right != NULL)
        {
            removesubtree(ptr->right);
        }
        // cout<<ptr->key_value;
        delete ptr;
    }
} 

BSTree::Node* BSTree::CreateNode(int key_value){
    Node* n = new Node();
    n->key_value = key_value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

bool BSTree::insert(int key_value){


    if(root == NULL)
    {
        root = CreateNode(key_value);
        return true;
    }


    return insertprivate(key_value, /*parent=*/root);
}


bool BSTree::insertprivate(int key_value, Node* parent)
{
    assert(root != NULL);


    ///now we want to insert the `key_value` under the `parent` node



    if(key_value < parent->key_value)
    {
      if(parent->left != NULL)
      {
          return insertprivate(key_value, parent->left);
      }
      else
      {
          ///in this case, the left IS null, therefore, we can just attach the new node to the left, and we are done.
          parent->left = CreateNode(key_value);
          return true;
      }
    }
    else if(key_value > parent->key_value)
    {
        if(parent->right != NULL)
        {
            return insertprivate(key_value,parent->right);

        }
        else
        {
            ///in this case, the right IS null, therefore, we can just attach the new node to the right, and we are done.
            parent->right = CreateNode(key_value);
        }
    }
    else
    {
        ///neither more than nor less than, is equal, no insertion possible, return false
        //cout<<"The key " << key_value << " has already been addes to the tree \n";
    }

    return false;

}


bool BSTree::find(int key_value){

    if (root == NULL)
      return false;

    return findprivate(key_value, root);
}

bool BSTree::findprivate(int key_value, Node* parent)
{
  
  assert(parent != NULL);

  if (key_value == parent->key_value)
    return true;

  if (key_value < parent->key_value) 
  {
    if(parent->left == NULL)
      return false;
    else
      return findprivate(key_value, parent->left);
  }
  else if (key_value > parent->key_value) {

    if(parent->right == NULL)
      return false;
    else
      return findprivate(key_value, parent->right);
  }

  return false;
}

bool BSTree::empty(){
    
    if(root == NULL)
        return true;
    else 
        return false;
}


/////////// i am not sure if we need it 

int BSTree::findsmallest(){
  assert(!empty());

  return findsmallestprivate(root);
}

int BSTree::findsmallestprivate(Node* node){
  assert(node != NULL);
  
  
  if(node->left != NULL)
  {
    return findsmallestprivate(node->left);
  } else{
    return node->key_value;
  }

}




bool BSTree::remove(int key_value) {
  if (root == NULL)
    return false;

  if (key_value == root->key_value)
  {
    root = removenode(root);
    return true;
  } else if (key_value < root->key_value) {
    return removevalue(key_value, /*parent=*/root, /*current=*/root->left);
  } else if (key_value > root->key_value) {
    return removevalue(key_value, /*parent=*/root, /*current=*/root->right);
  }
  return false;
}


BSTree::Node* BSTree::removenode(Node* current){

  assert(current != NULL);

  Node* left = current->left;
  Node* right = current->right;

  if (current->left == NULL)
  {

    delete current;
    return right;
  } else if (current->right == NULL) {
    ///     C
    ///    /
    ///   L
    ///  / \
    
    delete current;
    return left;
  } else {
    Node* next_min_node_parent = current;
    Node* next_min_node = right;
    while (next_min_node->left != NULL)
    {
      next_min_node_parent = next_min_node;
      next_min_node = next_min_node->left;
    }
    ///we know that next_min_node is the node with the next minimum value,
    /// AND that next_min_node_parent is the parent of `next_min_node`.

    ///sanity test
    assert(next_min_node_parent->left == next_min_node || next_min_node_parent->right == next_min_node);



    current->key_value = next_min_node->key_value;
    
    Node* replacement = removenode(next_min_node);
    
    if (next_min_node_parent->left == next_min_node)
    {
      next_min_node_parent->left = replacement;
    } else if (next_min_node_parent->right == next_min_node)
    {
      next_min_node_parent->right = replacement;
    }


    return current;
  }
}

bool BSTree::removevalue(int key_value, Node* parent, Node* current){

  ///if the parent is NULL, then we cannot fix the parent in the case where
  /// current is replaced by another node;
  /// and sometimes we MUST fix the parent.

  assert(parent != NULL);
  assert(parent->left == current || parent->right == current);

  if (current == NULL)
  {
    return false;
  }

  if (key_value < current->key_value)
  {
    if (current->left == NULL)
      return false;
    return removevalue(key_value, current, current->left);
  } else if (key_value > current->key_value) {
    if (current->right == NULL)
      return false;
    return removevalue(key_value, current, current->right);
  } else {
    ///current->key_value IS equal to key_value

    ///therefore, we must remove current

    Node* replacement = removenode(current);
    if (parent->left == current) {
      parent->left = replacement;
    } else if (parent->right == current) {
      parent->right = replacement;
    }

    return true;
  }
}

/*
bool BSTree::removevalue(int key_value, Node* parent, Node* current){

  if (current == NULL)
  {
    return false;
  }

  if (key_value < current->key_value)
  {
    if (current->left == NULL)
      return false;
    return removevalue(key_value, current->left);
  } else if (key_value > current->key_value) {
    if (current->right == NULL)
      return false;
    return removevalue(key_value, current->right);
  } else {
    ///current->key_value IS equal to key_value

    ///therefore, we must remove current

    Node* node_to_delete = current;

    if (current->left == NULL)
    {
      if (parent)
      {


        if (parent->left == current)
        {
          ///                  P
          ///                 /
          ///                C  
          ///                 \  
          ///                  R << no node on the left of Current
          /// 

          parent->left = current->right;
          ///                  P
          ///                 /
          ///                R
          /// 
        } else if (parent->right == current) {

          ///   P
          ///    \
          ///     C
          ///      \
          ///       R

          parent->right = current->right
          ///   P
          ///    \
          ///     R
        }
      }

      delete node_to_delete;
    } else if (current->right == NULL) {

      if (parent)
      {
        if (parent->left == current)
        {
          ///                  P
          ///                 /
          ///                C  
          ///               /   
          ///              L     << no node on the right of Current
          /// 

          parent->left = current->left;
          ///                  P
          ///                 /
          ///                L
          /// 
        } else if (parent->right == current) {
          parent->right = current->left;
        }
      }

      delete node_to_delete;
    } else {
      ///both current left and current right are NOT NULL

      int smallestinrightsubtree = findsmallestprivate(current->right);

      removevalue(smallestinrightsubtree, current, current->right);

      current->key_value = smallestinrightsubtree;
    }
  }
}
*/
/// not clear 

// bool BSTree::removeprivate(int num , Node* parent){

//   if (root->key_value == num) {
//     return removerootmatch();
//   }


//   if(num < parent->key_value && parent->left != NULL)
//   {
//     parent->left->key_value == num ?
//     removerootmatch(parent,parent->left,true):
//     removeprivate(num,parent->left);
//   }

//   else if(num > parent->key_value && parent->right != NULL)
//   {
//     parent->right->key_value == num ?
//     removerootmatch(parent,parent->right,false);
//     removeprivate(num,parent->right);
//   }
//   else
//     return false;
//   }

// }

// void BSTree::removerootmatch(){
//   if(root != NULL)
//   {
//     Node* delptr = root;
//     int rootkey = root->key_value;
    

//     // case 0-0
//     if(root->left == NULL && root -> right == NULL)
//     {
//       root = NULL;
//       delete delptr;
//     }
//     //case 1 - 1
//     else if(root->left == NULL && root -> right != NULL)
//     {
//       root = root->right;
//       delptr->right = NULL; // dis old root from tree
//       delete delptr;
//       cout<<"the root node with key "<< rootkey<<"was deleted"<<endl;

//     }

//     else if(root->left != NULL && root -> right == NULL)
//     {
//       root = root->left;
//       delptr->right = NULL; // dis old root from tree
//       delete delptr;
//       cout<<"the root node with key "<< rootkey<<"was deleted"<<endl;
      
//     }
//     // case 2- 2
//     else{
//       int smallestinrightsubtree = findsmallestprivate(root->right);
//       removeprivate(smallestinrightsubtree, root->right); // delete smalled value
//       root->key_value = smallestinrightsubtree;
//       cout<<"the root key containing key"<<rootkey<< "was overwriiten with key"<<root->key_value<<endl;
//     }
//   }
//   else 
//     return false;
// }

void BSTree::sortedArray(vector<int> &list){
  // do something
  sortedArrayprivate(root, list);
}

void BSTree::sortedArrayprivate(Node* ptr, vector<int>& list){
  // do something
  if(ptr == NULL)
      return;
  else
  {
    sortedArrayprivate(ptr->left, list);
    list.push_back( ptr->key_value );
    sortedArrayprivate(ptr->right, list);

  }
}

