
#include <stdio.h>
#define SIZE 6


void lin_rec(int arr[], int size, int key, int index);
int sorted(int arr[],int size);
void binary_search(int arr[],int size,int key,int left,int right);
int main() {
    int arr[SIZE];
    int key;

   // printf("Enter the SIZE: %d\n", SIZE);
    printf("Enter the array elements:\n");
    for (int i = 0; i < SIZE; i++)
        scanf("%d", &arr[i]);
    printf("Enter the key: ");
    scanf("%d", &key);
    //lin_rec(arr, SIZE, key, 0);
    binary_search(arr,SIZE,key,0,SIZE-1);
 // Start the linear search
    //sorted(arr,SIZE);

    return 0;
}

void lin_rec(int arr[], int size, int key, int index) {
    if (index == size) {
        printf("Key not found in the array.\n");
        return;
    }
    
    if (arr[index] == key) {
        printf("Key is found at index %d.\n", index);
        return;
    }

    lin_rec(arr, size, key, index + 1); // Recursively search the next element
}

/*
int sorted(int arr[],int size)
{
    int temp;
    {
    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
    {
        if(arr[i]>arr[j])
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
           // return arr;
        }
    }
    }
    }
    for(int i =0;i<size;i++)
    {
        printf("%4d",arr[i]);
    }
}
*/
void binary_search(int arr[],int size,int key,int left,int right)
{
int res,mid;
//sorted(arr,size);
//printf("%4d",arr[i]);
//printf("sorted array=%4d",res);
//left = 0;
//right = size-1;=)
mid = (left+right)/2;

while(left >= right)
 {
//mid = (left+right)/2;
if(key!=arr[mid])
{
    printf("key is not found!\n");
}
if(key==arr[mid])
    {
    printf("found in mid\n");
        return;

    }
    //return;
    //right sub array
else if(key > arr[mid])
    {
   // left = mid+1;
   // right = size;
   //// mid = (left+right)/2;

    if(key == arr[mid])
    {
      printf("found in left\n"); 
      return; 
      binary_search(arr,size,key,mid-1,right);

    }
    //return;
   // binary_search(arr,size,key,mid-1,right);

    }
else if(key < arr[mid])
   {
//left = 0;
//right = mid-1;
//mid = (left+right)/2;
   if(key == arr[mid])
   printf("found in right side!\n");
   return;
    binary_search(arr,size,key,left,mid-1);

   }
   //return;
   //binary_search(arr,size,key,left,mid-1);
  }
}
//binary_search(arr,size,key,(left+right)/2);




