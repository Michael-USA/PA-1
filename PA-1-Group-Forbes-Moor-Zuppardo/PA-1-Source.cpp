// Daniel Forbes
// Michael Zuppardo
// Donald Moor


#include <iostream>
#include <cstdlib> // for generating random numbers and absolute value
#include <fstream> // for operating on csv and txt files
#include <chrono> // for measuring time intervals
#include "quickSort.h"; // for quick sort, taken from GeeksforGeeks


std::ofstream fout;
int gcd_BF_v1(int, int); // the gcd algorithm methods, follows the prompt's naming scheme
int gcd_BF_v2(int, int);
int gcd_OE(int, int);
int gcd_SE(int, int);
double average(int[]); // returns average of all values in int array of size 1000
double median(int[]); // returns median of all values in int array of size 1000
int numFaster(int[], int[]); // returns how many values in the first array at index i are lower than the values in the second array at index i
double fasterAvg(int t1[], int t2[]); // returns, only for the faster pairs identified from numFaster, the average time difference
int randNumArr[1000][2]; // stores random number pairs
int gcdTimeArr1[1000]; // store gcd times, 1 is the first algorithm, 2 the second, etc.
int gcdTimeArr2[1000];
int gcdTimeArr3[1000];
int gcdTimeArr4[1000];
std::chrono::steady_clock::time_point t1; // start time
std::chrono::steady_clock::time_point t2; // end time

int testNum = 0; // FIXME delete


