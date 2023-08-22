#include <bits/stdc++.h>
using namespace std;

int main()
{
	int pg[] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2 };
	int pn = sizeof(pg) / sizeof(pg[0]);
	int fn = 4;

	bool isFound;
	int hit = 0;
	vector<int> fr;
	vector<int>::iterator it;
	for(int i = 0;i<fn;i++){
        fr.push_back(pg[i]);
	}
	for(int i=fn;i<pn;i++){
        it = fr.begin();
        isFound = false;
        for(auto j = fr.begin() ; j != fr.end(); ++j){
            if(pg[i] == *j){
                it = j;
                isFound = true;
                break;
            }
        }
        if(isFound){
            hit++;
        }
        fr.erase(it);
        fr.push_back(pg[i]);
	}
	cout<<"Number of hits : "<<hit;
	cout<<"\nNumber of misses : "<<pn-hit;
	return 0;
}
