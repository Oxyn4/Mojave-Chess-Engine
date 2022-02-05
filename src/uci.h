#pragma once

#include "Chessboard.h"

std::string const NAME = "Mojave";
std::string const AUTHOR = "Oxyn";


void ParseCommand(std::string Command, Chessboard Board);
void UCILoop(Chessboard Board);
