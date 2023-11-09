#include<stdio.h>
int selection_array(int arr[],int size1);
int main()
{
int res;
int size=5;
int arr[5] = {99,33,0,5,10};
printf("before swapping the array:\n");
for(int a=0;a<size;a++)
{
printf("%4d",arr[a]);
}
printf("\n");

selection_array(arr,5);
printf("after swapping the array:\n");
for(int i=0;i<size;i++)
{
printf("%4d",arr[i]);
}
printf("\n");
return 0;
}

int selection_array(int arr[],int size1)
{
int temp;
//printf("before swapping the array:")
// while(arr[i] < size1-1)
//{
for(int i=0;i<size1-1;i++)
{
    for(int j=i+1;j<size1;j++)
    {
    if(arr[i] > arr[j])
  {
    temp = arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
  }
    }
 //}
 }

}