/**
 * "Write a function that calculates the factorial
    of a number using pass-by-reference to return result.",
 */

 #include "localHeaders.h"
 #include <iostream>

using namespace std;

int main() {
    int number = 11;
    // Factoial(number);
    int arr[number] = {5, 2, 3, 4, 5, 6, 7, 3, 3, 6, 5};
    // int *p = arr;
    // for (int i = 0; i < number; i ++) {
    //     cout << arr[i] << endl; 
    // }
    // reverseArray(arr, number);
//     for (int i = 0; i < number; i ++) {
//         cout << arr[i] << endl; 
//     }
    // countDuplicate(arr, number);
    Rectangle re;
    re.length = 30;
    re.width = 25;
    calculateAreaAndPerimetre(re);
}


int Factoial(int &number) { //ex:s 5! = 5 * 4 * 3 * 2 * 1
    
    int result = 1; // avoid 0 because multiplication
    while (number > 0)
    {  
        
        result = result * number;
        number--;
        

    }
    cout << "result is: " << result;
    return result;
    
}

/** exercice 6:
 "Write a function that reverses an array using pointers only.",
 *
 */

void reverseArray(int *arr, int size) {

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }
}

/**
 *   "Implement a function that counts how many times a number
     appears in an array.",
 */

void countDuplicate(int *arr, int size) {
    int numberTocheck;
    cout << "wich number you want to check: ";
    cin >> numberTocheck; 

    int count = 0;
    for (int i = 0; i < size; i++) {
        
        if (arr[i] == numberTocheck) {
            count++;
        }
    }
    cout << numberTocheck << ": appear [" << count << "] times."; 
    
}

/**
 * "Write a program that uses struct to represent a rectangle
     and calculate area and perimeter.",
 */

 int calculateAreaAndPerimetre(Rectangle rectangle1) {

    int area = rectangle1.length * rectangle1.width;
    int perimetre = (rectangle1.length + rectangle1.width) * 2;
    cout << "- area = " << area << endl;
    cout << "- perimertre = " << perimetre;
    return area;

 }