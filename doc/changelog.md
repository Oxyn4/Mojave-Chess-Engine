# changelog

Any notable changes to versions of this software should be recorded here.

## Mojave engine (1.0.0) 21.09 - Oxyn

Hello world! the Mojave engine is now in a usable state and i feel comfortable releasing it with its limited features.

- NEW: Board representation, uses Bitboards to keep track of ocupancy
- NEW: Can generate moves for Leaping pieces (kings, pawns, knights)

## Mojave engine (1.1.0) 05.02.22 - Oxyn

- NEW: Can generate leaping piece moves (Queen, Rook. Bishop) 
- NEW: Fixed FEN parsing algorithm
- NEW: Built algorithm for getting moves off a chessboard object
- NEW: Reworked Bitscan functions

## Mojave engine (1.2.0) 27.02.22  - Oxyn

Reworked project structure removed:
- UCI.h
- Eval.h
- Search.h

added them as member functions to chessboard class as i noticed many of these relied on a 
chessboard object anyway so these member functions can directly access class variables.