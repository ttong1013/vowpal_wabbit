#pragma once

#include <cstdint>
#include <vector>
#include <string>

#include "v_array.h"
#include "action_score.h"
#include "options.h"


namespace LEARNER {
  template<class T, class E> struct learner;
  using base_learner = learner<char, char>;
}

struct vw;
struct example;

namespace CCB {
  void calculate_and_insert_interactions(
    example* shared, std::vector<example*> actions, std::vector<std::string>& generated_interactions);

  // Each positon in outer array is implicitly the decision corresponding to that index. Each inner array is the result of CB for that call.
  typedef v_array<ACTION_SCORE::action_scores> decision_scores_t;
  
  LEARNER::base_learner* ccb_explore_adf_setup(VW::config::options_i& options, vw& all);
  bool ec_is_example_header(example& ec);
  }
