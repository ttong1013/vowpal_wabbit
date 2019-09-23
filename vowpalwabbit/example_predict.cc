/*
Copyright (c) by respective owners including Yahoo!, Microsoft, and
individual contributors. All rights reserved.  Released under a BSD
license as described in the file LICENSE.
*/

#include "example_predict.h"

safe_example_predict::safe_example_predict()
{
  indices = v_init<namespace_index>();
  ft_offset = 0;
  // feature_space is initialized through constructors
}

safe_example_predict::~safe_example_predict()
{
  indices.delete_v();
  for (size_t i = 0; i < UINT8_MAX; i++) feature_space[i].delete_v();
}

void safe_example_predict::clear()
{
  for (auto ns : indices) feature_space[ns].clear();
  indices.clear();
}
