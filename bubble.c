#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SWAP(a, b) do {int tmp = a; a = b; b = tmp;} while (0)
#define ARRAY_LENGTH(array) (sizeof((array))/sizeof((array)[0]))

void bubbleSort(int arr[], int n);
void printArray(int arr[], int n);

long long main(int argc, char* argv[]) {
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
    bubbleSort(array, n);
    if(clock_gettime(CLOCK_REALTIME, &tv2)) perror("error clock_gettime\n");

    //printf("sorted:\n");
    //printArray(array, n);

    long int sortTime = tv2.tv_nsec-tv1.tv_nsec;
    //printf("Difference is %ld ns\n", sortTime);
    return sortTime;
}


void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                SWAP(arr[j], arr[j + 1]);
}

void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i) printf("%d ", arr[i]);
    printf("\n");
}