int main()
{
    // populate randNumArr with 1000 random number pairs using rand()
    for (int i = 0; i <= 999; ++i)
    {
        randNumArr[i][0] = rand() - (RAND_MAX / 2); // range is -16383 to 16384
        randNumArr[i][1] = rand() - (RAND_MAX / 2);
    }

    // record gcd_BF_v1 results in BF_v1_Results.csv
    fout.open("BF_v1_Results.csv");
    fout << "Number One,Number Two,Their GCD,Time Spent (Nanoseconds)\n"; // first row
    for (int i = 0; i <= 999; ++i) // columns are seperated by commas, rows by newlines
    {
        int time = std::chrono::duration_cast<std::chrono::duration<int64_t, std::ratio<1, 1000000000/*nanoseconds*/>>>(t2 - t1).count();
        fout << randNumArr[i][0] << "," << randNumArr[i][1] << "," << gcd_BF_v1(randNumArr[i][0], randNumArr[i][1]) << "," << time << "\n";
        gcdTimeArr1[i] = time;
    }
    fout.close();

    // record gcd_BF_v1 time statistics in BF_v1_Statistics.csv
    quickSort(gcdTimeArr1, 0, 999); // sorts array in ascending order
    fout.open("BF_v1_Statistics.csv");
    fout << "Statistics,Nanoseconds\n";
    fout << "Maximum Time," << gcdTimeArr1[999] << "\n";
    fout << "Minimum Time," << gcdTimeArr1[0] << "\n";
    fout << "Average Time," << average(gcdTimeArr1) << "\n";
    fout << "Median Time," << median(gcdTimeArr1) << "\n";
    fout.close();

    // record gcd_BF_v2 results in BF_v2_Results.csv
    fout.open("BF_v2_Results.csv");
    fout << "Number One,Number Two,Their GCD,Time Spent (Nanoseconds)\n";
    for (int i = 0; i <= 999; ++i)
    {
        int time = std::chrono::duration_cast<std::chrono::duration<int64_t, std::ratio<1, 1000000000>>>(t2 - t1).count();
        fout << randNumArr[i][0] << "," << randNumArr[i][1] << "," << gcd_BF_v2(randNumArr[i][0], randNumArr[i][1]) << "," << time << "\n";
        gcdTimeArr2[i] = time;
    }
    fout.close();

    // record gcd_BF_v2 time statistics in BF_v2_Statistics.csv
    quickSort(gcdTimeArr2, 0, 999); // sorts array in ascending order
    fout.open("BF_v2_Statistics.csv");
    fout << "Statistics,Nanoseconds\n";
    fout << "Maximum Time," << gcdTimeArr2[999] << "\n";
    fout << "Minimum Time," << gcdTimeArr2[0] << "\n";
    fout << "Average Time," << average(gcdTimeArr2) << "\n";
    fout << "Median Time," << median(gcdTimeArr2) << "\n";
    fout.close();

    // record gcd_OE results in OE_Results.csv
    fout.open("OE_Results.csv");
    fout << "Number One,Number Two,Their GCD,Time Spent (Nanoseconds)\n";
    for (int i = 0; i <= 999; ++i)
    {
        int time = std::chrono::duration_cast<std::chrono::duration<int64_t, std::ratio<1, 1000000000>>>(t2 - t1).count();
        fout << randNumArr[i][0] << "," << randNumArr[i][1] << "," << gcd_OE(randNumArr[i][0], randNumArr[i][1]) << "," << time << "\n";
        gcdTimeArr3[i] = time;
    }
    fout.close();

    // record gcd_OE time statistics in OE_Statistics.csv
    quickSort(gcdTimeArr3, 0, 999); // sorts array in ascending order
    fout.open("OE_Statistics.csv");
    fout << "Statistics,Nanoseconds\n";
    fout << "Maximum Time," << gcdTimeArr3[999] << "\n";
    fout << "Minimum Time," << gcdTimeArr3[0] << "\n";
    fout << "Average Time," << average(gcdTimeArr3) << "\n";
    fout << "Median Time," << median(gcdTimeArr3) << "\n";
    fout.close();

    // record gcd_SE results in SE_Results.csv
    fout.open("SE_Results.csv");
    fout << "Number One,Number Two,Their GCD,Time Spent (Nanoseconds)\n";
    for (int i = 0; i <= 999; ++i)
    {
        int time = std::chrono::duration_cast<std::chrono::duration<int64_t, std::ratio<1, 1000000000>>>(t2 - t1).count();
        fout << randNumArr[i][0] << "," << randNumArr[i][1] << "," << gcd_SE(randNumArr[i][0], randNumArr[i][1]) << "," << time << "\n";
        gcdTimeArr4[i] = time;
    }
    fout.close();

    // record gcd_SE time statistics in SE_Statistics.csv
    quickSort(gcdTimeArr4, 0, 999); // sorts array in ascending order
    fout.open("SE_Statistics.csv");
    fout << "Statistics,Nanoseconds\n";
    fout << "Maximum Time," << gcdTimeArr4[999] << "\n";
    fout << "Minimum Time," << gcdTimeArr4[0] << "\n";
    fout << "Average Time," << average(gcdTimeArr4) << "\n";
    fout << "Median Time," << median(gcdTimeArr4) << "\n";
    fout.close();

    // record conclusions on comparative algorithm performance in Conclusions.txt
    fout.open("Conclusions.txt");
    fout << "(1) Out of 1,000 pairs of integers, brute-force (v2) outperformed brute-force (v1) in " << numFaster(gcdTimeArr2, gcdTimeArr1) << " pairs; and the average saved time for these " << numFaster(gcdTimeArr2, gcdTimeArr1) << " pairs of integers was "<< fasterAvg(gcdTimeArr2, gcdTimeArr1) << " nanoseconds.\n";
    fout << "(2) Out of 1,000 pairs of integers, the original version of Euclid outperformed brute-force (v1) in " << numFaster(gcdTimeArr3, gcdTimeArr1) << " pairs; and the average saved time for these " << numFaster(gcdTimeArr3, gcdTimeArr1) << " pairs of integers was " << fasterAvg(gcdTimeArr3, gcdTimeArr1) << " nanoseconds.\n";
    fout << "(3) Out of 1,000 pairs of integers, the original version of Euclid outperformed brute-force (v2) in " << numFaster(gcdTimeArr3, gcdTimeArr2) << " pairs; and the average saved time for these " << numFaster(gcdTimeArr3, gcdTimeArr2) << " pairs of integers was " << fasterAvg(gcdTimeArr3, gcdTimeArr1) << " nanoseconds.\n";
    fout << "(4) Out of 1,000 pairs of integers, the second version of Euclid outperformed the original version of Euclid in " << numFaster(gcdTimeArr4, gcdTimeArr3) << " pairs; and the average saved time for these " << numFaster(gcdTimeArr4, gcdTimeArr3) << " pairs of integers was " << fasterAvg(gcdTimeArr4, gcdTimeArr3) << " nanoseconds\n";
    fout << "(5) Out of 1,000 pairs of integers, the second version of Euclid outperformed brute-force (v1) in " << numFaster(gcdTimeArr4, gcdTimeArr1) << " pairs; and the average saved time for these " << numFaster(gcdTimeArr4, gcdTimeArr1) << " pairs of integers was " << fasterAvg(gcdTimeArr4, gcdTimeArr1) << " nanoseconds.\n";
    fout << "(6) Out of 1,000 pairs of integers, the second version of Euclid outperformed brute-force (v2) in " << numFaster(gcdTimeArr4, gcdTimeArr2) << " pairs; and the average saved time for these " << numFaster(gcdTimeArr4, gcdTimeArr2) << " pairs of integers was " << fasterAvg(gcdTimeArr4, gcdTimeArr2) << " nanoseconds.";
    fout.close();

    return 0;
}


