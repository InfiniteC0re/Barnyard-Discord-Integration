#include <Windows.h>
#include <iostream>
#include <string>
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
		bool locationUpdated  = g_pPlayer->UpdateLocation();
		bool positionUpdated = g_pPlayer->UpdatePosition();
		bool bucksUpdated  = g_pPlayer->UpdateGBucks();
		bool storyModeUpdated = g_pPlayer->UpdateStoryProgress();

		if (locationUpdated || storyModeUpdated || bucksUpdated)
		{
			char RPCSmallImageText[128];
			char RPCLargeImage[32];
			char RPCState[256];
			char RPCDetails[256];

			if (g_pPlayer->WorldID == 0)
			{
				const char* locationName = g_pReaderHelper->readLocationName(g_pPlayer->LocationID);
				const char* locationImage = g_pReaderHelper->readLocationImage(g_pPlayer->LocationID);

				sprintf_s(RPCDetails, locationName);
				sprintf_s(RPCLargeImage, "%s", locationImage);
			}
			else
			{
				const char* worldName = g_pReaderHelper->ReadWorldName(g_pPlayer->WorldID);
				sprintf_s(RPCDetails, "%s", worldName);
				sprintf_s(RPCLargeImage, "%s", "default");
			}

			if (g_pPlayer->WorldID == 0 || g_pPlayer->WorldID == 2 || g_pPlayer->WorldID == 26 || g_pPlayer->WorldID == 35 || g_pPlayer->WorldID == 36)
			{
				if (storyModeUpdated)
					sprintf_s(RPCSmallImageText, "Story Progress: %d%%", (int)(g_pPlayer->CurrentQuest / 51.0f * 100));

				if (g_pPlayer->GBucks > 0)
					sprintf_s(RPCState, "Bucks: %d", g_pPlayer->GBucks);
			}
			else
			{
				// Reset stats
				sprintf_s(RPCState, "");
				sprintf_s(RPCSmallImageText, "");
			}

			rpcClient.Update(RPCState, RPCDetails, RPCLargeImage, RPCSmallImageText);
#ifdef _DEBUG
			cout << "Location updated: " << RPCDetails << " (" << g_pPlayer->LocationID << ", " << g_pPlayer->WorldID << ")" << endl;
#endif
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

#ifdef _DEBUG
		AllocConsole();
		FILE* fp;
		freopen_s(&fp, "CONOUT$", "w", stdout);

		setlocale(LC_ALL, "Russian");
		SetConsoleOutputCP(866);
#endif

		CreateThread(NULL, NULL, MainThread, instance, NULL, NULL);

		break;
	default:
		break;
	}

	return TRUE;
}