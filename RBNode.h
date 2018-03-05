//
// Created by manout on 18-3-4.
//

#ifndef ALOGRITHMS_RBNODE_H
#define ALOGRITHMS_RBNODE_H

template <typename Key, typename Value>
struct RBNode
{
    static const bool RED = true;
    static const bool BLACK = false;
    Key key;
    Value value;
    bool color = BLACK;
    RBNode* parent = nullptr;
    RBNode* left = nullptr;
    RBNode* right = nullptr;
    
    RBNode* grandparent();
    RBNode* uncle();
    RBNode(Key k, Value v):key(k), value(v){}
};

template<typename Key, typename Value>
RBNode *RBNode<Key, Value>::grandparent()
{
    return this->parent->parent;
}

template<typename Key, typename Value>
RBNode *RBNode<Key, Value>::uncle()
{
    if (this->parent == grandparent()->left)
    {
        return grandparent()->right;
    }else
    {
        return grandparent()->left;
    }
}

#endif //ALOGRITHMS_RBNODE_H
