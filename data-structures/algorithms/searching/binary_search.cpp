// Implementation of Binary Search

#include <iostream>
#include "binary_search.hpp"

using std::cout;
using std::endl;

int binary_search(int inp_arr[], int start_index, int end_index, int elem)
{
    int pivot_index = ((end_index - start_index)/2) + start_index;
    int elem_index = -1;
    if(elem == inp_arr[pivot_index])
    {
        elem_index = pivot_index;
        return elem_index;
    }
    else if(start_index == end_index)
    {
        cout << endl << "Element doesnt exists";
        return elem_index;
    }
    else if(elem > inp_arr[pivot_index])
    {
        binary_search(inp_arr,pivot_index+1,end_index,elem);
    }
    else if(elem < inp_arr[pivot_index])
    {
        binary_search(inp_arr,start_index,pivot_index-1,elem);
    }
}

// Comment the below part of code since this code is used as a Library

// int main()
// {
//     int inp_arr[] = {1,2,3,4,5,6,7};
//     int inp_arr_size = sizeof(inp_arr)/sizeof(inp_arr[0]);
//     int search_elem = 80;

//     int search_elem_index = binary_search(inp_arr,0,inp_arr_size-1,search_elem);
//     cout << endl << search_elem_index;
// }