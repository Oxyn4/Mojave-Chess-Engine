#pragma once

#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

#include "Bitboard.hpp"
#include "BoardConcepts.hpp"
#include "Chessboard.hpp"
#include "Interface.hpp"

enum MojaveInterfaceMethods 
{
    UCI,
    CLI,
    GUI
};

extern std::vector<std::string> CommandHistory;

extern int InterfaceMethod;

void ParseCommandLineArguments(int argc, char *argv[]);
void InterfaceLoop();
void ParseUCICommand(std::vector<std::string> TokenVector);
void ParseUCICommand(Chessboard Board, std::vector<std::string> TokenVector);
