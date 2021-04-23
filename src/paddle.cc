//
// Created by Tanishq Khurana on 4/20/21.
//

#include "paddle.h"
namespace pingpong {
Paddle::Paddle() {
}
Paddle::Paddle(glm::vec2 top_left_position, glm::vec2 bottom_right_position) {

  this->top_left_position_ = top_left_position;
  this->bottom_right_position_ = bottom_right_position;
}
const glm::vec2& Paddle::GetTopLeftPosition() const {
  return top_left_position_;
}
void Paddle::SetTopLeftPosition(const glm::vec2& position) {
  top_left_position_ = position;
}
const glm::vec2& Paddle::GetBottomRightPosition() const {
  return bottom_right_position_;
}
void Paddle::SetBottomRightPosition(const glm::vec2& position) {
  bottom_right_position_ = position;
}
}

