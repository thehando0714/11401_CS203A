
This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

- Developer: Cheng-Jun Hu 
- Email: chrishu0714@gmail.com

## My Hash Function
### Integer Keys 
- Formula / pseudocode:
  ```cpp
  int myHashInt(int key, int m) {
    
    //key*=13;
    unsigned int k=key;
    k*=987654361;
    return k % m;  
  }
  ```
- Rationale: At the beginning I guess key multiple a prime number can decrease collision,but 13 is too small,if key is a multiple by 13 or m(hash table size) ,hash value will be 0,that is too often to get collision,so I change 13 to 987654361 a bigger prime number,because of bigger prime number,collison will be harder to happen.I use unsigned int because multiple by 987654361 is too easy to overflow,unsigned int can prevent from k become a minus number.

### Non-integer Keys
- Formula / pseudocode:
  ```cpp
  int myHashString(const std::string& str, int m) {
    unsigned long hash = 0;
    //hash=str[0]-'a';
    for(int i=0;i<str.size();i++){
        hash+=str[i]-'a';
    }
    
    return static_cast<int>(hash % m);  // basic division method
  }
  ```
- Rationale: At first I only want to caculate the word's first letter minus 'a' to get a number,but I realized it is too easy to collision and if my table size is 37 I can't even have hash value more than 25,so I caculate not even first letter,but also every letter of word,hash could be more bigger and more unique.

## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C23 and C++23

## Results
<img width="281" height="580" alt="image" src="https://github.com/user-attachments/assets/4e43b441-98b8-40f3-91b4-3f23d6003695" />
<img width="303" height="298" alt="image" src="https://github.com/user-attachments/assets/070a1f40-0099-4d80-a0d2-8f34c5d395c8" />

| Table Size (m) | Index Sequence            | Observation              |
|----------------|---------------------------|--------------------------|
| 10             | 1,3,0,8,2,7,9,4,9,2       | Very unique              |
| 11             | 10,1,9,5,10,3,9,2,7,9     | Very unique              |
| 37             | 21,23,20,1,32,10,9,24,29,5| Very unique              |

## Compilation, Build, Execution, and Output

### Compilation
- The project uses a comprehensive task.json that builds both C and C++ versions with proper flags:
  ```bash
  {
    "version": "2.0.0",
    "tasks": [
        {
            // === 任務 1: 給 C 語言用 (gcc + *.c) ===
            "type": "cppbuild",
            "label": "Build C Project",
            "command": "C:\\mingw64\\bin\\gcc.exe",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "${fileDirname}/*.c",       // 這裡抓 .c 檔
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": ["$gcc"],
            "group": {
                "kind": "build",
                "isDefault": false           // 目前預設用這個 
            },
            "detail": "編譯當前資料夾下的所有 .c 檔案"
        },
        {
            // === 任務 2: 給 C++ 語言用 (g++ + *.cpp) ===
            "type": "cppbuild",
            "label": "Build C++ Project",
            "command": "C:\\mingw64\\bin\\g++.exe",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "${fileDirname}/*.cpp",     // 這裡抓 .cpp 檔
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": ["$gcc"],
            "group": {
                "kind": "build",
                "isDefault": true        // 平常不用，需要時手動選
            },
            "detail": "編譯當前資料夾下的所有 .cpp 檔案"
        }
    ]
  }
  ```
  if you want to compile .cpp isDefault should be true like img<img width="525" height="215" alt="image" src="https://github.com/user-attachments/assets/6552c9ee-9d02-46f5-a9cc-53bc9c3c86e1" />
  and isDefault should be false like img<img width="680" height="241" alt="image" src="https://github.com/user-attachments/assets/231ca7e1-ba92-444f-b33d-687449b6d687" />
if you want to compile .c just switch true and false.
  


### Manual Compilation (if needed)
- Command for C or C++:
- press ctrl+shift+b  you will get a main.exe
### Clean Build Files
- Remove all compiled files:
  ```bash
  rm main.exe
  ```

### Execution
- Run the compiled binary:
  ```bash
  ./main.exe
  ```

### Result Snapshot

<img width="253" height="494" alt="image" src="https://github.com/user-attachments/assets/708a1eeb-7757-43d2-b8ab-5e2d5b207794" />
<img width="301" height="501" alt="image" src="https://github.com/user-attachments/assets/d8320c2b-c9cd-4d8b-9a56-632f2f9b0b9f" />
<img width="324" height="494" alt="image" src="https://github.com/user-attachments/assets/ce20a2cf-fc84-4356-83a3-40bd7986904e" />

  
<img width="281" height="580" alt="image" src="https://github.com/user-attachments/assets/4e43b441-98b8-40f3-91b4-3f23d6003695" />
<img width="303" height="298" alt="image" src="https://github.com/user-attachments/assets/070a1f40-0099-4d80-a0d2-8f34c5d395c8" />


- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.
- output for integers:
  ```
  Hash table (m=10): [7, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 9, 0, 1, 2]
  Hash table (m=11): [5, 2, 3, 4, 5, 6, 3, 4, 5, 6, 7, 8, 5, 6, 7, 8, 5, 6, 7, 8]
  Hash table (m=37): [19, 16, 20, 24, 28, 32, 29, 33, 0, 4, 16, 20, 17, 21, 25, 29, 26, 30, 34, 1]
  ```
- output for strings:
  ```
  Hash table (m=10): [1, 3, 0, 8, 2, 7, 9, 4, 9, 2]
  Hash table (m=11): [10, 1, 9, 5,10, 3, 9, 2, 7, 9]
  Hash table (m=37): [1, 23, 20, 1, 32, 10, 9, 2, 7, 9]
  ```
- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.

## Analysis
- Prime vs non-prime `m`: Prime table sizes generally result in better distribution and fewer collisions.
- Patterns or collisions: Non-prime table sizes tend to produce repetitive patterns, leading to more collisions.
- Improvements: Use a prime table size and a well-designed hash function to enhance distribution.

## Reflection
1. Designing hash functions requires balancing simplicity and effectiveness to minimize collisions.
2. Table size significantly impacts the uniformity of the hash distribution, with prime sizes performing better.
3. The design using a prime table size and a linear transformation formula produced the most uniform index sequence.

