//
//  ToyRobot.hpp
//
//  Created by Vathna Am.
//  Copyright © 2019 Vathna Am. All rights reserved.
//
//  Class definition (interface) of the Toy Robot Simulator

#ifndef ToyRobot_hpp
#define ToyRobot_hpp

#include <iostream>
#include <string>
#include <exception>

#endif /* ToyRobot_hpp */

using namespace std;


class ToyRobot {
private:
    //Private data members
    //The X,Y and orientation of the robot
    struct position {
        int x = -1;
        int y = -1;
        enum direction {NORTH,SOUTH,EAST,WEST} dir;
    } currentPosition;
    string inputString;
    
    //Private function members
    bool IsValid(void) const;
    void Place(void);
    void Move(void);
    void Left(void);
    void Right(void);
    void Report(void) const;
    void GetInput(void);
    ToyRobot(void){}; //Default constructor is defined private to avoid creating an object. User should not create an object for this class.
    
public:
    static void RunToyRobot(void);
};

