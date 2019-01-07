#include<stdio.h>  
#include<stdbool.h>
void findDirection(char [][8],int,int,int,int,char);
bool checkLimit(int,int);
void findMine(char [][8],char);
void printField(char [][8]);
int main(int argc,char* argv[]){
    char field[8][8],player;
    int i,j;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            field[i][j]=argv[i+1][j];
	player=argv[9][0];		
    findMine(field,player);
    printField(field);
return 0;
}
bool checkLimit(int r,int c){
	if(r>=0 && c>=0 && r<8 && c<8)
		return true;
	else
		return false;	
}

void findDirection(char field[][8],int r,int c,int row,int col,char player){
	int count=0,opposit;
	if(player=='1')
		opposit='2';
	else
		opposit='1';	
	while(checkLimit(r+(count*row),c+(count*col))){
		if(field[r+(count*row)][c+(count*col)] == '0'){
			break;
		}
		if(field[r+(count*row)][c+(count*col)] == opposit){                      
			if(checkLimit(r+((count+1)*row),c+((count+1)*col)) && field[r+((count+1)*row)][c+((count+1)*col)]=='0')
                field[r+((count+1)*row)][c+((count+1)*col)]='*';
			break;
        }
        count++;
	}
} 

void findMine(char field[][8],char player){
	int i,j;
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			if(field[i][j]==player){
				int row,col;
				for(row=-1;row<=1;row++)
					for(col=-1;col<=1;col++){
						if(row==0 && col==0);
						else if(checkLimit(i+row,j+col))
							findDirection(field,i+row,j+col,row,col,player);
					}
			}
}

void printField(char field[][8]){
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++)
            printf("%c ",field[i][j]);
        puts("");
    }
}