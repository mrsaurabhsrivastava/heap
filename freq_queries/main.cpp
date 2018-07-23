//https://www.hackerrank.com/challenges/frequency-queries/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
vector<int> freqQuery(vector<vector<int>> queries) 
{
	vector<int> lResultVec;	
	unordered_map<int, int> lElFreqMap;
	unordered_map<int, int> lFreqMap;
	for (int i = 0; i < queries.size(); i++) 
	{
		int lOp = queries[i][0];
		if (lOp == 1) 
		{
			// Insert
			int lEl = queries[i][1];
			if (lElFreqMap.find(lEl) != lElFreqMap.end()) 
			{
				// Already exists 
			 	int lCurrFreq = lElFreqMap[lEl];
				int lNewFreq = lCurrFreq+1;
				lElFreqMap[lEl] = lNewFreq;
				lFreqMap[lCurrFreq]--;
				if (lFreqMap.find(lNewFreq) != lFreqMap.end()) 
					lFreqMap[lNewFreq]++;
				else 
					lFreqMap[lNewFreq] = 1;
			}
			else 
			{
				lElFreqMap[lEl] = 1;
				if (lFreqMap.find(1) != lFreqMap.end()) 
					lFreqMap[1]++;
				else 
					lFreqMap[1] = 1;
			}
		}
		else if (lOp == 2) 
		{
			int lEl = queries[i][1];
			if (lElFreqMap.find(lEl) != lElFreqMap.end()) 
			{
				int lCurrFreq = lElFreqMap[lEl];
				int lNewFreq = lCurrFreq-1;
				if (lCurrFreq == 1) 
				{
					lElFreqMap.erase(lElFreqMap.find(lEl));
				}
				lFreqMap[lCurrFreq]--;
				if (lFreqMap[lCurrFreq] == 0) 
				{
					lFreqMap.erase(lFreqMap[lCurrFreq]);
				}
				if (lNewFreq > 0) 
				{
					if (lFreqMap.find(lNewFreq) != lFreqMap.end()) 
						lFreqMap[lNewFreq]++;
					else 
						lFreqMap[lNewFreq] = 1;
					
				}
			}
		}
		else if (lOp == 3) 
		{
			int lSearchFreq = queries[i][1];
			if (lFreqMap.find(lSearchFreq) != lFreqMap.end()) 
				lResultVec.push_back(1);
			else 
				lResultVec.push_back(0);
		}
	}
	return lResultVec;
}


int main () 
{
	vector<vector<int>> lInput = {{1, 100043},
{1, 100062},
{1, 100089},
{1, 100007},
{3, 3},
{2, 3},
{3, 4},
{3, 3},
{3, 4},
{2, 5},
};
	vector<int> lResult = freqQuery(lInput);
	for (auto el:lResult) 
	{
		cout<<el<<endl;
	}
}
