#include <iostream>
#include <fstream>
using namespace std;
class Student{
public:
string name;
int rollno;

void accept(){
cout<<"Enter name";
cin>>name;
cout<<"Enter the roll no"<<endl;
cin>>rollno;
}
void display(){
// cout<<"Name : "<<name;
// cout<<"Roll No : "<<rollno;
fstream f;
f.open("mytext.txt",ios::in);
if(!f){
cout<<"ERROR file does not exit";
}
else{
char x;
while(1){
x=f.get();
if(f.eof())
break;
cout<<x;
}
}
f.close();
}
};
int main() {
fstream f;
Student obj;
int record;
cout<<"How many records you want"<<endl;
cin>>record;

f.open("mytext.txt",ios::out);
while(record--){
obj.accept();

if(!f){
cout<<"ERROR while creating a file";
}
else{
cout<<"File created and also data got written into the file \n";
f<<"Name="<<obj.name<<endl<<"Roll No="<<obj.rollno<<endl;
}
}
f.close();
obj.display();
//
return 0;
}
