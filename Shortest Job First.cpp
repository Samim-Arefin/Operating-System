/*
 *  Problem : Shortest Job First.cpp
 *  Created by Samim Arefin
*/

#include <bits/stdc++.h>

class processor{
public:
    int index;
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;
    std::string name;
    bool isComplete = false;
};

void CalculateCT(std::vector<processor>& processorList)
{
     processorList[0].CT = processorList[0].AT + processorList[0].BT;
     processorList[0].isComplete = true;

     for(int i = 1; i<processorList.size();i++)
     {
        std::vector<processor>Temporary_ProcessorList;
        int CT = processorList[i-1].CT;
        for(int j = 0; j<processorList.size();j++)
        {
           if(!processorList[j].isComplete && processorList[j].AT <= CT)
           {
               Temporary_ProcessorList.push_back(processorList[j]);
           }
        }

        std::sort(Temporary_ProcessorList.begin(),Temporary_ProcessorList.end(), [](processor a, processor b)
        {
            if(a.BT == b.BT)
            {
               return a.AT<b.AT;
            }
            else
            {
               return a.BT<b.BT;
            }
        });

        for(int j = 0 , k = i; j < Temporary_ProcessorList.size(); j++)
        {
            processorList[k++] = Temporary_ProcessorList[j];
        }
        processorList[i].isComplete = true;
        processorList[i].CT = processorList[i-1].CT > processorList[i].AT
     	                      ? processorList[i-1].CT + processorList[i].BT
     	                      : processorList[i].AT+ processorList[i].BT;
     }

}

void Calculate_TAT_AND_WT(std::vector<processor>& processorList)
{

    for(auto& processor: processorList)
    {
        processor.TAT = processor.CT - processor.AT;
        processor.WT = processor.TAT - processor.BT;
    }
}

void SJF(std::vector<processor>& processorList)
{
   std::sort(processorList.begin(), processorList.end(), [](processor a, processor b)
        {
            return a.AT<b.AT;
        });

    CalculateCT(processorList);
    Calculate_TAT_AND_WT(processorList);

    std::sort(processorList.begin(), processorList.end(), [](processor a, processor b)
        {
            return a.index<b.index;
        });
}


int main()
{
	freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    

   int processSize;
   std::cin>>processSize;

   std::vector<processor> processorList(processSize);

   for(int i = 0; i<processSize;i++)
   {
       std::cin>>processorList[i].name>>processorList[i].AT>>processorList[i].BT;
       processorList[i].index = i;
   }
   
   SJF(processorList);

   std::cout<<"Name\t AT\t BT\t CT\t TAT\t WT\n";
   for(auto processor : processorList)
   {
      std::cout<<processor.name<<'\t'<<processor.AT<<'\t'<<processor.BT<<'\t'<<processor.CT<<'\t'<<processor.TAT<<'\t'<<processor.WT<<'\n';
   }
}
