#ifndef GSTATE_H
#define GSTATE_H

#include <vector>
#include <array>
#include <random>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>

class gState
{
    public:
        gState();
        virtual ~gState();

    virtual bool terminalQ(std::vector<int>) = 0;
    virtual std::vector<int> expandNode(std::vector<int>) = 0;
    virtual float oracle(std::vector<int>) = 0;

    //std::mt19937_64 generator;

    protected:
    private:
};

#endif // GSTATE_H
