#pragma once

#include <cstdint>
#include <vector>

class Spell {
private:
    std::vector<float> baseDamage;
    std::vector<float> totalBaseDamage;
    std::vector<float> maxBaseDamage;
    std::vector<float> minBaseDamage;
    
    uint8_t level;
    float ap, ad;
    float apMultipler, adMultiplier;
    
protected:
    Spell* set_base_damage(std::vector<float> baseDamage) {
        this->baseDamage = baseDamage;
        return this;
    }
    
    Spell* set_total_base_damage(std::vector<float> totalBaseDamage) {
        this->totalBaseDamage = totalBaseDamage;
        return this;
    }
    
    Spell* set_max_base_damage(std::vector<float> maxBaseDamage) {
        this->maxBaseDamage = maxBaseDamage;
        return this;
    }
    
    Spell* set_min_base_damage(std::vector<float> minBaseDamage) {
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
    
    float get_ap() {
        return ap;
    }
    
    float get_ad() {
        return ad;
    }
    
    uint8_t get_level() {
        return level;
    }
    
public:
    Spell() = default;
    ~Spell() = default;
    
    virtual float get_damage() {
        float dmg = 0;
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
    
    Spell* set_ap(float ap) {
        this->ap = ap;
        return this;
    }
    
    Spell* set_ad(float ad) {
        this->ad = ad;
        return this;
    }
};