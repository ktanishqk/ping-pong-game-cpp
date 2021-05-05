//
// Created by Tanishq Khurana on 4/20/21.
//

#include "paddle.h"
namespace pingpong {
Paddle::Paddle() {
}
Paddle::Paddle(const glm::vec2 &top_left_position, const glm::vec2 &bottom_right_position, ci::Color color) {
  this->top_left_position_ = top_left_position;
  this->bottom_right_position_ = bottom_right_position;
  this->color_ = color;
}
glm::vec2 &Paddle::GetTopLeftPosition() {
  return top_left_position_;
}
glm::vec2 &Paddle::GetBottomRightPosition() {
  return bottom_right_position_;
}
void Paddle::AdvanceFrametoLeft() {
  bottom_right_position_.x -= 40;
  top_left_position_.x -= 40;
}
void Paddle::AdvanceFrametoRight() {
  bottom_right_position_.x += 40;
  top_left_position_.x += 40;
}
void Paddle::Display() {
  ci::gl::color(color_);
  ci::gl::drawSolidRect(ci::Rectf(top_left_position_, bottom_right_position_));
}
ci::Color &Paddle::GetColor() {
  return color_;
}
}// namespace pingpong
