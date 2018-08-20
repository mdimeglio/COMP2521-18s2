1. Simple recursion example
```C
int fac(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * fac(n-1);
  }
}
```

2. Sorting examples on the board
-- Highlight insertion sort implementation works backwards
-- From sortlab - the implementations given are likely the same or similar to those in sortlab


Sorts:
* Bubble sort
* Insertion sort
* Shell sort
* Merge sort
* Quicksort
* Quicksort median of three
* Selection sort

```C
int nums[8] = { 4, 6, 2, 7, 8, 5, 1, 3 };
xyzSort(nums, 0, 7);

// bubble sort
void bubbleSort(int a[], int lo, int hi)
{
   int i, j, nswaps;
   for (i = lo; i < hi; i++) {
      nswaps = 0;
      for (j = hi; j > i; j--) {
         if (less(a[j], a[j-1])) {
            swap(a,j,j-1);
            nswaps++;
         }
      }
      //monitor("Next");
      if (nswaps == 0) break;
   }
}

// insertion sort
void insertionSort(int a[], int lo, int hi)
{
   int i, j, val;
   for (i = hi; i > lo; i--)
      if (less(a[i],a[i+1])) swap(a,i,i+1);
   //monitor("Next");
   for (i = lo+2; i <= hi; i++) {
      val = a[i];
      for (j = i; less(val,a[j-1]); j--) {
         move(a,j,j-1);
      }
      a[j] = val;
      //monitor("Next");
   }
}

// shell sort
void shellSort(int a[], int lo, int hi)
{
	int gaps[8] = {701, 301, 132, 57, 23, 10, 4, 1};
	//int gaps[6] = {1073, 281, 77, 23, 8, 1};
	int g, gap, start, i, j, val;

	for (g = 0; g < 8; g++) {
		gap = gaps[g];
		start = lo + gap;
		for (i = start; i < hi; i++) {
			val = a[i];
			for (j = i; j >= start && less(val,a[j-gap]); j -= gap)
				move(a, j, j-gap);
			a[j] = val;
		}
	}
}

// mergesort
#if 1
void merge(int a[], int lo, int mid, int hi)
{
   int  i, j, k, nitems = hi-lo+1;
   int *tmp = malloc(nitems*sizeof(int));

   i = lo; j = mid+1; k = 0;
   while (i <= mid && j <= hi) {
     if (less(a[i],a[j]))
        copy(tmp, &k, a, &i);
	 else
        copy(tmp, &k, a, &j);
   }
   while (i <= mid) copy(tmp, &k, a, &i);
   while (j <= hi) copy(tmp, &k, a, &j);

   //copy back
   for (i = lo, k = 0; i <= hi; i++, k++) {
      a[i] = tmp[k];
      nmoves++;
   }
   free(tmp);
}
void mergeSort(int a[], int lo, int hi)
{
   int mid = (lo+hi)/2; // mid point
   if (hi <= lo) return;
   mergeSort(a, lo, mid);
   mergeSort(a, mid+1, hi);
   merge(a, lo, mid, hi);
}
#else
// merge arrays a[] and b[] into c[]
// aN = size of a[], bN = size of b[]
void merge(int a[], int aN, int b[], int bN, int c[])
{
   int i; // index into a[]
   int j; // index into b[]
   int k; // index into c[] 
   for (i = j = k = 0; k < aN+bN; k++) {
      if (i == aN)
         c[k] = b[j++];
      else if (j == bN)
         c[k] = a[i++];
      else if (less(a[i],b[j]))
         c[k] = a[i++];
      else
         c[k] = b[j++];
   }
}
void doMergeSort(int a[], int b[], int lo, int hi)
{
   if (lo >= hi) return;
   int mid = (lo+hi)/2;
   doMergeSort(b, a, lo, mid);
   doMergeSort(b, a, mid+1, hi);
   merge(b+lo, mid-lo+1, b+mid+1, hi-mid, a+lo);
}
void mergeSort(int a[], int lo, int hi)
{
   int i;
   int *aux = malloc((hi+1)*sizeof(int));
   for (i = lo; i <= hi; i++) aux[i] = a[i];
   doMergeSort(a, aux, lo, hi);
   free(aux);
}
#endif

// quicksort
void medianOfThree(int a[], int lo, int hi)
{
   int mid = (lo+hi)/2;
   if (less(a[mid],a[lo])) swap(a, lo, mid);
   if (less(a[hi],a[mid])) swap(a, mid, hi);
   if (less(a[mid],a[lo])) swap(a, lo, mid);
   // now, we have a[lo] <= a[mid] <= a[hi]
   // swap a[mid] to a[lo+1] to use as pivot
   swap(a, lo+1, mid);
}

int partition(int a[], int lo, int hi)
{
   int v = a[lo];  // pivot
   int i = lo+1, j = hi;
   for (;;) {
      while (less(a[i],v) && i < j) i++;
      while (less(v,a[j]) && j > i) j--;
      if (i == j) break;
      swap(a,i,j);
   }
   j = less(a[i],v) ? i : i-1;
   swap(a,lo,j);
   return j;
}

void quickSort(int a[], int lo, int hi)
{
   int i; // index of pivot
   //printf("qsort(a,%d,%d)\n",lo,hi);
   if (lo >= hi) return;
   i = partition(a, lo, hi);
   quickSort(a, lo, i-1);
   quickSort(a, i+1, hi);
}

void quickSort1(int a[], int lo, int hi)
{
   int i; // index of pivot
   //printf("qsort(a,%d,%d)\n",lo,hi);
   if (lo >= hi) return;
   if (hi-lo < 10) {
      insertionSort(a,lo,hi);
      return;
   }
   medianOfThree(a, lo, hi);
   i = partition(a, lo, hi);
   quickSort1(a, lo, i-1);
   quickSort1(a, i+1, hi);
}


// selection sort
void selectionSort(int a[], int lo, int hi)
{
   int i, j, min;
   for (i = lo; i < hi; i++) {
      min = i;
      for (j = i+1; j <= hi; j++) {
         if (less(a[j],a[min])) min = j;
      }
      swap(a,i,min);
   }
}
```