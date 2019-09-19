# ToyRobot

This Toy Robot Simulator was created using C++ in Xcode as a console application. 

* The library allows for a simulation of a toy robot moving on a 5 x 5 square tabletop (but can be changed in code with the variable `maxTableDimension`).
* There are no obstructions on the table surface.
* The robot is free to roam around the surface of the table. Any movement that would result in the robot being outside the table will be prevented, however further valid movement commands are still allowed.
* `PLACE` will put the toy robot on the table in position X,Y and facing NORTH, SOUTH, EAST or WEST.
* (0,0) can be considered as the SOUTH WEST corner and (4,4) as the NORTH EAST corner.
* The first valid command to the robot is a `PLACE` command. After that, any sequence of commands may be issued, in any order, including another `PLACE` command. The simulation will discard all commands in the sequence until a valid `PLACE` command has been executed.
* The `PLACE` command will be discarded if it places the robot outside of the table surface.
* `MOVE` will move the toy robot one unit forward in the direction it is currently facing.
* `LEFT` and `RIGHT` will rotate the robot 90 degrees in the specified direction without changing the position of the robot.
* `REPORT` will announce the X,Y and orientation of the robot.
* A robot that is not on the table will ignore the `MOVE`, `LEFT`, `RIGHT` and `REPORT` commands.
* The simulation will discard all invalid commands and parameters.


## To run the simulator
### Xcode:
1. Create a new console project (Command Line Tool) in Xcode. Name the project ToyRobot and select C++ for language. Delete any new .cpp and .hpp files that are added by default.

2. Copy and paste all the files (i.e., RunToyRobot.cpp, ToyRobot.cpp, and ToyRobot.hpp) into the project directory. In Xcode, this is the folder with the project name (i.e., ToyRobot) in the Project Navigator (View->Navigators->Show Project Navigator).

3. Build and run the RunToyRobot.cpp file. In Xcode, click Product->Build and then Product->Run, or press cmd+B and then cmd+R.

4. Use the Xcode console (All Output) at the bottom of the app to input commands

### `g++` GNU C++ compiler (macOS):
1. Open the terminal window and compile the RunToyRobot.cpp file into a .o file by typing the following command line:
```
g++ -c -o RunToyRobot.o RunToyRobot.cpp
``` 

2. Compile the ToyRobot.cpp file into a .o file by typing the following command line (make sure that the ToyRobot.hpp is in the same directory): 
```
g++ -c -o ToyRobot.o ToyRobot.cpp
``` 


3. Link all the .o files together into an executable as follows: 
```
g++ -o RunToyRobot ToyRobot.o RunToyRobot.o -lm
```

4. To run the executable, type `./RunToyRobot`. 

5. You can now enter the commands that you want the robot to carry out. 

### Examples:
```
PLACE 2,1,SOUTH
MOVE
MOVE
REPORT
Output: 2,0,SOUTH
```
```
PLACE 1,2,EAST
MOVE
MOVE
LEFT
MOVE
REPORT
Output: 3,3,NORTH
```
```
PLACE 0,0,NORTH
MOVE
MOVE
RIGHT
MOVE
MOVE
REPORT
Output: 2,2,EAST
```

Note that it is assumed the simulation runs continuously, thus you must manually stop the application to quit the simulator.
