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
    
    // ask user to add how many students then their names and grades
    int numberOfStudents; // size of elemnt in the struct
    cout << "Enter number of studets: ";
    cin >> numberOfStudents;

    // array to store data
    Students *StudentArray = new Students[numberOfStudents]; // dinamically allocate memory of n Students array

    
    int i = 0;
    while (i < numberOfStudents)
    {
        
        cout << "Enter Student name and grade: ";
        
        // cout << "Enter Student " << i + 1 << " grade:";
        cin >> StudentArray[i].name; // read student name
        cin >> StudentArray[i].grade;  // read student grade     
        i++;
    }
    

    // print array elements
    // for (i = 0; i < numberOfStudents; i++) {

    //     cout << "Student " << i + 1 << ": " << StudentArray[i].name << ", " << StudentArray[i].grade << endl;    
    // }
    
    
    // start using sort algorithm in sort_students function
    cout << "we using sort now" << endl;
    
    // float &referG = StudentArray[0].grade; // create reference to the first element in the array
    // string &referN = StudentArray[0].name;

    sorts_students(StudentArray, numberOfStudents); // call the sort function 
                         
    
    // print the element after sort
    for (i = 0; i < numberOfStudents; i++) {

        cout << "Student " << i + 1 << ": " << StudentArray[i].name << ", " << StudentArray[i].grade << endl;    
    }
    

    // ask user for name to search
    // string name;
    // cout << "enter the name: " << endl;
    // cin >> name;

    // use search function
    // searchByNames(&referN, &referG, name);    
    
    // free the allocated memory
    delete StudentArray;
    return 0;

}

/**
 * sorts_students - sorts students by grade (ascending).
 * @param: pointer to first element in array (names)
 * @param: pointer to first element in array (grades)
 * @param: number of students
 * @return:  (void) 
 *      usecase: sort_student(array of names, array of grades, size)
 */
void sorts_students(Students* arr, int size) { // pass pointer to the first element in the array
    
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
            if (arr[j].grade > arr[j + 1].grade) { // if the first values greater then the second swap
                
                float tempG = arr[j].grade;
                string tempN = arr[i].name;
                
                arr[j].grade = arr[j + 1].grade;
                arr[i].name = arr[i + 1].name;
                
                arr[j + 1].grade = tempG;
                arr[j + 1].name = tempN; // 
            }
        } 

    }
}
/** searchByNames - search by name and return grade
 * @param: pointer to first element in array (names)
 * @param: pointer to first element in array (grades)
 * @param: name of student to search
 * @return: corresonding grade if success
 *          "Not found" (-1) if fail 
 *      usecase: sort_student(array of names, array of grades, name to search)
 */
float searchByNames(string *names, float *grades, string name) {
    
    float grade; // the corespond grade 
    // hold the name entred
    for (int i = 0; i < 6; i++) { // loop trought names the array
        if (name == names[i]) { // if name founded in the array
            // grade = grades[i]; // put his corresponding grade value in grade var
            cout << "Founded name: " << names[i] << endl << "his grade: " << grades[i]; // print name and grade founded
            return grades[i]; // return gra
        }
    }
    if (name != *names) { // if name not founded
        cout << "not found"; 
    }
    return -1;
}
