////////// ERHUN ÇETÝNER 2020401279 PROJECT 3 EE242
////Welcome to my project. In this project, we are going to implement the bisection and secant methods to solve any polynomials correctly argumented to the code. More on how to argument and use the
////code may be found on the readme.txt file.
////In short, we are going to use the bisection method -a method that attempts to find a solution in an interval of the input polynomial. It starts by checking whether the function satisfies the necessary
////requirements needed to run the program. If the necessary requirements are satisfied, the program will move on to implement the bisection method. It consists of dividing the interval into two pieces and checking
////which one has the solution. This triggers a change in the interval and thus the bound values are updated. This goes on and on until the tolerance value is larger than the interval. Then the program decides that
////the real value is close enough and prints the most recently updated value of x. This is said to be the solution for the bisection method. Before moving on to the next method, the program also uses the formula
////given in the lecture of Prof. Arslan to calculate how many iterations are needed for the bisection method.
////
////Later, the code moves on to implement the secant method. This method is a slight alteration of the Newton method. It uses two initial guesses to find a third value for x. The newer values increasingly become closer
////to the real value of x. This goes on and on until the tolerance is larger than the difference between the newest x and the medium-aged one. Finally, we get a value close to x. This is printed as the result of the
////secant method. The number of iterations are also correctly printed.
////
////Finally, we are going to implement a mixture of both of these methods. We are going to implement the bisection method for 2 iterations. Then we are going to calculate the rest by the secant method.
////The program then prints the final result as well as the number of iterations. The number of iterations is found by adding 2 to the times the secant method was used in this hybrid part. This is the end of the 
////hybrid model and the project!
////
////The code also lets the user easily check and see important variables. These are commented by default, however the user may choose to uncomment them.
////
////With that, I end the prologue of the project, I hope you like it!


#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <cmath>
#include <iostream>
// These are the necessary libraries.

using namespace std;
double tol,x1,x0,f0i,f0,f1i,f1,x3,xd,x4,x5;
double f3,f3i,f4,f4i,f3ik,f4ik,cost;
double nextepisode, difference;
double argcd,stop;
double newx[2],newf[2],secx[2],secf[2],newxx[2],newff[2],secxxx[2],secfff[2];

// Some of the variables are created here.
 

void funcvalue (double x0, double x1, int argu, double *coef){
	// This function is used to evaluate the function input for both of the initial guesses. x's are the guess values. f's are their corresponding function values.
	for (int i = 1; i < argu-3;i++){
	
		f0i = coef[i]*(pow(x0,(1.0*argu-4-i)));
		f0 += f0i;
		}
//		cout << f0 << endl;
	
		for (int i = 1; i < argu-3;i++){
	
		f1i = coef[i]*(pow(x1,(1.0*argu-4-i)));
		f1 += f1i;
		}

//		cout << f1 << endl;

	// The user may choose to uncomment the cout functions in order to better see the f's.
}

int lmao = 0;

void updater (double x0, double x1, double f0, double f1, int argu, double * coef, double *newx, double *newf){
		
	/// THIS IS THE BISECTION FUNCTION. IT IS EXPLAINED THROUGHLY IN THE PROLOGUE SO I AM NOT GOING OVER IT AGAIN. IT WILL UPDATE ITS BOUNDS WHEN NECESSARY TO THE ACCORDING ALGORITHM.
	// ONLY WHEN f1*f0 IS NOT LARGER THAN ZERO, THERE WILL BE A RESULT IN THE INTERVAL.
	if (f1*f0 <= 0){
//		cout << "We have a solution!" << endl;
		lmao = lmao+1;
//		cout << "The difference between the two points is equal to: " << xd << endl;
		x3=(x1+x0)/2;
		x4=(x1+x0)/2;
		// The bisection is done above.
		for (int i = 1; i < argu-3;i++){
	
		f3i = coef[i]*(pow(x3,(1.0*argu-4-i))); //x0 changed
		f3 += f3i;
		// The new function values.
		}
//		cout << "This is f3: " << f3 << endl;
	
		for (int i = 1; i < argu-3;i++){
	
		f4i = coef[i]*(pow(x4,(1.0*argu-4-i)));
		f4 += f4i;
		// The new function values.
		}
//		cout << "This is f4: " << f4 << endl;
		
		if (f3*f1<=0){
			
			x0=x3;
			f0=f3;
			x5=x3;
		// If after the new medium value is found the result is on the rightern side, this "if" will let us update our lower bound.	

////			cout << "Resulting x is equal to: " << x5 << " It was on the rightern side." << endl;

		}
		if (f0*f4<=0){
			x1=x4;
			f1=f4;
			x5=x4;
		// If after the new medium value is found the result is on the leftern side, this "if" will let us update our upper bound.		

////			cout << "Resulting x is equal to: " << x5 << " It was on the leftern side." << endl;

		}
		xd=(x1-x0);
//		cout << "The difference is equal to: " << xd << endl;
//		cout << "x0: " << x0 << endl;
//		cout << "x1: " << x1 << endl;
//		cout << "f0: " << f0 << endl;
//		cout << "f1: " << f1 << endl;
		newx[0] = x0;
		newx[1] = x1;
		newf[0] = f0;
		newf[1] = f1;
		f3=0; // both f's are set back to zero, because we don't want them to add on top of each other.
		f4=0; 
	
}

	else{
		cout << "There is no solution in this interval." << endl;
		
		// Very sad moment. There are no solutions here.
	}


}

