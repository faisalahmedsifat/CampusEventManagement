
#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User
{
public:
    int userID;
    string username;
    string password;
    bool isAdmin;


    User(const int userId, const string &user, const string &pass, bool admin)
        : userID(userId), username(user), password(pass), isAdmin(admin) {}

    string getUsername() const { return username; }
};

#endif
