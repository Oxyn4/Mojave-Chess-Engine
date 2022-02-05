# Mojave Chess engine
## Welcome
This is a chess engine written by me Oxyn in c++. It is a combination of many chess programming techniques.

Note: Currently, this software is linux exclusive as it relies on Gnu c compiler inbuilt funcitons, this is because linux
this is because linux is my devolopment enviroment eventually ill port it to windows.

The majority of useful doucmentation including a changelog and a todo list for features to be implemented 
into the project can be found in the docs folder.

- [Todo list](https://github.com/Oxyn4/Mojave-Chess-Engine/blob/master/doc/todo.md)
- [Changelog](https://github.com/Oxyn4/Mojave-Chess-Engine/blob/master/doc/changelog.md)

## Features
This engine uses many technique outlined on the [Chessprogramming](https://www.chessprogramming.org/Main_Page) wiki for efficency and effectiveness.

### Board Representation
Keeping track of board states:

- Bitboards

### Leaping Piece Move Generation:

leaping pieces use precomputated lookup arrays

- Pawn move & attack generation
- King move & attack generation
- Knight move & attack generation

### Sliding Piece Move generation:

Sliding pieces use the "Classical approach" of a Ray table combined with isolating blocking pieces and a bitscan

- Queen move & attack generation
- Pawn move & attack generation
- Bishop move & attack generation

