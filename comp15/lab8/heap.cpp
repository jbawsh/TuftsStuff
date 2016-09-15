#include "heap.h"

Heap::Heap()
{
    
    heap = new string[INIT_SIZE];
	heapSize = 0;
}


Heap::Heap(string list[], int listSize)
{
    
    heap = new string[listSize+1];

	//remember our implementation of a
    //heap starts at 1 not zero, so
    //we store a sentinal value at 0
    //this is not ideal as we could support
    //the null string, so it is best to
    //remember index 0 is not used
	heap[0]="";

    
    //copy the unsorted list over
	for(int i=0; i < listSize; i++)
	{
		heap[i+1] = list[i];
	}
	
	heapSize = listSize;

    //use the build heap function
    //to make it a heap
	buildHeap();

}

//doesn't really work
//as the upHeap function
//is not implemented as it
//is nearly the same as the
//down heap funciton

void Heap::insert(string x)
{
    
    if(heapSize >= maxCapacity)
    {
        expand();
    }
    
	//location to insert is heapSize+1 
	//(Recall, 0th location not used)
	heap[heapSize+1] = x;
	heapSize++;
    
	//heapsize points to index of last element now
	//reheap or upHeap to fix
	upHeap(heapSize);

}

string Heap::removeMin()
{
        string value = heap[1];

	heap[1] = heap[heapSize];
        downHeap(1);
        heapSize--;
	return value;
}

int Heap::size()
{
	return heapSize;
}



void Heap::downHeap(int location)
{
        int left = leftChild(location);
        int right = rightChild(location);
        string value = heap[location];
        bool isLeft = true;
        
        if (left <= heapSize) {
                if (right <= heapSize) {
                        if (heap[left] > heap[right]) {
                                isLeft = false;
                        }
                }
        } else {
                return;
        }

        if (isLeft) {
                if (heap[left] < heap[location]) {
                        heap[location] = heap[left];
                        heap[left] = value;
                        downHeap(left);
                }
        } else {
                if (heap[right] < heap[location]) {
                        heap[location] = heap[right];
                        heap[right] = value;
                        downHeap(right);
                }
        }
}

void Heap::upHeap(int location)
{
	//coming soon as it gives away the answer to heapify
        //they are the same funciton
}	

void Heap::buildHeap()
{

        int index = heapSize/2;
        for (int i = index; i > 0; i--) {
                downHeap(i);
        }
}

int Heap::leftChild(int index)
{
	return index*2;
}
int Heap::rightChild(int index)
{
	return index*2+1;

}
int Heap::parent(int index)
{
	return index/2;
}


//same old expand function, copying
//each element preserves the heap property
void Heap::expand()
{
    string *temp = new string[maxCapacity*2];
    
    for (int i = 0; i < heapSize+1; i++) {
        temp[i] = heap[i];
    }
    maxCapacity = maxCapacity*2;
    
    delete[] heap;
    heap = temp;
}

