#include <iostream>
#include <jni.h>
#include "javah.h"
/*int main() {
    std::cout << "Hello, World!" << std::endl;

    return 0;
}*/

JNIEXPORT void JNICALL Java_com_zakharkin_Main_Entry_tst(JNIEnv * env, jclass cls, jstring str)
{
    jboolean isCopy;
    const char* chrs = env->GetStringUTFChars(str, &isCopy);
    std::cout << chrs << std::endl;
    env->ReleaseStringUTFChars(str, chrs);
}