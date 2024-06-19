/**
 * @class EventManager
 * @brief Manages the events and users in a campus event management system.
 * 
 * The EventManager class is responsible for managing events and users in a campus event management system.
 * It provides functionalities to create, update, delete, and display events.
 * It also allows users to login, logout, and perform administrative tasks such as adding users and managing attendees.
 * The class uses a LinkedList to store the events and a vector to store the users.
 * 
 * The EventManager class has the following private member variables:
 * - eventList: A LinkedList object to store the events.
 * - users: A vector of User objects to store the users.
 * - currentUser: A pointer to the currently logged-in user.
 * - nextEventId: An integer to keep track of the next event ID.
 * - nextUserId: An integer to keep track of the next user ID.
 * 
 * The EventManager class provides the following public member functions:
 * - EventManager(): Default constructor to initialize the EventManager object.
 * - bool login(const string &username, const string &password): Logs in a user with the given username and password.
 * - void logout(): Logs out the currently logged-in user.
 * - bool isAdmin(): Checks if the currently logged-in user is an admin.
 * - bool addUser(const string &username, const string &password, bool admin): Adds a new user with the given username, password, and admin status.
 * - void createEvent(const string &title, const string &description, const string &date, const int &slot, const int &room): Creates a new event with the given details.
 * - void updateEvent(int id, const string &title, const string &description, const string &date, const int &slot, const int &room): Updates an existing event with the given ID and details.
 * - void deleteEvent(int id): Deletes an event with the given ID.
 * - void displayEvents(): Displays all the events.
 * - Event *searchEventByID(int id): Searches for an event with the given ID and returns a pointer to it.
 * - void addAttendee(int id, const string &attendee, int studentID): Adds an attendee to an event with the given ID.
 * - void removeAttendee(int id, int studentID): Removes an attendee from an event with the given ID.
 * - void displayAttendees(int id): Displays the attendees of an event with the given ID.
 * - void saveEvents(): Saves the events to a file.
 * - void loadEvents(): Loads the events from a file.
 * - string getCurrentUsername(): Returns the username of the currently logged-in user.
 * - void saveUsers(): Saves the users to a file.
 * - void loadUsers(): Loads the users from a file.
 */
#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H



#include "LinkedList.h"
#include "User.h"
#include <vector>

using namespace std;

class EventManager
{
private:
    LinkedList eventList;
    vector<User> users;
    User *currentUser;
    int nextEventId;
    int nextUserId;

public:
    EventManager();
    bool login(const string &username, const string &password);
    void logout();
    bool isAdmin();
    bool addUser(const string &username, const string &password, bool admin);
    void createEvent(const string &title, const string &description, const string &date, const int &slot, const int &room);
    void updateEvent(int id, const string &title, const string &description, const string &date, const int &slot, const int &room);
    void deleteEvent(int id);
    void displayEvents();
    Event *searchEventByID(int id);
    void addAttendee(int id, const string &attendee, int studentID);
    void removeAttendee(int id, int studentID);
    void displayAttendees(int id);
    void saveEvents();
    void loadEvents();
    string getCurrentUsername();
    void saveUsers();
    void loadUsers();
};

#endif
