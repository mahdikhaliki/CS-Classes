//
//  Fib.cpp
//  
//
//  Created by Mahdi Khaliki on 4/18/18.
//

#include <iostream>
using namespace std;

int Fib( int n )
{
        if( n <= 0 )
        return 0
        endif
        if( n == 1 )
        return 1
        endif
        x = Fib( n-1 )
        y = Fib( n-2 )
        return x + y
}

int main() {
        
        return 0;
}
