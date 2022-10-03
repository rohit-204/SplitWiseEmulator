#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

class person_compare
{
    public:
    bool operator()(pair<string, int>p1, pair<string, int>p2)
    {
        return p1.second<p2.second;
    }
};


int main() {
    ios_base::sync_with_stdio(true);
    cin.tie(NULL);
	int no_transaction;
	int no_friends;
	cin>>no_transaction;
	cin>>no_friends;
	string x,y;
    int amount;
    map< string , int> net;
    while(no_transaction--)
    {
        cin>>x>>y>>amount;
        if(net.count(x)==0)
        {
            net[x]=0;
        }
        if(net.count(x)==0)
        {
            net[y]=0;
        }
        net[x]-=amount;
        net[y]+=amount;
    }
    multiset< pair<string,int>,person_compare >m;
    for(auto p:net){
    string person=p.first;
    int amount= p.second;
    if(net[person]!=0)
    {
        m.insert(make_pair(person,amount));
    }
    }
    int count=0;
    while(!m.empty())
    {
        auto low =m.begin();
        auto high =prev(m.end());
        int debit=low->second;
        string debit_person=low->first;
        int credit=high->second;
        string credit_person=high->first;
        
        int settled_amount=min(abs(debit),credit);
        debit+=settled_amount;
        credit-=settled_amount;
        
        cout<<debit_person<<" will pay "<<settled_amount<<" to "<<credit_person<<endl;
        
        m.erase(low);
        m.erase(high);
        
        if(debit!=0)
        {
            m.insert(make_pair(debit_person,debit));
            
        }
        if(credit!=0)
        {
            m.insert(make_pair(credit_person,credit));
        }
        
        count+=1;
        
    }
	return 0;
}
