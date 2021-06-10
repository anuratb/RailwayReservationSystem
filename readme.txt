Name :Anurat Bhattacharya
Roll :19CS10071


Description of Folders:
-----------------------

1)include : Contains all the project headers
2)src : Contains all the Implementations to the headers in src
3)test_include : Contains the header for Test application
4)test_src : Contains the implementation of the test header in test_include
5)build : Contains the Makefile ,the object (*.o) files and executables
6)outputs : Contains all the golden outputs (This is required for the program to read the golden outputs and compare)
    |-->unit_test_goldens: Contains golden outputs of the output stream operator of all classes
    |-->application_golden_output.txt : Golden output for the test application (self written)
    |-->sample_application_golden_output.txt : Golden output for the sample test application as given in the Assignment



STEPS FOR RUNNING THE PROGRAM:
------------------------------
1)Open the project directory
2)Go to build folder by typing "cd build" in the terminal
3)Type the following commands to run the program
    -->"make testapp" : Compiles the program and links all project files and sample test application creating executable "testapp"
    -->"make testunit" : Compiles the program and Links all project files and self written test application and creates executable "testunit"
    -->"./testapp" : To run the application test
    -->"./testunit" : To run the unit tests
    -->"make clean" : To clean all object files
4)For specifically running the test application type 
        1) "make clean"       (In order to clean any residual .o files) 
        2) "make testapp" or "make testunit"         
        3) "./testapp"    or "./testunit"


**Note : Type the terminal commands without the quotes(they are only for clarity here)

COMPILER VERSION : 
------------------
g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Copyright (C) 2019 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.


COMPILER FLAGS : 
                 -c     (To compile and create .o files)
                 -o     (To link the .o files and create the executable)
