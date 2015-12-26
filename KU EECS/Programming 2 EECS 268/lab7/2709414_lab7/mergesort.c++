// mergeSort.c++

/** Merges two sorted array segments theArray[first..mid] and
 *  theArray[mid+1..last] into one sorted array.
 * @pre first <= mid <= last. The subarrays theArray[first..mid]
 * and theArray[mid+1..last] are each sorted in increasing order.
 * @post theArray[first..last] is sorted.
 * @param theArray  The given array.
 * @param first  The beginning of the first segment in theArray.
 * @param mid  The end of the first segement in theArray.  mid + 1
 *        marks the beginning of the second segment.
 * @param last  The last element in the second segment in theArray.
 * @note This function merges the two subarrays into a temporary
 * array and copies the result into the original array theArray. */
template <typename T>
void merge(T theArray[],
           long first, long mid, long last, T* tempArray)
{
   // initialize the local indexes to indicate the subarrays
   long first1 = first;       // beginning of first subarray
   long last1  = mid;         // end of first subarray
   long first2 = mid + 1;     // beginning of second subarray
   long last2  = last;        // end of second subarray

   // while both subarrays are not empty, copy the
   // smaller item into the temporary array
   long index = first1;    // next available location in
                          // tempArray
   for (; (first1 <= last1) && (first2 <= last2); ++index)
   {  // Invariant: tempArray[first..index-1] is in order
      if (theArray[first1] < theArray[first2])
      {  tempArray[index] = theArray[first1];
         ++first1;
      }
      else
      {  tempArray[index] = theArray[first2];
         ++first2;
      }  // end if
   }  // end for

   // finish off the nonempty subarray

   // finish off the first subarray, if necessary
   for (; first1 <= last1; ++first1, ++index)
      // Invariant: tempArray[first..index-1] is in order
      tempArray[index] = theArray[first1];

   // finish off the second subarray, if necessary
   for (; first2 <= last2; ++first2, ++index)
      // Invariant: tempArray[first..index-1] is in order
      tempArray[index] = theArray[first2];

   // copy the result back into the original array
   for (index = first; index <= last; ++index)
      theArray[index] = tempArray[index];
}  // end merge

/** Sorts the items in an array into ascending order.
 * @pre theArray[first..last] is an array.
 * @post theArray[first..last] is sorted in ascending order.
 * @param theArray  The given array.
 * @param first  The first element to consider in theArray.
 * @param last  The last element to consider in theArray. */
template <typename T>
void mergesort(T theArray[], long first, long last, T* tempArray)
{
   if (first < last)
   {  // sort each half
      long mid = (first + last)/2;    // index of midpoint
      // sort left half theArray[first..mid]
      mergesort(theArray, first, mid, tempArray);
      // sort right half theArray[mid+1..last]
      mergesort(theArray, mid+1, last, tempArray);

      // merge the two halves
      merge(theArray, first, mid, last, tempArray);
   }  // end if
}  // end mergesort

template <typename T>
void mergesort(T theArray[], long size)
{
	T* tempArray = new T[size];
	mergesort(theArray, 0, size-1, tempArray);
	delete [] tempArray;
}
