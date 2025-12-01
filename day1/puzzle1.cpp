#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include "queue.hpp"

/*
    *The circular queue was imported from a previous implementation
    *The idea behind going for a circular queue is to be able to go from 99->0 and vise versa
    *I had to normalize the indices since I was getting massive index values from the data file
    *Operator was implemnted by me for ease of data access
*/

int main()
{
    Queue q;
    ifstream reader("data.txt");
    string line;
    int count = 0;
    int index = 50;
    int oldIndex = 50;
    for (int i = 0; i <= 99; i++)
    {
        q.enqueue(i);
    }
    while (getline(reader,line))
    {
        if (line[0] == 'L')
        {
            int value = stoi(line.substr(1)) %MAX_SIZE;
            index = (oldIndex - value + MAX_SIZE) % MAX_SIZE;
            oldIndex = index;
            if (q[index] == 0)
                count++;
        }
        else if (line[0] == 'R')
        {
            int value = stoi(line.substr(1)) % MAX_SIZE;
            index = (oldIndex + value) % MAX_SIZE;
            oldIndex = index;
            if (q[index] == 0)
                count++;
        }
    }
    reader.close();
    cout<<count<<endl;
}