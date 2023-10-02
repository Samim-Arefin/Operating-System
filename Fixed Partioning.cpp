/*
 *  Problem : Fixed Partioning.cpp
 *  Created by Samim Arefin
*/

#include <bits/stdc++.h>
int processNumber,partitionNumber;

void FirstFit(std::vector<int>&processes,std::vector<int>&partitions,std::vector<int>&partitionHolds,std::vector<int>&fragmentation){
	for(int i=0;i<processNumber;i++){
		for(int j=0;j<partitionNumber;j++){
			if(fragmentation[j] == -1 && partitions[j]>=processes[i]){
                partitionHolds[j] = i;
                fragmentation[j] = partitions[j]-processes[i];
                break;
			}
		}
	}
}

void BestFit(std::vector<int>&processes,std::vector<int>&partitions,std::vector<int>&partitionHolds,std::vector<int>&fragmentation){
	for(int i = 0; i<processNumber;i++){
		int bestPartitionIndex = -1;
		for(int j = 0; j<partitionNumber;j++){
			if(fragmentation[j] == -1 && partitions[j]>= processes[i]){
				if(bestPartitionIndex == -1){
					bestPartitionIndex = j;
				}
				else{
					if((partitions[bestPartitionIndex] - processes[i]) > (partitions[j] - processes[i])){
						bestPartitionIndex = j;
					}
				}
			}
		}
		if(bestPartitionIndex != -1){
           partitionHolds[bestPartitionIndex] = i;
           fragmentation[bestPartitionIndex] = partitions[bestPartitionIndex] - processes[i];
		}
	}
}

void WorstFit(std::vector<int>&processes,std::vector<int>&partitions,std::vector<int>&partitionHolds,std::vector<int>&fragmentation){
	for(int i = 0; i<processNumber;i++){
		int worstPartitionIndex = -1;
		for(int j = 0; j<partitionNumber;j++){
			if(fragmentation[j] == -1 && partitions[j]>= processes[i]){
				if(worstPartitionIndex == -1){
					worstPartitionIndex = j;
				}
				else{
					if((partitions[worstPartitionIndex] - processes[i]) < (partitions[j] - processes[i])){
						worstPartitionIndex = j;
					}
				}
			}
		}
		if(worstPartitionIndex != -1){
           partitionHolds[worstPartitionIndex] = i;
           fragmentation[worstPartitionIndex] = partitions[worstPartitionIndex] - processes[i];
		}
	}
}

void print(std::vector<int>&partitions,std::vector<int>&partitionHolds,std::vector<int>&fragmentation){
	int total_internal_fragmentation = 0;

	for(int i=0;i<partitions.size();i++){
		if(fragmentation[i] != -1){
			std::cout<<"Partitions "<<partitionHolds[i]<<" has fragmentation "<<fragmentation[i]<<"\n";
			total_internal_fragmentation +=fragmentation[i];
		}
	}
	std::cout<<"Total Internal Fragmentation:"<<total_internal_fragmentation<<'\n';
}

int main()
{
	freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);

    std::cin>>processNumber>>partitionNumber;

    std::vector<int>processes(processNumber),partitions(partitionNumber),partitionHolds(partitionNumber),fragmentation(partitionNumber);

    for(int i = 0; i<processNumber;i++ ){
    	std::cin>>processes[i];
    	fragmentation[i] = -1;
    }

    for(int i = 0; i<partitionNumber;i++ ){
    	std::cin>>partitions[i];
    }
    
    while(true){
    	int n;
    	std::cin>>n;
    	switch(n){
    		case 1:
    		FirstFit(processes, partitions, partitionHolds, fragmentation);
    		break;
    		case 2:
    		BestFit(processes, partitions, partitionHolds, fragmentation);
    		break;
    		case 3:
    		WorstFit(processes, partitions, partitionHolds, fragmentation);
    		break;
    		case 4:
    		exit(1);
    		default:
    		std::cout<<"Wrong Choice\n";
    	}
        print(partitions,partitionHolds,fragmentation);
        break;
    }
}
