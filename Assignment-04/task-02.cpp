#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<cctype>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date()
    {
        day = 0;
        month = 0;
        year = 0;
    }
    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    void display()
    {
        cout << day << "/" << month << "/" << year << endl;
    }
    void setDay(int day)
    {
        this->day = day;
    }
    void setMonth(int month)
    {
        this->month = month;
    }
    void setYear(int year)
    {
        this->year = year;
    }
    int getDay()
    {
        return day;
    }
    int getMonth()
    {
        return month;
    }
    int getYear()
    {
        return year;
    }
};
class Address
{
private:
    string street;
    string city;
    string state;
    string country;
    string zip;
public:
    Address()
    {
        street = "";
        city = "";
        state = "";
        country = "";
        zip = "";
    }
    Address(string street, string city, string state, string country, string zip)
    {
        this->street = street;
        this->city = city;
        this->state = state;
        this->country = country;
        this->zip = zip;
    }
    void display()
    {
        cout << street << ", " << city << ", " << state << ", " << country << ", " << zip << endl;
    }
    void setStreet(string street)
    {
        this->street = street;
    }
    void setCity(string city)
    {
        this->city = city;
    }
    void setState(string state)
    {
        this->state = state;
    }
    void setCountry(string country)
    {
        this->country = country;
    }
    void setZip(string zip)
    {
        this->zip = zip;
    }
    string getStreet()
    {
        return street;
    }
    string getCity()
    {
        return city;
    }
    string getState()
    {
        return state;
    }
    string getCountry()
    {
        return country;
    }
    string getZip()
    {
        return zip;
    }
};
class Person
{
private:
    static int nextID;
    string ID;
    string firstName;
    string lastName;
    string CNIC;
    string Father;
    string Mother;
    Address address;
    Date dataOfBirth;

public:
    Person()
    {
        ID = firstName + to_string(nextID);
        nextID++;
        firstName = "";
        lastName = "";
        CNIC = "";
        address = Address();
        dataOfBirth = Date();
        Father = "";
        Mother = "";
    }
    Person(string firstName, string lastName, string CNIC, string Father, string Mother, Address address, Date dataOfBirth)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->CNIC = CNIC;
        this->Father = Father;
        this->Mother = Mother;
        this->address = address;
        this->dataOfBirth = dataOfBirth;
        this->ID = firstName + lastName + to_string(nextID);
        nextID++;
    }
    ~Person(){}
    void display()
    {
        cout << "ID: " << ID << endl;
        cout << "First Name: " << firstName << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "CNIC: " << CNIC << endl;
        cout << "Address: " << endl;
        address.display();
        cout << "Date of Birth: " << endl;
        dataOfBirth.display();
        cout << "Father: " << Father << endl;
        cout << "Mother: " << Mother << endl;
    }
    void setFirstName(string firstName)
    {
        this->firstName = firstName;
    }
    void setLastName(string lastName)
    {
        this->lastName = lastName;
    }
    void setCNIC(string CNIC)
    {
        this->CNIC = CNIC;
    }
    void setAddress(Address address)
    {
        this->address = address;
    }
    void setDataOfBirth(Date dataOfBirth)
    {
        this->dataOfBirth = dataOfBirth;
    }
    void setFather(string Father)
    {
        this->Father = Father;
    }
    void setMother(string Mother)
    {
        this->Mother = Mother;
    }
    string getID()
    {
        return ID;
    }
    string getFirstName()
    {
        return firstName;
    }
    string getLastName()
    {
        return lastName;
    }
    string getCNIC()
    {
        return CNIC;
    }
    Address getAddress()
    {
        return address;
    }
    Date getDataOfBirth()
    {
        return dataOfBirth;
    }
    string getFather()
    {
        return Father;
    }
    string getMother()
    {
        return Mother;
    }
};
int Person::nextID = 1;


