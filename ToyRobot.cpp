//
//  ToyRobot.cpp
//
//  Created by Vathna Am.
//  Copyright © 2019 Vathna Am. All rights reserved.
//
//  The implemenation of class definition in the ToyRobot.hpp

#include "ToyRobot.hpp"

//Checks for a valid move
bool ToyRobot::IsValid(void) const
{
    //The robot can only move on a 5x5 square tabletop
    if ((currentPosition.x <= maxTableDimension) && (currentPosition.x >= 0) && (currentPosition.y <= maxTableDimension) && (currentPosition.y >= 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//The PLACE command
void ToyRobot::Place(void)
{
    bool invalid = false; //Invalid input indicator
    position oldPosition = currentPosition; //Temporary old position
    unsigned long xIdx = inputString.find(" ")+1;
    unsigned long yIdx = inputString.find(",")+1;
    unsigned long dirIdx = inputString.find(",",yIdx)+1;
    string direction = inputString.substr(dirIdx,inputString.length()-dirIdx);
    
    try
    {
        //Place the robot in the specified x and y coordinates
        currentPosition.x = stoi(inputString.substr(xIdx,(yIdx-xIdx)-1));
        currentPosition.y = stoi(inputString.substr(yIdx,(dirIdx-yIdx)-1));
    }
    catch (exception &e)
    {
        //If the user input an invalid PLACE command, use the old position.
        currentPosition = oldPosition;
    }
    
    //Set the orientation of the robot
    if (direction == "NORTH")
    {
        currentPosition.dir = position::NORTH;
    }
    else if (direction == "SOUTH")
    {
        currentPosition.dir = position::SOUTH;
    }
    else if (direction == "EAST")
    {
        currentPosition.dir = position::EAST;
    }
    else if (direction == "WEST")
    {
        currentPosition.dir = position::WEST;
    }
    else //If there's an invalid input
    {
        invalid = true;
    }
    
    //If the new position is invalid, go back to the old position
    if(!IsValid()||invalid)
    {
        currentPosition = oldPosition;
    }
    
}

// The MOVE command
void ToyRobot::Move(void)
{
    position oldPosition = currentPosition; //Temporary old position
    
    //Move the robot one unit forward in the current direction it's facing
    switch (currentPosition.dir) {
        case position::NORTH:
            currentPosition.y += 1; break;
        case position::SOUTH:
            currentPosition.y -= 1; break;
        case position::EAST:
            currentPosition.x += 1; break;
        case position::WEST:
            currentPosition.x -= 1; break;
        default:
            break;
    }
    
    //If the new position is invalid, go back to the old position
    if(!IsValid())
    {
        currentPosition = oldPosition;
    }
}

//The LEFT command
void ToyRobot::Left(void)
{
    //Rotate the robot 90 degrees (anti-clockwise)
    switch (currentPosition.dir) {
        case position::NORTH:
            currentPosition.dir = position::WEST; break;
        case position::WEST:
            currentPosition.dir = position::SOUTH; break;
        case position::SOUTH:
            currentPosition.dir = position::EAST; break;
        case position::EAST:
            currentPosition.dir = position::NORTH; break;
        default:
            break;
    }
}

//The RIGHT command
void ToyRobot::Right(void)
{
    //Rotate the robot 90 degrees (clockwise)
    switch (currentPosition.dir) {
        case position::NORTH:
            currentPosition.dir = position::EAST; break;
        case position::EAST:
            currentPosition.dir = position::SOUTH; break;
        case position::SOUTH:
            currentPosition.dir = position::WEST; break;
        case position::WEST:
            currentPosition.dir = position::NORTH; break;
        default:
            break;
    }
}

//The REPORT command
void ToyRobot::Report(void) const
{
    //Output the current X, Y and orientation of the robot
    std::cout << "Output: " << currentPosition.x << "," << currentPosition.y << ",";
    switch (currentPosition.dir)
    {
        case position::NORTH:
            cout << "NORTH"; break;
        case position::SOUTH:
            cout << "SOUTH"; break;
        case position::EAST:
            cout << "EAST"; break;
        case position::WEST:
            cout << "WEST"; break;
    }
    cout << endl;
}

//Run the Toy Robot Simulator
void ToyRobot::RunToyRobot(void)
{
    ToyRobot myToyRobot;
    bool start = false; //The first valid PLACE command indicator
    
    
    //Check if the user input a valid PLACE command first
    do{
        //Get user input
        getline(cin, myToyRobot.inputString);
        
        if (myToyRobot.inputString.substr(0,5) == "PLACE")
        {
            myToyRobot.Place();
            start = true;
        }
        
    } while(!start || !myToyRobot.IsValid());
    
    
    //Continuously executing new commands
    while(1)
    {
        //Get user input
        getline(cin, myToyRobot.inputString);
        
        if (myToyRobot.inputString.substr(0,5) == "PLACE")
        {
            myToyRobot.Place();
        }
        else if (myToyRobot.inputString == "REPORT")
        {
            myToyRobot.Report();
        }
        else if (myToyRobot.inputString == "RIGHT")
        {
            myToyRobot.Right();
        }
        else if (myToyRobot.inputString == "LEFT")
        {
            myToyRobot.Left();
        }
        else if (myToyRobot.inputString == "MOVE")
        {
            myToyRobot.Move();
        }
    }
}
