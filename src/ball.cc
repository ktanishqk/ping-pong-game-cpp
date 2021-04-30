//
// Created by Tanishq Khurana on 4/20/21.
//

#include "ball.h"
namespace pingpong {
Ball::Ball(int radius, glm::vec2 position, glm::vec2 velocity) {
  this->radius_ = radius;
  this->velocity_ = velocity;
  this->position_ = position;
}
Ball::Ball() {

}
glm::vec2 Ball::GetPosition() {
  return position_;
}

glm::vec2& Ball::GetVelocity() {
  return velocity_;
}
int Ball::GetRadius() {
  return radius_;
}
void Ball::ChangeBallPosition() {
    position_.x+= velocity_.x;
    position_.y-= velocity_.y;
}
void Ball::Display() {
    ci::gl::drawSolidCircle(position_, radius_);
}
}