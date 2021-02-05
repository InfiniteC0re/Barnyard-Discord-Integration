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

void Discord::Update(char state[256], char details[256], char largeImageKey[32], char smallImageText[128])
{
	DiscordRichPresence drp;
	memset(&drp, 0, sizeof(drp));

	drp.state = state;
	drp.details = details;
	drp.startTimestamp = eptime;
	drp.largeImageKey = largeImageKey;

	if (largeImageKey != "default")
		drp.smallImageKey = "default";

	if (smallImageText[0] == '\0')
		drp.smallImageText = "Created by InfiniteC0re";
	else
		drp.smallImageText = smallImageText;

	Discord_UpdatePresence(&drp);
}