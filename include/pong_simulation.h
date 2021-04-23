//
// Created by Tanishq Khurana on 4/23/21.
//

#ifndef FINAL_PROJECT_KTANISHQK_PONG_SIMULATION_H
#define FINAL_PROJECT_KTANISHQK_PONG_SIMULATION_H

#endif  // FINAL_PROJECT_KTANISHQK_PONG_SIMULATION_H

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
  PongSimulation();

  void draw() override;
  void update() override;

 private:
  PongTable pong_table_;
};

}