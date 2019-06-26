------------------------------
     TOY ROBOT SIMULATOR
------------------------------

The Toy Robot Simulator was created using C++ in Xcode as a console application. 


To run the simulator:
=====================
1. Create a new console project (Command Line Tool) in Xcode. Name the project ToyRobot. Delete any new .cpp and .hpp files that are added by default.

2. Copy and paste all the files (i.e., RunToyRobot.cpp, ToyRobot.cpp, and ToyRobot.hpp) into the project directory. In Xcode, this is the folder with the project name (i.e., ToyRobot) in the Project Navigator (View->Navigators->Show Project Navigator).

3. Build and run the RunToyRobot.cpp file. In Xcode, click Product->Build and then Product->Run, or press cmd+B and then cmd+R.

4. Use the Xcode console (All Output) at bottom of the app to input commands

Examples:
a)
PLACE 2,1,SOUTH
MOVE
MOVE
REPORT
Output: 2,0,SOUTH

b)
PLACE 1,2,EAST
MOVE
MOVE
LEFT
MOVE
REPORT
Output: 3,3,NORTH

c)
PLACE 0,0,NORTH
MOVE
MOVE
RIGHT
MOVE
MOVE
REPORT
Output: 2,2,EAST


Note that it is assumed the simulation runs continuously, thus you must manually stop the application to quit the simulator.