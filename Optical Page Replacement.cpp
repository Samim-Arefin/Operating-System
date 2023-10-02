/*
 *  Problem : Optical Page Replacement.cpp
 *  Created by Samim Arefin
*/

#include <bits/stdc++.h>

int frameSize,pageSize,hit=0,miss=0;

void opr(std::vector<int>&pages)
{
    std::set<int> frames;
    std::vector<int>::iterator it;

    for(int i = 0;i<pages.size();i++)
    {
        if(frames.find(pages[i]) != frames.end())
        {
            hit++;
        }
        else
        {
            if(frames.size()< frameSize)
            {
                frames.insert(pages[i]);
                miss++;
            }
            else
            {
                int current_page = pages[i], next_index = i+1, frameFound = 0, page_found = 0, page_not_found = 0, least_demand_page = INT_MIN, pageIndex;
                for(auto frame : frames)
                {
                    it = std::find(pages.begin()+next_index,pages.end(),frame);
                    if(it != pages.end())
                    {
                        frameFound++;
                        pageIndex = it - pages.begin()+next_index;
                        if(pageIndex > least_demand_page )
                        {
                            least_demand_page = pageIndex;
                            page_found = *it;
                        }
                    }
                    else
                    {
                        page_not_found = frame;
                        break;
                    }
                }
                if(frameSize == frameFound)
                {
                    frames.erase(page_found);
                }
                else
                {
                    frames.erase(page_not_found);
                }
                frames.insert(current_page);
                miss++;
            }
        }
    }
}

int main()
{
	freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);

    std::cin>>frameSize>>pageSize;
    std::vector<int>pages(pageSize);

    for(int i=0;i<pageSize;i++)
    {
        std::cin>>pages[i];
    }

    opr(pages);

    std::cout<<"Hit: "<<hit<<" Miss: "<<miss<<'\n';
}
