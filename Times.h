#ifndef TIMES_H
#define TIMES_H
#include <iostream>

using namespace std;
struct Place{
    int place;
    string first;
    string last;
    float PTime;
    float FTime;
    Place *prev;
    Place *next;

    Place(){};
    Place(int in_place, string in_last, string in_first, float in_PTime, float in_FTime){
        place = in_place;
        first = in_first;
        last = in_last;
        PTime = in_PTime;
        FTime = in_FTime;
        prev = NULL;
        next = NULL;
    }
};

class Times
{
    public:
        Times();
        virtual ~Times();
        void MainMenu();
        void PrintList();
        void FindTies();
        void readFile(char *filename);
        void PrintPlace();
        void FindSwimmer();
        void FindImprovement();
        void FindAvg();
        void PrintCertainPlace();
        void PrintCertainTimes();

    protected:
    private:
        void addNode(int,string, string, float, float);
        Place *head;
};

#endif // TIMES_H
