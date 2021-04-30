//
// Created by Tanishq Khurana on 4/21/21.
//

#ifndef FINAL_PROJECT_KTANISHQK_PONG_TABLE_H
#define FINAL_PROJECT_KTANISHQK_PONG_TABLE_H

#endif //FINAL_PROJECT_KTANISHQK_PONG_TABLE_H
#pragma once

#include <cinder/Color.h>
#include <paddle.h>
#include <ball.h>
#include "../../../include/cinder/app/App.h"
#include "../../../include/glm/vec2.hpp"
using glm::vec2;

namespace pingpong {
    class PongTable {
    public:
        /**
         * Constructor for a ball
         */
        PongTable();
        /**
         * Displays the pong table
         */
        void Display();

        void MovePaddle1Left();
        void MovePaddle1Right();
        void MovePaddle2Left();
        void MovePaddle2Right();
        void HandleCollisionWithWall();


    private:
      Paddle paddle1_;
      Paddle paddle2_;
      Ball ball_;
      // Size of the window
      const std::size_t kWindowSize = 900;
      const std::size_t kLeftEdge = 100;
      // This is the right edge coordinate
      const std::size_t kRightEdge = 800;
//      // This is the right boundary coordinate
//      const std::size_t kRightBoundary = 500;
//      // This is the bottom boundary coordinate
//      const std::size_t kBottomBoundary = 300;
      // This is the top edge coordinate
      const std::size_t kTopEdge = 100;
      // This is the bottom edge coordinate
    const std::size_t kBottomEdge = 800;
    };
}