//
// Created by Shaw on 2019-06-18.
//
#ifndef HUFFMANCODING_TOOLS_H
#define HUFFMANCODING_TOOLS_H
#endif //HUFFMANCODING_TOOLS_H

#include "HuffmanCoding.h"

using namespace std;

typedef char ElemType;          //元素类型char
typedef HTNode LinkNodeType;    //链表节点类型为哈夫曼树的节点

//字符元素节点
typedef struct ElemNode {
    ElemType data;          //字符数据
    unsigned int count = 0;     //字符数量统计
} ElemNode;

//用链表临时存储二叉树森林
typedef struct LinkNode {
    LinkNodeType data;      //节点数据
    LinkNode *next;         //下一个节点
} *LinkList;


int ReadFile(ElemNode HashTable[], string path);

void CreateHeap(ElemNode HashTable[], int len);