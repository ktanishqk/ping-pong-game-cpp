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
  glm::vec2 ball_position = pong_table.GetBall().GetPosition();
  glm::vec2 initial_velocity = pong_table.GetBall().GetVelocity();
  glm::vec2 paddle_lower_position = pong_table.GetPaddle1().GetBottomRightPosition();
  glm::vec2 paddle_upper_position = pong_table.GetPaddle1().GetTopLeftPosition();
  glm::vec2 paddle_lower_position_2 = pong_table.GetPaddle2().GetBottomRightPosition();
  glm::vec2 paddle_upper_position_2 = pong_table.GetPaddle2().GetTopLeftPosition();

  SECTION("Paddle 1 collision") {
    while ((((abs(ball_position.y - paddle_upper_position.y) >= pong_table.GetBall().GetRadius())
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
    while (((abs(ball_position.y - paddle_lower_position_2.y) < pong_table.GetBall().GetRadius())
            && (paddle_lower_position_2.x < ball_position.x)
            && (ball_position.x < paddle_upper_position_2.x))) {
      pong_table.AdvanceOneFrame();
    }
    pong_table.HandleCollisionWithPaddle();
    glm::vec2 require = initial_velocity;
    REQUIRE(pong_table.GetBall().GetVelocity().y == require.y);
  }
  SECTION("Left Wall collision") {
    pong_table.GetBall().GetVelocity() = vec2(1, 0);
    while ((abs(ball_position.x - 100) < 20)) {
      pong_table.AdvanceOneFrame();
    }
    pong_table.HandleCollisionWithWall();
    glm::vec2 require = initial_velocity;
    REQUIRE(pong_table.GetBall().GetVelocity().x == require.x * -1);
  }
  SECTION("Right Wall collision") {
    while ((abs(ball_position.x - 800) < 20)) {
      pong_table.AdvanceOneFrame();
    }
    pong_table.HandleCollisionWithWall();
    glm::vec2 require = initial_velocity;
    REQUIRE(pong_table.GetBall().GetVelocity().x == require.x * -1);
  }
}
TEST_CASE("Ball Color Change") {
  PongTable pong_table;
  glm::vec2 ball_position = pong_table.GetBall().GetPosition();
  glm::vec2 initial_velocity = pong_table.GetBall().GetVelocity();
  glm::vec2 paddle_lower_position = pong_table.GetPaddle1().GetBottomRightPosition();
  glm::vec2 paddle_upper_position = pong_table.GetPaddle1().GetTopLeftPosition();
  glm::vec2 paddle_lower_position_2 = pong_table.GetPaddle2().GetBottomRightPosition();
  glm::vec2 paddle_upper_position_2 = pong_table.GetPaddle2().GetTopLeftPosition();
  SECTION("Paddle 1 Collision") {
    while ((((abs(ball_position.y - paddle_upper_position.y) >= pong_table.GetBall().GetRadius())
             && (paddle_lower_position.x >= ball_position.x)
             && (ball_position.x >= paddle_upper_position.x)))) {
      pong_table.AdvanceOneFrame();
    }
    pong_table.HandleCollisionWithPaddle();
    ci::Color require = "blue";
    REQUIRE(pong_table.GetBall().GetColor() == ci::Color(require));
  }
  SECTION("Paddle 2 Collision") {
    for (int i = 0; i < 3; i++) {
      pong_table.MovePaddle2Right();
    }
    while (((abs(ball_position.y - paddle_lower_position_2.y) < pong_table.GetBall().GetRadius())
            && (paddle_lower_position_2.x < ball_position.x)
            && (ball_position.x < paddle_upper_position_2.x))) {
      pong_table.AdvanceOneFrame();
    }
    pong_table.HandleCollisionWithPaddle();
    ci::Color require = "green";
    REQUIRE(pong_table.GetBall().GetColor() == ci::Color(require));
  }
  SECTION("Off TopTable Ball") {
    while (ball_position.y != 100) {
      pong_table.AdvanceOneFrame();
    }
    ci::Color require = "black";
    REQUIRE(pong_table.GetBall().GetColor() == ci::Color(require));
  }
  SECTION("Off BottomTable Ball") {
    while (ball_position.y != 800) {
      pong_table.AdvanceOneFrame();
    }
    ci::Color require = "black";
    REQUIRE(pong_table.GetBall().GetColor() == ci::Color(require));
  }
}

TEST_CASE("Paddle Movement") {
  PongTable pong_table;
  glm::vec2 paddle_lower_position = pong_table.GetPaddle1().GetBottomRightPosition();
  glm::vec2 paddle_upper_position = pong_table.GetPaddle1().GetTopLeftPosition();
  glm::vec2 paddle_lower_position_2 = pong_table.GetPaddle2().GetBottomRightPosition();
  glm::vec2 paddle_upper_position_2 = pong_table.GetPaddle2().GetTopLeftPosition();
  SECTION("Paddle 1") {
    SECTION("Left Movement") {
      pong_table.MovePaddle1Left();
      paddle_upper_position.x -= 40;
      paddle_lower_position.x -= 40;
      REQUIRE(pong_table.GetPaddle1().GetTopLeftPosition().x == paddle_upper_position.x);
      REQUIRE(pong_table.GetPaddle1().GetBottomRightPosition().x == paddle_lower_position.x);
    }
    SECTION("Right Movement") {
      pong_table.MovePaddle1Right();
      paddle_upper_position.x += 40;
      paddle_lower_position.x += 40;
      REQUIRE(pong_table.GetPaddle1().GetTopLeftPosition().x == paddle_upper_position.x);
      REQUIRE(pong_table.GetPaddle1().GetBottomRightPosition().x == paddle_lower_position.x);
    }
  }
  SECTION("Paddle 2") {
    SECTION("Left Movement") {
      pong_table.MovePaddle2Left();
      paddle_upper_position_2.x -= 40;
      paddle_lower_position_2.x -= 40;
      REQUIRE(pong_table.GetPaddle2().GetTopLeftPosition().x == paddle_upper_position_2.x);
      REQUIRE(pong_table.GetPaddle2().GetBottomRightPosition().x == paddle_lower_position_2.x);
    }
    SECTION("Right Movement") {
      pong_table.MovePaddle2Right();
      paddle_upper_position_2.x += 40;
      paddle_lower_position_2.x += 40;
      REQUIRE(pong_table.GetPaddle2().GetTopLeftPosition().x == paddle_upper_position_2.x);
      REQUIRE(pong_table.GetPaddle2().GetBottomRightPosition().x == paddle_lower_position_2.x);
    }
  }
}
TEST_CASE("Scoreboard Implementation") {
  PongTable pong_table;
  glm::vec2 ball_position = pong_table.GetBall().GetPosition();
  SECTION("Blue Score") {
    while (ball_position.y != 100) {
      pong_table.AdvanceOneFrame();
    }
    REQUIRE(pong_table.GetBluePlayerScore() == 1);
  }
  SECTION("Green Score") {
    for (int i = 0; i < 3; i++) {
      pong_table.MovePaddle2Right();
    }
    while (ball_position.y != 800) {
      pong_table.AdvanceOneFrame();
    }
    REQUIRE(pong_table.GetGreenPlayerScore() == 1);
  }
}
}// namespace pingpong