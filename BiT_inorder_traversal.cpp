//
// Created by manout on 17-4-6.
//

#include "common_use.h"
#include "BiNode.h"
/*
 *      inorder traversal a BiT
 */

using TreeNode = BiNode;

void inorder_traversal(TreeNode* root, vector<int>& ret)
{
    if(not root)return;
    inorder_traversal(root->left, ret);
    ret.push_back(root->val);
    inorder_traversal(root->right, ret);
}

vector<int> inorder_traversal_(TreeNode* root)
{
    vector<int> ret;
    stack<TreeNode*> path;
    const TreeNode* p = root;
    if(not root)return ret;
    while(not path.empty() or root not_eq nullptr)
    {
        if(root not_eq nullptr)
        {
            path.push(root);
            root = root->left;
        }
        else{
            root = path.top();
            path.pop();
            ret.push_back(root->val);
            root = root->right;
        }
    }
    return ret;
}