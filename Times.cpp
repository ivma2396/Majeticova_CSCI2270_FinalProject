#include "Times.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>

Times::Times()
{
    head = NULL;
    //ctor
}

Times::~Times()
{
    //dtor
}

void Times::MainMenu(){
    cout << "======Main Menu======" << endl;
    cout << "1. Print List"<<endl;
    cout<< "2. Print the nth place winner"<<endl;
    cout<< "3. Find Swimmer"<<endl;
    cout<< "4. Find the ties"<<endl;
    cout<< "5. Find average time"<<endl;
    cout<< "6. Find improvement of an individual swimmer"<<endl;
    cout<< "7. Print selected places"<<endl;
    cout<< "8. Print swimmers that went between 2 given times"<<endl;
    cout << "9. Quit"<<endl;

}

void Times::PrintCertainPlace(){
    cout<<"What places should I print out (between 1 and 99)?"<<endl; //Specifies what places are valid
    int b;
    int e;
    cout<<"Starting place: ";
    cin>>b;
    while((b<1)||(b>99)) //Only allows for valid input
    {
        cout<<"Please enter number between 1 and 99"<<endl;
        cout<<"Starting place: ";
        cin>>b;
    }
    cout<<"Ending place: ";
    cin>>e;
    while((e<1)||(e>99)||(e<b)) //Only allows for input which is valid and is greater than the starting time
    {
        if((e<1)||(e>99))
        {
            cout<<"Please enter number between 1 and 100"<<endl;
        }
        else if (e<b)
        {
            cout<<"Please enter number greater than or equal to "<<b<<endl;
        }
        cout<<"Ending place: ";
        cin>>e;
    }
    Place *tmp = head;
    while(tmp->next!=NULL){
        if(tmp->place >=b and tmp->place<=e){
            cout<<tmp->place<<": "<<tmp->first<<" "<<tmp->last<<": "<<tmp->FTime<<endl;
        }
        tmp = tmp->next;
    }
}

void Times::PrintCertainTimes(){
    double b;
    double e;
    cout<<"Please Enter Times Between 29.87 s and 37 s Separated by At least .01 s"<<endl;
    cout<<"Starting time: ";
    cin>>b;
    while((b< 29.87)||(b>=37))
    {
    cout<<"Please Enter Times Between 29.87 s and 36.99 s (for Starting Time) Separated by At least .01 s"<<endl;
    cout<<"Starting time: ";
    cin>>b;
    }
    cout<<"Ending time: ";
    cin>>e;
    while((e<29.87)||(e>37)||(e<=b))
    {
        if((e<29.87)||(e>37))
        {
            cout<<"Please Enter Times Between 29.87 s and 37 s Separated by At least .01 s"<<endl;
            cout<<"Starting time: ";
            cin>>e;
        }
        else if((e<=b))
        {
            cout<<"Please enter a Time Greater Than "<<b<<" By At Least 0.01 s"<<endl;
            cin>>e;
        }
    }
    Place *tmp = head;
    bool print = false;
    while(tmp->next!=NULL){
        if(tmp->FTime >=b and tmp->FTime<=e){
            print = true;
            cout<<tmp->place<<": "<<tmp->first<<" "<<tmp->last<<": "<<tmp->FTime<<endl;
        }
        tmp = tmp->next;
    }
    if(!print){
        cout<<"No swimmers went between "<<b<<" and "<<e<<" seconds"<<endl;
    }
}

void Times::FindImprovement(){
    bool foundSwimmer=false; //Added to allow for error output if swimmer not in list
    string fl;
    string name;
    cout<<"Search by (f)irst name of (l)ast name?"<<endl;
    cin>>fl;
    while((fl!="f")&&(fl!="l"))
    {
        cout<<"Please enter \'f\' for first or \'l\' for last"<<endl;
        cin>>fl;
    }
    cout<<"Which swimmer would you like to find the improvement of? (please capitalize first letter)"<<endl;
    cin>>name;
    Place *tmp = head;
    Place *found = NULL;
    double improvement = 0;
    while(tmp->next!=NULL){
        if(fl=="f"){
            if(tmp->first==name){
                foundSwimmer=true; //Swimmer found in list
                improvement = tmp->PTime - tmp->FTime;
                if(improvement <0){
                    float improvement2 = -1*improvement;
                    cout<<tmp->first<<" " <<tmp->last<<" did not improve, she added "<<improvement2<<" seconds"<<endl;
                }
                else
                    cout<<tmp->first<<" " <<tmp->last<<" improved by "<<improvement<<" seconds"<<endl;
            }
        }
        else{
            if(tmp->last==name){
                foundSwimmer=true;
                improvement = tmp->PTime - tmp->FTime;
                if(improvement <0){
                    float improvement2 = -1*improvement;
                    cout<<tmp->first<<" " <<tmp->last<<" did not improve, she added "<<improvement2<<" seconds"<<endl;
                }
                else
                    cout<<tmp->first<<" " <<tmp->last<<" improved by "<<improvement<<" seconds"<<endl;
            }
            }
        tmp= tmp->next;
    }
    if(foundSwimmer==false) //If the swimmer is not in the list
    {
        cout<<"Swimmer not found"<<endl;
    }
}


