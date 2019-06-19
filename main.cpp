#include <iostream>
//#include "HuffmanCoding.h"
#include "Tools.h"

using namespace std;


int main() {
    ElemNode *HashTable = new ElemNode[128];

    int len = ReadFile(HashTable, "/Users/Shaw/Workspace/C++/HuffmanCoding/doc/article.txt");



    int j = 0;
    ElemNode *ElemArr = new ElemNode[len];

    for (int i = 0; i < 128; i++) {
        if (HashTable[i].count > 0) {
            ElemArr[j].data = HashTable[i].data;
            ElemArr[j].count = HashTable[i].count;
            j++;
        }
    }
    CreateHeap(ElemArr, len);

    for (int i = 0; i < len; i++) {

        cout << ElemArr[i].data << " " << ElemArr[i].count << endl;

    }

}