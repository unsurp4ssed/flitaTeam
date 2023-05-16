#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <error.h>
#define SWAP(a, b) do {int tmp = a; a = b; b = tmp;} while (0)
#define LeftChild(i) (2*(i)+1)
#define ARRAY_LENGTH(array) (sizeof((array))/sizeof((array)[0]))

void heapify(int *arr, int i, int n);
void heapSort(int arr[], int n);
void printArray(int arr[], int n);

long main(int argc, char* argv[]) {
    struct timespec tv1;
    struct timespec tv2;

    FILE* f = fopen("data.txt", "r");
    int n = atoi(argv[1]);
    char s[10];
    int array[n];
    for (int i = 0; i < n; i++)
    {
        fgets(s, 10, f);
        array[i] = atoi(s);
    }

    //printf("unsorted: \n");
    //printArray(array, n);

    if(clock_gettime(CLOCK_REALTIME, &tv1)) perror("error clock_gettime\n");
    heapSort(array, n);
    if(clock_gettime(CLOCK_REALTIME, &tv2)) perror("error clock_gettime\n");

    //printf("sorted:\n");
    //printArray(array, n);

    long int sortTime = tv2.tv_nsec-tv1.tv_nsec;
    //printf("Difference is %ld ns\n", sortTime);
    return sortTime;
}


void heapify(int *a, int i, int n)
{
    int child,temp,k;
    for(temp=a[i];LeftChild(i)<n;i=child)
    {
        child=LeftChild(i);
        if(child != n-1 && a[child+1]>a[child])
            child++;
        if(temp < a[child])
            a[i]=a[child];
        else
            break;
    }
    a[i]=temp;
}

void heapify_old(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i)
    {
        SWAP(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, i, n);
    for (int i=n-1; i>=0; i--)
    {
        SWAP(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}

void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i) printf("%d ", arr[i]);
    printf("\n");
}
