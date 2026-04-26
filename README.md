# Singly Linked List Implementation in C++
## 📌 Project Overview
This project implements a **Singly Linked List** in C++, developed during my first year at XMUM. It focuses on building a solid understanding of: 
- **Pointer manipulation**: Managing links between nodes. 
- **Dynamic memory management**: Efficiently using heap memory.
- **Fundamental data structure design**: Principles of linear data structures. *These concepts are essential for low-level programming, system architecture, and cybersecurity.* 
---
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
	Dual-Role Workflow & RBAC 👥---Implemented a secure authentication layer that bifurcates system access into Doctor and Nurse workstations.
	Advanced Patient Profiling 📊---Enhanced data objects to include Clinical Conditions and Age, allowing for a more holistic triage process.
	Defensive Input Handling 🛡️---Integrated buffer management (cin.clear()/cin.ignore()) to protect the system from malformed user input and logical deadlocks.

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
	•	v3.0 — Security Governance & Role-Based Access Update

---

💡 Reflection

This update demonstrates how foundational data structures can evolve into meaningful applications. It also highlights the importance of:
	•	Designing for real-world constraints
	•	Writing maintainable and extensible code
	•	Bridging the gap between theory and practical systems

---

✅ Fulfilled Improvements

This update successfully implements several features that were previously outlined in the Future Improvements section of the nnitial lined list
	•	✔️ Search Functionality (searchByID)
→ Enables efficient lookup of patients within the queue system
	•	✔️ Application-Level Extension
→ The original linked list has been extended into a practical system (hospital triage queue), demonstrating real-world applicability
	•	✔️ Improved System Structure
→ Clear separation between data model (Patient), node structure, and queue logic (PatientQueue)
	•       ✔  Defensive Input Validation
→ Leveraged cin.clear() and cin.ignore() to neutralize buffer redundancy. This shields the system from potential logic hangs caused by malformed user telemetry.

---

🔄 Updated Future Improvements

With the core system now functional, future development will focus on:
	•       🔐 Cryptographic Identity: Transitioning from plaintext checks to DJB2 One-Way Hashing for credential protection.
	•       💾 Persistence: Implementing serialized file I/O to maintain medical logs across sessions.
	•	🔹 Modular refactoring into header (.h) and implementation (.cpp) files
	•	🔹 Additional utility functions (e.g., reverse, statistics, or reporting features)


## ⚙️ Complexity Analysis

| Operation | Time Complexity | Space Complexity | Logical Context |
| :--- | :--- | :--- | :--- |
| `enqueue` | $O(n)$ | $O(1)$ | Maintains priority order during Nurse registration. |
| `dequeue` | $O(1)$ | $O(1)$ | Immediate patient retrieval for Doctor treatment. |
| `searchByID` | $O(n)$ | $O(1)$ | Linear traversal to retrieve specific records. |
| `displayQueue`| $O(n)$ | $O(1)$ | Full system state visualization. |
| `Cleanup/Exit`| $O(n)$ | $O(1)$ | Recursive deallocation of all heap nodes. |

--- 
## 🧠 System Safety, Security & Implementation Highlights🛡️ This project emphasizes safe and correct memory handling:
 - **Role-Based Access Control (RBAC**: Implemented a bifurcated interface for Doctors and Nurses. By segregating functional logic, the system ensures the Principle of Least Privilege (PoLP).
 - **Action Isolation**: Destructive operations (e.g., patient discharge via dequeue) are restricted to the Doctor’s workstation, preventing unauthorized data removal by triage staff.
 - **Explicit Dynamic Allocation**: Uses `new` and `delete` to manually manage heap memory. 
 - **Destructor for Full Cleanup**: All nodes are properly deallocated when the list object is destroyed, ensuring zero memory leaks. Guarantees 100% heap deallocation even during multi-role session switching.
 - **Dangling Pointer Prevention**: Careful re-assignment of pointers during deletion to avoid unsafe memory access.
 - **Edge Case Handling**:
  - Empty list verification.
  - Head node removal.
  - Safe traversal with `nullptr` termination. ---

### 🛡 Robustness Enhancements (NEW)
	• Input Sanitization: Integrated cin.clear() and cin.ignore() to neutralize buffer redundancy. This defensive layer shields the system from logic hangs or infinite loops caused by malformed user input. 
	• Secure Termination: Added a dedicated exit protocol that triggers the class destructor, ensuring a Graceful Shutdown rather than an abrupt process kill.
	- Safe handling of empty queue operations (dequeue, display, peek) 
	- Graceful error messages instead of runtime crashes
	- Defensive programming against invalid state access

## ▶️ Example Output

1. Multi-Role Authentication Layer
When the system starts, it requires role identification to enforce the Principle of Least Privilege:
#################### SYSTEM LOGIN ####################
Enter role (doctor/nurse) or 'exit' to shut down: nurse
 -------------------- NURSE WORKSTATION -------------------- 
1. Display All Waiting Patients 
2. Register New Patient Entry 
3. Search Patient by ID 
4. Logout
Selection: 1

2. Enhanced Live Hospital Queue (High-Fidelity UI) 
The output now features optimized spacing and includes clinical notes for better triage visibility:
============================== LIVE HOSPITAL QUEUE ==============================
Pos   Patient Name      ID          Condition                Status
--------------------------------------------------------------------------------
No.1  Wong              P004        Head Injury              [CRITICAL]
No.2  Ahmad             P001        Heart Attack             [CRITICAL]
No.3  John              P003        Severe Asthma            [MODERATE]
No.4  Zali              P005        Abdominal Pain           [MODERATE]
No.5  Siti              P002        Common Cold              [MILD]
No.6  Tan               P006        Skin Rash                [MILD]
================================================================================

3. Doctor's Clinical In
terface Switching to the doctor role reveals administrative privileges such as treatment and priority previews:
#################### SYSTEM LOGIN ####################
Enter role (doctor/nurse) or 'exit' to shut down: doctor 

++++++++++++++++++++ DOCTOR INTERFACE ++++++++++++++++++++ 
1. Treat Next Patient 
2. Preview Next in Line 
3. View Full Queue 
4. Logout
Selection: 1

******************** CALLING PATIENT ********************
Patient ID : P004 
Name : Wong Age : 12 
Clinical Note : Head Injury
 Priority Status : CRITICAL (Immediate Attention)

## 🚀 How to Run
### 1. Prerequisites
Ensure you have a C++ compiler installed (e.g., `g++` for Linux/macOS or `MinGW` for Windows).
### 2. Compile the Source File
Use the following command to compile the triage system: ```bash g++ PatientQueue.cpp -o hospital_system
### 3. Execute the Binary
Run the compiled program to enter the secure login interface
: ./hospital_system
### 4. System Usage Guide
�� Login: Enter doctor or nurse to access specific workstations. 
�� Navigation: Follow the on-screen numerical menus to perform operations. 
�� Termination: Type exit in the main login screen to trigger the Secure Exit Protocol and clear memory.

📈 v3.0 Evolution Sumary
• Fulfilled: ✅ Role-based Access Control (RBAC) | ✅ Clinical Condition Tracking | ✅ Defensive Input Handling.
• Future Roadmap: 🔐 Implementing DJB2 Password Hashing for cryptographic security | 💾 Adding File I/O Persistence for patient records.


