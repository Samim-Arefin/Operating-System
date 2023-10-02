/*
 *  Problem : Least Recently Used Page.cpp
 *  Created by Samim Arefin
*/

#include <bits/stdc++.h>

int hit=0,miss=0;

void lru(std::vector<int>&pages, int frameSize)
{
	std::unordered_set<int> frame;
	std::unordered_map<int,int>pageIndex;

	for(int i = 0; i<pages.size(); i++ )
	{
		if(frame.find(pages[i]) != frame.end())
		{
            hit++;
		}
		else
		{
           if(frame.size()<frameSize)
           {
           	   frame.insert(pages[i]);
           	   miss++;
           }
           else
           {
               int last_demand_page = INT_MAX, value = 0;
               for(auto it : frame)
               {
               	   if(last_demand_page > pageIndex[it])
               	   {
               	   	   last_demand_page = pageIndex[it];
               	   	   value = it;
               	   }
               }
               frame.erase(value);
               frame.insert(pages[i]);
               miss++;
           }
		}
		pageIndex[pages[i]] = i;
	}
}

int main()
{
	freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    int pageSize,frameSize;
    std::cin>>frameSize>>pageSize;
    std::vector<int>pages(pageSize);
     
    for(int i = 0; i<pages.size();i++)
    {
    	std::cin>>pages[i];
    }

    lru(pages, frameSize);

    std::cout<<"Hit: "<<hit<<" Miss: "<<miss<<'\n';
}
