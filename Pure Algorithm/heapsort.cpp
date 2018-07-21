//Given an array , create a heap and apply Heap sort algorithm to sort the array.
#include <iostream>
#include<cmath>
#include<cstdio>

#define PARENT(i) ((i-1) / 2)
#define LINE_WIDTH 100

using namespace std;

/*Printing the tree looks like actual tree*/
void Print(int NUM_NODES,int tree[])
{
    int print_pos[NUM_NODES];
    int i, j, k, pos, x=1, level=0;

    print_pos[0] = 0;
    for(i=0,j=1; i<NUM_NODES; i++,j++) {
        pos = print_pos[PARENT(i)] + (i%2?-1:1)*(LINE_WIDTH/(pow(2,level+1))+1);

        for (k=0; k<pos-x; k++) printf("%c",i==0||i%2?' ':'-');
        if(i<NUM_NODES-1)printf("%d",tree[i+1]);

        print_pos[i] = x = pos+1;
        if (j==pow(2,level)) {
            printf("\n");
            level++;
            x = 1;
            j = 0;
        }
    }
}

/* A function to heapify the array.*/
void MaxHeapify(int a[], int i, int n)
{
	int j, temp;
	temp = a[i];
	j = 2*i;

 	while (j <= n)
	{
		if (j < n && a[j+1] > a[j])
		j = j+1;
		// Break if parent value is already greater than child value.
		if (temp > a[j])
			break;
		// Switching value with the parent node if temp < a[j].
		else if (temp <= a[j])
		{
			a[j/2] = a[j];
			j = 2*j;
		}
	}
	a[j/2] = temp;
	return;
}
void HeapSort(int a[], int n)
{
	int i, temp;
	for (i = n; i >= 2; i--)
	{
		// Storing maximum value at the end.
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		// Building max heap of remaining element.
		MaxHeapify(a, 1, i - 1);
	}
}
void Build_MaxHeap(int a[], int n)
{
	int i;
	for(i = n/2; i >= 1; i--)
		MaxHeapify(a, i, n);
}
int main()
{
    while(1){
        int n, i;
        cout<<"\nEnter the number of data element to be sorted: ";
        cin>>n;
        n++;
        int arr[n];
        for(i = 1; i < n; i++)
        {
            cout<<"Enter element "<<i<<": ";
            cin>>arr[i];
        }

        //printing the binary tree of given array;
        printf("\n\n\nThe binary tree of given array :\n\n\n");
        Print(n,arr);

        // Building max heap.
        Build_MaxHeap(arr, n-1);

        //printing the tree after max heaping
        printf("\n\n\nThe tree after building Max Heap :\n\n\n");
        Print(n,arr);

        //sorting after building max heap
        HeapSort(arr, n-1);

        // Printing the sorted data.
        cout<<"\n\n\nSorted Data ";

        for (i = 1; i < n; i++)
            cout<<"  "<<arr[i];
        cout<<endl<<endl<<endl;

        //printing the sorted binary tree
        printf("The binary tree after completing heap-sort :\n\n\n");
        Print(n,arr);
        printf("\n\n");
    }
    return 0;
}
