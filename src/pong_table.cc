//
// Created by Tanishq Khurana on 4/21/21.
//
#include "pong_table.h"

#include <paddle.h>

namespace pingpong {
PongTable::PongTable(int kTopEdge, int kBottomEdge, int kLeftEdge,
                     int kRightEdge) {
  this->kTopEdge = kTopEdge;
  this->kLeftEdge = kLeftEdge;
  this->kBottomEdge = kBottomEdge;
  this->kRightEdge = kRightEdge;
}
void PongTable::Display() const {
  ci::gl::drawStrokedRect(
      ci::Rectf(vec2(kLeftEdge, kTopEdge),
                     vec2(kRightEdge, kBottomEdge)));
}
}  // namespace pingpong