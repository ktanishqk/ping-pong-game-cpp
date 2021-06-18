//
// Created by Tanishq Khurana on 4/20/21.
//

#ifndef FINAL_PROJECT_KTANISHQK_BALL_H
#define FINAL_PROJECT_KTANISHQK_BALL_H
#pragma once
#include "cinder/gl/gl.h"
#include <cinder/Color.h>
using glm::vec2;
namespace pingpong {
class Ball {
  /**
   * Class handling the ball functionality in the game
   */
 private:
  int radius_;
  glm::vec2 velocity_;
  glm::vec2 position_;
  ci::Color color_;

 public:
  /**
   * Default constructor for the ball
   */
  Ball();
  /**
   * Constructor for a ball that sets the radius, position, and the velocity of the ball
   */
  Ball(int radius, const glm::vec2& position, const glm::vec2& velocity, const ci::Color& color);
  /**
   * Display function for the ball
   */
  void Display();
  /**
   * simple getter for the position of the ball
   * @return the position vector of the ball
   */
  glm::vec2 GetPosition();

  /**
   * Simple getter of the velocity of the ball
   * @return the velocity vector of the ball
   */
  glm::vec2 &GetVelocity();
  /**
 * Simple getter for the radius of the ball
 * @return integer representing the radius of the ball
 */
  int &GetRadius();
  /**
   * Change the position of the ball to make the ball move
   */
  void ChangeBallPosition();
  /**
   * Simple Getter for the color of the ball
   */
   ci::Color &GetColor();
};
}// namespace pingpong
#endif// FINAL_PROJECT_KTANISHQK_BALL_H
