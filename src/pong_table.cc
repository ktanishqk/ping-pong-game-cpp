//
// Created by Tanishq Khurana on 4/21/21.
//
#include "pong_table.h"

namespace pingpong {
PongTable::PongTable() {
  ci::app::setWindowSize(kExtendedWindowSize, kWindowSize);
  paddle1_ = Paddle(vec2(5 * kLeftEdge, 6 * kLeftEdge), vec2(4 * kLeftEdge, 6 * kLeftEdge + kDisplayFactor));
  paddle2_ = Paddle(vec2(5 * kLeftEdge, 2 * kLeftEdge), vec2(4 * kLeftEdge, 2 * kLeftEdge + kDisplayFactor));
  ball_ = Ball(20, vec2(kWindowSize / 2, kWindowSize / 2), vec2(0.5, -2));
  game_state_ = GameState::NewGame;
  //score_ = 0;
}
void PongTable::Display() {
  // Making the window for the game
  ci::gl::color(ci::Color(kRed));
  ci::gl::drawSolidRect(
      ci::Rectf(vec2(kLeftEdge, kTopEdge), vec2(kRightEdge, kBottomEdge)));
  // Making the welcome page with the gamer tag and give instructions for the game
  if (game_state_ == GameState::NewGame) {
    ci::gl::drawStringCentered(kWelcomeMessage, vec2(kWindowSize / 2, (kWindowSize - 3 * kDisplayFactor) / 2));
    ci::gl::drawStringCentered(kGamerTagBlue, vec2(kWindowSize / 2, (kWindowSize - 2 * kDisplayFactor) / 2));
    ci::gl::drawStringCentered(kGamerTagGreen, vec2(kWindowSize / 2, (kWindowSize - kDisplayFactor) / 2));
    ci::gl::drawStringCentered(kInstructions, vec2(kWindowSize / 2, (kWindowSize) / 2));
    ci::gl::drawStringCentered(kGreenInstructions,
                               vec2(kWindowSize / 2, (kWindowSize + kDisplayFactor) / 2));
    ci::gl::drawStringCentered(kBlueInstructions,
                               vec2(kWindowSize / 2, (kWindowSize + 2 * kDisplayFactor) / 2));
    // Making the current game state to actually play the game
  } else if (game_state_ == GameState::CurrentGame) {
    //Scoreboard
    ci::gl::color(ci::Color(kWhite));
    ci::gl::drawStrokedRect(ci::Rectf(vec2(kExtendedWindowSize - 2 * kDisplayFactor, kRightEdge/2), vec2(kWindowSize + kDisplayFactor, kRightEdge/4)));
    ci::gl::color(ci::Color(kRed));
    ci::gl::drawSolidRect(
        ci::Rectf(vec2(kLeftEdge, kTopEdge), vec2(kRightEdge, kBottomEdge)));
    ci::gl::color(ci::Color(kBlue));
    paddle1_.Display();
    ci::gl::color(ci::Color(kGreen));
    paddle2_.Display();
    ci::gl::color(ci::Color(kBlack));
    ball_.Display();
    //  } else if (game_state_ == GameState::RestartGame) {
    //    ci::gl::color(ci::Color("red"));
    //    ci::gl::drawSolidRect(
    //        ci::Rectf(vec2(kLeftEdge, kTopEdge), vec2(kRightEdge, kBottomEdge)));
    //    ci::gl::color(ci::Color("blue"));
    //    paddle1_.Display();
    //    ci::gl::color(ci::Color("green"));
    //    paddle2_.Display();
    //    ci::gl::color(ci::Color("black"));
    //    ball_.Display();
    //  }
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
    ci::gl::color(ci::Color("red"));
    ball_.Display();
    hits_++;
  }
  if (((abs(ball_position.y - paddle_lower_position_2.y) < ball_.GetRadius())
       && (paddle_lower_position_2.x < ball_position.x)
       && (ball_position.x < paddle_upper_position_2.x))) {
    current_velocity.y = -current_velocity.y;
    ci::gl::color(ci::Color("green"));
    ball_.Display();
    hits_++;
  }
}
void PongTable::AdvanceOneFrame() {
  if (game_state_ == GameState::CurrentGame) {
    ball_.ChangeBallPosition();
    HandleCollisionWithPaddle();
    HandleCollisionWithWall();
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
      case ci::app::KeyEvent::KEY_BACKSPACE:
        game_state_ = GameState::RestartGame;
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
}// namespace pingpong