class Transaction
{
private:
    static int nextID;
    string transactionID;
    string senderID;
    string receiverID;
    string senderName;
    string receiverName;
    double amountTransferred;
    Date date;
public:
    Transaction()
    {
        senderName = "";
        receiverName = "";
        transactionID = "transaction" + to_string(nextID);
        senderID = senderName + to_string(nextID);
        receiverID = receiverName + to_string(nextID);
        nextID++;
        amountTransferred = 0;
        date = Date();
    }
    Transaction(string senderID, string receiverID, double amountTransferred, Date date)
    {
        this->transactionID = "transaction" + to_string(nextID);
        this->senderName = senderName;
        this->receiverName = receiverName;
        this->senderID = senderName + to_string(nextID);
        this->receiverID = receiverName + to_string(nextID);
        this->amountTransferred = amountTransferred;
        this->date = date;
    }
    ~Transaction(){}
    void display()
    {
        cout << "Transaction ID: " << transactionID << endl;
        cout << "Sender ID: " << senderID << endl;
        cout << "Receiver ID: " << receiverID << endl;
        cout << "Sender Name: " << senderName << endl;
        cout << "Receiver Name: " << receiverName << endl;
        cout << "Amount Transferred: " << amountTransferred << endl;
        cout << "Date: " << endl;
        date.display();
    }
    void setSenderName(string senderName)
    {
        this->senderName = senderName;
    }
    void setReceiverName(string receiverName)
    {
        this->receiverName = receiverName;
    }
    void setAmountTransferred(double amountTransferred)
    {
        this->amountTransferred = amountTransferred;
    }
    void setDate(Date date)
    {
        this->date = date;
    }
    string getTransactionID()
    {
        return transactionID;
    }
    string getSenderID()
    {
        return senderID;
    }
    string getReceiverID()
    {
        return receiverID;
    }
    string getSenderName()
    {
        return senderName;
    }
    string getReceiverName()
    {
        return receiverName;
    }
    double getAmountTransferred()
    {
        return amountTransferred;
    }
    Date getDate()
    {
        return date;
    }
};
int Transaction::nextID = 1;


class Account
{
private:
    static int nextID;
    string accountNumber;
    string accountType;
    char balanceArray[50] = {0};
    Person accountHolder;
    vector<Transaction> transactions;
public:
    Account()
    {
        accountNumber = accountHolder.getFirstName() + accountHolder.getLastName() + to_string(nextID);
        nextID++;
        accountType = "";
        balanceArray[0] = '0';
        accountHolder = Person();
        transactions = vector<Transaction>();
    }
    Account(string accType, Person accHolder)
    {
        this->accountType = accType;
        this->accountHolder = accHolder;
        this->accountNumber = accountHolder.getFirstName() + accountHolder.getLastName() + to_string(nextID);
        nextID++;

    }
    ~Account(){}
    void saveBalanceInArray(int balance)
    {
        for (int i = 49 ; i >= 0; i--) 
        {
            int digit = i % 10;
            balanceArray[i] = digit + '0';
            balance /= 10;
        }
    }
    int availableBalance()
    {
        int availableBalance = 0;
        for (int i = 0; i < 50; i++) 
        {
            int digit = balanceArray[i] - '0';
            availableBalance = availableBalance * 10 + digit;
        }
        return availableBalance;
    }
    void checkBalance()
    {
        for (int i = 0; i < 50; i++) 
        {
            cout << "Balance: " << balanceArray[i] << " ";
        }
    }
    void transactionHistory()
    {
        for (int i = 0; i < transactions.size(); i++)
        {
            transactions[i].display();
        }
    }
    virtual void display()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Account Holder: " << endl;
        accountHolder.display();
    }
    virtual void deposit(int amount)
    {
        saveBalanceInArray(amount);
    }
    virtual void withdraw(int amount)
    {
        if (amount > availableBalance())
        {
            cout << "Your Balance is Low " << endl;
        }
        else
        {
            saveBalanceInArray(-amount);
        }        
    }
    virtual void transfer(int amount, Account& recipient)
    {
        if (amount > availableBalance())
        {
            cout << "Your Balance is Low " << endl;
        }
        else
        {
            saveBalanceInArray(-amount);
            recipient.deposit(amount);
        }
    }
    string getAccountNumber()
    {
        return accountNumber;
    }
    Person getAccountHolder()
    {
        return accountHolder;
    }
    string getAccountType()
    {
        return accountType;
    }
};
int Account::nextID = 1;

