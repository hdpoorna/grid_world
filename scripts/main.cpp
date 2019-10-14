#include "gridWorld.h"

int main()
{
    std::cout << "Let's Begin!" << std::endl << std::endl;

    gridWorld gW;
    std::cout << std::endl;

    std::vector<int> trans;

    /*
    int nextMove = 0;
    bool quit = false;
    std::cout << "Enter the directions you want to go one by one." << std::endl;
    std::cout << "0 = Up ||| 1 = Down ||| 2 = Left ||| 3 = Right ||| any other integer = Quit" << std::endl;
    do{
        std::cin >> nextMove;
        //std::cout << std::endl;
        if(nextMove==0 || nextMove==1 || nextMove==2 || nextMove==3){
            trans.push_back(nextMove);
        }else{
            quit = true;
        }
    }while(!quit);
    std::cout << std::endl;
    //std::cout << std::endl << gW.terminalQ(trans) << std::endl;
    //std::cout << gW.score << std::endl;
    */

    trans = {0};
    float total = gW.oracle(trans);
    std::cout << std::endl << "Total = " << total << std::endl;
    return 0;
}
