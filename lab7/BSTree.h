#ifndef BSTree_H
#define BSTree_H
#include "vector"



class BSTree
{
    private:
        class Node
        {
                friend class BSTree;
                int key_value;
                Node* left;
                Node* right;
        };
        Node* root;
        bool insertprivate(int val, Node* parent);
        bool findprivate(int val, Node *leaf);
        Node* CreateNode(int key_value);

        ///Note that parent must not be NULL
        bool removevalue(int num, Node* parent, Node* current);
        ///removes a node in the case where it has two children
        ///returns the new root of this subtree
        Node* removenode(Node* current);

        int findsmallestprivate(Node* ptr);
        void removesubtree(Node* ptr);
        void sortedArrayprivate(Node* ptr, std::vector<int> &list);
        Node* copyHelper(const Node*); //The recursive helper
        int findsmallest();


    public:
        BSTree();
        BSTree(const BSTree& other);
        ~BSTree();
        bool insert(int val);
        bool find(int val);
        bool empty();
        bool remove(int num); // remove node
        void sortedArray(std::vector<int> &list);

};

#endif