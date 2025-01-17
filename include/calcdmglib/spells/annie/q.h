#pragma once

#include "../spell.h"

class AnnieQ : public Spell {
public:
    AnnieQ() {
        set_base_damage({80, 115, 150, 185, 220});
        set_ap_multiplier(0.75f);
    }
};