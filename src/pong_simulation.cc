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

void PongSimulation::keyDown(ci::app::KeyEvent event) {
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_RIGHT:
      pong_table_.GetPaddle1().AdvanceFrametoRight();
      break;

    case ci::app::KeyEvent::KEY_LEFT:
      pong_table_.GetPaddle1().AdvanceFrametoLeft();
      break;
  }
}
}