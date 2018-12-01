#include <iostream>
#include <jni.h>
#include "javah.h"
#include "Algorythm/Builder.h"
#include "Algorythm/Algo.h"
#include "StlPlay.h"
#include "Sort/QuickSortInt.h"
#include "Algorythm/SimpleNode.h"
void fillLevel(SimpleNode*node, int level, int (&levelCnt)[12]);
void printByLevel(SimpleNode*node, int level);
const int MAX_CHILDREN = 3;
const int MAX_LEVEL = 4;

int main() {
    int levelCounter[] = {0,0,0,0,0,0,0,0,0,0,0,0};
    SimpleNode root(0);
    fillLevel(&root, 1,levelCounter);
    printByLevel(&root, 0);
    return 0;
    /*std::vector<int> unsorted (100);
    std::uniform_int_distribution<int> di(100,200);
    std::default_random_engine dre;
    for(int i = 0; i < 100; ++i){
        unsorted[i] = di(dre);
        std::cout << "(" << i << "-" << unsorted[i] <<"):";
    }
    std::cout << std::endl;
    QuickSortInt qs(unsorted, 100);
    qs.sort();
    for(int i = 0; i < 100; ++i){
        std::cout << unsorted[i] << " ";
    }

    return 0;*/
}
int ipow(int base, int exp)
{
    int result = 1;
    for (;;)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }

    return result;
}

void printByLevel(SimpleNode*node, int level) {
    for (int i = 0; i < level; ++i) std::cout << " ";
    if(level > 0) std::cout << "|";
    std::cout << "Level: " << level << " cur val: " << node->getValue() << std::endl;
    for (int i = 0; i < MAX_CHILDREN; ++i) {
        if(level < MAX_LEVEL) printByLevel(node->getChildren()[i], level + 1);
    }
}

void fillLevel(SimpleNode*node, int level, int (&levelCnt)[12]) {
    for (int i = 0; i < MAX_CHILDREN; ++i) {
        SimpleNode* newNode = new SimpleNode(ipow(10, level) + (++levelCnt[level]));
        if(level <= MAX_LEVEL) {
            fillLevel(newNode, level + 1, levelCnt);
        }
        node->addNode(newNode);
    }
}

void algoRun() {
    std::cout << "-------------CPP STARTS HERE-----------" << std::endl;
    Builder b;
    std::pair<Node*, std::array<Node*, 6>> t = b.buildGraph();
    Algo a(t.first, t.second);
    a.runAlgo(t.first);
    for(Node* node : t.second) {
        std::cout << "Node " << node->getName() << " has weight " << node->getWeight() << std::endl;
    }
    std::cout << "Cleaning" << std::endl;
    for(Node * node  : t.second){
        delete node;
    }
    std::cout << "-------------END OF CPP CODE-----------" << std::endl;
}

JNIEXPORT jobject JNICALL Java_com_zakharkin_Main_Entry_tst(JNIEnv * env, jclass cls, jstring str)
{
    jboolean isCopy;
    const char* chrs = env->GetStringUTFChars(str, &isCopy);
    std::cout << chrs << std::endl;
    env->ReleaseStringUTFChars(str, chrs);
    std::cout << "Searching for com/zakharkin/Add/TestCls" << std::endl;
    jclass testCls = env->FindClass("com/zakharkin/Add/TestCls");
    if(testCls){
        std::cout << "Searching for com/zakharkin/Add/TestCls CONSTRUCTOR" << std::endl;
        jmethodID ctor = env->GetMethodID(testCls, "<init>", "()V");
        if(ctor){
            std::cout << "com/zakharkin/Add/TestCls CONSTRUCTOR is found. Instantiating object" << std::endl;
            jobject o = env->NewObject(testCls, ctor);

            algoRun();
            return o;
        }
        else{
            std::cout << "com/zakharkin/Add/TestCls constructor is not found" << std::endl;
        }
    }
    else{
        std::cout << "com/zakharkin/Add/TestCls is not found" << std::endl;
    }
    return nullptr;
}