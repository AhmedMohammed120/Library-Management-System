/****************************************************************
 FILE DESCRIPTION
-----------------------------------------------------------------
*        File     :  Book.cpp
*        Brief    :  Implementation of the Book class methods.
*                    
*        Details  :  This file contains the implementation of the methods 
*                    declared in the Book class header file. It includes the 
*                    constructor to initialize a Book object with provided 
*                    Title, Author, and Year, as well as methods to retrieve 
*                    book details such as title, author, and publication year.
*
*****************************************************************
* INCLUDES
****************************************************************/
#include <iostream>
#include "Book.h"

/****************************************************************
*    LOCAL MACROS CONSTATN\FUNCTIONS
****************************************************************/

/****************************************************************
*    LOCAL DATA
****************************************************************/


/****************************************************************
*    GLOBAL DATA
****************************************************************/

/****************************************************************
*    LOCAL FUNCTION PROTOTYPES
****************************************************************/






/****************************************************************
*    LOCAL FUNCTIONS
****************************************************************/



/****************************************************************
*   GLOBAL FUNCTIONS
****************************************************************/
/*
      Brief    : Constructor to initialize a Book object.
	  Details  : Initializes the Title, Author, and Year of the Book.
	  param[in]: Title_Cpy - Title of the book.
	  param[in]: Author_Cpy - Author of the book.
	  param[in]: Year_Cpy - Year of publication.
*/
Book::Book(std::string Title_Cpy, std::string Author_Cpy, int Year_Cpy)
{
    //std::cout<<"Parameterized Constructor Called"<<std::endl;
    Title  = Title_Cpy;
    Author = Author_Cpy;
    Year   = Year_Cpy;
}

/*
      Brief    : Retrieves the title of the book.
	  Details  : Returns the title of the book as a string.
	  param[out]: The title of the book.
*/
std::string Book::Get_Title(void)
{
    return Title;
}

/*
      Brief    : Retrieves the author of the book.
	  Details  : Returns the author of the book as a string.
	  param[out]: The author of the book.
*/
std::string Book::Get_Author()
{
    return Author;
}

/*
      Brief    : Retrieves the publication year of the book.
	  Details  : Returns the publication year of the book as an integer.
	  param[out]: The publication year of the book.
*/
int Book::Get_Year(void)
{
    return Year;
}

/*
      Brief    : Displays information about the book.
	  Details  : Prints the title, author, and publication year of the book.
*/
void Book::Display_Info(void)
{
    std::cout<<"Book Name: "<<Get_Title()<<std::endl;
    std::cout<<"Author Name: "<<Get_Author()<<std::endl;
    std::cout<<"Publication Year: "<<Get_Year()<<std::endl;
}

/****************************************************************
*  END OF  FILE: Book.cpp
****************************************************************/
