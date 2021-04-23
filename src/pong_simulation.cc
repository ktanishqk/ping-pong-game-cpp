//
// Created by Tanishq Khurana on 4/23/21.
//
#include "pong_simulation.h"
#include "ball.h"


namespace pingpong {

PongSimulation::PongSimulation()
    {
}

void PongSimulation::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);
  pong_table_.Display();
}

void PongSimulation::update() {
  pong_table_.AdvanceOneFrame();
}
}