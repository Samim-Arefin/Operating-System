#include<bits/stdc++.h>
#include<algorithm>

using namespace std;
int main() {

    int n;
    std::cout << "Enter the number of Process : ";
    std::cin >> n;
    int pid[100], at[100], bt[100], ct[100], tat[100], wt[100];

    for (int i = 0; i < n; i++) 
    {
        std::cout << "Enter Arival & Burst Time : ";
        std::cin >> at[i] >> bt[i];
    }

    priority_queue<pair<int, pair<int, int>>> pqu;

    int last_arrive = 0;
    while (at[last_arrive] <= at[0]) 
    {
        pqu.push({ -bt[last_arrive],{at[last_arrive],last_arrive} });
        last_arrive++;
    }

    int pre_com = pqu.top().second.second;
    ct[pre_com] = pqu.top().second.first + (-pqu.top().first);
    pqu.pop();

    for (int i = 1; i < n; i++) 
    {
        while (last_arrive < n && at[last_arrive] <= ct[pre_com]) 
        {
            pqu.push({ -bt[last_arrive],{at[last_arrive],last_arrive} });
            last_arrive++;
        }
        if (pqu.empty()) 
        {
            if (last_arrive < n) 
            {
                pqu.push({ -bt[last_arrive],{at[last_arrive],last_arrive} });
                last_arrive++;
            }
            else 
            {
                break;
            }
        }
        int cur_com = pqu.top().second.second;
        ct[cur_com] = max(ct[pre_com], pqu.top().second.first) + (-pqu.top().first);
        pre_com = cur_com;
        pqu.pop();
    }


    int ttat = 0, twt = 0;

    for (int i = 0; i < n; i++) 
    {
        tat[i] = ct[i] - at[i];
        ttat += tat[i];
        wt[i] = tat[i] - bt[i];
        twt += wt[i];
    }

    std::cout << "AT" << '\t' << "BT" << '\t' << "CT" << '\t' << "TAT" << '\t' << "WT\n";
    for (int i = 0; i < n; i++) 
    {
        cout << at[i] << '\t' << bt[i] << '\t' << ct[i] << '\t' << tat[i] << '\t' << wt[i] << '\n';
    }
    cout << '\n';
    cout << "Total : " << "\t\t" << ttat << '\t' << twt << '\n';

    cout << "Average Tarn Around Time : " << ttat / (n + 0.0) << '\n';
    cout << "Average Waiting Time : " << twt / (n + 0.0) << '\n';
    return 0;
}
