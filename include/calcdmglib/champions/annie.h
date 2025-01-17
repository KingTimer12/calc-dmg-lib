#pragma once

#include "../champion.h"
#include "../spells/annie/q.h"
#include "../spells/annie/w.h"
#include "../spells/annie/e.h"
#include "../spells/annie/r.h"

class Annie : public ChampionDamage<AnnieQ, AnnieW, AnnieE, AnnieR> {
    AnnieQ* get_q() override {
        static AnnieQ *spell;
        return spell;
    }
    
    AnnieW* get_w() override {
        static AnnieW *spell;
        return spell;
    }
    
    AnnieE* get_e() override {
        static AnnieE *spell;
        return spell;
    }
    
    AnnieR* get_r() override {
        static AnnieR *spell;
        return spell;
    }
};