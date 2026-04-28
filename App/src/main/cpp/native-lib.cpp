#include <jni.h>
#include <string>
#include "../../../../Core/include/DataModel.hpp"
#include "../../../../Core/include/ServerModel.hpp"
#include "../../../../Core/include/NetworkHandle.hpp"
#include "../../../../Core/include/ShooterService.hpp"
#include "../../../../Core/include/MapService.hpp"
#include <android/log.h>

#define LOG_TAG "MyEngine"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

extern "C" JNIEXPORT void JNICALL
Java_com_cstudioss_fpsgame_MainActivity_nativeInit(JNIEnv* env, jobject /* this */) {
    LOGI("Initializing Engine from JNI...");
    
    DataModel* DM = DataModel::Get();
    DM->Init();

    ServerModel* SM = ServerModel::Get();
    SM->Init();

    // Start Shooter Game and Load Map
    DM->shooterService->StartGame();
    DM->mapService->LoadMap("Arena_1");

    SM->handle->Connect([](int code, const std::string& body) {
        __android_log_print(ANDROID_LOG_INFO, "MyEngine", "[Connect] %d — %s", code, body.c_str());
    });

    LOGI("Engine Initialized.");
}

extern "C" JNIEXPORT void JNICALL
Java_com_cstudioss_fpsgame_MainActivity_nativeShoot(JNIEnv* env, jobject /* this */) {
    DataModel::Get()->shooterService->Shoot();
}

extern "C" JNIEXPORT jint JNICALL
Java_com_cstudioss_fpsgame_MainActivity_nativeGetAmmo(JNIEnv* env, jobject /* this */) {
    return DataModel::Get()->shooterService->GetAmmo();
}

extern "C" JNIEXPORT jint JNICALL
Java_com_cstudioss_fpsgame_MainActivity_nativeGetHealth(JNIEnv* env, jobject /* this */) {
    return DataModel::Get()->shooterService->GetHealth();
}