void costly (double x0, double x1, double tol){
	/// THIS FUNCTION APPLIES THE LECTURE SLIDE NOTE ON HOW TO FIND THE NUMBER OF ITERATIONS WHEN BISECTION METHOD IS USED.
	/// THAT IS EQUAL TO interval difference DIVIDED BY tolerance INSIDE THE log2. IT IS THEN ROUNDED UP TO GET THE NECESSARY ITERATION NUMBER.
	cost = log2((x1-x0)/tol);
	
	int costa = ceil(cost);
	cout << "The required number of iterations for the bisection method is equal to: " << costa << "." << endl;
	
}
double oldx,fmed,fold,med,fnew;
double f0i1,f0i2,f0i3;
// Some necessary variables are created.
void secant (double x0, double x1, double f0, double f1, double *newx, double *newf, double argu, double*coef){
	/// THIS FUNCTION IMPLEMENTS THE SECANT ALGORITHM TO FIND A VALUE FOR X AS CLOSE TO ITS REAL VALUE AS POSSIBLE
	if(f0*f1==0){
	
	if(f0==0){
		secx[1]=x0;
	//What happens when we are standing on top of the result at our bound? Our initial guess is correct. Pass it on.
	}
	if(f1==0){
		secx[1]=x1;
		
	
	}}
	else{
	
	oldx += x0;
	med += x1;
	
	
	for (int i = 1; i < argu-3;i++){
	
		f0i1 = coef[i]*(pow(oldx,(1.0*argu-4-i)));
		fold += f0i1;}
		
		
	for (int i = 1; i < argu-3;i++){
	
		f0i2 = coef[i]*(pow(med,(1.0*argu-4-i)));
		fmed += f0i2;}
		
	for (int i = 1; i < argu-3;i++){
	
		f0i3 = coef[i]*(pow(nextepisode,(1.0*argu-4-i)));
		fnew += f0i3;}
	
	nextepisode = med - fmed*((med-oldx)/(fmed-fold)); /// THIS IS THE MAIN FUNCTION FOR THE SECANT ALGORITHM. THE NEXT X VALUE IS CALCULATED BY SUBTRACTING THE FUNCTION VALUE OF THE MEDIUM X MULTIPLIED BY THE OLD X DIFFERENCE DIVIDED BY THEIR
	/// FUNCTION VALUES FROM THE MEDIUM X.
//	cout << "The next episode: " << nextepisode << endl;
//This can be uncommented to see the next value of x.
	difference = abs(med-oldx); 
	// Here the difference between the medium and older x's are calculated.

//	cout << "Diff. " << difference << endl;

	
	secx[0] = med;
	secx[1] = nextepisode;
	secf[0] = fmed;
	secf[1] = fnew;
	fold = 0;
	fmed = 0;
	fnew = 0;
	med = 0;
	oldx = 0;
	// The outputs are sent and then flushed to avoid running into adding the results on top of each other.
}
}
 double xupper, xlower, first, fullzero;
 