/*************************** methods ***************************/

// gcd brute force v1 algorithm
int gcd_BF_v1(int a, int b)
{
    t1 = std::chrono::steady_clock::now();
    a = abs(a);
    b = abs(b);
    int c = 1; // the gcd being tested
    int g = 1; // the result
    while (c <= a) // repeats until the test gcd, c, is greater than a
    {
        if ((a % c == 0) && (b % c == 0)) // if c is a divisor of both a and b
        {
            g = c;
        }
        ++c;
    }
    t2 = std::chrono::steady_clock::now();
    return g;
}

// gcd brute force v2 algorithm
int gcd_BF_v2(int x, int y) {
    t1 = std::chrono::steady_clock::now();
    x = abs(x);
    y = abs(y);
    int gcd = y;
    if (y == 0) { // Checks for zeroes
        gcd = x;
        t2 = std::chrono::steady_clock::now();
        return gcd;
    }
    while (gcd > 0) {

        if ((x % gcd == 0) && (y % gcd == 0)) {
            break;
        }
        gcd--;
    }
    t2 = std::chrono::steady_clock::now();
    return gcd;
}

// original Euclid's algorithm
int gcd_OE(int x, int y) {
    t1 = std::chrono::steady_clock::now();
    x = abs(x);
    y = abs(y);
    int quotient;
    int remainder;
    if (x < y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
    if (y == 0) {
        t2 = std::chrono::steady_clock::now();
        return x;
    }
    // Beginning the Euclid's algorithm
    quotient = x / y; // Division with x being the biggest #
    remainder = x - quotient * y;
    x = y;
    y = remainder;
    while (remainder != 0) {
        quotient = x / y; // Division with x being the biggest #
        remainder = x - quotient * y;
        x = y;
        y = remainder;
    }
    t2 = std::chrono::steady_clock::now();
    return x;
}

// second Euclid's algorithm
int gcd_SE(int x, int y) {
    t1 = std::chrono::steady_clock::now();
    x = abs(x);
    y = abs(y);
    if (x < y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
    // GCD is found if x or y are 0.
    if (x == 0) {
        t2 = std::chrono::steady_clock::now();
        return y;
    }
    if (y == 0) {
        t2 = std::chrono::steady_clock::now();
        return x;
    }
    // Main algorithm.
    // Variable "x" ends up being the gcd.
    int remainder = -1;
    while (remainder != 0) {
        remainder = x - y;
        if (remainder >= y) { // If true, (x / y) > 1
            remainder -= y;
            if (remainder >= y) { // If true, (x / y) > 2
                remainder -= y;
                if (remainder >= y) { // If true, (x / y) > 3
                    remainder = x - y * (x / y);
                }
            }
        }
        x = y;
        y = remainder;
    }
    t2 = std::chrono::steady_clock::now();
    return x;
}

// returns averge of all values in int array of size 1000
double average(int arr[])
{
    int sum = 0;
    for (int i = 0; i < 1000; ++i)
    {
        sum = sum + arr[i];
    }
    return (sum / 1000.0);
}

// returns median of all values in int array of size 1000
double median(int arr[])
{
    return ((arr[499] + arr[500]) / 2.0);
}

// returns how many values in the first array at index i are lower than the values in the second array at index i
int numFaster(int arr1[], int arr2[])
{
    int num = 0;
    for (int i = 0; i < 1000; ++i)
    {
        if (arr1[i] < arr2[i])
        {
            ++num;
        }
    }
    return num;
}

// returns, only for the times in arr1 faster than arr2, the average time difference
double fasterAvg(int arr1[], int arr2[])
{
    double num = 0.0;
    double avg = 0.0;
    for (int i = 0; i < 1000; ++i)
    {
        if (arr1[i] < arr2[i])
        {
            ++num;
            avg += arr2[i] - arr1[i];
        }
    }
    return (avg / num); // longer - shorter
}