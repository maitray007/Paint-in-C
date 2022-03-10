#include<math.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>

int c=15,p=3,gdriver=DETECT,gmode;
int arrayline[10][4],arraybar[10][4],arrayrect[10][4],arraycircle[10][4];
void help();
void loading();
void logo();
int main2();
void clear();
int setcolor1();
int fpattern();
void bar1();
void eraser();
void fhand();
void brush();
void rect();
void line1();
void circle2();
void circle1();
void mouse(void);
void initmouse();
void showmp();
void hidemp();
int getmp(int *button,int *x,int *y);
void setmp();
void restrictmp( int x1, int y1, int x2, int y2);
int screen();
void button(int x1,int y1,int x2,int y2,char str[]);
int click(int x1,int y1,int x2,int y2,char str[]);
int press(int,int,int,int);
int unpress(int,int,int,int);


int main ()
{

	int h;
	initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
	cleardevice();
	setfillstyle(1,c);
	mouse();
return 0;
}




 void mouse(){
   initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
   cleardevice();
   initmouse();
   showmp();
   screen();

}

void initmouse(){
	union REGS i,o;
	i.x.ax=0x0;
	int86(0x33,&i,&o);
}

void showmp(){
	union REGS i,o;
	i.x.ax=0x1;
	int86(0x33,&i,&o);
}

void hidemp(){
	union REGS i,o;
	i.x.ax=0x2;
	int86(0x33,&i,&o);
}

int getmp(int *button,int *x,int *y){
	union REGS i,o;
	i.x.ax=0x3;
	int86(0x33,&i,&o);
	*button=o.x.bx;
	*x=o.x.cx;
	*y=o.x.dx;
return 0;
}

void setmp(){
	union REGS i,o;
	i.x.ax=0x4;
	i.x.cx=0;
	i.x.dx=0;
	int86(0x33,&i,&o);
}
void restrictmp( int x1, int y1, int x2, int y2)
{
   union REGS i,o;
   i.x.ax = 7;
   i.x.cx = x1;
   i.x.dx = x2;
   int86(0x33, &i, &o);

   i.x.ax = 8;
   i.x.cx = y1;
   i.x.dx = y2;
   int86(0x33, &i, &o);
}
void loading()
{
int i1,j1;
for(i1=220;i1<=380;i1++)
	       {
		 gotoxy(35,16);
		 printf("LOADING");

		 delay(10);
		 j1=210;
		 while(j1!=235)
		 {
		  putpixel(i1,j1,2);
		  j1++;
		 }
}
}
void clear()
{
clearviewport();
main2();
}
int setcolor1()
{
c++;
if(c>15)
c=0;
return(c);
}
int fpattern()
{
p++;
if(p>12)
p=0;
return(p);
}
void bar1()
{
 int x,y,b,leftpressed=0,point1check=0,i=0,j=0;
restrictmp(181,131,619,449);

	delay(500);
	while(!kbhit())
	{


		showmp();
		getmp(&b,&x,&y);

		if(b==1)
		{
			leftpressed=1;
			if(point1check==0)
			{	arraybar[i][0]=x;
				arraybar[i][1]=y;
				point1check=1;
			}
			arraybar[i][2]=x;
			arraybar[i][3]=y;

		}
		if(b==0 && leftpressed==1)
		{
			i++;
			point1check=0;
			leftpressed=0;
		}
		setfillstyle(p,c);
		for(j=0;j<i;j++)


		bar(arraybar[j][0],arraybar[j][1],arraybar[j][2],arraybar[j][3]);


	}
if(getch())
{
restrictmp(0,0,getmaxx(),getmaxy());
main2();
}
}




void eraser()
{
int b,x,y;

restrictmp(206,156,619,449);
showmp();


while(!kbhit())
	    {
	       getmp(&b,&x,&y);

	       while(b==1)
	       {
	       setfillstyle(SOLID_FILL, BLACK);
	       bar(x,y,x-25,y-25);


	       getmp(&b,&x,&y);

	      }
	     showmp();
	     }

if(getch())
{

restrictmp(0,0,getmaxx(),getmaxy());
main2();
}
}
void brush()
{
int b,x,y;

restrictmp(182,132,619,449);
showmp();


while(!kbhit())
	    {
	       getmp(&b,&x,&y);

	       while(b==1)
	       {
	       putpixel(x,y,c);
	       putpixel(x+1,y,c);
	       putpixel(x,y+1,c);
	       putpixel(x-1,y,c);
	       putpixel(x,y-1,c);
	       putpixel(x+1,y-1,c);
	       putpixel(x-1,y+1,c);
	       putpixel(x+1,y+1,c);
	       putpixel(x-1,y-1,c);
	       getmp(&b,&x,&y);

	      }
	     showmp();
	     }

if(getch())
{

restrictmp(0,0,getmaxx(),getmaxy());
main2();
}
}

