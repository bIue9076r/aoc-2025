#include <stdio.h>

#define BUFFER_SIZE 128

static int Jolts = 0;
static long long unsigned int Jolts_12 = 0;

int stlen(char* s){
	int r = 0;
	while (*s++){
		r++;
	}
	return r;
}

int toInt(char* s){
	int r = 0;
	for (int i = 0; s[i] != 0; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			r = (r*10) + (s[i] - '0');
		}
	}
	return r;
}

long long unsigned int toInt_LL(char* s){
	long long unsigned int r = 0;
	for (int i = 0; s[i] != 0; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			r = (r*10) + (s[i] - '0');
		}
	}
	return r;
}

int ReadString(char* buf){
	int high1 = 0;
	int high2 = 0;
	int ind = 0;
	int len = stlen(buf);

	for(int i = 0; i < len - 1; i++){
		if (buf[i] >= '0' && buf[i] <= '9'){
			if(buf[i] > high1){
				high1 = buf[i];
				ind = i + 1;
			}
		}
	}
	
	for(int i = ind; i < len; i++){
		if (buf[i] >= '0' && buf[i] <= '9'){
			if(buf[i] > high2){
				high2 = buf[i];
			}
		}
	}

	char str[3] = {0,0,0};
	str[0] = high1;
	str[1] = high2;
	int r = toInt(str);
	Jolts = Jolts + r;
	return 0;
}

int ReadString_12(char* buf){
	int high1 = 0; int high2 = 0; int high3 = 0;
	int high4 = 0; int high5 = 0; int high6 = 0;
	int high7 = 0; int high8 = 0; int high9 = 0;
	int high10 = 0; int high11 = 0; int high12 = 0;
	int ind = 0;
	int len = stlen(buf);
	int left = 11;

	for(int i = 0; i < len - 11; i++){
		if (buf[i] >= '0' && buf[i] <= '9'){
			if(buf[i] > high1){
				if (len - (i + 1) >= left){
					high1 = buf[i];
					ind = i + 1;
				}
			}
		}
	}
	left--;

	for(int i = ind; i < len - 10; i++){
		if (buf[i] >= '0' && buf[i] <= '9'){
			if(buf[i] > high2){
				if (len - (i + 1) >= left){
					high2 = buf[i];
					ind = i + 1;
				}
			}
		}
	}
	left--;

	for(int i = ind; i < len - 9; i++){
		if (buf[i] >= '0' && buf[i] <= '9'){
			if(buf[i] > high3){
				if (len - (i + 1) >= left){
					high3 = buf[i];
					ind = i + 1;
				}
			}
		}
	}
	left--;

	for(int i = ind; i < len - 8; i++){
		if (buf[i] >= '0' && buf[i] <= '9'){
			if(buf[i] > high4){
				if (len - (i + 1) >= left){
					high4 = buf[i];
					ind = i + 1;
				}
			}
		}
	}
	left--;

	for(int i = ind; i < len - 7; i++){
		if (buf[i] >= '0' && buf[i] <= '9'){
			if(buf[i] > high5){
				if (len - (i + 1) >= left){
					high5 = buf[i];
					ind = i + 1;
				}
			}
		}
	}
	left--;

	for(int i = ind; i < len - 6; i++){
		if (buf[i] >= '0' && buf[i] <= '9'){
			if(buf[i] > high6){
				if (len - (i + 1) >= left){
					high6 = buf[i];
					ind = i + 1;
				}
			}
		}
	}
	left--;

	for(int i = ind; i < len - 5; i++){
		if (buf[i] >= '0' && buf[i] <= '9'){
			if(buf[i] > high7){
				if (len - (i + 1) >= left){
					high7 = buf[i];
					ind = i + 1;
				}
			}
		}
	}
	left--;

	for(int i = ind; i < len - 4; i++){
		if (buf[i] >= '0' && buf[i] <= '9'){
			if(buf[i] > high8){
				if (len - (i + 1) >= left){
					high8 = buf[i];
					ind = i + 1;
				}
			}
		}
	}
	left--;

	for(int i = ind; i < len - 3; i++){
		if (buf[i] >= '0' && buf[i] <= '9'){
			if(buf[i] > high9){
				if (len - (i + 1) >= left){
					high9 = buf[i];
					ind = i + 1;
				}
			}
		}
	}
	left--;

	for(int i = ind; i < len - 2; i++){
		if (buf[i] >= '0' && buf[i] <= '9'){
			if(buf[i] > high10){
				if (len - (i + 1) >= left){
					high10 = buf[i];
					ind = i + 1;
				}
			}
		}
	}
	left--;

	for(int i = ind; i < len - 1; i++){
		if (buf[i] >= '0' && buf[i] <= '9'){
			if(buf[i] > high11){
				if (len - (i + 1) >= left){
					high11 = buf[i];
					ind = i + 1;
				}
			}
		}
	}
	left--;

	for(int i = ind; i < len; i++){
		if (buf[i] >= '0' && buf[i] <= '9'){
			if(buf[i] > high12){
				high12 = buf[i];
			}
		}
	}

	char str[13];
	for(int _ = 0; _ < 13; _++){str[_] = 0;}
	str[0] = high1;
	str[1] = high2;
	str[2] = high3;
	str[3] = high4;
	str[4] = high5;
	str[5] = high6;
	str[6] = high7;
	str[7] = high8;
	str[8] = high9;
	str[9] = high10;
	str[10] = high11;
	str[11] = high12;
	
	long long unsigned int r = toInt_LL(str);
	Jolts_12 = Jolts_12 + r;
	return 0;
}

int ReadLine(char* buf){
	ReadString(buf);
	ReadString_12(buf);
	return 0;
}

int ReadFile(char* path){
	FILE* file;
	char buffer[BUFFER_SIZE];
	for (int _ = 0; _ < BUFFER_SIZE; _++){buffer[_] = 0;}

	file = fopen(path,"r");
	if (file == NULL){
		return -1;
	}

	int _ind = 0;
	while (!feof(file)){
		char c = fgetc(file);
		if(c == '\n'){
			ReadLine(buffer);
			for (int _ = 0; _ < BUFFER_SIZE; _++){buffer[_] = 0;}
			_ind = 0;
		}else{
			buffer[_ind++] = c;
		}
	}

	buffer[_ind - 1] = 0;
	ReadLine(buffer);
	for (int _ = 0; _ < BUFFER_SIZE; _++){buffer[_] = 0;}
	_ind = 0;

	fclose(file);
	return 0;
}

int main(void){
	ReadFile("ex.txt");
	printf("Jolts: %d, %llu\n",Jolts, Jolts_12);

	Jolts = 0;
	Jolts_12 = 0;
	ReadFile("data.txt");
	printf("Jolts: %d, %llu\n",Jolts, Jolts_12);
	return 0;
}