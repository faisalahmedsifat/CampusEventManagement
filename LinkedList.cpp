
#include "LinkedList.h"

void LinkedList::addEvent(Event *event)
{
    if (!head)
    {
        head = event;
    }
    else
    {
        Event *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = event;
    }
}

bool LinkedList::checkSlotAvailability(const string &date, const int &slot, const int &room)
{
    Event *temp = head;
    while (temp)
    {
        if (temp->date == date && temp->slot == slot && temp->room == room)
        {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

void LinkedList::updateEvent(int eventID, const string &title, const string &description, const string &date, const int &slot, const int &room)
{
    Event *event = searchEventByID(eventID);
    if (event)
    {
        event->title = title;
        event->description = description;
        event->date = date;
        event->slot = slot;
        event->room = room;

    }
    else
    {
        cout << "Event not found.\n";
    }
}

void LinkedList::deleteEvent(int eventID)
{
    Event *temp = head;
    Event *prev = nullptr;

    if (temp && temp->eventID == eventID)
    {
        head = temp->next;
        delete temp;
        return;
    }

    while (temp && temp->eventID != eventID)
    {
        prev = temp;
        temp = temp->next;
    }

    if (!temp)
        return;

    prev->next = temp->next;
    delete temp;
}

Event *LinkedList::searchEventByID(int eventID)
{
    Event *temp = head;
    while (temp)
    {
        if (temp->eventID == eventID)
        {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}
void LinkedList::displayEvents(User *currentUser)
{
    Event *temp = head;
    cout << "\nEvents: " << endl;

    while (temp)
    {
        if (currentUser->userID == 1 || temp->ownerID == currentUser->userID)
        {
            cout << "ID: " << temp->eventID << ", Title: " << temp->title << ", Date: " << temp->date << ", Slot: " << temp->slot << ", Room: " << temp->room << "\n";
            cout << "Attendees: ";
            for (const auto &attendee : temp->attendees)
            {
                cout << "Name: " << attendee.first << ", Student ID: " << attendee.second << "\n";
            }
            cout << "\n";
        }
        temp = temp->next;
    }

    cout << endl;
}
void LinkedList::clear()
{
    Event *temp = head;
    while (temp)
    {
        Event *next = temp->next;
        delete temp;
        temp = next;
    }
    head = nullptr;
}
void LinkedList::addAttendee(int eventID, const string &attendee, int studentID)
{
    Event *event = searchEventByID(eventID);
    if (event)
    {
        event->attendees.push_back(make_pair(attendee, studentID));
    }
    else
    {
        cout << "Event not found.\n";
    }
}

void LinkedList::removeAttendee(int eventID, int studentID)
{
    Event *event = searchEventByID(eventID);
    if (event)
    {
        auto &attendees = event->attendees;
        attendees.erase(remove_if(attendees.begin(), attendees.end(),
                                  [studentID](const pair<string, int> &attendee)
                                  { return attendee.second == studentID; }),
                        attendees.end());
    }
    else
    {
        cout << "Event not found.\n";
    }
}

void LinkedList::displayAttendees(int eventID)
{
    Event *event = searchEventByID(eventID);
    if (event)
    {
        cout << "Attendees for event " << event->title << ":\n";
        for (const auto &attendee : event->attendees)
        {
            cout << "Name: " << attendee.first << ", Student ID: " << attendee.second << "\n";
        }
    }
    else
    {
        cout << "Event not found.\n";
    }
}

// void LinkedList::saveToFile(const string &filename)
// {
//     ofstream file(filename);
//     Event *temp = head;
//     while (temp)
//     {
//         file << temp->eventID << "," << temp->ownerID << "," << temp->title << "," << temp->description << "," << temp->date << "," << temp->time << "," << temp->location;
//         for (const auto &attendee : temp->attendees)
//         {
//             file << "," << attendee;
//         }
//         file << "\n";
//         temp = temp->next;
//     }
// }

// void LinkedList::loadFromFile(const string &filename)
// {
//     ifstream file(filename);
//     string line;
//     while (getline(file, line))
//     {
//         stringstream ss(line);
//         string token;
//         vector<string> tokens;
//         while (getline(ss, token, ','))
//         {
//             tokens.push_back(token);
//         }
//         if (tokens.size() >= 7)
//         {
//             int id = stoi(tokens[0]);
//             int ownerID = stoi(tokens[1]);
//             Event *event = new Event(id, tokens[2], tokens[3], tokens[4], tokens[5], tokens[6], ownerID);
//             for (size_t i = 7; i < tokens.size(); ++i)
//             {
//                 event->attendees.push_back(tokens[i]);
//             }
//             addEvent(event);
//         }
//     }
// }
