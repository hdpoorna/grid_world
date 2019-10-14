#include "gridWorld.h"

gridWorld::gridWorld()
{
    /*
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator2 {seed};
    generator.seed(std::random_device{}());
    std::uniform_int_distribution<> go(0, 3);

    for (int i = 0; i < 5; i++)
    {
            std::cout << go(generator2) << std::endl;
    }
    */

    std::array<std::array<square_type, side>, side> emptyWorld = {Empty};       //local empty array of grid world size

    //std::uniform_int_distribution<> board(0, side*side - 1);
    std::srand(time(0));        //to get different random numbers
    //int startPos = 1;
    int goalPos = 23;
    bool con_1 = false;     //condition to check whether the Start and the Goal are following the rules
    do{
        //startPos = board(generator);
        //goalPos = board(generator);
        startPos = rand()%(side*side);
        goalPos = rand()%(side*side);
        //std::cout << startPos << "  " << goalPos << std::endl;

        bool checkStart = startPos==0 || startPos==side-1 || startPos==side*side-1 || startPos==side*side-side;     //whether the Start is in one of the corners
        bool checkGoal = goalPos==0 || goalPos==side-1 || goalPos==side*side-1 || goalPos==side*side-side;          //whether the Start is in one of the corners
        con_1 = checkStart||checkGoal||startPos==goalPos;
    }while(con_1);
    emptyWorld.at(int(startPos/side)).at(int(startPos%side)) = Start;       //assign Start
    emptyWorld.at(int(goalPos/side)).at(int(goalPos%side)) = Goal;          //assign Goal

    xPos = int(startPos%side);
    yPos = int(startPos/side);

    std::vector<int> walls;
    for(int x=1; x<=numWalls; x++){
        int wallPos = 3;
        bool con_2 = false;                 //check whether the walls follow the rules
        do{
            //wallPos = board(generator);
            wallPos = rand()%(side*side);

            bool checkWall = wallPos==startPos || wallPos==goalPos;         //whether a wall is in the same position as Start or Goal
            bool dupWall = false;                                           //whether there are duplicate walls
            for(int y=1; y<=walls.size(); y++){
                if(walls.at(y-1)==wallPos){
                    dupWall = true;
                    break;
                }
            }
            con_2 = checkWall || dupWall;
        }while(con_2);
        walls.push_back(wallPos);
        emptyWorld.at(int(wallPos/side)).at(int(wallPos%side)) = Wall;      //assign walls
    }

    gWorld = emptyWorld;                                //make global grid world
    for(int i=0; i<=side-1; i++){
        for(int j=0; j<=side-1; j++){
            std::cout << gWorld.at(i).at(j) << "  ";
        }
        std::cout << std::endl;
    }
}
gridWorld::~gridWorld()
{

}

bool gridWorld::terminalQ(std::vector<int> transitions)
{
    //int xPos = int(startPos%side);
    //int yPos = int(startPos/side);
    //int xPos = xPos_0;
    //int yPos = yPos_0;
    //std::cout << xPos << "," << yPos << std::endl;
    for(int k=1; k<=transitions.size(); k++){

        score = score - 1;

        switch(transitions.at(k-1)){
            case 0:
                yPos = yPos - 1;
                std::cout << "Up" << std::endl;
                break;
            case 1:
                yPos = yPos + 1;
                std::cout << "Down" << std::endl;
                break;
            case 2:
                xPos = xPos - 1;
                std::cout << "Left" << std::endl;
                break;
            case 3:
                xPos = xPos + 1;
                std::cout << "Right" << std::endl;
                break;
            default:
                std::cout << transitions.at(k-1) << " is not a valid transition." << std::endl;
                //do some error handling. throw, catch
        }
        // whether the player hits the outside wall
        bool checkX = xPos<0 || xPos>side-1;
        bool checkY = yPos<0 || yPos>side-1;
        //std::cout << xPos << "," << yPos << std::endl;
        if(checkX || checkY || gWorld.at(yPos).at(xPos)==Wall){
            score = score + wallPenalty;
            return true;
        } else if(gWorld.at(yPos).at(xPos)==Goal){
            return true;
        }
    }
    return false;
}

float gridWorld::oracle(std::vector<int> transitions)
{
    bool terminal = terminalQ(transitions);             //whether the entered transitions are terminal
    if(terminal){
        return score;
    } else{
        auto seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator2 {seed};
        std::uniform_int_distribution<> go(0, 3);
        std::vector<int> nextTrans;
        std::cout << std::endl;
        do{
            nextTrans = {go(generator2)};
            terminal = terminalQ(nextTrans);
            if(score<=scoreThreshold){
                //score = score - 0.1f;
                terminal = true;
            }
        }while(!terminal);
        return score;
    }
}

std::vector<int> gridWorld::expandNode(std::vector<int> transitions)
{
    std::vector<int> output;

    output.push_back(0);
    output.push_back(1);
    output.push_back(2);
    output.push_back(3);

    return output;
}
