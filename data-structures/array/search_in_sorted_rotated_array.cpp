// https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/

#include <iostream>

// Provide -I<include_path_dir> to gcc while compiling
// Provide -L<library_path_dir> and -l<library_name(excluding prefix 'lib' & suffix '.a')> to gcc while linking
#include "binary_search.hpp"

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

void find_elem_index(int inp_arr[], int size, int elem, const int &pivot_index)
{
    int elem_index = -1;
    if(pivot_index == -1)
    {
        elem_index = binary_search(inp_arr,0,size-1,elem);
    }
    else if(elem > inp_arr[0])
    {
        elem_index = binary_search(inp_arr,0,pivot_index,elem);
    }
    else
    {
        elem_index = binary_search(inp_arr,pivot_index+1,size-1,elem);
    }
    if(elem_index != -1)
    {
        cout << endl << "Element: " << elem << " exists at index - " << elem_index;
    }
}

int main()
{
    // int inp_array[] = {7,1,2,3,4,5,6};
    int inp_array[] = {3,4,5,6,7,1,2};
    int elem_to_search = 2;
    int size = sizeof(inp_array)/sizeof(inp_array[0]);
    int pivot_index = find_pivot_index(inp_array,0,size-1);

    find_elem_index(inp_array,size,elem_to_search,pivot_index);
}