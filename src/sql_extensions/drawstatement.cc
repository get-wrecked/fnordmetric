/**
 * This file is part of the "FnordMetric" project
 *   Copyright (c) 2011-2014 Paul Asmuth, Google Inc.
 *
 * FnordMetric is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License v3.0. You should have received a
 * copy of the GNU General Public License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#include <fnordmetric/sql_extensions/drawstatement.h>
#include <fnordmetric/sql_extensions/barchartbuilder.h>

namespace fnordmetric {
namespace query {

void DrawStatement::execute(ui::Canvas* canvas) {
  switch (type_) {
    case T_BAR_CHART:
      return executeWithType<BarChartBuilder>(canvas);
    //case T_LINE_CHART:
    //  return executeWithType<ui::LineChart>(canvas);
  }
}

}
}