class BusinessAccount : public Account
{
private:
    int negativeBalance;
public:
    BusinessAccount()
    {
        negativeBalance = 0;
    }
    BusinessAccount(string accountType, Person accountHolder)
    : Account(accountType, accountHolder) 
    {
        cout << "============================================" << endl;
        cout << "Business Account Created Successfully" << endl;
        cout << "============================================" << endl;
    }
    ~BusinessAccount(){}
    void display()
    {
        cout << "Account Number: " << getAccountNumber() << endl;
        cout << "Account Type: " << getAccountType() << endl;
        cout << "Account Holder: " << endl;
        getAccountHolder().display();
    }
    void deposit(int amount)
    {
        cout << "Depositing: " << amount << endl;
    }
    void withdraw(int amount)
    {
        if (amount > 0)
        {
            cout << "Withdrawing: " << amount << endl;
        }
        else
        {
            cout << "You can't withdraw negative amount" << endl;
        }
    }
    void transfer(int amount, Account& recipient)
    {
        cout << "Transferring: " << amount << " to " << recipient.getAccountNumber() << endl;
    }
};

class StudentAccount : public Account
{
private:
    int depositLimit;
    int withdrawalLimit;
    int transferLimit;
    int withdrawalCharge;
    int transferCharge;
    int numOfTransactionCanMade;
public:
    StudentAccount()
    {
        depositLimit = 0;
        withdrawalLimit = 0;
        transferLimit = 0;
        withdrawalCharge = 0;
        transferCharge = 0;
        numOfTransactionCanMade = 0;
    }
    StudentAccount(string accountType, Person accountHolder) 
    : Account(accountType, accountHolder)
    {
        this->depositLimit = 50000;
        this->withdrawalLimit = 40000;
        this->transferLimit = 20000;
        this->withdrawalCharge = 25;
        this->transferCharge = 5;
        this->numOfTransactionCanMade = 10;
        cout << "============================================" << endl;
        cout << "Student Account Created Successfully" << endl;
        cout << "============================================" << endl;
    }
    ~StudentAccount(){}
    void display()
    {
        cout << "Account Number: " << getAccountNumber() << endl;
        cout << "Account Type: " << getAccountType() << endl;
        cout << "Account Holder: " << endl;
        getAccountHolder().display();
    }
    void withdraw(int amount)
    {
        cout << "Withdrawing: " << amount << endl;
    }
    void deposit(int amount)
    {
        cout << "Depositing: " << amount << endl;
    }
    void transfer(int amount, Account& recipient)
    {
        cout << "Transferring: " << amount << " to " << recipient.getAccountNumber() << endl;
    }


};

class SavingAccount : public Account
{
private:
    int timePeriod;
    int interestRate;
    Date packageStartDate;
public:
    SavingAccount()
    {
        timePeriod = 365;
        interestRate = 10;
        packageStartDate = Date();
    }
    SavingAccount(string accountType, Person accountHolder, Date packageStartDate) : Account(accountType, accountHolder)
    {
        this->timePeriod = 365;
        this->interestRate = 10;
        this->packageStartDate = packageStartDate;
        cout << "============================================" << endl;
        cout << "Saving Account Created Successfully" << endl;
        cout << "============================================" << endl;
    }
    ~SavingAccount(){}
    void display()
    {
        cout << "Account Number: " << getAccountNumber() << endl;
        cout << "Account Type: " << getAccountType() << endl;
        cout << "Account Holder: " << endl;
        getAccountHolder().display();
    }
    void withdraw(int amount)
    {
        cout << "Withdrawing: " << amount << endl;
    }
    void deposit(int amount)
    {
        cout << "Depositing: " << amount << endl;
    }
    void transfer(int amount, Account& recipient)
    {
        cout << "Transferring: " << amount << " to " << recipient.getAccountNumber() << endl;
    }
};

