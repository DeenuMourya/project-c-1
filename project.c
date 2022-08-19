#include<stdio.h>
#include<stdlib.h>
void rules(void);//to display rules
void username(char[]);//to enter username
void shifting(int[][4]);//to shift numbers
void console(int[][4],char[],int);//to print the screen after shifting or refresh
void moves(int[][4],char[]);//creates decrease in the number of chances to shifting
void compare(int[][4],char[],int);//compares  matrix to our wanted condition
void judge(int);//check whether we win the game or loose the game
int main()
{
    int a[][4]={108,115,103,112,107,106,104,102,109,105,114,110,113,111,101,0};
    char ch[20];
    system("cls");
    username(ch);
    rules();
    moves(a,ch);

}
void rules(void)
{
    printf("\n\t\t:::::RULES OF THIS GAME:::::\n\n");
    printf("1. You can move only 1 step at a time by using keys\n");
    printf("Move UP      : By \'W\' key\nMove DOWN    : By \'S\' key\nMove LEFT    : By \'A\' key\n");
    printf("Move RIGHT   : By \'D\' key\n\n2. You can number only at \" 0\' s\" position only\n");
    printf("\n3. For each valid move: your total number of move will be decreased by 1\n\n");
    printf("4. Winning situation  : Numbers in a 4 X 4 matrix should be in order from 1 to 15\n\n");
    printf("\tWINNING SITUATION:\n|_______________________|\n| 101 | 102 | 103 | 104 |\n| 105 | 106 | 107 | 108 |\n");
    printf("| 109 | 110 | 111 | 112 |\n| 113 | 114 | 115 |  0  |\n|-----------------------|\n\n");
    printf("5. You can exit any time by pressing \'E\' or \'e\'");
    printf("\nSo Try to win in minimum number of moves\n\n\tHappy gaming , Good Luck\n\n");
    printf("PRESS :: Enter key to start.....");
    getchar();
}
void username(char ch[])
{
    printf("Enter your name::::::    ");
    fgets(ch,20,stdin);
}
void shifting(int a[][4])
{
    int i,j,m,n,temp;
    char key;
    for(i=0;i<4;i++)//for checking the position of 0 in array
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j]==0)
            {
                m=i;
                n=j;
            }
        }
    }
    fflush(stdin);
    scanf("%c",&key);
    switch(key)//make changes according to the pressed key
    {
        case 65:
        case 97:
        if(n!=0)
        {
            temp=a[m][n];
            a[m][n]=a[m][n-1];
            a[m][n-1]=temp;
        }
        break;
        case 68:
        case 100:
        if(n!=3)
        {
            temp=a[m][n];
            a[m][n]=a[m][n+1];
            a[m][n+1]=temp;
        }
        break;
        case 87:
        case 119:
        if(m!=0)
        {
            temp=a[m][n];
            a[m][n]=a[m-1][n];
            a[m-1][n]=temp;
        }
        break;
        case 83:
        case 115:
        if(m!=3)
        {
            temp=a[m][n];
            a[m][n]=a[m+1][n];
            a[m+1][n]=temp;
        }
        break;
        case 69:
        case 101:
            exit(0);
        default:
        printf("Invalid key");
    }
}
void console(int a[][4],char ch[],int m)
{
    system("cls");
    printf("\nHello  %s\nMoves remaining ::: %d\n",ch,m);//prints username and remaining chances
    int i,j;
    printf("\n|----|----|----|----|\n");//prints the game sceen
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            printf(" %d ",a[i][j]);
        }
        printf("\n|----|----|----|----|\n");
    }
    printf("\nPress Enter key after pressing key to continue\n");
}
void moves(int a[][4],char ch[])
{
    int m=30;
    do
    {
        system("cls");
        console(a,ch,m);
        shifting(a);
        compare(a,ch,m);
        m--;
    }while(m);//for repeating the screen until moves finish
    system("cls");
    console(a,ch,m);
    judge(0);
}
void compare(int a[][4],char ch[],int m)
{
    int b[4][4]={101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,0};//wanted output
    int i,j,flag=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j]==b[i][j])//comparing each elements
            flag++;//incresing flag to check equality
            else
            break;
        }

    }
      printf("\n%d\n",flag);
        getchar();
        if(flag==16)//when all elements are equal
       {
        console(a,ch,m);
        judge(1);}
}
void judge(int k)
{
    char b;
    if(k==1)//win or loose msg condition
       printf("\n::: YOU WON THE GAME :::\n");
    else
        printf("\n::: YOU LOOSE THE GAME :::\n");
    printf("\n Press \'y\' to play again ,OR \'n\' to quit\n");
    fflush(stdin);
    scanf("%c",&b);
    switch(b)//creating exit or restart key
    {
    case 'y':
    main();
    break;
    case 'n':
    exit(0);
    break;
    default:
    printf("Invalid key pressed ");
    exit(0);
    }
}
