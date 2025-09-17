class Job:
    def __init__(self, id, deadline, profit):
        self.id = id
        self.deadline = deadline
        self.profit = profit

def jobScheduling(jobs, n):
    jobs.sort(key=lambda x: x.profit, reverse=True)
    max_deadline = max(job.deadline for job in jobs)
    slots = [-1] * (max_deadline + 1)
    count, total_profit = 0, 0
    for job in jobs:
        for j in range(job.deadline, 0, -1):
            if slots[j] == -1:
                slots[j] = job.id
                count += 1
                total_profit += job.profit
                break
    return count, total_profit
