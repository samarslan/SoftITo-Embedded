#include<stdio.h>


char* findChar(const char str[], size_t len,const char character) {
	char *c = NULL;

	for(size_t i=0;i<len;i++){
		if(str[i]==character){
			c = &str[i];
		}
	}
	return c;
}

int main(){

	size_t len = 10;
	char str[len];

	gets(str);

	char character;
	scanf("%c",&character);

	printf("%p",findChar(str,len,character));
}