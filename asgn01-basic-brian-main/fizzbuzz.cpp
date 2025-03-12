#include <iostream>
#include <string>
using namespace std;

int main() {
    const string prompt_fizz = "Enter the fizz number:";
    const string prompt_buzz = "Enter the buzz number:";
    const string error_message = "Invalid input.";

    int f;
    int b;

    cout << prompt_fizz << endl;
    if (!(cin >> f) || f <= 0) {
        cout << error_message << endl;
        return 1;
    }

    cout << prompt_buzz << endl;
    if (!(cin >> b) || b <= 0) {
        cout << error_message << endl;
        return 1;
    }

    for (int i = 1; i <= 20; i++) {
        if (i % f == 0 && i % b == 0) {
            cout << "FizzBuzz" << endl;
        } else if (i % f == 0) {
            cout << "Fizz" << endl;
        } else if (i % b == 0) {
            cout << "Buzz" << endl;
        } else {
            cout << i << endl;
        }
    }

    return 0;
}