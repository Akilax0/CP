/**
 * 
 * Topic : std::array
 * 
 * 1. std::array is a container fixed size
 * 2. arraysize needed at compile time
 * 3. assign by value is actually by value
 * 4.  Access elements: 
 *          a. at() -> throws out of bound
 *          b. []
 *          c. front()
 *          d. back()
 *          e.data() -> return the pointer of array
 * 
*/

#include<iostream>
#include<array>
using namespace std;

int main(){
    //declare
    array<int,5> myarray;

    //init
    array<int,5> myarray = {1,2,3,4,5};
    // uniform init
    array<int,5> myarray2 {1,2,3,4,5};

    // assign using init list
    array<int,5> myarray;
    myarray = {1,2,3,4,5};

}