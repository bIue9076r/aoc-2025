#include <stdio.h>

int Dial = 50;
static int ZeroCount = 0;
static int PassZeroCount = 0;

int LshiftDial(int dial, int mag){
	LSHEAD:;
	int res = dial - mag;
	if (res < 0){
		if(dial){
			PassZeroCount++;
		}
		mag = mag - dial;
		dial = 100;
		goto LSHEAD;
	} else {
		dial = res;
	}

	if (!dial){
		ZeroCount++;
	}

	return dial;
}

int RshiftDial(int dial, int mag){
	RSHEAD:;
	int res = dial + mag;
	if (res > 99){
		if(res - 100){
			PassZeroCount++;
		}
		dial = 0;
		mag = res - 100;
		goto RSHEAD;
	} else {
		dial = res;
	}

	if (!dial){
		ZeroCount++;
	}

	return dial;
}

int toInt(char* s){
	int r = 0;
	for (int i = 0; s[i] != 0; i++){
		r = (r*10) + (s[i] - '0');
	}
	return r;
}

int ReadFile(char* path){
	int D = 50;
	FILE* file;
	char buffer[8] = {0,0,0,0,0,0,0,0};

	file = fopen(path,"r");
	if (file == NULL){
		return -1;
	}

	int _ind = 0;
	while(!feof(file)){
		char c = fgetc(file);
		if(c == '\n'){
			switch(buffer[0]){
				case 'L':
					D = LshiftDial(D,toInt(buffer + 1));
				break;

				case 'R':
					D = RshiftDial(D,toInt(buffer + 1));
				break;
			}

			for (int i = 0; i < 8; i++){
				buffer[i] = 0;
			}
			_ind = 0;
		}else{
			buffer[_ind++] = c;
		}
	}

	fclose(file);
	return D;
}

int main(void){
	//Dial = ReadFile("ex.txt");
	//printf("Dial: [%d], Zeros: [%d], Pass: [%d], Total: [%d]\n",Dial,ZeroCount,PassZeroCount,ZeroCount + PassZeroCount);

	ZeroCount = 0;
	PassZeroCount = 0;
	Dial = ReadFile("data.txt");
	printf("Dial: [%d], Zeros: [%d], Pass: [%d], Total: [%d]\n",Dial,ZeroCount,PassZeroCount,ZeroCount + PassZeroCount);
	return 0;
}