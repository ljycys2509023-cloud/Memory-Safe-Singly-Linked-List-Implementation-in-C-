# Singly Linked List Implementation in C++
## 📌 Project Overview
This project implements a **Singly Linked List** in C++, developed during my first year at XMUM. It focuses on building a solid understanding of: - **Pointer 
manipulation**: Managing links between nodes. - **Dynamic memory management**: Efficiently using heap memory. - **Fundamental data structure design**: Principles of 
linear data structures. *These concepts are essential for low-level programming, system architecture, and cybersecurity.* ---
## 🛠️ Core Features
- **Insert at Head** (`addhead`) — $O(1)$ - **Insert after Value** (`addNode`) — $O(n)$ - **Delete by Value** (`delNode`) — $O(n)$ - **Traversal**: Print the list to 
console. - **Memory Safety**: Automatic cleanup via custom destructor. ---

## 🔄 Project Update: From Data Structure to Application System

📌 Motivation
After completing the initial implementation of a singly linked list, I explored how fundamental data structures can be applied to real-world scenarios.

The hospital emergency department was chosen as a practical case study, where patient management requires both priority-based decision making and efficient queue 
handling. This led to the development of a hospital emergency triage and queue management system built on top of the original linked list structure.

This transition reflects a shift from academic exercise to application-oriented system design.
⸻

🚀 What’s New in This Update

This version extends the original linked list into a functional system:
	•	Introduced a Patient class to encapsulate structured data (ID, name, condition, priority level)
	•	Transformed the linked list into a priority-based queue (triage system)
	•	Implemented priority-aware insertion (enqueue) ensuring critical patients are served first
	•	Added dequeue operation to simulate patient service workflow
	•	Developed search functionality for locating patients by ID
	•	Enhanced output formatting using <iomanip> for clear and professional display
	•	Strengthened robustness with proper handling of edge cases (e.g., empty queue operations)

---

🧠 Design Insight

The system adopts a priority-based insertion strategy with a look-ahead approach (temp->next), ensuring:
	•	Correct ordering of patients based on urgency
	•	FIFO behavior for patients with equal priority
	•	Clean and maintainable pointer logic

---

🛠 System Evolution

	•	v1.0 — Basic singly linked list implementation
	•	v2.0 — Hospital emergency triage & queue management system

---

💡 Reflection

This update demonstrates how foundational data structures can evolve into meaningful applications. It also highlights the importance of:
	•	Designing for real-world constraints
	•	Writing maintainable and extensible code
	•	Bridging the gap between theory and practical systems

---

✅ Fulfilled Improvements

This update successfully implements several features that were previously outlined in the Future Improvements section of the initial linked li
	•	✔️ Search Functionality (searchByID)
→ Enables efficient lookup of patients within the queue system
	•	✔️ Application-Level Extension
→ The original linked list has been extended into a practical system (hospital triage queue), demonstrating real-world applicability
	•	✔️ Improved System Structure
→ Clear separation between data model (Patient), node structure, and queue logic (PatientQueue)

---

🔄 Updated Future Improvements

With the core system now functional, future development will focus on:
	•	🔹 Role-based access control (Doctor / Nurse interface)
	•	🔹 Input validation and interactive user interface
	•	🔹 Modular refactoring into header (.h) and implementation (.cpp) files
	•	🔹 Additional utility functions (e.g., reverse, statistics, or reporting features)


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

### 🛡 Robustness Enhancements (NEW)

	- Safe handling of empty queue operations (dequeue, display, peek) 
	- Graceful error messages instead of runtime crashes
	- Defensive programming against invalid state access

## ▶️ Example Output

Step 1 & 2: Initialize queue with 6 patients - Patients inserted based on priority (Critical > Moderate > Mild)
- Queue automatically sorted upon insertion

Step 3: Dequeue operation (x2) - Two highest-priority patients are served fir
- Queue dynamically updates after each removal

Step 4: Search operation
- Search by Patient ID (P003 → found, P999 → not found)

Step 5: Insert new critical patient
- New patient automatically placed at front due to highest priority

Step 6: Final queue state
- System shows updated priority-ordered queue

##How to Run
# Compile the source file
g++ Linked_List.cpp -o linked_list
# Execute the binary
./linked_list

##Future Improvement:
	•	Implement reverse() for the linked list
	•	Refactor into .h and .cpp files
	•	Add unit tests for robustness
