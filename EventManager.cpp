/**
 * @class EventManager
 * @brief Manages the events and users in the campus event management system.
 *
 * The EventManager class is responsible for managing the events and users in the campus event management system.
 * It provides functionality to create, update, and delete events, as well as add and remove attendees from events.
 * The class also handles user authentication and provides methods to login and logout users.
 *
 * The EventManager class uses the EventList class to store and manage the events, and the User class to store and manage the users.
 * It also provides methods to load and save events and users from/to files.
 *
 * The EventManager class is designed to be used in a campus event management system, where users can create and manage events,
 * and attendees can register for and attend events.
 */
#include "EventManager.h"

EventManager::EventManager() : currentUser(nullptr), nextEventId(1), nextUserId(1)
{
    loadUsers();
    // loadEvents();

    if (users.empty())
    {
        addUser("admin", "admin", true);
    }
}

string EventManager::getCurrentUsername()
{
    if (currentUser)
    {
        return currentUser->getUsername();
    }
    return "";
}

bool EventManager::login(const string &username, const string &password)
{
    loadUsers();
    for (auto &user : users)
    {
        if (user.username == username && user.password == password)
        {
            currentUser = &user;
            cout << "Login successful.\n";
            return true;
        }
    }
    cout << "Invalid credentials.\n";
    return false;
}

void EventManager::logout()
{
    currentUser = nullptr;
    cout << "Logged out.\n";
}

bool EventManager::isAdmin()
{
    return currentUser && currentUser->isAdmin;
}

bool EventManager::addUser(const string &username, const string &password, bool admin)
{
    // loadUsers();
    users.push_back(User(nextUserId++, username, password, admin));
    cout << "User added.\n";
    saveUsers();
    loadUsers();
    return true;
}

void EventManager::createEvent(const string &title, const string &description, const string &date, const string &startTime, const string &endTime, const int &room)
{

    loadEvents();
    if (!eventList.checkSlotAvailability(date, room, startTime, endTime))
    {
        cout << "Slot not available.\n";
        return;
    }

    Event *event = new Event(nextEventId++, title, description, date, room, startTime, endTime, currentUser->userID);

    eventList.addEvent(event);
    cout << "\n---------------------------------\n"
         << endl;
    cout << "Event created." << endl;
    cout << "\n---------------------------------\n"
         << endl;

    saveEvents();
}

void EventManager::updateEvent(int id, const string &title, const string &description, const string &date, const string &startTime, const string &endTime, const int &room)
{
    if (isAdmin() || eventList.searchEventByID(id)->ownerID == currentUser->userID)
    {
        eventList.updateEvent(id, title, description, date, room, startTime, endTime);
        saveEvents();
    }
    else
    {
        cout << "Only admin or the owner can update events.\n";
    }
}

void EventManager::deleteEvent(int id)
{
    if (isAdmin() || eventList.searchEventByID(id)->ownerID == currentUser->userID)
    {
        eventList.deleteEvent(id);
        cout << "Event deleted.\n";
        saveEvents();
    }
    else
    {
        cout << "Only admin or the owner can delete events.\n";
    }
}

void EventManager::displayEvents()
{
    loadEvents();
    eventList.displayEvents(currentUser);
}

Event *EventManager::searchEventByID(int id)
{
    Event *event = eventList.searchEventByID(id);
    if (event)
    {
        cout << "ID: " << event->eventID << ", Title: " << event->title << ", Date: " << event->date << ", Start time: " << event->startTime << ", End Time: " << event->endTime << ", Room: " << event->room << "\n";
        return event;
    }
    else
    {
        cout << "Event not found.\n";
    }
    return nullptr;
}

void EventManager::addAttendee(int id, const string &attendee, string studentID)
{
    if (isAdmin() || eventList.searchEventByID(id)->ownerID == currentUser->userID)
        eventList.addAttendee(id, attendee, studentID);
    saveEvents();
}

void EventManager::removeAttendee(int id, string studentID)

{
    if (isAdmin() || eventList.searchEventByID(id)->ownerID == currentUser->userID)
        eventList.removeAttendee(id, studentID);
    saveEvents();
}

void EventManager::displayAttendees(int id)
{
    if (isAdmin() || eventList.searchEventByID(id)->ownerID == currentUser->userID)
        eventList.displayAttendees(id);
}

void EventManager::searchEventsByTitle(const string &title)
{
    vector<Event *> search_result = eventList.searchEventsByTitle(title);
    for (Event *event : search_result)
    {
        cout << "---------------------------------\n";
        cout << "ID: " << event->eventID << endl;
        cout << "Title: " << event->title << endl;
        cout << "Description: " << event->description << endl;
        cout << "Date: " << event->date << endl;
        cout << "Start Time: " << event->startTime << endl;
        cout << "End Time: " << event->endTime << endl;
        cout << "Room: " << event->room << endl;
        cout << "---------------------------------\n";
    }
}

