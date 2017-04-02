//
// Created by koncord on 03.04.17.
//

#ifndef OPENMW_PROCESSORSCRIPTLOCALSHORT_HPP
#define OPENMW_PROCESSORSCRIPTLOCALSHORT_HPP

#include "apps/openmw-mp/WorldProcessor.hpp"

namespace mwmp
{
    class ProcessorScriptLocalShort : public WorldProcessor
    {
    public:
        ProcessorScriptLocalShort()
        {
            BPP_INIT(ID_SCRIPT_LOCAL_SHORT)
        }

        void Do(WorldPacket &packet, Player &player, BaseEvent &event) override
        {
            packet.Send(true);
        }
    };
}

#endif //OPENMW_PROCESSORSCRIPTLOCALSHORT_HPP