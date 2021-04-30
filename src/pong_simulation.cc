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
          pong_table_.MovePaddle1Right();
          break;

      case ci::app::KeyEvent::KEY_LEFT:
          pong_table_.MovePaddle1Left();
          break;

      case ci::app::KeyEvent::KEY_a:
          pong_table_.MovePaddle2Left();
          break;

      case ci::app::KeyEvent::KEY_d:
          pong_table_.MovePaddle2Right();
          break;
  }
  }
void PongSimulation::update(){
    pong_table_.AdvanceOneFrame();
}
}