//
// Created by Tanishq Khurana on 4/20/21.
//
#include "ball.h"
namespace pingpong {
Ball::Ball(int radius, ci::Color color, glm::vec2 position, glm::vec2 velocity) {
  this->radius_ = radius;
  this->color_ = color;
  this->velocity_ = velocity;
  this->position_ = position;
}
glm::vec2 Ball::GetPosition() {
  return position_;
}

glm::vec2 Ball::GetVelocity() {
  return velocity_;
}

int Ball::GetRadius() {
  return radius_;
}

ci::Color Ball::GetColor() {
  return color_;
}

void Ball::SetPosition(const glm::vec2& position) {
  this->position_ = position;
}

void Ball::SetVelocity(const glm::vec2& velocity) {
  this->velocity_ = velocity;
}

void Ball::SetColor(const ci::Color& color) {
  this->color_ = color;
}

void Ball::SetRadius(int radius) {
  this->radius_ = radius;
}
void Ball::ChangePosition() {

}
//void Ball::Display() {
//  ci::gl::color("blue");
//  ci::gl::drawSolidCircle()
//}
}