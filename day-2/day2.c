#include <stdio.h>

#define BUFFER_SIZE 64
#define INTEGER_SIZE 28

static int Invalid_Ids = 0;
static long long unsigned int Invalid_Ids_Num = 0;

static int Invalid_Ids_P = 0;
static long long unsigned int Invalid_Ids_Num_P = 0;

// "####-####,"
// Read until ','
// "####-XXXX"
// Split at '-'
// "####" "XXXX"
// lower bound = smallest (####)
// upper bound = highest (XXXX)
// Check for repeat

long long int toInt(char* s){
	long long int r = 0;
	for (int i = 0; s[i] != 0; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			r = (r*10) + (s[i] - '0');
		}
	}
	return r;
}

int stlen(char* s){
	int r = 0;
	while (*s++){
		r++;
	}
	return r;
}

// 12341234
// Even chars (already asserted)
// len
// i and len/2 + i

int CheckStr(char* str){
	int len = stlen(str);
	int hlen = len/2;
	int r = 0;
	for (int i = 0; i < hlen; i++){
		r = r + !!(str[i] - str[i + hlen]);
	}
	
	return !r;
}

// Ranges
// 10^1 <= x < 10^2
// 10^3 <= x < 10^4
// 10^5 <= x < 10^6
// 10^7 <= x < 10^8
// 10^9 <= x <= INT_MAX

int CheckNum(long long int num){
	if(num < 10){
		return 0;
	}

	if(num >= 100 && num < 1000){
		return 0;
	}
	
	if(num >= 10000 && num < 100000){
		return 0;
	}

	if(num >= 1000000 && num < 10000000){
		return 0;
	}

	if(num >= 100000000 && num < 1000000000){
		return 0;
	}

	if(num >= 10000000000 && num < 100000000000){
		return 0;
	}

	if(num >= 10000000000 && num < 100000000000){
		return 0;
	}

	
	long long int n = num;
	char str[INTEGER_SIZE];
	char* sp = str;
	for (int _ = 0; _ < INTEGER_SIZE; _++){str[_] = 0;}
	*sp = '0';
	while (n > 0){
		*(sp++) = n % 10 + '0';
		n = n / 10;
	}

	return CheckStr(str);
}

// n = 3
int CheckStr_3(char* str){
	int len = stlen(str);
	int hlen = len/3;
	int r = 0; int r2 = 0;
	int r3 = 0; int r4 = 0;
	for (int i = 0; i < hlen; i++){
		r2 = str[i];
		r3 = str[i + hlen];
		r4 = str[i + 2*hlen];
		if (r2 != r3 || r2 != r4 || r3 != r4 ){
			r = 1;
		}
		
	}
	
	return !r;
}
int CheckNum_3(long long int num){
	if(num < 100){
		return 0;
	}

	if(num >= 1000 && num < 100000){
		return 0;
	}
	
	if(num >= 1000000 && num < 100000000){
		return 0;
	}

	if(num >= 1000000000){
		return 0;
	}
	
	long long int n = num;
	char str[INTEGER_SIZE];
	char* sp = str;
	for (int _ = 0; _ < INTEGER_SIZE; _++){str[_] = 0;}
	*sp = '0';
	while (n > 0){
		*(sp++) = n % 10 + '0';
		n = n / 10;
	}

	return CheckStr_3(str);
}

// n = 5
int CheckStr_5(char* str){
	int len = stlen(str);
	int hlen = len/5;
	int r = 0; int r2 = 0; int r3 = 0;
	int r4 = 0; int r5 = 0; int r6 = 0;
	for (int i = 0; i < hlen; i++){
		r2 = str[i];
		r3 = str[i + hlen];
		r4 = str[i + 2*hlen];
		r5 = str[i + 3*hlen];
		r6 = str[i + 4*hlen];
		if (r2 != r3 || r2 != r4 || r2 != r5 || r2 != r6 || r3 != r4 || r3 != r5 || r3 != r6 || r4 != r5 || r4 != r6 || r5 != r6 ){
			r = 1;
		}
	}
	
	return !r;
}
int CheckNum_5(long long int num){
	if(num < 10000){
		return 0;
	}

	if(num >= 100000 && num < 1000000000){
		return 0;
	}

	
	long long int n = num;
	char str[INTEGER_SIZE];
	char* sp = str;
	for (int _ = 0; _ < INTEGER_SIZE; _++){str[_] = 0;}
	*sp = '0';
	while (n > 0){
		*(sp++) = n % 10 + '0';
		n = n / 10;
	}

	return CheckStr_5(str);
}

