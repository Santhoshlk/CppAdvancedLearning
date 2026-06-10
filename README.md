🧠 CppAdvancedLearning
A structured 6-week C++ deep-dive into memory, ownership, and modern C++ — built for game development.
This is not a tutorial-follow repo. Every file here is code written from scratch after
studying a concept, as part of a strict learn → explain → code solo → commit protocol.
No generated code, no copy-paste — the commits are the proof of understanding.

⚙️ The Block
A 6-week intensive focused on the C++ that actually matters for gameplay programming:
memory, object lifetime, ownership, and (upcoming) concurrency.
Primary spine:

📕 Effective Modern C++ — Scott Meyers (mapped week by week)
📗 A Tour of C++ — Bjarne Stroustrup (reference/lookup)
📘 C++ Concurrency in Action — Anthony Williams (concurrency weeks)
🎥 The Cherno C++ series

Tooling:

Visual Studio 2026 · Cppcheck static analysis wired into the IDE · AddressSanitizer
Every exercise passes static analysis before commit


🗺️ Progress
✅ Week 1 — Object Lifecycle & Fundamentals
Object lifetime in and beyond scope, new keyword, implicit/explicit conversions,
casting, const / mutable, member initializer lists, stack vs heap, this,
templates, auto.
StackVsHeap.cpp · CEInitiate.cpp · CENewKeyword.cpp · Casting.cpp ·
ImplicitExplicit.cpp · MemberInitList.cpp · this.cpp · templates.cpp ·
Auto.cpp · MiniProject1.cpp
✅ Week 2 — Copy Semantics & Move Semantics
Copy constructors, deep vs shallow copies, the Rule of Five, move semantics,
arrow operator, STL vector internals and optimization.
Copy.cpp · CopyConstructor.cpp · CopyingSandbox.cpp · Arrow.cpp ·
VectorSTL.cpp · Optimize Dynamic Vector.cpp · PlayerClass.cpp ·
LinearAllocation.cpp
🔄 Week 3 — Smart Pointers & Memory Layout (in progress)
unique_ptr, shared_ptr, weak_ptr — ownership as a destructor question.
Memory layout, AoS vs SoA ahead.
SmartPointers.cpp · Unique1.cpp · SmartPointerMiniProject-1.cpp
⏳ Weeks 4–6 — Concurrency
Threads, synchronization, atomics, lock-free thinking — via
C++ Concurrency in Action.

🎯 The Method

Study the concept (book chapter + video)
Explain it back in my own words until it holds up under questioning
Code solo — cumulative challenges that integrate every prior concept,
including deliberate cases where a tool is not needed (judgment over habit)
Analyze — Cppcheck clean before commit
Commit — daily, no gaps

Challenges are game-flavored (player classes, combat encounters, inventory-style
ownership problems) because this block exists to feed directly into Unreal Engine
C++ work.

🔗 Related Work

⚔️ CombatLearning — flagship UE5 GAS
Action RPG, 400+ commits
🕯️ AshesBeyondTheGrave —
UE5 C++ foundation project


📫 Connect
📧 lukksanthosh@gmail.com