int main(int argc, char** argv) /// Argument entrance. VIP.
{	

	cout << "Erhun Cetiner | 2020401279 | BOUN EE | June 6th, 2022 | EE242 Project 3" << endl << endl;
	
	double coef[argc];
	double coef1[argc],coef2[argc],coef3[argc];
//    cout << "You have entered " << argc
//         << " arguments:" << "\n";
  
    for (int i = 0; i < argc; ++i){
	

	}
       
    int argu;
    argu = argc;
	tol = atof(argv[argu-1]);
	// Tolerance
 
    x1 = atof(argv[argu-2]);
    xupper = x1;
    // Upper bound
    
    x0 = atof(argv[argu-3]);
    xlower = x0;
    // Lower bound
    
    first = atof(argv[argu-4]);
    // The coefficient of the x^0.
    
//    cout << "The initial guess values are: " << x0 << " and " << x1 << endl;

    if (argc<5){
    	cout << "There are not enough arguments." << endl; // This means that the user has not given any coefficients, that is an error.
    	return 0;
	}
    if (argc==5){
    	if (first!=0){
    		cout << "There are no solutions for this function." << endl; // Special case for when the one and only coefficient x^0 is equal something different than 0. (For example f(x)=4.) However, this does not have
    		// any solutions.
    		return 0;
		}
		if (first==0){
			cout << "You have entered the notorious function of 0 = 0. That means the entire R space. This function is not built for that!" << endl; // Similiar story for when the function is gives 0 = 0. This has infinite
			// solutions. That is an error.
			return 0; // Return 0 makes the code go back to its initial state.
		}
	}
	
    
    for (int i = 1; i < argu-3;i++){
	
	
    	coef[i]=atof(argv[i]); //// coef[1] is the first coefficient, that means an.
    	fullzero += abs(coef[i]);
		
		}
		if (fullzero==0){
			cout << "That is a sneaky 0 = 0 function right there! This program is not built for that!" << endl; // The case for when the function has multiple coefficient inputs but they are all equal to zero. So 0 = 0 case again.
			return 0;
		}
    	
    	for (int i = 1; i < argu-3;i++){
		

		}

    	cout << "This is your function: " << " ";
		 for (int i = 1; i < argu-4;i++)
		 
		 cout << "(" << coef[i] << "x^" << argu-4-i << ")" << " + " ;
		 cout << "(" << coef[argu-4] << "x^" << "0)" << endl;
			//// This part correctly prints out the function the user has input.

//// BISECTION METHOD
funcvalue(x0,x1,argu,coef); //First let's evaluate the function.
if (f1*f0 <= 0){ //If this condition holds, we can start.

updater(x0,x1,f0,f1,argu,coef,newx,newf); // The first iteration.
while (xd>tol){ // The rest of the iterations.
updater(newx[0],newx[1],newf[0],newf[1],argu,coef,newx,newf);
}
cout << "The result from the bisection method is equal to: " << x5 << endl; // The result.
costly(x0,x1,tol); // The number of iterations.
}

else {
	cout << "The bisection method cannot be used here as f(x1)*f(x0) is larger than zero." << endl; // For when the condition is not satisfied.
}

int counter1=0;
int counter2=0;


//// SECANT METHOD
if (f1*f0 <= 0){ //If this is not satisfied, there will be problems. The guess values may overlap etc. So it's an error.
secant(x0,x1,f0,f1,secx,secf,argu,coef); // First iteration
while (difference>tol){
	counter1=counter1+1; // iteration counter
secant(secx[0],secx[1],secf[0],secf[1],secx,secf,argu,coef); // The rest
if ((argc == 6)&&(secf[1]==0)){
	break;
}
}

if ((secx[1]>xupper)||(secx[1]<xlower)){
	cout << "There are some results elsewhere, however they are not in this interval." << endl; // If somehow we end up having results outside the interval.
}
else{

cout << "The result from the secant method is equal to: " << secx[1] << endl; // The result
cout << "The required number of iterations for the secant method is equal to " << counter1 << "." << endl; // The iteration number
}
}
else{
	cout << "f(x0)*f(x1) is larger than zero. That causes problems for the secant method. Guess values may be the same after a point for example. So it wouldn't work for your function." << endl; 
}


//// HYBRID METHOD
funcvalue(x0,x1,argu,coef); // Firstly, the function is evaluated.

if (f1*f0 <= 0){
updater(x0,x1,f0,f1,argu,coef,newxx,newff); // Bisection 1
if(xd>tol){

updater(newxx[0],newxx[1],newff[0],newff[1],argu,coef,newxx,newff); // Bisection 2

x0 = newxx[0];
x1 = newxx[1];
f0 = newff[0];
f1 = newff[1];

secant(x0,x1,f0,f1,secx,secf,argu,coef); // Initial secant
counter2 = counter2 + 1;
if(difference>tol){
	counter2 = counter2 - 1;
}
while (difference>tol){
	counter2 = counter2 + 1;
secant(secx[0],secx[1],secf[0],secf[1],secx,secf,argu,coef); // Further iterations
if ((argc == 6)&&(secf[1]==0)){
	break;
}
}

cout << "The result from the hybrid method is equal to: " << secx[1] << endl;
cout << "The required number of iterations for the hybrid method is equal to " << counter2+2 << ". " <<  endl;
}
else{

cout << "The result from the hybrid method is equal to: " << x5 << endl; /// For when only 1 bisector is used. That means no iterations.
cout << "The required number of iterations for the hybrid method is equal to " << 0 << ". " <<  endl;
}

}
else{
	cout << "The hybrid method cannot work as the first two steps require the usage of the bisection method. Here the multiplication f(x0)*f(x1) is larger than zero. So bisection method cannot be used also rendering the hybrid method unusable." << endl;
} // Another condition.

		 
  
    return 0;
    
}
	// THE END
//////// ERHUN ÇETÝNER

