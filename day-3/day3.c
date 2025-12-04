#include <stdio.h>

#define BUFFER_SIZE 128

static int Jolts = 0;

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

int ReadLine(char* buf){
	ReadString(buf);
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

	ReadLine(buffer);
	for (int _ = 0; _ < BUFFER_SIZE; _++){buffer[_] = 0;}
	_ind = 0;
	

	fclose(file);
	return 0;
}

int main(void){
	ReadFile("ex.txt");
	printf("Jolts: %d, %llu\n",Jolts);

	Jolts = 0;
	ReadFile("data.txt");
	printf("Jolts: %d\n",Jolts);
	return 0;
}