//
// Created by Tanishq Khurana on 5/4/21.
//

#include "pong_table.h"
#include <catch2/catch.hpp>
namespace pingpong {
TEST_CASE("Initialisation Check") {
  PongTable pong_table;
  SECTION("Checking Paddle1's initial position") {
    glm::vec2 top_left = vec2(5 * 100, 6 * 100);
    glm::vec2 bottom_right = vec2(4 * 100, 6 * 100 + 50);
    REQUIRE(pong_table.GetPaddle1().GetTopLeftPosition() == top_left);
    REQUIRE(pong_table.GetPaddle1().GetBottomRightPosition() == bottom_right);
  }
  SECTION("Checking Paddle2's initial position") {
    glm::vec2 top_left = vec2(5 * 100, 2 * 100);
    glm::vec2 bottom_right = vec2(4 * 100, 2 * 100 + 50);
    REQUIRE(pong_table.GetPaddle2().GetTopLeftPosition() == top_left);
    REQUIRE(pong_table.GetPaddle2().GetBottomRightPosition() == bottom_right);
  }
  SECTION("Checking Ball's radius") {
    size_t require = 20;
    REQUIRE(pong_table.GetBall().GetRadius() == require);
  }
  SECTION("Checking Ball's initial position") {
    glm::vec2 require = vec2(450, 450);
    REQUIRE(pong_table.GetBall().GetPosition() == require);
  }
  SECTION("Checking Ball's initial velocity") {
    glm::vec2 require = vec2(0.5, -2);
    REQUIRE(pong_table.GetBall().GetVelocity() == require);
  }
  SECTION("Checking Ball's initial color") {
    ci::Color require = ci::Color("black");
    REQUIRE(pong_table.GetBall().GetColor() == require);
  }
  SECTION("Checking Paddle1's initial color") {
    ci::Color require = ci::Color("blue");
    REQUIRE(pong_table.GetPaddle1().GetColor() == require);
  }
  SECTION("Checking Paddle2's initial color") {
    ci::Color require = ci::Color("green");
    REQUIRE(pong_table.GetPaddle2().GetColor() == require);
  }
}
TEST_CASE("Collision Check") {
  PongTable pong_table;
  //ci::Color color = pong_table.GetBall().GetColor();
  glm::vec2 ball_position = pong_table.GetBall().GetPosition();
  glm::vec2 initial_velocity = pong_table.GetBall().GetVelocity();
  glm::vec2 paddle_lower_position = pong_table.GetPaddle1().GetBottomRightPosition();
  glm::vec2 paddle_upper_position = pong_table.GetPaddle1().GetTopLeftPosition();
  glm::vec2 paddle_lower_position_2 = pong_table.GetPaddle2().GetBottomRightPosition();
  glm::vec2 paddle_upper_position_2 = pong_table.GetPaddle2().GetTopLeftPosition();

  SECTION("Paddle 1 collision") {
    while((((abs(ball_position.y - paddle_upper_position.y) >= pong_table.GetBall().GetRadius())
        && (paddle_lower_position.x >= ball_position.x)
        && (ball_position.x >= paddle_upper_position.x)))) {
        pong_table.AdvanceOneFrame();

    }
    pong_table.HandleCollisionWithPaddle();
    glm::vec2 require = initial_velocity;
    REQUIRE(pong_table.GetBall().GetVelocity().y == require.y * -1);
  }
  SECTION("Paddle 2 collision") {
    for (int i = 0; i < 10; i++) {
      pong_table.MovePaddle2Right();
    }
    while(((abs(ball_position.y - paddle_lower_position_2.y) < pong_table.GetBall().GetRadius())
        && (paddle_lower_position_2.x < ball_position.x)
        && (ball_position.x < paddle_upper_position_2.x))) {
      pong_table.AdvanceOneFrame();
    }
    pong_table.HandleCollisionWithPaddle();
    glm::vec2 require = initial_velocity;
    REQUIRE(pong_table.GetBall().GetVelocity().y == require.y);
  }
  SECTION("Left Wall collision") {
    while((abs(ball_position.x - 100) < 20)) {
      pong_table.AdvanceOneFrame();
    }
    pong_table.HandleCollisionWithPaddle();
    glm::vec2 require = initial_velocity;
    REQUIRE(pong_table.GetBall().GetVelocity().y == require.y);
  }
}
}// namespace pingpong