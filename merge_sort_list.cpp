/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //初始化要有一个哨兵作为头部
        ListNode res(0);
        ListNode** result = &res.next;
        while(l1 not_eq NULL and l2 not_eq NULL){
            if(l1 -> val < l2 -> val){
                (*result) = new ListNode(l1 -> val);
                l1 = l1 -> next;
            }
            else{
                (*result) = new ListNode( l2-> val);
                l2 = l2 -> next;
            }
            if(l1 != NULL or l2 != NULL){
                (*result) -> next = new ListNode(0);
                result = &((*result) -> next);
            }
        }
        *result = l1 ? l1 : l2;
        return res.next;
    }
};
