#include<iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>// to acces windows library
using namespace std;
//....................prototypes start
void board();
int checkwin();
void clearScreen();
//....................prototypes End

//....................Data structures start
HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
//const int SIZE=10;
char array[10]= {'0','1','2','3','4','5','6','7','8','9'};
//....................Data structures End

main()
{
    int choice , player=1;
    char mark;
    int i;

    do
    {
        board();

        if(player%2==1)
        {
            player = 1;
        }
        else
        {
            player = 2;
        }
        cout<<"     Player 1 [X] \t Player 2 [O]"<<endl;
        cout<<"     ----------------------------\n";
        cout<<"     Player "<<player<<" enter number:";
        cin>>choice;

        if(player==1)
        {
            mark = 'X';
        }
        else if(player==2)
        {
            mark = 'O';
        }
        
        if(choice==1 && array[1]=='1')
        array[1]=mark;
        else if(choice==2 && array[2]=='2')
        array[2]=mark;
        else if(choice==3 && array[3]=='3')
        array[3]=mark;
        else if(choice==4 && array[4]=='4')
        array[4]=mark;
        else if(choice==5 && array[5]=='5')
        array[5]=mark;
        else if(choice==6 && array[6]=='6')
        array[6]=mark;
        else if(choice==7 && array[7]=='7')
        array[7]=mark;
        else if(choice==8 && array[8]=='8')
        array[8]=mark;
        else if(choice==9 && array[9]=='9')
        array[9]=mark;
        else
        {
            cout<<"Invalid move because you entered invalid number";
            player--;
            cin.ignore();
            cin.get();
        }

        i = checkwin();
        player++;

    }//End of while loop

    while(i== -1);
    board();
     if (i==1)
    {
        cout<<"==> \a Player "<<--player<<" win"<<endl;
    }
    else
    {
        cout<<"==> \a Game Draw";
        cin.ignore();
        cin.get();
    
    }
}//End of main
void board()
{
    clearScreen();
    cout<<"||==================================||\n";
    cout<<"||           TIC TAC TOE            ||\n";
    cout<<"||==================================||\n";
    cout<<"\n";
    cout<<"        Let's Start the game!       \n";
    cout<<"\t   ============="<<endl;
    cout<<"\t   | "<<array[1]<<" | "<<array[2]<<" | "<<array[3]<<" |"<<endl;
    cout<<"\t   | "<<"  | "<<"  | "<<"  |"<<endl;
    cout<<"\t   -------------"<<endl;
    cout<<"\t   | "<<array[4]<<" | "<<array[5]<<" | "<<array[6]<<" |"<<endl;
    cout<<"\t   | "<<"  | "<<"  | "<<"  |"<<endl;
    cout<<"\t   -------------"<<endl;
    cout<<"\t   | "<<array[7]<<" | "<<array[8]<<" | "<<array[9]<<" |"<<endl;
    cout<<"\t   | "<<"  | "<<"  | "<<"  |"<<endl;
    cout<<"\t   ============="<<endl<<endl;
    SetConsoleTextAttribute(h,11);
}

int checkwin()
{
    if(array[1]==array[2] && array[2]==array[3])
    return 1;
    else if(array[4]==array[5] && array[5]==array[6])
    return 1;
    else if(array[7]==array[8] && array[8]==array[9])
    return 1;
    else if(array[1]==array[4] && array[4]==array[7])
    return 1;
    else if(array[2]==array[5] && array[5]==array[8])
    return 1;
    else if(array[3]==array[6] && array[6]==array[9])
    return 1;
    else if(array[1]==array[5] && array[5]==array[9])
    return 1;
    else if(array[3]==array[5] && array[5]==array[7])
    return 1;
    else if(array[1]!='1' && array[2]!='2' && array[3]!='3' && array[4]!='4' && array[5]!='5' && array[6]!='6' && 
    array[7]!='7' && array[8]!='8' && array[9]!='9') 

    return 0;
    else
    {
        return -1;
    }
   SetConsoleTextAttribute(h,7);

}
void clearScreen()
{
    system("cls");
}//End of 5th function