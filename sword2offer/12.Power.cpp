//数值的整数次方
//https://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00
class Solution {
public:
    bool is0(double d){
        return (d-0.0) > -1e-9 && (d-0.0) < 1e-9;
    }
    int error_;
    double Power(double base, int exponent) {
        bool neg = exponent < 0;
        if(neg && is0(base)){
            error_ = 1;
            return 0;
        }
        error_ = 0;
        if(exponent == 0) return 1;
        if(neg) exponent = -exponent;
        double result = GetPower(base,exponent);
        if(neg) result = 1.0/result;
        return result;
    }
    double GetPower(double base,int exponent){
        if(exponent == 1) return base;
        double result = GetPower(base*base,exponent/2);
        if(exponent & 1) result *= base;
        return result;
    }
};