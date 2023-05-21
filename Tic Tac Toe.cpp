#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <windows.h>

using namespace std;

char square3[10] = {'o','1','2','3','4','5','6','7','8','9'}; // Array use for 3*3 game
char square4[16] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'}; //Array use for 4*4 game
char square5[25] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y'};// Array use for 5*5 game
int checkwin3();
void board3();
void game3();
int checkwin4();
void board4();
void game4();
int checkwin5();
void board5();
void game5();
int main (){
	
	system("Color 9E");
	
	int player = 1,i,choice,c=0;
    char mark;
    char PN1[25],PN2[25];
	int rounds,*pointer;
	char I='\0';
	char ch , choice1,choice2;
    int gametype;
	cout<<endl<<endl;
	
	do{
		cout<<"********************************************"<<endl;
	cout<<"     WELCOME TO  'TIC TAC TOE'  GAME"<<endl;
	cout<<"********************************************"<<endl;
	cout<<endl<<endl;
	cout<<"Enter player 1 Name:"; //Getting name as the input from player 1
	cin>>PN1;
    cout<<endl;
    cout <<"Enter player 2 Name:";// Getting name as the input from player 2
    cin>>PN2;
    cout<<endl;
    
    // Ask user to select the difficulty
    cout<<setw(15);
    cout<<"EASY"<<endl;
    cout<<setw(16);
    cout<<endl;
    cout<<"MEDIUM"<<endl;
    cout<<setw(15);
    cout<<endl;
    cout<<"HARD"<<endl;
    cout<<endl;
    cout<<"Select the Difficulty (If it is Easy enter 1 , Medium enter 2 , Hard enter 3) :"; 
    cin>>gametype;
    cout<<endl;
    
    //If user choice is "Easy"
    if(gametype==1){
    	//Player can first read the manual or directly play the game
    	cout<<"Enter 'u' to see the user manual or Enter 'c' to go to the game:";
	    cin>>I;
	ifstream inFile; 
    if(I=='U'||I=='u'){
		inFile.open("usermanual.3.txt");// Opening the Usermanual for 3*3 game in reading mode
	    if(pointer==NULL){
	    	
 		cout<<"Error in opening file!"<<endl;
 	}
	cout<<"\n User manual:"<<endl;
	cout<<endl;
	while(inFile>>noskipws>>ch)
        cout<<ch;
    inFile.close();
    cout<<endl;
    cout<<endl;
    cout<<"////Hope you get an idea about the game////"<<endl;
    cout<<endl;
    char c1;
	cout<<"Do you want to play the game??"<<endl;
	cout<<"If you want to play enter 'Y', If you want to exit enter 'N' :";
	cin>>c1;
	if(c1=='Y'|| c1=='y'){
	}
	else{
		return 0;
	}
	
	  
	}
	cout<<endl<<endl;
	
	
	if(I=='C'||I=='c'){
	}
    	do
    {
        board3();// call the function board3
        cout<<"please enter only 1 to 9 numbers"<<endl; 
        cout<<endl;
        player=(player%2)?1:2;

        cout << "Player " << player << ", enter a number:  "; 
        cin >> choice;
        
        // when player 1 enter a number the symbol X will display 
        if(player == 1){
            mark = 'X';
        }
        else{ //when player 2 enter a number the symbol O will display 
            mark = 'O';
        }
        
        // Mark the relevant box according to the user input number with the corresponding symbol
        if (choice == 1 && square3[1] == '1')

            square3[1] = mark;
        else if (choice == 2 && square3[2] == '2')

            square3[2] = mark;
        else if (choice == 3 && square3[3] == '3')

            square3[3] = mark;
        else if (choice == 4 && square3[4] == '4')

            square3[4] = mark;
        else if (choice == 5 && square3[5] == '5')

            square3[5] = mark;
        else if (choice == 6 && square3[6] == '6')

            square3[6] = mark;
        else if (choice == 7 && square3[7] == '7')

            square3[7] = mark;
        else if (choice == 8 && square3[8] == '8')

            square3[8] = mark;
        else if (choice == 9 && square3[9] == '9')

            square3[9] = mark;
        else if (choice<1 || choice>9 || choice=='\0')//If user input is not a numbers 1-9 or any other character then display invalid move
        {
            cout<<"Invalid move   \a";
            cout<<"Again enter the number:";
            cin.clear();
            cin.ignore();
            cin>>choice;
            square3[choice]=mark;
            
        }
        i=checkwin3();//calling the function to check the winner of the 3*3 game

        player++;
    }while(i==-1);
    int p1=0,p2=0;
    board3();// calling the function 
    if(i==1){
    	cout<<"congratulations!!!"<<" "<<"Player"<<" "<<--player<<" win "<<endl;// Displaying the winner of the game
        if(player==1){ // Increment the score of the winner
        	p1++;
        }
        	
		else{
			p2++;
		}
	}

        
    else
        cout<<".......Game draw.......\a"; //If there is no winner then display 
    cout<<endl;
    cout<<"score of "<<" "<<PN1<<" "<<":"<<p1<<endl;
	cout<<endl;	
	cout<<"score of "<<" "<<PN2<<" "<<":"<<p2<<endl;
	cout<<endl<<endl;
	cout<<"_______________________________________________"<<endl;
	cout<<endl;
	cout<<"            Thank you for playing              "<<endl;
	cout<<"_______________________________________________"<<endl;
	cout<<endl<<endl;
    cout << "\nDo You Want to Play Again? (Y / N): ";
    cin >> ch;
    cout<<endl<<endl;
    for(int i = 0; i < 10; i++){
    		square3[0]='1',square3[1]='2',square3[2]='3',square3[3]='4',square3[4]='5',square3[5]='6',square3[6]='7',square3[7]='8',
    		square3[8]='9';
	}
    //return 0;
}
    // If user choice is "medium"   
if(gametype==2){ 
	cout<<"Enter 'u' to see the user manual or Enter 'c' to go to the game:";// Opening the Usermanual for 4*4 game in reading mode
	cin>>I;
	
	ifstream inFile;
    if(I=='U'||I=='u'){
		inFile.open("usermanual.4.txt");
	    if(pointer==NULL){
	    	
 		cout<<"Error in opening file!"<<endl;
 	}
	cout<<"\n User manual:"<<endl;
	cout<<endl;
	while(inFile>>noskipws>>ch)
        cout<<ch;
    inFile.close();
    cout<<endl;
    cout<<endl;
    cout<<"////Hope you get an idea about the game////"<<endl;
    cout<<endl;
    char c1;
	cout<<"Do you want to play the game??"<<endl;
	cout<<"If you want to play enter 'Y', If you want to exit enter 'N' :";
	cin>>c1;
	if(c1=='Y'|| c1=='y'){
	}
	else{
		return 0;
	}
	}
	cout<<endl<<endl;
	
	if(I=='C'|| I=='c'){
    }
    do
    {
        board4();
        cout<<endl;
        cout<<"!!!!please enter only capital letters (A-P)!!!!"<<endl;
        cout<<endl;
        
        player=(player%2)?1:2;

        cout << "Player " << player << ", enter a number:  ";
        cin >> choice1;
        
        if(player == 1){// when player 1 enter a letter the symbol "1" will display 
            mark = '1';
        }
        else{
            mark = '0';// when player 2 enter a letter the symbol "0" will display 
        }
        // Mark the relevant box according to the user input letter with the corresponding symbol
        if (choice1 == 'A' && square4[0] == 'A')

            square4[0] = mark;
        else if (choice1 == 'B' && square4[1] == 'B')

            square4[1] = mark;
        else if (choice1 == 'C' && square4[2] == 'C')

            square4[2] = mark;
        else if (choice1 == 'D' && square4[3] == 'D')

            square4[3] = mark;
        else if (choice1 == 'E' && square4[4] == 'E')

            square4[4] = mark;
        else if (choice1 == 'F' && square4[5] == 'F')

            square4[5] = mark;
        else if (choice1 == 'G' && square4[6] == 'G')

            square4[6] = mark;
        else if (choice1 == 'H' && square4[7] == 'H')

            square4[7] = mark;
        else if (choice1 == 'I' && square4[8] == 'I')

            square4[8] = mark;
        else if (choice1 == 'J' && square4[9] == 'J')

            square4[9] = mark;
        else if (choice1 == 'K' && square4[10] == 'K')

            square4[10] = mark;
        else if (choice1 == 'L' && square4[11] == 'L')

            square4[11] = mark;
        else if (choice1 == 'M' && square4[12] == 'M')

            square4[12] = mark;
        else if (choice1 == 'N' && square4[13] == 'N')

            square4[13] = mark;
        else if (choice1 == 'O' && square4[14] == 'O')

            square4[14] = mark;
        else if (choice1 == 'P' && square4[15] == 'P')

            square4[15] = mark;
        
        else if (!(choice1=='A' || choice1=='B' ||choice1=='C'|| choice1=='D' ||choice1=='E' || choice1=='F' ||choice1=='G' || choice1=='H' ||choice1=='I' || choice1=='J' ||
		choice1=='K' || choice1=='L' ||choice1=='M' || choice1=='N' ||choice1=='O' || choice1=='P' ))
        {
            cout<<"Invalid move  \a"; // If the user input is not capital letters (A-P), then display
            cout<<"Again enter the number:";
            cin.clear();
            cin.ignore();
            cin>>choice1;
            square4[choice1]=mark;
            player--;
        }
        i=checkwin4();// Calling the function to check the winner

        player++;
    }while(i==-1);
    int p1=0,p2=0;
    board4();//calling the function 
    cout<<endl;
    if(i==1){
    	cout<<"congratulations!!!"<<" "<<"Player"<<" "<<--player<<" win "<<endl;
        if(player==1){
        	p1++;
        }
        	
		else{
			p2++;
		}
	}
	else
        cout<<".......Game draw.......\a";
    cout<<endl;
    cout<<"score of "<<" "<<PN1<<" "<<":"<<p1<<endl;
	cout<<endl;	
	cout<<"score of "<<" "<<PN2<<" "<<":"<<p2<<endl;
    cout<<endl<<endl;
	cout<<"_______________________________________________"<<endl;
	cout<<endl;
	cout<<"            Thank you for playing              "<<endl;
	cout<<"_______________________________________________"<<endl;
	cout<<endl<<endl;
    cout << "\nDo You Want to Play Again? (Y / N): ";
    cin >> ch;
    cout<<endl<<endl;
    for(int i = 0; i < 16; i++){
    		square4[0]='A',square4[1]='B',square4[2]='C',square4[3]='D',square4[4]='E',square4[5]='F',square4[6]='G',square4[7]='H',
    		square4[8]='I',square4[9]='J',square4[10]='K',square4[11]='L',square4[12]='M',square4[13]='N',square4[14]='O';
    		square4[15]='P';
	}
	
	system("Color B0");
	//return 0;
}
    //If user choice is "Hard"
if (gametype==3){
	cout<<"Enter 'u' to see the user manual or Enter 'c' to go to the game:";// Opening the Usermanual for 5*5 game in reading mode
	cin>>I;
	
	ifstream inFile;
    if(I=='U'||I=='u'){
		inFile.open("usermanual.5.txt");
	    if(pointer==NULL){
	    	
 		cout<<"Error in opening file!"<<endl;
 	}
	cout<<"\n User manual:"<<endl;
	cout<<endl;
	while(inFile>>noskipws>>ch)
        cout<<ch;
    inFile.close();
    cout<<endl;
    cout<<endl;
    cout<<"////Hope you get an idea about the game////"<<endl;
    cout<<endl;
    char c1;
	cout<<"Do you want to play the game??"<<endl;
	cout<<"If you want to play enter 'Y', If you want to exit enter 'N' :";
	cin>>c1;
	if(c1=='Y'|| c1=='y'){
	}
	}
	cout<<endl<<endl;
	
	if(I=='C'|| I=='c'){
    }
    do
    {
        board5();
        cout<<endl;
        cout<<"!!!!please enter only capital letters (A-Y)!!!!"<<endl;
        cout<<endl;
        
        player=(player%2)?1:2;

        cout << "Player " << player << ", enter a number:  ";
        cin >> choice2;
        
        if(player == 1){// when player 1 enter a letter the symbol "1" will display 
            mark = '1';
        }
        else{// when player 2 enter a letter the symbol "0" will display 
            mark = '0';
        }
        // Mark the relevant box according to the user input letter with the corresponding symbol
        if (choice2 == 'A' && square5[0] == 'A')

            square5[0] = mark;
        else if (choice2 == 'B' && square5[1] == 'B')

            square5[1] = mark;
        else if (choice2 == 'C' && square5[2] == 'C')

            square5[2] = mark;
        else if (choice2 == 'D' && square5[3] == 'D')

            square5[3] = mark;
        else if (choice2 == 'E' && square5[4] == 'E')

            square5[4] = mark;
        else if (choice2 == 'F' && square5[5] == 'F')

            square5[5] = mark;
        else if (choice2 == 'G' && square5[6] == 'G')

            square5[6] = mark;
        else if (choice2 == 'H' && square5[7] == 'H')

            square5[7] = mark;
        else if (choice2 == 'I' && square5[8] == 'I')

            square5[8] = mark;
        else if (choice2 == 'J' && square5[9] == 'J')

            square5[9] = mark;
        else if (choice2 == 'K' && square5[10] == 'K')

            square5[10] = mark;
        else if (choice2 == 'L' && square5[11] == 'L')

            square5[11] = mark;
        else if (choice2 == 'M' && square5[12] == 'M')

            square5[12] = mark;
        else if (choice2 == 'N' && square5[13] == 'N')

            square5[13] = mark;
        else if (choice2 == 'O' && square5[14] == 'O')

            square5[14] = mark;
        else if (choice2 == 'P' && square5[15] == 'P')

            square5[15] = mark;
        else if (choice2 == 'Q' && square5[16] == 'Q')

            square5[16] = mark;
        else if (choice2 == 'R' && square5[17] == 'R')

            square5[17] = mark;
         else if (choice2 == 'S' && square5[18] == 'S')

            square5[18] = mark;
         else if (choice2 == 'T' && square5[19] == 'T')

            square5[19] = mark;
         else if (choice2 == 'U' && square5[20] == 'U')

            square5[20] = mark;
         else if (choice2 == 'V' && square5[21] == 'V')

            square5[21] = mark;
         else if (choice2 == 'W' && square5[22] == 'W')

            square5[22] = mark;
         else if (choice2 == 'X' && square5[23] == 'X')

            square5[23] = mark;
         else if (choice2 == 'Y' && square5[24] == 'Y')

            square5[24] = mark;
        else if (!(choice2=='A' || choice2=='B' ||choice2=='C'|| choice2=='D' ||choice2=='E' || choice2=='F' ||choice2=='G' || choice2=='H' ||choice2=='I' || choice2=='J' ||
		choice2=='K' || choice2=='L' ||choice2=='M' || choice2=='N' ||choice2=='O' || choice2=='P'|| choice2=='Q'|| choice2=='R'|| choice2=='S'
		|| choice2=='T'|| choice2=='U'|| choice2=='V'|| choice2=='W'|| choice2=='X'|| choice2=='Y' ))
        {
            cout<<"Invalid move  \a"; // If the user input is not capital letters (A-Y), then display
            cout<<"Again enter the number:";
            cin.clear();
            cin.ignore();
            cin>>choice2;
            square5[choice2]=mark;
            player--;
        
        }
        i=checkwin5(); //Calling the function to check the winner of game 5*5

        player++;
    }while(i==-1);
    int p1=0,p2=0;
    board5();
    cout<<endl;
    if(i==1){
    	cout<<"congratulations!!!"<<" "<<"Player"<<" "<<--player<<" win "<<endl;
        if(player==1){
        	p1++;
        }
        	
		else{
			p2++;
		}
	}
	else
        cout<<".......Game draw.......\a";
    cout<<endl;
    cout<<"score of "<<" "<<PN1<<" "<<":"<<p1<<endl;
	cout<<endl;	
	cout<<"score of "<<" "<<PN2<<" "<<":"<<p2<<endl;
    cout<<endl<<endl;
	cout<<"_______________________________________________"<<endl;
	cout<<endl;
	cout<<"            Thank you for playing              "<<endl;
	cout<<"_______________________________________________"<<endl;
	cout<<endl<<endl;
    cout << "\nDo You Want to Play Again? (Y / N): ";
    cin >> ch;
    cout<<endl<<endl;
	for(int i = 0; i < 25; i++){
    		square5[0]='A',square5[1]='B',square5[2]='C',square5[3]='D',square5[4]='E',square5[5]='F',square5[6]='G',square5[7]='H',
    		square5[8]='I',square5[9]='J',square5[10]='K',square5[11]='L',square5[12]='M',square5[13]='N',square5[14]='O';
    		square5[15]='P',square5[16]='Q',square5[17]='R',square5[18]='S',square5[19]='T',square5[20]='U',square5[21]='V',
			square5[22]='W',square5[23]='X',square5[24]='Y';
	}	
}
	}while(ch != 'n' && ch != 'N');

}
//Function delaration for check the winner of game 3*3
int checkwin3()
{
    if (square3[1] == square3[2] && square3[2] == square3[3])

        return 1;
    else if (square3[4] == square3[5] && square3[5] == square3[6])

        return 1;
    else if (square3[7] == square3[8] && square3[8] == square3[9])

        return 1;
    else if (square3[1] == square3[4] && square3[4] == square3[7])

        return 1;
    else if (square3[2] == square3[5] && square3[5] == square3[8])

        return 1;
    else if (square3[3] == square3[6] && square3[6] == square3[9])

        return 1;
    else if (square3[1] == square3[5] && square3[5] == square3[9])

        return 1;
    else if (square3[3] == square3[5] && square3[5] == square3[7])

        return 1;
    
    else if (square3[1] != '1' && square3[2] != '2' && square3[3] != '3' 
                  && square3[4] != '4' && square3[5] != '5' && square3[6] != '6' 
                  && square3[7] != '7' && square3[8] != '8' && square3[9] != '9')

        return 0;
    else
        return -1;
}


