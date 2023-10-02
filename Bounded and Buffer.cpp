/*
 *  Problem : Bounded And Buffer.cpp
 *  Created by Samim Arefin
*/

#include <bits/stdc++.h>

int lock = 1, capacity = 100, fill = 0, product = 0;

void producer()
{
	--lock;
	--capacity;
	++fill;
	++product;
	std::cout<<"Producer produces product "<<product<<'\n';
	++lock;
}

void consumer()
{
	--lock;
	++capacity;
	--fill;
	std::cout<<"Consumer consumes product "<<product<<'\n';
	--product;
	++lock;
}

int main()
{
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while(true)
    {
        int choice;
        std::cin>>choice;
        switch(choice)
        {
        	case 1:
	        	if (lock == 1 && capacity != 0)
	        	{
	        		producer();
	        	}
	        	else
	        	{
                    std::cout<<"Buffer is full!\n";
	        	}
	        	break;
	        case 2:
	        	if (lock == 1 && fill != 0)
	        	{
	        		consumer();
	        	}
	        	else
	        	{
                    std::cout<<"Buffer is empty\n";
	        	}
	        	break;
	        case 3:
	            exit(0);

	        default:
	            std::cout<<"Wrong Choice. Try again !!\n";
	            break;
        }
    }
}
