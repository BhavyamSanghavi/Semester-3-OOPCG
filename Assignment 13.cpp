#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main ()
{
    map<string,int>m;
    int num;
    cout<<"Enter the number of states you want to enter : ";cin>>num;cout<<endl;
    for(int i = 0 ;i<num ; i++){
        string name;
        cout<<"Enter name of state : ";cin>>name;cout<<endl;
        int popu;
        cout<<"Enter name of Population : ";cin>>popu;cout<<endl;
        m.insert({name,popu});
    }

    string s;
    cout << endl
         << "Enter state name you wanna find population of :- ";
    cin >> s;
    map<string,int>::iterator it=m.begin();
    it = m.find(s);
    if(it!=m.end()){
        cout<<"Population of the "<<it->first<<" is  "<<it->second<<endl;
    }
    else{
        cout<<"Not found!!!";
    }
    
    return 0;
}
