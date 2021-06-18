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
glm::vec2& Paddle::GetTopLeftPosition(){
  return top_left_position_;
}
void Paddle::SetTopLeftPosition(glm::vec2& position) {
  top_left_position_ = position;
}
glm::vec2& Paddle::GetBottomRightPosition(){
  return bottom_right_position_;
}
void Paddle::SetBottomRightPosition(glm::vec2& position) {
  bottom_right_position_ = position;
}
void Paddle::AdvanceFrametoLeft() {
  bottom_right_position_.x++;
  top_left_position_.x++;
}
void Paddle::AdvanceFrametoRight() {
  bottom_right_position_.x--;
  top_left_position_.x--;
}
}

