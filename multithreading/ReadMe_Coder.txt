// ReadMe for Coders/Developers
// Project: Multithreading C++11 Implementation
// Author : VeeGee

// Directory Structure:
// ├── Makefile
// ├── include/
// │   ├── dataloader.h
// │   ├── models.h
// │   └── utility.h
// ├── src/
// │   ├── main.cpp
// │   └── DataLoader.cpp
// └── build/ (post-compilation generated)

Coding prerequisites:

1.  Knowledge of TPC-H dbgen tool, it is open source data set available on git 
    to clone it ->git clone https://github.com/electrum/tpch-dbgen.git
                ->cd tpch-dbgen

2.  Set up makefile in directory tpch_dbgen as per your machine ( here i used on mac os and CC set to GCC and machine set to MAC same for DATABASE to dbgen)
    please update accordingly then generate the database ->dbgen 

3.  Once the database gets generated move the required tables as per project outline ( here i moved in tpchdata)

4.  Logic for inner join and threading 


Coding standards:

1.  Here I used C++11 standards as in multithreading part i used thread count as input which is friendly when comes with CLI 

2.  Strucures, StringStream, Unordered_map, Vector, Set, Pair and main with arguments
    As a coder one might wonder why use main with arguments, as i wanted to build the system driven project, and in system driven we do no always have right inputs
    To assist the right compilation and debugging made easy used the argument in main so comes cerr.

3.  For build in Makefile i went somewhat ahead as i wanted to see if i can use global variables instead of simply writing path and terminal command
    I took reference from my old projects and from "https://makefiletutorial.com/"

P.S. Again please note for different machines Makefile needs to be modified as per your coding standards.