/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //base case 
        if( list1== nullptr || list2 == nullptr){
            return list1== nullptr ? list2:list1 ;
        }
        //case1 when h1<h2
        if( list1->val <= list2->val) {
            list1->next = mergeTwoLists( list1->next , list2) ;
            return list1;
        }

        //case2 when h1>h2
        else{
            list2->next = mergeTwoLists( list1 , list2->next) ;
            return list2 ;
        }
    }
};