class Solution {
public:
    long long Multiply(long long m, long long n)
    {
        if(0 == n) {return 0;}
        if(1 == n) {return m;}
        int ret = 0;
        if((n & 0x1) == 0x1) ret += m;
        return ret + (Multiply(m, n>>1) << 1);
    }
    
    int GetBound(long long dividend, long long divisor)
    {
        int n = 0; // log(dividend/divisor)
        long long sum = divisor;
        while(sum < dividend)
        {
            n++;
            sum = sum + sum;
        }
        if(sum == dividend) {n++;}
        return n;
    }
    
    long long BSearch(long long dividend, long long divisor, int n)
    {
        long long l = ((long long)1) << (n - 1);
        long long r = ((long long)1) << n;
        while(l < r - 1)
        {
            long long mid = l + ((r - l) >> 1);
            if(Multiply(divisor, mid) > dividend) {r = mid;}
            else{l = mid;}
        }
        return l;
    }
    
    int divide(int dividend, int divisor) {
        bool isPos = false;
        if(0 == dividend) {return 0;}
        if((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
        {
            isPos = true;
        }
        else
        {
            isPos = false;
        }
        long long divdendll = dividend;
        long long divisorll = divisor;
        if(divdendll < 0) {divdendll = 0 - divdendll;}
        if(divisorll < 0) {divisorll = 0 - divisorll;}
        if(divdendll < divisor) {return 0;}
        int n = GetBound(divdendll, divisorll);
        long long ret = BSearch(divdendll, divisorll, n);
        if(!isPos) {ret = 0 - ret;}
        return ret;
    }
};
