#include <iostream>

using namespace std;

void insertsort(int nums[],int n)
{
    // original insert sort
    int i,j;
    int key;
    for(i = 1;i<n;++i)
    {
        key = nums[i];
        for(j=i-1;j>=0 && key < nums[j];--j)
            nums[j+1] = nums[j];
        nums[j+1] = key;
    }
}
void insertsort2(int nums[],int n)
{
    // advance insert sort
    int i,j;
    int key;
    for(i =1;i<n;++i)
    {
        key = nums[i];
        if(key < nums[i-1])
        {
            for(j=i-1;j>=0 && key < nums[j];--j)
                nums[j+1] = nums[j];
            nums[j+1] = key;
        }
    }
}

void binaryinsertsort(int nums[],int n)
{
    // binary insert sort
    int i,j,low,high,mid;
    int key;
    for(int i=1;i<n;++i)
    {
        key = nums[i];
        low = 0;high = i-1;
        while(low <= high)
        {
            mid = (low+high)/2;
            if(nums[mid] > key)
                high = mid-1;
            else
                low = mid +1;
        }
        for(j =i-1;j>high;--j)
            nums[j+1] = nums[j];
        nums[j+1] = key;
    }
}
void swap(int &a,int &b)
{
    a = a+b;
    b = a-b;
    a = a-b;
}
void bubblesort(int nums[],int n)
{
    // original bubble sort
    bool flag = false;
    for(int i=0;i<n;i++)
    {
        flag = false;
        for(int j = 1;j<n-i;++j)
        {
            if(nums[j] < nums[j-1])
            {
                swap(nums[j],nums[j-1]);
                flag = true;
            }
        }
        if(!flag)
            break;
    }
}
int partition(int nums[],int low,int high)
{
    int key = nums[low];
    while(low < high)
    {
        while(low < high && key <= nums[high]) -- high;
        nums[low] = nums[high];
        while(low < high && key >= nums[low]) ++low;
        nums[high] = nums[low];
    }
    nums[low] = key;
    return low;
}

void QuickSort(int nums[],int low,int high)
{
    // quick sort
    if(low < high)
    {
        int pivotloc = partition(nums,low,high);
        QuickSort(nums,low,pivotloc-1);;
        QuickSort(nums,pivotloc+1,high);
    }
}
void selectsort(int nums[],int n)
{
    // simple select sort
    int minidx;
    for(int i=0;i<n;i++)
    {
        minidx = i;
        for(int j=i;j<n;++j)
        {
            if(nums[minidx] > nums[j])
                minidx = j;
        }
        if(minidx != i)
            swap(nums[minidx],nums[i]);
    }
}

int main()
{
    int nums[] = {5,3,7,9,23,3,1,6};
    int len = sizeof(nums)/sizeof(int);
    for(int i =0;i<len;++i)
        cout<<nums[i]<<" ";
    cout<<endl;
    // insert sort
//    insertsort(nums,len);
//    insertsort2(nums,len);
//    binaryinsertsort(nums,len);
//    bubblesort(nums,len);
    QuickSort(nums,0,len-1);
    for(int i =0;i<len;++i)
        cout<<nums[i]<<" ";
    cout<<endl;
    return 0;
}

