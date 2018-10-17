/******************************************************************************************************
 * Ryan Lockman                                                                                       *
 * 101430670                                                                                          *
 * pa4.cpp driver file                                                                                *
 * Description: This program is a command-line text editor. It provides the user with some very basic *
 *              text edditing commands.                                                               *
 ******************************************************************************************************/

// Headers
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "pa4functions.h"
#include "editor.h"

// Function Prototypes
void help_menu();

int main(int argc, char *argv[]) {
    // Check Arguments
    if(argc != 2 || strcmp(argv[1], "-h") == 0) {
        std::cout << "\nUsage: " << argv[0] << " [file path]\n\n";
        return EXIT_FAILURE;
    }

    // Output Welcome and Continue
    std::string ans;
    std::cout << "\n*************************************************************************"
              << "\n***                             Welcome!                              ***"
              << "\n***           This program is a command-line text editor              ***"
              << "\n***       which loads the desired document specified by the user.     ***"
              << "\n***                         By: Ryan Lockman                          ***"
              << "\n*************************************************************************"
              << "\n\nContinue?: ";
    std::cin  >> ans;
    if(!promptYN(ans)) {
        std::cout << "\nGood-Bye!\n\n";
        return 0;
    }

    // Declarations
    Editor editor;
    unsigned choice = 0;
    const char* const path(argv[1]);

    // Fill List
    if(editor.fill_editor(path) == -1)
        return EXIT_FAILURE;

    // Loop User Input
    while(choice != 11) {
        // Refresh Screen
        editor.clear_screen();
            
        // Print Cammands and Editor Document
        std::cout << "\nCommands: 1. delete | 2. ndelete | 3. insert | 4. ninsert | 5. fremove | 6. aremove |"
                  << " 7. freplace | 8. areplace | 9. save | 10. help | 11. quit\n\n\n";
        editor.print();
        std::cout << std::endl;

        // Wait on User Input
        if(std::cin >> choice) {
            // Parse User Input
            switch(choice) { 
            case 1:
                line_remove(editor);
                break;
            case 2:
                nline_remove(editor);
                break;
            case 3:
                insert(editor);
                break;
            case 4:
                ninsert(editor);
                break;
            case 5:
                fremove(editor);
                break;
            case 6:
                aremove(editor);
                break;
            case 7:
                freplace(editor);
                break;
            case 8:
                areplace(editor);
                break;
            case 9:
                // Save File
                if(editor.save_editor(path) == -1)
                    std::cerr << "\nError, could not save file.\n";
                break;
            case 10:
                // Output Help Menu
                editor.clear_screen();
                help_menu();

                // Wait on User
                flush_stream();
                std::cin.get();
                break;
            case 11:
                // Check Save on Exit
                std::cout << "\nSave before Quitting?: ";
                std::cin  >> ans;
                if(promptYN(ans))
                    editor.save_editor(path);

                std::cout << "\nGood-Bye\n";
                break;
            default:
                std::cout << "\nWrong Choice";
            };
        }
        else
            flush_stream();
    }

    return EXIT_SUCCESS;
}

// Function Implementations
void help_menu() {
std::cout << "\n **********************************"
          << "\n **           Help Menu          **"
          << "\n **  DESCRIPTION       COMMAND   **"
          << "\n **  Delete After:     delete    **"
          << "\n **  Delete N After:   ndelete   **"
          << "\n **  Insert After:     insert    **"
          << "\n **  Insert N After:   ninsert   **"
          << "\n **  Remove First:     fremove   **"
          << "\n **  Remove All:       aremove   **"
          << "\n **  Replace First:    freplace  **"
          << "\n **  Replace All:      areplace  **"
          << "\n **  Save Document:    save      **"
          << "\n **  Quit Editor:      quit      **"
          << "\n **  Help Menu:        help      **"
          << "\n ***********************************\n"
          << "\n Press Enter to Contiune: ";
}

