//
// Created by Shaw on 2019-06-18.
//

#ifndef HUFFMANCODING_HUFFMANCODING_H
#define HUFFMANCODING_HUFFMANCODING_H
#endif //HUFFMANCODING_HUFFMANCODING_H


//哈夫曼二叉树节点
typedef struct HTNode {
    int             weight;     //节点权值
    unsigned int    code;       //节点哈夫曼编码
    char            data;       //原始数据
    struct HTNode   *parent,    //父节点
                    *lchild,    //左子节点
                    *rchild;    //右子节点
} HTNode, *HuffmanTree;


class Haffman {

public:
    //合并两个节点为一个二叉树
    HuffmanTree MergeNode(HuffmanTree N1, HuffmanTree N2);

};