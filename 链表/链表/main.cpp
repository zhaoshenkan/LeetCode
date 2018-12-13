//
//  main.cpp
//  从尾到头打印链表
//
//  Created by 赵申侃 on 2018/12/3.
//  Copyright © 2018 赵申侃. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode
{
    int m_nKey;
    ListNode *m_pNext;
};
//虽然我们写程序的人知道head是一个指针，但是在编译器看来它就是一个值而已（只是这个值恰巧是指针），那么在AddToTail函数中对head进行赋值操作，肯定不会对函数外的head产生任何影响。只有把&head作为实参传递进AddToTail去，然后在函数中对*head作赋值操作，才会对函数外的head产生影响

// 链表的末尾中增加一个节点
void AddToTail(ListNode ** pHead,int value) {
    
    ListNode *node = new ListNode;
    node -> m_nKey = value;
    node -> m_pNext = NULL;
    
    if (*pHead == NULL) {
        *pHead = node;
    } else {
        ListNode *node1 = *pHead;
        //遍历到末尾节点
        while (node1 -> m_pNext != NULL) {
            node1 = node1 -> m_pNext;
        }
        node1 -> m_pNext = node;
    }
}

//找到某个值得节点并删除
void removeNode(ListNode ** phead, int value){
    
    if (*phead == NULL || phead == NULL) {
        return;
    }
    
    ListNode *deleteNode = NULL;
    if ( (*phead) -> m_nKey == value) {
        deleteNode = (*phead);
        *phead = (*phead) -> m_pNext;
    } else {
        ListNode *node = *phead;
        //向下遍历节点 并且当下个节点的值不等于value 递归找到该值得节点
        while ( node -> m_pNext != NULL && node -> m_pNext ->m_nKey != value) {
            node = node -> m_pNext;
        }
        if (node ->m_pNext != NULL && node ->m_pNext ->m_nKey == value) {
            deleteNode = node -> m_pNext;
            node -> m_pNext = node -> m_pNext -> m_pNext;
        }
    }
    delete deleteNode;
    deleteNode = NULL;
}

//O(1)时间删除节点
void deleteNode(ListNode **phead,ListNode *deleteNode){
    
    if (*phead == NULL || deleteNode == NULL) {
        return;
    }
    ListNode *headnode = *phead;
    if (headnode ->m_nKey == deleteNode -> m_nKey) { //删除的节点是头节点
        headnode -> m_pNext = NULL;
        delete deleteNode;
        deleteNode = NULL;
    } else if(deleteNode -> m_pNext != NULL) { //该链表有多个节点并且删除的不是尾节点
        ListNode *nextNode = deleteNode -> m_pNext;
        deleteNode -> m_nKey = nextNode -> m_nKey;
        deleteNode -> m_pNext = nextNode -> m_pNext;
        delete deleteNode;
        deleteNode = NULL;
    } else { //删除的是尾节点 这个时候只能从头遍历到尾节点的前一个节点，把 node -> next = null
        
        while (headnode -> m_pNext != deleteNode) {
            headnode = headnode -> m_pNext;
        }
        headnode -> m_pNext = NULL;
        delete deleteNode;
        deleteNode = NULL;
    }
    
    
    
    
    
}

//链表中倒数第k个节点 思路:两个点相差K,当一个点到末尾的时候，另外一个点刚好是倒数k
void printNodeIndex(ListNode *pNode,int k){
    
    ListNode *node = pNode;
    for (int i = 1; i < k; i ++) {
        node = node -> m_pNext;
    };
    while (node -> m_pNext != NULL) {
        node = node -> m_pNext;
        pNode = pNode -> m_pNext;
    };
    cout << pNode -> m_nKey << endl;
}

//从尾到头打印链表 递归本质上是栈结构
void PrintListReversingly(ListNode *pHead) {
    if (pHead != NULL) {
        if (pHead->m_pNext != NULL) {
            PrintListReversingly(pHead->m_pNext);
        }
        printf("%d\t",pHead->m_nKey);
    }
}

int main(int argc, const char * argv[]) {
    
    ListNode *pHead = NULL;
    
    for (int i = 1; i < 10; i ++) {
        AddToTail(&pHead, i);
    }
    
        PrintListReversingly(pHead);
//    removeNode(&pHead, 6);
//    PrintListReversingly(pHead);
    printNodeIndex(pHead, 1);
    return 0;
}


