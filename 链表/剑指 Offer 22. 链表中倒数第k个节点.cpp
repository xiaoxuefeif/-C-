/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 快慢指针
struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while(k)
    {
        if(fast == NULL)
        {
            return NULL;
        }
        fast = fast->next;
        k--;
    }

    while(fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
