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
bool UserManager::checkIfLoginAlreadyExists(string login)
{
     for(int i=0; i < users.size(); i++)
    {
        if(login == users[i].getUserLogin())
        {
            cout << endl << "Podany login juz istnieje. Prosze wpisac inny login." << endl;
            return true;
        }
    }
    return false;
}
User UserManager::loadNewUserData()
{
    User newUser;
    string login, password, name, surname;
    do
    {
    cout << "Podaj swoj login: ";
    cin >> login;
    }while(checkIfLoginAlreadyExists(login) == true);
    cout << "Podaj haslo: ";
    cin >> password;
    cout << "Podaj swoje imie: ";
    cin >> name;
    cout << "Podaj swoje nazwisko: ";
    cin >> surname;
    newUser.setUserId(returnLastUserId());
    newUser.setUserLogin(login);
    newUser.setUserPassword(password);
    newUser.setUserName(name);
    newUser.setUserSurname(surname);
    return newUser;
}
void UserManager::registerNewUser()
{
    User newUser;
    newUser = loadNewUserData();
    users.push_back(newUser);
    cout << endl << "Konto zalozone pomyslnie" << endl << endl;
    Sleep(1500);
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
void UserManager::logUserIn()
{
    string login, password;
    cout << "Prosze podac login: ";
    cin >> login;
    for(vector <User>:: iterator i = users.begin(); i!=users.end(); i++)
    {
        if(login == i -> getUserLogin())
        {
            for(int check = 3; check > 0; check--)
            {
                cout << "Prosze podac haslo: ";
                cin >> password;
                if(password == i -> getUserPassword())
                {
                    cout << "Zalogowales sie.";
                    loggedUserId = i -> getUserId();
                    return;
                }
                else {
                  cout << "Bledne haslo. Zostaly Ci: " << check - 1 << " proby." << endl;
                  Sleep(1000);
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            loggedUserId = 0;
            return;
        }
    }
    cout << "Nie znaleziono uzytkownika o podanym loginie." << endl;
    system("pause");
    loggedUserId = 0;
}
void UserManager::logUserOut()
{
    loggedUserId = 0;
    cout << endl << "Wylogowales sie. ";
}
