#include <iostream>
#include <stdlib.h>
#include <string> 
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

double pv = 0.0181*2;


void put_call_parity(double call, double put, double taiex[], double strike){
    if(put!=0){
        double put_price = call + strike*pv - taiex[1];
        double call_price = taiex[1] + put - strike*pv;
        if(put_price!=put){
            if(put_price<put){
                double arbitrage = abs(put-put_price)+(taiex[0]-taiex[1]) - 3;
                return "Put Call Parity: Sell a put. Sell a Taiex, Buy a call."
            }
            else{
                double arbitrage = abs(put-put_price)-3;
                return "Put Call Parity: Buy a put. Buy a Taiex. Sell a call."
            }
        }
    }
}

void put_call_future_parity(double call, double put, double future[], double strike){
    if(put!=0){
        put_price = call + strike*pv - future[0]*pv;
        call_price = -strike*pv + put + future[0]*pv;
        if(put_price!=put){
            if(put_price < put){
                arbitrage = abs(put_price - put)-3;
                return "Put Call Future Parity: Sell a put. Sell a future. Buy a call."
            }
            else{
                arbitrage = abs(put_price - put)-(future[1]-future[0]);
            }
        }
    }

    return arbitrage;
}


void theorem_3(double call, double put, double taiex[], double strike){
    if(call > taiex[0]){
        arbitrage = (call-taiex[0])-2;
        return "Theorem 3: Short a call, Long the stock"
    }
    if(put > strike){
        arbitrage = put-1;
        return "Theorem 3: Short a put."
    }
    else{
        return "No arbitrage"
    }
}


void theorem_4(double call, double put, double taiex[], double strike){
    if(call < max((taiex[1]-strike*pv),0)){
        arbitrage = (max((taiex[1] - strike*pv), 0) - call) + (taiex[0] - taiex[1]) - 2;
        return "Theorem 4: Long a call. Short the stock."
    }
    else{
        return "No arbitrage."
    }
}


void theorem_6(double call, double put, double taiex[], double strike){
    if(put!=0){
        if(put<max((strike*pv - taiex[1]), 0){
            arbitrage = (max((strike*pv - taiex[1]),0) - put - 2);
            return "Theorem 6: Long a put. Long the stock."
        }
        else{
            return "Theorem 6: No arbitrage."
        }
    }
}




int main(){
    double taiex[] = {9900,10000,10100,10200,10300,10400,10500,10600,10700,10800,10900,11000,11100,11200};
    double call[] = {665,585,510,424,339,263,190,132,87,54,32.5,19,12.5,2.1};
    double put[] = {16.5, 21.5,28.5,40.5,55,77,107,147,201,266,345,432,520,580};
    double strike[] = {9900,10000,10100,10200,10300,10400,10500,10600,10700,10800,10900,11000,11100,11200};

    put_call_parity(call, put, taiex, strike);
    put_call_future_parity(call, put, taiex, stirke);
    theorem_3(call,put,taiex, strike);
    theorem_4(call,put,taiex, strike);
    theorem_6(call,put,taiex, strike);
    return 0;
}