#include<bits/stdc++.h>
using namespace std;

int coeff_deg_i[100];
int highest_degree;

class SecantMethod{
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


void secant(double x1, double x2)
{
    double n = 0, xm, x0, c;
    if (func(x1) * func(x2) < 0) {
        do {
            x0 = (x1 * func(x2) - x2 * func(x1)) / (func(x2) - func(x1));

            c = func(x1) * func(x0);

            x1 = x2;
            x2 = x0;

            n++;

            if (c == 0)
                break;
            xm = (x1 * func(x2) - x2 * func(x1)) / (func(x2) - func(x1));
        } while (fabs(xm - x0) >= 0.0001);

        cout << "Root of the given equation=" << x0 << endl;
        cout << "No. of iterations = " << n << endl;
    }
    else
        cout << "Can not find a root in the given interval";
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
    SecantMethod obj;
    cout << "What is the highest degree of your polynomial? " << endl;
    cin >> highest_degree;
      for (int i = highest_degree; i >= 0; i--) {
         coeff_deg_i[i] = obj.poly_input(i);
      }
    obj.assume();

    double k = obj.m, l = obj.n;
    obj.secant(k, l);
    return 0;
}
