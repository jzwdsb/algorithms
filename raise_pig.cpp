#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;

int main() {

    int C;
    cin>>C;
    vector<int> input(C);
    int N = 0;
    for (int i = 0; i < C; ++i) {
        cin>>input[i];
        if(input[i] > N){
            N = input[i];
        }
    }
    vector<int> ret(N + 1, 0);
    ret[0] = 1;
    ret[1] = 1;
    for(int i = 2; i <= N; ++i)
    {
        ret[i] = ret[i - 1] + ret[i - 2];
    }
    for(int i = 0; i < C; ++i)
    {
        printf("%d\n",ret[input[i]]);
    }
    return 0;
}