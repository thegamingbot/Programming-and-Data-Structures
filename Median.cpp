#include<stdio.h>

void mergeArrays(int arr1[], int arr2[], int n, int arr3[]) 
{ 
    int i = 0, j = 0, k = 0; 
    while (i<n && j <n) 
    {
        if (arr1[i] < arr2[j]) 
            arr3[k++] = arr1[i++]; 
        else
            arr3[k++] = arr2[j++]; 
    }
    while (i < n) 
        arr3[k++] = arr1[i++];
    while (j < n) 
        arr3[k++] = arr2[j++]; 
}

int main()
{
	int arr1[]={1,3,5,7,9};
	int arr2[]={0,2,4,6,8};
	int n=sizeof(arr1)/sizeof(arr1[0]);
	int arr3[2*n];
	float median;
	mergeArrays(arr1, arr2, n, arr3);
	median = (float)(arr3[n]+arr3[n-1])/2;
	printf("%f", median);
}
