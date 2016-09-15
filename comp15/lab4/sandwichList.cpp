/* sandwichList.cpp
 * Comp 15 
 * Spring 2014 
 * Lab 4
 */

#include "sandwichList.h"


SandwichList::SandwichList()
{
	capacity = INITIAL_SIZE;
	orders = new Order[INITIAL_SIZE];
	orderCount = 0;

	back = 0;
	front = 0;
}

bool SandwichList::isEmpty()
{
	if (size() == 0)
		return true;
	else
		return false;
}


int SandwichList::size()
{
        return orderCount;
        // you could use the following arithmetic (but be careful):
	//return (back - front + capacity) % capacity;
}

//function to remove Order from the front of the queue
Order SandwichList::dequeue()
{

        orderCount--;
        Order removed = orders[front];
        front++;
        if(front >= capacity) {
                front = 0;
        }
        return removed;

}

//add an element, make sure it is not full, if it is call expand funciton
void SandwichList::enqueue(const Order& sw)
{

        orderCount++;
        if(orderCount > capacity) {
                expandList();
        }        
        orders[back] = sw;
        back++;
        if (back >= capacity) {
                back = 0;
        }

}

//Double the queue size, copy the values, and reset back and front
void SandwichList::expandList()
{

        int index;
        Order* temp = new Order[capacity*2];
        for(int i = 0; front+i < capacity; i++) {
                temp[i] = orders[front+i];
                index = i;
        }
        index += 1;

        if(front > 0) {
                for(int j = 0; j < front; j++) {
                        index += j;
                        temp[index] = orders[j];
                }
                index += 1;
        }

        delete [] orders;

        orders = new Order[capacity*2];
        orders = temp;
        capacity = capacity*2;
        front = 0;
        back = index;

}

void SandwichList::printOrder(Order s)
{
	cout << s.sandwich << " " << s.customerName << " " << s.orderNbr << " " << s.fries;
	cout << endl;
}



