#ifndef MONEY_H
#define MONEY_H
#include <iostream>

using namespace std;

class Money
{
    int moneyId, userId, amount;
    int  date;
    string item;
public:

 bool operator< (const Money &other) const {
        return date < other.date;
    }
    int getMoneyId();
    void setMoneyId(int newMoneyId);
    int getUserId();
    void setUserId(int newUserId);
    int getDate();
    void setDate(int newDate);
    string getItem();
    void setItem(string newItem);
    int getAmount();
    void setAmount(int newAmount);
};

#endif
