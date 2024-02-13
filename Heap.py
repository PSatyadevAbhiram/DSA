import heapq

class MinHeap:
    def __init__(self):
        self.heap = []

    def push(self, val):
        heapq.heappush(self.heap, val)

    def pop(self):
        return heapq.heappop(self.heap)

    def peek(self):
        return self.heap[0] if self.heap else None

class MaxHeap:
    def __init__(self):
        self.heap = []

    def push(self, val):
        heapq.heappush(self.heap, -val)

    def pop(self):
        return -heapq.heappop(self.heap)

    def peek(self):
        return -self.heap[0] if self.heap else None

# Example usage:
min_heap = MinHeap()
max_heap = MaxHeap()

# Adding elements to min heap
min_heap.push(5)
min_heap.push(2)
min_heap.push(10)

print("Min heap:")
print(min_heap.pop())  # Output: 2
print(min_heap.pop())  # Output: 5
print(min_heap.pop())  # Output: 10

# Adding elements to max heap
max_heap.push(5)
max_heap.push(2)
max_heap.push(10)

print("Max heap:")
print(max_heap.pop())  # Output: 10
print(max_heap.pop())  # Output: 5
print(max_heap.pop())  # Output: 2
