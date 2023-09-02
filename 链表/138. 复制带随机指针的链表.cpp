/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {

    struct Node* cur = head;

    // 复制每一个节点
    while(cur)
    {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;   // 复制值
        copy->random = NULL;
        copy->next = cur->next;
        cur->next = copy;

        cur = copy->next;
    }

    // 复制random指针
    cur = head;
    while(cur)
    {
        struct Node* copynode = cur->next;
        if(cur->random == NULL)
        {
            copynode->random = NULL;
        }
        else
        {
            copynode->random = cur->random->next;
        }
        cur = copynode->next;
    }

    // 拆解指针及复原原指针
    cur = head;
    struct Node* phead = NULL;
    struct Node* ptail = NULL;

    while(cur)
    {
        struct Node* Copy = cur->next;
        struct Node* next = Copy->next;
        if(phead == NULL)
        {
            phead = ptail = Copy;
        }
        else
        {
            ptail->next = Copy;
            ptail = ptail->next;
        }
        cur->next = next;            // 复原原指针(head)
        cur = next;
    }
  
    return phead;
}
