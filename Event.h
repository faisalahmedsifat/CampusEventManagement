#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <vector>

using namespace std;

class Event
{
public:
    int eventID;
    string title;
    string description;
    string date;
    int slot;
    int room;
    vector<pair<string, int>> attendees;
    int ownerID;

    Event *next;

    Event(int id, const string &t, const string &d, const string &dt, const int &slot, const int &room, int ownerID)
        : eventID(id), ownerID(ownerID), title(t), description(d), date(dt), slot(slot), room(room), next(nullptr) {}
};

#endif
