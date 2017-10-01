/*
Various Sorthing Methods
While I generally hate the idea of creating a global variable as there's too many
different things that can go wrong, for the sake of demonstrating various sorting 
methods, I felt it would be fine for this.

Feedback welcomed, still a work in progress.

*/


#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int counter = 0;
const int MAX_ARR = 6; //Global Variable for testing different interations

void merge(int num[], int size, int first, int mid, int last)
{
     int tempArr[size];
     
     for (int i = first;i<=last;i++)
     tempArr[i]=num[i];
     
     int a = first;
     int b = mid+1;
     int c = first;
     
     while (a<=mid && b <=last)
     {
           if (tempArr[a] <=tempArr[b])
           {
              num[c] = tempArr[a];
              a++;
           }
           else
           {
               num[c] = tempArr[b];
               b++;
           }
           c++;
     }
     
     while (a <= mid)
     {
           num[c] = tempArr[a];
           c++;
           a++;
     }
}

void mergeSort (int num[], int size, int first, int last)
{
     int mid = 0;
     
     if (first < last)
     {
        mid = (first+last)/2;
        mergeSort (num, size, first, mid);
        mergeSort (num, size, mid+1, last);
        merge (num, size, first, mid, last);
     }
}

void bucketSort(int numbers[], int size)
{
     int high = numbers[0]; 
     int low = high;
     int temp = 0;
     
     //Determine Boundaries
     for (int i =1; i < MAX_ARR; i++)
     {    
          if (numbers[i] < low)
          low = numbers[i];
          
          if (numbers[i] > high)
          high = numbers[i];
     }
     
     int mid = (high+low)/2;
     int i = numbers[low+1];
     
     while (i!>= mid && i
     
     
}



int main()
{
    int swap = 0;
    int numbers[MAX_ARR];
    
	srand(time(NULL));
        
    //Allocate an Array for Bubble Sort
    cout << endl << "Allocating test numbers for Bubble sort.."<<endl;
    
	for (int i = 0; i < MAX_ARR; i++)
    	numbers[i] =(rand()%100)+1;
        
    //Display current Array
    for (int i =0; i < MAX_ARR; i++)
    	cout << endl << i+1 << ". "<<numbers[i];
    
    cout << endl << endl << "Now utilizing the Bubble Sort..." <<endl;
        
    //Bubble Sort
    for (int i = 0; i < MAX_ARR; i++)
    {
        for (int j=0; j < MAX_ARR-1; j++)
        {
            if (numbers[j] > numbers[j+1])
            {
               swap = numbers[j];
               numbers[j] = numbers[j+1];
               numbers[j+1] = swap;
            }
        }
    }
        
    //Display results of Bubble Sort
    cout << endl <<"Results of Bubble Sort" << endl;
    for (int i = 0; i < MAX_ARR; i++)
    	cout << endl << i + 1 << ". " << numbers[i];
       
    //Reallocate array for Merge Sort
    cout << endl << endl << "Allocating test numbers for Merge sort..." << endl;
    for (int i = 0; i < MAX_ARR; i++)
    	numbers[i] = (rand()%100) + 1;
        
    //Display current array for Merge Sort
    for (int i = 0; i < MAX_ARR; i++)
    	cout << endl << i+1 << ". " <<numbers[i]; 
    
    cout << endl << endl << "Now utilizing the Merge Sort..." <<endl;
    
    //Merge Sort
    mergeSort(numbers,MAX_ARR, 0,MAX_ARR-1);
       
    //Display results of Merge Sort
    cout << endl << "Results of Merge Sort" << endl;
    for (int i = 0; i < MAX_ARR; i++)
    	cout << endl << i+1 << ". " << numbers[i];
       
    //Reallocate array for Bucket Sort
    cout << endl << endl << "Allocating test numbers for Bucket sort..."<<endl;
    for (int i = 0; i < MAX_ARR; i++)
    	numbers[i] =(rand()%100)+1;
    
    //Display Current array for Bucket Sort
    for (int i = 0; i < MAX_ARR; i++)
    	cout << endl << i+1 << ". " << numbers[i];
        
    //Bucket Sort
    bucketSort(numbers,MAX_ARR);       
    
    cout << endl << endl;

    system("pause");   
       
return 0;
}
