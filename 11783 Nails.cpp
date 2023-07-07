#include <bits/stdc++.h>

using namespace std;

#define si 1010
#define max(a,b) (a>b ?a:b)
#define min(a,b) (a<b ?a:b)
#define fr(i,a,b) for(i=a;i<=b;i++)

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int i,j,l,n,cs=1,cnt,sm,fg,mat[si][si];

struct ss
{
    int x1,y1,x2,y2;
}stru[si];

struct P
{
    double x,y;
    P(double x=0,double y=0)
    {
        this->x=x;
        this->y=y;
    }
};

P MV(P aa,P bb) {return P(bb.x-aa.x,bb.y-aa.y);}
double CP(P aa,P bb){return aa.x*bb.y-aa.y*bb.x;}

int main()
{
   	while(~scanf("%d",&n)&&n)
   	{
   	    sm=cnt=0;
		fg=1;
		fr(i,1,n)
		{
		    scanf("%d%d%d%d",&stru[i].x1,&stru[i].y1,&stru[i].x2,&stru[i].y2);
		    fr(j,1,n)
		    mat[i][j]=0;
		}
		fr(i,1,n)
		{
		    P a=P(stru[i].x1,stru[i].y1);
		    P b=P(stru[i].x2,stru[i].y2);
		    P ab=MV(a,b);
		    fg=1;
		    fr(j,1,n)
		    {
		        if(!mat[i][j]&&!mat[j][i]&&i!=j)
		        {
		            P c=P(stru[j].x1,stru[j].y1);
		            P d=P(stru[j].x2,stru[j].y2);
		            P ac=MV(a,c);
		            P ad=MV(a,d);
		            P cd=MV(c,d);
		            P ca=MV(c,a);
		            P cb=MV(c,b);
		            double v1=CP(ab,ac);
		            double v2=CP(ab,ad);
		            double v3=CP(cd,ca);
		            double v4=CP(cd,cb);

                    int found=0;
		            if(v1*v2<0&&v3*v4<0)
		            {
		                sm++;
		                mat[i][j]=1;
		                fg=0;
		                found=1;
		            }
		            if(!v1)
		            {
		                int mnx,mny,mxx,mxy;
		                mnx=min(stru[i].x1,stru[i].x2);
		                mxx=max(stru[i].x1,stru[i].x2);
                        mny=min(stru[i].y1,stru[i].y2);
		                mxy=max(stru[i].y1,stru[i].y2);
		                int cx=stru[j].x1;
		                int cy=stru[j].y1;
		                if(mnx<=cx&&mxx>=cx&&mny<=cy&&mxy>=cy)
		                {
		                    if(!found)
		                    sm++;
		                    found=1;
		                    mat[i][j]=mat[j][i]=1;
		                    fg=0;
		                }
		            }
		            if(!v2)
		            {
		                int mnx,mny,mxx,mxy;
		                mnx=min(stru[i].x1,stru[i].x2);
		                mxx=max(stru[i].x1,stru[i].x2);
                        mny=min(stru[i].y1,stru[i].y2);
		                mxy=max(stru[i].y1,stru[i].y2);
		                int dx=stru[j].x2;
		                int dy=stru[j].y2;
		                if(mnx<=dx&&mxx>=dx&&mny<=dy&&mxy>=dy)
		                {
		                    if(!found)
		                    sm++;
		                    found=1;
		                    mat[i][j]=mat[j][i]=1;
		                    fg=0;
		                }
		            }
		            if(!v3)
		            {
		                int mnx,mny,mxx,mxy;
		                mnx=min(stru[j].x1,stru[j].x2);
		                mxx=max(stru[j].x1,stru[j].x2);
                        mny=min(stru[j].y1,stru[j].y2);
		                mxy=max(stru[j].y1,stru[j].y2);
		                int ax=stru[i].x1;
		                int ay=stru[i].y1;
		                if(mnx<=ax&&mxx>=ax&&mny<=ay&&mxy>=ay)
		                {
		                    if(!found)
		                    sm++;
		                    found=1;
		                    mat[i][j]=mat[j][i]=1;
		                    fg=0;
		                }
		            }
		            if(!v4)
		            {
		                int mnx,mny,mxx,mxy;
		                mnx=min(stru[j].x1,stru[j].x2);
		                mxx=max(stru[j].x1,stru[j].x2);
                        mny=min(stru[j].y1,stru[j].y2);
		                mxy=max(stru[j].y1,stru[j].y2);
		                int bx=stru[i].x2;
		                int by=stru[i].y2;
		                if(mnx<=bx&&mxx>=bx&&mny<=by&&mxy>=by)
		                {
		                    if(!found)
		                    sm++;
		                    found=1;
		                    mat[i][j]=mat[j][i]=1;
		                    fg=0;
		                }
		            }
		        }
		        else if(i!=j)
		        fg=0;
		    }
		    if(fg)
            sm+=2;
		}
		printf("%d\n",sm);
    }
   	return 0;
}