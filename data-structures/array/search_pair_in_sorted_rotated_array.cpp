// https://www.geeksforgeeks.org/given-a-sorted-and-rotated-array-find-if-there-is-a-pair-with-a-given-sum/

#include <iostream>

using std::cout;
using std::endl;

int find_pivot_index(int inp_arr[], int start_index, int end_index)
{
    if(end_index < start_index)
        return -1;
    if(start_index == end_index)
        return start_index;

    int pivot_index = ((end_index - start_index)/2) + start_index;
    if(inp_arr[pivot_index] > inp_arr[pivot_index+1])
    {
        return pivot_index;
    }
    else if(inp_arr[pivot_index] < inp_arr[pivot_index-1])
    {
        return pivot_index-1;
    }

    if(inp_arr[start_index] >= inp_arr[pivot_index])
    {
        return find_pivot_index(inp_arr,start_index,pivot_index-1);
    }
    else
    {
        return find_pivot_index(inp_arr,pivot_index+1,end_index);
    }
}

void find_pair_of_nums(int *arr,int pivot_index, int size, int sum)
{
    int left_ptr = (pivot_index + 1) % size;
    int right_ptr = pivot_index % size;

    while(left_ptr != right_ptr)
    {
        if(left_ptr > size-1)
        {
            left_ptr = 0;
        }
        if(right_ptr < 0)
        {
            right_ptr = size - 1;
        }
        int tmp_sum = arr[left_ptr]+arr[right_ptr];
        if(tmp_sum == sum)
        {
            cout << endl << "Pair found " << arr[left_ptr] << " " << arr[right_ptr];
            return;
        }
        else if(tmp_sum > sum)
        {
            right_ptr--;
        }
        else if(tmp_sum < sum)
        {
            left_ptr++;
        }
    }
    cout << endl << "No pair found";
}

int main()
{
    int arr[] = {11, 15, 26, 38, 9, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int elem = 45;

    int pivot_index = find_pivot_index(arr,0,size-1);
    cout << endl << pivot_index;

    find_pair_of_nums(arr,pivot_index,size,elem);
}
