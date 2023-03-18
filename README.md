# Mojave Chess engine
## Welcome
This is a chess engine written by me Oxyn in c++. It is a combination of many chess programming techniques.

Note: Currently, this software is linux exclusive as it relies on Gnu c compiler inbuilt funcitons.

This is because linux is my devolopment enviroment eventually i will port it to windows.

The majority of useful doucmentation including a changelog and a todo list for features to be implemented 
into the project can be found in the docs folder.

- [Todo list](https://github.com/Oxyn4/Mojave-Chess-Engine/blob/master/doc/todo.md)
- [Changelog](https://github.com/Oxyn4/Mojave-Chess-Engine/blob/master/doc/changelog.md)

---

## Compilation 

Mojave uses cmake to generate a makefile which can then be used to build Mojave.

The main binary has no dependancies other than the c++ standard library.

However, Mojave does have tests which are dependant on [googletest](https://github.com/google/googletest) a unit testing framework

as well as benchmark dependant on [hayai](https://github.com/nickbruun/hayai) a benchmarking library

and finally for logging mojave uses boost log.

These are optional and **do not** need to be compilied unless desired.

To compile the Mojave binary:

```sh
    mkdir build
    cd build 
    cmake .. -DLOGGING=<OFF | ON> -DBUILD_TESTS=<OFF | ON> -BUILD_BENCHMARK=<OFF | ON>
    make
```

This will build the binaries under /build/bin

These binaries includes:

- **mojave**, this is the mojave chess engine program 
- **tests** this runs all the tests and returns results
- **benchmark** shows preformance of some preformance critical functions in source code

The **tests** and **benchmark** will not be built unless the cmake flags are set **ON**

The debug option enables debugging mode on the **mojave** binary this makes debugging easier.

---

## Usage

Mojave has two interfaces which let you interact with the engine. These are how positions are set,
searches are ran, and evaluations are started.

The interfaces are: 

- UCI: [universal chess interface](https://www.chessprogramming.org/UCI)
- CLI: command line interface

### UCI

The universal chess interface is a protocol standard for chess programs communication.

This is the standard for chess engines Mojave not only supports it but it is it's default interface for human interaction.

It allows Mojave to talk to a chess GUI a specialised piece of software that handles a GUI of the chessboard among many other features.

This allows Mojave to focus on bieng a chess engine first and foremost and not have to have its own gui.

This results in mojave have low dependancies, as UCI communication is simply done through stdin and stdout.

This standardiation makes GUIs able to act as a hub for one or several engines, allowing for tournements or computer matches.

Mojave is devoloped using the [Arena GUI](http://www.playwitharena.de/)

This is a capable GUI, easy to set up and configure. However, there are many [alternatives](https://www.chessprogramming.org/GUI#Chess_GUIs).

Any chess gui with a valid implementation of the UCI standard should work.

### CLI

The command line interface allows doesnt require any additional software and comes pre-part of the Mojave engine.

The cli also allows for more features that are not present in the UCI protocol.

This is the best option if you want to see mojave working without other software.

The downside to this interface is that there is a learning curve as you have to learn Mojaves cli commands.

To start the engine with the cli:

```sh
    mojave --cli
```

This uses the --cli flag to tell mojave to use the correct interface.

This will put you in a shell in which you can invoke cli commands that call mojaves functions and display output.

#### Conventions used in CLI documentation

To make the CLI easier to learn you must first learn a little about the internals of Mojave.

Several commands require arguments to preform their purpose, for example the FEN command needs a fen passed to it.

While the FEN command is unique in needing a FEN passed to it Several functions share common argument types they need.

For example the pp (put piece) and wp (wipe piece) commands which repectively place and remove pieces from the board need 

a square passed to them, that they put a piece on or remove a piece from respectively.

throughout the Documentation of CLI commands you will see such arguments that will be abbreviated.

The common arguments are:

- SM: This stands for square mapping mojave will except any square notation like: a1, e3, f6, h7, etc
- PT: This stand for piecetype and is how you pass a piecetype to a function that will require it. PieceTypes follow the formula of ColorPiece: BlackPawn, WhiteRook, BlackKing, WhiteKnight, etc.

so anytime these appear in the documentation make sure you submit a correct value following these guidelines.

---

#### Print board (p command)

This command prints out the internal state of the board, using unicode piece symbols.

Usage is as followed:

```
Mojave -> p
```

#### FEN (f command)

This allows you to parse a FEN and set the board acordingly.

Usage is as followed:

```sh
Mojave -> f <FEN>
```

"startpos" can be subsututed for FEN in order to submit the chess starting position.

Note: FEN is not checked for validity

Example usage:

```
Mojave -> f startpos
Mojave -> f rnb1r1k1/ppp2ppp/5n2/3q4/4PB2/5P2/P1P3PP/RN2K1NR w KQq - 0 1
```

#### Put Piece (pp command)

This command allows you to place a piece on the board

Usage is as followed: 

```
Mojave -> pp <SM> <PT>
```

This will place a piece of PT on square of SM.

Exmaple usage:

```
Mojave -> pp e4 WhitePawn
```

This will place a white pawn on e4.

#### wipe piece (wp command)

This command removes pieces from the board.

Usage is as followed:

```
Mojave -> wp <SM>
```

removes the piece on SM

Example usage:

```
Mojave -> wp a1
```

#### Get moves (gm command)

This gets all the squares mojave recognises a piece can move to.

Usage is as followed:

```
Mojave -> gm <SM>
```

This will output legal moves of piece on square SM

Example usage:

```
Mojave -> gm e2
```

Gets legal moves of piece on e2

#### make move (mm command)

This will make a move on the board.

Usage is as followed:

```
Mojave -> mm <SM> <SM>
```

this will move piece on 1st SM to 2nd SM

Example usage:

```
Mojave -> mm e2 e4
```

this will move piece on e2 to e4

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

