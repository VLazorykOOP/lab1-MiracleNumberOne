#include <iostream>
#include <fstream>
#include <vector>
#include <valarray>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to enter array elements from console and write to text file
void enterArrayAndWriteToFile() {
    int N;
    cout << "Enter the size of the array: ";
    cin >> N;
    int A[N];
    cout << "Enter " << N << " elements: ";
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Write array elements to text file
    ofstream file("array.txt");
    if (file.is_open()) {
        for (int i = 0; i < N; i++) {
            file << A[i] << " ";
        }
        file.close();
        cout << "Array elements written to 'array.txt' file." << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}

// Function to enter array size and create random array elements and write to binary file
void enterSizeCreateRandomAndWriteToFile() {
    int N;
    cout << "Enter the size of the array: ";
    cin >> N;
    int A[N];
    srand(time(0)); // Seed the random number generator with current time
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 100 + 1; // Generate random numbers between 1 and 100
    }

    // Write array elements to binary file
    ofstream file("array.bin", ios::binary);
    if (file.is_open()) {
        file.write(reinterpret_cast<char*>(&A), sizeof(A));
        file.close();
        cout << "Array elements written to 'array.bin' file." << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}

// Function to solve problems using dynamic arrays
void solveProblemsUsingDynamicArrays() {
    // Read array elements from text file
    ifstream file("array.txt");
    if (file.is_open()) {
        int num;
        vector<int> array;
        while (file >> num) {
            array.push_back(num);
        }
        file.close();

        // Perform operations on array
        // Example: Finding sum, product, max and min of array elements
        int sum = 0;
        int product = 1;
        int max = array[0];
        int min = array[0];
        for (int i = 0; i < array.size(); i++) {
            sum += array[i];
            product *= array[i];
            if (array[i] > max) {
                max = array[i];
            }
            if (array[i] < min) {
                min = array[i];
            }
        }

        // Write results to text file
        ofstream resultFile("result.txt");
        if (resultFile.is_open()) {
            resultFile << "Sum: " << sum << endl;
            resultFile << "Product: " << product << endl;
            resultFile << "Max: " << max << endl;
            resultFile << "Min: " << min << endl;
            resultFile.close();
            cout << "Results written to 'result.txt' file." << endl;
        } else {
            cout << "Unable to open result file." << endl;
        }

        // Output results to console
        cout << "Sum: " << sum << endl;
        cout << "Product: " << product << endl;
        cout << "Max: " << max << endl;
        cout << "Min: " << min << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}

int main() {
    int choice;
    do {
        // Display menu
        cout << "Menu:" << endl;
        cout << "1. Enter array elements from console and write to text file." << endl;
        cout << "2. Enter array size, create random array elements, and write to binary file." << endl;
        cout << "3. Solve problems using dynamic arrays." << endl;
        cout << "4. Read data from files into container and output to console." << endl;
        cout << "5. Exit." << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                enterArrayAndWriteToFile();
                break;
            case 2:
                enterSizeCreateRandomAndWriteToFile();
                break;
            case 3:
                solveProblemsUsingDynamicArrays();
                break;
            case 4:
                // Function to read data from files into container and output to console
                // You can implement this function as per your requirement
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}


void task_2() {
    int N;  // size of array
    cout << "Enter the size of the array: ";
    cin >> N;
    int A[N];  // one-dimensional array
    cout << "Enter " << N << " elements of the array:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int T;  // given number T
    cout << "Enter the given number T: ";
    cin >> T;

    int last_max_pos_index = -1;  // initialize the index of the last maximal element

    for (int i = 0; i < N; i++) {
        if (A[i] > T && A[i] > A[last_max_pos_index]) {
            last_max_pos_index = i;
        }
    }

    // print the index of the last maximal element
    if (last_max_pos_index == -1) {
        cout << "No positive element greater than T found in the array." << endl;
    } else {
        cout << "Index of the last maximal element among the positive elements greater than T: " << last_max_pos_index << endl;
}


void task_3() {
    // input values
    double a, b;
    int n;
    cout << "Enter values of a, b (a < b): ";
    cin >> a >> b;
    cout << "Enter size of array X (n <= 200): ";
    cin >> n;
    double X[n];
    cout << "Enter elements of array X: ";
    for (int i = 0; i < n; i++) {
        cin >> X[i];
    }

    // calculate sum of elements less than a
    double sum = 0;
    for (int i = 0; i < n; i++) {
        if (X[i] < a) {
            sum += X[i];
        }
    }
    cout << "Sum of elements less than a: " << sum << endl;

    // calculate product of elements greater than b
    double product = 1;
    for (int i = 0; i < n; i++) {
        if (X[i] > b) {
            product *= X[i];
        }
    }
    cout << "Product of elements greater than b: " << product << endl;

    // find max and min of elements between a and b
    double max_val = a, min_val = b;
    for (int i = 0; i < n; i++) {
        if (X[i] >= a && X[i] <= b) {
            if (X[i] > max_val) {
                max_val = X[i];
            }
            if (X[i] < min_val) {
                min_val = X[i];
            }
        }
    }
    cout << "Max element between a and b: " << max_val << endl;
    cout << "Min element between a and b: " << min_val << endl;
}
