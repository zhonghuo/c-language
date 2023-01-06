#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int status[11][10001] = {};
void print(){
	int i, j;
	for(i=0; i<10; i++){
		printf("%d: ", status[i][0]);
		for(j=1; j<10000; j++){
			if(status[i][j] == 0 && j==1){
				printf("No card");
				break;
			}
			if(status[i][j] == 0)
			  break;  
			else{
				if(status[i][j+1] == 0)
				  printf("%d", status[i][j]);
				else
				  printf("%d ", status[i][j]);
			}  
		}
		printf("\n");
	}
}
int main(void){
	int i, j;
	char s[64];
	for(i=0; i<10; i++)
	  status[i][0] = i;
	while(scanf("%s", s) != EOF){
		int num, len;
		if(!strcmp(s, "all")){
			for(i=0; i<11; i++){
				for(j=1; j<10001; j++)
				  status[i][j] = 0;
			}
			scanf("%d %d", &num, &len);
			for(i=0; i<10; i++){
				for(j=1; j<len+1; j++)
				  status[i][j] = num;
			}
		}
		else if(!strcmp(s,"place")){
			scanf("%d %d", &num, &len);
			int *detail = (int*) malloc(sizeof(int)*len);
			for(i=0; i<len; i++)
				scanf("%d", &detail[i]);
			for(i=0; i<10; i++){
				if(status[i][0] == num){
					j = 1;
					while(j++<10000){
						if(status[i][j] == 0)
						  break;
						else
						  status[i][j] = 0;
					}
					for(j=1; j<len+1; j++)
					  status[i][j] = detail[j-1];
				}
			}
			free(detail);
		}
		
		else if(!strcmp(s, "swap")){
			int table_1, table_2;
			scanf("%d %d", &table_1, &table_2);
			for(i=1; i<10001; i++)
			  status[10][i] = status[table_1][i];
			for(i=1; i<10001; i++)
			  status[table_1][i] = status[table_2][i];
			for(i=1; i<10001; i++)
			  status[table_2][i] = status[10][i];
		}
		
		else if(!strcmp(s, "shiftleft")){
			for(i=1; i<10001; i++)
			  status[10][i] = status[0][i];
			j = 0;
			while(j<10){
			  for(i=1; i<10001; i++)
			    status[j][i] = status[j+1][i];	
			   j++;			
			}
        }

        else if(!strcmp(s, "shiftright")){
        	for(i=1; i<10001; i++)
        	  status[10][i] = status[9][i];
        	j = 9;
        	while(j>0){
        		for(i=1; i<10001; i++)
        		  status[j][i] = status[j-1][i];
        		j--;
			}
			for(i=1; i<10001; i++)
			  status[0][i] = status[10][i];	
		}
        else if(!strcmp(s, "clear")){
        	for(i=0; i<11; i++){
        		for(j=1; j<10001; j++)
        		  status[i][j] = 0;
			}	
		}
		else if(!strcmp(s, "print"))
			print();
		else if (!strcmp(s, "exit"))
            break;
	}
	return 0;
} 
