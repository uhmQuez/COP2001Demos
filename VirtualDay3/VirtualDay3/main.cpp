//
//  main.cpp
//  VirtualDay3
//
//  Created by Christian Vazquez on 5/28/17.
//  Copyright © 2017 Christian Vazquez. All rights reserved.
//

#include <iostream>
#include <fstream>

int main(int argc, const char * argv[])
{
    
    using namespace std;
    //Makes life a little easier.
    
    fstream file;
    file.open("myfile.txt");
    //Open file for reading
    
    
    if(file.is_open())
    {
        while(!file.eof())
        //While end of file not reached
        {
            cout << (char)file.get();
            //print file that was read
        }
        cout  << "\n";
        //creating space for user
    }
    
    file.close();
    //closed file
    system("pause");
    
    return 0;
}
