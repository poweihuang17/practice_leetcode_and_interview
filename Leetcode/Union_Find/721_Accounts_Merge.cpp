#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;


class UF // union find
{
	private: 
		int *id;  // parent link
		int *sz; // size of component for roots
		int count; // number of components

	public:
		UF(int N)
		{
			count=N;
			id=new int[N];
			sz=new int[N];
			for (int i=0;i<N;i++)
			{
				id[i]=i;
				sz[i]=i;
			}
		}
		~UF()
		{
			delete id;
			delete sz;
		}

		int getCount()
		{
			return count;
		}

		int find(int i)
		{
			while(i != id[i])
			{
				id[i] = id[id[i]];  // path compression by halving
				i=id[i];
			}
			return i;
		}

		bool is_connected(int p, int q)
		{
			return find(p)==find(q); // check if two union is connected
		}

		void connect(int p , int q) // Merge
		{
			int i=find(p);
			int j=find(q);
			if (i==j) return;
			//make smaller root point to larger one.
			if(sz[i]<sz[j])
			{
				id[i]=j;
				sz[j]+=sz[i];
			}
			else
			{
				id[j]=i;
				sz[i]+=sz[j];
			}
			count--;
		}
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

    unordered_map< string, int>  email_to_id; //Map email to index of accounts.
    UF u=UF(10000); //DS to find connection between accounts.
    unordered_map<int, vector<string>> seperation; //Map index to the set that it connected with.
	
	for (int i=0; i< accounts.size();i++)
		{
			for (int j=1;j<accounts[i].size();j++)
			{
				if (email_to_id.count(accounts[i][j]))
				{
					u.connect(email_to_id[accounts[i][j]], i);
				}
				else
				{
					email_to_id[accounts[i][j]]=i;
				}
			}
		}

	//Might not be needed if the root is preserved...?

	for (auto kv:email_to_id){
		if (seperation.count(u.find(kv.second)))
		{
			seperation[u.find(kv.second)].push_back(kv.first);
		}
		else
		{
			seperation[u.find(kv.second)]={kv.first};
		}
	}

	vector<vector<string>> result;
	for(auto kv:seperation)
	{
		sort(kv.second.begin(),kv.second.end());
		vector <string> c={accounts[kv.first][0]};
		c.insert(c.end(),kv.second.begin(),kv.second.end());
		result.push_back(c);
	}
	return result;
    }
};

int main()
{
	Solution s= Solution();
	vector<vector<string>> accounts={{"John", "johnsmith@mail.com", "john00@mail.com"}, {"John", "johnnybravo@mail.com"}, {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"Mary", "mary@mail.com"}};
	s.accountsMerge(accounts);

	vector<vector<string>> accounts2={{"David","David0@m.co","David0@m.co","David1@m.co","David2@m.co","David3@m.co","David4@m.co","David5@m.co","David6@m.co","David7@m.co"},{"David","David0@m.co","David0@m.co","David1@m.co","David2@m.co","David3@m.co","David4@m.co","David5@m.co","David6@m.co","David7@m.co"},{"David","David2@m.co","David18@m.co","David19@m.co","David20@m.co","David21@m.co","David22@m.co","David23@m.co","David24@m.co","David25@m.co"},{"David","David3@m.co","David27@m.co","David28@m.co","David29@m.co","David30@m.co","David31@m.co","David32@m.co","David33@m.co","David34@m.co"},{"David","David1@m.co","David9@m.co","David10@m.co","David11@m.co","David12@m.co","David13@m.co","David14@m.co","David15@m.co","David16@m.co"}};
	s.accountsMerge(accounts2);

	vector<vector<string>> accounts3={{"David","David5@m.co","David8@m.co"},{"David","David1@m.co","David1@m.co","David8@m.co"},{"David","David0@m.co","David0@m.co","David5@m.co"}};
	s.accountsMerge(accounts3);
}