#include "Money.h"

    int Money::getMoneyId()
    {
        return moneyId;
    }
    void Money::setMoneyId(int newMoneyId)
    {
        moneyId = newMoneyId;
    }
    int Money::getUserId()
    {
        return userId;
    }
    void Money::setUserId(int newUserId)
    {
        userId = newUserId;
    }
    int Money::getDate()
    {
        return date;
    }
    void Money::setDate(int newDate)
    {
        date = newDate;
    }
    string Money::getItem()
    {
        return item;
    }
    void Money::setItem(string newItem)
    {
        item = newItem;
    }
    float Money::getAmount()
    {
        return amount;
    }
    void Money::setAmount(float newAmount)
    {
        amount = newAmount;
    }
