/*
 * @lc app=leetcode.cn id=225 lang=rust
 * @lcpr version=30117
 *
 * [225] 用队列实现栈
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
struct MyStack {
    q: VecDeque<i32>,
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyStack {

    fn new() -> Self {
        MyStack {
            q: VecDeque::new(),
        }
    }
    
    fn push(&self, x: i32) {
        let q = &mut self.q;
        q.push_back(x);
    }
    
    fn pop(&self) -> i32 {
        let q = &mut self.q;
        let mut size = q.len();
        size -= 1;
        while size > 0 {
            let x = q.pop_front().unwrap();
            q.push_back(x);
            size -= 1;
        }
        q.pop_front().unwrap()
    }
    
    fn top(&self) -> i32 {
        let q = &mut self.q;
        return *q.back().unwrap();
    }
    
    fn empty(&self) -> bool {
        let q = &mut self.q;
        q.is_empty()

    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * let obj = MyStack::new();
 * obj.push(x);
 * let ret_2: i32 = obj.pop();
 * let ret_3: i32 = obj.top();
 * let ret_4: bool = obj.empty();
 */
// @lc code=end



/*
// @lcpr case=start
// ["MyStack", "push", "push", "top", "pop", "empty"][[], [1], [2], [], [], []]\n
// @lcpr case=end

 */

