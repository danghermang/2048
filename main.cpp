#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <conio.h>
#define KB_UP 72
#define KB_DOWN 80
#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_ESCAPE 27
using namespace std;
void afisare(int a[])
{
    int k=0;
    for(int i=0;i<=15;i++)
    {
        if(k==4)
        {
            cout<<endl;
            k=0;
        }
        cout<<a[i]<<"\t";
        k++;
    }
    cout<<endl;
}
int main()
{
    int matrix[16]={0},newcell_1=0,newcell_2=0,new_val=0,count=0,KB_code=0,case_l=0,case_r=0,case_u=0,case_d=0,count_1=0,i,j,q;

    srand(time(NULL));
    newcell_1=rand()%15;
    do
    {
        newcell_2=rand()%15;
    }while(newcell_2==newcell_1);
    while(count!=2)
    {
        new_val=rand()%4 + 2;
        if(new_val==2||new_val==4)
            {
                if(matrix[newcell_1]==0)
                    {
                        matrix[newcell_1]=new_val;
                        count++;
                    }
                else
                {
                    matrix[newcell_2]=new_val;
                    count++;
                }
            }
    }
    afisare(matrix);
    count_1=0;
    while (count_1==0)
    {
        if(kbhit()){
            KB_code = getch();
            switch (KB_code)
            {
                case KB_LEFT:
                           {
                               for(i=0;i<4;i++)
                               {
                                   for(j=0;j<4;j++)
                                   {
                                       if(j<3)
                                       {
                                           if(matrix[i+j]==matrix[i+j+1])
                                           {
                                               matrix[i+j]+=matrix[i+j+1];
                                               matrix[i+j+1]=0;
                                               case_l=1;
                                           }
                                           if(matrix[i+j]==0)
                                           {
                                               for(q=j;q<4;q++)
                                               {
                                                   int aux;
                                                   aux=matrix[i+j];
                                                   matrix[i+j]=matrix[i+j+1];
                                                   matrix[i+j+1]=aux;

                                               }
                                           }
                                       }
                                   }
                               }
                               newcell_1=rand()%15;
                                while(count!=1)
                                    {
                                        new_val=rand()%4 + 2;
                                        if(new_val==2||new_val==4)
                                                if(matrix[newcell_1]==0)
                                                    {
                                                        matrix[newcell_1]=new_val;
                                                        count++;
                                                    }

                                    }
                           }
                break;

                case KB_RIGHT:
                           //Do something
                break;

                case KB_UP:
                           //Do something
                break;

                case KB_DOWN:
                           //Do something
                break;
                afisare(matrix);
            }
        }
    }
    return 0;
}
