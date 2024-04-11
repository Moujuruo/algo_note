/*
 * @lc app=leetcode.cn id=232 lang=rust
 * @lcpr version=30117
 *
 * [232] 用栈实现队列
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
use std::collections::VecQueue;
struct MyQueue {
    q1: VecQueue<i32>,
    q2: VecQueue<i32>,
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyQueue {

    fn new() -> Self {
        MyQueue {
            q1: VecQueue::new(),
            q2: VecQueue::new(),
        }
    }
    
    fn push(&mut self, x: i32) {
        self.q1.push_back(x);
    }
    
    fn pop(&mut self) -> i32 {
        if !self.q2.is_empty() {
            return self.q2.pop_front().unwrap();
        }
        while !self.q1.is_empty() {
            self.q2.push_back(self.q1.pop_front().unwrap());
        }
        self.q2.pop_front().unwrap()
    }
    
    fn peek(&self) -> i32 {
        if !self.q2.is_empty() {
            return *self.q2.front().unwrap();
        }
        while !self.q1.is_empty() {
            self.q2.push_back(self.q1.pop_front().unwrap());
        }
        *self.q2.front().unwrap()
    }
    
    fn empty(&self) -> bool {
        self.q1.is_empty() && self.q2.is_empty()

    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * let obj = MyQueue::new();
 * obj.push(x);
 * let ret_2: i32 = obj.pop();
 * let ret_3: i32 = obj.peek();
 * let ret_4: bool = obj.empty();
 */
// @lc code=end



/*
// @lcpr case=start
// ["MyQueue", "push", "push", "peek", "pop", "empty"][[], [1], [2], [], [], []]\n
// @lcpr case=end

 */

