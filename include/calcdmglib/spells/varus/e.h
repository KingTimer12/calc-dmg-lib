#pragma once

#include "../spell.h"

class VarusE : public Spell {
public:
    VarusE() {
        set_base_damage({60, 100, 140, 180, 220});
        set_ap_multiplier(0.9f);
    }
};