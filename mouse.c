
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
union REGS i,o;
 int gm,gd=DETECT;
 struct SREGS s;
void design()
{
setbkcolor(0);

setcolor(3);
setfillstyle(1,3);
circle(600,20,40);
floodfill(600,20,3);
setcolor(0);
setfillstyle(1,0);
circle(600,20,35);
floodfill(600,20,0);
setcolor(13);
setfillstyle(1,13);
circle(600,20,30);
floodfill(600,20,13);
setcolor(0);
setfillstyle(1,0);
circle(600,20,25);
floodfill(600,20,0);

setcolor(3);
setfillstyle(1,3);
circle(40,450,40);
floodfill(40,450,3);
setcolor(0);
setfillstyle(1,0);
circle(40,450,35);
floodfill(40,450,0);
setcolor(13);
setfillstyle(1,13);
circle(40,450,30);
floodfill(40,450,13);
setcolor(0);
setfillstyle(1,0);
circle(40,450,25);
floodfill(40,450,0);
/////////////////////////

settextstyle(4,0,5);
setcolor(15);
outtextxy(10,5,"===================");

settextstyle(4,0,5);
setcolor(15);
outtextxy(86,410,"====================");

settextstyle(4,1,5);
setcolor(15);
outtextxy(15,5,"==============");

settextstyle(4,1,5);
setcolor(15);
outtextxy(575,65,"==============");

}
void intro()
{
 design();
 settextstyle(0,0,8);
 setcolor(3);
 outtextxy(110,200,"WELCOME");
 settextstyle(1,0,2);
 setcolor(7);
 outtextxy(300,400,"Press enter to continue....");
 getch();
 cleardevice();
}
 void first()
{
 design();
 settextstyle(1,0,4);
 setcolor(3);
 outtextxy(260,75,"PROJECT");
 outtextxy(300,110,"ON");
 outtextxy(270,145,"MOUSE");
 outtextxy(220,180,"PROGRAMMING");
 settextstyle(1,0,2);
 setcolor(15);
 outtextxy(110,230,"Submitted to:-");
 outtextxy(365,230,"Submitted by;-");
 settextstyle(3,0,1);
 setcolor(13);
 outtextxy(110,280,"Dr.Mohit K.Sharma(H.O.D)");
 outtextxy(110,310,"Ms.Simrat Kaur");
 outtextxy(110,330,"(Project Guide)");
 outtextxy(365,280,"Kiranjot Kaur(5260)");
 outtextxy(365,310,"Harnoor Kaur(5257)");
 getch();
 cleardevice();
}
void introcg()
{
 design();
 settextstyle(1,0,5);
 setcolor(13);
 outtextxy(110,60,"COMPUTER GRAPHICS");
 settextstyle(3,0,2);
 setcolor(3);
 outtextxy(60,140,"Computer Graphics is an art of drawing pictures on");
 outtextxy(60,180,"computer screens with the help of programming. It");
 outtextxy(60,220,"involve computations, creations and manipulation of");
 outtextxy(60,260,"data. In other words, we can say that computer ");
 outtextxy(60,300,"graphics is a rendering tool for the generation and");
 outtextxy(60,340,"manipulation of images.");
 getch();
 cleardevice();
}
void mintro()
{
 design();

 settextstyle(1,0,5);
 setcolor(13);
 outtextxy(110,60,"MOUSE PROGRAMMING");
 settextstyle(3,0,2);
 setcolor(3);
 outtextxy(60,140,"* By default,the mouse pointer is not visible when");
 outtextxy(60,180,"  we run any C program.");
 outtextxy(60,220,"* We need  to implement the  concept  of mouse");
 outtextxy(60,260,"  programming to make the mouse pointer visible");
 outtextxy(60,300,"  on the output screen.");
 getch();
 cleardevice();
}
void commands()
{
 design();
 settextstyle(1,0,3);
 setcolor(13);
 outtextxy(60,60,"INTERRUPT:");
 settextstyle(3,0,1);
 setcolor(3);
 outtextxy(200,60,"0X33 interrupt is implemented for mouse");
 outtextxy(200,80,"cursor.");
 setcolor(13);
 rectangle(80,120,560,400);
 setcolor(13);
 line(150,120,150,400);
 line(80,150,560,150);
 settextstyle(3,0,1);
 setcolor(15);
 outtextxy(85,125,"Service");
 outtextxy(320,125,"Purpose");
 settextstyle(3,0,1);
 setcolor(3);
 outtextxy(110,150,"0     Reset mouse and get status.");
 outtextxy(110,180,"1     Show mouse pointer.");
 outtextxy(110,210,"2     Hide mouse pointer.");
 outtextxy(110,240,"3     Get mouse poistion and button status.");
 outtextxy(110,270,"4     Set mouse pointer poistion.");
 outtextxy(110,300,"7     Set horizontal limits for pointer.");
 outtextxy(110,330,"8     Set vertical limits for pointer.");
 getch();
 cleardevice();
}
void prgm1()
{
closegraph();
clrscr();
i.x.ax=1;
int86(0x33,&i,&o);
printf("Mouse Pointer In Text Mode......\n");
if(o.x.ax==0)
printf("\nNo mouse available....");
else
printf("Mouse Available....");
getch();
i.x.ax=2;
int86(0x33,&i,&o);
//cleardevice();
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
}
void prgm2()
{
 i.x.ax=1;
int86(0x33,&i,&o);
printf("Mouse Pointer In Graphics Mode......\n");
if(o.x.ax==0)
printf("\nNo mouse available....");
else
printf("Mouse Available....");
getch();
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
//initgraph(&gd,&gm,"C:\\TC\\BGI");
}
void show_mouse()
{
i.x.ax=1;
int86(0x33,&i,&o);
}
void hide_mouse()
{
 i.x.ax=2;
int86(0x33,&i,&o);
}
void get_mouse_pos(int *x,int *y,int *button)
{
i.x.ax=3;
int86(0x33,&i,&o);
*x=o.x.cx;
*y=o.x.dx;
*button=o.x.bx&1;
}
void prgm3()
{

 int button,x1,y1,x2,y2;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 i.x.ax=0;
 int86(0x33,&i,&o);
 settextstyle(0,0,2);
 outtextxy(20,10,"Free Hand Drawing");
 if(o.x.ax==0)
 {
  printf("No mouse is avialable...");
  restorecrtmode();
 }
 //outtextxy(230,400,"press any key to exit....");
 while(!kbhit())
 {
  show_mouse();
  get_mouse_pos(&x1,&y1,&button);
  x2=x1;
  y2=y1;
  while(button==1)
  {
  hide_mouse();
  line(x1,y1,x2,y2);
  x1=x2;
  y1=y2;
  get_mouse_pos(&x2,&y2,&button);
  }
 }
// restorecrtmode();
 getch();
 cleardevice();
 //closegraph();
 //initgraph(&gd,&gm,"C:\\TC\\BGI");
}


