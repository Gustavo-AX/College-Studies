#include<stdlib.h>
#include<stdio.h>

int main(){
FILE *file;
file=fopen("C:\\Users\\USER\\Desktop\\teste.txt", "r");
if(file==NULL){
printf("\nerro na abertura\n");
system("pause");
exit(1);
}
char c;
c=fgetc(file);
while(c!=EOF){
printf("%c", c);
c=fgetc(file);
}
printf("\nfim");
fclose(file);
}
