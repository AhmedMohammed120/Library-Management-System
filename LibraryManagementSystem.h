/****************************************************************
 FILE DESCRIPTION
----------------------------------------------------------------
*        File     :  LibraryManagementSystem.h
*        Brief    :  Declaration of LibraryCatalog class and related functions.
*        Details  :  This header file contains the declaration of the LibraryCatalog class,
*                    which represents a library catalog. It includes method declarations
*                    for adding books to the catalog, searching for books by author,
*                    and displaying the catalog. Additionally, it declares functions for
*                    checking the validity of book names, dates, and author names.
*
****************************************************************/
#ifndef LIB_SYSTEM_H
#define LIB_SYSTEM_H
/****************************************************************
* INCLUDES
****************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include "Book.h"
#include <limits>

/****************************************************************
*    GLOBAL DATA TYPE AND INSTRUCTIONS Union, Enum & Struct
****************************************************************/
class LibraryCatalog
{
    private: 
    /*Attributes*/
    std::vector<Book> Library_System;
    static unsigned int Number_Of_Books;
    

    public:
    /*Methods*/
  
    /*
      Brief    : Adds a new book to the library.
	  Details  : Adds the provided book object to the library catalog.
	  param[in]: New_Book - The book object to be added.
    */
    void addBook(std::string Book_Name,std::string Author_Name,unsigned int Date);
    
    /*
      Brief    : Searches for books by author name.
	  Details  : Compares the provided author name with the names of 
	             authors of books in the library catalog. Displays 
	             information about the book if a match is found.
	  param[in]: Input_Name - The name of the author to search for.
    */
    void searchByAuthor(std::string Input_Name); 
    
    /*
      Brief    : Displays the catalog of books in the library.
	  Details  : Iterates through the library catalog and displays
	             information about each book.
    */
    void Display_Catogery(void);     

    static void Increment_Books_Counter(void);
};

/****************************************************************
*    GLOBAL CONSTANT MACROS
****************************************************************/

 
/****************************************************************
*    GLOBAL DATA PROTOTYPES
****************************************************************/
/*
      Brief  : Checks if the book name contains valid characters.
	  Details : Checks if the book name contains only alphabets 
	            and spaces. Returns true if valid, false otherwise.
	  param[in]: Book_Name - The name of the book to be checked.
*/
bool Check_Book_Name(std::string Book_Name);

/*
      Brief  : Checks if the input date is within a valid range.
	  Details : Checks if the input date is between the years 
	            1000 and 2024. Returns true if valid, false otherwise.
	  param[in]: Date - The date to be checked.
*/
bool Check_Input_Date(int Date);

/*
      Brief  : Checks if the author name contains valid characters.
	  Details : Checks if the author name contains only alphabets 
	            and spaces. Returns true if valid, false otherwise.
	  param[in]: Author_Name - The name of the author to be checked.
*/
bool Check_Author_Name(std::string Author_Name);

#endif
/****************************************************************
*  END OF  FILE: LibraryManagementSystem.h
****************************************************************/
