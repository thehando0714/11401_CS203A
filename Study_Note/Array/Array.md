# Array
## Description
Array is a data structure that stored data in **contiguous memory locations**,every data can be accessed by using index.
Array's size could be static or dynamic,and all elements need to same data type.

## Abstract Data Type
Array's operation: 
- Traversal all element in array,⏲️time complexity:**O(n)**.
- Access an element in array can directly access by index,⏲️time complexity:**O(1)**
- Insert an element to array have two situation:
  1. Worst case,insert an element to the beginning of an array,⏲️time complexity :**O(n)**
  2. Best case,insert an element to the end of an array,⏲️time complexity:**O(n)**
- Erase an element in an array also have two situation:
  1. Worst case,erase an element in the beginning of an array,⏲️time complexity :**O(n)**
  2. Best case,erase an element in the end of an array,⏲️time complexity:**O(n)**

## Array Code

### Static Array:

- Declaration
```cpp
//initial an array with size 3
int arr[3];
//initial an array with size 3 but every element is 0
int arr[3]{};
//inintial an array with size 3 but every element is specific
int arr[3]={4,9,3};
```
- Traversal
```cpp
  int arr[3]={4,9,3};// declare
  for(int i=0;i<3;i++){
    cout<<arr[i]<<" ";   //output 4 9 3
  }
```
### Dynamic arrary

- Declaration
```cpp
//initial an array
vector<int>arr;
//initial an array with size 3
vector<int>arr(3);
//initial an array with size 3 but every element is 0
vector<int>arr(3,0);
//inintial an array with size 3 but every element is specific
vetctor<int>arr={4,9,3};
```
- Traversal + Insert and Erase element
```cpp
//initial an array
vector<int>arr;
//insert 7 at the end of array
arr.push_back(7); //arr={7};
//insert 5 at the begin of array arr={5,7};
arr.insert(arr.begin(),5);
//traversal
for(int i=0;i<arr.size();i++){
  cout<<arr[i]<<" ";  //output 5 7
}
//erase a element at the end of array  arr={5};
arr.pop_back();
//erase the first element arr={};
arr.erase(arr.begin());
