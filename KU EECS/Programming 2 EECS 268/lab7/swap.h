// swap.h

#ifndef SWAP_H
#define SWAP_H

/** Swaps two items.
 * @pre x and y are the items to be swapped.
 * @post Contents of actual locations that x and y represent are
 *       swapped.
 * @param x  Given data item.
 * @param y  Given data item. */
template <typename T>
void swap(T& x, T& y)
{
	T temp = x;
	x = y;
	y = temp;
}  // end swap

#endif
