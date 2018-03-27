//  main.cpp
//  VirtualDay5
//
//  Created by Christian Vazquez on 6/9/17.
//  Copyright © 2017 Christian Vazquez. All rights reserved.
//

#include <iostream>

using namespace std;

class Stack
{
private:
    int topOfStack;
    int capacity;
    int *storage;
    
public:
    Stack(int capacity)
    {
        if (capacity <= 0)
            throw string("Stack's capacity must be positive");
        storage = new int[capacity];
        this->capacity = capacity;
        topOfStack = -1;
    }
    
    void push(int value)
    {
        if (topOfStack == capacity)
            throw string("Stack's underlying storage is overflow");
        topOfStack++;
        storage[topOfStack] = value;
    }
    
    int peek()
    {
        if (topOfStack == -1)
            throw string("Stack is empty");
        return storage[topOfStack];
    }
    
    void pop()
    {
        if (topOfStack == -1)
            throw string("Stack is empty");
        topOfStack--;
    }
    
    bool isEmpty()
    {
        return (topOfStack == -1);
    }
    
    Stack()
    {
        topOfStack = NULL;
    }
    
    ~Stack()
    {
        delete[] storage;
    }
};

int main ()
{
    Stack *myStack = new Stack();
    myStack->push(5);
    myStack->push(3);
    cout << "We pushed two integers";
    myStack->peek();
    myStack->push(6);
    myStack->push(99);
    myStack->pop();
    myStack->peek();
    cout << "Done with stack" << endl;
    return 0;
}
