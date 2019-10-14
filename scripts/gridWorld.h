#ifndef GRIDWORLD_H
#define GRIDWORLD_H

#include "gState.h"

class gridWorld : public gState
{
    public:
        gridWorld();
        virtual ~gridWorld();

        const static int side = 5;      //size of a side in static data, to create an array
        const int numWalls = 2;         //2 walls, otherwise the goal could be unattainable

        int startPos = 1;
        int xPos = int(startPos%side);      //x coordinate of the player
        int yPos = int(startPos/side);      //y coordinate of the player

        float score = 0;                    //global score
        float scoreThreshold = -100;        //float(-side*side);
        float wallPenalty = -10000.5;       //float(-side*side*side*side) - 0.1f;

        enum square_type {Wall = -1, Empty, Start, Goal};
        //enum direction {Up, Down, Left, Right};

        std::array<std::array<square_type, side>, side> gWorld;     //global grid world array

        //auto seed = std::chrono::system_clock::now().time_since_epoch().count();
        //std::mt19937 generator2 {seed};

        bool terminalQ(std::vector<int>);
        std::vector<int> expandNode(std::vector<int>);
        float oracle(std::vector<int>);
};

#endif
