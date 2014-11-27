// CadillacProblem.cpp : 
// Christopher D'Urso
// chris@durso.org
// 22 August 2005
// 
// Empirical proof of the "Cadillac Problem":   
// Given:
// a) One prize hidden behind one of three doors, and a 
// b) host that will always tempt you change your initial choice after revealing one 
// of the remaining doors does not contain your prize, 
//
// You are best strategy is to choose the remaining untouched door as this has a 2/3 
// probability of hiding the prize.

char strOut[] = ""\
" Christopher D'Urso\n"\
" 22 August 2005\n"\
" chris@durso.org\n"\
" \n\n"\
" Empirical proof of the \"Cadillac Problem\":   \n\n\n"\
" Given: \n\n"\
" One prize hidden behind one of three doors, and a \n\n"\
" host that will always tempt you change your initial choice after revealing \n"\
" one of the remaining doors that does not contain the prize,\n\n"\
" Your best strategy is to choose the remaining untouched door whichhas a 2/3\n"\
" probability of containing the prize.\n\n\n"\
" CadilacProblem [OptionalNumberOfTrials(default 1000)]\n";


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef long long __int64;

const int numberOfDoors = 3;

// choose(p) 
// simple [0..p-1] psudorandomiser
int
choose(int p = numberOfDoors ) {
	return rand() %p;
}
int main(int argc, char* argv[])
{
	__int64 trials = 1000;

	srand(time(NULL));
	// pick up trials
	if(argc > 1){
		// check the command line
		if (1 != sscanf(argv[1], "%I64d", &trials)){
			printf("%s", strOut);
			return 1;
		}
		if (trials < 1){
			printf("%s Trials Must be > 0 !", strOut);
			return 1;
		}
	}

	
	enum doorState { empty =0, prize = 1, choice = 2, revealed = 4};
	__int64 strategyFirstChoiceTally = 0;
	__int64 strategySwitchChoiceTally = 0;

	// main loop
	__int64 i;
	for (i = 0; i < trials; i++){
		int door[numberOfDoors] = {empty, empty, empty};

		// hide prize randomly behind one door
		door[choose()] |= prize;

		// choose initial door
		int firstChoice = choose();
		door[firstChoice] |= choice;

		// choose door to reveal 1st random non (prize or choosen) door
		int reveal = choose();
		while(door[reveal])
			reveal = (reveal + 1)%numberOfDoors;
		door[reveal] |= revealed;

		// strategy "stick with initial choice"
		if( door[firstChoice] & prize ) 
			strategyFirstChoiceTally++;

		// strategy "switch from initial choice"
		int j;
		int secondChoice(-1);
		for( j = 0; j < numberOfDoors; j++){
			if(door[j] & revealed)
				continue;
			if(door[j] & choice){
				door[j] &= ~choice; // erase old choice
				continue;
			}
			door[secondChoice = j] |= choice;
		}
	
		if( door[secondChoice] & prize ) 
			strategySwitchChoiceTally++;

	} // main loop

	// print statistics
	double total = double(strategyFirstChoiceTally + strategySwitchChoiceTally);
	double sfp = double(strategyFirstChoiceTally)/trials*100.;
	printf("of %I64d trials\n\n", trials);
	printf("Strategy \"keep first choice\" wins : %10lld\t (%f%%)\n", 
		strategyFirstChoiceTally, sfp);
	double ssp = double(strategySwitchChoiceTally)/total*100.;
	printf("Strategy \"Switch door\"       wins : %10lld\t (%f%%)\n", strategySwitchChoiceTally, ssp);
    printf("                                  -----------\t---------- \n");
	printf("                            total : %10lld\t (%f%%)\n", 
		__int64(total), sfp+ssp);


	return 0;
}