void fhand()
{
int b,x,y,temp1,temp2;
setcolor(c);
restrictmp(181,131,619,449);
showmp();


while(!kbhit())
	    {
	       getmp(&b,&x,&y);
	       temp1 = x;
	       temp2 = y;
	       while(b==1)
	       {
	       line(temp1,temp2,x,y);

	       temp1 = x;
	       temp2 = y;
	       hidemp();
	       getmp(&b,&x,&y);
	       if(b==0)
	       showmp();
	      }
	      showmp();
	     }
showmp();
if(getch())
{
restrictmp(0,0,getmaxx(),getmaxy());
main2();
}
}
void rect()
{
int x,y,b,leftpressed=0,point1check=0,i=0,j=0;
restrictmp(181,131,619,449);
	setcolor(c);
	delay(500);
	while(!kbhit())
	{


		showmp();
		getmp(&b,&x,&y);

		if(b==1)
		{
			leftpressed=1;
			if(point1check==0)
			{	arrayrect[i][0]=x;
				arrayrect[i][1]=y;
				point1check=1;
			}
			arrayrect[i][2]=x;
			arrayrect[i][3]=y;

		}
		if(b==0 && leftpressed==1)
		{
			i++;
			point1check=0;
			leftpressed=0;
		}

		for(j=0;j<i;j++)

		rectangle(arrayrect[j][0],arrayrect[j][1],arrayrect[j][2],arrayrect[j][3]);

		delay(100);
	}
if(getch())
{
restrictmp(0,0,getmaxx(),getmaxy());
main2();
}
}

void circle1()
{

int x,y,b,leftpressed=0,point1check=0,i=0,j=0;
int midx,halfx,halfy,midy,radius;
setcolor(c);

delay(500);
restrictmp(180,130,620,450);
while(!kbhit())
{

	showmp();
	getmp(&b,&x,&y);

	if(b==1)
	{
		leftpressed=1;
		if(point1check==0)
		{	arraycircle[i][0]=x;
			arraycircle[i][1]=y;
			point1check=1;
		}
		arraycircle[i][2]=x;
		arraycircle[i][3]=y;

	}
	if(b==0 && leftpressed==1)
	{
		i++;point1check=0;leftpressed=0;
	}

for(j=0;j<i;j++)
{
halfx=abs((arraycircle[j][0]-arraycircle[j][2])/2);     //x2-x1/2;
halfy=abs((arraycircle[j][1]-arraycircle[j][3])/2);     //y2-y1/2;

if(arraycircle[j][0]<arraycircle[j][2])
	midx=halfx+arraycircle[j][0];
else
	midx=halfx+arraycircle[j][2];
if(arraycircle[j][1]<arraycircle[j][3])
	midy=halfy+arraycircle[j][1];
else
	midy=halfy+arraycircle[j][3];

radius=sqrt(pow(arraycircle[j][0]-arraycircle[j][2],2)+pow(arraycircle[j][1]-arraycircle[j][3],2))/2;


circle(midx,midy,radius);
}delay(100);

}
if(getch())
{
restrictmp(0,0,getmaxx(),getmaxy());
main2();
}
}

