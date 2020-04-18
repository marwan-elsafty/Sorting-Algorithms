#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"
#include "SortingAlgorithms.h"

//FUNCTION THAT RETURNS THE PARENT OF A NODE
int parent(int child)
{
    return (child-1)/2;
}

//FUCNTION THAT RETURNS THE LEFT CHILD OF A NODE
int left(int parent)
{
    return 2*parent+1;
}

//FUCNTION THAT RETURNS THE RIGHT CHILD OF A NODE
int right(int parent)
{
    return 2*parent+2;
}

//FUNCTION THAT CONSTRUCTS A HEAP BY ALLOCATING MEMORY AND SETTING INITIAL VALUES
Heap * constructHeap(int capacity)
{
    Heap * newHeap =(Heap *) malloc(sizeof(Heap));
    newHeap->array = (int *)malloc(capacity*sizeof(int));
    newHeap->capacity =capacity;
    newHeap->size = 0;
    return newHeap;
}


//FUNCTION THAT INSERTS A NEW ELEMENT TO THE HEAP
void insertHeap ( Heap * currHeap, int var)
{
  //IT IS SUPPOSED TO REARRANGE THE HEAP EACH TIME AN ELEMENT
  // IS INSERTED BUT DIDN'T DO SO TO TEST THE HEAP SORT FUNCTION
    currHeap->array[currHeap->size] = var;
    currHeap->size++;
}

//FUNCTION THAT DESTRUCTS THE HEAP BY FREEING THE ALLOCATED MEMORY
void destructHeap(Heap * currHeap)
{
    free(currHeap);
    return;
}

//FUNCTION THAT PUTS THE SELECTED NODE IN ITS RIGHT POSITION IN THE HEAP
void maxHeapify( Heap * currHeap, int node)
{
    int l = left(node);
    int r = right(node);
    int largest = node;

    if( l < currHeap->size && currHeap->array[l] > currHeap->array[largest])
        largest = l;


    if ( r < currHeap->size && currHeap->array[r] > currHeap->array[largest])
        largest = r;

    if ( largest != node)
    {
        swap( &(currHeap->array[largest]), &(currHeap->array[node]) );
        maxHeapify(currHeap, largest);
    }
    else
        return;

}


//FUNCTION THAT BUILD A MAX HEAP
//Assumed that the unordered array
//is already in the Heap structure
void buildMaxHeap(Heap * currHeap)
{
    for (int i = ((currHeap->size)/2)-1; i >= 0 ; i--)
        maxHeapify(currHeap, i);

    return ;
}

//FUNCTION THAT SORTS THE HEAP
void heapSort( Heap * currHeap, int n)
{
     buildMaxHeap(currHeap);

    for(int i = n-1 ; i >=0 ; i--)
    {
        swap(&(currHeap->array[0]), &(currHeap->array[i]));

        currHeap->size -= 1;
        maxHeapify(currHeap, 0);
    }
}



