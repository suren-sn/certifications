#python3

def countClimbsDFS(n, strides, cache=False):
    if not cache: cache={}
    if n in cache: return cache[n]
    if n<0: return 0
    if n==0: return 1

    return sum(countClimbsDFS(n-s, strides, cache) for s in strides)

def countClimbsIter(n, strides):
    count = [0] * (n+1)
    count[0] = 1

    for stepsToClimb in range(1, n+1):
        for s in strides:
            if (stepsToClimb-s) >= 0:
                count[stepsToClimb] += count[stepsToClimb - s]
    return count[n]

def countClimbsWrap(n, strides, expected):
    #r = countClimbsDFS(n, strides)
    r = countClimbsIter(n, strides)

    print(f"expected={expected} result={r}")

if __name__ == '__main__':
    r = countClimbsWrap(1, [1,2], 1)
    r = countClimbsWrap(2, [1,2], 2)
    r = countClimbsWrap(3, [1,2], 3)
    r = countClimbsWrap(10, [1,2,3], 274)
