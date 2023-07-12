#include<bits/stdc++.h>
using namespace std;

class processor
{
public:
    string name;
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;
};

void calculate_CompletionTime(vector<processor>& processorList)
{
    processorList[0].CT = processorList[0].AT + processorList[0].BT;
    for (int i = 1; i < processorList.size(); i++)
    {
        processorList[i].CT = (processorList[i].AT <= processorList[i - 1].CT ?
            processorList[i].BT + processorList[i - 1].CT : processorList[i].BT + processorList[i].AT);
    }
}

void calculate_TurnAroundTime(vector<processor>& processorList)
{
    for (auto& processor : processorList)
        processor.TAT = processor.CT - processor.AT;
}

void calculate_WaitingTime(vector<processor>& processorList)
{
    for (auto& processor : processorList)
        processor.WT = processor.TAT - processor.BT;
}

int main()
{
    int n;
    std::cout << "Enter the number of Processor : ";
    std::cin >> n;
    std::vector<processor> processorList(n);
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter the Processor Name, Arival Time & Burst Time : ";
        std::cin >> processorList[i].name>> processorList[i].AT >> processorList[i].BT;
    }

    calculate_CompletionTime(processorList);
    calculate_TurnAroundTime(processorList);
    calculate_WaitingTime(processorList);

    std::cout << '\n';
    std::cout << "name\t at\t bt\t ct\t tat\t wt\n";

    for (auto& processor : processorList)
    {
        std::cout << processor.name << "\t" << processor.AT << "\t" << processor.BT << "\t"
            << processor.CT << "\t" << processor.TAT << "\t" << processor.WT << '\n';
    }
    return 0;
}
