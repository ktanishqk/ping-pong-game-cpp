

#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "pong_table.h"

namespace pingpong {
/**
 * An app for visualizing the behavior of an ideal gas.
 */
class PongSimulation : public ci::app::App {
 public:
  /**
   * Default constructor for the simulation app
   */
  PongSimulation();
  /**
 * Overriding the draw function from the Cinder App
 */
  void draw() override;

  /**
  * Overriding the keyDown function that allows for key input for the movement of the paddle
  * @param event
  */
  void keyDown(ci::app::KeyEvent event) override;
  /**
   * Overriding the update function that allows for advancing the frame every second
   */
  void update() override;

 private:
  PongTable pong_table_;
};

}// namespace pingpong