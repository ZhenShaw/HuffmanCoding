#include <iostream>
#include "HuffmanCoding.h"

using namespace std;

void Menu() {
    cout << "\n------- 哈夫曼编码解码\t-------" << endl;
    cout << "------- 1、编码文件\t-------" << endl;
    cout << "------- 2、解码文件\t-------" << endl;
    cout << "------- 0、退出程序\t-------" << endl;
    cout << "\n请选择：";
}

int main(int args, char **argv) {
    //获取运行路径
    string path = argv[0];

    cout << "当前程序运行路径:" + path << endl;
    cout << "请提前把英文文档命名为【article.txt】放到程序同级目录下\n\n";

    path = ".";

    int choose;
    Menu();
    while (cin >> choose) {
        if (choose == 1) {

            HTNode *HashTable = new HTNode[128];               //创建哈希表统计ascii码的个数

            int len = ReadFile(HashTable, "article.txt");      //读取文件，统计字符个数，初始化哈希表

            HTNode *HT[len];
            CreateForest(HT, HashTable);                      //去除哈希表中权重为0的字符，重新建立森林

            CreateHuffmanTree(HT, len); //创建哈夫曼树

            HuffmanCode(HT, len);       //哈夫曼编码

            ShowCode(HT, len);          //显示编码结果

            SaveCode(HT, len, path);    //保存编码文件

        } else if (choose == 2) {

            DeCode(path);               //解码文件

        }
        if (choose == 0) break;

        Menu();
    }

}

