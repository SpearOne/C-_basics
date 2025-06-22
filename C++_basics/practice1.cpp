/*
    this is a serie of exercices and answers to practice C++ concepts, 
    - reverse array 
    - rotate array
    - swap values (using pass by pointer parametre)
*/



#include <iostream>
#include "localHeaders.h"



using namespace std;



int main() {
    
    // array declaration and initialisation of points values
    float values[10] = {10.1, 20.2, 30.3, 40.4, 50.5, 60.6, 70.7, 80.8, 90.9, 100.45};
    
    cout << "\n---------------array operations--------------\n";
    cout << "               ----------------               \n";
    cout << "{10.1, 20.2, 30.3, 40.4, 50.5, 60.6, 70.7, 80.8, 90.9, 100.45}";
    cout << "\n\n-----> reverse operation\n\n";
    
    // call function to reverse array
    cout << "values after reverse\n";
    reverse(values);
    for (int i = 0; i <= 9; i++)
    {
        cout << values[i] << ", ";
    }
    
    // try to reverse using pointers
    reversebypointers(values, 10);
    
    // display array after reverse using the pointer so it will be the default sort
    cout << "\n\nvalues after reverse using pointer\n(while we already reverse it above it will return to default sort): " << endl;
    for (int i = 0; i <= 9; i++)
    {
        cout << values[i] << ", ";
    }
    
    // call function to rorate array - shifting opeartion
    rotate_right(10, values);
    
    // display array after shift values to right by one place
    cout << "\n\nvalues after rotate(shifting values by one place to the right): " << endl;
    for (int i = 0; i <= 9; i++)
    {
        cout << values[i] << ", ";
    }
    
    // variables to swap
    float firsValue = 10.10;
    float secondValue = 20.10;
    
    // print values before swapping
    cout << "\n\n-------------- pointer operations ----------------: " << endl;
    cout << "\nbefore swap:\nfirst value: " << firsValue << "\nsecond value: " <<  secondValue << endl;
    
    swap_floats(&firsValue, &secondValue); // call function to swap arguments
    // print values after swapping
    cout << "after swap:\nfirst value: " << firsValue << "\nsecond value: " <<  secondValue << endl;
    
    return 0;    
}

/* Exercise 1: Reverse Array
    ---------
    Write a function named "reverse" that takes an array of floating point values
    as its argument and returns the reversed order of those values
*/
/** reverse - reverse given array elements
 * @param: array of float points 
* Return: reversed order 
*/
void reverse(float arr[10]) {
    // loop trought given array size / 2
    for (int i = 0; i < 5; ++i)
    {   
        // swap the first value with the last one and so on
        float temp = arr[i]; // take the first value to temp
        arr[i] = arr[9 - i]; // take the last value to the the first position
        arr[9 - i] = temp; // take the temp to the last value
    }
    return;
}

/** reversebypointers - reverse given array using pointers
 * @param: pointer to array elements
 * @param: size of the array
 * return: (void)
 */
void reversebypointers(float *arr, int size) {

    // loop trought array size / 2
    for (int i = 0; i < size/2; ++i)
    {   
        // swap the first value with the last one and so on
        float temp = arr[i]; // take the first value to temp
        arr[i] = arr[size - 1 - i]; // take the last value to the the first position
        arr[size - 1 - i] = temp; // take the temp to the last value
    }
    return;
}


/* Exercise 2: Rotate Right Array
----------
Write a function named "rotate_right"
that takes two arguments, an integer representing the number of cells in the array,
and an array of floating point values. The function should shift each cell one place
to the right within the specified range.
*/
/** rotate_right - shift each cell one place to the right within specified rang
 * @param: integer numbers of cells
 * @param: array of floating point values
 * return: (void)
 * */
void rotate_right(int cellsNumber, float arr[]) {

   for (int i = cellsNumber; i > 0; i--)
   {
        // swap the current element with the previous element 
        int temp  = arr[i];
        arr[i] = arr[i - 1];
        arr[i - 1] = temp;

   }
   

}

/* Exercise 3: Swap Floats 
----------
Write a function named "swap_floats" that takes two float arguments
as its parameters and swaps their values without using any additional variables
or data structures.
*/
/** swap_floats - swap to values using pointers
 * @param: first float value
 * @param: second float value
 * return: (void)
*/
void swap_floats(float *a, float *b) {
    *a = *a + *b; // the total to a
    *b = *a - *b; // the difference to b (a has new value the total)
    *a = *a - *b; // the diff again to a (b has new value the diff)

    return;
}