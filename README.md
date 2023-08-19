# GuessThePokémon

## Description
Simple program a [pokémon](https://www.google.com/search?q=pokemon) guessing game, random pokémon name will be displayed with removed characters in random position and you have to guess that pokémon name.

## Requirements
* Computer
* Time
* Mood

## Installations
* [GCC](https://www.google.com/search?q=gcc) compiler

### Step 0:
To run this code use:
```
git clone https://github.com/doer08736/guessThePokemon
```

## How to run (Docker)
#### Step 1:
Build Image
```
docker build -t gtp:v0 .
```

#### Step 2:
Create container and run
```
docker run --rm -it gtp:v0
```

## How to run (Linux)
#### Step 1:
Install [libsqlite3-dev](https://www.google.com/search?q=libsqlite3-dev)

Debian:
```
sudo apt install libsqlite3-dev
```
Arch Linux
```
sudo pacman -S sqlite
```

#### Step 2:
Head on to code directory
```
cd guessThePokemon/code
```
compile & run
```
cc main.c -lsqlite3; ./a.out
```

## How to run (Windows)
#### Step 1:
Download sqlite3.c file from [here](https://sqlite.org/2023/sqlite-amalgamation-3410009.zip).

Extract the downloaded zip file and copy only the sqlite3.c file to code directory.

#### Step 2:
Head on to code directory
```
cd guessThePokemon/code
```
In code main.c line number 6 change
```
# include <sqlite3.h> to # include "sqlite3.c"
```

#### Step 3:
compile & run
```
gcc main.c; ./a.exe;
```

## Help
If you need help just [google](https://www.google.com)

## Authors
[doer08736](https://github.com/doer08736)

## Conclusion
The End.
