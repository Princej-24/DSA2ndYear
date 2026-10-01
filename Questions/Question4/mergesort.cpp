#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr,int st,int mid,int end){       //2nd step // TC=0(n)
    vector<int> temp;       // creating temporary array to store the sorted elements //SC=0(n) because of temp extra space
    int i=st, j=mid+1;        // taking two pointers

    while(i<=mid && j<=end){    // camparison 
        if(arr[i]<=arr[j]){        // if we want to sort in decreasing order then (arr[i]>=arr[j]) 
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid){ //remaining elements in left half
        temp.push_back(arr[i]);
            i++;
    }
 
    while(j<=end){ // remaining elements in right half
         temp.push_back(arr[j]);
            j++;
    }

    for(int idx=0;idx<temp.size();idx++){ // pushing back elements from temp to small sorted arrays
        arr[idx+st]=temp[idx];
    }


}

void mergeSort(vector<int> &arr,int st,int end){
    if(st<end){

        int mid=st+(end-st)/2;

        mergeSort(arr,st,mid); // left half
        mergeSort(arr,mid+1,end); // right half

        merge(arr,st,mid,end); // 2nd step

    }
}

int main(){

    vector<int> arr={11,43,23,44,5,2};
    mergeSort(arr,0,arr.size()-1);

    for(int val:arr){ // to print the sorted elements
        cout<<val<<endl;
    }
    return 0;
}
// this algo is sorting in increasing order 

//--------------------------------------------------------



