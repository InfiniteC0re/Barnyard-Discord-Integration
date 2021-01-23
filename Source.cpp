#include <Windows.h>
#include <iostream>
#include <locale>

#include "Utils\ReaderHelper.h"
#include "Engine\Player.h"
#include "Utils\Discord.h"

using namespace std;

ReaderHelper* g_pReaderHelper;
Player* g_pPlayer;

DWORD WINAPI MainThread(LPVOID lpArgs)
{
	uintptr_t baseAddress = (uintptr_t)GetModuleHandle("Barnyard.exe");

	ReaderHelper rh(baseAddress);
	g_pReaderHelper = &rh;
	Player player(g_pReaderHelper);
	g_pPlayer = &player;

	Discord rpcClient;
	rpcClient.Initialize();

	while (true)
	{
		bool didLocationUpdated = g_pPlayer->UpdateLocation();
		bool gotPosition = g_pPlayer->UpdatePosition();

		if (didLocationUpdated)
		{
			int locationID = g_pPlayer->LocationID;

			const char* locationName = g_pReaderHelper->readLocationName(locationID);
			const char* locationImage = g_pReaderHelper->readLocationImage(locationID);
			char RPCLargeImageText[256];
			char RPCLargeImage[32];
			char RPCState[256];

			sprintf_s(RPCState, "");
			sprintf_s(RPCLargeImageText, locationName);
			sprintf_s(RPCLargeImage, "%s", locationImage);

			rpcClient.Update(RPCLargeImageText, RPCState, RPCLargeImage);
			cout << "Location updated: " << locationName << " (" << locationID << ")" << endl;
		}

		Sleep(500);
	}

	FreeLibraryAndExitThread((HMODULE)lpArgs, 0);
	return 0;
}

DWORD APIENTRY DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved)
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
		AllocConsole();
		FILE* fp;
		freopen_s(&fp, "CONOUT$", "w", stdout);

		setlocale(LC_ALL, "Russian");
		SetConsoleOutputCP(866);

		// Создаём поток
		CreateThread(NULL, NULL, MainThread, instance, NULL, NULL);

		break;
	default:
		break;
	}

	return TRUE;
}