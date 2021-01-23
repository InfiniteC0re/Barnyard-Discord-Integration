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

	bool UpdateLocation();
	bool UpdatePosition();
};

