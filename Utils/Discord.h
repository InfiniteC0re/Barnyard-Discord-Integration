#pragma once
#include "..\Discord RPC\include\discord_register.h"
#include "..\Discord RPC\include\discord_rpc.h"
#include <Windows.h>

class Discord {
public:
	void Initialize();
	void Update(char state[256], char details[256], char largeImageKey[32], char smallImageText[128]);
};