void line1()
{


 int leftpressed=0,point1check=0,i=0,j=0,b,in,out;

  setcolor(c);
  delay(500);
    restrictmp(181,131,619,449);
while(!kbhit())
{

	showmp();
	getmp(&b,&in,&out);
	if(b==1)
	{
		leftpressed=1;
		if(point1check==0)
		{	arrayline[i][0]=in;
			arrayline[i][1]=out;
			point1check=1;
		}
		arrayline[i][2]=in;
		arrayline[i][3]=out;


	}
	if(b==0 && leftpressed==1)
	{
		i++;
		point1check=0;
		leftpressed=0;
	}
	for(j=0;j<i;j++)
		line(arrayline[j][0],arrayline[j][1],arrayline[j][2],arrayline[j][3]);

	delay(100);
}
if(getch())
{
restrictmp(0,0,getmaxx(),getmaxy());
main2();
}
}
void help()
{
	int l,no;
	setmp();
	setbkcolor (0);
	settextstyle (7,HORIZ_DIR,4);
	setcolor (10);
	outtextxy (170,10,"CGR Micro Project");
	setcolor (WHITE);
	rectangle (4,50,635,90);
	rectangle (4,100,635,400);
	line(30,100,30,400);
	line(56,200,56,400);
	for(l=120;l<=400;l=l+20)
	{
	 line(4,l,635,l);
	}
	settextstyle (8,HORIZ_DIR,3);
	setcolor (13);
	outtextxy (60,50,"HOW TO USE FEATURES OF THIS PAINT");
	setcolor(11);
	settextstyle (6,HORIZ_DIR,1);
	outtextxy (14,95,"1.Firstly you have to Select tools from the right side of screen.");
	outtextxy (14,115,"2.After Selecting Any tool you have to Paint that using Mouse pointer.");
	outtextxy (14,135,"3.When you Select any tool then your mouse is restricted in the paint window.");
	outtextxy (14,155,"4.To Select New Tool press Any Key on keyboard & select new tool with mouse.");
	outtextxy (14,175,"5.After selecting Tool How to use it: ");
	setcolor(6);
	outtextxy (45,195,"a.LINE: Select starting pt. & drag Cursor to end pt. of line you want to draw.");
	outtextxy (45,215,"b.RECTANGLE: Drag the Cursor and adjust the length & breadth of Rectangle.");
	outtextxy (45,235,"c.CIRCLE: Select the Diameter of circle you want to draw using mouse.");
	outtextxy (45,255,"d.BAR: Works like Rectangle just having stylefill Effect.");
	outtextxy (45,275,"e.FREE HAND: Just like Pencil of MS Paint left clicked on mouse and draw.");
	outtextxy (47,295,"f.BRUSH: Works like Free hand but you can fill color using this.");
	outtextxy (45,315,"g.COLOR: It will Automatically selects new color after clicking on it.");
	outtextxy (45,335,"h.PATTERN:Automatically selects new Pattern for BAR after clicking on it.");
	outtextxy (49,355,"i.ERASER: Erase paint window as you want.");
	outtextxy (48,375,"j.CLEAR: It will Reset The Paint Window.");
	settextstyle(1,HORIZ_DIR,1);
	setcolor(4);
	outtextxy (230,430,"press any key to continue");
	getch();

}
void logo()
{
	hidemp();
	cleardevice();
	setbkcolor (0);
	settextstyle (7,HORIZ_DIR,4);
	setcolor (10);
	outtextxy (170,10,"CGR Micro Project");
	setcolor (WHITE);
	rectangle (4,50,635,90);
	rectangle (90,95,540,135);
	rectangle (10,150,400,400);
	rectangle (430,150,620,240);
	rectangle (430,250,620,400);
	settextstyle (8,HORIZ_DIR,1);
	setcolor (13);
	outtextxy (10,50,"Smt. Sharachchandrika Suresh Patil Institue of Technology");
	setcolor (11);
	settextstyle (10,HORIZ_DIR,1);
	outtextxy (240,90,"PAINT IN C");
	setcolor (10);
	settextstyle (6,HORIZ_DIR,1);
	outtextxy (130,150,"Developed By :");
	setcolor (11);
	settextstyle (6,HORIZ_DIR,1);
	outtextxy (50,200,"1.MAITRAY WANI");
	outtextxy (50,230,"2.HEMANT PATIL");
	outtextxy (50,260,"3.DHIRAJ CHAUDHARY");
	outtextxy (50,290,"4.DARSHAN DESHMUKH");
	outtextxy (50,320,"5.RAKESH VISAVE");

	setcolor (10);
	settextstyle (3,HORIZ_DIR,1);
	outtextxy (440,150,"Guided By :");
	setcolor (11);
	settextstyle (6,HORIZ_DIR,1);
	outtextxy (460,180,"Mr. D.M.FEGADE");
	setcolor (7);
	outtextxy (440,260,"Thoughts:");
	settextstyle (3,HORIZ_DIR,1);
	outtextxy (440,300,"* Life is nothing");
	outtextxy (440,330," without struggle");
	settextstyle(1,HORIZ_DIR,1);
	setcolor(100);
	outtextxy (230,430,"press any key to continue");
	getch();



  }
