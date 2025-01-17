#pragma once

#include <cstdint>
#include <vector>

class Spell {
private:
    std::vector<uint16_t> baseDamage;
    std::vector<uint16_t> totalBaseDamage;
    std::vector<uint16_t> maxBaseDamage;
    std::vector<uint16_t> minBaseDamage;
    
    uint8_t level;
    float ap, ad;
    float apMultipler, adMultiplier;
    
protected:
    Spell* set_base_damage(std::vector<uint16_t> baseDamage) {
        this->baseDamage = baseDamage;
        return this;
    }
    
    Spell* set_total_base_damage(std::vector<uint16_t> totalBaseDamage) {
        this->totalBaseDamage = totalBaseDamage;
        return this;
    }
    
    Spell* set_max_base_damage(std::vector<uint16_t> maxBaseDamage) {
        this->maxBaseDamage = maxBaseDamage;
        return this;
    }
    
    Spell* set_min_base_damage(std::vector<uint16_t> minBaseDamage) {
        this->minBaseDamage = minBaseDamage;
        return this;
    }
    
    Spell* set_ap_multiplier(float apMultiplier) {
        this->apMultipler = apMultiplier;
        return this;
    }
    
    Spell* set_ad_multiplier(float adMultiplier) {
        this->adMultiplier = adMultiplier;
        return this;
    }
    
public:
    Spell() = default;
    ~Spell() = default;
    
    float get_damage() {
        uint16_t dmg = 0;
        if (!baseDamage.empty()) dmg = baseDamage[level-1];
        else if (!totalBaseDamage.empty()) dmg = totalBaseDamage[level-1];
        else if (!maxBaseDamage.empty()) dmg = maxBaseDamage[level-1];
        else if (!minBaseDamage.empty()) dmg = minBaseDamage[level-1];
        else if (maxBaseDamage.empty() && minBaseDamage.empty()) dmg = maxBaseDamage[level-1] + minBaseDamage[level-1];
        if (dmg == 0) return 0.0f;
        return dmg + (ap * apMultipler) + (ad * adMultiplier);
    }
    
    Spell* set_level(uint8_t level) {
        this->level = level;
        return this;
    }
};