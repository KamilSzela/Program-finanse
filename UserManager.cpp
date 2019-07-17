# include "UserManager.h"

bool UserManager::checkIfUserisLogged()
{
    if (loggedUserId == 0) return false;
    else return true;
}
int UserManager::returnLastUserId(){
    if(users.empty() == true) return 1;
    else return users.back().getUserId()+1;
}
void UserManager::registerNewUser()
{
    User newUser;
    newUser.setUserId(returnLastUserId());
    string login, password, name, surname;
    cout << "Podaj swoj login: ";
    cin >> login;
    cout << "Podaj haslo: ";
    cin >> password;
    cout << "Podaj swoje imie: ";
    cin >> name;
    cout << "Podaj swoje nazwisko: ";
    cin >> surname;
    newUser.setUserLogin(login);
    newUser.setUserPassword(password);
    newUser.setUserName(name);
    newUser.setUserSurname(surname);
    users.push_back(newUser);
    cout << endl << "Konto zalozone pomyslnie" << endl << endl;
}
void UserManager::showAllUsers()
{
   for (int i=0; i < users.size(); i++)
   {
       cout<<users[i].getUserId()<<endl;
       cout<<users[i].getUserName()<<endl;
       cout<<users[i].getUserSurname()<<endl;
       cout<<users[i].getUserLogin()<<endl;
       cout<<users[i].getUserPassword()<<endl;
   }
   system("pause");
}
