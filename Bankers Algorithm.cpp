/*
 *  Problem : Bankers Algorithm.cpp
 *  Created by Samim Arefin
*/

#include <bits/stdc++.h>

int main()
{
	freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);

    int processSize = 5, resourceSize = 3 ,flag,index = 0;
    int sequence[processSize],finish[processSize]={0},need[processSize][resourceSize];

    int allocated[processSize][resourceSize] = { 
								    	          { 0, 1, 0 },
												  { 2, 0, 0 },
												  { 3, 0, 2 },
												  { 2, 1, 1 },
												  { 0, 0, 2 } 
										       };

    int maximum[processSize][resourceSize] = { 
								    	        { 7, 5, 3 },
												{ 3, 2, 2 },
												{ 9, 0, 2 },
												{ 2, 2, 2 },
												{ 4, 3, 3 } 
											 };

    int available[resourceSize] = { 3, 3, 2 };

    for(int i = 0; i<processSize; i++)
    {
    	for(int j = 0; j < resourceSize; j++)
    	{
    		need[i][j] = maximum[i][j]-allocated[i][j];
    	}
    }
   
    
    for(int i = 0; i < processSize; i++)
    {
    	flag = 0;
    	if(finish[i] == 0)
    	{
    		for(int j = 0; j < resourceSize; j++)
    		{
    			if(need[i][j] > available[j])
    			{
    				flag = 1;
    				break;
    			}
    		}
            
            if(flag == 0)
            {
                finish[i] = 1;
                sequence[index++] = i;
                for(int j = 0; j<resourceSize;j++)
                {
                    available[j] += allocated[i][j];
                }
                if(i == processSize-1)
                {
                   i = -1;
                }
            }
    	}
    }

    bool check = true;
    for(int i = 0; i<processSize;i++)
    {
        if(finish[i] == 0)
        {
           check = false;
           std::cout << "The given sequence is not safe";
		   break;
        }
    }

    if(check)
    {
       for(int i = 0; i<processSize;i++)
       {
          std::cout<<"P"<<sequence[i]<<" ";
       }
       std::cout<<'\n';
    }
}
