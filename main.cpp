#include <iostream>
#include "EventManager.h"

void adduser(EventManager &manager);
void create(EventManager &manager);
void update(EventManager &manager);
void deleteEvent(EventManager &manager);
void display(EventManager &manager);
void search(EventManager &manager);
void addAttendee(EventManager &manager);
void removeAttendee(EventManager &manager);
void attendees(EventManager &manager);
void save(EventManager &manager);
void quit(EventManager &manager);
bool signUp(EventManager &manager);
void processInitialCommand(EventManager &manager, const int &command);
void logout(EventManager &manager);
void parseLoggedInCommand(EventManager &manager, const int &command);
void login(EventManager &manager);
int displaySlots();
int displayRooms();

void adduser(EventManager &manager)
{
    string username, password;
    bool admin;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    cout << "Admin (1 for yes, 0 for no): ";
    cin >> admin;
    manager.addUser(username, password, admin);
}

void create(EventManager &manager)
{
    // int id;
    string title, description, date;
    int slot, room;
    // cout << "ID: ";
    // cin >> id;
    // cin.ignore();
    cout << "Title: ";
    getline(cin, title);
    cout << "Description: ";
    getline(cin, description);
    cout << "Date (YYYY-MM-DD): ";
    getline(cin, date);

    // Validate date format
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        cout << "Invalid date format. Please enter date in YYYY-MM-DD format." << endl;
        return;
    }
    
    slot = displaySlots();
    room = displayRooms();
    manager.createEvent(title, description, date, slot, room);
}

void update(EventManager &manager)
{
    int id;
    string title, description, date;
    int slot, room;
    cout << "ID: ";
    cin >> id;
    Event *found_event = manager.searchEventByID(id);
    if (!found_event)
    {
        cout << "Event not found.\n"
             << endl;
        return;
    }
    cout << "Enter new details: " << endl;
    cout << "---------------------------------\n"
         << endl;
    cin.ignore();
    cout << "Title (" << found_event->title << "): ";
    getline(cin, title);
    cout << "Description: (" << found_event->description << "): ";
    getline(cin, description);
    cout << "Date: (" << found_event->date << "): ";
    getline(cin, date);
    cout << "Slot: (" << found_event->slot << "): ";
    cin >> slot;
    cout << "Room: (" << found_event->room << "): ";
    cin >> room;
    manager.updateEvent(id, title, description, date, slot, room);
}

int displaySlots()
{
    int slot;
    cout << "\nSelect a slot:" << endl;
    cout << "---------------------------------\n"
         << endl;
    cout << "1. 9:00 - 10:00" << endl;
    cout << "2. 10:00 - 11:00" << endl;
    cout << "3. 11:00 - 12:00" << endl;
    cout << "4. 12:00 - 13:00" << endl;
    cout << "5. 13:00 - 14:00" << endl;
    cout << "6. 14:00 - 15:00" << endl;
    cout << "7. 15:00 - 16:00" << endl;
    cout << "8. 16:00 - 17:00" << endl;
    cout << "9. 17:00 - 18:00" << endl;
    cout << "10. 18:00 - 19:00" << endl;
    cout << "11. 19:00 - 20:00" << endl;
    cout << "12. 20:00 - 21:00" << endl;
    cout << "13. 21:00 - 22:00" << endl;

    cout << "Enter your choice: ";
    cin >> slot;
    return slot;
}

int displayRooms()
{
    int room;
    cout << "\nSelect a room:" << endl;
    cout << "---------------------------------\n"
         << endl;
    cout << "1. Room 1" << endl;
    cout << "2. Room 2" << endl;
    cout << "3. Room 3" << endl;
    cout << "4. Room 4" << endl;
    cout << "5. Room 5" << endl;
    cout << "6. Room 6" << endl;
    cout << "7. Room 7" << endl;
    cout << "8. Room 8" << endl;
    cout << "9. Room 9" << endl;
    cout << "10. Room 10" << endl;

    cout << "Enter your choice: ";
    cin >> room;
    return room;
}

void deleteEvent(EventManager &manager)
{
    int id;
    cout << "ID: ";
    cin >> id;
    manager.deleteEvent(id);
}

void display(EventManager &manager)
{
    manager.displayEvents();
}

void search(EventManager &manager)
{
    int id;
    cout << "ID: ";
    cin >> id;
    manager.searchEventByID(id);
}

