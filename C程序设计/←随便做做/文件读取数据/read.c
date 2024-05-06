#include<stdio.h>
#include<stdlib.h>

int main() {
	
	FILE *in,*out;
	in = fopen("111.jpg","r");
	out = fopen("se111.txt","wb");
	char s[1024] = {0};
	while(!feof(in)){
		int c = fgetc(in);
		sprintf(s,"0x%x",c);
		fputs(s,out);
	}
    return 0;	
} 
