# Stack Distance Analyzer

A simple C project to visualize **temporal locality** of memory accesses using the **stack distance** method. It helps evaluate how well a program exhibits locality, a key factor in memory performance.

## 📁 Files

| File Name               | Description |
|------------------------|-------------|
| `stack_distance_tool.h`| Header file defining stack size and histogram bins |
| `stack_distance_tool.c`| Implements stack distance tracking and histogram printing |
| `main_test_runner.c`   | Reads a fixed access sequence and prints the histogram |
| `generate_sequence.c`  | Generates a synthetic address access pattern with localities |

---

## 🛠️ Build Instructions

Compile with `gcc`:

```bash
# Compile main analysis tool
gcc -o analyze main_test_runner.c stack_distance_tool.c

# Compile synthetic trace generator
gcc -o generate generate_sequence.c
```

---

## ▶️ Usage

### 1. Generate Address Trace

```bash
./generate
```

This will output a C array of 100 memory addresses simulating local and remote accesses.

### 2. Analyze Stack Distance

Paste the generated array into `main_test_runner.c` → `addresses[]`, then run:

```bash
./analyze
```

You will see output like:

```
=== 栈距离分布柱状图（时间局部性） ===
距离  0:   10 | **********
距离  1:    6 | ******
距离  2:    4 | ****
...
距离 19:    0 |
```

This histogram shows how many times each stack distance occurred — smaller distances imply higher temporal locality.

---

## 📖 Concept Overview

### ✅ What is Stack Distance?

Stack distance is the number of unique addresses accessed between two references to the same address.

- **Low stack distance** = recent reuse ⇒ **high temporal locality**
- **High stack distance** = poor reuse ⇒ **low locality**

### 🧪 What it tells you

- A program with many accesses in distance 0–10 likely performs well with small caches.
- You can visually identify locality by observing how “left-heavy” the histogram is.

---

## 📌 Example Use Cases

- Evaluate how loop-structured programs exhibit locality
- Design better caching policies
- Teach memory performance concepts in architecture courses

---

## 📦 License

MIT License.

---

## ✍️ Author

Built for learning and analysis of temporal locality.

Feel free to fork and extend for file input, multiple program traces, or real-world benchmarks!
