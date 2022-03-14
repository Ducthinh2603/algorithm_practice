#include<iostream>

using namespace std;


int Maxdistance (int A[], int N)
    {
        //code here
        int s = 0, l = 0, r = 0;
        int templ = 0;
        int rs = 0;
        while(r < N){
            if (r == N - 1){
                rs = max(rs, r - l);
                return rs;
            }
            if (A[r] > A[r + 1]){
                rs = max(rs, r - l);
                l = templ;
                s = r + 1;
            }
            else if (A[r] < A[r+1]){
                templ = r+1;
            }
            r += 1;
        }
    }

int main(){
    int N = 3;
    int arr[] =  {4,3,3};
    int rs = Maxdistance(arr, N);
    cout << rs;
}

