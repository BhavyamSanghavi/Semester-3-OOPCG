#include <iostream>
#include<string>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<string>>s)
{
for(int i=0;i<s.size();i++)
{
for(int j=0;j<s[0].size();j++)
{
cout<<s[i][j]<<"  ";
}
cout<<"Next item"<<endl;
}
}

void search(vector<vector<string>>s,string key)
{
for(int i=0;i<s.size();i++)
{
if(s[i][3]==key)
{
for(int j=0;j<s[0].size();j++)
{
cout<<s[i][j]<<"  ";
}
break;
}
}
}

int main() {
vector<vector<string>>s;
vector<string>v;

int cond=1;
while(cond!=0)
{
string item,name,cost,quan;
cout<<"Item=";cin>>item;
cout<<"Name=";cin>>name;
cout<<"Cost=";cin>>cost;
cout<<"Quantity=";cin>>quan;

v.push_back(cost);
v.push_back(name);
v.push_back(quan);
v.push_back(item);
for(int i=0;i<v.size();i++)
{
cout<<v[i]<<"  ";
}cout<<endl;
s.push_back(v);
v.clear();

cout<<"Press 0 to exit=";cin>>cond;
}

sort(s.begin(),s.end());
print(s);

search(s,"bat");
return 0;
}
