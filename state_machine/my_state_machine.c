#include <stdio.h>

enum State {
	STATEONE,
	STATETWO,
	STATETHREE,
	STATEEND
} ;

enum State currentState = STATEONE;

void	stateOne(void)
{
	printf("One\n");
}

void	stateTwo(void)
{
	printf("Two\n");
}

void	stateThree(void)
{
	printf("Three\n");
}

void	(*stateFunctions[])() = {stateOne, stateTwo, stateThree};

int	main(void)
{
	stateFunctions[currentState]();
	currentState = STATETWO;
	stateFunctions[currentState]();
	currentState = STATETHREE;
	stateFunctions[currentState]();
	currentState = STATEEND;
	return 0;
}
// void	*stateFunctions[] = {stateOne, stateTwo, stateThree};
// 
// int	main(void)
// {
// 	stateFunctions[currentState];
// 	currentState = STATETWO;
// 	stateFunctions[currentState];
// 	currentState = STATETHREE;
// 	stateFunctions[currentState];
// 	currentState = STATEEND;
// 	return 0;
// }
