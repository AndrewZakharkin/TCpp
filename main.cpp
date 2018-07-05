#include <iostream>
#include <jni.h>
#include "javah.h"
#include "Algorythm/Builder.h"
#include "Algorythm/Algo.h"
/*int main() {
    std::cout << "Hello, World!" << std::endl;

    return 0;
}*/

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

            std::cout << "-------------CPP STARTS HERE-----------" << std::endl;
            Builder b;
            std::pair<Node*, std::array<Node*, 6>> t = b.buildGraph();
            Algo a(t.first, t.second);
            a.runAlgo(t.first);
            for(Node* node : t.second){
                std::cout << "Node " << node->getName() << " has weight " << node->getWeight() << std::endl;
            }
            std::cout << "-------------END OF CPP CODE-----------" << std::endl;
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