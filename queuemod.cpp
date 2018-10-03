#include<bits/stdc++.h>
using namespace std;
int factorial(int x)
{
  return (x == 1 || x == 0) ? 1 : factorial(x - 1) * x;
}
int main()
{
int n;
	cout<<"enter ur choice of queuing model :\n 1>> for single sever \n 2>> for multiple server"<<endl;
	cin>>n;
	if(n==1){
		int x;
		cout<<"enter 1 for infinite queue 2 for finite";
		cin>>x;
		if(x==1){
			float a,s;
			cout<<"enter the arrival and service rate respectively:"<<endl;
			cin>>a>>s;
			float r=a/s;
			cout<<"utilization rate "<<r<<endl;
			int n1;
			cout<<"enter the n for which u want to find probability (n1>1) "<<endl;
			cin>>n1;
			cout<<pow(r,n1)*(1-r);
			cout<<"length ofsever"<<endl;
			float ls=(float)(r/(1-r));
			cout<<ls<<endl;
			float lq=ls-r;
			cout<<"length of queue "<<lq<<endl;
			cout<<"wq"<<(float)lq/a<<endl;
			cout<<"ws"<< (float)ls/a<<endl;
			
			
		}
		else{
			float a,s;
			cout<<"enter the arrival and service rate respectively:"<<endl;
			cin>>a>>s;
			float r=a/s;
			cout<<"utilization rate "<<r<<endl;
			int n2;
			cout<<"enter limiting no of queue : N __"<<endl;
			cin>>n2;
			int n1;
			cout<<"enter the n for which u want to find probability (n1>1) "<<endl;
			cin>>n1;
			float pn=(float)(pow(r,n1)*(r-1))/(pow(r,n2+1)-1);
			cout<<pn<<endl;
			cout<<"length ofsever"<<endl;
			float ls=(float)(r*((n2*pow(r,n2+1))-((n2+1)*pow(r,n2))+1))/((1-r)*(1-pow(r,n2+1)));
			cout<<ls<<endl;
			float lq=(float)(ls-1+((r-1)/(pow(r,n2+1)-1)));
			cout<<"length of queue"<<lq<<endl;
			float p0=(r-1)/(pow(r,n2+1)-1);
			int n3;
			
			float ws=(float)(lq/(a*(1-pn)))+(1/s);
			cout<<"Ws : "<<ws<<endl;
			cout<<"Wq : "<<(float)(ws-(float)(1/s));
			
			
			
			
		}
	}
	if(n==2){
		
		int x;
		cout<<"Press 1 for infinite queue length; for finite press 2"<<endl;
		cin>>x;
		if(x==1){
		int c;
		float a,s;
		cout<<"enter no of server i.e value of c  "<<endl;
		cin>>c;
		cout<<"enter arrival and service rate respectively "<<endl;
		cin>>a>>s;
		float r=a/s;
			int n2;
			float t1=0;
			for(int i=0;i<=c-1;i++){
				t1=t1+(pow(r,i)/factorial(i));
			}
			float t2=(c*pow(r,c))/((factorial(c))*(c-r));
			float p0=(float)1/(t1+t2);
			cout<<"enter the value of n for which u want to find pn "<<endl;
			cin>>n2;
			if(n2<=c){
				cout<<"Pn: "<<(float)(pow(r,n2)*p0)/factorial(n2)<<endl;
			}
			else{
				cout<<"Pn: "<<(float)(pow(r,c)*pow((r/c),(n2-c))*p0)/factorial(c)<<endl;
			}
			float lq=(float)(pow(r,(c+1))*p0)/(pow((c-r),2)*factorial(c-1));
			cout<<"length of queue: "<<lq<<endl;
			float wq=(float)(lq/a);
			cout<<"Wq-->>"<<wq<<endl;
			float ws=(float)(wq+(1/s));
			cout<<"Ws-->>"<<ws<<endl;
			float ls=(float)(a*ws);
			cout<<"length of server  "<<ls<<endl;
			
		}
		else
		{
		int c;
		float a,s;
		cout<<"enter no of server i.e value of c  "<<endl;
		cin>>c;
		cout<<"enter arrival and service rate respectively "<<endl;
		cin>>a>>s;
		float r=a/s;
			int n2,n3;
			cout<<"enter the limiting value in queue "<<endl;
			cin>>n2;
			float t1=0,t2=0,pn;
			for(int i=0;i<=c-1;i++){
				t1=t1+(pow(r,i)/factorial(i));
				
			}
			 t2+=(pow(r,c)*((pow((r/c),(n2-c+1))-1)))/((factorial(c))*(r/c-1));
			float p0=(float)(1/(t1+t2));
			cout<<"enter n for which u want to know pn ;n<=limiting value!"<<endl;
			cin>>n3;
			if(n3<=c){
				 pn=(float)(pow(r,n3)*p0/factorial(n3));
				cout<<"Pn: "<<pn<<endl;
			}
			else{
				pn=(float)(pow(r,c)*pow(r/c,n3-c)*p0)/factorial(c);
				cout<<"Pn: "<<pn<<endl;
			}
			float t3=r/c;
			float lq=(float)((p0*pow(r,c+1))*(1+((c-n2-1)*pow(t3,n2-c))-((c-n2)*pow(t3,n2-c+1))))/(c*(factorial(c))*(pow(1-t3,2)));
			cout<<"length of queue : "<<lq<<endl;
			float ae=(float)(a*(1-pn));
			float wq=(float)(lq/ae);
			float ls=lq+r;
			float ws=(float)(ls/ae);
			cout<<"length of sever: "<<ls<<endl;
			cout<<"WQ: "<<wq<<endl;
			cout<<"WS: "<<ws<<endl;
			
			
		}
		
	}
}
