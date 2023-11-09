#include<stdio.h>
void insertion_sort(int arr[],int size);
void display(int arr[],int size);

int main()
{
    int arr[5]={99,55,1,2,0};
    printf("Before swapping!\n");
    for(int i =0;i<5;i++)
    {
        printf("%4d",arr[i]);
    }
    printf("\nAfter swapping!\n");
    insertion_sort(arr,5);
    display(arr,5);

}
void insertion_sort(int arr[],int size)
{
 int i,j,temp;
 for(i=1;i<size;i++)
 {
     temp=arr[i];
    for(j=i-1;j>=0 && arr[j]>temp;j--)
    {
        //temp=arr[i];
        //if(arr[j]>temp)
            arr[j+1]=arr[j];
    }
    arr[j+1]=temp;
 }
}

void display(int arr[],int size)
{
    for(int i=0;i<size;i++)
    printf("%4d",arr[i]);
}
