#include<cstdio>
#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<windows.h>
#include<list>
#include<string>
#include <limits>
using namespace std;
class Money
{
public:
    int cash;
    Money() 
    {
        cash = 1;
    }
    void MoneyAdd(int cash_) 
    {
        cash += cash_;
    }
}money;
class Job {
public:
    string name;
    string desc;
    int level;
    int maxLevel;
    int price;
    int reward;
    time_t startTime;
    int secondsToGo;
    float timeToShow;
    Job(string name_, string desc_, int price_, int reward_,int secondsToGo_) {
        level = 0;
        maxLevel = 20;
        name = name_;
        desc = desc_;
        price = price_;
        reward = reward_;
        secondsToGo = secondsToGo_;
        timeToShow = 0;
        StartWorking();
    }
    void StartWorking() 
    {
        startTime = time(NULL);
    }
    void CheckWorkDone()
    {
        if (level!=0)
        {
            int currentTime = time(NULL);
            
            int secondsPassed = (currentTime - startTime);
            int CirclesDoneInt = secondsPassed / secondsToGo;
            float CirclesDoneFloat = secondsPassed % secondsToGo;
            int secondsSpare = secondsPassed - CirclesDoneInt * secondsToGo;
            
            if (CirclesDoneInt >= 1)
            {
                money.MoneyAdd(reward * CirclesDoneInt);
                startTime = currentTime - secondsSpare;
            }
            timeToShow = (float)(CirclesDoneFloat / secondsToGo);
        }
        
    }
};
class Game {
public:
    list<Job> jobs;
    list<Job>::iterator it;
    Job j1 = Job("Biznes1", "Zwykly biznes", 1, 1, 5);
    /*Job j2 = Job("Biznes2", "Zwykly biznes", 0, 500, 500, 1, 5, true);
    Job j3 = Job("Biznes3", "Zwykly biznes", 0, 500, 500, 1, 5, true);
    Job j4 = Job("Biznes4", "Zwykly biznes", 0, 500, 500, 1, 5, true);
    Job j5 = Job("Biznes5", "Zwykly biznes", 0, 500, 500, 1, 5, true);
    Job j6 = Job("Biznes6", "Zwykly biznes", 0, 500, 500, 1, 5, true);
    Job j7 = Job("Biznes7", "Zwykly biznes", 0, 500, 500, 1, 5, true);
    Job j8 = Job("Biznes8", "Zwykly biznes", 0, 500, 500, 1, 5, true);*/
    Game() {
        jobs.push_back(j1);
        /*jobs.push_back(j2);
        jobs.push_back(j3);
        jobs.push_back(j4);
        jobs.push_back(j5);
        jobs.push_back(j6);
        jobs.push_back(j7);
        jobs.push_back(j8);*/
    }
    void Menu() {
        cout << "IT CAPITALIST \n";
        cout << "CASH: " << money.cash << " CPU's \n\n";
        for (it = jobs.begin(); it != jobs.end(); ++it)
        {
            cout << it->name << endl;
            cout << it->desc << endl;
            if (it->level!=0)
            {
                cout << "PRICE: " << it->price << endl;
                cout << "TIME: " << it->timeToShow << endl;
                cout << "LEVEL: " << it->level << " / " << it->maxLevel << "\n\n";
            }
            else
            {
               cout << "LOCKED\n\n";
            }
            
        }
    }
    void Commands(string code)
    {
        string cheatCodes[] = { "alldone", "unlockall", "firstday" };
        if (code == cheatCodes[0])
        {
            for (it = jobs.begin(); it != jobs.end(); ++it)
            {
                   it->level = 100;

            }
        }
        else if (code == cheatCodes[1])
        {
            for (it = jobs.begin(); it != jobs.end(); ++it)
            {
                if (it->level == 0)
                {
                    it->level = 1;
                }
            }
        }
        else if (code == cheatCodes[2])
        {
            jobs.begin()->level = 500;
        }
        else if (code.substr(0, 7) == "upgrade") 
        {
            char index = code.back();
            int number = (int)index;
            cout << index;
        }
    }
    void ClearScreen()
    {
        cout << string(100, '\n');
    }
    void CheckWorkDone() 
    {
        for (it = jobs.begin(); it != jobs.end(); ++it)
        {
            it->CheckWorkDone();
        }
    }
}game;

int main() {
    string command;
    for (;;) {
        game.Menu();
        do {
            cout << "Press ENTER" << endl;
            getline(cin, command);
            game.Commands(command);      
        } while (command.length() != 0);
        game.ClearScreen();
        game.CheckWorkDone();
    }
    return 0;

}