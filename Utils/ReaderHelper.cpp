#include "ReaderHelper.h"

ReaderHelper::ReaderHelper(uintptr_t base)
{
    BaseAddress = base;
}

uintptr_t ReaderHelper::ReadInteger(uintptr_t baseAddress, const uintptr_t offsets[], int size)
{
    uintptr_t addr = baseAddress;

    int lastElem = size - 1;
    for (int i = 0; i < lastElem; i++)
    {
        if (addr != NULL) addr = *(uintptr_t*)(addr + offsets[i]);

        if (addr >= 0xFFFFFFF) return -1;
    }

    if (addr != NULL && addr < 0xFFFFFFF) addr = *(uintptr_t*)(addr + offsets[lastElem]);

    return addr;
}

Vector3 ReaderHelper::ReadVector3(uintptr_t baseAddress, const uintptr_t offsets[], int size) {
    Vector3 vec;

    uintptr_t addr = baseAddress;

    for (int i = 0; i < size; i++)
    {
        if (addr != NULL) addr = *(uintptr_t*)(addr + offsets[i]);
        if (addr >= 0xFFFFFFF) return vec;
    }

    std::cout << "Addr: " << std::hex << addr << std::endl;

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