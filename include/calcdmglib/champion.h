#pragma once

#include "spells/spell.h"

template <class Q, class W, class E, class R>
class ChampionDamage {
  virtual Q* get_q() = 0;
  virtual W* get_w() = 0;
  virtual E* get_e() = 0;
  virtual R* get_r() = 0;
};