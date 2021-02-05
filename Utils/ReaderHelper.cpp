#include "ReaderHelper.h"

ReaderHelper::ReaderHelper(uintptr_t base)
{
    BaseAddress = base;
}

uintptr_t ReaderHelper::ReadAddress(const uintptr_t offsets[], int size)
{
    uintptr_t addr = BaseAddress;

    for (int i = 0; i < size; i++)
    {
        if (addr + offsets[i] >= 0xFFFFFFF) return NULL;
        if (addr != NULL) addr = *(uintptr_t*)(addr + offsets[i]);
        if (addr >= 0xFFFFFFF) return NULL;
    }

    return addr;
}

Vector3 ReaderHelper::ReadVector3(const uintptr_t offsets[], int size) {
    Vector3 vec;

    uintptr_t addr = BaseAddress;

    for (int i = 0; i < size; i++)
    {
        if (addr + offsets[i] >= 0xFFFFFFF) return vec;
        if (addr != NULL) addr = *(uintptr_t*)(addr + offsets[i]);
        if (addr >= 0xFFFFFFF) return vec;
    }

    if (addr != NULL)
    {
        vec.x = *(float*)(addr + 0x18);
        vec.y = *(float*)(addr + 0x18 + 0x04);
        vec.z = *(float*)(addr + 0x18 + 0x08);
    }
    

    return vec;
}

const char* ReaderHelper::readLocationName(int id)
{
    switch (id) {
    case 0:
        return "The Farm";
        break;
    case 1:
        return "The Farm";
        break;
    case 2:
        return "Beady Farm";
        break;
    case 3:
        return "Road from the Beady Farm to the Izzy Springs";
        break;
    case 22:
        return "Road to the Veggie Patch";
        break;
    case 23:
        return "Izzy Springs Golf Course";
        break;
    case 24:
        return "Izzy Springs Golf Course";
        break;
    case 25:
        return "Gopher Hill";
        break;
    case 26:
        return "Grizzly Gulch";
        break;
    case 27:
        return "Grizzly Gulch";
        break;
    case 28:
        return "Road from the Ben's Hill to the Grizzly Gulch";
        break;
    case 29:
        return "Road to the Dandelion Meadow";
        break;
    case 30:
        return "Ben's Hill";
        break;
    case 31:
        return "Grizzly Gulch";
        break;
    case 32:
        return "Junkyard";
        break;
    case 33:
        return "Dandelion Meadow";
        break;
    case 34:
        return "Veggie Patch";
        break;
    case 35:
        return "Old Mill";
        break;
    case 36:
        return "Road to the Old Mill";
        break;
    case 37:
        return "Dankweed Pond";
        break;
    case 38:
        return "Road to the Grizzly Gulch";
        break;
    case 39:
        return "Road to the Dankweed Pond";
        break;
    case 40:
        return "Southest road to the Gopher's Hill";
        break;
    case 41:
        return "Northest road to the Gopher's Hill";
        break;
    case 47:
        return "Walnut Forest";
        break;
    case 48:
        return "Honey Forest Entry";
        break;
    case 49:
        return "Road from the Izzy Springs to the Walnut Forest";
        break;
    case 50:
        return "Road to the Walnut Forest";
        break;
    case 51:
        return "Crossroads near the Barnyard";
        break;
    case 52:
        return "Road to the Veggie Patch";
        break;
    case 53:
        return "Road to the Dankweed Pond";
        break;
    default:
        if (id > 0 && id <= 53)
            return "Unknown Location";
        else
            return "Mini Game";
        break;
    }
}

const char* ReaderHelper::readLocationImage(int id)
{
    switch (id) {
    case 0:
        return "barnyard";
        break;
    case 1:
        return "barnyard2";
        break;
    case 2:
        return "beady";
        break;
    case 3:
        return "r_beady_izzy24_3";
        break;
    case 22:
        return "r_dandelion";
        break;
    case 23:
        return "izzy_springs";
        break;
    case 24:
        return "r_beady_izzy24_3";
        break;
    case 25:
        return "gopher";
        break;
    case 26:
        return "gulch";
        break;
    case 27:
        return "gulch";
        break;
    case 28:
        return "r_ben_to_gulch";
        break;
    case 29:
        return "r_dandelion29";
        break;
    case 30:
        return "bens_hill";
        break;
    case 31:
        return "gulch";
        break;
    case 32:
        return "junkyard";
        break;
    case 33:
        return "dandelion_meadow";
        break;
    case 34:
        return "veggie";
        break;
    case 35:
        return "old_mill";
        break;
    case 36:
        return "r_old_mill";
        break;
    case 37:
        return "dankweed";
        break;
    case 38:
        return "r_gulch";
        break;
    case 39:
        return "r_dankweed";
        break;
    case 40:
        return "peck_launch"; // Peck-launch
        break;
    case 41:
        return "peck_launch";
        break;
    case 47:
        return "walnut";
        break;
    case 48:
        return "walnut";
        break;
    case 49:
        return "r_walnut_to_izzy";
        break;
    case 50:
        return "r_walnut";
        break;
    case 51:
        return "cross";
        break;
    case 52:
        return "r_dandelion";
        break;
    case 53:
        return "r_dankweed";
        break;
    default:
        return "default";
        break;
    }
}

const char* ReaderHelper::ReadWorldName(int id)
{
    switch (id) {
    case 0:
        return "Main World";
        break;
    case 1:
        return "Mud Jumpers";
        break;
    case 2:
        return "Night Barn";
        break;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
        char returnVal[256];
        sprintf_s(returnVal, "Golf: Hole %d", id - 2);
        return returnVal;
        break;
    case 21:
        return "Chicken Launch";
        break;
    case 22:
        return "Main Menu";
        break;
    case 23:
        return "Tease The Mailman";
        break;
    case 24:
        return "Tease Mrs. Beady";
        break;
    case 25:
        return "Honey Collecting";
        break;
    case 26:
        return "Day Barn";
        break;
    case 27:
        return "Gopher Underground";
        break;
    case 28:
        return "Cow Tipping";
        break;
    case 29:
        return "Vegetable Petch Defender ";
        break;
    case 31:
        return "Barnyard Pool";
        break;
    case 32:
        return "Whack-A-Rack";
        break;
    case 33:
        return "Milk Bar";
        break;
    case 34:
        return "Joy Ride";
        break;
    case 35:
        return "Kitchen";
        break;
    case 36:
        return "Mixing Cocktails";
        break;
    case 37:
        return "Chicken Coop Defender";
        break;
    case 42:
    case 43:
        return "Barnyard Darts";
        break;
    case 55:
        return "Coyote Showdown";
        break;
    case 57:
        return "Loading Screen";
        break;
    default:
        return "Minigame";
        break;
    }
}