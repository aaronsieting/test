#include <stdio.h>
#include <stdlib.h>

int transition(char input);//function to determine state transition

int main(int argc, char * argv[]) {

	int stateTable[15][6] = {{1,0,11,0,6,0},
							{1,2,11,0,6,0},
							{1,0,3,0,6,0},
							{1,0,4,0,6,0},
							{1,0,11,5,6,0},
							{5,5,5,5,5,5},
							{1,0,7,0,6,0},
							{1,0,8,0,6,0},
							{1,0,11,9,6,0},
							{10,14,14,14,14,14},
							{10,10,10,10,10,10},
							{1,0,12,0,6,0},
							{1,0,11,13,6,0},
							{13,13,13,13,13,13},
							{14,14,14,14,14,14}};
	int state = 0;
	char *line = malloc(512);
	int t = 0;
	size_t n = 1024;
	int i =0;
	int cont = 1;
	//read lines from stdin until none are read.
	while(getline(&line, &n, stdin) != 1) {
		i = 0;
		state = 0;
		cont = 1;
		while(line[i] != '\n' && cont){
			if (state == 5 || state == 10 || state == 13 || state == 14)
				cont = -1;
			else{
				t = transition(line[i]);
				state = stateTable[state][t];
			}

			i++;
		}

		switch(state){
			case 5:
				printf("SNOOP \n");
				break;
			case 10:
				printf("LOOPS \n");
				break;
			case 14:
				printf("LOOP \n");
				break;
			case 9:
				printf("LOOP \n");
				break;
			case 13:
				printf("OOP \n");
				break;
			default:
				printf("\n");
				break;
			}
	}


}

int transition(char input){
	int ret = 0;
	switch(input){
		case 's':
			ret = 0;
			break;
		case 'S':
			ret = 0;
			break;
		case 'n':
			ret = 1;
			break;
		case 'N':
			ret = 1;
			break;
		case 'O':
			ret = 2;
			break;
		case 'o':
			ret = 2;
			break;
		case 'p':
			ret = 3;
			break;
		case 'P':
			ret = 3;
			break;
		case 'l':
			ret = 4;
			break;
		case 'L':
			ret = 4;
			break;
		default:
			ret = 5;
			break;
	}
	return ret;

}

