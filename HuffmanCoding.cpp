//
// Created by Shaw on 2019-06-18.
//

#include "HuffmanCoding.h"



HuffmanTree Haffman::MergeNode(HuffmanTree N1, HuffmanTree N2) {
    HTNode *NewHTNode = new HTNode;
    NewHTNode->weight = N1->weight + N2->weight;
    NewHTNode->parent = nullptr;
    NewHTNode->lchild = N1;
    NewHTNode->rchild = N2;
    N1->parent = N2->parent = NewHTNode;
    return NewHTNode;
}

