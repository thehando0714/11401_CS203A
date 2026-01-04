
# Description
### Stack
- Stack is a data structure designed to operate **LIFO(last in first out)** context,element can only insert and acess element and erase at the end of stack
### Queue
- Queue is a data structure designed to operate **FIFO(first in first out)** context,element can only insert at the end of queue,but erase and acess element at the begining of queue 


## Abstract Data Type
### Stack
- Acess element at the end of stack,⏲️time Complexity:**O(1)**
- Erase element at the end of stack,⏲️time Complexity:**O(1)**
- Insert an element at the end of stack,⏲️time Complexity:**O(1)**
### Queue
- Acess element at the begining of queue,⏲️time Complexity:**O(1)**
- Erase element at the begining of queue,⏲️time Complexity:**O(1)**
- Insert an element at the end of queue,⏲️time Complexity:**O(1)**
## Stack Code

- Basic operation
```cpp
// declare a stack that is empty
stack<int>st;
//insert a element at the end of stack
st.push(7);// st={7}
//acess element at the end of stack
cout<<st.top();// output 7
//insert a element at the end of stack
st.push(5);// st={7,5}
//acess element at the end of stack
cout<<st.top();// output 5
//erase element at the end of stack
st.pop();//st={7}
```
## Queue Code

- Basic operation
```cpp
// declare a queue that is empty
queue<int>qu;
//insert a element at the end of queue
qu.push(7);// qu={7}
//acess element at the begining of queue
cout<<qu.front();// output 7
//insert a element at the end of queue
qu.push(5);// qu={7,5}
//acess element at the begining of queue
cout<<qu.front();// output 7
//erase element at the begining of queue
qu.pop();//st={5}
```
## Leetcode Pratice 
- for stack
  1. 2390.Removing
  2. 735.Asteroid Collision
  3. 394.Decode String
- for queue
  1. 1926.Nearest Exit from Entrance in Maze
  2. 994.Rotting Oranges
