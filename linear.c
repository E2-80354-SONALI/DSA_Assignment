#include<stdio.h>
int linear_search(int arr[],int size,int key);
int main()
{
    int result;
int arr[5]={66,77,33,22,11}; 
int key =11;

result = linear_search(arr,5,11);
if(result != -1)
    printf("key is found in index %d!",result);
else
    printf("key is not found!");
}

int linear_search(int arr[],int size,int key)
{
for(int i=0;i<size;i++)
{
    if(key==arr[i])
    //if(key != arr[i])
      //  printf("key is not found!");
      return i;

}
 return -1;
}