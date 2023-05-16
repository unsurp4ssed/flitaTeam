from random import randint
import subprocess
OutFileHeap = open("outHeapsort.txt", "w")
OutFileBubble = open("outBubblesort.txt", "w")
timeList = []

testsAmount = 10
n = 1
while n <= 100001:
    print(str(n-1)+"... Done")
    avgTime = 0
    k = 0
    for i in range(1, testsAmount):
        numList = []
        for i in range(n): numList.append(randint(-2147483646,  2147483646))
        DataFile = open('data.txt', 'w')
        for element in numList:
            DataFile.write(str(element))
            DataFile.write('\n')
        DataFile.close()

        p = subprocess.run(["heap", str(n)], capture_output=True, text=True)
        avgTime += p.returncode
    
    avgTime = round(avgTime/testsAmount)
    timeList.append(avgTime)
    OutFileHeap.write(str(n)); OutFileHeap.write(' '); OutFileHeap.write(str(avgTime))
    OutFileHeap.write('\n')
    n+=500
OutFileHeap.close()

timeList = []

n = 1
while n <= 100001:
    print(str(n-1)+"... Done")
    avgTime = 0
    k = 0
    for i in range(1, testsAmount):
        numList = []
        for i in range(n): numList.append(randint(-2147483646,  2147483646))
        DataFile = open('data.txt', 'w')
        for element in numList:
            DataFile.write(str(element))
            DataFile.write('\n')
        DataFile.close()

        p = subprocess.run(["bubble", str(n)], capture_output=True, text=True)
        avgTime += p.returncode
    
    avgTime = round(avgTime/testsAmount)
    timeList.append(avgTime)
    OutFileBubble.write(str(n)); OutFileBubble.write(' '); OutFileBubble.write(str(avgTime))
    OutFileBubble.write('\n')
    n+=500
OutFileBubble.close()