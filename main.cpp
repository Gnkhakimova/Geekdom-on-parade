/*

Name:	Gulnoza Khakimova
Course: CS 201R
Program:  Geekdom on parade
Due Date:	05/09/2016
Description:  A large collection of data and a collection of
queues to manage it.
Inputs:	Data from input file
Outputs: First output  each team in order, listing the number of problems solved and total
times for each; the second lists the teams by score (problems solved, ties on problems solved broken
based on time, lower time wins).  
Algorithm:
• Write a template Queue class, using a linked-list as the underlying data structure.
• Create a simple struct containing time, team number, problem, and a record of whether the
problem was solved (either a bool or a string). If the problem was not solved, you do not need
to record the judging feedback.
• There will be no more than 30 teams in the contest. Create an array of 30 Queues of this struct,
one for each team.
• Use the array of queues to separate each team's records, then process each team separately.
• Remember scoring details:
? The basic score for each correctly-solved problem is the time at which the solution is turned
in, plus
? 20 minutes penalty for each incorrect solution submitted prior to the correct solution.
? If a team submitted incorrect solutions but never solved the problem, there is no effect on
the score.
• The input file is in chronological order. There may be multiple entries for the same time.


*/

#include<iostream>
#include<fstream>
#include<string>
#include "Queue.h"
#include "algorithm"

using namespace std;

// Create a simple struct containing time, team number, problem, and a record of whether the
//problem was solved
struct Data
{
    int time;
    int teamNumber;
    char problem;
    string record;
};

int main()
{
    // creating an array of 20 queues
    Queue<Data> teamList [30];
    Data values;
    //open input and output files change the paths as needed
    ifstream fin("Data_01.csv");
    ofstream fout1("team.txt");
    ofstream fout2("ranking.txt");
    // declaring all variables
    string junk;
    int time1;
    int teamNumber1;
    char problem1;
    string language1;
    string record1;
    // declaring arrays
    int arrayOfTeams[30];
    int NumberOfProblemsSolved[30];
    int TimeToSolve[30];
    int SortedTeams[30];
    string Output1;
    string Output2;
        // read in the data from inout file
    while (fin >> time1 >> teamNumber1 >> problem1 >> language1 >> record1)
    {
        values.time = time1;
        values.teamNumber = teamNumber1;
        values.problem = problem1;
        values.record = record1;
        // if team did not solved a problem read in data after "No" and store variables into a queue
        if (record1 == "No")
        {
            getline(fin, junk);
            teamList[teamNumber1 - 1].push_back(values);
        }
        // if team solved a problem and store data into a queue
        else
        {
            teamList[teamNumber1-1].push_back(values);
        }
         
    }
    //iterate through the data
   for (int i = 0; i < 30; i++)
    {
        // declaring variables
        static int TimePenalty = 20;
        int NumberCompleted = 0;
        int TotalTime = 0;
        
        int TimeA = 0;
        int TimeB = 0;
        int TimeC = 0;
        int TimeD = 0;
        int TimeE = 0;
        int TimeF = 0;
        int TimeG = 0;
        int TimeH = 0;

        bool ACompleted = 0;
        bool BCompleted = 0;
        bool CCompleted = 0;
        bool DCompleted = 0;
        bool ECompleted = 0;
        bool FCompleted = 0;
        bool GCompleted = 0;
        bool HCompleted = 0;
        //check it while array is not empty
        while (teamList[i].isEmpty() != true)
        {
              Data temp2 = teamList[i].pop_front();
            //checking which problems been solved
            switch (temp2.problem)
            {
            case ('A') :
                TimeA++;
                break;
            case ('B') :
                TimeB++;
                break;
            case ('C') :
                TimeC++;
                break;
            case ('D') :
                TimeD++;
                break;
            case ('E') :
                TimeE++;
                break;
            case ('F') :
                TimeF++;
                break;
            case ('G') :
                TimeG++;
                break;
            case ('H') :
                TimeH++;
                break;
            }
            //check if problem was solved
            if (temp2.record == "Yes")
            {
                NumberCompleted++;
                //colculate the time that they spent on solving a problems
                switch (temp2.problem)
                {
                case ('A') :
                    TimeA = TimeA*TimePenalty - TimePenalty + temp2.time;
                    ACompleted = 1;
                    break;
                case ('B') :
                    TimeB = TimeB*TimePenalty - TimePenalty + temp2.time;
                    BCompleted = 1;
                    break;
                case ('C') :
                    TimeC = TimeC*TimePenalty - TimePenalty + temp2.time;
                    CCompleted = 1;
                    break;
                case ('D') :
                    TimeD = TimeD*TimePenalty - TimePenalty + temp2.time;
                    DCompleted = 1;
                    break;
                case ('E') :
                    TimeE = TimeE*TimePenalty - TimePenalty + temp2.time;
                    ECompleted = 1;
                    break;
                case ('F') :
                    TimeF = TimeF*TimePenalty - TimePenalty + temp2.time;
                    FCompleted = 1;
                    break;
                case ('G') :
                    TimeG = TimeG*TimePenalty - TimePenalty + temp2.time;
                    GCompleted = 1;
                    break;
                case ('H') :
                    TimeH = TimeH*TimePenalty - TimePenalty + temp2.time;
                    HCompleted = 1;
                    break;
                }
            }
        }
        //calculate the time and penalties
        TotalTime = TimeA * ACompleted + TimeB * BCompleted + TimeC * CCompleted +
            TimeD * DCompleted + TimeE * ECompleted + TimeF * FCompleted + 
            TimeG * GCompleted + TimeH * HCompleted ;
        //store number of problems solved into an array
        NumberOfProblemsSolved[i] = NumberCompleted;
        //store time that teams spent to solve a probles into an array
        TimeToSolve[i] = TotalTime;
    }
        //loop through array to create an output
    for (int n = 0; n < 30; n++)
                
            {
                    Output1 += "Team " + to_string(n + 1) + " completed " + to_string(NumberOfProblemsSolved[n]) +
                        " tasks " + " in " + to_string(TimeToSolve[n]) + " minutes.\n";
            }
   //check who solved the largesr number of problems, if they are equal check timing
   for (int j = 8; j > 0; j--)
    {
        int TempArrayOfTasks[30];
        int TempArrayNumber = 0;
        int TempArrayOfTimes[30];

        for (int i = 0; i < 30; i++)
        {
            if (NumberOfProblemsSolved[i] == j)
            {
                TempArrayOfTimes[TempArrayNumber] = TimeToSolve[i];
                TempArrayNumber++;
            }
        }
        //loop through an array to produce second output
        for (int l = 0; l < TempArrayNumber; l++)
        {
            sort(TempArrayOfTimes, TempArrayOfTimes + l);
            int tempTime = TempArrayOfTimes[l];
            for (int m = 0; m < 30; m++)
            {
                if (TimeToSolve[m]==tempTime)
                {
                    Output2 += "Team " + to_string(m + 1) + " completed " + to_string(NumberOfProblemsSolved[m]) +
                        " tasks " + " in " + to_string(TimeToSolve[m]) + " minutes.\n";
                    int z = m;
                }
            }
        }
    }
   // output the data into a files
   fout1 << Output1 << endl;
   fout2 << Output2 << endl;
   // close the file
   fin.close();
   return 0;
}