int main2(){


	settextstyle(10,HORIZ_DIR,5);
	setcolor(14);
	outtextxy(140,0,"PAINT IN C");
	setcolor(7);
	rectangle(15,10,615,90);

	rectangle(240,95,560,125);
	settextstyle(10,HORIZ_DIR,1);
	setcolor(2);
	outtextxy(285,88,"PAINT WINDOW");

	setmp();
	showmp();

	button(50,130,150,160,"LINE");
	button(50,160,150,190,"RECTANGLE");
	button(50,190,150,220,"CIRCLE");
	button(50,220,150,250,"BAR");
	button(50,250,150,280,"FREE HAND");
	button(50,280,150,310,"BRUSH");
	button(50,310,150,340,"COLOR");
	button(50,340,150,370,"PATTERN");
	button(50,370,150,400,"ERASER");
	button(50,400,150,430,"CLEAR");
	button(50,430,150,460,"BACK TO MENU");
	rectangle(180,130,620,450);
	while(1){
		if(click(50,130,150,160,"LINE")==0){
			hidemp();
			line1();
			return 0;
		}


		if(click(50,160,150,190,"RECTANGLE")==0){
			hidemp();
			rect();
			return 0;
		}
		if(click(50,190,150,220,"CIRCLE")==0){
			hidemp();
			circle1();

			return 0;
		}
		if(click(50,220,150,250,"BAR")==0){
			hidemp();
			bar1();
			return 0;
		}
		if(click(50,250,150,280,"FREE HAND")==0){
			hidemp();
			fhand();
			return 0;
		}if(click(50,280,150,310,"BRUSH")==0){
			hidemp();
			brush();
			return 0;
		}if(click(50,310,150,340,"COLOR")==0){
			hidemp();
			setcolor1();
			main2();
			return 0;
		}if(click(50,340,150,370,"PATTERN")==0){
			fpattern();
			main2();
			return 0;
		}
		if(click(50,370,150,400,"ERASER")==0){
			eraser();
			return 0;

		}
		if(click(50,400,150,430,"CLEAR")==0){
			clear();
			return 0;

		}
		if(click(50,430,150,460,"BACK TO MENU")==0){
			screen();
			return 0;

		}



	}
}

int screen(){

	logo();
	cleardevice();
	showmp();
	settextstyle(10,HORIZ_DIR,5);
	setcolor(14);
	outtextxy(140,0,"PAINT IN C");
	setcolor(7);

	rectangle(15,10,615,90);

	setmp();

	button(250,150,400,200,"START");
	button(250,200,400,250,"HELP");
	button(250,250,400,300,"ABOUT");
	button(250,300,400,350,"EXIT");

	while(1){
		if(click(250,150,400,200,"START")==0){
			hidemp();
			cleardevice();
			loading();
			cleardevice();
			main2();
			return 0;
		}


		if(click(250,200,400,250,"HELP")==0){
			hidemp();
			cleardevice();
			help();
			cleardevice();
			showmp();
			screen();
			return 0;
		}
		if(click(250,250,400,300,"ABOUT")==0){
			showmp();
			cleardevice();

			screen();
			return 0;
		}
		if(click(250,300,400,350,"EXIT")==0){
			exit(0);
		}


	}
}

void button(int x1,int y1,int x2,int y2,char str[]){
	int xc,yc,i1=0,l1=0;
	while(i1<strlen(str)){
		l1+=4;
		i1++;
	}
	xc=(x2-x1)/2+x1-l1;
	yc=(y2-y1)/2+y1;
	unpress(x1,y1,x2,y2);
	settextstyle(0,0,1);
	setcolor(7);
	outtextxy(xc,yc,str);
}

int click(int x1,int y1,int x2,int y2,char str[]){
	int button,x,y;
	int xc,yc,i1=0,l1=0;
	while(i1<strlen(str)){
		l1+=4;
		i1++;
	}
	xc=(x2-x1)/2+x1-l1;
	yc=(y2-y1)/2+y1;
	getmp(&button,&x,&y);
	if( (x>x1 && x<x2) && (y>y1 && y<y2) && button==1){
		hidemp();
		press(x1,y1,x2,y2);
		setcolor(GREEN);
		settextstyle(0,0,1);
		outtextxy(xc,yc,str);
		showmp();
		while((button==1))
			getmp(&button,&x,&y);
		hidemp();
		press(x1,y1,x2,y2);
		showmp();
		setcolor(GREEN);
		settextstyle(0,0,0);
		outtextxy(xc,yc,str);
		for(i1=50;i1<500;i1=i1+50){
			delay(10);
			sound(i1+200);
		}
		showmp();
		nosound();
		setcolor(GREEN);
		settextstyle(0,0,0);
		outtextxy(xc,yc,str);
		return 0;
	}else return 1;
}
int unpress(int x1,int y1,int x2,int y2){

	setfillstyle(3,12);
	bar(x1,y1,x2,y2);
	setcolor(WHITE);
	line(x1,y1,x2,y1);
	line(x1,y1,x1,y2);
	line(x1,y2,x2,y2);
	line(x2,y1,x2,y2);
return 0;
}


int press(int x1,int y1,int x2,int y2){


	setfillstyle(6,1);
	bar(x1,y1,x2,y2);

	setcolor(WHITE);
	line(x1,y1,x2,y1);
	line(x1,y1,x1,y2);
	line(x1,y2,x2,y2);
	line(x2,y1,x2,y2);
return 0;
}
