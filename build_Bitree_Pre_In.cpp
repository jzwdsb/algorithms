//
// Created by manout on 17-3-20.
//

#include "common_use.h"
#include "BiNode.h"
/*
 * Given preorder and inorder traversal of a tree, construct the binary tree
 * 从先序遍历序列和中序遍历序列中还原二叉树的结构
 * 分析：
 *    利用二叉树的递归性质和中序先序的关系还原二叉树
 */

BiNode* build_tree(const vector<int>& pre_order,const vector<int>& in_order)
{
   return build(begin(pre_order), end(pre_order), begin(in_order), end(in_order));
}

template <typename It>
BiNode* build(It pre_first, It pre_last, It in_first, It in_last)
{
   if(pre_first == pre_last or in_first == in_last)
   {
      return nullptr;
   }

   BiNode* root = new BiNode(pre_first -> val);
   auto rootpos = find(in_first, in_last, *pre_first);
   auto left_size = distance(in_first, rootpos);

   root->left = build(next(pre_first), next(pre_first, left_size + 1), in_first, rootpos);
   root->right = build(next(pre_first, left_size + 1), pre_last, next(rootpos), in_last);
   return root;

}
