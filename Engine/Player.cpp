#include "Player.h"

Player::Player(ReaderHelper* rh) {
    g_pReaderHelper = rh;

    Position = Vector3(0, 0, 0);
    LocationID = -1;
}

bool Player::UpdateLocation()
{
    int readedLocation = g_pReaderHelper->ReadInteger(g_pReaderHelper->BaseAddress, Offsets::Player::Location, 8);
    if (readedLocation != LocationID)
    {
        LocationID = readedLocation;
        return TRUE;
    }

    return FALSE;
}

bool Player::UpdatePosition()
{
    Vector3 vec = g_pReaderHelper->ReadVector3(g_pReaderHelper->BaseAddress, Offsets::Player::Position, 7);
    Position = vec;
    char buffer[256];

    sprintf_s(buffer, "%f; %f; %f", vec.x, vec.y, vec.z);
    std::cout << buffer << std::endl;

    return FALSE;
}
