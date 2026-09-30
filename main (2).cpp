/////////////////////////////////////////////////////////////////////
// Name: Miguel Puga
// Date: 9-29-26
// Class: CSCI 1470.0X
// Semester: Fall 2026
// CSCI 1470 Instructor: Dr. Jonatan Reyes
// Program Description: books keeping (keeps count of how many books are checked out)
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int TOTAL_BOOKS_BORROWED = 0;

int generateUserID();
void borrowBook(int &books);
void log(int id, int books);
void report();

int main()
{
    int uid, bookCount;
    
    // Simulating book checkouts for a user
    bookCount = 0;
    uid = generateUserID(); 
    borrowBook(bookCount);
    borrowBook(bookCount);
    borrowBook(bookCount);
    borrowBook(bookCount);
    borrowBook(bookCount);
    log(uid, bookCount);
    
    // Simulating book checkouts for another user
    bookCount = 0;
    uid = generateUserID(); 
    borrowBook(bookCount);
    log(uid, bookCount);
    
    // Simulating book checkouts for another user
    bookCount = 0;
    uid = generateUserID(); 
    borrowBook(bookCount);
    borrowBook(bookCount);
    log(uid, bookCount);
    
    // Simulating book checkouts for another user
    bookCount = 0;
    uid = generateUserID(); 
    borrowBook(bookCount);
    borrowBook(bookCount);
    log(uid, bookCount); 
    
    // Simulating book checkouts for another user
    bookCount = 0;
    uid = generateUserID(); 
    borrowBook(bookCount);
    borrowBook(bookCount);
    borrowBook(bookCount);
    borrowBook(bookCount);
    borrowBook(bookCount);
    borrowBook(bookCount);
    borrowBook(bookCount);
    log(uid, bookCount);
    
    // Reporting end-of-day transactions
    report();

    return 0;
}

int generateUserID()
{
    static int id = 1001;
    return id++;
}

void borrowBook(int &books)
{
    int input = 0;
    cout<< "Enter number of books to borrow: ";
    cin >> input;

    cin.ignore(1000, '\n');
  
    books += input;
    TOTAL_BOOKS_BORROWED += input;
}
void log(int id, int books)
{
    ofstream outFile ("log.txt", ios::app);
    if(outFile.is_open())
    {
        outFile << "User id: " << setfill('.') << setw(13) << id << "\n";
        outFile << "Books Borrowed: " << setfill('.') << setw(6) << books << "\n\n";
        outFile.close();    
    }
    
}
void report()
{
    cout << "A total of " << TOTAL_BOOKS_BORROWED << " items were checked out today."<< endl;
    ofstream outFile("log.txt", ios::app);
    if(outFile.is_open())
    {
        outFile << "A total of " << TOTAL_BOOKS_BORROWED << " items were checked out today." << endl;
        outFile.close();
    }
    
}
