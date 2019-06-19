//
// Created by Shaw on 2019-06-18.
//

#include <fstream>
#include <istream>
#include <string>
#include <iostream>
#include "Tools.h"

using namespace std;

//读取文件存入哈希表
int ReadFile(ElemNode HashTable[], string path) {
    fstream file(path, ios::in);
    char ch;
    int n = 0;//统计不同字符的个数
    while (file.get(ch)) {
        //使用字符的ASCII码作为哈希值
        int hash = (unsigned int) ch;
        HashTable[hash].data = ch;
        HashTable[hash].count++;
        if (HashTable[hash].count == 1) n++;
    }
    return n;
}

//创建小根堆
void HeapAdjust(ElemNode HashTable[], int s, int m) {
    ElemNode rc = HashTable[s];
    for (int j = 2 * s; j < m; j *= 2) {
        if (j < m && HashTable[j].count < HashTable[j + 1].count) j++;
        if (HashTable[s].count <= HashTable[j].count) break;
        HashTable[s] = HashTable[j];
        s = j;
    }
    HashTable[s] = rc;
}

//
void CreateHeap(ElemNode HashTable[], int len) {
    for (int i = len / 2; i > 0; i--) {
        HeapAdjust(HashTable, i, len);
    }
}



