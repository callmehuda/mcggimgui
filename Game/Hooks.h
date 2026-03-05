#pragma once

#define MYHOOK(ret, func, ...) \
    ret (*orig##func)(__VA_ARGS__); \
    ret my##func(__VA_ARGS__)

MYHOOK(int, get_curSnowNum, void* instance) {
    if (instance != nullptr && dbAurora){
        return 6;
    }
    
    return origget_curSnowNum(instance);
}

void Hooks() {

    const auto assembly = UnityResolve::Get("Assembly-CSharp.dll");
    
    const auto dbAuroramethod   = assembly->Get("MCLogicSpecialMonsterAurora", "Battle")->Get<UnityResolve::Method>("get_curSnowNum");
    DobbyHook(dbAuroramethod->function, (void *)myget_curSnowNum, (void **)&origget_curSnowNum);

}