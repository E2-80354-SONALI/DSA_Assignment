#include<stdio.h>
#define SIZE 10
typedef struct heap
{
        int arr[SIZE];
        int size;
    }heap_t;
void init_heap(heap_t *h);
void add_heap(heap_t *h,int value);
int delete_heap(heap_t *h);

int main()
{
        heap_t h;
        //int value;
        init_heap(&h);
        int value;
        for(int i=0;i<9;i++)
        {
                printf("Enter elements:");
                scanf("%d",&value);
                add_heap(&h,value);
        
        }
        for(int i=0;i<9;i++)
        delete_heap(&h);
        //add_heap(&h,value);
        printf("heap elements are:");
        for(int i =1;i<9;i++)
        {
                printf("%4d",h.arr[i]);
            }
        return 0;
    
}


void init_heap(heap_t *h)
{
        h->size=0;
    }

void add_heap(heap_t *h,int value)
{
        //increment the heap
        h->size++;
        //add one element into the heap
        h->arr[h->size]=value;
    
    //find parent of the newly added element
        
    int pi = h->size/2;
    int ci = h->size;
        //int pi = h->size/2;
    
    //compare the newly added element with the parent
        while(pi >=1)
        {
            if(h->arr[pi] > h->arr[ci])
          break;
        //if the child is greater than the paren then
    
    int temp;
        temp = h->arr[pi];
        h->arr[pi] = h->arr[ci];
        h->arr[ci] = temp;
    
    //update the newly added element into the array
        ci = pi;
        pi = pi/2;
        }
    }
int delete_heap(heap_t *h)
{    //first put the first element in the temp value
    //change the first and last elements in the heap
        int max = h->arr[1];
        //swap the first and last element in the stack
        h->arr[1]=h->arr[h->size];
        h->arr[h->size]=max;
        //decrease the heap
        h->size--;
        //find the i;ndex of the child node
        int ci = 1 * 2;
        
        while(ci <= h->size)
        {
        //find the index of the parent
        int pi = ci/2;
        //if ci+1 is > ci
        if(ci +1 <= h->size && h->arr[ci+1] > h->arr[ci])
         ci = ci+1;
        //if parent is the greater than the child then the
        if(h->arr[pi] > h->arr[ci])
        break;
        //if ci + 1 is greater than the ci then we need to swap
        int temp = h->arr[ci];
        h->arr[ci]=h->arr[pi];
        h->arr[pi]=temp;
        //u
        ci = ci*2;
        }
    return max;
}



    
