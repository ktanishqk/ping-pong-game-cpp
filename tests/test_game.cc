//
// Created by Tanishq Khurana on 5/4/21.
//

#include "pong_table.h"
#include <catch2/catch.hpp>
namespace pingpong {
TEST_CASE("Check that the pong table is being made properly") {
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
}
}// namespace pingpong