# Empty vs Single Element in a Doubly Linked List Queue

## Aim
To investigate and solve the problem of differentiating an empty queue and a queue that contains one element in a doubly linked list following the enqueue and dequeue implementation.

## Group Research
This project is a group research assignment completed by:

- Busisiwe Tyhokolo – 202416885
- Siyambulela Williams – 202502154
- Nombulelo Angela Nkambule – 202402946
- Unathi Spele – 202517137
- Phathutshedzo Michelle Mahada – 202524881

## Problem Statement
When implementing a queue using a doubly linked list, the empty state and the single-element state can be difficult to distinguish. In an empty queue, both `Front` and `Rear` should be `NULL`. In a one-element queue, `Front` and `Rear` point to the same node, and neither is `NULL`. Because `Front == Rear` can be true in both states, using only that condition is not enough.

## Four Differentiation Techniques
All four techniques below were researched by the group and implemented in the submitted C++ source file, `#include iostream.txt`. The file contains valid C++ code and can be renamed to `main.cpp` for compilation.

### 1. Null-Pointer Check
This technique checks whether the front pointer is `NULL`.

```cpp
bool isEmpty() {
    return Front == NULL;
}
```

### 2. Size counter

```cpp
int queueSize = 0;
```

### 3. Dummy/Sentinel Node

```cpp
bool isEmptyUsingSentinel() {
    return Header->next == Trailer;
}
```
### 4. Next-Pointer and Front/Rear Check
```cpp
bool isSingle() {
    return Front == Rear && Front != NULL;
}
```
```cpp
bool isSingleUsingLinks() {
    return Header->next != Trailer
        && Header->next->next == Trailer
        && Trailer->prev == Header->next;
}
```
