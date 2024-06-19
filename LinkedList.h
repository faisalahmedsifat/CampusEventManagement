
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Event.h"
#include "User.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class LinkedList
{
public:
    Event *head;

    LinkedList() : head(nullptr) {}

    void addEvent(Event *event);
    void updateEvent(int eventID, const string &title, const string &description, const string &date, int room, const string &startTime, const string &endTime);
    void deleteEvent(int eventID);
    Event *searchEventByID(int eventID);
    void displayEvents(User *currentUser);
    void addAttendee(int eventID, const string &attendee, string studentID);
    void removeAttendee(int eventID, string studentID);
    void displayAttendees(int eventID);
    void clear();
    bool checkSlotAvailability(const string &date, int room, const string &startTime, const string &endTime);
    vector<Event *> searchEventsByTitle(const string &title);
    vector<Event *> searchEventsByDate(const string &date);
    vector<Event *> searchEventsByTime(const string &time);
    vector<Event *> searchEventsByLocation(int room);
    // void saveToFile(const string &filename);
    // void loadFromFile(const string &filename);
};

#endif
