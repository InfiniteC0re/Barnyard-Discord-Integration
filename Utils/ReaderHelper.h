#pragma once
#include <Windows.h>
#include <iostream>
#include "Vector3.h"

class ReaderHelper
{
public:
	ReaderHelper(uintptr_t base);
	uintptr_t BaseAddress;

	uintptr_t ReadInteger(uintptr_t baseAddress, const uintptr_t offsets[], int size);
	Vector3 ReadVector3(uintptr_t baseAddress, const uintptr_t offsets[], int size);
	const char* readLocationImage(int id);
	const char* readLocationName(int id);
};

