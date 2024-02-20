#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY x
 *  2. INTEGER k
 */
int hackerlandRadioTransmitters(vector<int> x, int k) {
    if(x.size() == 1) return 1;
    sort(x.begin(), x.end());
    int counter = 0;
    vector<int>::iterator i = x.begin() + 1;
    bool passedTransmiter = false;
    int dist = 0;
    bool remaining = false;
    while(i < x.end()) {
        int d = *i - *(i-1);
        cout << "d: " << d << endl;
        if (d > k) {
            cout << "Remaining: " << remaining << endl;
            if(remaining) {
                cout << "[C]" << endl;
                counter++;
            }
            counter++;
            cout << "[A]" << endl;
            passedTransmiter = false;
            dist = 0;
            remaining = false;
        } else {
            dist += d;
            if(dist > k) {
                if(!passedTransmiter) {
                    dist = d;
                    passedTransmiter = true;
                    remaining = true;
                } else {
                    dist = 0;
                    passedTransmiter = false;
                    counter++;
                    cout << "[B]" << endl;
                    remaining = true;
                }
            } else {
                remaining = true;
            }
        }
        ++i;
    }
    if(remaining) {
        counter++;
    }
    return counter;
}

int hackerlandRadioTransmittersAlt(vector<int> x, int k) {
    if(x.size() == 1) return 1;
    
    sort(x.begin(), x.end());
    int counter = 0, d = 0;
    bool remaining = false;
    for(int i = 1; i < x.size(); i++) {
        remaining = true;
        int r = x.at(i) - x.at(i-1);
        d += r;
        if(r > k) {
            cout << "New transmitter (R) in: " << x.at(i) << endl;
            counter++;
            d = 0;
            remaining = false;
        } else {
            cout << "d = " << d << endl;
            if(d >= 2*k) {
                counter++;
                cout << "New transmitter (D) ends in: " << x.at(i) << endl;
                d = 0;
                remaining = false;
            }
        }
    }
    if(remaining) {
        cout << "New transmitter (END) ends in: " << x.back() << endl;
        counter++;
    }
    return counter;
}

int main()
{
    ifstream f;
    f.open("input.txt");
    string first_multiple_input_temp;
    getline(f, first_multiple_input_temp);
    //getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string x_temp_temp;
    getline(f, x_temp_temp);
    //getline(cin, x_temp_temp);

    vector<string> x_temp = split(rtrim(x_temp_temp));

    vector<int> x(n);
    cout << "FORMAT" << endl;
    for (int i = 0; i < n; i++) {
        int x_item = stoi(x_temp[i]);

        x[i] = x_item;
    }

    int result = hackerlandRadioTransmitters(x, k);

    cout << result << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char c) { return !ispunct(c); })
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char c) { return !ispunct(c); }).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
