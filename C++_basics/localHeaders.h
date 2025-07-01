// define header constant
#ifndef HEADERS_H
#define HEADERS_H


#include <string>
// using namespace std;



// declare book struct data structure
struct Books
{
    char book_title[20];
    int book_price;
    int book_id;
};


// declare used functions

void reverse(float arr[10]);
void reversebypointers(float *arr, int size);
void rotate_right(int cellsNumber, float arr[]);
void swap_floats(float *a, float *b);
// ---------------------------------------- //
void DoubleByVaues(int a);
void DoubleByPointers(int *a);
void DoubleByReference(int &a);
void arrOperations();
// ---------------------------- //
void addBook(Books &rBook, int id, const char *title, int price);
void updatePrice(Books *rBook, int bookId, int newPrice);
void displayAllBooks(int *bookIds[], char *bookTitle[], int *bookPrice[]);
void displaybooksArray(Books *booksArray, int size);
// ------------------------------------------- //

struct Students {
    std::string name;
    float grade;
};

void sorts_students(Students* arr, int size);
float searchByNames(Students *arr, std::string name);
void printStudents(Students *studentData, int size);


// ------------------------------------------
int Factoial(int &number);
// ------------------------------------
void reverseArray(int *arr, int size);
// --------------------------------
void countDuplicate(int *arr, int size);
// ----------------------------------
struct Rectangle
{
    int length;
    int width;
};

int calculateAreaAndPerimetre(Rectangle rectangle1);







#endif

