

#pragma once

#include "../../../include/cinder/app/App.h"
#include "../../../include/cinder/app/KeyEvent.h"
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
  PongSimulation();

  /**
   *
   */
  void draw() override ;

 // void update() override;
  void keyDown(ci::app::KeyEvent event) override;

 private:
  PongTable pong_table_;
};

}