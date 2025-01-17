#pragma once

#include "../spell.h"

class AnnieR : public Spell {
public:
    AnnieR() {
        set_base_damage({150, 275, 400});
        set_ap_multiplier(0.75f);
    }
};