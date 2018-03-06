//
// Created by manout on 18-3-4.
//

#ifndef ALOGRITHMS_RBTREE_H
#define ALOGRITHMS_RBTREE_H


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
    
    bool insert(key_refer key, value_refer value);
    void find(key_refer key);
    void remove(key_refer key);
    
private:
    enum Color
    {
        BLACK,RED
    };
    struct RBNode
    {
        Key key;
        Value value;
        Color color = BLACK;
        RBNode* parent = nullptr;
        RBNode* left = nullptr;
        RBNode* right = nullptr;
        
        RBNode* grandparent()
        {
            return this->parent->parent;
        }
        RBNode* uncle()
        {
            if (this->parent == grandparent()->left)
            {
                return grandparent()->right;
            }else
            {
                return grandparent()->left;
            }
        }
        RBNode(Key k, Value v):key(k), value(v){}
    };
    using node_pointer = RBNode*;
    void left_rotate(node_pointer node);
    void right_rotate(node_pointer node);
    void fix_up(node_pointer node);
private:
    static node_pointer nil = new RBNode(Key(), Value());
    
    RBNode* root;
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
bool RBTree<Key, Value>::insert(key_refer key, value_refer value)
{
    node_pointer curr_node = this->root;
    if (curr_node == nullptr)
    {
        this->root = new RBNode(key, value);
        this->root->left = nil;
        this->root->right = nil;
        this->root->color = Color::RED;
        return true;
    }
    while (curr_node->left not_eq nil and curr_node->right not_eq nil)
    {
        if (curr_node->key == key)
        {
            return false;
        }else if (curr_node->key < key)
        {
            curr_node = curr_node->right;
        }else if (curr_node->key > key)
        {
            curr_node = curr_node->left;
        }
    }
    if (curr_node->key == key)
    {
        return false;
    }else if (curr_node->key < key)
    {
        curr_node->right = new RBNode(key, value);
        curr_node->right->parent = curr_node;
        curr_node->right->left = curr_node->right = nil;
        curr_node->right->color = Color::RED;
        fix_up(curr_node->right);
        
    }else if (curr_node->key > key)
    {
        curr_node->left = new RBNode(key, value);
        curr_node->left ->parent = curr_node;
        curr_node->left->left = curr_node->right = nil;
        curr_node->left->color = Color::RED;
        fix_up(curr_node->left);
    }
   return true;
}

template<typename Key, typename Value>
void RBTree<Key, Value>::fix_up(RBTree::node_pointer node)
{
    /** case 1: the new node is the root*/
    if (node->parent == nullptr)
    {
        node->color = Color::BLACK;
        return;
    }
    /** case 2: the new node's parent node is black*/
    if (node->parent->color == Color::BLACK)
    {
        /** nothing to do*/
        return ;
    }
    /** case 3: the new node's parent and it's uncle is both red*/
    if (node->uncle() not_eq nullptr and node->uncle()->color == Color::RED)
    {
        node->parent->color = Color::BLACK;
        node->uncle()->color = Color::BLACK;
        node->grandparent()->color = Color::RED;
        fix_up(node->grandparent());
        return ;
    }
    /** case 4: the new node is a right node and it's parent is a left node*/
    if (node == node->parent->right and node->parent == node->grandparent()->left)
    {
        left_rotate(node->parent);
        node = node->left;
    }/** the new node is a left node and it's parent is a right node*/
    else if (node == node->parent->left and node->parent == node->grandparent()->right)
    {
        right_rotate(node->parent);
        node = node->right;
    }
    /** case 5: the new node's parent is red and it's uncle is black or missing, the new
     *          node is a left node and the it's parent is also a left node, do the left
     *          rotate to the grandparent node ,
     *          or the opposite,
     *          the new node is right node and it's parent is also a right node
     *          do the right rotate to the grandparent
     *          */
    node->parent->color = Color::BLACK;
    node->grandparent()->color = Color::RED;
    if (node == node->parent->left and node->parent == node->grandparent()->left)
    {
        right_rotate(node->grandparent());
    }else
    {
        left_rotate(node->grandparent());
    }
}


#endif //ALOGRITHMS_RBTREE_H
