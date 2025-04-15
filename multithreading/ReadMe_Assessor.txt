// ReadMe for Assessor
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

F A Q

1. Why use C++ 11
-> The features i used for logic are most stable in 11 and for multithreading i didnt have the need for future or final.

2. Why Structure not classes
-> The valued data set variables were less in numbers setting the need for memory management close to void (destructure)
   also handling structure is easier.

3. Why Chose these DS 
-> the structure in input is mostly tabular and map is the best close one structure for storage
   also the libraries in unordered map are less complicated when the data is not keyed

4. References if any
-> for TPC-H "https://github.com/electrum/tpch-dbgen/tree/master"

-> for Makefile "https://makefiletutorial.com/"
                "https://github.com/veegee29/nivetti-job_scheduler_API/blob/main/build/Makefile"

5. Did use ChatGpt or any ai chatbot  
-> For reference, yes ChatGpt is quicker still i prefer stackoverflow
   The logic is NOT plaguarised.

Approach

1. To begin with i went for the join logic first, I was looking for much optimised way still chose nested method.

2. Initially i only took manual data from csv sample and joined them, later enhanced it to 6 tables.

3. Next approach was with threads, for which i chose thread sequence same i used in my one project on git on thread sequence.

4. After that only accepting the user data and structure forming and designing of system.

5. For CLI i found terminal handling pretty confident and easy to handle as the query5 as per document in TPC-H is unique.