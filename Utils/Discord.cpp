#include "Discord.h"
#include <time.h>
#include <chrono>

static int64_t eptime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();

void Discord::Initialize()
{
	DiscordEventHandlers Handle;
	memset(&Handle, 0, sizeof(Handle));

	Discord_Initialize("800986404490182677", &Handle, 1, NULL);
}

void Discord::Update(char state[256], char location[256], char largeImageKey[32])
{
	DiscordRichPresence drp;
	memset(&drp, 0, sizeof(drp));

	drp.state = state;
	drp.startTimestamp = eptime;
	drp.largeImageKey = largeImageKey;

	if (largeImageKey != "default") {
		drp.largeImageText = location;
		drp.smallImageKey = "default";
		drp.smallImageText = "Created by InfiniteC0re";
	}
	else {
		
	}

	Discord_UpdatePresence(&drp);
}