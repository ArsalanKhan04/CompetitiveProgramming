#include <bits/stdc++.h>

using namespace std;

class Solution {
    int strLen;
    int cycleSize;
    string output;
    public:
        string convert(string s, int numRows) {
            if (numRows < 2) { return s;}
            output = s;
            strLen = s.size();  
            cycleSize = 2*numRows - 2;
            cout << "cycleSize: " << cycleSize << endl;
            int c = 0;
            int currInd;
            for (int i = 0; i*cycleSize < strLen; i++) {
                output[c++] = s[i*cycleSize];
            }
            for (int row = 1; row < numRows - 1; row++){
                for (int i = 0; i*cycleSize < strLen; i++) {
                    currInd = i*cycleSize + row;
                    if (currInd < strLen) {
                        output[c++] = s[currInd];
                    }
                    currInd = (i+1)*cycleSize - row;
                    if (currInd < strLen) {
                        output[c++] = s[currInd];
                    }
                }
            }
            for (int i = numRows-1; i < strLen; i+= cycleSize){
                output[c++] = s[i];
            }
            return output;
        }
};

int main() {
    Solution newSol;
    string check = "A";

    cout << newSol.convert(check, 1) << endl;

}
