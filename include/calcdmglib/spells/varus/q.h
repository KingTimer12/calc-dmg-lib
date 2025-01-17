#pragma once

#include "../spell.h"
#include "stacks.h"
#include <vector>

class VarusQ : public Spell {
private:
    std::vector<float> w_min_base_percent, min_base_percent, max_base_percent;
    
    void set_w_min_base_percent(std::vector<float> w_min_base_percent) {
        this->w_min_base_percent = w_min_base_percent;
    }
    
    void set_min_base_percent(std::vector<float> min_base_percent) {
        this->min_base_percent = min_base_percent;
    }
    
    void set_max_base_percent(std::vector<float> max_base_percent) {
        this->max_base_percent = max_base_percent;
    }
    
public:
    VarusQ() {
        set_w_min_base_percent({0.03, 0.035, 0.04, 0.045, 0.05});
        set_min_base_damage({ 10, 46.67, 83.33, 120, 156.67 });
        set_max_base_damage({ 15, 70, 125, 180, 235 });
        set_ap_multiplier(0.75f);
    }
};