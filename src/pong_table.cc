//
// Created by Tanishq Khurana on 4/21/21.
//
#include "pong_table.h"


namespace pingpong {
PongTable::PongTable() {
  ci::app::setWindowSize(kWindowSize, kWindowSize);
    paddle1_ = Paddle(vec2(500, 600), vec2(400, 650));
    paddle2_ = Paddle(vec2(500, 200), vec2(400, 250));

}
void PongTable::Display(){
  ci::gl::color(ci::Color("red"));
  ci::gl::drawSolidRect(
      ci::Rectf(vec2(kLeftEdge, kTopEdge), vec2(kRightEdge, kBottomEdge)));
  ci::gl::color(ci::Color("blue"));
  ci::gl::drawSolidRect(ci::Rectf(paddle1_.GetTopLeftPosition(), paddle1_.GetBottomRightPosition()));
  ci::gl::color(ci::Color("green"));
  ci::gl::drawSolidRect(ci::Rectf(paddle2_.GetTopLeftPosition(), paddle2_.GetBottomRightPosition()));
}

void PongTable::MovePaddle1Left() {
    paddle1_.AdvanceFrametoLeft();
}

    void PongTable::MovePaddle1Right() {
    paddle1_.AdvanceFrametoRight();
    }

    void PongTable::MovePaddle2Left() {
        paddle2_.AdvanceFrametoLeft();
    }

    void PongTable::MovePaddle2Right() {
        paddle2_.AdvanceFrametoRight();
    }
    void PongTable::HandleCollisionWithWall() {
        glm::vec2 current_position = ball_.GetPosition();
        glm::vec2 current_velocity = ball_.GetVelocity();
        float radius = ball_.GetRadius();
        if ((abs(current_position.x - kLeftEdge) < radius) ||
            (abs(current_position.x - kRightEdge) < radius)) {
            current_velocity.x = -current_velocity.x;
        }
        if ((abs(current_position.y - kTopEdge) < radius)) {
            current_velocity.y = -current_velocity.y;
        }
}


}  // namespace pingpong