#include <stdio.h>
#include <inttypes.h>
#include <fcntl.h>
#include <unistd.h>

int32_t *read_counter = (int32_t *) READ_COUNTER_ADDR;
int main(void)
{
	FILE* file;
    	char str[50];
	char buf[50];

    	file=fopen("file_io.txt","w");
    	if(file==NULL){
        	printf("read file error!\n\r");
        	return 0;
    	}
	
	printf("enter the words you want to write into file:\n\r");
	scanf("%s",str);
   	printf("the string \"%s\" has written into the file\n\r",str);
    	fprintf(file,"%s",&str);
    	fclose(file);


    	file=fopen("file_io.txt", "r");
    	if(file==NULL){
        	printf("read file error!\n\r");
        	return 0;
    	}

    	fread(buf,sizeof(buf),1,file);
    	printf("\"%s\" is read from the file\n\r",buf);
    	fclose(file);

	return 0;
}
