#include<bits/stdc++.h> 
using namespace std; 

struct Data{ 
	int x, y; 
}; 

class LagInterpol{
	
	public:
		double interpolate(Data f[], int xi, int n) { 
			double result = 0;
		
			for (int i=0; i<n; i++){ 
				double term = f[i].y; 
				for (int j=0;j<n;j++) 
				{ 
					if (j!=i) 
						term = term*(xi - f[j].x)/double(f[i].x - f[j].x); 
				} 
	
				result += term; 
			} 
		
			return result; 
		} 
	
};

int main() { 
	LagInterpol obj;
	cout << "Number of known data Points: " << endl;
	int n; 
	cin >> n; 
	Data f[n];
	cout << endl << n << " Known Data points are: " << endl;
	for(int i = 0; i < n; i++){
		cin >> f[i].x >> f[i].y;
	} 

	int newDP;
	cout << "Enter the new data point whose value is to be obtained: " << endl;
	cin >> newDP; 
	cout << "Value of f( "<< newDP << " ) is : " << obj.interpolate(f, newDP, n); 

	return 0; 
} 

