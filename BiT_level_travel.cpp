//
// Created by manout on 17-3-20.
//

#include "common_use.h"
#include "BiNode.h"

/*
 * 二叉树的广度优先遍历递归实现
 */

vector<vector<int>> BiT_level_travel(BiNode* root)
{
    vector<vector<int>> ret;
    BiT_level_travel_(root, 1, ret);
    return ret;
}

void  traverse(BiNode *root, int level, vector<vector<int>> &ret)
{
    if (not root)return;
    if(level > ret.size())
    {
        ret.push_back(vector<int>());
    }
    ret[level - 1].push_back(root->val);
    traverse(root->left, level + 1, ret);
    traverse(root->right, level + 1, ret);
}
