#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &nums){
    int n = nums.size();
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(nums[i] > nums[j]){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

void bubbleSort(vector<int> &nums){
    int n = nums.size();
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(nums[j] > nums[j+1]){
                int temp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

void insertionSort(vector<int> &nums){
    int n = nums.size();
    for(int i=1; i<n; i++){
        int cur = nums[i];
        int j = i-1;
        while(j>=0 && nums[j]>cur){
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = cur;
    }
}

class Merge{
    public:

        void merge(vector<int> &nums, int l, int mid, int r){
            int i = l;
            int j = mid+1;
            int k = l;
            vector<int> temp(10000);

            while(i<=mid && j<=r){
                if(nums[i]<nums[j]){
                    temp[k++] = nums[i++];
                }
                else{
                    temp[k++] = nums[j++];
                }
            }

            while(i<=mid) temp[k++] = nums[i++];
            while(j<=r) temp[k++] = nums[j++];

            for(int f=l; f<=r; f++){
                nums[f] = temp[f];
            }
        }

        void mergeSort(vector<int> &nums, int l, int r){
            if(l<r){
                int mid = l + (r-l)/2;
                mergeSort(nums, l, mid);
                mergeSort(nums, mid+1, r);
                merge(nums, l, mid, r);
            }
        }
};

class Quick{
    public:
        int partition(vector<int> &nums, int low, int high){
            int pivote = nums[low];
            int i = low;
            int j = high;
            while(i<j){
                while(nums[i]<=pivote && i<high-1) i++;
                while(nums[j]>pivote && j>low) j--;
                if(i<j){
                    swap(nums[i], nums[j]);
                }
            }
            swap(nums[j], nums[low]);
            return j;
        }

        void quickSort(vector<int> &nums, int low, int high){
            if(low<high){
                int pivot = partition(nums, low, high);
                quickSort(nums, low, pivot-1);
                quickSort(nums, pivot+1, high);
            }
        }
};

int main(){
    vector<int> nums;
    nums.push_back(21); nums.push_back(12); nums.push_back(5); nums.push_back(8); nums.push_back(36); nums.push_back(8);
    Quick obj;
    obj.quickSort(nums, 0, nums.size());
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }cout<<endl;
return 0;
}