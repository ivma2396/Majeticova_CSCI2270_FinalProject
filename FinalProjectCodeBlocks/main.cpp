#include <iostream>
#include "Times.h"

using namespace std;

int main(int argc, char **argv)
{if(argc<2){
    cout<<argc<<endl;
    cout<<"usage: <filename> <top n>\n";
    return -1;
}
Times T;
T.readFile(argv[1]);
int choice=0;
while(choice!=9){
    T.MainMenu();
    cin>>choice;
    if(choice == 1)
        T.PrintList();
    if(choice == 2)
        T.PrintPlace();
    if(choice == 3)
        T.FindSwimmer();
    if(choice==4)
        T.FindTies();
    if(choice == 5)
        T.FindAvg();
    if(choice == 6)
        T.FindImprovement();
    if(choice == 7)
        T.PrintCertainPlace();
    if(choice == 8)
        T.PrintCertainTimes();
}
cout<<"Thank you for visiting"<<endl;

    return 0;
}