void addAttendee(EventManager &manager)
{
    int id, studentId;
    string attendee;
    cout << "Event ID: ";
    cin >> id;
    // TODO
    cin.ignore();
    cout << "Attendee Name: ";
    getline(cin, attendee);
    cout << "Student ID: ";
    cin >> studentId;
    manager.addAttendee(id, attendee, studentId);
}

void removeAttendee(EventManager &manager)
{
    int id, studentId;
    cout << "Event ID: ";
    cin >> id;
    cin.ignore();
    cout << "Attendee Id: ";
    cin >> studentId;
    manager.removeAttendee(id, studentId);
}

void attendees(EventManager &manager)
{
    int id;
    cout << "Event ID: ";
    cin >> id;
    manager.displayAttendees(id);
}

void save(EventManager &manager)
{
    manager.saveEvents();
}

void quit(EventManager &manager)
{
    cout << "Goodbye!\n";
    exit(0);
}

bool signUp(EventManager &manager)
{
    string username, password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    bool returnStatus = manager.addUser(username, password, 0);
    return returnStatus;
}

void displayInitialMenu()
{
    cout << "1. Signup" << endl;
    cout << "2. Login" << endl;
    cout << "0. Quit" << endl;
    cout << "Enter your choice: ";
}

void processInitialCommand(EventManager &manager, const int &command)
{
    if (command == 1)
    {
        signUp(manager);
    }
    else if (command == 2)
    {
        login(manager);
    }
    else if (command == 0)
    {
        quit(manager);
    }
}

void logout(EventManager &manager)
{
    manager.logout();
    // int command;
    // while (true)
    // {
    //     // cout << "Enter command (login, logout, adduser, create, update, delete, display, search, addattendee, removeattendee, attendees, save, quit): ";
    //     displayInitialMenu();
    //     cin >> command;
    //     cin.ignore();

    //     processInitialCommand(manager, command);
    // }
}

void displayLoggedInMenu(EventManager &manager)
{
    string username = manager.getCurrentUsername();
    cout << "\n---------------------------------\n"
         << endl;
    cout << "Welcome, " << username << "!" << endl;
    cout << "\n---------------------------------\n"
         << endl;
    cout << "3. Logout" << endl;
    cout << "4. Add User" << endl;
    cout << "5. Create Event" << endl;
    cout << "6. Update Event" << endl;
    cout << "7. Delete Event" << endl;
    cout << "8. Display Events" << endl;
    cout << "9. Search Event" << endl;
    cout << "10. Add Attendee" << endl;
    cout << "11. Remove Attendee" << endl;
    cout << "12. Display Attendees" << endl;
    cout << "13. Save to File" << endl;
    cout << "0. Quit" << endl;
    cout << "Enter your choice: ";
}

void parseLoggedInCommand(EventManager &manager, const int &command)
{
    if (command == 3)
    {
        logout(manager);
    }
    else if (command == 4)
    {
        adduser(manager);
    }
    else if (command == 5)
    {
        create(manager);
    }
    else if (command == 6)
    {
        update(manager);
    }
    else if (command == 7)
    {
        deleteEvent(manager);
    }
    else if (command == 8)
    {
        display(manager);
    }
    else if (command == 9)
    {
        search(manager);
    }
    else if (command == 10)
    {
        addAttendee(manager);
    }
    else if (command == 11)
    {
        removeAttendee(manager);
    }
    else if (command == 12)
    {
        attendees(manager);
    }
    else if (command == 13)
    {
        save(manager);
    }
    else if (command == 0)
    {
        quit(manager);
    }
}

void login(EventManager &manager)
{
    string username, password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    bool returnStatus = manager.login(username, password);
    while (returnStatus)
    {
        int command;
        while (true)
        {
            displayLoggedInMenu(manager);
            cin >> command;
            cin.ignore();
            parseLoggedInCommand(manager, command);
        }
    }
}

int main()
{
    EventManager manager;
    // manager.loadEvents();
    // manager.loadUsers();

    int command;
    while (true)
    {
        // cout << "Enter command (login, logout, adduser, create, update, delete, display, search, addattendee, removeattendee, attendees, save, quit): ";
        displayInitialMenu();
        cin >> command;
        cin.ignore();

        processInitialCommand(manager, command);
    }

    return 0;
}