Hw4

Three Sorts

Name: James McCants
Date: 5/6/14

--------------------------------------------------------------------------------

Selection Sort:

The algorithm for this sort is to move through the array to find the smallest
element and then swap it with the first element. Then think about that part of
the array as sorted and have a new 'frist' element. You do this all the way
through and eventually the entire array is sorted.

Complexity Analysis:

It always takes n-1 comparisons for every time you go through the array so it
is within O(n2). It is most efficient on smaller arrays where the O(nlogn) 
advantage is less noticeable.

--------------------------------------------------------------------------------

Insertion Sort:

The algorithm for this sort is to divide the array into two parts of sorted and
unsorted and each time through take the first element of the unsorted part and
insert it into the sorted part in the right position until there is no unsorted
part left.

Complexity Analysis:

In the best case the array is already sorted so it is linear O(n) where each
element is only compared with the one next to it and no swaps take place. The
worst case is a reversed order array which comes out to O(n2) because the entire
sorted portion has to be shifted every time something is added. The average case
is also quadratic eventually so insertion sort is better suited for smaller
arrays.

--------------------------------------------------------------------------------

Shell Sort:

The algorithm for this sort is a lot like insertion sort but it uses ever
decreasing gaps between comparisons so that a lot of the mess is cleaned up
earlier on so that when the gaps are smaller there is less work to do then there
would be in a normal insertion sort.

Complexity Analysis:

The best case scenario is O(nlogn) because every time you go through you have to
check for the gaps all the way down to no gaps so even if it's sorted you go
through more than n times. Worst case depends on the formula you use to decrease
the gap size with it being at most as bad as a straight up insertion sort at
O(n2).

--------------------------------------------------------------------------------

Referenced Wikipedia for all three algorithms and the complexity of them.
