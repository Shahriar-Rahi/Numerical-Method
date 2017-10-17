#include<bits/stdc++.h>

using namespace std;

int coeff_deg_i[100];
int highest_degree;

class NewtonRaphson{
    public:
    double func(double x)
    {

      double f = 0;
      for (int i = highest_degree; i >= 0; i--) {
         f += double(double(coeff_deg_i[i]) * pow(x, double(i)));
      }
      return f;
   }

	double derivFunc(double x)
	{
   	  double f = 0;
      for (int i = highest_degree; i >= 1; i--) {
         f += double(double(coeff_deg_i[i] * i) * pow(x, double(i) - 1));
      }
      return f;
	}
 
	void newtonRaphson(double x)
	{
	    double h = func(x) / derivFunc(x);
	    while (abs(h) >= 0.001)
	    {
	        h = func(x)/derivFunc(x);
	  
	        // x(i+1) = x(i) - f(x) / f'(x)  
	        x = x - h;
	    }
	 
	    cout << "The value of the root is : " << x;
	}

    int poly_input(int degree) {
      cout << "Please enter coefficient for degree " << degree << endl;
      int coefficient;
      cin >>  coefficient;
      return coefficient;
   }

};



int main()
{
    NewtonRaphson obj;
    cout << "What is the highest degree of your polynomial? " << endl;
    cin >> highest_degree;
      for (int i = highest_degree; i >= 0; i--) {
         coeff_deg_i[i] = obj.poly_input(i);
      }
    double x0 = -20;
    obj.newtonRaphson(x0);
    return 0;
}
