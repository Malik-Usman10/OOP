#include <iostream>

using namespace std;

class Person
{
private:
    int id;
    string name;
    string address;
    string gender;
    int no_of_accounts;
public:
    Person(): id(0), name(""), address(""), gender(""), no_of_accounts(0) {}
    Person(int id, string name, string address, string gender, int no_of_accounts) 
    : id(id++), name(name), address(address), gender(gender), no_of_accounts(no_of_accounts){}

    void setID(int ID)
    {
        id = ID;
    }
    int getID()
    {
        return id;
    }
    void setName(string Name)
    {
        name = Name;
    }
    string getName()
    {
        return name;
    }
    void setAddress(string Address)
    {
        address = Address;
    }
    string getAddress()
    {
        return address;
    }
    void setGender(string Gender)
    {
        gender = Gender;
    }
    string getGender()
    {
        return gender;
    }
    void setNoOfAccoutns(int noOfAccounts)
    {
        no_of_accounts = noOfAccounts;
    }
    int getNoOfAccounts()
    {
        return no_of_accounts;
    }



};

class Account
{
private:
    int account_number;
    int balance;
    Person person;
public:
    Account() :  account_number(0), balance(0),person(""){}
    Account(int account_number, int balance, Person& person) 
    : account_number(account_number), balance(balance),person(person){}

    void setAccountNumber(int accountNumber)
    {
        account_number = accountNumber;
    }
    int getAccountNumber()
    {
        return account_number;
    }
    void setBalance(int accBalance)
    {
        balance = accBalance;
    }
    int getBalance()
    {
        return balance;
    }

    int depositMoney(int amount)
    {
        balance += amount;
    }

    int withdrawMoney(int amount)
    {
        balance -= amount;
    }

    int getBalance()
    {
        cout << "The Balance in your account is " <<  balance << endl;
    }

};
class savingAccount : public Account
{
private:
    float interest_rate;
    int timeLimit;
public:
    savingAccount() : interest_rate(0.00), timeLimit(365) {}
    savingAccount(float interest_rate, int timeLimit) : interest_rate(interest_rate), timeLimit(timeLimit){}

    void setInterestRate(float interestRate)
    {
        interest_rate = interestRate;
    }
    float getInterestRate()
    {
        return interest_rate;
    }
    int getTimeLimit()
    {
        return timeLimit;
    }
    int withdrawMoney(int amount)
    {
        if (getBalance() => 500)
        {
            setBalance(getBalance() - amount)
            cout << "Money Withdraw Succesfully \n";
        }
        else
        {
            cout << "Minimum 500 Rupees is Required for Withdraw \n";
        }   
    }
    int calculateInterest()
    {
        setInterestRate(getBalance() + (10/100));
    }
};
class CheckingAccount: public Account
{
private: 
    int overdraft_limit;
public:
    CheckingAccount() : overdraft_limit(500){}
    CheckingAccount(int overdraft_limit): overdraft_limit(overdraft_limit){}

    int withdrawMoney(int amount)
    {
        if (overdraft_limit >= 500)
        {
            cout << "You can withdraw the money"
        }   
    }
};

class LoanAccount : public Account{
private:
    int interest-rate;
    int term;
public:
    LoanAccount() : interest_rate(0.00), term(1) {}
    LoanAccount(float interest_rate, int term) : interest_rate(interest_rate), term(term){}
    void setInterestRate(float interestRate)
    {
        interest_rate = interestRate;
    }
    float getInterestRate()
    {
        return interest_rate;
    }
    int getTerm()
    {
        return term;
    }

    int depositMoney()
    {
        if (loan)
        {
            /* code */
        }
        
    }


};
int main()
{

}