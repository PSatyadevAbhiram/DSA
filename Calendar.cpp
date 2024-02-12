#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Event{
    public:
    string name;
    string time;

    Event(string n, string t): name(n), time(t) {}
};

class Node{
    public:
    string date;
    Event event;
    Node* next;

    Node(string d, Event e) : date(d), event(e), next(nullptr) {} 
};

class Calendar{
    private:
        unordered_map<string, Node*> calendarMap;
    public:
        //Function to add an event in a calendar
        void addEvent(string date, string eventName, string eventTitle){
            Event event(eventName, eventTitle);
            Node* newNode = new Node(date, event);
            if(calendarMap.find(date) == calendarMap.end()){
                calendarMap[date] = newNode;
            }
            else{
                Node* temp = calendarMap[date];
                while(temp->next){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        void getEvents(string date){
            if(calendarMap.find(date) == calendarMap.end()){
                cout<<"No event found for that date."<<endl;
                return;
            }
            Node* temp = calendarMap[date];
            cout<<"Events for"<<date<<": "<<endl;
            while(temp){
                cout<<temp->event.name<<"  "<<temp->event.time<<endl;
                temp = temp->next;
            }
        }
};

int main(){
    Calendar calendar;
    // Adding events to the calendar
    calendar.addEvent("2024-02-11", "Meeting with client", "10:00 AM");
    calendar.addEvent("2024-02-11", "Lunch with team", "12:00 PM");
    calendar.addEvent("2024-02-15", "Birthday party", "7:00 PM");
    
    // Getting events for a specific date
    calendar.getEvents("2024-02-11");
    calendar.getEvents("2024-02-15");
    calendar.getEvents("2024-02-20");

    return 0;
}