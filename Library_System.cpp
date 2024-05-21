/****************************************************************
 FILE DESCRIPTION
-----------------------------------------------------------------
*        File     :  Library_System.cpp
*        Brief    :  Implementation of the main program for the Library Management System.
*                    
*        Details  :  This file contains the implementation of the main program for the Library 
*                    Management System. It includes functions for adding books to the library, 
*                    searching for books by author, and displaying the library's catalog. The 
*                    program provides a menu-driven interface for users to interact with the 
*                    library system.
*
*****************************************************************
* INCLUDES
****************************************************************/
#include "LibraryManagementSystem.h"
#include <limits>
/****************************************************************
*    LOCAL MACROS CONSTATN\FUNCTIONS
****************************************************************/

/****************************************************************
*    LOCAL DATA
****************************************************************/

/****************************************************************
*    GLOBAL DATA
/*****************************************************************/
 LibraryCatalog Library;
 
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
  Brief    : main function.
	Details  : Entry point of the program. Displays a menu for users to choose from 
             various options like adding a book, searching by author, displaying the 
             library's catalog, and exiting the program.
	param[in]: None.
*/
int main(void)
{
    /*1. Display features which included to the Library Management System Project*/
  std::cout<<"\n\nFeatures that included to Library Management System Project"<<std::endl;
  std::cout<<"1. Error checking when writing special characters or numbers in Book name"<<std::endl;
  std::cout<<"2. Book name can contain spaces "<<std::endl;
  std::cout<<"3. Error checking when enter invalid publishing date  "<<std::endl;
  std::cout<<"4. Error checking when writing special characters or numbers in author name"<<std::endl;
  std::cout<<"5. It doesn't matter if you search with author name in upper or lower case letters "<<std::endl;
  std::cout<<"6. If no matching between when searching by author, a new algorithm 'll start to find\ 
an author with the same characters name in case that user swap between chars"<<std::endl;
  std::cout<<"7. It doesn't matter how many spaces that you insert between chars when searching about\ 
author name"<<std::endl;

/*2. Init Variables*/
unsigned int Num_of_Books = 0;

int Operation_ID = 0;
int Input_Year;

bool Main_Prog_Flag = true;
bool Status = false;

std::string Input_Book_Name;
std::string Input_Author_Name;

     
  /*3. Start while loop*/
while(Operation_ID!=4)
{
    std::cout<<"Menu:\n1. Add a book\n2.Search by author\n3.Display catalog\n4. Exit\nEnter your choice: ";
    std::cin>>Operation_ID;
    
switch(Operation_ID)
 {
    case 1:
    /*2. Addition Book Operation*/
    /*3. Ask user to input Book name.*/
    std::cout<<"Enter book name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
    std::getline(std::cin, Input_Book_Name);
    
    /*4. Check weather Input name is valid or not*/
    Status = Check_Book_Name(Input_Book_Name);  
    if(Status == false)
      {
        std::cout<<"Invalid Book name, Book should not conatin any digits except Alpha and spaces"<<std::endl;
        std::cout<<"Operation terminated"<<std::endl;
      }
     /*5. if book name is a valid name, Continue*/     
      else
      {
        /*6. Ensure to the user that process is done successfully*/  
        std::cout<<"Book name: "<<Input_Book_Name<<std::endl;
        std::cout<<"Book name check complete."<<std::endl;
        std::cout<<"Success Process"<<std::endl;

        /*7. Ask user to add Year of publication of the book*/  
        std::cout<<"Enter publishing year: ";
        std::cin>>Input_Year;
        Status = Check_Input_Date(Input_Year);

        /*8. Check Validity of publication year*/  
        if(Status == false)
        {
          std::cout<<"Invalid Publish year, Publication year should be between 1000 : 2024(Current)"<<std::endl;
          std::cout<<"Operation terminated"<<std::endl;
        }
        else
        {
          /*9. Ensure to the user that process is done successfully*/   
          std::cout<<"Publication year check complete."<<std::endl;
          std::cout<<"Success Process"<<std::endl;

          /*10. Ask user to Input author name*/  
          std::cout<<"Enter Author name: ";
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cin.clear();
          std::getline(std::cin, Input_Author_Name);
          Status = Check_Author_Name(Input_Author_Name);

          /*11. Check Validity of Input Author name*/
          if(Status == false)
          {
            std::cout<<"Invalid Author name, Author should not conatin any digits except Alpha and spaces"<<std::endl;
            std::cout<<"Operation terminated"<<std::endl; 
          }
          else
          {
            /*12. Ensure to the user that process is done successfully*/ 
            std::cout<<"Author name check complete."<<std::endl;
            std::cout<<"Success Process Author Name: "<<Input_Author_Name<<std::endl;

            /*13. Add New book to the library*/ 
            
            Library.addBook(Input_Book_Name, Input_Author_Name, Input_Year);
            Num_of_Books++;
          }
        }
      }
    break;
   
    case 2:
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
    
    /*14. Check Number of books*/
    if(Num_of_Books)
    {
    std::cout<<"Enter Author Name: ";
    std::getline(std::cin, Input_Author_Name);
    Status = Check_Author_Name(Input_Author_Name);

    /*15. Check Validity of Author name*/
    if(Status == false)
    {
      std::cout<<"Invalid Author name, Author name should n't have special characters or number"<<std::endl;
    }

    else
    {
      Library.searchByAuthor(Input_Author_Name);
    }
    }
    /*16. else if library is empty*/
    else
      {
        std::cout<<"Library Catogery is Empty, Please fill it first"<<std::endl;
      }
    break;

    case 3:

    /*17. Check Number of books*/
    if(Num_of_Books)
    {
    std::cout<<"Display Catalog Process "<<std::endl;
    Library.Display_Catogery();
    }

    /*18. Library is empty*/
    else
    {
      std::cout<<"Library Catogery is Empty, Please fill it first"<<std::endl;
    }
    break;
    
    /*19. Exit Condtion*/
    case 4:
    std::cout<<"Case 4"<<std::endl;
    Main_Prog_Flag = false;
    break;
   
    /*20. if Wrong ID Process is entered*/
    default:
    std::cout<<"Wrong Operation ID, Please try again."<<std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear(); 
    break;     
 }
}
  
  /*21. End of function*/ 
    return 0;
}
/****************************************************************
*  END OF  FILE: Library_System.cpp
****************************************************************/
