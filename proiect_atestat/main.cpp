#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int a[4][4], ocupat,castigator=0;
int scor_0=0, scor_x=0;
int main();
void buton_play_again();
void buton_stop();
void creare_scor();
void creare_X(int x1, int y1, int x2, int y2)
{
    line(x1,y1,x2,y2);
    line(x1,y2,x2,y1);
    setcolor(WHITE);
}
void creare_0(int x,int y, int r)
{
    circle(x,y,r);
}

void aftergame()
{
    buton_play_again();
    buton_stop();
    setcolor(WHITE);
    creare_scor();
    while(!ismouseclick(WM_LBUTTONDBLCLK))
        delay(0);
    int x, y;
    getmouseclick(WM_LBUTTONDBLCLK, x, y);
    if(x>=550 && x<=700 && y>=10 && y<=40)
        main();
    if(x>=550 && x<=700 && y>45 && y<=80)
    {
        closegraph(ALL_WINDOWS);
    }
}

///conditii de egalitate+ afisare//////////////////////
int egal(int c)
{
    settextstyle(1, 0, 7);
    if(c==9 && castigator==0)
    {
        outtextxy(200, 80, "EGAL!");
        castigator=1;
    }
}
///afisare castigator///////////////////////////////
int castigator_0_text()
{
    settextstyle(1, 0, 7);
    if(castigator==0)
    {
        scor_0++;
        outtextxy(50, 80, "0 a castigat!");
        castigator=1;
    }
}
int castigator_x_text()
{
    settextstyle(1, 0, 7);
    if(castigator==0)
    {
        scor_x++;
        outtextxy(50, 80, "X a castigat!");
        castigator=1;
    }
}
///conditii de castig X////////////////////////////////////////////////////////////
void Castigator_X()
{
    if(a[1][1]==1 and a[1][2]==1 and a[1][3]==1)      castigator_x_text();
    else if(a[2][1]==1 and a[2][2]==1 and a[2][3]==1) castigator_x_text();
    else if(a[3][1]==1 and a[3][2]==1 and a[3][3]==1) castigator_x_text();
    else if(a[1][1]==1 and a[2][1]==1 and a[3][1]==1) castigator_x_text();
    else if(a[1][2]==1 and a[2][2]==1 and a[3][2]==1) castigator_x_text();
    else if(a[1][3]==1 and a[2][3]==1 and a[3][3]==1) castigator_x_text();
    else if(a[1][1]==1 and a[2][2]==1 and a[3][3]==1) castigator_x_text();
    else if(a[1][3]==1 and a[2][2]==1 and a[3][1]==1) castigator_x_text();
}
///conditii de castig 0////////////////////////////////////////////////////////////
void Castigator_0()
{
    if(a[1][1]==0 and a[1][2]==0 and a[1][3]==0)      castigator_0_text();
    else if(a[2][1]==0 and a[2][2]==0 and a[2][3]==0) castigator_0_text();
    else if(a[3][1]==0 and a[3][2]==0 and a[3][3]==0) castigator_0_text();
    else if(a[1][1]==0 and a[2][1]==0 and a[3][1]==0) castigator_0_text();
    else if(a[1][2]==0 and a[2][2]==0 and a[3][2]==0) castigator_0_text();
    else if(a[1][3]==0 and a[2][3]==0 and a[3][3]==0) castigator_0_text();
    else if(a[1][1]==0 and a[2][2]==0 and a[3][3]==0) castigator_0_text();
    else if(a[1][3]==0 and a[2][2]==0 and a[3][1]==0) castigator_0_text();
}
/// creare tabel scor/////////////////////////////////////////////////////////////////
void creare_scor()
{
    setcolor(WHITE);
    outtextxy(20,20,"Scor: ");
    char sx[100],s0[100];
    itoa(scor_x,sx,10);
    itoa(scor_0,s0,10);
    outtextxy(50,40,"x: ");
    outtextxy(75,40,sx);
    outtextxy(50,60,"0: ");
    outtextxy(75,60,s0);
}
///creare tabel////////////////////////////////////////////////////////////////////////

