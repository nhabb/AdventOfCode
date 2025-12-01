// C++ program to implement the circular queue using array
#include <bits/stdc++.h>

// defining the max size of the queue
#define MAX_SIZE 100

using namespace std;

// class that represents queue
class Queue {
public:
    int front, rear, count;
    int arr[MAX_SIZE];

    Queue() : front(0), rear(0), count(0) {}

    bool isEmpty() { return count == 0; }
    bool isFull()  { return count == MAX_SIZE; }

    void enqueue(int val)
    {
        if (isFull()) { printf("Queue Overflow!\n"); return; }
        arr[rear] = val;
        rear = (rear + 1) % MAX_SIZE;
        count++;
    }

    void dequeue()
    {
        if (isEmpty()) { printf("Queue Underflow!\n"); return; }
        front = (front + 1) % MAX_SIZE;
        count--;
    }

    int size() const { return count; }

    class OutOfRangeException : public std::exception 
    { 
        virtual const char *what() const throw() 
        { 
            return "index out of range"; 
        }
    };

    void print()
    {
        int n = size();
        for (int i = 0; i < n; ++i) 
        {
            int pos = (front + i) % MAX_SIZE;
            cout << arr[pos] << "\n";
        }
    }


    int &operator[](int index)
    {
        if (index < 0 || index >= count)
            throw OutOfRangeException();
        int pos = (front + index) % MAX_SIZE;
        return arr[pos];
    }
};
