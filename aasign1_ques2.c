//2. Modify selection sort, bubble sort and insertion sort functions to return number of passes and number of comparisons and print both in main function.
#include<stdio.h>
#define SIZE 5
void selection_sot(int arr[]);
void bubble_sort(int arr[]);
void display(int arr[]);

int main()
{
    int arr[SIZE];
    int data;
    printf("0.exit\n1.selection_sort\n2.bubble_sort\n");
    case 0: exit(0);
    case 1:
            printf("Enter the data:\n");
            scanf("%d",&data);

}

void selection_sot(int arr[])
{
    int sel_pos,pos;
    for(sel_pos ==0;sel_pos<size;sel_pos++)
    {
        for(pos = sel_pos +1;pos<size;pos++)
        {
            int temp;
            temp = arr[sel_pos];
            arr[ar]

        }
    }


}
void bubble_sort(int arr[])
{
    for(int i =0;i<size;i++)
    {
        for(int j =i+1;j<size-1;j++)
        {
            if(arr[i]<arr[j])
            {
                int temp;
                temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
void display(int arr[])
{
    for(int i =0;i<SIZE;i++)
    {
        printf("%4d",arr[i]);
    }
}

