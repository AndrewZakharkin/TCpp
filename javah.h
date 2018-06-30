//
// Created by andre on 30.06.2018.
//

#ifndef FIRSTTEST_JAVAH_H
#define FIRSTTEST_JAVAH_H
#include <jni.h>
/* Header for class com_zakharkin_Main_Entry */

#ifndef _Included_com_zakharkin_Main_Entry
#define _Included_com_zakharkin_Main_Entry
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_zakharkin_Main_Entry
 * Method:    tst
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_zakharkin_Main_Entry_tst(JNIEnv * env, jclass cls, jstring str);

#ifdef __cplusplus
}
#endif
#endif
#endif //FIRSTTEST_JAVAH_H
