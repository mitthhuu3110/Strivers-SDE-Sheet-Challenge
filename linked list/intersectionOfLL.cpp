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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> ump;
        while(headA || headB){
            if(headA){
                if(ump[headA]++) return headA;
                headA = headA -> next;
            }
            if(headB){
                if(ump[headB]++) return headB;
                headB = headB -> next;
            }
        }
        return NULL;
    }
};
