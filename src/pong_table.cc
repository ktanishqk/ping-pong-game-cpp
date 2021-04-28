//
// Created by Tanishq Khurana on 4/21/21.
//
#include "pong_table.h"


namespace pingpong {
PongTable::PongTable() {
  ci::app::setWindowSize(kWindowSize, kWindowSize);
  paddle1 = Paddle(vec2(500, 600), vec2(400, 650));
  paddle2 = Paddle(vec2(500, 201), vec2(400, 250));
}
void PongTable::Display(){
  ci::gl::color(ci::Color("red"));
  ci::gl::drawSolidRect(
      ci::Rectf(vec2(kLeftEdge, kTopEdge), vec2(kRightEdge, kBottomEdge)));
  ci::gl::color(ci::Color("blue"));
  ci::gl::drawSolidRect(ci::Rectf(paddle1.GetTopLeftPosition(), paddle1.GetBottomRightPosition()));
  ci::gl::color(ci::Color("green"));
  ci::gl::drawSolidRect(ci::Rectf(paddle2.GetTopLeftPosition(), paddle2.GetBottomRightPosition()));
}
}  // namespace pingpong