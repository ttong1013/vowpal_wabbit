/*
Copyright (c) by respective owners including Yahoo!, Microsoft, and
individual contributors. All rights reserved.  Released under a BSD
license as described in the file LICENSE.
 */
#pragma once

namespace CSOAA
{
LEARNER::base_learner* csoaa_setup(VW::config::options_i& options, vw& all);

LEARNER::base_learner* csldf_setup(VW::config::options_i& options, vw& all);
struct csoaa;
void finish_example(vw& all, csoaa&, example& ec);
}  // namespace CSOAA
