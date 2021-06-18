//
// Created by Tanishq Khurana on 4/20/21.
//
#include "cinder/gl/gl.h"
#include <cinder/Color.h>

#pragma once
namespace pingpong {
    class Paddle {
    private:
        glm::vec2 top_left_position_;
        glm::vec2 bottom_right_position_;
    public:
     Paddle();
     Paddle(glm::vec2 top_right_position, glm::vec2 bottom_left_position);
     void SetTopLeftPosition(glm::vec2& position);
     glm::vec2& GetTopLeftPosition();
      void SetBottomRightPosition(glm::vec2& position);
      glm::vec2& GetBottomRightPosition();
      void AdvanceFrametoRight();
      void AdvanceFrametoLeft();
    };
}

#ifndef FINAL_PROJECT_KTANISHQK_PADDLE_H
#define FINAL_PROJECT_KTANISHQK_PADDLE_H

#endif //FINAL_PROJECT_KTANISHQK_PADDLE_H
