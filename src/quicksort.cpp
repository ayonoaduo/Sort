/*
Student Name: Onisokien Ayonoadu
Student Number: 200360422
Course: CS 340 - Advanced Data Structures
Task: This program will will sort any number of elements using the Quicksort algorithm
*/

#include <iostream>
using namespace std;

int partition(int *,int, int);
void quicksort(int *,int, int);

int main()
{
    int num;
    char option;
    
    do
    {
        cout << "Enter number of elements: ";
        cin >> num;

        int elements[num];

        cout << "Enter numbers to be sorted: ";
        for(int i = 0 ; i < num; i++)
        {
            cin >> elements[i];
        }

        quicksort(elements, 0, num-1);
        cout << "Sorted list:\n";
        for(int i = 0; i < num; i++)
        {
            cout << elements[i] <<" ";
        }
        
        cout << endl;
        cout << "Do you want to continue? (y/n): ";
        cin >> option;
    
    }while(option == 'y' || option == 'Y');
    
    return 0;
}

int partition(int *elements, int begin, int end)
{
    //Pivot
    int pivot = elements[end];
    
    //Index of pivot
    int pIndex = begin;
    int temp;
    
    //Check if current element is less or equal to pivot then swap
    for(int i = begin; i < end; i++)
    {
        if(elements[i] <= pivot)
        {
            temp = elements[i];
            elements[i] = elements[pIndex];
            elements[pIndex] = temp;
            pIndex++;
        }
    }
    
    //Exchange value of pivot and its index
    temp = elements[end];
    elements[end] = elements[pIndex];
    elements[pIndex] = temp;
    
    return pIndex;  
}
    
void quicksort(int *elements, int begin, int end)
{
    //Ensure end is not zero
    if(begin < end)
    {
        //Recursively perform sort
        int pIndex = partition(elements, begin, end);
        quicksort(elements, begin, pIndex-1);
        quicksort(elements, pIndex+1, end);
    }
}