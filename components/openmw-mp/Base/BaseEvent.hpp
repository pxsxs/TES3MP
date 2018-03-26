#ifndef OPENMW_BASEEVENT_HPP
#define OPENMW_BASEEVENT_HPP

#include <components/esm/loadcell.hpp>
#include <components/openmw-mp/Base/BaseStructs.hpp>
#include <RakNetTypes.h>

namespace mwmp
{
    struct ContainerItem
    {
        std::string refId;
        int count;
        int charge;
        double enchantmentCharge;

        int actionCount;

        inline bool operator==(const ContainerItem& rhs)
        {
            return refId == rhs.refId && count == rhs.count && charge == rhs.charge && enchantmentCharge == rhs.enchantmentCharge;
        }
    };

    struct WorldObject
    {
        std::string refId;
        int refNumIndex;
        int mpNum;
        int count;
        int charge;
        double enchantmentCharge;
        int goldValue;

        ESM::Position position;

        bool objectState;
        int doorState;
        int lockLevel;
        float scale;

        std::string filename;
        bool allowSkipping;

        std::string animGroup;
        int animMode;

        int index;
        int shortVal;
        float floatVal;
        std::string varName;

        bool isDisarmed;
        bool droppedByPlayer;

        Target master;
        bool hasMaster;

        std::vector<ContainerItem> containerItems;
        unsigned int containerItemCount;

        RakNet::RakNetGUID guid; // only for events that can also affect players
        bool isPlayer;
    };

    class BaseEvent
    {
    public:

        BaseEvent(RakNet::RakNetGUID guid) : guid(guid)
        {

        }

        BaseEvent()
        {

        }

        enum WORLD_ACTION
        {
            SET = 0,
            ADD = 1,
            REMOVE = 2,
            REQUEST = 3
        };

        enum CONTAINER_SUBACTION
        {
            NONE = 0,
            DRAG = 1,
            DROP = 2,
            TAKE_ALL = 3
        };

        RakNet::RakNetGUID guid;
        
        std::vector<WorldObject> worldObjects;
        unsigned int worldObjectCount;

        ESM::Cell cell;
        std::string consoleCommand;

        unsigned char action; // 0 - Clear and set in entirety, 1 - Add item, 2 - Remove item, 3 - Request items
        unsigned char containerSubAction; // 0 - None, 1 - Drag, 2 - Take all

        bool isValid;
    };
}

#endif //OPENMW_BASEEVENT_HPP
