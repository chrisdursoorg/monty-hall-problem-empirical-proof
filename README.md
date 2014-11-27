<<<<<<< HEAD
monty-hall-problem-empirical-proof
==================================

Proof of Monty Hall or Cadillac Problem by empirical test in a single file C/C++ program.

puzzle:
Given that a valued prize (a Cadillac automobile) is hidden behind one of three doors.  You must select correct door to win the prize, however once you make your initial guess a knowing game host reveals one of the empty doors.  At this point you are given the opportunity to change your initial guess in favor of the only remaining door.  What should you do, and what is the probability of obtaining the prize given this choice?

answer:
Clearly you begin with the simple odds of one in three, however the knowing  host's act of revealing a dud choice may lead you astray into considering the resulting situation a game of simple odds (2 options 1 choice) and an incorrect answer.  Consider instead, that the probability of all the states any system sums to 1.  As the original probability is 1/3 goes to your initial guess the other 2/3 must evenly distributed to the remaining two doors ... that is until the knowing  revelation of a dud door.  Following this, the probability redistribution of that 2/3 must be re-accounted and it may only transfer to only the unselected door.  You should select this so far untouched door as it now holds a 2/3 chance of being the prize door.

If you still are uncovinced or just as a fun exercise download my CadillacProgram.cpp examine that it follows the rules and run a simulation of  it for yourself.  For those without a C++ compiler here's a peek at the results.

[chris@durso monty-hall-problem-empirical-proof]$ g++ -O3 -o CadillacProblem  CadillacProblem.cpp 
[chris@durso monty-hall-problem-empirical-proof]$ time ./CadillacProblem 1073741824
of                                                       1073741824 trials

Strategy "keep first choice" wins :  357909368   (33.332907%)
Strategy "Switch door"       wins :  715832456   (66.667093%)
                                  -----------   ----------
                            total : 1073741824   (100.000000%)

real    1m17.912s
user    1m17.892s
sys     0m0.002s


references:
http://durso.org/cadillac/
http://en.wikipedia.org/wiki/Monty_Hall_problem


=======
knights-tour-search
===================

Small program to search and print out chess knights tour solutions

To build simply:

>  gcc -c knight.cpp -o knight

Then print out the following with the help command as illustrated below
or you can just start a knights search without the -h option.

By starting the knight down a particular path you can have the program
explore that particular knight's tour subspace (e.g. > ./knight 0 11 58 15 
note the coordinates below).  

A bit more documentation and references are at 

http://durso.org/knights_tour/

> ./knight -h

knights [OPTIONS] [SEARCHPATH]
knights crossing program (v1.1, 12Feb12), by chris durso, ref. www.durso.org

OPTIONS

-v
--verbose       print more information
-g=#
--grid=#        use grid of size # (default 8 for 8x8). Minimum 5, Maximum 11.
                    Note no white spaces!

SEARCHPATH

The optional SEARCHPATH is a sequence of positive numbers not longer than
grid x grid in length, and thier numerical values in the range of 0 to
grid x grid and non repeating. Each number is sequence must be a legal
chess knights move from the previous number in the SEARCHPATH.

COORDINATE SYSTEM

The bottom left hand corner is noted as 0 and the increment first
goes up and wraps to the right.  The bottom left is 0, the top
left is grid -1, and the top right square is grid x grid -1.

   7  15  23  31  39  47  55  63
   6  14  22  30  38  46  54  62
   5  13  21  29  37  45  53  61
   4  12  20  28  36  44  52  60
   3  11  19  27  35  43  51  59
   2  10  18  26  34  42  50  58
   1   9  17  25  33  41  49  57
   0   8  16  24  32  40  48  56
>>>>>>> 40f6717cdb2df2a86cd0b55f8491992094cb54af

