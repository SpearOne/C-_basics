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
    
    Students *StudentArray = new Students[6]; // dinamically allocate memory of 6 Students array

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
    // for (int i = 0; i < 6; i++) {
    //     cout << students_names[i] << ", ";
    //     cout << students_grades[i] << endl;
    // }
    
    // start using sort algorithm in sort_students function
    // cout << "we using sort now" << endl;
   
    float &referG = students_grades[0]; // create reference to the first element in the array
    string &referN = students_names[0];

    sorts_students(&referN, &referG, 6); // call the sort function -> first argument: access adress of the first element in the grades array
                               //                        ->  second : the size
    
    // print the element after sort
    // for (int i = 0; i < 6; i++) {
    //     cout << students_names[i] << ", ";
    //     cout << students_grades[i] << endl;
    // }

    // ask user for name to search
    string name;
    cout << "enter the name: " << endl;
    cin >> name;

    // use search function
    searchByNames(&referN, &referG, name);    
    
    // free the allocated memory
    delete StudentArray;

}

/**
 * sorts_students - sorts students by grade (ascending).
 * @param: pointer to first element in array (names)
 * @param: pointer to first element in array (grades)
 * @param: number of students
 * @return:  (void) 
 *      usecase: sort_student(array of names, array of grades, size)
 */
void sorts_students(string *names, float *grades, int size) { // pass pointer to the first element in the array
    
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
            if (grades[j] > grades[j + 1]) { // if the first values greater then the second swap
                float tempG = grades[j]; // temp var for grades
                string tempN = names[j];  // temp var for names
                grades[j] = grades[j + 1];
                names[j] = names[j + 1];
                grades[j + 1] = tempG;
                names[j + 1] = tempN; // 
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