//Function declaration to display the board of game 3*3
void board3()
{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		system("Color 0C");
		
	system("cls");
    cout <<"\n\n\tTic Tac Toe\n\n";
    cout   <<"Player 1 (X)  -  Player 2 (O)" << endl << endl;
   
    cout << endl;
    cout<<setw(20);
    
      HANDLE console_color;
	console_color = GetStdHandle(
		STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(
			console_color, 11);
			
    cout << "     |     |     " << endl;
    cout<<setw(5);
    cout << "  " << square3[1] << "  |  " << square3[2] << "  |  " << square3[3] << endl;
    cout<<setw(20);
    cout << "_____|_____|_____" << endl;
    cout<<setw(20);
    
      SetConsoleTextAttribute(
			console_color, 10);
			
    cout << "     |     |     " << endl;
    cout<<setw(5);
    cout << "  " << square3[4] << "  |  " << square3[5] << "  |  " << square3[6] << endl;
    cout<<setw(20);
    cout << "_____|_____|_____" << endl;
    cout<<setw(20);
    
      SetConsoleTextAttribute(hConsole,
    FOREGROUND_RED);
    
    cout << "     |     |     " << endl;
    cout<<setw(5);
    cout << "  " << square3[7] << "  |  " << square3[8] << "  |  " << square3[9] << endl;
    cout<<setw(20);
    cout << "     |     |     " << endl << endl;
    
    	SetConsoleTextAttribute(
			console_color, 31);
}

//Fuction declaration for check the winner of game 4*4
int checkwin4()
{
    if (square4[0] == square4[1] && square4[1] == square4[2] && square4[2]== square4[3])

        return 1;
    else if (square4[4] == square4[5] && square4[5] == square4[6] && square4[6]== square4[7])

        return 1;
    else if (square4[8] == square4[9] && square4[9] == square4[10] && square4[10]== square4[11])

        return 1;
    else if (square4[12] == square4[13] && square4[13] == square4[14] && square4[14]== square4[15])
        return 1;
    else if (square4[0] == square4[4] && square4[4] == square4[8] && square4[8]==square4[12])

        return 1;
    else if (square4[1] == square4[5] && square4[5] == square4[9] && square4[9]==square4[13])

        return 1;
    else if (square4[2] == square4[6] && square4[6] == square4[10] && square4[10]==square4[14])

        return 1;
    else if (square4[3] == square4[7] && square4[7] == square4[11] && square4[11]==square4[15])

        return 1;
    else if (square4[0] == square4[5] && square4[5] == square4[10] && square4[10]==square4[15])

        return 1;
    else if (square4[3] == square4[6] && square4[6] == square4[9] && square4[9]==square4[12])

        return 1;
    else if (square4[0]== square4[3] && square4[3]==square4[12] && square4[12]==square4[15] && square4[0]==square4[15])
        
		return 1;
	else if (square4[0]==square4[1] && square4[1]==square4[5] && square4[5]==square4[4] && square4[4]==square4[0])
	
	    return 1;
	else if (square4[2]==square4[3] && square4[3]==square4[7] && square4[7]==square4[6] && square4[6]==square4[2])
	
	    return 1;
	else if (square4[1]==square4[2] && square4[2]==square4[6] && square4[6]==square4[5] && square4[5]==square4[1])
	
	    return 1;
	else if (square4[8]==square4[9] && square4[9]==square4[13] && square4[13]==square4[12] && square4[12]==square4[8])
	
	    return 1;
	else if (square4[10]==square4[11] && square4[11]==square4[15] && square4[15]==square4[14] && square4[14]==square4[10])
	
	    return 1;
	else if (square4[9]==square4[10] && square4[10]==square4[14] && square4[14]==square4[13] && square4[13]==square4[9])
	
	    return 1;
	else if (square4[4]==square4[5] && square4[5]==square4[9] && square4[9]==square4[8] && square4[8]==square4[4])
	
	    return 1;
	else if (square4[6]==square4[7] && square4[7]==square4[11] && square4[11]==square4[10] && square4[10]==square4[6])
	
	    return 1;
	else if (square4[5]==square4[6] && square4[6]==square4[10] && square4[10]==square4[9] && square4[9]==square4[5])
	
	    return 1;
    else if (square4[0]!='A' &&square4[1] != 'B' && square4[2] != 'C' && square4[3] != 'D' 
                  && square4[4] != 'E' && square4[5] != 'F' && square4[6] != 'G' 
                  && square4[7] != 'H' && square4[8] != 'I' && square4[9] != 'J'&& square4[10]!='K'&& square4[11]!='L'&& square4[12]!='M'
				  && square4[13]!='N'&& square4[14]!='O'&& square4[15]!='P')

        return 0;
    else
        return -1;
}

//function declaration to display the board for game 4*4
void board4()
{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("Color 7A");
    
	system("cls");
    
    cout << "\n\n\tTic Tac Toe\n\n";
    cout << "Player 1 (1)  -  Player 2 (0)" << endl << endl;
    
    cout << endl;

    cout << endl;
    cout<<setw(25);
       HANDLE console_color;
	console_color = GetStdHandle(
		STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(
			console_color, 112); 
	cout<<setw(25);
    cout << "     |     |     |     " << endl;
    cout<<setw(4);
    cout << "  " << square4[0] << "  |  " << square4[1] << "  |  " << square4[2] << "  |  " << square4[3] << "  " << endl;
    cout<<setw(25);
    cout << "_____|_____|_____|_____" << endl;
    cout<<setw(25);
    
	SetConsoleTextAttribute(
			console_color, 114);
				
    cout << "     |     |     |     " << endl;
    cout<<setw(4);
	cout << "  " << square4[4] << "  |  " << square4[5] << "  |  " << square4[6] << "  |  " << square4[7] << "  " << endl;
    cout<<setw(25);
    cout << "_____|_____|_____|_____" << endl;
    
    SetConsoleTextAttribute(
			console_color, 113);
	cout<<setw(25);		
    cout << "     |     |     |     " << endl;
    cout<<setw(4);
     cout << "  " << square4[8] << "  |  " << square4[9] << "  |  " << square4[10] << "  |  " << square4[11] << "  " << endl;
    cout<<setw(25);
    cout << "_____|_____|_____|_____" << endl;
    
     SetConsoleTextAttribute(
			console_color, 116);
	cout<<setw(25);
    cout << "     |     |     |     " << endl;
    cout<<setw(4);
    cout << "  " << square4[12] << "  |  " << square4[13] << "  |  " << square4[14] << "  |  " << square4[15] << "  " << endl;
    cout<<setw(25);
    cout << "     |     |     |     " << endl;
    SetConsoleTextAttribute(
			console_color, 125);   
    
    
}

//function declaration to check the winner of game 5*5
int checkwin5()
{
    if (square5[0] == square5[1] && square5[1] == square5[2] && square5[2]== square5[3] && square5[3]== square5[4])

        return 1;
    else if (square5[5] == square5[6] && square5[6] == square5[7] && square5[7]== square5[8] && square5[8]== square5[9])

        return 1;
    else if (square5[10] == square5[11] && square5[11] == square5[12] && square5[12]== square5[13] && square5[13]== square5[14])

        return 1;
    else if (square5[15] == square5[16] && square5[16] == square5[17] && square5[17]== square5[18] && square5[18]== square5[19])
        return 1;
    else if (square5[20] == square5[21] && square5[21] == square5[22] && square5[22]== square5[23] && square5[23]== square5[24])

        return 1;
    else if (square5[0] == square5[5] && square5[5] == square5[10] && square5[10]==square5[15] && square5[15]==square5[20])

        return 1;
     else if (square5[1] == square5[6] && square5[6] == square5[11] && square5[11]==square5[16] && square5[16]==square5[21])

        return 1;
    else if (square5[2] == square5[7] && square5[7] == square5[12] && square5[12]==square5[17] && square5[17]==square5[22])

        return 1;
    else if (square5[3] == square5[8] && square5[8] == square5[13] && square5[13]==square5[18] && square5[18]==square5[23])

        return 1;
    else if (square5[4] == square5[9] && square5[9] == square5[14] && square5[14]==square5[19] && square5[19]==square5[24])

        return 1;
    else if (square5[0]== square5[6] && square5[6]==square5[12] && square5[12]==square5[18] && square5[18]==square5[24])
        
		return 1;
	else if (square5[4]==square5[8] && square5[8]==square5[12] && square5[12]==square5[16] && square5[16]==square5[20])
	
	    return 1;
	else if (square5[0]==square5[1] && square5[1]==square5[2] && square5[2]==square5[7] && square5[7]==square5[6] && square5[6]==square5[5] && square5[5]==square5[0]
	&& square5[7]==square5[12] && square5[12]==square5[11] && square5[11]==square5[10] && square5[10]==square5[5] )
	
	    return 1;
	else if (square5[10]==square5[11] && square5[11]==square5[12] && square5[12]==square5[17] && square5[17]==square5[16] && square5[16]==square5[15] && square5[15]==square5[10]
	&& square5[17]==square5[22] && square5[22]==square5[21] && square5[21]==square5[20] && square5[20]==square5[15] )
	
	    return 1;
	else if (square5[2]==square5[3] && square5[3]==square5[4] && square5[4]==square5[9] && square5[9]==square5[8] && square5[8]==square5[7] && square5[7]==square5[2]
	&& square5[9]==square5[14] && square5[14]==square5[13] && square5[13]==square5[12] && square5[12]==square5[7] )
	
	    return 1;
	else if (square5[12]==square5[13] && square5[13]==square5[14] && square5[14]==square5[19] && square5[19]==square5[18] && square5[18]==square5[17] && square5[17]==square5[12]
	&& square5[19]==square5[24] && square5[24]==square5[23] && square5[23]==square5[22] && square5[22]==square5[17] )
	
	    return 1;
	else if (square5[6]==square5[7] && square5[7]==square5[8] && square5[8]==square5[13] && square5[13]==square5[12] && square5[12]==square5[11] && square5[11]==square5[6]
	&& square5[13]==square5[18] && square5[18]==square5[17] && square5[17]==square5[16] && square5[16]==square5[11] )
	
	    return 1;
	
    else if (square5[0]!='A' &&square5[1] != 'B' && square5[2] != 'C' && square5[3] != 'D' 
                  && square5[4] != 'E' && square5[5] != 'F' && square5[6] != 'G' 
                  && square5[7] != 'H' && square5[8] != 'I' && square5[9] != 'J'&& square5[10]!='K'&& square5[11]!='L'&& square5[12]!='M'
				  && square5[13]!='N'&& square5[14]!='O'&& square5[15]!='P'&& square5[16]!='Q'&& square5[17]!='R'&& square5[18]!='S'
				  && square5[19]!='T'&& square5[20]!='U'&& square5[21]!='V'&& square5[22]!='W'&& square5[23]!='X'&& square5[24]!='Y')

        return 0;
    else
        return -1;
}

//function declaration to display board of 5*5
void board5()
{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		system("Color B0");
		
	system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (1)  -  Player 2 (0)" << endl << endl;
    cout << endl;

    cout << endl;
    cout<<setw(15);
     HANDLE console_color;
	console_color = GetStdHandle(
		STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(
			console_color, 176);
    cout << "             |     |     |     |     " << endl;
    cout<<setw(10);
    cout << "  " << square5[0] << "  |  " << square5[1] << "  |  " << square5[2] << "  |  " << square5[3] << "  |  " << square5[4] << "  " << endl;
    cout<<setw(20);
    cout << "        _____|_____|_____|_____|_____" << endl;
    
     SetConsoleTextAttribute(
			console_color, 180);
			
    cout<<setw(20);
    cout << "             |     |     |     |     " << endl;
    cout<<setw(10);
	cout << "  " << square5[5] << "  |  " << square5[6] << "  |  " << square5[7] << "  |  " << square5[8] << "  |  " << square5[9] << "  "<< endl;
    cout<<setw(20);
    cout << "        _____|_____|_____|_____|_____" << endl;
    
     SetConsoleTextAttribute(
			console_color, 177);
			
    cout<<setw(20);
    cout << "             |     |     |     |     " << endl;
    cout<<setw(10);
    cout << "  " << square5[10] << "  |  " << square5[11] << "  |  " << square5[12] << "  |  " << square5[13] << "  |  " << square5[14] << "  "<< endl;
    cout<<setw(20);
    cout << "        _____|_____|_____|_____|_____" << endl;
    
     SetConsoleTextAttribute(
			console_color, 181);
			
    cout<<setw(20);
    cout << "             |     |     |     |     " << endl;
    cout<<setw(10);
    cout << "  " << square5[15] << "  |  " << square5[16] << "  |  " << square5[17] << "  |  " << square5[18] << "  |  " << square5[19] << "  "<< endl;
    cout<<setw(20);
    cout << "        _____|_____|_____|_____|_____" << endl;
    
     SetConsoleTextAttribute(
			console_color, 188);
			
    cout<<setw(20);
    cout << "             |     |     |     |     " << endl;
    cout<<setw(10);
    cout << "  " << square5[20] << "  |  " << square5[21] << "  |  " << square5[22] << "  |  " << square5[23] << "  |  " << square5[24] << "  "<< endl;
    cout<<setw(20);
    cout << "             |     |     |     |     " << endl;
    
    SetConsoleTextAttribute(
			console_color, 191);
    
}


