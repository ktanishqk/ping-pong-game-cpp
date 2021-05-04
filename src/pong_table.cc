//
// Created by Tanishq Khurana on 4/21/21.
//
#include "pong_table.h"

namespace pingpong {
PongTable::PongTable() {
  ci::app::setWindowSize(kExtendedWindowSize, kWindowSize);
  SetGame();
}
void PongTable::SetGame() {
  paddle1_ = Paddle(vec2(5 * kLeftEdge, 6 * kLeftEdge), vec2(4 * kLeftEdge, 6 * kLeftEdge + kDisplayFactor), kBlue);
  paddle2_ = Paddle(vec2(5 * kLeftEdge, 2 * kLeftEdge), vec2(4 * kLeftEdge, 2 * kLeftEdge + kDisplayFactor), kGreen);
  ball_ = Ball(20, vec2(kWindowSize / 2, kWindowSize / 2), vec2(0.5, -2), ci::Color(kBlack));
}
void PongTable::Display() {
  cinder::Font welcome_font("times new roman", 50);
  cinder::Font gamertag_font("times new roman", 20);
  cinder::Font instructions_font("times new roman", 30);
  // Making the window for the game
  ci::gl::color(ci::Color(kRed));
  ci::gl::drawSolidRect(
      ci::Rectf(vec2(kLeftEdge, kTopEdge), vec2(kRightEdge, kBottomEdge)));
  // Making the welcome page with the gamer tag and give instructions for the game
  if (game_state_ == GameState::NewGame) {
    ci::gl::drawStringCentered(kWelcomeMessage, vec2(kWindowSize / 2, (kWindowSize - 5 * kDisplayFactor) / 2), ci::ColorA(1, 1, 1, 1), welcome_font);
    ci::gl::drawStringCentered(kGamerTagBlue, vec2(kWindowSize / 2, (kWindowSize - 2 * kDisplayFactor) / 2), ci::ColorA(1, 1, 1, 1), gamertag_font);
    ci::gl::drawStringCentered(kGamerTagGreen, vec2(kWindowSize / 2, (kWindowSize - kDisplayFactor) / 2), ci::ColorA(1, 1, 1, 1), gamertag_font);
    ci::gl::drawStringCentered(kInstructions, vec2(kWindowSize / 2, (kWindowSize + kDisplayFactor) / 2), ci::ColorA(1, 1, 1, 1), instructions_font);
    ci::gl::drawStringCentered(kGreenInstructions,
                               vec2(kWindowSize / 2, (kWindowSize + 3 * kDisplayFactor) / 2), ci::ColorA(1, 1, 1, 1), gamertag_font);
    ci::gl::drawStringCentered(kBlueInstructions,
                               vec2(kWindowSize / 2, (kWindowSize + 4 * kDisplayFactor) / 2), ci::ColorA(1, 1, 1, 1), gamertag_font);
    // Making the current game state to actually play the game
  } else if (game_state_ == GameState::CurrentGame) {
    DisplayScoreboard();
    ci::gl::color(ci::Color(kRed));
    ci::gl::drawSolidRect(
        ci::Rectf(vec2(kLeftEdge, kTopEdge), vec2(kRightEdge, kBottomEdge)));
    paddle1_.Display();
    paddle2_.Display();
    ball_.Display();
  }
}

void PongTable::MovePaddle1Left() {
  if (paddle1_.GetBottomRightPosition().x > 100) {
    paddle1_.AdvanceFrametoLeft();
  }
}
void PongTable::MovePaddle1Right() {
  if (paddle1_.GetTopLeftPosition().x < 800) {
    paddle1_.AdvanceFrametoRight();
  }
}

void PongTable::MovePaddle2Left() {
  if (paddle2_.GetBottomRightPosition().x > 100) {
    paddle2_.AdvanceFrametoLeft();
  }
}

void PongTable::MovePaddle2Right() {
  if (paddle2_.GetTopLeftPosition().x < 800) {
    paddle2_.AdvanceFrametoRight();
  }
}
void PongTable::HandleCollisionWithWall() {
  glm::vec2 current_position = ball_.GetPosition();
  glm::vec2 &current_velocity = ball_.GetVelocity();
  float radius = ball_.GetRadius();
  if ((abs(current_position.x - kLeftEdge) < radius) || (abs(current_position.x - kRightEdge) < radius)) {
    current_velocity.x = -current_velocity.x;
  }
}
void PongTable::HandleCollisionWithPaddle() {
  ci::Color &color = ball_.GetColor();
  glm::vec2 ball_position = ball_.GetPosition();
  glm::vec2 &current_velocity = ball_.GetVelocity();
  glm::vec2 paddle_lower_position = paddle1_.GetBottomRightPosition();
  glm::vec2 paddle_upper_position = paddle1_.GetTopLeftPosition();
  glm::vec2 paddle_lower_position_2 = paddle2_.GetBottomRightPosition();
  glm::vec2 paddle_upper_position_2 = paddle2_.GetTopLeftPosition();
  if (((abs(ball_position.y - paddle_upper_position.y) < ball_.GetRadius())
       && (paddle_lower_position.x < ball_position.x)
       && (ball_position.x < paddle_upper_position.x))) {
    current_velocity.y = -current_velocity.y;
    color = paddle1_.GetColor();
    hits_++;
  }
  if (((abs(ball_position.y - paddle_lower_position_2.y) < ball_.GetRadius())
       && (paddle_lower_position_2.x < ball_position.x)
       && (ball_position.x < paddle_upper_position_2.x))) {
    current_velocity.y = -current_velocity.y;
    color = paddle2_.GetColor();
    hits_++;
  }
}
void PongTable::AdvanceOneFrame() {
  if (game_state_ == GameState::CurrentGame) {
    ball_.ChangeBallPosition();
    HandleCollisionWithPaddle();
    HandleCollisionWithWall();
    ManageGameScore();
  }
}
void PongTable::HandlePlayerMovement(const ci::app::KeyEvent &event) {
  if (game_state_ == GameState::CurrentGame) {
    switch (event.getCode()) {
      case ci::app::KeyEvent::KEY_RIGHT:
        MovePaddle1Right();
        break;

      case ci::app::KeyEvent::KEY_LEFT:
        MovePaddle1Left();
        break;

      case ci::app::KeyEvent::KEY_a:
        MovePaddle2Left();
        break;

      case ci::app::KeyEvent::KEY_d:
        MovePaddle2Right();
        break;
      case ci::app::KeyEvent::KEY_SPACE:
        SetGame();
        break;
    }
  } else if (game_state_ == GameState::NewGame) {
    switch (event.getCode()) {
      case ci::app::KeyEvent::KEY_SPACE:
        game_state_ = GameState::CurrentGame;
        break;
    }
  }
}
void PongTable::ManageGameScore() {
  if (ball_.GetPosition().y == kTopEdge) {
    score_blue_++;
  }
  if (ball_.GetPosition().y == kBottomEdge) {
    score_green_++;
  }
}
void PongTable::DisplayScoreboard() {
  ci::gl::color(ci::Color(kWhite));
  ci::gl::drawStrokedRect(ci::Rectf(vec2(kExtendedWindowSize - 2 * kDisplayFactor, kRightEdge / 2), vec2(kWindowSize + kDisplayFactor, kRightEdge / 4)));
  ci::gl::drawStringCentered("SCOREBOARD", vec2(1025, (kRightEdge) / 3.5));
  ci::gl::drawStringCentered("BluePlayer Score: " + std::to_string(score_blue_), vec2(1025, (kRightEdge) / 3));
  ci::gl::drawStringCentered("GreenPlayer Score: " + std::to_string(score_green_), vec2(1025, (kRightEdge) / 2.5));
}
}// namespace pingpong