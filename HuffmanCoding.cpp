//
// Created by Shaw on 2019-06-18.
//

#include <fstream>
#include <istream>
#include <queue>
#include <string>
#include <iostream>
#include "HuffmanCoding.h"


//读取文件存入哈希表
int ReadFile(HTNode HashTable[], string path) {
    fstream file(path, ios::in);
    if (!file.is_open()) {
        cout << "源文档打开失败！\n";
        return 0;
    }

    char ch;
    int n = 0;      //统计不同字符的个数
    while (file.get(ch)) {
        //使用字符的ASCII码作为哈希值
        int hash = (unsigned int) ch;
        HashTable[hash].data = ch;
        HashTable[hash].weight++;
        if (HashTable[hash].weight == 1) n++;
    }
    return n;
}


void CreateForest(HTNode **HT, HTNode *HashTable) {
    //去除权重为0的字符，重新建立森林
    int j = 0;
    for (int i = 0; i < MAX; i++) {

        if (HashTable[i].weight > 0) {
            HTNode *newNode = new HTNode();
            newNode->data = HashTable[i].data;
            newNode->weight = HashTable[i].weight;
            HT[j] = newNode;
            j++;
        }
    }
}


//模板申明带3个参数：priority_queue<Type, Container, Functional>
// 其中Type 为数据类型，Container为保存数据的容器，Functional 为元素比较方式。
priority_queue<HTNode *, vector<HTNode *>, PCmp> Heap;    //最小堆结构

//构造HuffmanTree
void CreateHuffmanTree(HTNode **HT, int n) {
    //创建小根堆
    for (int i = 0; i < n; i++) {
        Heap.push(HT[i]);
    }
    HTNode *parent;
    HTNode *s1, *s2;

    while (!Heap.empty()) {
        //取出小根堆前面两个元素
        s1 = Heap.top();
        Heap.pop();
        if (Heap.empty()) break;        //最后队列中只有一个元素，也就是已经生成HuffmanTree
        s2 = Heap.top();
        Heap.pop();

        //新建临时节点，合并权重
        parent = new HTNode();
        parent->data = ' ';
        parent->weight = s1->weight + s2->weight; //设置权重

        //设定子节点
        parent->right = s2;
        parent->left = s1;

        //设定父节点
        s1->parent = parent;
        s2->parent = parent;

        //把合并后的节点放入小根堆
        Heap.push(parent);
    }
}


void HuffmanCode(HTNode *HT[], int n) {
    for (int i = 0; i < n; i++) {
        HTNode *cur = HT[i];
        HTNode *parent = HT[i]->parent;
        string code = "";

        //沿着指针路径读取编码
        while (parent != nullptr) {    //到达根节点的时候解码结束
            if (parent->left == cur)
                code = "0" + code;
            else
                code = "1" + code;

            //结点向上一层
            cur = parent;
            parent = parent->parent;
        }
        HT[i]->code = code;//赋值编码
    }
}


//保存文件
void SaveCode(HTNode *HT[], int len, string path) {
    ofstream fCode("./result.dat", ios::out | ios::binary);
    ofstream fTable("./table.dat", ios::out | ios::binary);
    ifstream fOrigin("./article.txt", ios::in);
    if (!fOrigin.is_open()) {
        cout << "源文档打开失败！\n";
        return;
    }
    //写入编码结果
    char ch;
    while (fOrigin.get(ch)) {
        for (int i = 0; i < len; i++) {
            if (ch == HT[i]->data) {
                fCode.write(HT[i]->code.c_str(), HT[i]->code.length());
            }
        }
    }

    //写入编码表
    for (int i = 0; i < len; i++) {
        CodingTable T;
        T.data = HT[i]->data;
        T.code = HT[i]->code.c_str();
        fTable.write((char *) &T, sizeof(T));
    }
    cout << "\n保存编码结果和编码表完成!" << endl;
    cout << "编码结果文件：" + path + "/result.dat" << endl;
    cout << "编码表文件：" + path + "/table.dat" << endl;

    fCode.close();
    fTable.close();
    fOrigin.close();
}

void DeCode(string path) {
    ifstream fCode("./result.dat", ios::in | ios::binary);
    ifstream fTable("./table.dat", ios::binary);
    ofstream fRec("./recovery.txt", ios::out);
    if (!fCode.is_open() || !fTable.is_open()) {
        cout << "编码文件或编码表打开失败！\n";
        return;
    }
    //读取编码表
    CodingTable tempTable[MAX], flag;
    int k = 0;
    while (fTable.read((char *) &flag, sizeof(flag))) {
        tempTable[k] = flag;
        k++;
    }

    //解码写入文件
    string res = "";
    char ch;
    while (fCode.get(ch)) {
        res += ch;
        for (int i = 0; i < k; i++) {
            if (res == tempTable[i].code) {
                fRec << tempTable[i].data;
                res = "";
                break;
            }
        }
    }
    cout << "\n解码完成!" << endl;
    cout << "解码文件：" + path + "/recovery.txt" << endl;

    fCode.close();
    fTable.close();
    fRec.close();
}


//遍历统计结果
void ShowCode(HTNode *Forest[], int len) {
    for (int i = 0; i < len; i++) {
        cout << "字符：" << Forest[i]->data << "\t"
             << "权重：" << Forest[i]->weight << "\t"
             << "编码：" << Forest[i]->code << endl;
    }
}


