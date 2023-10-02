/*
 *  Problem : First Come First Serve.cpp
 *  Created by Samim Arefin
*/

#include <bits/stdc++.h>

class processor{
public:
	std::string Name;
	int AT;
	int BT;
	int CT;
	int TAT;
	int WT;
};

void calculateCT(std::vector<processor>& processorList)
{
     processorList[0].CT = processorList[0].AT+ processorList[0].BT;
     for(int i = 1; i<processorList.size(); i++ )
     {
     	processorList[i].CT = processorList[i-1].CT > processorList[i].AT
     	                      ? processorList[i-1].CT + processorList[i].BT
     	                      : processorList[i].AT+ processorList[i].BT;
     }
}

void calculate(std::vector<processor>& processorList){
     for(auto& processor : processorList)
     {
          processor.TAT = processor.CT - processor.AT;
          processor.WT = processor.TAT - processor.BT;
     }
}

int main()
{
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int processSize;
    std::cout<<"Enter Process Size:\n";
    std::cin>>processSize;

    std::vector<processor> processorList(processSize);

    std::cout << "Enter the Processor Name, Arival Time & Burst Time:";
    for(int i=0;i<processSize;i++)
    {
        std::cin>>processorList[i].Name>>processorList[i].AT>>processorList[i].BT;
    }

    std::sort(processorList.begin(), processorList.end(), [](processor a, processor b)
    {
          return a.AT < b.AT;
    });

    calculateCT(processorList);
    calculate(processorList);

    std::cout<<"\nName\t AT\t BT\t CT\t TAT\t WT\n";
    for(auto processor : processorList)
    {
       std::cout<<processor.Name<<'\t'<<processor.AT<<'\t'<<processor.BT<<'\t'<<processor.CT<<'\t'<<processor.TAT<<'\t'<<processor.WT<<'\n';
    }
}
