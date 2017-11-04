#include "MergeSort.h"

/*   Merges two subarrays of arr[].
 **  First subarray is arr[l..m]
 *   Second subarray is arr[m+1..r]
 */
void Merge(uint8_t arr[],int l,int r,int m){

  int i, j, k;
  int leftIndex = m - l + 1;
  int rightIndex = r - m;

  uint8_t leftArray[leftIndex], rightArray[rightIndex];   // temporary array

// Copy data to Temporary array
  for(i=0;i<leftIndex;i++)
    leftArray[i] = arr[i+l];
  for(j=0;j<rightIndex;j++)
    rightArray[j] = arr[m+1+j];

    i=0;
    j=0;
    k=l;

// Merge the temp arrays back into arr[l..r]
    while(i<leftIndex && j<rightIndex){
      if(leftArray[i] <= rightArray[j]){
        arr[k] = leftArray[i];
        i++;
      }else{
        arr[k] = rightArray[j];
        j++;
      }
      k++;
    }

// For data that are remaining(optional)
    while(i<leftIndex){
      arr[k] = leftArray[i];
      i++;
      k++;
    }

    while(j<rightIndex){
      arr[k] = rightArray[j];
      j++;
      k++;
    }
  }


void MergeSort(uint8_t arr[],int l, int r){
    if(l<r){
      int mid = l + ( r-l )/2;

 // Sort first and second halves
      MergeSort(arr,l,mid);
      MergeSort(arr,mid+1,r);

      Merge(arr,l,r,mid);
  }
}
