//
//  main.cpp
//  VirtualDay2
//
//  Created by Christian Vazquez on 5/24/17.
//  Copyright © 2017 Christian Vazquez. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    double principle = 15000;
    double principlePaid;
    double newPrinciple;
    double interestOwed;
    double monthlyInterest;
    double monthlyPayment = 300;
    double interestRate = 0.12;
    
    
    monthlyInterest = interestRate/12;
    interestOwed = principle * monthlyInterest;
    principlePaid = monthlyPayment - interestOwed;
    printf("This month, you paid %.02lf towards the principle, and %.02lf towards interest.\n", principlePaid, interestOwed);
    if (principlePaid > principle) {
        principlePaid = principle;
    }
    newPrinciple = principle - principlePaid;
    printf("After the this month of payment, you owe %.02lf towards the principle.\n", newPrinciple);
    principle = newPrinciple;
    
    return 0;
}
