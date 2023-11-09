#include<stdio.h>
int bubble_sort(int arr[],int size);

int main()
{
    int arr[5]={10,80,40,4,0};
    printf("Before the sorting array!\n");
    for(int i=0;i<5;i++)
    {
        printf("%4d",arr[i]);
    }
bubble_sort(arr,5);
    printf("\nAfter the swapping array!\n");
    for(int i=0;i<5;i++)
    {
        printf("%4d",arr[i]);
    }


}

int bubble_sort(int arr[],int size)
{
    for(int position=0;position<size;position++)
    {
        for(int sel_pos = position+1;sel_pos<size-1;sel_pos++)
        {
            int temp;
            if(position > sel_pos)
            temp = position;
            position = sel_pos;
            sel_pos = temp;

        }
    }
}