void creare_tabel()
{
    setcolor(YELLOW);
    settextstyle(1, 0, 3);
    outtextxy(290, 50, "X si 0");
    settextstyle(1, 0, 2);
    outtextxy(270, 100, "Incepe X!");
    settextstyle(1, 0, 1);
    line(100, 367, 601, 367);
    line(100, 534, 601, 534);
    line(267, 200, 267, 701);
    line(434, 200, 434, 701);
}
///jocul propriu-zis///////////////////////////////////////////////////////////////////
void joc()
{
    castigator=0;
    for(int i=1; i<=3; i++)
        for(int j=1; j<=3; j++)
            a[i][j]=2;

    for(int c=1; c<=9; c++)
    {
        ocupat=0;
        while(!ocupat && castigator==0)
        {
            while(!ismouseclick(WM_LBUTTONDBLCLK))
                delay(0);
            int x, y;
            getmouseclick(WM_LBUTTONDBLCLK, x, y);

            if(x>=100 && x<=267 && y>=200 && y<=367)
            {
                if(a[1][1]==2)
                {
                    if(c%2==1)
                    {
                        creare_X(130, 337, 237, 230);
                        a[1][1]=1;
                    }
                    else
                    {
                        creare_0((130+237)/2, (337+230)/2, 53.2);
                        a[1][1]=0;
                    }
                }
                else c--;
                ocupat=1;
            }

            if(x>=267 && x<=434 && y>=200 && y<=367)
            {
                if(a[1][2]==2)
                {
                    if(c%2==1)
                    {
                        creare_X(297, 337, 404, 230);
                        a[1][2]=1;
                    }
                    else
                    {
                        creare_0((297+404)/2, (337+230)/2, 53.2);
                        a[1][2]=0;
                    }
                }
                else c--;

                ocupat=1;
            }

            if(x>=434 && x<=601 && y>=200 && y<=367)
            {
                if(a[1][3]==2)
                {
                    if(c%2==1)
                    {
                        creare_X(464, 337, 571, 230);
                        a[1][3]=1;
                    }
                    else
                    {
                        creare_0((571+464)/2, (337+230)/2, 53.2);
                        a[1][3]=0;
                    }
                }
                else c--;

                ocupat=1;
            }

            if(x>=100 && x<=267 && y>=367 && y<=534)
            {
                if(a[2][1]==2)
                {
                    if(c%2==1)
                    {
                        creare_X(130, 504, 237, 397);
                        a[2][1]=1;
                    }
                    else
                    {
                        creare_0((130+237)/2, (504+397)/2, 53.2);
                        a[2][1]=0;
                    }
                }
                else c--;
                ocupat=1;
            }

            if(x>=267 && x<=434 && y>=367 && y<=534)
            {
                if(a[2][2]==2)
                {
                    if(c%2==1)
                    {
                        creare_X(297, 397, 404, 504);
                        a[2][2]=1;
                    }
                    else
                    {
                        creare_0((297+404)/2, (504+397)/2, 53.2);
                        a[2][2]=0;
                    }
                }
                else c--;
                ocupat=1;
            }

            if(x>=434 && x<=601 && y>=367 && y<=534)
            {
                if(a[2][3]==2)
                {
                    if(c%2==1)
                    {
                        creare_X(464, 397, 571, 504);
                        a[2][3]=1;
                    }
                    else
                    {
                        creare_0((571+464)/2, (504+397)/2, 53.2);
                        a[2][3]=0;
                    }
                }
                else c--;
                ocupat=1;
            }
            if(x>=100 && x<=267 && y>=534 && y<=701)
            {
                if(a[3][1]==2)
                {
                    if(c%2==1)
                    {
                        creare_X(130, 564, 237, 671);
                        a[3][1]=1;
                    }
                    else
                    {
                        creare_0((130+237)/2, (564+671)/2, 53.2);
                        a[3][1]=0;
                    }
                }
                else c--;
                ocupat=1;
            }

            if(x>=267 && x<=434 && y>=534 && y<=701)
            {
                if(a[3][2]==2)
                {
                    if(c%2==1)
                    {
                        creare_X(297, 671, 404, 564);
                        a[3][2]=1;
                    }
                    else
                    {
                        creare_0((297+404)/2, (564+671)/2, 53.2);
                        a[3][2]=0;
                    }
                }
                else c--;
                ocupat=1;
            }

            if(x>=434 && x<=601 && y>=534 && y<=701)
            {
                if(a[3][3]==2)
                {
                    if(c%2==1)
                    {
                        creare_X(464, 564, 571, 671);
                        a[3][3]=1;
                    }
                    else
                    {
                        creare_0((464+571)/2, (564+671)/2, 53.2);
                        a[3][3]=0;
                    }
                }
                else c--;
                ocupat=1;
            }
            Castigator_X();
            Castigator_0();
            egal(c);
            if(castigator==1)
                aftergame();
        }
    }
}
int main()
{
    initwindow(800, 900);
    creare_tabel();
    creare_scor();
    joc();
}
void buton_play_again()
{
    setcolor(LIGHTGREEN);
    settextstyle(1,0,2);
    outtextxy(550, 10, "PLAY AGAIN");
}
void buton_stop()
{
    setcolor(RED);
    settextstyle(1,0,2);
    outtextxy(550, 50, "STOP");
}


