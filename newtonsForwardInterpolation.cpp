#include <bits/stdc++.h> 
using namespace std; 

class NewInterpol{
	
	public: 
		float u_cal(float u, int n) 
		{ 
			float temp = u; 
			for (int i = 1; i < n; i++) 
				temp = temp * (u - i); 
			return temp; 
		} 
		
		int fact(int n) 
		{ 
			int f = 1; 
			for (int i = 2; i <= n; i++) 
				f *= i; 
			return f; 
		} 
	
};


int main(){
	NewInterpol obj; 
	cout << "Number of values: " << endl; 
	int n;
	cin >> n; 
	float x[n];
	for(int i = 0; i < n; i++){
		cin >> x[i];
	} 
	
	float y[n][n];
	for(int i = 0; i < n; i++){
		float xDegree = x[i]*3.14159/180;
		y[i][0] = sin(xDegree);
		cout << " " << y[i][0] << " " << endl;
	} 
	for (int i = 1; i < n; i++) { 
		for (int j = 0; j < n - i; j++) 
			y[j][i] = y[j + 1][i - 1] - y[j][i - 1]; 
	} 

	for (int i = 0; i < n; i++) { 
		cout << setw(4) << x[i] << "\t"; 
		for (int j = 0; j < n - i; j++) 
			cout << setw(4) << y[i][j] << "\t";
			cout << endl; 
	} 


	cout << "Value to interpolate at: " << endl;
	float value;
	cin >> value; 

	float sum = y[0][0]; 
	float u = (value - x[0]) / (x[1] - x[0]); 
	for (int i = 1; i < n; i++) { 
		sum = sum + (obj.u_cal(u, i) * y[0][i]) / obj.fact(i); 
	} 

	cout << "\n Value at " << value << " is " << sum << endl; 
	return 0; 
} 

