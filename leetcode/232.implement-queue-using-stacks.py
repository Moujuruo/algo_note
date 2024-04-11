#
# @lc app=leetcode.cn id=232 lang=python3
# @lcpr version=30117
#
# [232] 用栈实现队列
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start

class Stack:
    def __init__(self):
        self.stack = []

    def push(self, x: int) -> None:
        self.stack.append(x)

    def pop(self) -> int:
        return self.stack.pop()

    def peek(self) -> int:
        return self.stack[-1]

    def empty(self) -> bool:
        return len(self.stack) == 0


class MyQueue:

    def __init__(self):
        self.q1 = Stack()
        self.q2 = Stack()


    def push(self, x: int) -> None:
        self.q1.push(x)


    def pop(self) -> int:
        if self.q2.empty():
            while not self.q1.empty():
                self.q2.push(self.q1.pop())
        return self.q2.pop()



    def peek(self) -> int:
        if self.q2.empty():
            while not self.q1.empty():
                self.q2.push(self.q1.pop())
        return self.q2.peek()


    def empty(self) -> bool:
        return self.q1.empty() and self.q2.empty()



# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
# @lc code=end



#
# @lcpr case=start
# ["MyQueue", "push", "push", "peek", "pop", "empty"][[], [1], [2], [], [], []]\n
# @lcpr case=end

#

