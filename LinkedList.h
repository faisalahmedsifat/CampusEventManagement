
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
    void updateEvent(int eventID, const string &title, const string &description, const string &date, const int &slot, const int &room);
    void deleteEvent(int eventID);
    Event *searchEventByID(int eventID);
    void displayEvents(User *currentUser);
    void addAttendee(int eventID, const string &attendee, int studentID);
    void removeAttendee(int eventID, int studentID);
    void displayAttendees(int eventID);
    void clear();
    bool checkSlotAvailability(const string &date, const int &slot, const int &room);
    // void saveToFile(const string &filename);
    // void loadFromFile(const string &filename);
};

#endif
