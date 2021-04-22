//
// Created by Tanishq Khurana on 4/21/21.
//

#ifndef FINAL_PROJECT_KTANISHQK_PONG_TABLE_H
#define FINAL_PROJECT_KTANISHQK_PONG_TABLE_H

#endif //FINAL_PROJECT_KTANISHQK_PONG_TABLE_H
#pragma once
#include <cinder/Color.h>
using glm::vec2;

namespace pingpong{
    class PongTable {
    public:
        /**
         * Constructor for a ball
         */
        PongTable(int kTopEdge,
        int kBottomEdge,
        int kLeftEdge,
        int kRightEdge);
        /**
         * Displays the pong table
         */
        void Display() const;
        /**
         * Updates the velocity and the position of the ball
         */
        void AdvanceOneFrame();

private:
    int kTopEdge;
    int kBottomEdge;
    int kLeftEdge;
    int kRightEdge;
    };
}