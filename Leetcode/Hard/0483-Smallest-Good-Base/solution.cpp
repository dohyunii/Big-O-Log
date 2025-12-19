class Solution {
public:
    string smallestGoodBase(string n) {
        long long int x = stoll(n);
        for(int i = ceil(log2(x)); i > 2; --i){
            int q = pow(x, 1.0 / (i - 1));
            unsigned long long int answer = 0, p = 1;
            for(int j = 0; j < i; ++j){
                answer += p;
                p *= q;
            }
            if(answer == x){
                return to_string(q);
            }
        }
        return to_string(x - 1);
    }
};
