#include<stdio.h>  
#include<stdbool.h>
void findDirection(char [][8],int,int,int,int);
bool checkLimit(int,int);
void findMine(char [][8]);
void printField(char [][8]);
int main(int argc,char* argv[]){
    char field[8][8];
    int i,j;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            field[i][j]=argv[i+1][j];
    findMine(field);
    printField(field);
return 0;
}
bool checkLimit(int r,int c){
	if(r>=0 && c>=0 && r<8 && c<8)
		return true;
	else
		return false;	
}

void findDirection(char field[][8],int r,int c,int row,int col){
	int count=0;
	while(checkLimit(r+(count*row),c+(count*col))){
		if(checkLimit(r+(count*row),c+(count*col)) && field[r+(count*row)][c+(count*col)] == '0'){
			break;
		}
		if(checkLimit(r+(count*row),c+(count*col)) && field[r+(count*row)][c+(count*col)] == '2'){
                                
			if(checkLimit(r+((count+1)*row),c+((count+1)*col)))
                field[r+((count+1)*row)][c+((count+1)*col)]='*';
			break;
        }
        count++;
	}
}

void findMine(char field[][8]){
	int i,j;
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			if(field[i][j]=='1'){
				int row,col;
				for(row=-1;row<=1;row++)
					for(col=-1;col<=1;col++){
						if(row==0 && col==0);
						else if(checkLimit(i+row,j+col))
							findDirection(field,i+row,j+col,row,col);
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