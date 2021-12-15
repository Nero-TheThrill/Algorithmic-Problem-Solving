class Solution {
public:
    int reverse(int x) {
        std::vector<int> v;
        bool isPositive=x>0?true:false;
        bool shouldPlusOne=false;
        if(!isPositive)
        {
            if(x==-2147483648)
            {
                x=-(x+1);
                shouldPlusOne=true;
            }
            else
                x=-x;
        }
        while(x>0)
        {
            v.push_back(x%10);
            x/=10;
        }
        int pow_factor=v.size()-1;
        int result=0;
        for(auto i:v)
        {
            if(9<pow_factor)
                return 0;
            if(9==pow_factor&&i>2)
                return 0;
            if(2147483647-result-i*std::pow(10,pow_factor)<0)
                return 0;
            
            if(pow_factor==v.size()-1 && shouldPlusOne)
                result+=(i+1)*std::pow(10,pow_factor);
            else                
                result+=i*std::pow(10,pow_factor);
           
            pow_factor--;
        }
        if(!isPositive)
            result=-result;


        return result;
    }
};