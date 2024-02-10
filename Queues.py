class Queues:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []

    def enqueue(self, element):
        self.stack1.append(element)

    def dequeue(self):
        if not self.stack2:
            if not self.stack1:
                return "Queue is empty"
            while self.stack1:
                self.stack2.append(self.stack1.pop())
        return self.stack2.pop()

if __name__ == "__main__":
    queues = Queues()
    queues.enqueue(5)
    queues.enqueue(4)
    queues.enqueue(3)
    queues.enqueue(2)
    queues.enqueue(1)
    print(queues.dequeue())