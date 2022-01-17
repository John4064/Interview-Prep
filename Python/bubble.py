# Bubble Sort
#John Parkhurst
def swap(a,b):
    """
    :param a: element to be swapped with b
    :param b: element that is being swapped with a
    :return:
    """
    temp = a
    a=b
    b=temp
    return a,b
def bubblesort(arr) -> []:
    """
    :param arr: An integer/float array that is to be sorted by a bubble sort
    :return:  returns a sorted array that has been sorted by a bubble sort
    """
    for x in range(1,len(arr)):
        y = x
        while arr[x-1] >= arr[y] and y+1 != len(arr):
            arr[x-1],arr[x]=swap(arr[x-1],arr[y])
            y +=1
    return arr


if __name__ == "__main__":
    print("Pre Sorted Array:")
    mylis = [6, 3, 1, 8, 4, 2, 6, 34, 88, 9,4]
    print(mylis)
    mylis=bubblesort(mylis)
    print(mylis)
