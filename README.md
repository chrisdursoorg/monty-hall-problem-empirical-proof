monty-hall-problem-empirical-proof
==================================

Proof of Monty Hall or Cadillac Problem by empirical test in a single file C/C++ program.

puzzle:
Given that a valued prize (a Cadillac automobile) is hidden behind one of three doors.  You must select correct door to win the prize, however once you make your initial guess a knowing game host reveals one of the empty doors.  At this point you are given the opportunity to change your initial guess in favor of the only remaining door.  What should you do, and what is the probability of obtaining the prize given this choice?

answer:
Clearly you begin with the simple odds of one in three, however the knowing  host's act of revealing a dud choice may lead you astray into considering the resulting situation a game of simple odds (2 options 1 choice) and an incorrect answer.  Consider instead, that the probability of all the states any system sums to 1.  As the original probability is 1/3 goes to your initial guess the other 2/3 must evenly distributed to the remaining two doors ... that is until the knowing  revelation of a dud door.  Following this, the probability redistribution of that 2/3 must be re-accounted and it may only transfer to only the unselected door.  You should select this so far untouched door as it now holds a 2/3 chance of being the prize door.

If you still are uncovinced or just as a fun exercise download my CadillacProgram.cpp examine that it follows the rules and run a simulation of  it for yourself.  For those without a C++ compiler here's a peek at the results.

```
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
```

references:
http://durso.org/cadillac/
http://en.wikipedia.org/wiki/Monty_Hall_problem

