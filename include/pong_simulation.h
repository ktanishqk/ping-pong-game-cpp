

#pragma once



#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "pong_table.h"
#include "../../../include/cinder/app/App.h"

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
  void draw();

 // void update() override;
  void keyDown(ci::app::KeyEvent event);

 private:
  PongTable pong_table_;
};

}