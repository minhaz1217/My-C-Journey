#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a, b) cout << a << " : " << b << endl;
#define msg2(a, b, c ) cout << a << " : " << b << " : " << c << endl;

int main(){
    int n,a,b,x,y,z, counter, i,mcounter;
    int arr[3];
    while(scanf("%d", &n) == 1){
    stack<int>st;
    queue<int>q;
    priority_queue<int>pq;
    for(i=0;i<3;i++){
        arr[i] = 1;
    }
    mcounter = 0;
        while(n--){
            scanf("%d %d", &a, &b);
            if(a == 1){
                st.push(b);
                q.push(b);
                pq.push(b);
                mcounter++;
            }else if(a == 2){
                if(mcounter>0){
                    x = st.top();
                    y = q.front();
                    z = pq.top();
                    st.pop();
                    q.pop();
                    pq.pop();
                    if(x != b){
                        arr[0] = 0;
                    }
                    if(y != b){
                        arr[1] =0;
                    }
                    if(z!=b){
                        arr[2] = 0;
                    }
                    mcounter--;
                }else{
                    arr[0] = 0;
                    arr[1] = 0;
                    arr[2] = 0;
                }
                //cc(z)
            }
        }

        counter = 0;
        for(i=0;i<3;i++){
            if(arr[i]){
                counter++;
            }
        }
        if(counter >1){
            printf("not sure\n");
        }else if(counter == 0){
            printf("impossible\n");
        }else if(arr[0] == 1){
            printf("stack\n");
        }else if(arr[1] == 1){
            printf("queue\n");
        }else if(arr[2] == 1){
            printf("priority queue\n");
        }

    }

    return 0;
}
