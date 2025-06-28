/*
    this is a serie of exercices and answers to practice C++ concepts, 
    - pass-by-value, reference, pointer
    - array operations
    - struct opeartions
*/

#include <iostream>
#include <cstring>
#include "localHeaders.h" // hearder file contain functions and struct declarations.

using namespace std;

int main() {

    Books *booksArray = new Books[4]; // dynamically allocate array of 4 books(allocate memory)

    // initialize arrays to hold data coming
    int book_ids[] = {booksArray[0].book_id, booksArray[0].book_id, booksArray[0].book_id, booksArray[0].book_id};
    char *book_titls[] = {booksArray[0].book_title, booksArray[0].book_title, booksArray[0].book_title, booksArray[0].book_title};
    int book_prices[] = {booksArray[0].book_price, booksArray[0].book_price, booksArray[0].book_price, booksArray[0].book_price};
    
    // add books data to created objects using function
    addBook(booksArray[0], 1, "\"sahih lbokhari\"", 100);
    addBook(booksArray[1], 2, "\"sahih moslim\"", 200);
    addBook(booksArray[2], 3, "\"tafsir ljalalyn\"", 300);
    addBook(booksArray[3], 4, "\"sira nabawiya\"", 400);
    
    // set pointers to the first element of the arrays
    int *ptids = &book_ids[0];
    int *ptprice = &book_prices[0];

    cout << "\ndisplaying all existing books: \n" << endl;
    displaybooksArray(booksArray, 4); // display all books data using array of books objects
    delete[] booksArray; // free allocated memory for books array
    
    updatePrice(&booksArray[1], 2, 1000);
    cout << "updating prices process\nnow price of:" << booksArray[1].book_title << " is " << booksArray[1].book_price << " DH";

}

/* Exercice '1'
"Write three functions to double a value using: 
a) pass-by-value, 
b) pass-by-reference, 
c) pass-by-pointer. 
Test them on the same variable.",

*/
void DoubleByVaues(int a) {
    int result = a * 2;
    cout << "im here by value: " << result;
}

void DoubleByPointers(int *a) {
    int result = *a * 2;
    cout << "im here by pointer: " << result;
}

void DoubleByReference(int &a) {
    int result = a * 2;
    cout << "im here by reference: " << result;
}

/* Exercice '2' 
"Create an int array of 5 elements, then use pointer arithmetic to:
a) print all elements 
b) sum all elements 
c) double each element.",
*/
void arrOperations() {
    int arr[5] = {34, 78, 45, 34, 98};
    int *p;
    
    p = arr;
    int sum = 0;
    
    for (int i = 0; i < 5; i++)
    {
        cout << *p  << ", ";
        sum = sum + *p;
        p++;
    }
    
    cout << "\nsum of values: " << sum;
    
    p = arr; // intialize pointer to the first element
    
    cout << "\ndouble of values: ";
    for (int i = 0; i < 5; i++)
    {
        int db = *p * 2;
        cout << db << ", ";
        p++;
    }
}

/*  Exercice '3'

"struct 'Book' with id, title, and price.
function to update price using pointer.
Use dynamically allocated array of 3 books (update: look in main).",
*/
// function to add book by arguments. ex use:look main
void addBook(Books &rBook, int id, const char *title, int price) {
    // initialize book data into struct data structure
    rBook.book_id = id; //  entred id to struct 
    rBook.book_price = price; // entred price to struct 
    strcpy(rBook.book_title, title); // entred title to struct
    
}

/** updatePrice - updating book price
 * @param: reference to the book object in Books struct
 * @param: book id
 * @param: new choosen price
 * 
 * @return: (void)
 */
void updatePrice(Books *booksArray, int bookId, int newPrice) {
    
    int bookIdToCheck = booksArray->book_id; // move id value to new var
    int *pt = &newPrice; // pointer to new price

    if (bookId == bookIdToCheck) { // check id if existe
        // cout << "updating price...." << endl;
        booksArray->book_price = *pt; // derefrencing pointer and update price based on the entry
        // cout << "new price of: " << booksArray->book_title << ": " << booksArray->book_price << " DH" << endl; // print confirmation
    } else {    
        cout << "cant find this id" << endl; // if id dont existe
    }    
    return;  
}

// display books by accesing data arrays (id, title, price)
void displayAllBooks(int *bookIds[], char *bookTitle[], int *bookPrice[]) {

    int *ptids = bookIds[0]; // pointer to the first element in ids array
    int *ptprice = bookPrice[0]; // pointer to the first element in prices array
    // output books data 
    for (int i= 0; i < 4; i++) {
        cout << "book[0" << i + 1 << "] data: " << endl;
        cout << "initial book id: " << *ptids << endl; // derefrence and print the id value 
        cout << "initial book price: " << bookTitle[i] << " DH" << endl; // print title value
        cout << "initial book title: " << *ptprice << endl; // derefrence and print the price value
        
        ptids++; // move to the next address in ids array
        ptprice++; // move to the next address in price array
    }
}

/** displaybooksArray - display books data using array of Books objects
 * @param: pointer to the array of Books objects
 * @param: size of the array
 * @return: (void)
 */
void displaybooksArray(Books *booksArray, int size) {
    // loop throught books array and print elements
    for (int i = 0; i < size; i++) {
        // cout << "book[0" << i + 1 << "] data: " << endl; 
        cout << "book id: " << booksArray[i].book_id << endl; // print book id
        cout << "book title: " << booksArray[i].book_title << endl; // print book title
        cout << "book price: " << booksArray[i].book_price << " DH" << endl; // print book price
        cout << " --------------------------- \n";
    }
}

