//
// Created by Tanishq Khurana on 4/21/21.
//
#include "pong_table.h"

namespace pingpong {
PongTable::PongTable() {
  std::cout << "Blue Player Gamer Tag: ";
  std::cin >> blue_player_gamer_tag_;
  std::cout << "Green Player Gamer Tag: ";
  std::cin >> green_player_gamer_tag_;
  SetGame();
  if (green_player_gamer_tag_ == "comp") {
    game_state_ = GameState::NewGameCvP;
  }
}
void PongTable::SetGame() {

  paddle1_ = Paddle(vec2(5 * kLeftEdge, 6 * kLeftEdge),
                    vec2(4 * kLeftEdge, 6 * kLeftEdge + kDisplayFactor), kBlue);
  paddle2_ = Paddle(vec2(5 * kLeftEdge, 2 * kLeftEdge),
                    vec2(4 * kLeftEdge, 2 * kLeftEdge + kDisplayFactor), kGreen);
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
  if (game_state_ == GameState::NewGamePvP) {
    ci::gl::drawStringCentered(kWelcomeMessage, vec2(kWindowSize / 2, (kWindowSize - 5 * kDisplayFactor) / 2),
                               ci::ColorA(1, 1, 1, 1), welcome_font);
    ci::gl::drawStringCentered(kGamerTagBlue + blue_player_gamer_tag_, vec2(kWindowSize / 2, (kWindowSize - 2 * kDisplayFactor) / 2),
                               ci::ColorA(1, 1, 1, 1), gamertag_font);
    ci::gl::drawStringCentered(kGamerTagGreen + green_player_gamer_tag_, vec2(kWindowSize / 2, (kWindowSize - kDisplayFactor) / 2),
                               ci::ColorA(1, 1, 1, 1), gamertag_font);
    ci::gl::drawStringCentered(kInstructions, vec2(kWindowSize / 2, (kWindowSize + kDisplayFactor) / 2),
                               ci::ColorA(1, 1, 1, 1), instructions_font);
    ci::gl::drawStringCentered(kGreenInstructions,
                               vec2(kWindowSize / 2, (kWindowSize + 3 * kDisplayFactor) / 2),
                               ci::ColorA(1, 1, 1, 1), gamertag_font);
    ci::gl::drawStringCentered(kBlueInstructions,
                               vec2(kWindowSize / 2, (kWindowSize + 4 * kDisplayFactor) / 2),
                               ci::ColorA(1, 1, 1, 1), gamertag_font);

  }
  // Making the current game state to actually play the game
  if (game_state_ == GameState::NewGameCvP) {
    ci::gl::drawStringCentered(kWelcomeMessage, vec2(kWindowSize / 2, (kWindowSize - 5 * kDisplayFactor) / 2),
                               ci::ColorA(1, 1, 1, 1), welcome_font);
    ci::gl::drawStringCentered(kGamerTagBlue + blue_player_gamer_tag_, vec2(kWindowSize / 2, (kWindowSize - 2 * kDisplayFactor) / 2),
                               ci::ColorA(1, 1, 1, 1), gamertag_font);
    ci::gl::drawStringCentered(kGamerTagGreen + kComp, vec2(kWindowSize / 2, (kWindowSize - kDisplayFactor) / 2),
                               ci::ColorA(1, 1, 1, 1), gamertag_font);
    ci::gl::drawStringCentered(kInstructions, vec2(kWindowSize / 2, (kWindowSize + kDisplayFactor) / 2),
                               ci::ColorA(1, 1, 1, 1), instructions_font);
    ci::gl::drawStringCentered(kBlueInstructions,
                               vec2(kWindowSize / 2, (kWindowSize + 4 * kDisplayFactor) / 2),
                               ci::ColorA(1, 1, 1, 1), gamertag_font);
    // Making the current game state to actually play the game
  } else if (game_state_ == GameState::CurrentGamePvP) {
    DisplayScoreboard();
    ci::gl::color(ci::Color(kRed));
    ci::gl::drawSolidRect(
        ci::Rectf(vec2(kLeftEdge, kTopEdge), vec2(kRightEdge, kBottomEdge)));
    paddle1_.Display();
    paddle2_.Display();
    ball_.Display();
  } else if (game_state_ == GameState::CurrentGameCvP) {
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
  if (paddle1_.GetBottomRightPosition().x > 120) {
    paddle1_.AdvanceFrametoLeft();
  }
}
void PongTable::MovePaddle1Right() {
  if (paddle1_.GetTopLeftPosition().x < 780) {
    paddle1_.AdvanceFrametoRight();
  }
}

void PongTable::MovePaddle2Left() {
  if (paddle2_.GetBottomRightPosition().x > 120) {
    paddle2_.AdvanceFrametoLeft();
  }
}

void PongTable::MovePaddle2Right() {
  if (paddle2_.GetTopLeftPosition().x < 780) {
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
  }
  if (((abs(ball_position.y - paddle_lower_position_2.y) < ball_.GetRadius())
       && (paddle_lower_position_2.x < ball_position.x)
       && (ball_position.x < paddle_upper_position_2.x))) {
    current_velocity.y = -current_velocity.y;
    color = paddle2_.GetColor();
  }
}

void PongTable::HandlePlayerMovement(const ci::app::KeyEvent &event) {
  if (game_state_ == GameState::CurrentGamePvP) {
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
  } else if (game_state_ == GameState::NewGamePvP) {
    switch (event.getCode()) {
      case ci::app::KeyEvent::KEY_SPACE:
        game_state_ = GameState::CurrentGamePvP;
        break;
    }
  } else if (game_state_ == GameState::NewGameCvP) {
    switch (event.getCode()) {
      case ci::app::KeyEvent::KEY_SPACE:
        game_state_ = GameState::CurrentGameCvP;
        break;
    }
  } else if (game_state_ == GameState::CurrentGameCvP) {
    switch (event.getCode()) {
      case ci::app::KeyEvent::KEY_RIGHT:
        MovePaddle1Right();
        break;
      case ci::app::KeyEvent::KEY_LEFT:
        MovePaddle1Left();
        break;
      case ci::app::KeyEvent::KEY_SPACE:
        SetGame();
        break;
    }
  }
}
void PongTable::ManageBallOffTable() {
  if (ball_.GetPosition().y == kTopEdge) {
    // scorecard update
    score_blue_++;
    // change ball color to black
    ball_.GetColor() = kBlack;
  }
  if (ball_.GetPosition().y == kBottomEdge) {
    // scorecard update
    score_green_++;
    // change ball color to black
    ball_.GetColor() = kBlack;
  }
}
void PongTable::AdvanceOneFrame() {
  if (game_state_ == GameState::CurrentGamePvP) {
    ball_.ChangeBallPosition();
    HandleCollisionWithPaddle();
    HandleCollisionWithWall();
    ManageBallOffTable();
  }
  if (game_state_ == GameState::CurrentGameCvP) {
    ball_.ChangeBallPosition();
    HandlePaddleAutomaticMovement();
    HandleCollisionWithPaddle();
    HandleCollisionWithWall();
    ManageBallOffTable();
  }
}
void PongTable::HandlePaddleAutomaticMovement() {
  vec2 ball_centre = ball_.GetPosition();
  vec2 &ball_velocity = ball_.GetVelocity();
  vec2 paddle_comp_centre = vec2(paddle2_.GetTopLeftPosition().x - paddle2_.GetBottomRightPosition().x, paddle2_.GetTopLeftPosition().y - paddle2_.GetBottomRightPosition().y);
  float dist = glm::length(paddle_comp_centre - ball_centre);
  if (dist > 0 && dist < 100) {
    ball_velocity += 0.2;
  }
  if (dist >= 100 && dist < 200) {
    ball_velocity += 0.2;
  }
  if (dist >= 200 && dist < 300) {
    ball_velocity += 0.2;
  }
  if (dist >= 300 && dist < 400) {
    ball_velocity += 0.2;
  }
  while(ball_centre.x <= (paddle_comp_centre.x + 30) || ball_centre.x > (paddle_comp_centre.x - 30)) {
    if (ball_centre.x >= 400) {
      paddle2_.AdvanceFrametoRight();
    }
    if (ball_centre.x < 400) {
      paddle2_.AdvanceFrametoLeft();
    }
  }
}
void PongTable::DisplayScoreboard() {
  ci::gl::color(ci::Color(kWhite));
  ci::gl::drawStrokedRect(ci::Rectf(vec2(kExtendedWindowSize - 2 * kDisplayFactor, kRightEdge / 2),
                                    vec2(kWindowSize + kDisplayFactor, kRightEdge / 4)));
  ci::gl::drawStringCentered("SCOREBOARD", vec2(kScoreboard, (kRightEdge) / 3.5));
  ci::gl::drawStringCentered(blue_player_gamer_tag_ + "'s Score: " + std::to_string(score_blue_), vec2(kScoreboard, (kRightEdge) / 3));
  ci::gl::drawStringCentered(green_player_gamer_tag_ + "'s Score: " + std::to_string(score_green_), vec2(kScoreboard, (kRightEdge) / 2.5));
}
Ball PongTable::GetBall() {
  return ball_;
}
Paddle PongTable::GetPaddle1() {
  return paddle1_;
}
Paddle PongTable::GetPaddle2() {
  return paddle2_;
}
size_t PongTable::GetBluePlayerScore() {
  return score_blue_;
}
size_t PongTable::GetGreenPlayerScore() {
  return score_green_;
}
}// namespace pingpong