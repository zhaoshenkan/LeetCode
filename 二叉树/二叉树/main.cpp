//
//  main.cpp
//  二叉树
//
//  Created by 赵申侃 on 2018/12/11.
//  Copyright © 2018 赵申侃. All rights reserved.
//

//三种遍历:
// 1.前序遍历 根节点 -> 左子节点 -> 右子节点
// 2.中序遍历 左子节点 -> 根节点 -> 右子节点
// 3.后序遍历 左子节点 -> 右子节点 -> 根节点

#include <iostream>
#include <vector>
#include <stack>


using namespace std;
struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

//重构二叉树
BinaryTreeNode* ConstructBinaryTree(vector<int> pre,vector<int> in){
    
    if (pre.size() != in.size()) {
        return NULL;
    }
    
    long int length = pre.size();
    if (length == 0) {
        return NULL ;
    }
    
    BinaryTreeNode *treeNode = new BinaryTreeNode;
    treeNode -> m_nValue = pre[0];
    treeNode -> m_pLeft = treeNode -> m_pRight = NULL;
    
    //在中序遍历中查找根的位置
    int rootIndex = 0;
    for (int i = 0; i < in.size(); i ++) {
        if (in[i] == pre[0]) {
            rootIndex = i;
            break;
        }
    }
    
    if (rootIndex >= length) {
        return NULL;
    }
    
    ///  首先确定左右子树的长度, 从中序遍历in中确定
    long int leftLength = rootIndex;
    long int rightLength = length - 1 - rootIndex;
    
    vector<int> preLeft(leftLength), inLeft(leftLength);
    vector<int> preRight(rightLength), inRight(rightLength);
    for(int i = 0; i < length; i++)
    {
        //分别把前序遍历后序遍历的 左右子树取出来
        if(i < rootIndex)
        {
            //  前序遍历的第一个是根节点, 根后面的(leftLegnth = rootIndex) - 1个节点是左子树, 因此是i+1
            preLeft[i] = pre[i + 1];
            //  中序遍历前(leftLength = rootIndex) - 1个节点是左子树, 第rootIndex个节点是根
            inLeft[i] = in[i];

        }
        else if(i > rootIndex)
        {
            //  前序遍历的第一个是根节点, 根后面的(leftLegnth = rootIndex) - 1个节点是左子树, 后面是右子树
            preRight[i - rootIndex - 1] = pre[i];
            //  中序遍历前(leftLength = rootIndex) - 1个节点是左子树, 第rootIndex个节点是根, 然后是右子树
            inRight[i - rootIndex - 1] = in[i];
            
        }
    }

    treeNode->m_pLeft = ConstructBinaryTree(preLeft, inLeft);
    treeNode->m_pRight = ConstructBinaryTree(preRight, inRight);
    return  treeNode;
}

//二叉树的前序遍历(递归)
void preTraversalTreeNode(BinaryTreeNode *treeNode){
    cout << treeNode -> m_nValue << endl;
    if (treeNode -> m_pLeft != NULL) {
        preTraversalTreeNode(treeNode -> m_pLeft);
    }
    if (treeNode -> m_pRight != NULL) {
        preTraversalTreeNode(treeNode -> m_pRight);
    }
}

//前序遍历非递归
vector<int> preTraversalTreeNode2(BinaryTreeNode *treeNode){
    
    stack<BinaryTreeNode *> stack;
    vector<int> v;
    BinaryTreeNode *t = treeNode;
    stack.push(t);
    while (!stack.empty()) {
        t = stack.top();
        stack.pop();
        v.push_back(t -> m_nValue);
        if (t -> m_pRight != NULL) {
            stack.push(t -> m_pRight);
        }
        if (t -> m_pLeft != NULL) {
            stack.push(t -> m_pLeft);
        }
        
    }
    return v;
}

//二叉树的中序遍历(递归)
void inTraversalTreeNode(BinaryTreeNode *treeNode) {
    
    if (treeNode -> m_pLeft != NULL) {
        inTraversalTreeNode(treeNode -> m_pLeft);
    }
    cout << treeNode ->m_nValue << endl;
    if (treeNode -> m_pRight != NULL) {
        inTraversalTreeNode(treeNode -> m_pRight);
    }
}

//中序遍历非递归
vector<int> inTraversalTreeNode2(BinaryTreeNode *treeNode) {
    stack<BinaryTreeNode *> inStack;
    vector<int> inOrder;
    BinaryTreeNode *tree = treeNode;
    while (tree || !inStack.empty()) {
        //把所有左边的节点加入到栈
        while ( tree != NULL) {
            inStack.push(tree);
            tree = tree -> m_pLeft;
        }
        //取出栈顶的节点 也就是最后一个节点
        tree = inStack.top();
        //pop掉顶节点
        inStack.pop();
        inOrder.push_back(tree -> m_nValue);
        tree = tree -> m_pRight;
    }
    return inOrder;
}


int main(int argc, const char * argv[]) {
    
    // 普通二叉树
    //              1
    //           /     \
    //          2       3
    //         /       / \
    //        4       5   6
    //         \         /
    //          7       8
    //前序遍历
    int pre[8] = {1,2,4,7,3,5,6,8};
    //中序遍历
    int in[8] = {4,7,2,1,5,3,8,6};
    
    //复制[begin,end)区间内另一个数组的元素到vector中
    vector<int> preOrder(pre, pre + 8);
    vector<int> inOrder( in,  in + 8);
    BinaryTreeNode *treeNode = ConstructBinaryTree(preOrder, inOrder);
//    preTraversalTreeNode(treeNode);
//    inTraversalTreeNode(treeNode);
    vector<int> v = inTraversalTreeNode2(treeNode);
    vector<int> v2 = preTraversalTreeNode2(treeNode);
    
    return 0;
}
