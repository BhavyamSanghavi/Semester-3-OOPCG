#include <iostream>
using namespace std;

template<typename t> void insertsort(t arr[] , t n){
float  key;
int j , i;
   for ( i = 1; i < n; i++) {
       key = arr[i];
       j = i - 1;


   while (j >= 0 && arr[j] > key) {
       arr[j + 1] = arr[j];
       j = j - 1;
   }
   arr[j + 1] = key;
   }
}

template<typename t> void selectsort(t arr[] , t n){
int i, j;
int min_idx;


   for (i = 0; i < n - 1; i++) {

       min_idx = i;
       for (j = i + 1; j < n; j++) {
           if (arr[j] < arr[min_idx])
               min_idx = j;
       }

       if (min_idx != i)
           swap(arr[min_idx], arr[i]);
   }
}

template<typename t> void printarray(t arr[] ,t n){
for(int i = 0 ; i < n ; i++){
cout<<arr[i]<<" ";
}
cout<<endl;
}

int main() {
int arr[5] = {5,4,3,2,1};
float arr1[5] = { 4.3, 1.1 , 0.3 , 4.3 , 4.1};

cout<<"INSERTION SORTING"<<endl;
insertsort <int> (arr,5);
printarray <int> (arr,5);
insertsort <float> (arr1,5);
printarray <float> (arr1,5);

int arr2[5] = {5,4,3,2,1};
float arr3[5] = { 4.3, 1.1 , 0.3 , 4.3 , 4.1};

cout<<"SELECTION SORTING"<<endl;
selectsort <int> (arr2,5);
printarray <int> (arr2,5);
insertsort <float> (arr3,5);
printarray <float> (arr3,5);
}

//vector<int,int>v;
//vector<string>v