void mouse1()
{

int cursor[32]=
{
 0x0000,0x0000,0x0000,0x0000,
 0x8001,0xc003,0xf00f,0xfc3f,
 0xfc3f,0xf00f,0xc003,0x8001,
 0x0000,0x0000,0x0000,0x0000,

 0xffff,0x8001,0xffff,0x8001,
 0x4002,0x2004,0x1008,0x0240,
 0x0240,0x0810,0x2004,0x4002,
 0x8001,0xffff,0x8001,0xffff,
 };


 initgraph(&gd,&gm,"C:\\TURB0C3\\BGI");
 if(initmouse()==0)
 {
 closegraph();
 printf("\nMouse not installed!");
exit(1);
 }
 gotoxy(10,1);
 //printf("Mouse:..");
 settextstyle(0,0,2);
 outtextxy(20,10,"Mouse pointer 1: Hour Glass");
 changecursor(cursor);
 showmouseptr();
 getch();
}
 initmouse()
 {
 i.x.ax=0;
 int86(0x33,&i,&o);
 return(o.x.ax);
 }
 showmouseptr()
 {
 i.x.ax=1;
 int86(0x33,&i,&o);
 return 0;
 }

 changecursor(int*shape)
 {
 i.x.ax=9;
 i.x.bx=0;
 i.x.cx=0;
 i.x.dx=(unsigned)shape;
 segread(&s);
 s.es=s.ds;
 int86x(0x33,&i,&i,&s);
 return 0;
 }


