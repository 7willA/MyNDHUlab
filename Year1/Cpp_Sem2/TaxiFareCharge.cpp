#include <iostream>
#include <cmath>
using namespace std;
class Charge{
    private:
        static constexpr double KM_rate = 1.2;
        static constexpr double limit = 200;
        static constexpr double discount = 0.75;
    public:
        double calculate(int distance){
            if(distance <=limit){
                return round(distance*KM_rate);
            } else{
                double charge_1 = limit*KM_rate;
                double charge_2 = (distance-limit)*KM_rate*discount;
                return round(charge_1+charge_2);
            }
        }
};
int main(){
    int distance;
    cin >> distance;
    Charge bill;
    double bill_total = bill.calculate(distance);
    cout << bill_total << endl;
    return 0;
}