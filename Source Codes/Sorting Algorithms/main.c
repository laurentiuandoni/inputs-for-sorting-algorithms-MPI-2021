#include <stdio.h>
#include <math.h>
#include <time.h>
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    static int L[9999999], R[9999999];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int partition(int arr[], int l, int h)
{
    int x = arr[(l+h)/2];
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}
void quicksort(int arr[], int l, int h)
{
    static int stack[9999999];
    int top = -1;
    stack[++top] = l;
    stack[++top] = h;
    while (top >= 0) {
        h = stack[top--];
        l = stack[top--];
        int p = partition(arr, l, h);
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
void countSort(long arr[], long n, long exp)
{
    static int output[9999999];
    int i, count[10] = { 0 };
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixsort(long arr[], long n)
{
    long m = getMax(arr, n);
    for (long exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
void arraySortedCheck(int arr[], int n){
    for (int i = 0; i < n; ++i){
        if(arr[n-1] < arr[n-2])
            printf("----------------------------------------------------------------------------------------------------------------------------\n\n");
    }
    printf("Sorted\n\n");
}
void print_array(int a[],int i)
{
    for(int j = 0; j < i; j++)
        printf("%c ",a[j]);
}
void read_file_1(char arr[],int a[],int i)
{   printf("Insertion sort started...\n\n");
    clock_t begin = clock();
    FILE* fptr;
    fptr = fopen(arr, "r");
    while (fscanf(fptr, "%f", &a[i])==1)
    {
        i++;
    }
    insertionSort(a,i);
    clock_t end = clock();
    double time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
    printf("Total time spent= %f",time_spent);
    printf("\n\n");
}
void read_file_2(char arr[],int a[],int i)
{
    printf("Bubble sort started...\n\n");
    clock_t begin = clock();
    FILE* fptr;
    fptr = fopen(arr, "r");
    while (fscanf(fptr, "%f", &a[i])==1)
    {
        i++;
    }
    bubbleSort(a,i);
    clock_t end = clock();
    double time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
    printf("Total time spent= %f",time_spent);
    printf("\n\n");
}
void read_file_3(char arr[],int a[],int i)
{
    printf("Merge sort started...\n\n");
    clock_t begin = clock();
    FILE* fptr;
    fptr = fopen(arr, "r");
    while (fscanf(fptr, "%f", &a[i])==1)
    {
        i++;
    }
    mergeSort(a,1,i);
    clock_t end = clock();
    double time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
    printf("Total time spent= %f",time_spent);
    printf("\n\n");

}
void read_file_4(char arr[],int a[],int i)
{
    printf("Quick sort started...\n\n");
    clock_t begin = clock();
    FILE* fptr;
    fptr = fopen(arr, "r");
    while (fscanf(fptr, "%c", &a[i])==1)
    {
        i++;
    }
    quicksort(a,1,i);
    clock_t end = clock();
    double time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
    printf("Total time spent= %f",time_spent);
    printf("\n\n");
}
void read_file_6(char arr[],int a[],int i)
{
    printf("Radix sort started...\n\n");
    clock_t begin = clock();
    FILE* fptr;
    fptr = fopen(arr, "r");
    while (fscanf(fptr, "%f", &a[i])==1)
    {
        i++;
    }
    radixsort(a,i);
    clock_t end = clock();
    double time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
    printf("Total time spent= %f",time_spent);
    printf("\n\n");
}
void choice_menu(int a,int i)
{
    int choice;
    do
    {
        printf("\n\nMenu\n\n");
        printf("1. Small Lists\n");
        printf("2. Medium Lists\n");
        printf("3. Large Lists\n");
        printf("4. Extra Large Lists\n");
        printf("99. Hamlet\n");
        printf("5. Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                for(int k=0;k<5;k++)
                {
                    printf("\n\nRun Number %d\n\n",k);
                    printf("\n\nSorting Small Lists...\n\n");
                    printf("\n\nSmall Sorted Lists...\n\n");
                    read_file_6("small_sorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_4("small_sorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("small_sorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("small_sorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("small_sorted_list", a, i);
                    arraySortedCheck(a, i);
                    printf("\n\nSmall Reverse Sorted Lists...\n\n");
                    read_file_6("small_reversesorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_4("small_reversesorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("small_reversesorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("small_reversesorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("small_reversesorted_list", a, i);
                    arraySortedCheck(a, i);
                    printf("\n\nSmall Positive Lists...\n\n");
                    read_file_6("small_positive_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_4("small_positive_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("small_positive_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("small_positive_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("small_positive_list", a, i);
                    arraySortedCheck(a, i);
                    printf("\n\nSmall Negative Lists...\n\n");
                    read_file_6("small_negative_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_4("small_negative_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("small_negative_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("small_negative_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("small_negative_list", a, i);
                    arraySortedCheck(a, i);
                    printf("\n\nSmall Integer Lists...\n\n");
                    read_file_4("small_integer_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("small_integer_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("small_integer_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("small_integer_list", a, i);
                    arraySortedCheck(a, i);
                    printf("\n\nSmall Almost Sorted Lists...\n\n");
                    read_file_6("small_almostsorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_4("small_almostsorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("small_almostsorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("small_almostsorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("small_almostsorted_list", a, i);
                    arraySortedCheck(a, i);
                    printf("\n\nSmall Similar Lists...\n\n");
                    read_file_6("small_similar_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_4("small_similar_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("small_similar_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("small_similar_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("small_similar_list", a, i);
                    arraySortedCheck(a, i);
                    printf("\n\nSmall Floating Lists...\n\n");
                    read_file_6("small_floating_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_4("small_floating_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("small_floating_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("small_floating_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("small_floating_list", a, i);
                    arraySortedCheck(a, i);
                }
                break;
            case 2:
                for(int k=0;k<5;k++) {
                    printf("\n\nRun Number %d\n\n", k);
                    printf("\n\nSorting Medium Lists...\n\n");
                    printf("\n\nMedium Sorted Lists...\n\n");
                    read_file_6("medium_sorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_4("medium_sorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("medium_sorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("medium_sorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("medium_sorted_list", a, i);
                    arraySortedCheck(a, i);
                    printf("\n\nMedium Reverse Sorted Lists...\n\n");
                    read_file_6("medium_reversesorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_4("medium_reversesorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("medium_reversesorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("medium_reversesorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("medium_reversesorted_list", a, i);
                    arraySortedCheck(a, i);
                    printf("\n\nMedium Positive Lists...\n\n");
                    read_file_6("medium_positive_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_4("medium_positive_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("medium_positive_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("medium_positive_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("medium_positive_list", a, i);
                    arraySortedCheck(a, i);
                    printf("\n\nMedium Negative Lists...\n\n");
                    read_file_6("medium_negative_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_4("medium_negative_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("medium_negative_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("medium_negative_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("medium_negative_list", a, i);
                    arraySortedCheck(a, i);
                    printf("\n\nMedium Integer Lists...\n\n");
                    read_file_4("medium_integer_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("medium_integer_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("medium_integer_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("medium_integer_list", a, i);
                    arraySortedCheck(a, i);
                    printf("\n\nMedium Almost Sorted Lists...\n\n");
                    read_file_6("medium_almostsorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_4("medium_almostsorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("medium_almostsorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("medium_almostsorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("medium_almostsorted_list", a, i);
                    arraySortedCheck(a, i);
                    printf("\n\nMedium Similar Lists...\n\n");
                    read_file_6("medium_similar_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_4("medium_similar_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("medium_similar_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("medium_similar_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("medium_similar_list", a, i);
                    arraySortedCheck(a, i);
                    printf("\n\nMedium Floating Lists...\n\n");
                    read_file_6("medium_floating_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_4("medium_floating_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("medium_floating_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("medium_floating_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("medium_floating_list", a, i);
                    arraySortedCheck(a, i);
                }
                break;
            case 3:
                for(int k=0;k<5;k++) {
                    printf("\n\nRun Number %d\n\n", k);
                    printf("\n\nSorting Large Lists...\n\n");
                    printf("\n\nLarge Sorted Lists...\n\n");
                    read_file_6("large_sorted_list", a, i);
                    arraySortedCheck(a, i);

                    read_file_4("large_sorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("large_sorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("large_sorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("large_sorted_list", a, i);
                    arraySortedCheck(a, i);
                    printf("\n\nLarge Reverse Sorted Lists...\n\n");
                    read_file_6("large_reversesorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_4("large_reversesorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("large_reversesorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("large_reversesorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("large_reversesorted_list", a, i);
                    arraySortedCheck(a, i);
                    printf("\n\nLarge Positive Lists...\n\n");
                    read_file_6("large_positive_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_4("large_positive_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("large_positive_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("large_positive_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("large_positive_list", a, i);
                    arraySortedCheck(a, i);
                    printf("\n\nLarge Negative Lists...\n\n");
                    read_file_6("large_negative_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_4("large_negative_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("large_negative_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("large_negative_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("large_negative_list", a, i);
                    arraySortedCheck(a, i);
                    printf("\n\nLarge Integer Lists...\n\n");
                    read_file_4("large_integer_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("large_integer_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("large_integer_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("large_integer_list", a, i);
                    arraySortedCheck(a, i);
                    printf("\n\nLarge Almost Sorted Lists...\n\n");
                    read_file_6("large_almostsorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_4("large_almostsorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("large_almostsorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("large_almostsorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("large_almostsorted_list", a, i);
                    arraySortedCheck(a, i);
                    printf("\n\nLarge Similar Lists...\n\n");
                    read_file_6("large_similar_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_4("large_similar_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("large_similar_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("large_similar_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("large_similar_list", a, i);
                    arraySortedCheck(a, i);
                    printf("\n\nLarge Floating Lists...\n\n");
                    read_file_6("large_floating_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_4("large_floating_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("large_floating_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("large_floating_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("large_floating_list", a, i);
                    arraySortedCheck(a, i);
                }
                break;
            case 4:
                for(int k=0;k<5;k++) {
                    printf("\n\nRun Number %d\n\n", k);
                    printf("\n\nSorting Extra Large Lists...\n\n");
                    printf("\n\nExtra Large Sorted Lists...\n\n");
                    read_file_6("extralarge_sorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_4("extralarge_sorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("extralarge_sorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("extralarge_sorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("extralarge_sorted_list", a, i);
                    arraySortedCheck(a, i);
                    printf("\n\nExtra Large Reverse Sorted Lists...\n\n");
                    read_file_6("extralarge_reversesorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_4("extralarge_reversesorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("extralarge_reversesorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("extralarge_reversesorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("extralarge_reversesorted_list", a, i);
                    arraySortedCheck(a, i);
                    printf("\n\nExtra Large Positive Lists...\n\n");
                    read_file_6("extralarge_positive_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_4("extralarge_positive_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("extralarge_positive_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("extralarge_positive_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("extralarge_positive_list", a, i);
                    arraySortedCheck(a, i);
                    printf("\n\nExtra Large Negative Lists...\n\n");
                    read_file_6("extralarge_negative_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_4("extralarge_negative_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("extralarge_negative_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("extralarge_negative_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("extralarge_negative_list", a, i);
                    arraySortedCheck(a, i);
                    printf("\n\nExtra Large Integer Lists...\n\n");
                    read_file_4("extralarge_integer_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("extralarge_integer_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("extralarge_integer_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("extralarge_integer_list", a, i);
                    arraySortedCheck(a, i);
                    printf("\n\nExtra Large Almost Sorted Lists...\n\n");
                    read_file_6("extralarge_almostsorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_4("extralarge_almostsorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("extralarge_almostsorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("extralarge_almostsorted_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("extralarge_almostsorted_list", a, i);
                    arraySortedCheck(a, i);
                    printf("\n\nExtra Large Similar Lists...\n\n");
                    read_file_6("extralarge_similar_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_4("extralarge_similar_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("extralarge_similar_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("extralarge_similar_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("extralarge_similar_list", a, i);
                    arraySortedCheck(a, i);
                    printf("\n\nExtra Large Floating Lists...\n\n");
                    read_file_6("extralarge_floating_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_4("extralarge_floating_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_3("extralarge_floating_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_2("extralarge_floating_list", a, i);
                    arraySortedCheck(a, i);
                    read_file_1("extralarge_floating_list", a, i);
                    arraySortedCheck(a, i);
                }
                break;
            case 5:
                printf("Goodbye\n");
                choice=0;
                break;
            case 99:
                printf("Hamlet started...\n");
                read_file_6("Hamlet.txt", a, i);
                arraySortedCheck(a, i);
                read_file_4("Hamlet.txt", a, i);
                arraySortedCheck(a, i);
                read_file_3("Hamlet.txt", a, i);
                arraySortedCheck(a, i);
                read_file_2("Hamlet.txt", a, i);
                arraySortedCheck(a, i);
                read_file_1("Hamlet.txt", a, i);
                arraySortedCheck(a, i);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

    } while (choice);
}
int main()
{
    long *i=0;
    static long a[9999999];
    choice_menu(a,i);

}