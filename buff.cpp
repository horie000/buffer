#include "buff.h"
#include <iostream>

void initListNode(ListNode *root)
{
    for (int ii = 0; ii < MAX_LIST_SIZE; ii++)
    {
        root[ii].isEmpty = true;
        root[ii].data = ii;
    }
}

ListNode *getEmptListNode(ListNode *root)
{
    for (int ii = 0; ii < MAX_LIST_SIZE; ii++)
    {
        if (root[ii].isEmpty == true)
        {
            //std::cout << "find empty node at ind["<<ii<<"]" << std::endl;
            (&root[ii])->isEmpty = false;
            return &root[ii];
        }
        else
        {
            // do nothing
        }
    }
    std::cout<<"cant find empty node"<<std::endl;
    return nullptr;
}

void createNewList(ListNode *root)
{
    ListNode *begin = nullptr;
    ListNode *end = nullptr;
    begin = getEmptListNode(root);
    if(begin == nullptr){return;}   
    end = getEmptListNode(root);
    if(end == nullptr){return;}

    begin->next = end;
    begin->prev = end;
    begin->data = 11;
    end->next = nullptr;
    end->prev = begin;
    end->data = 22;
}

bool pushBack(ListNode *begin, int val)
{
    
    ListNode* it = nullptr;
    for (it = begin; it->next->next != nullptr; it = it->next){}
        ListNode *new_node = getEmptListNode(begin);
        if(new_node == nullptr){return false;}
        new_node->data = val;
        new_node->next = it->next;
        new_node->prev = it;

        it->next = new_node;
        return true;
}

bool insert(ListNode *begin, int val, int ind)
{
    int ii = 0;
    for(ListNode* it = begin; it ->next != nullptr; it = it->next){
        if(ii == ind ){
            ListNode* new_node = getEmptListNode(begin);
            if(new_node == nullptr){return false;}
            new_node->data = val;
            new_node->next = it->next;
            it->next = new_node;
            return true;
        }else{
            ii++;
        }
    }
    return false;
}

bool remove(ListNode *begin, int ind)
{
    int ii = 0;
    for(ListNode* it = begin; it ->next != nullptr; it = it->next){
        if(ii == ind ){
            it->next->isEmpty = true;
            it->next = it->next->next;
            it->next->prev = it;
            return true;
        }else{
            ii++;
        }
    }
    return false;
}

void printList(ListNode *begin)
{
    // for (int ii = 0; ii < MAX_LIST_SIZE; ii++)
    // {
    //     std::cout << ii << " : " << begin[ii].isEmpty << "/ data : " << begin[ii].data << std::endl;
    // }
    ListNode* it = begin->next;
    while(it->next  != nullptr){
        std::cout << it->isEmpty << "/ data : " << it->data << std::endl;
        //std::cout << "addr : " << &it << std::endl;
        it  = it->next;
    }
}

void printMem(ListNode *root)
{
    for (int ii = 0; ii < MAX_LIST_SIZE; ii++)
    {
        std::cout << ii << " : " << &root[ii] << "/ data : " << root[ii].data <<"/ next : "<<root[ii].next<< std::endl;
    }
}

int main()
{
    ListNode list[10] = {};
    initListNode(list);
    createNewList(list);
    if(!pushBack(list, 55)){std::cout<<"cant add list"<<std::endl;}
    if(!pushBack(list, 66)){std::cout<<"cant add list"<<std::endl;}
    if(!pushBack(list, 77)){std::cout<<"cant add list"<<std::endl;}
    if(!insert(list, 99, 2)){std::cout<<"cant ins list"<<std::endl;}
    if(!insert(list, 111, 0)){std::cout<<"cant ins list"<<std::endl;}
    printList(list);
    std::cout<<"------------------------"<<std::endl;
    if(!remove(list, 3)){std::cout<<"cant remove list"<<std::endl;}
    printList(list);
    //printMem(list);
}