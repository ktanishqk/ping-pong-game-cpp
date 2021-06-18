//
// Created by Tanishq Khurana on 4/20/21.
//
#include "cinder/gl/gl.h"
#include <cinder/Color.h>

#pragma once
namespace pingpong {
class Paddle {
  /**
   * Class handling the functionality of the paddle in the game
   */
 private:
  /**
   * Stores the vector representing the top left coordinate of the paddle
   */
  glm::vec2 top_left_position_;
  /**
   * Stores the vector representing the bottom right coordinate of the paddle
   */
  glm::vec2 bottom_right_position_;
  ci::Color color_;
 public:
  /**
   * Default Constructor for the Paddle
   */
  Paddle();
  /**
   * Constructor required for making the paddle with the following parameters
   * @param top_right_position
   * @param bottom_left_position
   */
  Paddle(const glm::vec2& top_right_position, const glm::vec2& bottom_left_position, ci::Color color);
  /**
   * Simple getter for the top left position of the paddle
   * @return the top left position vector
   */
  glm::vec2 &GetTopLeftPosition();
/**
 * Simple getter for the bottom right position fo the paddle
 * @return the bottom right vector
 */
  glm::vec2 &GetBottomRightPosition();
  /**
   * Function that advances the paddle to the right
   */
  void AdvanceFrametoRight();
  /**
   * Funtion that advances the paddle to the left
   */
  void AdvanceFrametoLeft();
  /**
   * Display function for the paddle
   */
  void Display();
  /**
   * Simple getter for the color of the paddle
   */
  ci::Color &GetColor();
};
}

#ifndef FINAL_PROJECT_KTANISHQK_PADDLE_H
#define FINAL_PROJECT_KTANISHQK_PADDLE_H

#endif //FINAL_PROJECT_KTANISHQK_PADDLE_H
