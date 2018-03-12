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
    
    value_pointer find(key_refer key);
    bool insert(key_refer key, value_refer value);
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
        RBNode* grandparent();
        RBNode* uncle();
        RBNode* silbing();
        void relplace(RBNode* n);
        RBNode(Key k, Value v):key(k), value(v){}
    };
    using node_pointer = RBNode*;
    void left_rotate(node_pointer node);
    void right_rotate(node_pointer node);
    void fix_up(node_pointer node);
    node_pointer find_(key_refer key);
    void remove_(node_pointer node);
    node_pointer tree_max(node_pointer root);
    node_pointer tree_min(node_pointer root);
    
    void delete_case1(node_pointer node);
    void delete_case2(node_pointer node);
    void delete_case3(node_pointer node);
    void delete_case4(node_pointer node);
    void delete_case5(node_pointer node);
    void delete_case6(node_pointer node);
private:
    static node_pointer nil = new RBNode(Key(), Value());
    
    RBNode* root;
    int level;
    int count;
};

template<typename Key, typename Value>
RBTree::RBNode *RBTree<Key, Value>::RBNode::grandparent()
{
    return this->parent->parent;
}

template<typename Key, typename Value>
RBTree::RBNode *RBTree<Key, Value>::RBNode::uncle()
{
    {
        if (this->parent == grandparent()->left)
        {
            return grandparent()->right;
        }else
        {
            return grandparent()->left;
        }
    }
}

template<typename Key, typename Value>
RBTree::RBNode *RBTree<Key, Value>::RBNode::silbing()
{
    if (this == this->parent->left)
        return this->parent->right;
    return this->parent->left;
}

template<typename Key, typename Value>
void RBTree<Key, Value>::RBNode::relplace(RBTree::RBNode *n)
{
    if (this->parent not_eq nullptr)
    {
        n->parent = this->parent;
        if (this == this->parent->left)
        {
            this->parent->left = n;
        }else
        {
            this->parent->right = n;
        }
    }
}


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

template<typename Key, typename Value>
node_pointer RBTree<Key, Value>::find_(Key &key)
{
    node_pointer curr_node = this->root;
    while (curr_node->left not_eq nil and curr_node->right not_eq nil)
    {
        if (curr_node->key == key)
        {
            return curr_node;
        }
        if (curr_node->key < key)
        {
            curr_node = curr_node->right;
        }else
        {
            curr_node = curr_node->left;
        }
    }
    if (curr_node->left not_eq nil)
    {
        if (curr_node->left->key == key)
            return curr_node->left;
        else
            return nullptr;
    } else if (curr_node->right not_eq nil)
    {
        if (curr_node->right->key == key)
            return curr_node->right;
    }
    return nullptr;
}

template<typename Key, typename Value>
RBTree::value_pointer RBTree<Key, Value>::find(Key &key)
{
    return &find_(key)->value;
}

template<typename Key, typename Value>
void RBTree<Key, Value>::remove(Key &key)
{
    node_pointer node = find_(key);
    if (node == nullptr)return ;
    node_pointer max_node = tree_max(node);
    node->key = max_node->key;
    node->value = max_node->value;
    remove_(max_node);
}

template<typename Key, typename Value>
RBTree::node_pointer RBTree<Key, Value>::tree_max(RBTree::node_pointer root)
{
    while (root->right not_eq nil)
    {
        root = root->right;
    }
    return root;
}

template<typename Key, typename Value>
RBTree::node_pointer RBTree<Key, Value>::tree_min(RBTree::node_pointer root)
{
    while (root->left not_eq nil)
    {
        root = root->left;
    }
    return root;
}

template<typename Key, typename Value>
void RBTree<Key, Value>::remove_(RBTree::node_pointer node)
{
    /** the node must have one non null child*/
    node_pointer son = node->left == nil ? node->right : node->left;
    node->relplace(son);
    if (node->color == Color::BLACK)
    {
        if (son->color == Color::RED)
        {
            son->color = Color ::BLACK;
        }else
        {
            delete_case1(son);
        }
    }
    delete node;
}

template<typename Key, typename Value>
void RBTree<Key, Value>::delete_case1(RBTree::node_pointer node)
{
    /** case 1: the node is red, just delete it and return*/
    if (node->parent not_eq nullptr)
        delete_case2(node);
}

template<typename Key, typename Value>
void RBTree<Key, Value>::delete_case2(RBTree::node_pointer node)
{
    node_pointer sibling = node->silbing();
    if (sibling->color == Color::RED)
    {
        node->parent->color = Color ::RED;
        sibling->color = Color ::BLACK;
        if (node == node->parent->left)
        {
            left_rotate(node->parent);
        }else
        {
            right_rotate(node->parent);
        }
    }
    delete_case3(node);
}

template<typename Key, typename Value>
void RBTree<Key, Value>::delete_case3(RBTree::node_pointer node)
{
    node_pointer silbing = node->silbing();
    if (node->parent->color == BLACK
        and silbing->color == BLACK
        and silbing->left->color == BLACK
        and silbing->right->color == BLACK)
    {
        silbing->color = Color ::RED;
        delete_case1(node->parent);
    }else
    {
        delete_case4(node);
    }
}

template<typename Key, typename Value>
void RBTree<Key, Value>::delete_case4(RBTree::node_pointer node)
{
    node_pointer silbing = node->silbing();
    if (node->parent->color == RED
        and silbing->color == BLACK
        and silbing->left->color == BLACK
        and silbing->right->color == BLACK)
    {
        silbing->color = Color ::RED;
        node->parent->color = Color ::RED;
    }else
    {
        delete_case5(node);
    }
}

template<typename Key, typename Value>
void RBTree<Key, Value>::delete_case5(RBTree::node_pointer node)
{
    node_pointer sibling = node->silbing();
    if (sibling->color == RED)
    {
        if (node == node->parent->left
            and sibling->left->color == RED
            and sibling->right->color == BLACK)
        {
            sibling->color = RED;
            sibling->left->color = BLACK;
            right_rotate(sibling);
        }else if (node == node->parent->right
                  and sibling->left->color == BLACK
                  and sibling->right->color == RED)
        {
            sibling->color = RED;
            sibling->right->color = BLACK;
            left_rotate(sibling);
        }
    }
    delete_case6(node);
}

template<typename Key, typename Value>
void RBTree<Key, Value>::delete_case6(RBTree::node_pointer node)
{
    node_pointer sibling = node->silbing();
    sibling->color = node->parent->color;
    node->parent->color = BLACK;
    if (node == node->parent->left)
    {
        sibling->right->color = BLACK;
        left_rotate(node->parent);
    }else
    {
        sibling->left->color = BLACK;
        right_rotate(node->parent);
    }
}


#endif //ALOGRITHMS_RBTREE_H
