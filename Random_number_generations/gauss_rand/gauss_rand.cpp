// A C++ program to generate a sequence of random numbers that are uniformly distributed in the interval [-1,+1)
// Generating random numbers between -1 and 1 using drand48()
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ofstream outfile("data.txt"); // Create an output file stream

    if (!outfile.is_open()) { // Check if the file is open
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int i, n,seed;
    double x, random_num, I, stder, f_val, f_val2;

    cout << "Number of sample points: ";
    cin >> n;

    f_val = 0;
    f_val2 = 0;
    seed=78741;
    srand48(seed);
    for (i = 0; i <= n; i++) { 
        random_num = drand48();
        // random number between 0 and 1 (default seed is 1)
        x = 2.0 * (random_num - 0.5); 
        // Now x is a random number between -1 and 1

        outfile << i << "\t" << x << endl;

        f_val += x;
        f_val2 += x * x;
    }

    // Calculation of mean and standard deviation
    I = f_val * 2 / n; 
    f_val /= n;
    f_val2 /= n;
    stder = 2.0 * sqrt((f_val2 - f_val * f_val) / n);

    cout << setw(8) << n << setw(12) << I << setw(12) << stder << endl;

    outfile.close();
    return 0;
}

