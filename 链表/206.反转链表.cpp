/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){

    if(head == NULL)
    {
        return NULL;
    }
    else
    {
        struct ListNode* cur = NULL;
        while(head)
        {
            struct ListNode* next = head->next;
            head->next = cur;
            cur = head;
            head = next;
        }
        return cur;
    }

}
