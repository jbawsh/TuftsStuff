/***********************************************************************/
/*                          IntList Utilities                          */
/***********************************************************************/

#include <iostream>

using std::cout;

#include "IntList.h"


/*
 * Can use a while or for loop. 
 */
void print(IntList list)
{
        //IntList == IntListNode*
        IntList temp;
        temp = list;

	while (!isEmpty(temp)) {
                cout << head(temp) << " ";
                list = tail(temp);
        }
}

// 	4 ~> 3 ~> ()
void printArtistically(IntList list)
{
	if (isEmpty(list)) {
                cout << "()" << endl;
        } else {
                cout << head(list) << " ~> ";
                printArtistically(tail(list));
        }
}

int sumList(IntList list)
{
	IntList temp;
        temp = list;
        int sum = 0;

        while (!isEmpty(temp)) {
                sum += head(temp);
                list = tail(temp);
        }
	return sum;
}

int length(IntList list)
{
	IntList temp;
        temp = list;
        int counter = 0;

        while (!isEmpty(temp)) {
                list = tail(temp);
                counter++;
        }
	return counter;
}

IntList copy(IntList list)
{
        return list;
}

IntList mapIncrement(IntList list)
{
        int temp;

	if (isEpmty(list)) {
                return list;
        } else {
                temp = head(list) + 1;
                list = deleteHead(list);
                list  = prepend(temp, list);
                mapIncrement(list);
        }
	return list;
}

IntList mapIncrementBy(IntList list, int increment)
{
        int temp;

	if (isEpmty(list)) {
                return list;
        } else {
                temp = head(list) + increment;
                list = deleteHead(list);
                list  = prepend(temp, list);
                mapIncrement(list);
        }
	return list;
}

IntList sum(IntList list1, IntList list2)
{
	// STUB
	return empty();
}

IntList filterPositive(IntList list)
{
	// STUB
	return empty();
}

IntList range(int lo, int hi)
{
	// STUB
	return empty();
}

void deleteList(IntList *p_list)
{
	while (!isEmpty(list)) {
                
}
