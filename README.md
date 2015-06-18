# allegroLife
## A 3D representation of Conway's Game of Life

This is a 3 dimensional representation of Conway's Game of Life
The same rules as the original game apply, except the board is 3 dimensional

## Video of Gameplay
[![Video](http://img.youtube.com/vi/uPsP3dvheSA/0.jpg)](https://www.youtube.com/watch?v=uPsP3dvheSA)

This project was written sometime from September of 2012 to the December of 2013
It was also ported to XNA and C# and handed up as a programming assignment for Bryan Duggan's Programming class, taught to DT211 second years

## Usage
The Esc key quits the game
The game board can be rotated by clicking and dragging
The Play/Pause button to the left of the screen dictates if the game is in progress or not
The 'M' button at the top right of the screen provides more usage options

## Tools
This project was originally written in C++ and used the Allegro library for graphics, It's currently being written in C and still uses the Allegro graphics library
Allegro 4.4.2
The project was originally written with Visual Studio 2011, it's currently being developed with GCC on Linux Mint 17

## Changelog


####  2015-06-18
        General Details
            I brought this project to GitHub, It's not written to my
                current standard and exists as I wrote it in 2012
            I rewrote some sections to conform to C standard rather
                than C++
            I cut the lines down to be no more than 72 characters
                in length
            I wrote the makefile
            I wrote this README.md file
        Usage
            The Esc key quits the game
            The game board can be rotated by clicking and dragging
            The Play/Pause button to the left of the screen dictates if 
                the game is in progress or not
            The 'M' button at the top right of the screen provides more 
                usage options
        Changes to Source
            Copied old source files to ./oldSourceFiles/
            Created allegroLife.c based completely on the old version:
                ./oldSourceFiles/allegroLifeSizable20130423.cpp
                I rewrote some sections to conform to C standard rather
                    than C++
                I cut the lines down to be no more than 72 characters
                    in length
                I wrote the makefile
                I wrote this README.md file
            Created the 'makefile', it redirects errors and warnings to
                the 'err' file
            Created this README.md file
        To Do
            Rewrite to personal current standard of C files
            Add comments everywhere
            Make more efficient
        Additional
            The current version of this project is almost exactly as it
                was when I wrote it in 2012, as such, you will almost
                definitely be able to make it throw an error, it's 
                basically unstable, and needs more work.
                Right now I just want to put all of my projects on 
                GitHub, so making this project stable is not one of my
                main concerns, though I will fix it in the future
                I might mess with it a bit more now anyway
                Enjoy the youtube video
            This was written over the 17th to the 18th of June 2015
        
        Conor Stefanini, 18 June 2015
