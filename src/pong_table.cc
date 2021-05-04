//
// Created by Tanishq Khurana on 4/21/21.
//
#include "pong_table.h"

namespace pingpong {
PongTable::PongTable() {
  ci::app::setWindowSize(kWindowSize, kWindowSize);
  paddle1_ = Paddle(vec2(500, 600), vec2(400, 650));
  paddle2_ = Paddle(vec2(500, 200), vec2(400, 250));
  ball_ = Ball(20, vec2(kWindowSize/2, kWindowSize/2), vec2(0.5, -1));
  game_state_ = GameState::NewGame;
  //score_ = 0;
}
void PongTable::Display() {
  ci::gl::color(ci::Color("red"));
  ci::gl::drawSolidRect(
      ci::Rectf(vec2(kLeftEdge, kTopEdge), vec2(kRightEdge, kBottomEdge)));
  if (game_state_ == GameState::NewGame) {
    ci::gl::drawStringCentered("Welcome to Ping-Pong! Gamertag: ", vec2(kWindowSize / 2, kWindowSize / 2));
    game_state_ = GameState::CurrentGame;
  } else if (game_state_ == GameState::CurrentGame) {
    ci::gl::color(ci::Color("red"));
    ci::gl::drawSolidRect(
        ci::Rectf(vec2(kLeftEdge, kTopEdge), vec2(kRightEdge, kBottomEdge)));
    ci::gl::color(ci::Color("blue"));
    paddle1_.Display();
    ci::gl::color(ci::Color("green"));
    paddle2_.Display();
    ci::gl::color(ci::Color("black"));
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
  if ((abs(current_position.x - kLeftEdge) < radius) ||
      (abs(current_position.x - kRightEdge) < radius)) {
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
    hits_++;
  }
  if (((abs(ball_position.y - paddle_lower_position_2.y) < ball_.GetRadius())
      && (paddle_lower_position_2.x < ball_position.x)
      && (ball_position.x < paddle_upper_position_2.x))) {
    current_velocity.y = -current_velocity.y;
    hits_++;
  }
}
void PongTable::AdvanceOneFrame() {
  ball_.ChangeBallPosition();
  HandleCollisionWithPaddle();
  HandleCollisionWithWall();
}
void PongTable::HandlePlayerMovement(ci::app::KeyEvent event) {
  if (game_state_ == GameState::CurrentGame) {
    switch (event.getCode()) {
      case ci::app::KeyEvent::KEY_RIGHT:MovePaddle1Right();
        break;

      case ci::app::KeyEvent::KEY_LEFT:MovePaddle1Left();
        break;

      case ci::app::KeyEvent::KEY_a:MovePaddle2Left();
        break;

      case ci::app::KeyEvent::KEY_d:MovePaddle2Right();
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
//void PongTable::RestartGame() {
//  PongTable();
//}
}  // namespace pingpong