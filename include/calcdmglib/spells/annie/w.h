#pragma once

#include "../spell.h"

class AnnieW : public Spell {
public:
    AnnieW() {
        set_base_damage({70, 115, 160, 205, 250});
        set_ap_multiplier(0.85f);
    }
};