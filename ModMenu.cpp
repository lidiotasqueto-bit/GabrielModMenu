#include <jni.h>
#include <string>
#include <android/log.h>

#define TAG "GabrielModMenu"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)

bool featureOneEnabled = false;
bool featureTwoEnabled = false;

extern "C" JNIEXPORT void JNICALL
Java_com_gabriel_modmenu_MainActivity_ToggleFeature(JNIEnv *env, jobject thiz, jint id, jboolean enable) {
    switch(id) {
        case 1:
            featureOneEnabled = enable;
            LOGD("Funcao 1 alterada para: %s", enable ? "ATIVADO" : "DESATIVADO");
            break;
        case 2:
            featureTwoEnabled = enable;
            LOGD("Funcao 2 alterada para: %s", enable ? "ATIVADO" : "DESATIVADO");
            break;
        default:
            LOGD("Funcao desconhecida.");
            break;
    }
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }
    
    LOGD("========================================");
    LOGD(" Gabriel Mod Menu inicializado com sucesso! ");
    LOGD("========================================");
    
    return JNI_VERSION_1_6;
}
