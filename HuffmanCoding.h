//
// Created by Shaw on 2019-06-18.
//
#ifndef HUFFMANCODING_H
#define HUFFMANCODING_H
#endif
using namespace std;

#define MAX 128

typedef char ElemType;              //元素类型char

struct HTNode {
    ElemType data;                  //字符
    int weight;                     //权重
    string code;                    //编码

    HTNode *parent, *left, *right;  //父子节点

    //初始化结构体
    HTNode() {
        parent = left = right = nullptr;
        code = "";
        weight = 0;
    }
};

//编码表
typedef struct CodingTable {
    ElemType data;
    const char *code;
} CodingTable;

//定义指针比较函数
struct PCmp {
    bool operator()(HTNode const *x, HTNode const *y) {
        return x->weight > y->weight;
    }
};

//读取文件，初始化哈希表，返回不同字符个数
int ReadFile(HTNode HashTable[], string path);
//根据哈希表建立森林
void CreateForest(HTNode **HT, HTNode *HashTable);
//根据森林节点权重创建一棵哈夫曼树
void CreateHuffmanTree(HTNode **HT, int n);
//对哈夫曼树进行编码
void HuffmanCode(HTNode *HT[], int n);
//打印 字符--权重--编码
void ShowCode(HTNode *HT[], int len);
//保存编码表和编码结果到二进制文件
void SaveCode(HTNode *HT[], int len, string path);
//解码还原文件
void DeCode(string path);