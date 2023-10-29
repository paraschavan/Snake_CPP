#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
#define l 335
#define b 635
int x=b/2,y=l/2,fx,fy,afx[100],afy[100],i,j,p=0,pp,d,ch=NULL;
int sh=1,sx[100],sy[100],tx,ty,lc=0,px,py,ee,e,q,k,go=0;
int flw[20000],di=0,tdata[1000],ti=1,otp=0;
char points[100],msg[100],gameover[100],position[100];
void calfood();
void food();
void snake();
void tail();
void follow();
void tdraw();
void bite();
void data();
void draw();
void direction();
void ui();
void fill();
void fillcolor(int,int,int);
void score(int,int);
void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\bgi");
	calfood();
	tdata[0]=0;
	while(ch!=113)
	{
		setcolor(15);
		ui();
		direction();
		score(fx,fy);
		setcolor(2);
		snake();
		data();
		follow();
		tail();
		tdraw();
		//fi	ll();
		setcolor(9);
		draw();
		setcolor(4);
		food();
		bite();
		delay(10);
		cleardevice();
		if(go==1)
	{
		settextstyle(2,0,10);
		setcolor(4);
		sprintf(gameover,"Game Over");
		outtextxy(225,200,gameover);
		setcolor(2);
		sprintf(points,"Points: %d",p);
		outtextxy(225,250,points);
		getch();
		exit(0);

	}
	}
	getch();
	closegraph();
}
void ui()
{
	settextstyle(2,0,7);
	sprintf(msg,"Press W-UP S-DOWN A-LEFT D-RIGHT Q-QUIT ");
	outtextxy(5,350,msg);
	sprintf(points,"Points: %d",p);
	outtextxy(5,400,points);
       //	sprintf(position,"x=%d y=%d",x,y);
       //	outtextxy(140,400,position);
}
void calfood()
{
	fx=rand()%b;
	fy=rand()%l;
}
void food()
{
	circle(fx,fy,5);
}
void snake()
{
	circle(x,y,5);
}
void tail()
{
		sx[0]=x;
		sy[0]=y;
		for(i=1;i<sh;i++)
	{
		if(i==sh-1)
	   {
		if(flw[tdata[i]]==1&&lc==1)
		{
			sy[i]=sy[i-1]+10;
			sx[i]=sx[i-1];
			lc=0;
		}
		if(flw[tdata[i]]==2&&lc==1)
		{
			sy[i]=sy[i-1];
			sx[i]=sx[i-1]-10;
			lc=0;
		}
		if(flw[tdata[i]]==3&&lc==1)
		{
			sy[i]=sy[i-1]-10;
			sx[i]=sx[i-1];
			lc=0;
		}
		if(flw[tdata[i]]==4&&lc==1)
		{
			sy[i]=sy[i-1];
			sx[i]=sx[i-1]+10;
			lc=0;
		}


	   }


	}

}
void data()
{
	flw[di]=d;
	di++;
}
void follow()
{
	if(lc==1&&otp==0)
	{
		tdata[ti]=di-10;
		ti++;
		otp=1;
	}
	else if (lc==1)
	{
		tdata[ti]=tdata[ti-1]-10;
		ti++;
	}
}
void tdraw()
{
	for(i=1;i<sh;i++)
	{
		switch(flw[tdata[i]])
		{
			case 1:
				sy[i]--;
				break;
			case 2:
				sx[i]++;
				break;
			case 3:
				sy[i]++;
				break;
			case 4:
				sx[i]--;
				break;
		}
		circle(sx[i],sy[i],5);
		tdata[i]++;
	}
}
void bite()
{
	for(k=1;k<sh;k++)
 {
	q=sx[k];
	e=sy[k];
	q=q-2;
	e=e-2;
	ee=e;
	for(i=0;i<3;i++)
	{
		afx[i]=q;
		for(j=0;j<3;j++)
	    {
		afy[j]=e;
		e++;
	    }
		e=ee;
		q++;
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(x==afx[i]&&y==afy[j])
			{
				go=1;
				break;
			}

		}

	}
 }
	if((x>635||x<0)||(y>335||y<0))
	{
		go=1;
	}
}
void draw()
{
	line(0,0,0,l);
	line(b,0,b,l);
	line(0,0,b,0);
	line(0,l,b,l);
}
void score (int q,int e)
{
	q=q-5;
	e=e-5;
	ee=e;
	for(i=0;i<10;i++)
	{
		afx[i]=q;
		for(j=0;j<10;j++)
	    {
		afy[j]=e;
		e++;
	    }
		e=ee;
		q++;
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(x==afx[i]&&y==afy[j])
			{
				calfood();
				p++;
				sh++;
				lc=1;
				break;
			}

		}

	}
}
void direction()
{

		if(kbhit())
		{
			ch=getch();
			switch(ch)
			{
				case 119://w
					y--;
					d=1;
					break;
				case 97://a
					x--;
					d=4;
					break;
				case 115://s
					y++;
					d=3;
					break;
				case 100://d
					x++;
					d=2;
					break;

			}
		}
		else
		{
			if(ch!=NULL)
		   {
			switch(ch)
			{
				case 119://w
					y--;
					d=1;
					break;
				case 97://a
					x--;
					d=4;
					break;
				case 115://s
					y++;
					d=3;
					break;
				case 100://d
					x++;
					d=2;
					break;
			}
		    }

		}

}
void fill()
{
	for(i=0;i<sh;i++)
	{
		fillcolor(sx[i],sy[i],14);
	}
}
void fillcolor(int z,int t,int n)
{
	if(getpixel(z,t)==0)
	{
		putpixel(z,t,n);
		fillcolor(z+1,t,n);
		fillcolor(z-1,t,n);
		fillcolor(z,t+1,n);
		fillcolor(z,t-1,n);
	}
}
