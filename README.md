# Singly Linked List Implementation in C++
## 📌 Project Overview
This project implements a **Singly Linked List** in C++, developed during my first year at XMUM. It focuses on building a solid understanding of: - **Pointer 
manipulation**: Managing links between nodes. - **Dynamic memory management**: Efficiently using heap memory. - **Fundamental data structure design**: Principles of 
linear data structures. *These concepts are essential for low-level programming, system architecture, and cybersecurity.* ---
## 🛠️ Core Features
- **Insert at Head** (`addhead`) — $O(1)$ - **Insert after Value** (`addNode`) — $O(n)$ - **Delete by Value** (`delNode`) — $O(n)$ - **Traversal**: Print the list to 
console. - **Memory Safety**: Automatic cleanup via custom destructor. ---
## ⚙️ Complexity Analysis
| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| `addhead` | $O(1)$ | $O(1)$ | `addNode` | $O(n)$ | $O(1)$ | `delNode` | $O(n)$ | $O(1)$ | `printlist`| $O(n)$ | $O(1)$ |
---
## 🧠 Memory Safety & Implementation Highlights
This project emphasizes safe and correct memory handling: - **Explicit Dynamic Allocation**: Uses `new` and `delete` to manually manage heap memory. - **Destructor for 
Full Cleanup**: All nodes are properly deallocated when the list object is destroyed, ensuring zero memory leaks. - **Dangling Pointer Prevention**: Careful re-assignment 
of pointers during deletion to avoid unsafe memory access. - **Edge Case Handling**:
  - Empty list verification.
  - Head node removal.
  - Safe traversal with `nullptr` termination. ---
## ▶️ Example Output
```text 50->40->30->20->10->NULL 50->40->20->10->NULL
100->50->300->40->20->10->NULL

---

##How to Run
# Compile the source file
g++ Linked_List.cpp -o linked_list
# Execute the binary
./linked_list

##Future Improvements
	•	Add search() and size() functions
	•	Implement reverse() for the linked list
	•	Refactor into .h and .cpp files
	•	Add unit tests for robustness
