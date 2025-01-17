#pragma once

#include <cstdint>
#include <vector>

class Stacks {
private:
    std::vector<float> w_min_base_percent;
    
    void set_w_min_base_percent(std::vector<float> w_min_base_percent) {
        this->w_min_base_percent = w_min_base_percent;
    }
    
public:
    Stacks() {
        set_w_min_base_percent({0.03, 0.035, 0.04, 0.045, 0.05});
    }

    float get_passive_dmg(float &ap, uint8_t &level, float &max_hp, float &casting_time) {
        float ap_scaling = 0.015f * (ap / 100.0f);
        float base_percent = this->w_min_base_percent[level - 1] + ap_scaling;
        float stacks_dmg = base_percent * max_hp;
        float casting_dmg = 0.05f * std::min<float>(10, casting_time / 0.2f);
        return stacks_dmg + (stacks_dmg * casting_dmg);
    }
};