#include "Player.h"
#include <iostream>

Player::Player(ReaderHelper* rh) {
    g_pReaderHelper = rh;

    Position = Vector3(0, 0, 0);
    LocationID = -1;
    WorldID = -1;
    GBucks = 0;

    // Story
    Act = -1;
    Tier = -1;
    CurrentQuest = 0;
}

bool Player::UpdateLocation()
{
    int readedWorld = g_pReaderHelper->ReadAddress(Offsets::Player::World, 1);
    int readedLocation = g_pReaderHelper->ReadAddress(Offsets::Player::Location, 8);

    if (readedLocation != LocationID || readedWorld != WorldID)
    {
        WorldID = readedWorld;
        LocationID = readedLocation;

        return TRUE;
    }

    return FALSE;
}

bool Player::UpdatePosition()
{
    Vector3 vec = g_pReaderHelper->ReadVector3(Offsets::Player::Position, 7);
    Position = vec;
    char buffer[256];

    return FALSE;
}

bool Player::UpdateGBucks()
{
    int newBucks = g_pReaderHelper->ReadAddress(Offsets::Player::GBucks, 2);

    if (newBucks != GBucks)
    {
        GBucks = newBucks;

        return TRUE;
    }

    return FALSE;
}

bool Player::UpdateStoryProgress()
{
    int newAct = g_pReaderHelper->ReadAddress(Offsets::Story::Act, 7);
    int newTier = g_pReaderHelper->ReadAddress(Offsets::Story::Tier, 7) - 1;

    if (newTier != Tier || newAct != Act)
    {
        if (newAct == 2)
            CurrentQuest = 15;
        else if (newAct == 3)
            CurrentQuest = 34;
        else
            CurrentQuest = 0;

        Act = newAct;
        Tier = newTier;

        CurrentQuest += Tier;

        return TRUE;
    }

    return FALSE;
}