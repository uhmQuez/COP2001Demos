//
//  main.cpp
//  PracticeCode
//
//  Created by Christian Vazquez on 5/15/17.
//  Copyright © 2017 Christian Vazquez. All rights reserved.
//

#include <iostream>
#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int scoreEarned = 0;
    
    std::cout << "Please enter your grade.\n";
        //prompt user for score on test.
    
    scanf("%d", &scoreEarned);
        //pass in user input.
    
    if (scoreEarned == 100) {
        
        std::cout << "You got a perfect score.\n";
    }
    else if(scoreEarned >= 90 && scoreEarned < 100) {
        std::cout << "You scored an A.\n";
    }
    else if(scoreEarned >= 80 && scoreEarned < 90) {
        std::cout << "You scored an B.\n";
    }
    else if(scoreEarned >= 70 && scoreEarned < 80) {
        std::cout << "You scored an C.\n";
    }
    else if(scoreEarned >= 60 && scoreEarned < 70) {
        std::cout << "You scored an D.\n";
    }
    else if(scoreEarned < 60 && scoreEarned >= 0) {
        std::cout << "You scored an F.\n";
    }
    
    std::cout << "Welcome to Vazquez Vending. I can give you a choice of any\n";
    std::cout << "5 drinks: Coca-Cola, Dirty Sprite, Ironbeer, Heineken, or OJ.\n";
    std::cout << "Please enter any option 1-5 respectively.\n";
        //Allow the user to chooose between any drink.
    
    int drinkOption = 0;
    
    scanf("%d", &drinkOption);
        //Pass in user input.
    
    switch (drinkOption) {
        case 1:
            std::cout << "Dispensing Coca-Cola...\n";
            break;
        case 2:
            std::cout << "Dispensing Dirty Sprite...\n";
            break;
        case 3:
            std::cout << "Dispensing Ironbeer...\n";
            break;
        case 4:
            std::cout << "Dispensing Heineken...\n";
            break;
        case 5:
            std::cout << "Dispensing OJ...\n";
            break;
        default:
            std::cout << "Error: Not a valid option.\n";
            break;
    }
    
    std::cout << "Okay, here's part 3. I'm going to ask you NOT to type in the number 5... Type in ANY number other than 5.\n";
    int notThisNumber = 0;
    
    do {
        scanf("%d", &notThisNumber);
        if (notThisNumber != 5) {
            std::cout << "Input accepted.\n";
        }
        else {
            std::cout << "Bruh, I asked you not to type 5 in!\n";
        }
    } while (notThisNumber != 5);
    return 0;
}
