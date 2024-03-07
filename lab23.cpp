#include<iostream>
#include<cmath>
using namespace std;

#define M_PI 3.14159265358979323846

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber operator+(double number,const ComplexNumber &c){
	return ComplexNumber(number+c.real,c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

ComplexNumber operator-(double number,const ComplexNumber &c){
	return ComplexNumber(number-c.real,-c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber((real*c.real)-(imag*c.imag),(real*c.imag)+(c.real*imag));
}

ComplexNumber operator*(double number,const ComplexNumber &c){
	return ComplexNumber(number*c.real,number*c.imag);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	double divisor = c.real * c.real + c.imag * c.imag;
    return ComplexNumber((real * c.real + imag * c.imag) / divisor,
                        (imag * c.real - real * c.imag) / divisor);	
}

ComplexNumber operator/(double number,const ComplexNumber &c){
	return ComplexNumber((number*c.real)/ (c.real * c.real + c.imag * c.imag),
	                    -number * c.imag / (c.real * c.real + c.imag * c.imag));
}

bool ComplexNumber::operator==(const ComplexNumber &c){
    return (real == c.real) && (imag == c.imag);
}

bool operator==(double number,const ComplexNumber &c){
    return (number == c.real) && (0 == c.imag);
}


double ComplexNumber::abs(){
	return sqrt(real*real+imag*imag);
}

double ComplexNumber::angle(){
	double reg = atan2(imag,real);
	return reg* (180.0/M_PI);
}

ostream &operator<<(ostream &os, const ComplexNumber &c) {
	if(c.real == 0){
		if(c.imag == 0){
			os << "0";
			return os;
		}else{
			if (c.imag >= 0)
        	os << c.imag << "i";
    		else
       		os << "-" << -c.imag << "i";
            return os;
		}
	}else{
		if(c.imag == 0){
			os << c.real;
			return os;
		}else{
			os << c.real;
			if (c.imag >= 0)
        	os << "+" << c.imag << "i";
    		else
       		os << "-" << -c.imag << "i";
            return os;			
		}		
	}
}



int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}




