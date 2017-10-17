#include<bits/stdc++.h>

using namespace std;

#define MAX_ITER 1000000

int coeff_deg_i[100];
int highest_degree;

class FalsePositionMethod{
    public:
    double func(double x)
    {

      double f = 0;
      for (int i = highest_degree; i >= 0; i--) {
         f += double(double(coeff_deg_i[i]) * pow(x, double(i)));
      }
      return f;
   }

    double m, n;

    void assume(){
        int i=0, j=0;
        for(; func(i)*func(j) >= 0; i++){
            j--;
        }

        m = double(i);
        n = double(j);
    }


    void regulaFalsi(double a, double b)
	{
	    if (func(a) * func(b) >= 0)
	    {
	        cout << "You have not assumed right a and b\n";
	        return;
	    }
	 
	    double c = a;
	 
	    for (int i=0; i < MAX_ITER; i++)
	    {
	        c = (a*func(b) - b*func(a))/ (func(b) - func(a));
	 
	        if (func(c)==0)
	            break;
	        else if (func(c)*func(a) < 0)
	            b = c;
	        else
	            a = c;
	    }
	    cout << "The value of root is : " << c;
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
    FalsePositionMethod obj;
    cout << "What is the highest degree of your polynomial? " << endl;
    cin >> highest_degree;
      for (int i = highest_degree; i >= 0; i--) {
         coeff_deg_i[i] = obj.poly_input(i);
      }
    obj.assume();

    double k = obj.m, l = obj.n;
    obj.regulaFalsi(k, l);
    return 0;
}
