/**
 *
 * \section COPYRIGHT
 *
 * Copyright 2013-2015 Software Radio Systems Limited
 *
 * \section LICENSE
 *
 * This file is part of the srsUE library.
 *
 * srsUE is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * srsUE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * A copy of the GNU Affero General Public License can be found in
 * the LICENSE file in the top-level directory of this distribution
 * and at http://www.gnu.org/licenses/.
 *
 */

/******************************************************************************
 * File:        metrics_stdout.h
 * Description: Metrics class printing to stdout.
 *****************************************************************************/

#ifndef METRICS_STDOUT_H
#define METRICS_STDOUT_H

#include <pthread.h>
#include <stdint.h>
#include <string>

#include "srslte/common/metrics_hub.h"
#include "ue_metrics_interface.h"

namespace srsue {

class metrics_stdout : public srslte::metrics_listener<ue_metrics_t>
{
public:
  metrics_stdout();

  void toggle_print(bool b);
  void set_metrics(ue_metrics_t &m, float report_period_secs);

private:
  std::string float_to_string(float f, int digits);
  std::string float_to_eng_string(float f, int digits);
  std::string int_to_eng_string(int f, int digits);

  bool          do_print;
  uint8_t       n_reports;
};

} // namespace srsue

#endif // METRICS_STDOUT_H