// n = 7
int CheckStr_7(char* str){
	int len = stlen(str);
	int hlen = len/7;
	int r = 0; int r2 = 0; int r3 = 0; int r4 = 0;
	int r5 = 0; int r6 = 0; int r7 = 0; int r8 = 0;
	for (int i = 0; i < hlen; i++){
		r2 = str[i];
		r3 = str[i + hlen];
		r4 = str[i + 2*hlen];
		r5 = str[i + 3*hlen];
		r6 = str[i + 4*hlen];
		r7 = str[i + 5*hlen];
		r8 = str[i + 6*hlen];
		if (
			r2 != r3 || r2 != r4 || r2 != r5 || r2 != r6 || r2 != r7 || r2 != r8 ||
			r3 != r4 || r3 != r5 || r3 != r6 || r3 != r7 || r3 != r8 ||
			r4 != r5 || r4 != r6 || r4 != r7 || r4 != r8 ||
			r5 != r6 || r5 != r7 || r5 != r8 ||
			r6 != r7 || r6 != r8 ||
			r7 != r8
		){
			r = 1;
		}
	}
	
	return !r;
}
int CheckNum_7(long long int num){
	if(num < 1000000){
		return 0;
	}

	if(num >= 10000000){
		return 0;
	}
	
	long long int n = num;
	char str[INTEGER_SIZE];
	char* sp = str;
	for (int _ = 0; _ < INTEGER_SIZE; _++){str[_] = 0;}
	*sp = '0';
	while (n > 0){
		*(sp++) = n % 10 + '0';
		n = n / 10;
	}

	return CheckStr_7(str);
}

int AnalyzeRange(long long int n1, long long int n2){
	long long int upper, lower;
	if (n1 > n2){
		upper = n1; lower = n2;
	} else {
		upper = n2; lower = n1;
	}
	
	for (long long int i = lower; i <= upper; i++){
		if(CheckNum(i)){ // n = 2
			Invalid_Ids++;
			Invalid_Ids_Num = Invalid_Ids_Num + i;
			Invalid_Ids_P++;
			Invalid_Ids_Num_P = Invalid_Ids_Num_P + i;
			continue;
		}

		// n = 3
		if(CheckNum_3(i)){
			Invalid_Ids_P++;
			Invalid_Ids_Num_P = Invalid_Ids_Num_P + i;
			continue;
		}

		// n = 5
		if(CheckNum_5(i)){
			Invalid_Ids_P++;
			Invalid_Ids_Num_P = Invalid_Ids_Num_P + i;
			continue;
		}

		// n = 7
		if(CheckNum_7(i)){
			Invalid_Ids_P++;
			Invalid_Ids_Num_P = Invalid_Ids_Num_P + i;
		}
	}
	
	return 0;
}

int ReadLine(char* buf){
	long long int n1,n2;
	char str_n1[INTEGER_SIZE];
	char str_n2[INTEGER_SIZE];
	char* sp = str_n1;
	for (int _ = 0; _ < INTEGER_SIZE; _++){str_n1[_] = 0;}
	for (int _ = 0; _ < INTEGER_SIZE; _++){str_n2[_] = 0;}

	int _ind = 0;
	while (*(buf) != 0){
		if (*buf == '-'){
			sp = str_n2;
			buf++;
		}
		
		*(sp++) = *buf;
		buf++;
	}

	n1 = toInt(str_n1);
	n2 = toInt(str_n2);
	AnalyzeRange(n1,n2);

	return 0;
}

int ReadFile(char* path){
	FILE* file;
	char buffer[BUFFER_SIZE];
	for (int _ = 0; _ < BUFFER_SIZE; _++){buffer[_] = 0;}

	file = fopen(path,"r");
	if(file == NULL){
		return -1;
	}

	int _ind = 0;
	while (!feof(file)){
		char c = fgetc(file);
		if(c == ','){
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
	//ReadFile("ex.txt");
	//printf("Invalid Ids: [%d], Total[%llu]\n",Invalid_Ids,Invalid_Ids_Num);

	Invalid_Ids = 0;
	Invalid_Ids_Num = 0;
	Invalid_Ids_P = 0;
	Invalid_Ids_Num_P = 0;
	ReadFile("data.txt");
	printf("Invalid Ids: [%d], Total[%llu]\n",Invalid_Ids,Invalid_Ids_Num);
	printf("Invalid Ids P: [%d], Total[%llu]\n",Invalid_Ids_P,Invalid_Ids_Num_P);
	return 0;
}