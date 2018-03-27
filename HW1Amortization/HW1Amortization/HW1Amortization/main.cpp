//
//  main.cpp
//  HW1Amortization
//
//  Created by Christian Vazquez on 5/22/17.
//  Copyright © 2017 Christian Vazquez. All rights reserved.
//

#include <iostream>
void computeAmortization(double principle, double principlePaid, double newPrinciple, double interestOwed, double monthlyInterest, double monthlyPayment, double interestRate) {
    
    double prin = 15000;
    double prinPaid;
    double newPrin;
    double intOwed;
    double monInt;
    double monPay = 300;
    double intRate = 0.12;
    
    while (prin > 0) {
        monInt = intRate/12;
        intOwed = prin * monInt;
        prinPaid = monPay - intOwed;
        printf("Principle: %0.2lf, Interest Paid: %0.2lf, Principle Paid: %0.2lf, Paid Today: %0.2lf, Balance: %0.2lf", prin, intOwed, prinPaid, monPay, newPrin);
        if (prinPaid > prin) {
            prinPaid = prin;
        }
        newPrin = prin - prinPaid;
        prin = newPrin;
        printf("\n");
    }
    
    
    
}

int main(int argc, const char * argv[]) {
    
    computeAmortization(15000, 0, 0, 0, 0, 300, 0.12);
    
    return 0;
}
