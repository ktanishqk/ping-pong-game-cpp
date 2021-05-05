//
// Created by Tanishq Khurana on 4/21/21.
//

#ifndef FINAL_PROJECT_KTANISHQK_PONG_TABLE_H
#define FINAL_PROJECT_KTANISHQK_PONG_TABLE_H

#endif//FINAL_PROJECT_KTANISHQK_PONG_TABLE_H
#pragma once

#include "../../../include/cinder/app/App.h"
#include "../../../include/cinder/app/KeyEvent.h"
#include "../../../include/cinder/app/MouseEvent.h"
#include "../../../include/glm/vec2.hpp"
#include "pong_table.h"
#include <ball.h>
#include <cinder/Color.h>
#include <cinder/Text.h>
#include <paddle.h>
#include <string>
using glm::vec2;

namespace pingpong {

enum class GameState {
  NewGamePvP,
  NewGameCvP,
  CurrentGamePvP,
  CurrentGameCvP,
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
   * Function to handle movement of the paddle using input
   */
  void HandlePlayerMovement(const ci::app::KeyEvent &event);
  /**
   * Function that manages the score of the game
   */
  void ManageBallOffTable();
  /**
   * Function that sets or resets the game
   */
  void SetGame();
  /**
    * Display for scoreboard of the game
    */
  void DisplayScoreboard();
  /**
   * Simple getter for the ball within the ping pong table
   */
  Ball GetBall();
  /**
   * Simple getter for the first paddle within the ping pong table
   */
  Paddle GetPaddle1();
  /**
   * Simple getter for the second paddle within the ping pong table
   */
  Paddle GetPaddle2();

 private:
  std::string blue_player_gamer_tag_;
  std::string green_player_gamer_tag_;
  GameState game_state_ = GameState::NewGamePvP;
  //std::size_t score_;
  Paddle paddle1_;
  Paddle paddle2_;
  Ball ball_;
  const std::size_t kExtendedWindowSize = 1200;
  // Size of the window
  const std::size_t kWindowSize = 900;
  const std::size_t kLeftEdge = 100;
  // This is the right edge coordinate
  const std::size_t kRightEdge = 800;
  // This is the top edge coordinate
  const std::size_t kTopEdge = 100;
  // This is the bottom edge coordinate
  const std::size_t kBottomEdge = 800;
  // This is the Coordinate required for scoreboard rectangle
  const std::size_t kScoreboard = 1025;
  const std::string kWelcomeMessage = "Welcome to Ping-Pong!";
  const std::string kGamerTagBlue = "Player 1 Gamertag: ";
  const std::string kGamerTagGreen = "Player 2 Gamertag: ";
  const std::string kComp = "Computer";
  const std::string kInstructions = "INSTRUCTIONS:";
  const std::string kGreenInstructions = "For GreenPlayer, use a and d keys to move the paddle left or right.";
  const std::string kBlueInstructions = "For BluePlayer, use the the arrow keys to move the paddle left or right.";
  const char *const kWhite = "white";
  const char *const kRed = "red";
  const char *const kBlue = "blue";
  const char *const kGreen = "green";
  const char *const kBlack = "black";
  const size_t kDisplayFactor = 50;
  size_t score_green_ = 0;
  size_t score_blue_ = 0;
};
}// namespace pingpong