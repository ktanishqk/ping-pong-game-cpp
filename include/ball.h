//
// Created by Tanishq Khurana on 4/20/21.
//

#ifndef FINAL_PROJECT_KTANISHQK_BALL_H
#define FINAL_PROJECT_KTANISHQK_BALL_H
#pragma once
#include <cinder/Color.h>
using glm::vec2;

namespace pingpong {
class Ball {
 private:
  int radius_;
  ci::Color color_;
  glm::vec2 velocity_;
  glm::vec2 position_;

 public:
  /**
   * Constructor for a ball
   */
  Ball(int radius, ci::Color color, glm::vec2 position, glm::vec2 velocity);
  Ball();
  void Display();
  /**
   *
   */
  glm::vec2 GetPosition();

  /**
   *
   */
  glm::vec2 GetVelocity();

  /**
   *
   */
  int GetRadius();

  /**
   *
   */
  ci::Color GetColor();

  /**
   *
   */
  void SetPosition(const glm::vec2& position_);

  /**
   *
   */
  void SetVelocity(const glm::vec2& velocity_);

  /**
   *
   */
  void SetRadius(int radius_);

  /**
   *
   */
  void SetColor(const ci::Color& color_);
};
}  // namespace pingpong
#endif  // FINAL_PROJECT_KTANISHQK_BALL_H
