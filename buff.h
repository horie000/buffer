#define MAX_LIST_SIZE 10
typedef struct ListNode_t
{
    bool isEmpty;
    int data;
    struct ListNode_t *next;
    struct ListNode_t *prev;
} ListNode;