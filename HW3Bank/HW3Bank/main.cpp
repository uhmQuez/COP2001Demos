//
//  main.cpp
//  HW3Bank
//
//  Created by Christian Vazquez on 6/12/17.
//  Copyright © 2017 Christian Vazquez. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

class LoanData
{
//Private variables are declared strictly for use within the class
private:
    
    double  balRemaining;//Overall remaining balance for account
    double  n;//Number of years to pay off loan
    double	i;//Interest rate on the loan, written as a percent. (6%)
    double	A;//Monthly payment

//These functions are made public for use throughout the whole program
//That means within the class, and also the main function
public:
    
    //Function to calculate and display the loan data.
    LoanData(double p, double n, double interest)
    {
        i = ((interest/100)/12);//Calculates interest rate per month.
        n = n*12;//Calculate number of months to pay off the loan.
        A = ((p*(i*(pow(1+i, n))))/(pow(1+i, n)-1));
        balRemaining = p;
        cout << "The current remaining balance is: " << balRemaining << endl;
        cout << "This is your current interest rate: " << i << endl;
        cout << "This is your minimum monthly payment: " << A << endl;
    }
    
    //Function to make a payment. Receives payment amount from main function
    void MakePayment(double pay)
    {
        balRemaining = (i+1)*balRemaining - pay;
        cout << "You paid " << pay << " this month." << endl;
        cout << "Here is your remaining balance " << balRemaining << endl;
    }
    
    //Function to print out full payment schedule after first month
    void PrintAmortizationSchedule()
    {
        //Declaring these four variables inside of the function
        //being that they're mainly acting as placeholders when its
        //time to print out the amortization schedule.
        double nPrin;
        double iOwed;
        double pPaid;
        
        cout << "| Balance | Payment | Principle Paid | Interest Paid | New Balance |\n";
        
        //This loop will run till the remaining balance reaches 0
        while (balRemaining > 0)
        {
            iOwed = balRemaining * i;
            pPaid = A - iOwed;
            if (pPaid > balRemaining)
            {
                pPaid = balRemaining;
            }
            nPrin = balRemaining - pPaid;
            printf("  %0.2lf\t   %0.2lf\t   %0.2lf\t   %0.2lf\t   %0.2lf\t", balRemaining, A, pPaid, iOwed, nPrin);
            balRemaining = nPrin;
            //New line for better readability
            cout << "\n" << endl;
        }
    }
    
    //Used to create a report of the monthly payoff months from 1 to 50.
    void PrintPayOffTimeReport(double p, double i)
    {
        i = i / (100*12);
        for (n = 1; n <50; n++)
        {
            A = ((p*(i*(pow(1+i, n))))/(pow(1+i, n)-1));
            cout << "Number: " << n << " Amount: " << A << endl;
        }
    }
};

int main(int argc, const char * argv[])
{
    double prin;
    double monPay;
    double intRate;
    double numYears;
    
    
    cout << "Enter in the loan amount: \n" << endl;
    scanf("%lf" , &prin);
    
    cout << "Enter in the number of years you have to pay off the debt: \n" << endl;
    scanf("%lf", &numYears);
    
    cout << "Enter in the interest rate as a percent, like 6 for 6%. \n" << endl;
    scanf("%lf", &intRate);
    
    LoanData Christian = *new LoanData(prin, numYears, intRate);
                                      
    cout << "Let's make our payments. Please enter the amount you would like to pay monthly: \n" << endl;
    scanf("%lf", &monPay);
    
    Christian.MakePayment(monPay);
    
    Christian.PrintAmortizationSchedule();
    
    Christian.PrintPayOffTimeReport(prin, intRate);
    
    return 0;
}
