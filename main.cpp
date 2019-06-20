#include <iostream>
#include "HuffmanCoding.h"

using namespace std;

int main(int args, char **argv) {
    //获取运行路径
    string path = argv[0];
    cout << path << endl;

    path = "/Users/Shaw/Desktop";

    //创建哈希表统计ascii码的个数
    HTNode *HashTable = new HTNode[128];

    //读取文件，统计字符个数，初始化哈希表
    int len = ReadFile(HashTable, "../text/article.txt");

    //去除哈希表中权重为0的字符，重新建立森林
    HTNode *HT[len];
    CreatForest(HT, HashTable);

    CreatHuffmanTree(HT, len);

    HuffmanCode(HT, len);

    ShowCode(HT, len);

    SaveCode(HT, len, path);

    DeCode(path);


}



