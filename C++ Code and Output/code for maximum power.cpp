#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

float a(float t){
	float a1 = (-0.033)*pow(exp(1),(1268/t - 1268/303));
	return a1;
}
float b(float t){
	float b1 = (-7.4*pow(10,-5)*t);
	return b1;
}
float d(float t){
	return ((-4.5)*pow(10,-10));
}
float c(float t){
	float c1 = 1.22 - 0.85*pow(10,-3)*(t-298.15)+0.4308*0.0001*(log(1) + 0.5*log(0.21*1))+0.9514-0.312*0.01*t+ 0.187*0.001*t*log(1*(0.21/50.8)*exp(498/t));
	return c1;
}

float f(float x,float t){
 	float V = a(t)*x + b(t)*log(x) + d(t)*exp(x) + c(t);
	return V;
}

float f1prime(float x,float t){
	float V = 2*a(t)*x + b(t)*log(x) + d(t)*(x+1)*exp(x) + c(t)+d(t);
	return V;
}

float f2prime(float x,float t){
	float V = 2*a(t) + b(t)/x + d(t)*(x+2)*exp(x);
	return V;
}
	
int main(){
	float x,x1,fx,fx1,t;

		cout<<"Enter the initial guess:\n";
		cin>>x1;
		cout<<"Enter the temperature:\n";
		cin>>t;

		do
		{x=x1;
	    x1 = x - (f1prime(x,t)/f2prime(x,t));
		}
		while (fabs(x1-x)>=0.001);
		cout<<"For temperature "<<t<<endl;
		cout<<" a = "<<a(t)<<" b = "<<b(t)<<" c = "<<c(t)<<" d = "<<d(t)<<endl;
		cout<< "power is maximum at "<<x1<<endl;

return 0;	
}