# 42_solong

## Overview
This project is a graphical game developed as part of the 42 curriculum. It involves navigating a character around a map, collecting items, and reaching an exit. It uses the MiniLibX library for rendering.

## Project Structure
42_solong/  
├── README.md  
├── Makefile  
├── 42_gnl/  
├── 42_libft/  
├── maps/  
├── src/  
└── textures/

• 42_gnl/: Contains the get_next_line function for reading file descriptors line by line.  
• 42_libft/: Contains a library of useful C functions.  
• maps/: Holds map files used by the game.  
• src/: Contains the main game logic and rendering code.  
• textures/: Contains image files for game graphics.

## Dependencies
• MiniLibX: Handles the graphical rendering.  
• 42 Libft: Collection of basic C functions.  
• Get Next Line: Reads lines from input streams.

## Compilation
make  

This creates an executable named so_long.

## Usage
Run the game with:  
./so_long maps/map_name.ber  

Replace map_name.ber with your desired map file.

## Key Components
• Get Next Line (GNL): Reads map files line by line without global variables.  
• Libft: Custom C library with standard function reimplementations.  
• Map Validation: Ensures the map is rectangular, enclosed, and contains valid elements.  
• Game Logic: src/ handles initialization, window management, image loading, and player movement.

## Makefile
Automates compilation: defines the compiler, flags, libraries, and source files, including rules to clean and rebuild.

## so_long.h
Contains structures, function prototypes, and macros used throughout the game.

## What I Learned
• Improved handling of C libraries and pointers.  
• Better organization of source code into reusable modules.

## What Problems I Encountered (Handling External Libraries)
• Linking third-party libraries in the Makefile required careful flag settings.  
• Managing headers and paths for consistent builds was challenging.

• I had to learn how to use the MiniLibX library for rendering graphics.