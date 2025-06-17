#include <iostream>
#include <vector>
using namespace std;


// Training data
vector<double> x = {1, 2, 3, 4, 5};       // Input features
vector<double> y = {2, 4, 6, 8, 10};      // Corresponding targets (y = 2x)

// Initialize parameters
double m = 0; // slope
double c = 0; // intercept
double learningRate = 0.01;
int epochs = 10000;
void train() {
    int n = x.size();

    for (int epoch = 0; epoch < epochs; ++epoch) {
        double dm = 0; // derivative of loss w.r.t m
        double dc = 0; // derivative of loss w.r.t c

        // Compute gradients
        for (int i = 0; i < n; ++i) {
            double prediction = m * x[i] + c;
            double error = prediction - y[i];
            dm += error * x[i];
            dc += error;
        }

        // Update parameters
        m -= (learningRate * dm) / n;
        c -= (learningRate * dc) / n;

        // Optional: print loss every 100 epochs
        if (epoch % 100 == 0) {
            double loss = 0;
            for (int i = 0; i < n; ++i) {
                double prediction = m * x[i] + c;
                loss += (prediction - y[i]) * (prediction - y[i]);
            }
            cout << "Epoch " << epoch << " - Loss: " << loss / n << endl;
        }
    }
}

void test(double testX) {
    double prediction = m * testX + c;
    cout << "Prediction for x = " << testX << ": y = " << prediction << endl;
}

int main() {
    train();
    cout << "\nFinal model: y = " << m << "x + " << c << endl;

    // Test prediction
    test(6);  // Should be close to 12
    test(10); // Should be close to 20
    return 0;
}
