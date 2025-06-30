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
    
    int numberOfStudents; // to store students number
    // ask user to add how many students
    cout << "Enter number of studets: ";
    // read data
    cin >> numberOfStudents;

    // array to store data
    Students *StudentArray = new Students[numberOfStudents]; // dinamically allocate memory of n Students array

    // read user input data  
    int i = 0;
    while (i < numberOfStudents)
    {    
        cout << "Enter Student name and grade(ex: john 13.4): ";
        cin >> StudentArray[i].name; // read student name
        cin >> StudentArray[i].grade;  // read student grade     
        i++;
    }
    
    // print students data
    printStudents(StudentArray, numberOfStudents);

    // start using sort algorithm in sort_students function
    cout << "--------------------\nwe using sort now" << endl;

    // call sort function and give arguments
    sorts_students(StudentArray, numberOfStudents);                     
    
    // print students data sorted 
    printStudents(StudentArray, numberOfStudents);


    // ask user for name to search
    string name;
    cout << "enter a name: " << endl;
    cin >> name;

    // use search function
    searchByNames(StudentArray, name);    
    
    // free the allocated memory
    delete StudentArray;
    return 0;

}

/**
 * sorts_students - sorts students by grade (ascending).
 * @param: pointer to student struct 
 * @param: number of students
 * @return:  (void) 
 *      usecase: sort_student(array of names, array of grades, size)
 */
void sorts_students(Students* arr, int size) { // pass pointer to the first element in the array
    
    /* fast explain - sort algorithm
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
        for (int j = 0; j < size - i - 1; j++) {
            
            if (arr[j].grade > arr[j + 1].grade) { // if the first values greater then the second swap
                
                float tempG = arr[j].grade;
                string tempN = arr[j].name;
                
                arr[j].grade = arr[j + 1].grade;
                arr[j].name = arr[j + 1].name;
                
                arr[j + 1].grade = tempG;
                arr[j + 1].name = tempN;
            }

        }
    }
}


/** searchByNames - search by name and return grade
 * @param: pointer to student struct 
 * @param: name of student to search
 * @return: corresonding grade if success
 *          "Not found" (-1) if fail 
 *      usecase: sort_student(struct pointer, name to search)
 */
float searchByNames(Students *arr, string name) {
    
    // loop trought names into student struct
    for (int i = 0; i < 6; i++) { 
        if (name == arr[i].name) { // if founded
            cout << "name founded: " << arr[i].name << " - " << "his grade: " << arr[i].grade; // print name and grade founded
            return arr[i].grade; // return grade
        }
    }
    if (name != arr->name) { // if name not founded
        cout << "not found"; 
    }
    return -1;
}


void printStudents(Students *studentData, int size) {
    cout << "-------------------\nPrinting data...\n";
    for (int i = 0; i < size; i++) {
        cout << studentData[i].name << ", " << studentData[i].grade << endl; 
    }
}