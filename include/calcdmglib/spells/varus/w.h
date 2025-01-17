#pragma once

#include "../spell.h"
#include <algorithm>
#include <cmath>

class VarusW : public Spell {
private:
    float time_cast, game_time, target_max_hp, target_current_hp, damage;
    
    float get_w(float casting_time) {
        float percent = floorf(floorf(std::min<uint8_t>(13, this->get_level()) / 3.0f) - 0.3f);
        float percent_based_on_level = 0.06 + (0.02 * percent); // X% = 6 até 14
        float miss_hp = this->target_max_hp - this->target_current_hp;
        float no_stacks_dmg = percent_based_on_level * (miss_hp + this->damage);
        float casting_dmg = 0.05 * std::min<float>(10, casting_dmg / 0.2f);
        return no_stacks_dmg + (no_stacks_dmg * casting_dmg);
    }
    
    float get_max_w() {
        return get_w(2);
    }
    
public:
    VarusW() {
        // set_min_base_percent({0.03, 0.035, 0.04, 0.045, 0.05});
        // set_max_base_percent({0.135, 0.1575, 0.18, 0.2025, 0.225});
    }
    
    VarusW* set_time_cast(float time_cast) {
        this->time_cast = time_cast;
        return this;
    }
    
    VarusW* set_game_time(float game_time) {
        this->game_time = game_time;
        return this;
    }
    
    float get_damage() override {
        if (this->time_cast == 0.0f || this->game_time == 0.0f) return 0.0f;
        float casting_time = this->game_time - this->time_cast;
        if (casting_time <= 0) return get_max_w();
        return get_w(casting_time);
    }
};