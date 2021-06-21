#include <iostream>  
#include <cmath>
#include <algorithm>
using namespace std;
#define MAX_DISTANCE 10000000 

typedef struct Point
{
    double x;
    double y;
}Point;

bool SortX(Point A,Point B)
{
    return A.x<B.x;
}

bool SortY(Point A, Point B)
{
    return A.y<B.y;
}

double Distance(Point A,Point B)
{
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

double ClosestDistance(Point points[],Point &A,Point &B,int n)
{
    double distance;                 
    double d1,d2;                         
    Point A1,B1,A2,B2;   
	int i=0;
	int j=0;
	int k=0;
	int x=0;             
    if(n==2)
    {
        A=points[0];
        B=points[1];
        distance=Distance(points[0],points[1]);
    }
    else if(n<2){
        return MAX_DISTANCE;  
	}
    else
    {
        Point *p1=new Point[n];    
        Point *p2=new Point[n];
        sort(points,points+n,SortX);    
        double middle=points[(n-1)/2].x;  
        for(i=0;i<n/2;i++)
            p1[i]=points[i];
        for(int j=0,i=n/2;i<n;i++)
            p2[j++]=points[i];
        d1=ClosestDistance(p1,A1,B1,n/2);        
        d2=ClosestDistance(p2,A2,B2,n-n/2);    
        if(d1<d2) {
		   distance=d1;
		   A=A1;
		   B=B1;
		}            
        else { 
		  distance=d2;A=A2;B=B2;
		}
        Point *p3=new Point[n];
        for(i=0,k=0;i<n;i++)                      
            if(abs(points[i].x-middle)<=distance)
                p3[k++]=points[i];
        sort(p3,p3+k,SortY);                                    
        for(i=0;i<k;i++)
        {
            if(p3[j].x-middle>=0)                                            
                continue;
            x=0;
            for(j=i+1;j<=i+6+x&&j<k;j++)           
            {
                if(p3[j].x-middle<0)
                {
                    x++;
                    continue;
                }
                if(Distance(p3[i],p3[j])<distance)
                {
                    distance=Distance(p3[i],p3[j]);
                    A=p3[i];
                    B=p3[j];
                }
            }
        }
    }
    return distance;
}

int main()
{
    int n;           
    Point A,B;            
    double dis;   
    cout<<"请输入共有多少个点:";
    cin>>n;
    cout<<"请输入这些点："<<endl; 
    Point *points=new Point[n];
    for(int i=0;i<n;i++)
        cin>>points[i].x>>points[i].y;
        dis=ClosestDistance(points,A,B,n);
        cout<<"最近点对为"<<"("<<A.x<<","<<A.y<<")和"<<"("<<B.x<<","<<B.y<<")"<<endl;
        cout<<"最近点对距离为:"<<dis<<endl;
}


