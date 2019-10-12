#include <iostream>
using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int choice;
char turn='X';
int row,column;


void display(){									//function to display the game board
	system ("CLS");
	cout<<"\n\t\t\t\tTIC TAC TOE\n\n";
	cout<<"\tPlayer 1[X]\n\tPlayer 2[O]\n\n";
	
	cout<<"\t\t  "<<"     |"<<"     |"<<"     "<<endl;
	cout<<"\t\t  "<<"  "<<board[0][0]<<"  |"<<"  "<<board[0][1]<<"  |"<<"  "<<board[0][2]<<"  "<<endl;
	cout<<"\t\t  "<<"_____|"<<"_____|"<<"_____"<<endl;
	cout<<"\t\t  "<<"     |"<<"     |"<<"     "<<endl;
	cout<<"\t\t  "<<"  "<<board[1][0]<<"  |"<<"  "<<board[1][1]<<"  |"<<"  "<<board[1][2]<<"  "<<endl;
	cout<<"\t\t  "<<"_____|"<<"_____|"<<"_____"<<endl;
	cout<<"\t\t  "<<"     |"<<"     |"<<"     "<<endl;
	cout<<"\t\t  "<<"  "<<board[2][0]<<"  |"<<"  "<<board[2][1]<<"  |"<<"  "<<board[2][2]<<"  "<<endl;
	cout<<"\t\t  "<<"     |"<<"     |"<<"     "<<endl;
	
	
}


void player_turn(){						//funtion to alternate player turn
	
	if(turn=='X'){
		cout<<"\n"<<"\t"<<"Player1 [X] turn\n\tEnter block Number:";
	}
	else if(turn=='O'){
		cout<<"\n"<<"\t"<<"Player2 [O] turn\n\tEnter block Number:";
	}
		
		
	cin>>choice;
	
/*	while(choice<0 || choice>9 || isdigit(choice)==0 ){
		while ((getchar()) != '\n');
		cout<<"\n\tInvalid input.. \n\tNumber should be between 1-9";
		cout<<"\n\tEnter again:";
		cin>>choice;
	}
*/
	switch(choice){
		case 1:row=0; column=0; break;
		case 2:row=0; column=1; break;
		case 3:row=0; column=2; break;
		case 4:row=1; column=0; break;
		case 5:row=1; column=1; break;
		case 6:row=1; column=2; break;
		case 7:row=2; column=0; break;
		case 8:row=2; column=1; break;
		case 9:row=2; column=2; break;
		default:
			cout<<"\n\tInvalid Choice\n\tPlease Try again!!\n\n";
			player_turn();
			return ;
			break;	
	}
	
	if(turn=='X'&&board[row][column]!='O'&&board[row][column]!='X'){			
		board[row][column]='X';
		turn ='O';
	}
	else if(turn=='O'&&board[row][column]!='O'&&board[row][column]!='X'){
		board[row][column]='O';
		turn ='X';
	}
	else if(choice>=1&&choice<=9){
		cout<<"\n\tBox already filled!!\n\tPlease Try again!!\n\n";
		player_turn();
	}
	display();
}



bool gameover(){								//checks if game is over
	int i,j;
	for(i=0;i<3;i++){
			if(board[i][0]==board[i][1]&&board[i][0]==board[i][2] || board[0][i]==board[1][i]&&board[0][i]==board[2][i])
				return false;
	}
	if(board[0][0]==board[1][1]&&board[0][0]==board[2][2]||board[1][1]==board[0][2]&&board[1][1]==board[2][0])
		return false;
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(board[i][j]!='X'||board[i][j]!='O')
				return true;
		}
	}
	

}



int main() {
	cout<<"\nWelocome to Tic Tac Toe";
	char ch='Y';
	do{		
		int ct=0;	
		display();
		while(ct<9){
			ct++;
			player_turn();
			if(gameover()==false)
				break;
		}
		
		if(turn =='X'&&gameover()==false)
			cout<<"Player2 [O].. WINS!!\n\n\n\n";
		else if(turn =='O'&&gameover()==false)
			cout<<"Player1 [X],, WINS!!\n\n\n\n";
		else{
			cout<<"It is a Draw..\n\n\n\n";
		}
		
		cout<<"Do you want to play again?(y/n):";
		cin>>ch;
		
		int i,j,resetter=1;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
					board[i][j]=resetter+48;
					resetter++;
			}
		}

	}
	while(ch=='y'||ch=='Y');
	
	
	
	return 0;
}
