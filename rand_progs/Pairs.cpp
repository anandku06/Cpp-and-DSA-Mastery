/*
Pairs used to store a pair or two values together in a single variable.
Part of Utility Library.
Datatype.
*/


#include <iostream>
using namespace std;

int main()
{
    pair<int, int> p = {1 , 3}; // basic syntax: pair<datatype, datatype> var_name = {values};


    cout << p.first << " " << p.second << endl; // 1 3
    // to access the values use dot notation
    // each value is given first and second acc to their position like 
    // first corresponds to first value and second for the second value

    pair<int , pair<int , int>> pt = {1,{3,4}};
    // nesting of pairs is also done when to store more than two values 
    // here inside one pair another pair is used so two braces

    cout << pt.first << endl; // 1
    cout << pt.second.first << " " << pt.second.second; //3 4
    // just like accessing values from a 2D matrix: second's first, second's second
    // can't access the whole pair
    // cout << pt.second; throws an error

    pair <int ,int> arr[] = {{1,2},{3,4},{5,6}};
    // used to define arrays of pairs
    // each pairs inside the array is it's single element
    // indexing used to access each pair and pairs value using dot first or second

    cout << endl << arr[1].first << " " << arr[2].second;

    return 0;
}