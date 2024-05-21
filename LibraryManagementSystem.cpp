/****************************************************************
 FILE DESCRIPTION
-----------------------------------------------------------------
*        File     :  LibraryManagementSystem.cpp
*        Brief    :  Implementation of LibraryCatalog class methods.
*        Details  :  This file contains the implementation of methods 
*                    declared in the LibraryCatalog class header file. 
*                    It includes functions to add books to the library, 
*                    search for books by author, and display the library's catalog.
*
*****************************************************************
* INCLUDES
****************************************************************/
#include "LibraryManagementSystem.h"

/****************************************************************
*    GLOBAL FUNCTIONS
****************************************************************/
/*
      Brief    : Adds a new book to the library.
	  Details  : Adds the provided book object to the library catalog.
	  param[in]: Book_Name : The name of the book to be added.
	             Author_Name : The name of the author of the book.
	             Date : The publication date of the book.
*/
void LibraryCatalog:: addBook(std::string Book_Name, std::string Author_Name, unsigned int Date) {
   Book New_Book(Book_Name, Author_Name, Date);
    Library_System.push_back(New_Book);
}
/*
      Brief    : Searches for books by author name.
	  Details  : Compares the provided author name with the names of 
	             authors of books in the library catalog. Displays 
	             information about the book if a match is found.
	  param[in]: Input_Name - The name of the author to search for.
*/
void LibraryCatalog::searchByAuthor(std::string Input_Name) {
    /* 1. Init Variables */
    std::string Name_Cpy;
    unsigned int ID = 0;
    bool Compare_Flag = false;

    /* 2. Preprocess input name for comparison*/
    for (unsigned int Ch_Counts = 0; Ch_Counts < Input_Name.size(); Ch_Counts++) {
        if (isupper(Input_Name[Ch_Counts]) == 1) {
            Input_Name[Ch_Counts] = tolower(Input_Name[Ch_Counts]);
        }
        if (Input_Name[Ch_Counts] == ' ') {
            Input_Name.erase(Ch_Counts, 1);
            Ch_Counts--;
        }
    }

    /* 3. Search for the author in the library catalog */
    for (ID = 0; (ID < Library_System.size() && Compare_Flag == 0); ID++) {
        Name_Cpy = Library_System[ID].Get_Author();

        /* 4. Preprocess author name for comparison*/
        for (unsigned int Ch_Counts = 0; Ch_Counts < Name_Cpy.size(); Ch_Counts++) {
            if (isupper(Name_Cpy[Ch_Counts]) == 1) {
                Name_Cpy[Ch_Counts] = tolower(Name_Cpy[Ch_Counts]);
            }
            if (Name_Cpy[Ch_Counts] == ' ') {
                Name_Cpy.erase(Ch_Counts, 1);
                Ch_Counts--;
            }
        }

        /* 5. Start Comparison between names*/
        if (Name_Cpy.compare(Input_Name) == 0) {
            Compare_Flag = true;
            break;
        }  
    }

    /* 6. Display result of the search*/
    if (Compare_Flag == 1) {
        std::cout << "Success Operation" << std::endl;
        Library_System[ID].Display_Info();
    } else {
        /* 7. If no Identical matches, this algorithm 'll get any author with the same letters of name
              In case that the user swaps between two or more chars*/
        for (ID = 0; (ID < Library_System.size() && Compare_Flag == 0); ID++) {
            Name_Cpy = Library_System[ID].Get_Author();

            /* 8. Preprocess author name for comparison*/
            for (unsigned int Ch_Counts = 0; Ch_Counts < Name_Cpy.size(); Ch_Counts++) {
                if (isupper(Name_Cpy[Ch_Counts]) == 1) {
                    Name_Cpy[Ch_Counts] = tolower(Name_Cpy[Ch_Counts]);
                }
                if (Name_Cpy[Ch_Counts] == ' ') {
                    Name_Cpy.erase(Ch_Counts, 1);
                    Ch_Counts--;
                }
            }
            
            /* 9. Start Comparison between names*/
            std::sort(Input_Name.begin(),Input_Name.end());
            std::sort(Name_Cpy.begin(),Name_Cpy.end());
            if (Name_Cpy.compare(Input_Name) == 0) {
                Compare_Flag = true;
                break;
            }
        }

        /* 10. Display result of the second search*/
        if (Compare_Flag == 1) {
            std::cout << "This may match your search: " << std::endl;
            Library_System[ID].Display_Info();
        } else {
            std::cout << "Unsuccess Operation, Can't find the book " << std::endl;
        }
    }
}

/*
      Brief    : Displays the catalog of books in the library.
	  Details  : Iterates through the library catalog and displays
	             information about each book.
*/
void LibraryCatalog::Display_Catogery(void) {
  /*1. Init Variables*/
  int Counter = 1;
  std::cout << "Display Library Category\n" << std::endl << std::endl;
  /*2. Start printing algorithm*/
    for (auto It : Library_System) {
        std::cout << std::endl;
        std::cout << "Book  " << Counter << std::endl << std::endl;
        It.Display_Info();
        std::cout << std::endl << std::endl;
        Counter++;
    }
}

/*
      Brief    : Checks if the book name contains valid characters.
	  Details  : Checks if the book name contains only alphabets 
	             and spaces. Returns true if valid, false otherwise.
	  param[in]: Book_Name - The name of the book to be checked.
*/
bool Check_Book_Name(std::string Book_Name) {
    bool Status = true;
    for (auto Ch : Book_Name) {
        if (isalpha(Ch)) {
            Status = true;
        } else if (isspace(Ch)) {
            Status = true;
        } else {
            Status = false;
            break;
        }
    }
    return Status;
}

/*
      Brief   : Checks if the input date is within a valid range.
	  Details  : Checks if the input date is between the years 
	             1000 and 2024. Returns true if valid, false otherwise.
	  param[in]: Date - The date to be checked.
*/
bool Check_Input_Date(int Date) {
    bool Status = false;
    if (Date >= 1000 && Date <= 2024) {
        Status = true;
    }
    return Status;
}

/*
      Brief    : Checks if the author name contains valid characters.
	  Details  : Checks if the author name contains only alphabets 
	             and spaces. Returns true if valid, false otherwise.
	  param[in]: Author_Name - The name of the author to be checked.
*/
bool Check_Author_Name(std::string Author_Name) {
    bool Status = true;
    for (auto Ch : Author_Name) {
        if (isalpha(Ch)) {
            Status = true;
        } else if (isspace(Ch)) {
            Status = true;
        } else {
            Status = false;
            break;
        }
    }
    return Status;
}
/****************************************************************
*  END OF  FILE: LibraryManagementSystem.cpp
****************************************************************/
