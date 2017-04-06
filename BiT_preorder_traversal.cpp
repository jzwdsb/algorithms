//
// Created by manout on 17-4-6.
//

#include "common_use.h"
#include "Bi_node.h"
/*
 *      Given a binary tree, return the preorder traversal of its nodes' values;
 */


void preorder_traversal(TreeNode* root, vector<int>& ret){
    if(not root)
        return;
    ret.push_back(root->val);
    preorder_traversal(root->left, ret);
    preorder_traversal(root->right, ret);
}

vector<int> preorder_traversal(TreeNode* root)
{
    vector<int> ret;
    stack<TreeNode*> path;
    if(root)    path.push(root);
    while(not path.empty())
    {
        const TreeNode* curr_node = path.top();
        path.pop();
        ret.push_back(curr_node->val);
        if(curr_node->left)path.push(curr_node->left);
        if(curr_node->right)path.push(curr_node->right);
    }
    return ret;
}