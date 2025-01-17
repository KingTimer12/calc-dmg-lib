#pragma once

#include "../spell.h"

class AnnieQ : public Spell {
public:
    AnnieQ() {
        set_base_damage({30, 55, 80, 105, 130});
        set_ap_multiplier(0.4f);
    }
};