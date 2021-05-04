//
// Created by Tanishq Khurana on 4/21/21.
//

#ifndef FINAL_PROJECT_KTANISHQK_PONG_TABLE_H
#define FINAL_PROJECT_KTANISHQK_PONG_TABLE_H

#endif //FINAL_PROJECT_KTANISHQK_PONG_TABLE_H
#pragma once

#include <cinder/Color.h>
#include <paddle.h>
#include <ball.h>
#include <cinder/Text.h>
#include <string>
#include "../../../include/cinder/app/App.h"
#include "../../../include/glm/vec2.hpp"
#include "../../../include/cinder/app/MouseEvent.h"
#include "../../../include/cinder/app/KeyEvent.h"
#include "pong_table.h"
using glm::vec2;

namespace pingpong {

enum class GameState {
  NewGame,
  CurrentGame,
  RestartGame,
};

class PongTable {
 public:
  /**
   * Constructor for a ball
   */
  PongTable();
  /**
   * Displays the pong table
   */
  void Display();
  /**
   * Function to move paddle 1 to the left
   */
  void MovePaddle1Left();
  /**
   * Function to move paddle 1 to the right
   */
  void MovePaddle1Right();
  /**
   * Function to move paddle 2 to the left
   */
  void MovePaddle2Left();
  /**
   * Function to move paddle 2 to the right
   */
  void MovePaddle2Right();
  /**
   * Function that handles the collision of the ball with the walls of the ping pong table
   */
  void HandleCollisionWithWall();
  /**
   * Function that handles the collision of the ball with the paddles on the ping pong table
   */
  void HandleCollisionWithPaddle();
  /**
   * Advance One Frame function
   */
  void AdvanceOneFrame();
  /**
   * Function that restarts the game
   */
  void RestartGame();
  /**
   * Function to handle movement of the paddle using input
   */
  void HandlePlayerMovement(const ci::app::KeyEvent &event);

 private:
  const std::size_t kExtendedWindowSize = 1200;
  GameState game_state_;
  size_t hits_;
  //std::size_t score_;
  Paddle paddle1_;
  Paddle paddle2_;
  Ball ball_;
  // Size of the window
  const std::size_t kWindowSize = 900;
  const std::size_t kLeftEdge = 100;
  // This is the right edge coordinate
  const std::size_t kRightEdge = 800;
  // This is the top edge coordinate
  const std::size_t kTopEdge = 100;
  // This is the bottom edge coordinate
  const std::size_t kBottomEdge = 800;
  const std::string kWelcomeMessage = "Welcome to Ping-Pong!";
  const std::string kGamerTagBlue = "Player 1 Gamertag: BluePlayer";
  const std::string kGamerTagGreen = "Player 2 Gamertag: GreenPlayer";
  const std::string kInstructions = "INSTRUCTIONS:";
  const std::string kGreenInstructions = "For GreenPlayer, use the arrow keys to move the paddle left or right.";
  const std::string kBlueInstructions = "For BluePlayer, use the a and d keys to move the paddle left or right.";
  const char *const  kWhite = "white";
  const char *const  kRed = "red";
  const char *const  kBlue = "blue";
  const char *const  kGreen = "green";
  const char *const  kBlack = "black";
  const size_t kDisplayFactor = 50;
};
}