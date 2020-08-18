#include<bits/stdc++.h>
using namespace std; 

int main(){
map<pair<int,int>,int>m;
map<int,int>x; 

int arr[5] = {1,5,5,3,1};
int n=5; 
int i,j,k;
for(i=0; i<n; i++){
    for(j=0; j<n; j++){
        for(k=i; k<=j; k++){
            x[arr[k]]++;
        }
        int count=0;
        for(auto it=x.begin(); it!=x.end(); it++){
            if(it->second>1) count+=it->second; 
        }
        m[{i,j}]=count;
        x.clear();  
    }
}

for(auto it=m.begin(); it!=m.end(); it++){
    pair<int,int>p=it->first;
    cout << "("<<p.first<<","<<p.second<< ") "<<it->second<<endl;
}
return 0;
}


# this is my final version 

# adding some lines to get reflected into dev branch
