//
//  main.cpp
//  HW2IOFiles
//
//  Created by Christian Vazquez on 6/4/17.
//  Copyright © 2017 Christian Vazquez. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[])
{
    char nameOfInFile[80];
    char nameOfOutFile[80];
    char lineRead[100];

    cout << "Please type in the file you'd like to read from: " << endl;

    //Scan in name of text file to read
    scanf("%s", nameOfInFile);

    cout << "Excellent, now type in the name of the file you'd like to write to: " << endl;

    //Scan in name of text file to write to
    scanf("%s", nameOfOutFile);

    fstream inFile;
    fstream outFile;

    //Opening the file to read from
    inFile.open(nameOfInFile);

    //Opening the file to write to
    outFile.open(nameOfOutFile);

    //Counter variable to count each loop iteration
    int counter = 1;

    if (inFile.is_open())
    {
        //Reading through the file till there are no more lines to read
        while (inFile.getline(lineRead, 100))
           {
               //Adding the line number via the counter variable. Making it look GOOD
               outFile << counter << ". " << lineRead << "\n";
               counter++;
           }
    }
    else
    {
        //If file is not found or can't open
        cout << "Unable to open file.";
    }
    //Closing both files
    inFile.close();
    outFile.close();

    return 0;
}
