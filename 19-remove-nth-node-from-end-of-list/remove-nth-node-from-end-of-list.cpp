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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        // 1 Move fast pointer n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        
        // 2 If fast reached the end, the nth node from the end is the head itself
        if (fast == nullptr) {
            ListNode* newHead = head->next;
            delete head; // Use delete instead of free for objects allocated via new
            return newHead;
        }
        
        // 3. Move both pointers until fast reaches the last node
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // 4. slow->next is now the node to delete
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode; 
        
        return head;
    }
};
