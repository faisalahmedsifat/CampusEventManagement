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
void logged_in_menu(EventManager &manager);
void home_view(EventManager &manager);

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
    string title, description, date, starttime, endtime;
    int room;

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
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    {
        cout << "Invalid date format. Please enter date in YYYY-MM-DD format." << endl;
        return;
    }

    cout << "Start time: ";
    getline(cin, starttime);
    cout << "End time: ";
    getline(cin, endtime);
    room = displayRooms();
    manager.createEvent(title, description, date, starttime, endtime, room);
}

void update(EventManager &manager)
{
    int id;
    string title, description, date, starttime, endtime;
    int room;
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
    cout << "Start time: (" << found_event->startTime << "): ";
    getline(cin, starttime);
    cout << "End time: (" << found_event->endTime << "): ";
    getline(cin, endtime);
    cout << "Room: (" << found_event->room << "): ";
    cin >> room;
    manager.updateEvent(id, title, description, date, starttime, endtime, room);
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

void searchEventById(EventManager &manager)
{
    int id;
    cout << "Enter ID: ";
    cin >> id;
    manager.searchEventByID(id);
}

void addAttendee(EventManager &manager)
{
    int id;
    string attendee, studentId;
    cout << "Event ID: ";
    cin >> id;
    // TODO
    cin.ignore();
    cout << "Attendee Name: ";
    getline(cin, attendee);
    cout << "Student ID: ";
    getline(cin, studentId);
    manager.addAttendee(id, attendee, studentId);
}

void removeAttendee(EventManager &manager)
{
    int id;
    string studentId;
    cout << "Event ID: ";
    cin >> id;
    cin.ignore();
    cout << "Attendee Id: ";
    getline(cin, studentId);
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
    cout << "0. Exit" << endl;
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
void displayLoggedInMenu(EventManager &manager)
{
    string username = manager.getCurrentUsername();
    cout << "\n---------------------------------\n"
         << endl;
    cout << "Welcome, " << username << "!" << endl;
    cout << "\n---------------------------------\n"
         << endl;
    
    cout << "1. Create Event" << endl;
    cout << "2. Update Event" << endl;
    cout << "3. Delete Event" << endl;
    cout << "4. Display Events" << endl;
    cout << "5. Search Event" << endl;
    cout << "6. Add Attendee" << endl;
    cout << "7. Remove Attendee" << endl;
    cout << "8. Display Attendees" << endl;
    cout << "9. Save to File" << endl;
    cout << "10. Logout" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

void displaySearchMenu(EventManager &manager)
{
    cout << "\n---------------------------------\n"
         << endl;
    cout << "1. Search by ID" << endl;
    cout << "2. Search by Title" << endl;
    cout << "3. Search by Date" << endl;
    cout << "0. Go Back" << endl;
    cout << "Enter your choice: ";
}

void searchByTitle(EventManager &manager)
{
    string title;
    cout << "Enter title: ";
    cin.ignore();
    getline(cin, title);
    manager.searchEventsByTitle(title);
}

void searchByDate(EventManager &manager)
{
    string date;
    cout << "Enter date (YYYY-MM-DD): ";
    // cin.ignore();
    getline(cin, date);
    manager.searchEventsByDate(date);
}

void search(EventManager &manager)
{
    int command;
    while (true)
    {
        displaySearchMenu(manager);
        cin >> command;
        cin.ignore();
        if (command == 1)
        {
            searchEventById(manager);
        }
        else if (command == 2)
        {
            searchByTitle(manager);
        }
        else if (command == 3)
        {
            searchByDate(manager);
        }
        else if (command == 0)
        {
            break;
        }
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
    if (returnStatus)
    {
        logged_in_menu(manager);
    }
    else
    {
        cout << "Invalid username or password.\n"
             << endl;
    }
}

void logged_in_menu(EventManager &manager)
{
    int command;
    while (true)
    {
        displayLoggedInMenu(manager);
        cin >> command;
        cin.ignore();
        // loggedInCommand(manager, command);
        if (command == 1)
        {
            create(manager);
        }
        else if (command == 2)
        {
            update(manager);
        }
        else if (command == 3)
        {
            deleteEvent(manager);
        }
        else if (command == 4)
        {
            display(manager);
        }
        else if (command == 5)
        {
            search(manager);
        }
        else if (command == 6)
        {
            addAttendee(manager);
        }
        else if (command == 7)
        {
            removeAttendee(manager);
        }
        else if (command == 8)
        {
            attendees(manager);
        }
        else if (command == 9)
        {
            save(manager);
        }
        else if (command == 10){
            manager.logout();
            break;
        }
        else if (command == 0)
        {
            quit(manager);
        }
    }
}

void home_view(EventManager &manager)
{
    int command;
    while (true)
    {
        displayInitialMenu();
        cin >> command;
        cin.ignore();
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
            break;
        }
    }
}

int main()
{
    EventManager manager;
    // manager.loadEvents();
    // manager.loadUsers();

    // int command;
    // while (true)
    // {
    //     // cout << "Enter command (login, logout, adduser, create, update, delete, display, search, addattendee, removeattendee, attendees, save, quit): ";
    //     displayInitialMenu();
    //     cin >> command;
    //     cin.ignore();

    //     processInitialCommand(manager, command);

    //     home_view();
    // }
    home_view(manager);

    return 0;
}
