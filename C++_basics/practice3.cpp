/*exercice 4:
    "Using struct Student { name, grade }, // look in localHeaders file
    write a function that sorts students by grade (ascending).// DONE
    Use pointers or references."
    "Dynamically allocate N students, input their data,
    and write a function to search by name and return grade."
*/

#include <iostream>
#include <cstring>
#include "localHeaders.h" // the struct and the functions used located here

using namespace std;


int main() {
    
    Students *StudentArray = new Students[6]; // dinamically allocate memory of  3 Students array

    // array to store data
    string students_names[] = {StudentArray[0].name, StudentArray[0].name, StudentArray[0].name, StudentArray[0].name, StudentArray[0].name, StudentArray[0].name};
    float students_grades[] = {StudentArray[0].grade, StudentArray[0].grade, StudentArray[0].grade, StudentArray[0].grade, StudentArray[0].grade, StudentArray[0].grade};

    // initialize names and grades arrays with values
    students_names[0] = "walid";
    students_names[1] = "khalid";
    students_names[2] = "afrae";
    students_names[3] = "amir";
    students_names[4] = "hicham";
    students_names[5] = "yahya";
    students_grades[0] = 18.5;
    students_grades[1] = 15.4;
    students_grades[2] = 12.5;
    students_grades[3] = 16.5;
    students_grades[4] = 15.3;
    students_grades[5] = 11.5;
    
    // print array elements
    for (int i = 0; i < 6; i++) {
        cout << students_names[i] << ", ";
        cout << students_grades[i] << endl;
    }
    
    // start using sort algorithm in sort_students function
    cout << "we using sort now" << endl;
   
    float &refer = students_grades[0]; // create reference to the first element in the array

    sorts_students(&refer, 6); // call the sort function -> first argument: access adress of the first element in the grades array
                               //                        ->  second : the size
    
    // print the element after sort
    for (int i = 0; i < 6; i++) {
        cout << students_names[i] << ", ";
        cout << students_grades[i] << endl;
    }
    
    
    
    
    
    delete StudentArray;

}

/**
 * sorts_students - sorts students by grade (ascending).
 * @param: pointer to student object in students struct
 * @param: size of student to sort
 * @return:  (void) 
 *      usecase: sort_student(arrayOfgrades, size)
 */
void sorts_students(float *grades, int size) { // pass pointer to the first element in the array
    
    /*
    // sort values ascending: (using sort algorithm)
        - bubble sort: repeatedly swaps adjacent items if they're in wrong order
        - insertion sort: builds the sorted list one item at a time
                          inserting each new item into its correct spot
        - selection sort: finds the smallest item and moves it to the front
                          repeating for each position
     */
    
     // sort using bubble sort algorithm
    for (int i = 0; i < size - 1; i++) // first indicateur
    {
        for (int j = 0; j < size - i - 1; j++) // second indicateur
        {
            if (grades[j] > grades[j + 1]) {
                float temp = grades[j];               
                grades[j] = grades[j + 1];
                grades[j + 1] = temp; // 
            }
        } 

    }
}

//  int search_by_name() {
    
    
    
//     return;
//  }
