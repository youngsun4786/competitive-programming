from sys import stdin

def area_triangle(a, b, c):

    temp = abs(a[0] * (b[1] - c[1]) + b[0] * (c[1] - a[1]) + c[0] * (a[1] - b[1]))
    return temp/2


def main(): 
    v1 = [int(i) for i in list(input().strip().split())]
    v2 = [int(i) for i in list(input().strip().split())]
    v3 = [int(i) for i in list(input().strip().split())]

    area = area_triangle(v1, v2, v3)

    n = int(stdin.readline())
    numTrees = 0

    for _ in range(n):
       point = [int(x) for x in stdin.readline().split()]
       summation = area_triangle(v1, point, v3) + area_triangle(v1, v2, point) + area_triangle(point, v2, v3)
       if area == summation:
           numTrees += 1

    print(area)
    print(numTrees)

if __name__ == "__main__":
    main()   