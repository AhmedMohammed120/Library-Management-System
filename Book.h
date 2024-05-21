/****************************************************************
 FILE DESCRIPTION
----------------------------------------------------------------
*        File     :  Book.h
*        Brief    :  Declaration of the Book class and its methods.
*        Details  :  This header file contains the declaration of the Book class, 
*                    which represents a book with attributes like Title, Author, and Year.
*                    It also includes method declarations for getting book details and 
*                    displaying information about the book.
*
****************************************************************/
#ifndef BOOK_H
#define BOOK_H
/****************************************************************
* INCLUDES
****************************************************************/
#include <string>
#include <iostream>
/****************************************************************
*    GLOBAL DATA TYPE AND INSTRUCTIONS Union, Enum & Struct
****************************************************************/
class Book
{
    private:
    /*Attributes*/
     std::string Title;   // Title of the book
     std::string Author;  // Author of the book
     int Year;            // Year of publication

     public:
     /*Methods*/

    /*
      Brief  : Constructor to initialize a Book object.
      Details  : Initializes the Title, Author, and Year of the Book.
      param[in]: Title_Cpy - Title of the book.
      param[in]: Author_Cpy - Author of the book.
      param[in]: Year_Cpy - Year of publication.
    */
    Book(std::string Title_Cpy, std::string Author_Cpy, int Year_Cpy);
    
    
    /*
      Brief  : Retrieves the title of the book.
      Details  : Returns the title of the book as a string.
      param[out]: The title of the book.
    */
    std::string Get_Title(void);
    
    /*
      Brief  : Retrieves the author of the book.
      Details  : Returns the author of the book as a string.
      param[out]: The author of the book.
    */
    std::string Get_Author(void);  
    
    /*
      Brief  : Retrieves the publication year of the book.
      Details  : Returns the publication year of the book as an integer.
      param[out]: The publication year of the book.
    */
    int Get_Year(void);
    
    /*
      Brief  : Displays information about the book.
      Details  : Prints the title, author, and publication year of the book.
    */
    void Display_Info(void);  
};



/****************************************************************
*    GLOBAL CONSTANT MACROS
****************************************************************/

 
/****************************************************************
*    GLOBAL DATA PROTOTYPES
****************************************************************/


#endif
/****************************************************************
*  END OF  FILE: Book.h
****************************************************************/
