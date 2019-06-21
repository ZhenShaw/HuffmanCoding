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
    string code;                    //解码结果
    HTNode *parent, *left, *right;

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

int ReadFile(HTNode HashTable[], string path);

void CreateForest(HTNode **HT, HTNode *HashTable);

void CreateHuffmanTree(HTNode **HT, int n);

void HuffmanCode(HTNode *HT[], int n);

void ShowCode(HTNode *HT[], int len);

void SaveCode(HTNode *HT[], int len, string path);

void DeCode(string path);