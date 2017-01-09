
// A utility function to swap two elements

#include<iostream>
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
class BinaryHeap
{
	int size;
	int heapspace;
	int *arr;
public:
	BinaryHeap(int n)
	{
		this->size=n;
		this->heapspace=0;
		this->arr=new int(n);
	}
	int left(int index)
	{
		return (index*2+1);
	}
	int right(int index)
	{
		return (index*2+2);
	}
	int parent(int index)
	{
		return (index-1)/2;
	}
	void Insert(int value);
	void DeleteKey(int value);
	void Heapify(int value);
	void DecreaseKey(int index, int value);
	int ExtractMin();
	void show();

};
void BinaryHeap::Insert(int value)
{
	if(this->heapspace<this->size)
	{
		heapspace++;
		arr[heapspace-1]=value;
		int i=heapspace-1;
		while(i>0&&arr[i]<arr[parent(i)])
		{
			swap(&arr[i],&arr[parent(i)]);
			i=parent(i);
		}
	}
	return;
}
int BinaryHeap::ExtractMin()
{
	if(heapspace==0)
		return -1;
	if(heapspace==1)
	{
		heapspace--;
		return arr[heapspace-1];

	}
	int min =arr[0];
	arr[0]=arr[heapspace-1];
	heapspace--;
	Heapify(0);
	return min;

}
void BinaryHeap::DecreaseKey(int key,int value)
{
	if(key<this->heapspace)
	{
		arr[key]=arr[key]-value;
		while(key>0&&arr[key]<arr[parent(key)])
		{
			swap(&arr[key],&arr[parent(key)]);
			key=parent(key);
		}
	}
}
void BinaryHeap::Heapify(int value)
{
	if(heapspace==1)
	{
		arr[0]=arr[heapspace-1];
		heapspace--;
		return;
	}
	while(value<heapspace-2)
	{
		int min=0;
		if(arr[value]>arr[left(value )])
			min=left(value);
		if(arr[value]>arr[right(value)])
			min =right(value );
		if(min==value)
			return;
		swap(&arr[value],&arr[min]);
		value=min;
	}
}
void BinaryHeap::show()
{
	for(int i=0;i<heapspace;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
void BinaryHeap::DeleteKey(int value)

{
	DecreaseKey( value, 0);
	ExtractMin();
}
class MinHeap
{
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    // Constructor
    MinHeap(int capacity);
 
    // to heapify a subtree with root at given index
    void MinHeapify(int );
 
    int parent(int i) { return (i-1)/2; }
 
    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }
 
    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }
 
    // to extract the root which is the minimum element
    int extractMin();
 
    // Decreases key value of key at index i to new_val
    void decreaseKey(int i, int new_val);
 
    // Returns the minimum key (key at root) from min heap
    int getMin() { return harr[0]; }
 
    // Deletes a key stored at index i
    void deleteKey(int i);
 
    // Inserts a new key 'k'
    void insertKey(int k);
};
 
// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}
 
// Inserts a new key 'k'
void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }
 
    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
 
    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}
 
// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}
 
// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
 
    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
 
    return root;
}
 
 
// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}
 
// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}
 

int main()
{
    BinaryHeap h(11);
    h.Insert(3);
    h.Insert(2);
    //h.DeleteKey(1);
    h.Insert(15);
    h.Insert(5);
    h.Insert(4);
    h.Insert(45);
    h.show();
   /* cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();*/
    return 0;
}