void mouse2()
{
  int cursor[32]=
{
  0xe3c7,0xe3c7,0xe3c7,0xe3c7,
 0xe3c7,0xe3c7,0xe007,0xe007,
 0xe007,0xe007,0xe3c7,0xe3c7,
 0xe3c7,0xe3c7,0xe3c7,0xe3c7,

 0x1c38,0x1428,0x1428,0x1428,
 0x1428,0x1428,0x17e8,0x1008,
 0x1008,0x17e8,0x1428,0x1428,
 0x1428,0x1428,0x1428,0x1c38,
 };


 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 if(initmouse()==0)
 {
 closegraph();
 printf("\nMouse not installed!");
exit(1);
 }
 gotoxy(10,1);
 //printf("Mouse:..");
 settextstyle(0,0,2);
 outtextxy(20,10,"Mouse pointer 2: H alphabet");
 changecursor(cursor);
 showmouseptr();
 getch();
}
initmouse1()
 {
 i.x.ax=0;
 int86(0x33,&i,&o);
 return(o.x.ax);
 }
 showmouseptr1()
 {
 i.x.ax=1;
 int86(0x33,&i,&o);
 }
 changecursor1(int*shape)
 {
 i.x.ax=9;
 i.x.bx=0;
 i.x.cx=0;
 i.x.dx=(unsigned)shape;
 segread(&s);
 s.es=s.ds;
 int86x(0x33,&i,&i,&s);
 }

void mouse3()
{
  int cursor[32]=
{
  0x0e70,0x09d0,0x1188,0x1188,
 0x1008,0x1008,0x1008,0x1808,
 0x0810,0x0810,0x0c30,0x0420 ,
 0x0660,0x0240,0x03c0,0x0180,

 0xf18f,0xf007,0xe001,0xe001,
 0xe001,0xe001,0xe001,0xe001,
 0xf001,0xf001,0xf001,0xf81f,
 0xf81f,0xfc3f,0xfc3f,0xfe7f,
 };


 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 if(initmouse2()==0)
 {
 closegraph();
 printf("\nMouse not installed!");
exit(1);
 }
 gotoxy(10,1);
 //printf("Mouse:..");
 settextstyle(0,0,2);
 outtextxy(20,10,"Mouse pointer 3");
 changecursor2(cursor);
 showmouseptr2();
 getch();
}
initmouse2()
 {
i.x.ax=0;
int86(0x33,&i,&o);
 return(o.x.ax);
 }
showmouseptr2()
 {
i.x.ax=1;
 int86(0x33,&i,&o);
 }
changecursor2(int*shape)
 {
 i.x.ax=9;
 i.x.bx=0;
 i.x.cx=0;
 i.x.dx=(unsigned)shape;
 segread(&s);
 s.es=s.ds;
 int86x(0x33,&i,&i,&s);
 }


void mouse4()
{
  int cursor[32]=
{
  0x0000,0x1ff8,0x3808,0x2c0c,
 0x2604,0x4206,0xc302,0xe7fe,
 0x2402,0x2402,0x2402,0x2402,
 0x2402,0x3ffe,0x0000,0x0000,

 0xffff,0xf007,0xc007,0xc003,
 0xc003,0x8001,0x0001,0x0001,
 0xc001,0xc001,0xc001,0xc001,
 0xc001,0xc001,0xffff,0xffff,
 };


 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 if(initmouse3()==0)
 {
 closegraph();
 printf("\nMouse not installed!");
exit(1);
 }
 gotoxy(10,1);
 //printf("Mouse:..");
 settextstyle(0,0,2);
 outtextxy(20,10,"Mouse pointer 4");
 changecursor3(cursor);
 showmouseptr3();
 getch();
}
initmouse3()
 {
 i.x.ax=0;
 int86(0x33,&i,&o);
 return(o.x.ax);
 }
 showmouseptr3()
 {
 i.x.ax=1;
 int86(0x33,&i,&o);
 }
 changecursor3(int*shape)
 {
 i.x.ax=9;
 i.x.bx=0;
 i.x.cx=0;
 i.x.dx=(unsigned)shape;
 segread(&s);
 s.es=s.ds;
 int86x(0x33,&i,&i,&s);
 }


