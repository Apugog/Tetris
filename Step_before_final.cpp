# include<iostream>
# include <stdio.h>
# include <conio.h>
# define h 20
# define w 11
int Land[w]={0},k=0,z=0;
char scr[h][w],img[h][w];
using namespace std;

void display_screen() //displays the global matrix scr
{
  int k,j=30;
     k=0;
     cout<<"                          ...TETRIS BY PRAMIT...\n";
    while(k<j)    //for centering the screen blank spaces
		   {
		   	 cout<<" ";
		   	 k++;
		   }
		   k=0;
	 while(k<w+1)    //for centering the screen blank spaces
		   {
		   	 cout<<"*";
		   	 k++;
		   }
		   k=0;
    cout<<"\n";	   
	for(int i=4;i<h;i++)
	{  k=0; 
	    while(k<j)    //for centering the screen blank spaces
		   {
		   	 cout<<" ";
		   	 k++;
		   }
		cout<<"<";
		for(int j=1;j<w;j++)
		{  
		  cout<<scr[i][j];
		}
		cout<<">";
		cout<<"\n";
	}	
	 k=0;
    while(k<j)    //for centering the screen blank spaces
		   {
		   	 cout<<" ";
		   	 k++;
		   }
		   k=0;
	 while(k<w+1)    //for centering the screen blank spaces
		   {
		   	 cout<<"*";
		   	 k++;
		   }
}
void initialize_screen() //intializes the screen with spaces
{
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			scr[i][j]=' ';
		}
	}
}
void swap(int i,int j,int l,int m) //moves a single point in screen by swapping blank spaces
{ 
    char temp;
  	temp = scr[i][j];
  	scr[i][j]=scr[l][m];
  	scr[l][m]=temp;
}
void delay(int i) //built delay function very rough aprroximation i=1 means 1sec delay
{ 
  int j,k;
   j=0;
	while(j<i)
	{   k=0;
		while(k<400000000)
		{
			k++;
		}
		j++;
	}
}
void transpose()  //transposes the entire screen matrix 
{  
   int x;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(i<j)
			{
			   x=scr[i][j];
			   scr[i][j]=scr[j][i];
			   scr[j][i]=x;
		    }
		}
	}	
}
void upside_down() //turns the screen matrix upside down
{
	int x;
  	for(int i=0;i<h/2;i++)
	{
		for(int j=0;j<w;j++)
		{
			x=scr[i][j];
			scr[i][j]=scr[h-i][j];
			scr[h-i][j]=x;
		}
	}	
}
void place_figure(int c,int d,char a[3][3])//places the figure in required position
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			scr[c+i][d+j]=a[i][j];
		}
	}
}
int move_down(int c,int d,char A[3][3])//makes the figure move down
{
	for(int i=2;i>=0;i--)
	{
		for(int j=2;j>=0;j--)
		{
		    if((c)==(h-3))
			{
		        return 1;
			}
			if((A[i][j]=='x'))
			{  	
			 swap(c+i,d+j,c+i+1,d+j);
			}
		}
	}
	return 0;
}
void calc_land() //it creates and array Land which contains data height of the below surface
{ 
    int j;
    for(int i=0;i<w;i++)
	{ j=0;
	  k=1;
	    while(k)
	    {
	    	if(scr[j][i]=='x'||j>h-1)
	    	{
	    		Land[i]=j-1;
	    		k=0;
			}
			j++;
		}
	}
}
int landed(int c,int d,char A[3][3])// it verifies that the next position of each points of the block equals to corresponding landing array value
{
  	for(int i=2;i>=0;i--)
	{
		for(int j=2;j>=0;j--)
		{
		    if((A[i][j]=='x'))
			{  	
			 if((c+i+1)==Land[d+j])
			     return 1;
			}
		}
	}
 return 0;	
}
void move_left(int c,int d,char A[3][3])// moves the figure left
{
   for(int j=0;j<3;j++)                          
   {
	    for(int i=2;i>=0;i--)	
		{
			if((d)<=(0))
			{
		       return ; 
			}
		    if((A[i][j]=='x'))
			{  	
			 swap(c+i,d+j,c+i,d+j-1);
			}
		}
   }
}
void move_right(int c,int d,char A[3][3])//moves the figure right
{
   for(int j=2;j>=0;j--)                          
   {
	    for(int i=2;i>=0;i--)	
		{
			if((d+3)>=(w))
			{
		       return ; 
			}
		    if((A[i][j]=='x'))
			{  	
			 swap(c+i,d+j,c+i,d+j+1);
			}
		}
   }
}
void initialize_image() //intializes the screen with spaces
{
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(scr[i][j]=='x')
			   img[i][j]='a';
			else
			   img[i][j]=' ';
		}
	}
}
void detect_side(int c,int d,char A[3][3])
{ int x;
  for(int i=2;i>=0;i--)
	{
		for(int j=2;j>=0;j--)
		{
			if((A[i][j]=='x'))
			{   z=0;
			 if(img[c+i][d+j+1]=='a'||img[c+i][d+j-1]=='a'||img[c+i+1][d+j+1]=='a'||img[c+i+1][d+j-1]=='a')
			    {
				 z=1;
				return;
			    }
		   }
		}
	}
}
int main()
{   
    int cha,x=0,y=w/2;
    char ch;
    initialize_screen();
    char A[3][3]={{' ','x','x'},
	              {' ',' ','x'},
	              {' ',' ','x'}};
    calc_land();
    place_figure(x,y,A);
    
    while(1)
    {  
	    for(int i=0;i<w;i++)
	    {
	    	if(Land[i]<5)
	    	{
	    	  system("cls");
	    	  cout<<"                           *************************\n";
	    	  cout<<"                           *       GAME ENDS       *\n";
	    	  cout<<"                           * BETTER LUCK NEXT TIME *\n";
	    	  cout<<"                           *************************";
	    	  exit(1);
			}
		}
		k=move_down(x,y,A);
        if(k==0&&landed(x,y,A)==0)
        {
		  x++;
		}
    	else
    	{ 	
		  calc_land();
		  initialize_image();
    	  x=0;
		  y=w/2;
		  place_figure(x,y,A);
		  k=0;	
		}
          if ( kbhit() )
            {
                ch = getch();
                cha = ch;
                if(cha=='a')
                {
                 if(z!=1)
				  {
				  move_left(x,y,A);
	              y--;
	              }
                }
                if(cha=='d')
                {
                 if(z!=1)
				  {
				  move_right(x,y,A);
	              y++;
	              }    
	            }
               ch='k';  
            }
    detect_side(x,y,A);
        if(y<0)
          y=0;
   else if(y+4>w)
          y=w-3;
    	display_screen();
    	delay(1);
    	system("cls");
    }
 return 0;
 }