class CreditAccount : public Account
{
private:
    int withdrawalCharge;
    int transferCharge;
    int depositLimit;
    int withdrawalLimit;
    int transferLimit;
public:
    CreditAccount()
    {
        withdrawalCharge = 0;
        transferCharge = 0;
        depositLimit = 0;
        withdrawalLimit = 0;
        transferLimit = 0;
    }
    CreditAccount(string accountType, Person accountHolder) 
    : Account(accountType, accountHolder)
    {
        cout << "============================================" << endl;
        cout << "Credit Account Created Successfully" << endl;
        cout << "============================================" << endl;
    }
    ~CreditAccount(){}
    void display()
    {
        cout << "Account Number: " << getAccountNumber() << endl;
        cout << "Account Type: " << getAccountType() << endl;
        cout << "Account Holder: " << endl;
        getAccountHolder().display();
    }
};

class LoanAccount : public Account
{
private:
    int interestRate;
    int totalLoan;
    int timePeriod;
    int chargeRate;
public:
    LoanAccount()
    {
        interestRate = 0;
        totalLoan = 0;
        timePeriod = 0;
        chargeRate = 0;
    }
    LoanAccount(string accountType, Person accountHolder) 
    : Account(accountType, accountHolder)
    {
        this->interestRate = interestRate;
        this->totalLoan = totalLoan;
        this->timePeriod = timePeriod;
        this->chargeRate = chargeRate;
    }
    ~LoanAccount(){}
    void display()
    {
        cout << "Account Number: " << getAccountNumber() << endl;
        cout << "Account Type: " << getAccountType() << endl;
        cout << "Account Holder: " << endl;
        getAccountHolder().display();
    }
    void withdraw(int amount)
    {
        cout << "Withdrawing: " << amount << endl;
    }
    void deposit(int amount)
    {
        cout << "Depositing: " << amount << endl;
    }
    void transfer(int amount, Account& recipient)
    {
        cout << "Transferring: " << amount << " to " << recipient.getAccountNumber() << endl;
    }
};

