#ifndef BSTree_H
#define BSTree_H

class BSTree
{
    private:
        class Node
        {
                int key_value;
                Node* left;
                Node* right;
        };
        Node* root;
        bool insertprivate(int val, Node *leaf);
        bool findprivate(int val, Node *leaf);

    public:
        BSTree();

        ~BSTree();
        Node* CreateNode(int key_value);
        bool insert(int val);
        bool find(int val);
        bool empty();
};

#endif