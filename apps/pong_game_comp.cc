//
// Created by Tanishq Khurana on 4/20/21.
//

#include <pong_simulation.h>
#include <pong_table.h>

#include "../../../include/cinder/app/RendererGl.h"

using pingpong::PongSimulation;

void prepareSettings(PongSimulation::Settings* settings) {
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(PongSimulation, ci::app::RendererGl, prepareSettings);