void Times::FindAvg(){
    Place *tmp = head;
    double total;
    int elements;
    while(tmp->next!=NULL){
        total = total + tmp->FTime;
        elements++;
        tmp=tmp->next;
    }
    double avg = total/elements;
    cout<<"The average time for this event was "<<avg<<" seconds"<<endl;
}

void Times::readFile(char *filename){
    ifstream inFile;
    string tmp;
    string data;
    string lastName; ///established variables needed for opening a file
    string firstName;
    float PTime;
    float FTime;
    int place;
    inFile.open(filename);///opens the file
        if(!inFile.good()){
        cout<<"File did not open"<<endl;///reads the file
        }
    while(getline(inFile, data)){
        stringstream ss(data);///creates a stringstream
        getline(ss,tmp,',');///separates the string by the ','
        place= atoi(tmp.c_str());///writes the part of the string into a variable and converts it to an integer
        getline(ss,tmp,',');
        lastName=tmp;
        getline(ss,tmp,',');
        firstName=tmp;
        getline(ss,tmp,',');
        PTime= atof(tmp.c_str());
        getline(ss,tmp,',');
        FTime= atof(tmp.c_str());
        addNode(place,lastName,firstName,PTime,FTime); ///calls the function add node with the given variables
    }
}

void Times::addNode(int place, string last, string first, float PTime, float FTime){
    Place *node = new Place(place, last, first, PTime, FTime);
    Place *tmp = head;
    if(tmp==NULL){
        head = node;
    }
    else{
        while(tmp->next!=NULL){
            if(tmp->FTime < node->FTime)
                tmp = tmp->next;
        }
        tmp->next = node;
        node->prev = tmp;
    }
}

void Times::PrintList(){
    Place *tmp = head;
    while(tmp->next!=NULL){
        cout<<tmp->place<<": "<<tmp->first<<" "<<tmp->last<<": "<<tmp->FTime<<endl;
        tmp = tmp->next;
    }
}

void Times::PrintPlace(){
    int placeV;
    cout<<"What place should I print out (between 1 and 99)?"<<endl;
    cout<<"Enter place: ";
    cin>>placeV;
    while((placeV<0)||(placeV>99))
    {
        cout<<"Please enter a number between 1 and 99"<<endl;
        cout<<"What place should I print out (between 1 and 99)?"<<endl;
        cout<<"Enter place: ";
        cin>>placeV;
    }
    Place *tmp = head;
    while(tmp->next!=NULL){
        if(tmp->place == placeV){
            cout<<placeV<<" place was claimed by "<<tmp->first<<" "<<tmp->last<<" with a time of "<<tmp->FTime<<" seconds"<<endl;
        }
        tmp = tmp->next;
    }
}
void Times::FindSwimmer(){
    bool foundSwimmer=false; //Variable to determine if swimmer is in list
    string fl;
    string name;
    cout<<"Search by (f)irst name of (l)ast name?"<<endl;
    cin>>fl;
    while((fl!="f")&&(fl!="l"))
    {
        cout<<"Please enter \'f\' for first or \'l\' for last"<<endl;
        cin>>fl;
    }
    cout<<"Which swimmer would you like to find? (please capitalize first letter)"<<endl;
    cin>>name;
    Place *tmp = head;
    if(fl == "f"){
        while(tmp->next!=NULL){
            if(tmp->first==name){
                foundSwimmer=true;
                cout<<tmp->place<<": "<<tmp->first<<" "<<tmp->last<<" : "<<tmp->FTime<<endl;
            }
            tmp = tmp->next;
        }
    }
    if(fl == "l"){
        while(tmp->next!=NULL){
            if(tmp->last==name){
                foundSwimmer=true;
                cout<<tmp->place<<": "<<tmp->first<<" "<<tmp->last<<" : "<<tmp->FTime<<endl;
            }
            tmp = tmp->next;
        }
    }
    if(foundSwimmer==false)
    {
        cout<<"Swimmer not found"<<endl;
    }
}

void Times::FindTies(){
    Place *tmp = head;
    int ties = 0;
    vector <Place> tiesV;
    while(tmp->next->next!=NULL){
        if(tmp->FTime == tmp->next->FTime){
            ties++;
            tiesV.push_back(*tmp);
            tiesV.push_back(*tmp->next);
        }
        tmp=tmp->next;
    }
    cout<<"There were "<<ties<<" ties in this event: "<<endl;
    for(int i=0; i<tiesV.size();i++){
        cout<<tiesV[i].place<<": "<<tiesV[i].first<<" "<<tiesV[i].last<<" : "<<tiesV[i].FTime<<endl;
    }
}
