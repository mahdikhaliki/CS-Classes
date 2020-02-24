//
//  PiSeries.cpp
//
//
//  Created by Mahdi Khaliki on 4/18/18.
//

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

float PI(int count, float i, float answer, int [10]array2) {
        if (count == 10000)
                return answer;
        if (count % 2)
                answer -= 4.0 / i;
        else
                answer += 4.0 / i;
        return PI(++count, i + 2, answer);
}



int main() {
        float answer = 0.0, i = 1.0, b = 0.0;
        int count = 0;
        
        while (count < 10000) {
                if (count % 1000 == 0 && count != 0)
                        cout << setprecision(7) << answer << endl;
                if (count % 2)
                        answer -= 4.0 / i;
                else
                        answer += 4.0 / i;
                i += 2;
                
                count++;
        }
        
        
        cout << setprecision(7) << fixed << answer << endl;
//        cout << PI(0, 1.0, 0.0) << endl;
        
}

