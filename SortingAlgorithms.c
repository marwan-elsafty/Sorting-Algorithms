#include <stdio.h>
#include <stdlib.h>
#include "SortingAlgorithms.h"



//SORTING ALGORITHMS WITH COMPLEXITY O(n^2)

void selectionSort(int array[], int size)
{
    for(int i = 0 ; i < size-1; i++)
    {
        int smallest = i;
        for(int j = i+1 ; j < size; j++)
        {
            if(array[j] < array[smallest])
                smallest = j;
        }
        swap(&array[i], &array[smallest]);
    }
}

void insertionSort(int array[], int size)
{
    for(int i = 1; i < size ; i++)
    {
        int key = array[i];
        int j = i-1;

        while(j>=0 && array[j]>key)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

void bubbleSort(int array[], int size)
{
    for(int i = 0; i < size-1; i++)
    {
        int flag=0;
        for(int j = 0; j < size-i-1; j++)
        {
            if(array[j] > array[j+1])
            {
                swap(&array[j],&array[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            return;
    }
}





// SORTING ALGORITHMS WITH COMPLEXITY O(n*lgn)

void mergeSort(int array[],int start, int end)
{
    if(end > start)
    {
        int middle = (start+end-1)/2 ;
        mergeSort(array, start, middle );
        mergeSort(array, middle+1, end);
        merge(array,start,end,middle);
    }
}

void quickSort(int array[], int start, int end)
{

    if(start <end)
    {
        int pivot = partition(array,start,end);
        quickSort(array, start, pivot-1);
        quickSort(array, pivot+1, end);
    }
}


//UTILITY FUNCTIONS

// FUNCTION THAT MERGES 2 GIVEN SORTED ARRAYS INTO ONE SORTED ARRAY
//  HELPER FUNCTION FOR THE MERGE SORT
void merge(int array[],int start,int end, int middle)
{
    int i,j,k;
    int n1 = middle - start + 1;
    int n2 = end - middle;

    int arr1[n1], arr2[n2];

    for(int i = 0; i < n1 ; i++)
        arr1[i] = array[start+i];

    for(int i = 0; i < n2 ; i++)
        arr2[i] = array[middle+1+i];

    i=j=0;
    k = start;

    while(i < n1 && j < n2)
    {
        if(arr1[i] <= arr2[j])
        {
            array[k] = arr1[i];
            i++;
        }
        else
        {
            array[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        array[k] = arr1[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        array[k] = arr2[j];
        j++;
        k++;
    }
}

// FUNCTION THAT PARTITIONS AN ARRAY INTO 2 HALFS IN THE SAME ARRAY
//  HELPER FUNCTION FOR THE QUICK SORT
int partition(int array[], int start, int end)
{
    int pivot = array[end];
    int i = start-1 ;

    for(int j = start; j <= end-1 ; j++)
    {
        if(array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i+1], &array[end]);
    return i+1;
}

// FUNCTION THAT SWAPS 2 ELEMENTS IN AN ARRAY
void swap( int * x, int * y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}






