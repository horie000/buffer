#define MAX_LIST_SIZE 10
typedef struct ListNode_t
{
    bool isEmpty;
    int data;
    struct ListNode_t *next;
    struct ListNode_t *prev;
} ListNode;

void initListNode(ListNode *root);
ListNode *getEmptListNode(ListNode *root);
void createNewList(ListNode *root);
bool pushBack(ListNode *begin, int val);
bool insert(ListNode *begin, int val, int ind);
bool remove(ListNode *begin, int ind);
void printList(ListNode *begin);
void printMem(ListNode *root);