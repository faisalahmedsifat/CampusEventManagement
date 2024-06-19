#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <vector>
#include <utility>

using namespace std;

class Event
{
public:
    int eventID;
    string title;
    string description;
    string date;
    int room;
    string startTime;                    // added start time
    string endTime;                      // added end time
    vector<pair<string, string>> attendees; // pair of attendee name and student ID
    int ownerID;

    Event *next;

    Event(int id, const string &t, const string &d, const string &dt, int r, const string &start, const string &end, int owner)
        : eventID(id), title(t), description(d), date(dt), room(r), startTime(start), endTime(end), ownerID(owner), next(nullptr) {}
};

#endif