class specialCitizenAccount : public Account
{
private:
    string supporter;
    int fixedAmount;
public:
    specialCitizenAccount()
    {
        supporter = "";
        fixedAmount = 0;
    }
    specialCitizenAccount(string accountType, Person accountHolder, string supporter) 
    : Account(accountType, accountHolder)
    {
        this->supporter = supporter;
        this->fixedAmount = 30000;
        cout << "============================================" << endl;
        cout << "Special Citizen Account Created Successfully" << endl;
        cout << "============================================" << endl;
    }
    ~specialCitizenAccount(){}
    void display()
    {
        cout << "Account Number: " << getAccountNumber() << endl;
        cout << "Account Type: " << getAccountType() << endl;
        cout << "Account Holder: " << endl;
        getAccountHolder().display();
    }
    void withdraw(int amount)
    {
        cout << "Withdrawing: " << amount << endl;
    }
    void deposit(int amount)
    {
        cout << "Depositing: " << amount << endl;
    }
    void transfer(int amount, Account& recipient)
    {
        cout << "Transferring: " << amount << " to " << recipient.getAccountNumber() << endl;
    }
};
class Bank 
{
private:
    string bankName;
    int numberOfAccounts;
    int totalBalance;
    int totalInterestToPay;
    int totalProfit;
    vector<Account *> accounts;
    vector<Transaction> transactions;
public:
    Bank()
    {
        bankName = "";
        numberOfAccounts = 0;
        totalBalance = 0;
        totalInterestToPay = 0;
        totalProfit = 0;
    }
    Bank(string bankName, int numberOfAccounts, int totalBalance, int totalInterestToPay, int totalProfit, vector<Account *> accounts, vector<Transaction> transactions)
    {
        this->bankName = bankName;
        this->numberOfAccounts = numberOfAccounts;
        this->totalBalance = totalBalance;
        this->totalInterestToPay = totalInterestToPay;
        this->totalProfit = totalProfit;
        this->accounts = accounts;
        this->transactions = transactions;
    }
    ~Bank(){}
    void addAccount(Account *account)
    {

        accounts.push_back(account);
        cout << "===================================================" << endl;
        account->display();
        cout << "===================================================" << endl;
    }
    void displayAllAccounts()
    {
        for (int i = 0; i < accounts.size(); i++)
        {
            cout << "==================================================" << endl;
            accounts[i]->display();
            cout << "==================================================" << endl;
        }
    }
    void searchSpecificAccount(string accountNumber)
    {
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i]->getAccountNumber() == accountNumber)
            {
                cout << "============================================" << endl;
                accounts[i]->display();
                cout << "============================================" << endl;
            }
            else
            {
                cout << "Account not found!" << endl;
            }
        }
    }
    void searchAllAccountsByCNIC(string CNIC)
    {
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i]->getAccountHolder().getCNIC() == CNIC)
            {
                cout << "============================================" << endl;
                accounts[i]->display();
                cout << "============================================" << endl;
            }
        }
        cout << "Account not found!" << endl;
    }

    void seeAccountTransactionHistory(string accountNumber)
    {
        for (int i = 0; i < transactions.size(); i++)
        {
            if (transactions[i].getSenderID() == accountNumber || transactions[i].getReceiverID() == accountNumber)
            {
                cout << "============================================" << endl;
                transactions[i].display();
                cout << "============================================" << endl;
            }
        }
        cout << "No Transaction History found!" << endl;
    }

    void depositMoney(string receiverAccountNumber, string senderAccountNumber, double amount, Date date)
    {
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i]->getAccountNumber() == receiverAccountNumber)
            {
                accounts[i]->deposit(amount);
                Transaction t(senderAccountNumber, receiverAccountNumber, amount, date);
                transactions.push_back(t);
                cout << "Money Deposit Successfully" << endl;
            }
        }
    }

    void withdrawMoney(string accountNumber, double amount)
    {
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i]->getAccountNumber() == accountNumber)
            {
                accounts[i]->withdraw(amount);
            }
        }
    }
    void transferMoney(string senderAccountNumber, string receiverAccountNumber, double amount)
    {
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i]->getAccountNumber() == senderAccountNumber)
            {
                accounts[i]->transfer(amount, *accounts[i]);
            }
        }
    }
    void rollBackTransaction(string transactionID)
    {
        for (int i = 0; i < transactions.size(); i++)
        {
            if (transactions[i].getTransactionID() == transactionID)
            {
                transactions.erase(transactions.begin() + i);
            }
        }
    }
};
int main()
{
    Bank bank;
    int choice;
    string accountType, accountNumber, firstName, lastName, CNIC, Father, Mother, street, city, state, country, zip;
    int day, month, year;
    while (true)
    {
        cout << "============= Welcome to Solstice Bank ===================== \n";
        cout << "1: Add New Bank Account: \n";
        cout << "2: Display All Accounts: \n";
        cout << "3: Search Specific Account: \n";
        cout << "4: Search All Accounts By CNIC: \n";
        cout << "5: See Account Transaction History: \n";
        cout << "6: Deposit Money: \n";
        cout << "7: Withdraw Money: \n";
        cout << "8: Transfer Money: \n";
        cout << "9: Roll Back Transaction: \n";
        cout << "10: Exit: \n";
        cin >> choice;
        switch (choice)
        {
            case 1:
            {   
                cout << "Enter the account type: ";
                cin >> accountType;
                cout << "Enter the First Name, Last Name, CNIC, Father Name, Mother Name: ";
                cin >> firstName >> lastName >> CNIC >> Father >> Mother;
                cout << "Enter the Address: [Street, City, State, Country, Zip]: ";
                cin >> street >> city >> state >> country >> zip;
                cout << "Enter the Date of Birth: [Day, Month, Year]: ";
                cin >> day >> month >> year;

                if (accountType == "Student" || accountType == "student")
                {
                    bank.addAccount(new StudentAccount(accountType, Person(firstName, lastName, CNIC, Father, Mother, Address(street, city, state, country, zip), Date(day, month, year))));
                }
                else if (accountType == "Business" || accountType == "business")
                {
                    bank.addAccount(new BusinessAccount(accountType, Person(firstName, lastName, CNIC, Father, Mother, Address(street, city, state, country, zip), Date(day, month, year))));
                }
                else if (accountType == "Saving" || accountType == "saving")
                {
                    int d,m,y;
                    cout << "Enter the Start Date of Package: [Day, Month, Year]: ";
                    cin >> d >> m >> y;
                    bank.addAccount(new SavingAccount(accountType, Person(firstName, lastName, CNIC, Father, Mother, Address(street, city, state, country, zip), Date(day, month, year)), Date(d, m, y)));
                }
                else if (accountType == "Credit" || accountType == "credit")
                {
                    bank.addAccount(new CreditAccount(accountType, Person(firstName, lastName, CNIC, Father, Mother, Address(street, city, state, country, zip), Date(day, month, year))));
                }
                else if (accountType == "Loan" || accountType == "loan")
                {
                    bank.addAccount(new LoanAccount(accountType, Person(firstName, lastName, CNIC, Father, Mother, Address(street, city, state, country, zip), Date(day, month, year))));
                }
                else if (accountType == "Special Citizen" || accountType == "special citizen")
                {
                    string organization;
                    cout << "Enter the Organization: ";
                    cin >> organization;
                    bank.addAccount(new specialCitizenAccount(accountType, Person(firstName, lastName, CNIC, Father, Mother, Address(street, city, state, country, zip), Date(day, month, year)), organization));
                }
                break;
            }
            case 2:
            {
                bank.displayAllAccounts();
                break;
            }
            case 3:
            {
                string accountNumber;
                cout << "Enter the Account Number: ";
                cin >> accountNumber;
                bank.searchSpecificAccount(accountNumber);
                break;
            }
            case 4:
            {   
                string accountNumber;
                cout << "Enter the Account Number: ";
                cin >> accountNumber;
                bank.searchAllAccountsByCNIC(accountNumber);
                break;
            }
            case 5:
            {
                string accountNumber;
                cout << "Enter the Account Number: ";
                cin >> accountNumber;
                bank.seeAccountTransactionHistory(accountNumber);
                break;
            }
            case 6:
            {
                string receiverAccountNumber, senderAccountNumber;
                double amount;
                int day, month, year;
                cout << "Enter the Date: [Day, Month, Year]: ";
                cin >> day >> month >> year;
                cout << "Enter the Receiver Account Number: ";
                cin >> receiverAccountNumber;
                cout << "Enter the Sender Account Number: ";
                cin >> senderAccountNumber;
                cout << "Enter the Amount: ";
                cin >> amount;
                bank.depositMoney(receiverAccountNumber, senderAccountNumber, amount, Date(day, month, year));
                break;
            }
            case 7:
            {
                string accountNumber;
                double amount;
                cout << "Enter the Account Number: ";
                cin >> accountNumber;
                cout << "Enter the Amount to Withdraw: ";
                bank.withdrawMoney(accountNumber, amount);
                break;
            }
            case 8:
            {
                string receiverAccountNumber, senderAccountNumber;
                double amount;
                cout << "Enter the Receiver Account Number: ";
                cin >> receiverAccountNumber;
                cout << "Enter the Sender Account Number: ";
                cin >> senderAccountNumber;
                cout << "Enter the Amount: ";
                cin >> amount;
                bank.transferMoney(receiverAccountNumber, senderAccountNumber, amount);
                break;
            }
            case 9:
            {
                string transactionID;
                cout << "Enter the Transaction ID to Rollback: ";
                cin >> transactionID;
                bank.rollBackTransaction(transactionID);
                break;
            }
            case 10:
            {
                return 0;
                break;
            }
            default:
            {
                cout << "Invalid Choice";
                break;
            }
        }
    }
    
    
}
