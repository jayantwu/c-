import subprocess
import sys
def race_conditon_check(file):
    l = []
    d = {"miss": [], "dup": []}
    with open(file, 'r') as f:
        for line in f:
            if "front: " in line:
                l.append(line[7:-1])

    # check miss 
    rslt_set = set(l)
    for i in range(10000):
        if str(i) not in rslt_set:
            #print("miss: " + str(i))
            d["miss"].append(str(i))


    # check duplicate
    s = set()
    for i in l:
        if i not in s:
            s.add(i)
        else:
            #print("dup: "+i)
            d["dup"].append(i)
    print("check done!")
    return d
    

def execute(filename):
    process = subprocess.Popen(f"./a.out > {filename}", shell=True)
    process.communicate()
    print("execute done!")

if __name__ == '__main__':
    filename = "4.txt"
    d = {"miss": [], "dup": []}
    while len(d["miss"]) == 0 and len(d["dup"]) == 0:
        execute(filename)
        d = race_conditon_check(filename)
    
    print("miss: ", end='')
    for i in d["miss"]:
        print(i, end=' ')
    print()
    print("dup: ", end='')
    for i in d["dup"]:
        print(i, end=' ')
    print()