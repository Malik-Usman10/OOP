#include <iostream>
using namespace std;

class VicobaAccount {
private:
    double loanAmount;
    int loanDuration;
    static double annualInterestRate;

public:
    VicobaAccount(double loanAmount, int duration) : loanAmount(loanAmount), loanDuration(duration) {}

    void setLoanAmount(double loanAmount) 
    {
        loanAmount = loanAmount;
    }

    double getLoanAmount() const 
    {
        return loanAmount;
    }

    void setLoanDuration(int duration) 
    {
        loanDuration = duration;
    }

    int getLoanDuration() const 
    {
        return loanDuration;
    }

    static void setAnnualInterestRate(double interestRate) 
    {
        annualInterestRate = interestRate;
    }

    static double getAnnualInterestRate() 
    {
        return annualInterestRate;
    }
    double calculateTotalRepaymentAmount() const 
    {
        double interest = (loanAmount * annualInterestRate * loanDuration) / 100.0;
        return loanAmount + interest;
    }
};

double VicobaAccount::annualInterestRate = 0.0;

int main() 
{
    double loanAmount, interestRate;
    int loanDuration;

    cout << "Enter the loan Amount: ";
    cin >> loanAmount;

    cout << "Enter the loan duration in loanDuration: ";
    cin >> loanDuration;

    cout << "Enter the interest Rate: ";
    cin >> interestRate;

    VicobaAccount::setAnnualInterestRate(interestRate);

    VicobaAccount customerAccount(loanAmount, loanDuration);

    cout << "The total Amount to repay is: " 
              << customerAccount.calculateTotalRepaymentAmount() << endl;

}
