#pragma once
#include "..\Utils\Vector3.h"
#include "..\Utils\ReaderHelper.h"
#include "..\Utils\Offsets.h"
#include <iostream>

class Player
{
public:
	Player(ReaderHelper*);
	ReaderHelper* g_pReaderHelper;

	Vector3 Position;
	int LocationID;
	int WorldID;
	int GBucks;

	// Story
	int Act;
	int Tier;
	int CurrentQuest;

	bool UpdateLocation();
	bool UpdatePosition();
	bool UpdateGBucks();
	bool UpdateStoryProgress();
};

