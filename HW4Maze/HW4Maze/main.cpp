//
//  main.cpp
//  HW4Maze
//
//  Created by Christian Vazquez on 6/18/17.
//  Copyright © 2017 Christian Vazquez. All rights reserved.
//

#include <iostream>

using namespace std;

class Stack
{
private:
    int sp; //Stack pointer
    int *s; //Stack
    int MAX_SIZE; //Maximum size allowed for stack.
    
//Constructor for the stack.
public: Stack(int size) //Creates the default Stack.
    {
        
        sp = -1; //Points to the outside of the stack.
        MAX_SIZE = size; //Size is set by user input.
        s = new int[MAX_SIZE]; //Declare the stack.
        
    }
    
    //Push function adds element to the top of the stack.
    void push (int in)
    {
        
        if ( sp == (MAX_SIZE - 1) ) //Catches "out of bounds" input.
        {
            printf("Error Stack Overflow \n");
            return;
        }
        s[++sp] = in;
        
    }
    
    //Pop function removes the top element from the stack.
    void pop ()
    {
        
        if (sp == -1) //Catches if stack is empty.
        {
            printf("Error: Stack is Empty \n");
            return;
        }
        sp = sp - 1;
    }
    
    //Peek function returns the top element in the stack.
    int peek()
    {
        return s[sp];
    }
    
    //This function will print the contents of the stack from top to bottom.
    void print()
    {
        int counter;
        printf("Stack: ");
        
        for ( counter = 0; counter <= sp; counter++)
        {
            printf("%d ", s[counter]);
        }
        
        printf("\n");
    }
    
    void size()
    {
    
    printf("Size of Stack: \t %d\n", sp + 1);
    
    }
    
};

//Variables set as row and column counters, respectively.
int r;
int c;

    //Function to print out myMaze.
    void displayMaze(char initialMaze[10][16])
    {
        for (r = 0; r < 10; r++)
        {
            printf("\n");
            for (c = 0; c < 16; c++)
            {
                printf("%c", initialMaze[r][c]);
            }
        }
        printf("\n");
        printf("\n");
    }


int main(int argc, const char * argv[])
{
    cout << "Welcome to the Maze of Craze. Your objective is to reach the bottom right corner." << endl;
    cout << "Here is the Maze: " << endl;
    
    //Declaration of the maze as written in HW4 File.
    char	myMaze[10][16] =
    {
        "11111111111111",
        "1 1 1 111 1  11",
        "1             1",
        "1 1 1111111 1 1",
        "1 1   1   1   1",
        "1 111  11  1111",
        "1    1 1      1",
        "11 1 1 1 111 11",
        "11   1   1    1",
        "111111111111111"
    };
    
    displayMaze(myMaze);
    
    //Initialization of position stacks for rows and counters, respectively.
    Stack myPositionR(80);
    Stack myPositionC(80);
    
    //Pushed in [1][1] as intial position.
    myPositionR.push(1);
    myPositionC.push(1);
    
    myMaze[1][1] = '*';
    
    //[8][13] is the end of the maze.
    while (r != 8 || c!= 13)
    {
        r = myPositionR.peek();
        c = myPositionC.peek();
        
        //Move right.
        if (myMaze[r][c+1] == ' ' && myMaze[r][c+1] != '*')
        {
            c++;
            myMaze[r][c] = '*';
            myPositionC.push(c);
            myPositionR.push(r);
        }
        
        //Move down.
        else if (myMaze[r+1][c] == ' ' && myMaze[r+1][c] != '*')
        {
            r++;
            myMaze[r][c] = '*';
            myPositionC.push(c);
            myPositionR.push(r);
        }
        
        //Move up.
        else if (myMaze[r-1][c] == ' ' && myMaze[r-1][c] != '*')
        {
            r--;
            myMaze[r][c] = '*';
            myPositionC.push(c);
            myPositionR.push(r);
        }
        
        //Move left.
        else if (myMaze[r][c-1] == ' ' && myMaze[r][c-1] != '*')
        {
            c--;
            myMaze[r][c] = '*';
            myPositionC.push(c);
            myPositionR.push(r);
        }
        
        //In the event that a dead end is reached, X is placed.
        else
        {
            myMaze[r][c] = '.';
            myPositionC.pop();
            myPositionR.pop();
        }
    }
    cout << "Here is the completed maze. It is a-maze-ing!\n" << endl;
    displayMaze(myMaze);
    
    return 0;
}
