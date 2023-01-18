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
float fprime(float x,float t){

	float V2 = a(t) + b(t)/x + d(t)*exp(x);
	return V2;
}


int main(){
	float x,x1,fx,fx1,t;

		cout<<"Enter the initial guess:\n";
		cin>>x1;

	
		
	for (t=323;t<424;t++){

		do
		{x=x1;
	    x1 = x - (f(x,t)/fprime(x,t));
		}
		while (fabs(x1-x)>=0.001);
		cout<<"For temperature "<<t<<endl;
		cout<<" a = "<<a(324.41)<<" b = "<<b(324.41)<<" c = "<<c(324.41)<<" d = "<<d(324.41)<<endl;
		cout<< "Saturation current is "<<x1<<endl;
		cout<<endl;
	}
	return 0;
	 
	
}