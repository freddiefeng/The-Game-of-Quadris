Contributor: Guoyao Feng(Freddie), Al Thai Tran(Alvin)

Compilation
--------------------
The program can be compiled by using the following command
make (make -f Makefile)

An executable called "quadris" will be produced.

Note that the proper XLib is necessary for compilation. Please refer to the makefile for more information.

Instruction
--------------------

Commands:

• left 
Moves the current block one cell to the left. If this is not possible (left edge of the board, or block in the way), the command has no effect.• right 
As above, but to the right.• down 
As above, but one cell downward.• clockwise 
Rotates the block 90 degrees clockwise, as described earlier. If the rotation cannot be accomplished without coming into contact with existing blocks, the command has no effect.• counterclockwise 
As above, but counterclockwise.• drop 
Drops the current block. It is (in one step) moved downward as far as possible until it comes into contact with either the bottom of the board or a block. This command also triggers the next block to appear. Even if a block is already as far down as it can go (as a result of executing the down command), it still needs to be dropped in order to get the next block.• levelup 
Increases the difficulty level of the game by one. The block showing as next still comes next, but subsequent blocks are generated using the new level. If there is no higher level, this command has no effect.• leveldown 
Decreases the difficulty level of the game by one. The block showing as next still comes next, but subsequent blocks are generated using the new level. If there is no lower level, this command has no effect.• restart 
Clears the board and starts a new game.

Command-line Interface:
Your program should support the following options on the command line: 
• -text runs the program in text-only mode. No graphics are displayed. The default behaviour(no -text) is to show both text and graphics.
• -seed xxx sets the random number generator’s seed to xxx. If you don’t set the seed, you always get the same random sequence every time you run the program. It’s good for testing, but not much fun.

Extra Feature
--------------------
Another executable named "walllessquadris" also is present for the bonus challenge.
The source code are included inside the project_feature directory. The executable can
also be generated inside that directory.

The "walllessquadris" program allows blocks to penetrate the left and right boarder
of the board and appear on the other side of the board. That is, the board is "wallless".
The feature applies to LeftShift, RightShift, Clockwise and Counterclockwise commands.

Xwindow Size
--------------------
The Xwindow may show up with different view dimensions depending on the screen resolution
and the operating system. 
The scale is adjustable inside the gdisplay.cc file under src directory.

Documentation
--------------------
The documents for due date 1 and due date 2 are all included inside the doc directory
