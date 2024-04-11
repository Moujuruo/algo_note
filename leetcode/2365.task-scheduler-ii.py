# @lcpr-before-debug-begin
from python3problem2365 import *
from typing import *
# @lcpr-before-debug-end

#
# @lc app=leetcode.cn id=2365 lang=python3
# @lcpr version=30119
#
# [2365] 任务调度器 II
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
from collections import defaultdict


class Solution:
    def taskSchedulerII(self, tasks: List[int], space: int) -> int:
        n = len(tasks)
        last_exec_time = {}  
        
        t = 0  # 任务指针
        i = 1  # 时间指针
        
        while t < n:
            cur = tasks[t]
            if cur not in last_exec_time or i - last_exec_time[cur] > space:
                last_exec_time[cur] = i
                t += 1
                i += 1
            else:
                e = last_exec_time[cur] + space - i + 1
                i += e

        return i - 1
            
        

            

                



# @lc code=end


# @lcpr-div-debug-arg-start
# funName=taskSchedulerII
# paramTypes= ["number[]","number"]
# @lcpr-div-debug-arg-end




#
# @lcpr case=start
# [1,2,1,2,3,1]\n3\n
# @lcpr case=end

# @lcpr case=start
# [5,8,8,5]\n2\n
# @lcpr case=end

#