void EventManager::searchEventsByDate(const string &date)
{
    vector<Event *> search_result = eventList.searchEventsByDate(date);
    for (Event *event : search_result)
    {
        cout << "---------------------------------\n";
        cout << "ID: " << event->eventID << endl;
        cout << "Title: " << event->title << endl;
        cout << "Description: " << event->description << endl;
        cout << "Date: " << event->date << endl;
        cout << "Start Time: " << event->startTime << endl;
        cout << "End Time: " << event->endTime << endl;
        cout << "Room: " << event->room << endl;
        cout << "---------------------------------\n";
    }
}

void EventManager::searchEventsByTime(const string &time)
{
    vector<Event *> search_result = eventList.searchEventsByTime(time);
    for (Event *event : search_result)
    {
        cout << "---------------------------------\n";
        cout << "ID: " << event->eventID << endl;
        cout << "Title: " << event->title << endl;
        cout << "Description: " << event->description << endl;
        cout << "Date: " << event->date << endl;
        cout << "Start Time: " << event->startTime << endl;
        cout << "End Time: " << event->endTime << endl;
        cout << "Room: " << event->room << endl;
        cout << "---------------------------------\n";
    }
}

void EventManager::searchEventsByLocation(int room)
{
    vector<Event *> search_result =  eventList.searchEventsByLocation(room);
    for (Event *event : search_result)
    {
        cout << "---------------------------------\n";
        cout << "ID: " << event->eventID << endl;
        cout << "Title: " << event->title << endl;
        cout << "Description: " << event->description << endl;
        cout << "Date: " << event->date << endl;
        cout << "Start Time: " << event->startTime << endl;
        cout << "End Time: " << event->endTime << endl;
        cout << "Room: " << event->room << endl;
        cout << "---------------------------------\n";
    }
}

void EventManager::saveEvents()
{
    string filename = "events.txt";
    ofstream file(filename);
    if (!file)
    {
        cout << "Error: Failed to open file for writing.\n";
        return;
    }
    Event *temp = eventList.head;
    while (temp)
    {
        file << temp->eventID << "," << temp->ownerID << "," << temp->title << "," << temp->description << "," << temp->date << "," << temp->room << "," << temp->startTime << "," << temp->endTime;
        for (const auto &attendee : temp->attendees)
        {
            file << "," << attendee.first << ":" << attendee.second;
        }
        file << "\n";
        temp = temp->next;
    }
    cout << "Events saved to file.\n";
}

void EventManager::loadEvents()
{
    eventList.clear();
    string filename = "events.txt";
    ifstream file(filename);
    if (!file)
    {
        cout << "Error: Failed to open file for reading.\n";
        return;
    }
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, ','))
        {
            tokens.push_back(token);
        }
        if (tokens.size() >= 7)
        {
            int id = stoi(tokens[0]);
            int ownerID = stoi(tokens[1]);
            int room = stoi(tokens[5]);
           
            Event *event = new Event(id, tokens[2], tokens[3], tokens[4], room, tokens[6], tokens[7], ownerID);
            for (size_t i = 7; i < tokens.size(); ++i)
            {
                size_t pos = tokens[i].find(':');
                string attendeeName = tokens[i].substr(0, pos);
                string attendeeID = tokens[i].substr(pos + 1);
                event->attendees.push_back(make_pair(attendeeName, attendeeID));
            }
            eventList.addEvent(event);
            if (id >= nextEventId)
            {
                nextEventId = id + 1;
            }
        }
    }
    cout << "Events loaded from file.\n";
}

void EventManager::saveUsers()
{
    string filename = "users.txt";
    ofstream file(filename);
    if (!file)
    {
        cout << "Error: Failed to open file for writing.\n";
        return;
    }
    for (const auto &user : users)
    {
        file << user.userID << "," << user.username << "," << user.password << "," << user.isAdmin << "\n";
    }
    cout << "Users saved to file.\n";
}

void EventManager::loadUsers()
{
    users.clear();
    string filename = "users.txt";
    ifstream file(filename);
    if (!file)
    {
        cout << "Error: Failed to open file for reading.\n";
        return;
    }
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string item;
        vector<string> tokens;
        while (getline(ss, item, ','))
        {
            tokens.push_back(item);
        }
        int userID = stoi(tokens[0]);
        string username = tokens[1];
        string password = tokens[2];
        bool isAdmin = tokens[3] == "1";
        users.push_back(User(userID, username, password, isAdmin));
        if (userID >= nextUserId)
        {
            nextUserId = userID + 1;
        }
    }
    cout << "Users loaded from file.\n";
}
