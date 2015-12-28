// quickSort.c++

#include "swap.h"

/** Chooses a pivot for quicksort's partition algorithm and swaps
 *  it with the first item in an array.
 * @pre theArray[first..last] is an array; first <= last.
 * @post theArray[first] is the pivot.
 * @param theArray  The given array.
 * @param first  The first element to consider in theArray.
 * @param last  The last element to consider in theArray. */
template <typename T>
void choosePivot(T theArray[], long first, long last)
{

	long middle = (first + last)/2;	

	if (theArray[first] > theArray[middle])
		swap(theArray[first],theArray[middle]);

	if(theArray[middle] > theArray[last])
		swap(theArray[middle],theArray[last]);

	if(theArray[first] > theArray[middle])
		swap(theArray[first],theArray[middle]);

	swap(theArray[middle],theArray[first]);

}

/** Partitions an array for quicksort.
 * @pre theArray[first..last] is an array; first <= last.
 * @post Partitions theArray[first..last] such that:
 *    S1 = theArray[first..pivotIndex-1] <  pivot
 *         theArray[pivotIndex]          == pivot
 *    S2 = theArray[pivotIndex+1..last]  >= pivot
 * @param theArray  The given array.
 * @param first  The first element to consider in theArray.
 * @param last  The last element to consider in theArray.
 * @param pivotIndex  The index of the pivot after partitioning. */

template <typename T>
void partition(T theArray[], long first, long last, long& pivotIndex)
{
   // place pivot in theArray[first]
   choosePivot(theArray, first, last);
   T pivot = theArray[first];     // copy pivot

   // initially, everything but pivot is in unknown
   long lastS1 = first;           // index of last item in S1
   long firstUnknown = first + 1; // index of first item in
                                 // unknown

   // move one item at a time until unknown region is empty
   for (; firstUnknown <= last; ++firstUnknown)
   {  // Invariant: theArray[first+1..lastS1] < pivot
      //         theArray[lastS1+1..firstUnknown-1] >= pivot

      // move item from unknown to proper region
      if (theArray[firstUnknown] < pivot)
      {  // item from unknown belongs in S1
         ++lastS1;
         swap<T>(theArray[firstUnknown], theArray[lastS1]);
      }  // end if

      // else item from unknown belongs in S2
   }  // end for

   // place pivot in proper position and mark its location
   swap<T>(theArray[first], theArray[lastS1]);
   pivotIndex = lastS1;
}  // end partition

/** Sorts the items in an array into ascending order.
 * @pre theArray[first..last] is an array.
 * @post theArray[first..last] is sorted.
 * @param theArray  The given array.
 * @param first  The first element to consider in theArray.
 * @param last  The last element to consider in theArray. */
template <typename T>
void quickInsertion(T theArray[], long first, long last, long threshold)
{
   long pivotIndex;

   if ((last-first+1)<= threshold){//if smaller or equal to threshold do insertion
      insertionSort(theArray,(last- first+1));
   
   }else if(first<last){// create the partition: S1, pivot, S2
      partition(theArray, first, last, pivotIndex);

      // sort regions S1 and S2
      quickInsertion(theArray, first, pivotIndex-1, threshold);
      quickInsertion(theArray, pivotIndex+1, last, threshold);
   }  // end if
}  // end quicksort

template <typename T>
void quickBubble(T theArray[], long first, long last, long threshold)
{
   long pivotIndex;

   if ((last-first)<= threshold){// if smaller or equal to threshold do bubble
      bubbleSort(theArray,(last- first+1));
   }else if(first<last){// create the partition: S1, pivot, S2
      partition(theArray, first, last, pivotIndex);

      // sort regions S1 and S2
      quickBubble(theArray, first, pivotIndex-1, threshold);
      quickBubble(theArray, pivotIndex+1, last, threshold);
   }  // end if
}  // end quicksort

template <typename T>
void quicksort(T theArray[], long first, long last)
{
   long pivotIndex;

   if (first < last)
   {  // create the partition: S1, pivot, S2
      partition(theArray, first, last, pivotIndex);

      // sort regions S1 and S2
      quicksort(theArray, first, pivotIndex-1);
      quicksort(theArray, pivotIndex+1, last);
   }  // end if
}  // end quicksort

template <typename T>
void quicksort(T theArray[], long size, long thresh, int n)//created another para to differentiate different versions of quick sort
{
	//decides which version of quick sort to do
	if(n==0){
		quickInsertion(theArray, 0, size-1,thresh);
	}else if(n==1){
		quickBubble(theArray, 0,size-1,thresh);
	}else{	
		quicksort(theArray, 0, size-1);
	}

}