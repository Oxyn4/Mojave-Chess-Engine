/*

    contains code for interfacing with the engine via a user interface

    manages one or more chessboard objectes
*/

#include "Interface.hpp"


int communicationstatus = 1;

int InterfaceMethod = -1;

// list of commands sent from GUI
std::vector<std::string> CommandHistory;

void InterfaceHandleSIGNINT(int SignalNumber) 
{
    std::cout << "\n\nPlease use the exit command to quit mojave\n\n";

    InterfaceLoop();
}


void ParseCommandLineArguments(int argc, char *argv[]) 
{

    for (int ArgumentIterator = 1; ArgumentIterator < argc; ArgumentIterator++) 
    {
        if (strcmp(argv[ArgumentIterator], "--CLI")) 
        {
            InterfaceMethod = CLI;
        }


    }

}


void InterfaceLoop() 
{  
    if (InterfaceMethod == CLI) {signal(SIGINT, InterfaceHandleSIGNINT);}

    while (communicationstatus == 1) 
    {
        char UCI_Command[50];

        // if cli add prompt to cli
        if (InterfaceMethod == CLI) {std::cout << "Mojave -> ";}

        std::cin.getline(UCI_Command, 50);

        std::string UCI_CommandString = UCI_Command;

        std::vector<std::string> TokenVector;

        std::istringstream CommandStringStream(UCI_CommandString);

        std::string Token;

        while (CommandStringStream >> Token)
        {
            TokenVector.push_back(Token);
        }
    
        if (InterfaceMethod == -1) 
        {
            InterfaceMethod = UCI;
        }

        if (InterfaceMethod == UCI) 
        {
            ParseUCICommand(TokenVector);
        }
        else if (InterfaceMethod == CLI)
        {
            // TODO: Implement mojave CLI
            CommandLineInterface(TokenVector);
        }
        else if (InterfaceMethod == GUI)
        {
            // implement GUI compatiblity 
        }
    }
}