void mouse5()
{
  int cursor[32]=
{
  0xe3c7,0xe3c7,0xe3c7,0xe3c7,
 0xe3c7,0xe3c7,0xe007,0xe007,
 0xe007,0xe007,0xe3c7,0xe3c7,
 0xe3c7,0xe3c7,0xe3c7,0xe3c7,

 0x1c38,0x1428,0x1428,0x1428,
 0x1428,0x1428,0x17e8,0x1008,
 0x1008,0x17e8,0x1428,0x1428,
 0x1428,0x1428,0x1428,0x1c38,
 };


 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 if(initmouse4()==0)
 {
 closegraph();
 printf("\nMouse not installed!");
exit(1);
 }
 gotoxy(10,1);
 //printf("Mouse:..");
 settextstyle(0,0,2);
 outtextxy(20,10,"Mouse pointer 2: H alphabet");
 changecursor4(cursor);
 showmouseptr4();
 getch();
}
initmouse4()
 {
 i.x.ax=0;
 int86(0x33,&i,&o);
 return(o.x.ax);
 }
 showmouseptr4()
 {
 i.x.ax=1;
 int86(0x33,&i,&o);
 }
 changecursor4(int*shape)
 {
 i.x.ax=9;
 i.x.bx=0;
 i.x.cx=0;
 i.x.dx=(unsigned)shape;
 segread(&s);
 s.es=s.ds;
 int86x(0x33,&i,&i,&s);
 }

 void mouse6()
{
  int cursor[32]=
{
  0x03c0,0x0240,0x0240,0x0240,
 0x0240,0x0240,0xffff,0x8241,
 0x8241,0xffff,0x0240,0x0240,
 0x0240,0x0240,0x0240,0x03c0,

 0xfc3f,0xfdbf,0xfdbf,0xfdbf,
 0x7dbc,0xfdbf,0x0000,0x7dbe,
 0x7dbe,0x0000,0xfdbf,0xfdbf,
 0xfdbf,0xfdbf,0xfdbf,0xfc3f,
 };


 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 if(initmouse5()==0)
 {
 closegraph();
 printf("\nMouse not installed!");
exit(1);
 }
 gotoxy(10,1);
 //printf("Mouse:..");
 settextstyle(0,0,2);
 outtextxy(20,10,"Mouse pointer 6: ");
 changecursor5(cursor);
 showmouseptr5();
 getch();
}
initmouse5()
 {
 i.x.ax=0;
 int86(0x33,&i,&o);
 return(o.x.ax);
 }
 showmouseptr5()
 {
 i.x.ax=1;
 int86(0x33,&i,&o);
 }
 changecursor5(int*shape)
 {
 i.x.ax=9;
 i.x.bx=0;
 i.x.cx=0;
 i.x.dx=(unsigned)shape;
 segread(&s);
 s.es=s.ds;
 int86x(0x33,&i,&i,&s);
 }
void thanks()
{
 //closegraph();
//cleardevice();
// initgraph(&gd,&gm,"C:\\TC\\BGI");
 design();
 settextstyle(0,0,8);
 setcolor(3);
 outtextxy(160,150,"THANK");
 outtextxy(220,250,"YOU");
 getch();
 cleardevice();
}

void main()
{
 //int gm,gd=DETECT;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 //design();
 intro();
 first();
 introcg();
 mintro();
 commands();
 prgm1();
 prgm2();
 prgm3();
 mouse1();
 mouse2();
 mouse3();
 mouse4();
 mouse5();
 mouse6();
 closegraph();
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 getch();
 thanks();
 getch();
 closegraph();
}
