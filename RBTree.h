//
// Created by manout on 18-3-4.
//

#ifndef ALOGRITHMS_RBTREE_H
#define ALOGRITHMS_RBTREE_H

#include "RBNode.h"

template <typename Key, typename Value>
class RBTree
{
public :
    using key_type = Key;
    using key_refer = Key&;
    using const_key_refer = const Key&;
    using key_pointer = Key*;
    using const_key_pointer = const Key*;
    using value_type = Value;
    using value_refer = Value&;
    using const_value_refer = const Value&;
    using value_pointer = Value*;
    using const_value_pointer = const Value*;
    
    RBNode<Key, Value>* insert(RBNode<Key, Value>* node, key_refer key, value_refer value);
    void find(key_refer key);
    void remove(key_refer key);
    
private:
    using node_pointer = RBNode<Key, value_type>*;
    
    void left_rotate(node_pointer node);
    void right_rotate(node_pointer node);
    
private:
    static node_pointer nil = new RBNode<Key, Value>(Key(), Value());
    
    RBNode<Key , value_type>* root;
    int level;
    int count;
};

template<typename Key, typename Value>
void RBTree<Key, Value>::left_rotate(RBTree::node_pointer node)
{
    node_pointer y = node->right;
    node->right = y->left;
    if (y not_eq nil)
    {
        y->left->parent = node;
    }
    y->parent = node->parent;
    if (node->parent == nil)
    {
        this->root = y;
    }else if (node == node->parent->left)
    {
        node->parent->left = y;
    }else
    {
        node->parent->right = y;
    }
    y->left = node;
    node->parent = y;
}

template<typename Key, typename Value>
void RBTree<Key, Value>::right_rotate(RBTree::node_pointer node)
{
    node_pointer x = node->left;
    node->left = x->right;
    if (x not_eq nil)
    {
        x->right->parent = node;
    }
    x->parent = node->parent;
    if (x->parent == nil)
    {
        this->root = x;
    }else if (node == node->parent->right)
    {
        node->parent->right = x;
    }else
    {
        node->parent->left = x;
    }
    x->right = node;
    node->parent = x;
}

template<typename Key, typename Value>
RBNode<Key, Value>* RBTree<Key, Value>::insert(node_pointer node, key_refer key, value_refer value)
{
    if (node == nil)
    {
        node_pointer new_node = new RBNode(key, value);
        if ()
        return root;
    }else if (node->key == key)
    {
        return nullptr;
    }else if (node->key < key)
    {
        return insert(node->right, key, value);
    }else
    {
        return insert(node->left, key, value);
    }
}


#endif //ALOGRITHMS_RBTREE_H
