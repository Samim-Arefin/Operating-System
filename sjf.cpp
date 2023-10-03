#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cout<<"Number of Process: ";
    cin>>n;
    //[sj][AT,BT,CT,TAT,WT,P_ID]
    int p[n][6];
    for(int i=0;i<n;i++){
        cout<<"insert "<<i+1<<" no. process arrival time and brust time: ";
        cin>>p[i][0]>>p[i][1];
        p[i][5] = i+1;
    }

    //sorting(insertion sort) according to bt keeping first one unchanged
    for(int i=1;i<n;i++){
        int minbt = i;
        for(int j = i;j<n;j++){
            if(p[j][1]<p[i][1]){
                minbt = j;
            }
        }
        swap(p[i][0],p[minbt][0]);//at
        swap(p[i][1],p[minbt][1]);//bt
        swap(p[i][5],p[minbt][5]);//p_ID
    }


    //calculating ct
    p[0][2] = p[0][0] + p[0][1]; //initial ct = first ct - first at
    for(int i=1;i<n;i++){
        if(p[i-1][2]>p[i][0]){
            p[i][2] = p[i-1][2] + p[i][1];
        }else{
            p[i][2] = p[i][0] + p[i][1];
        }
    }

    //calculating tat,wt
    for(int i=0;i<n;i++){
        p[i][3] = p[i][2] - p[i][0]; //tat
        p[i][4] = p[i][3] - p[i][1]; //wt
    }

    double totalwt = 0;
    for(int i=0;i<n;i++){
        cout<<"process No: "<<p[i][5]<<"\t AT-"<<p[i][0]<<" BT-"<<p[i][1]<<" CT-"<<p[i][2]<<" TAT-"<<p[i][3]<<" WT-"<<p[i][4]<<endl;
        totalwt += p[i][4];
    }

    cout<<"\nAverage waiting time: "<<totalwt/n<<endl;
}
