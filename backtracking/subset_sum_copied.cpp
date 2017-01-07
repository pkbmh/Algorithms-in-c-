#include<iostream>
using namespace std;
int n,d,w[10],used[10],count=0;
int cs = 0; // cs=Current Sum

void subset(int k)
{
    if (k >= n) return;  // boundry check
    int i;
    used[k] = 1; // use element k
    cs += w[k];

    if(cs == d) {
        cout<<"\n\nSolution " << ++count << " is:"; 
        for(i=0;i <= k;i++)  
            if(used[i]==1) 
                cout<<w[i]<<" ";
    }
    if (cs < d)  // only when current sum is not enough
        subset(k + 1); 

    used[k] = 0; // not use element k
    cs -= w[k];
    subset(k+1);
}

int  main()
{
    int sum=0,i;

    cout<<"enter n\n";
    cin>>n;

    cout<<"enter "<<n<<" elements\n";
    for(i=0;i<n;i++)
    cin>>w[i];

    for(i=0;i<n;i++)
    sum+=w[i];

    cout<<"enter value of sum\n";
    cin>>d;
    cs = 0;
    if(sum<d)
        cout<<"INVALID SOLUTION\n";
    else
        subset(0);
return 0;
}
