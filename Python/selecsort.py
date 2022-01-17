#Benefit: Lower swap cost useful if write memory is expensive
# O(n^2) sadly as there r two nested loop
#Selection Sort
#John Parkhurst

def selectsort(arr) -> []:
    """
    :param arr: An integer/float array to sort using selection sort
    :return: an int/float array that is sorted!
    """
    for x in range(len(arr)):
        #This is the minimum index so for example at index 0 we check the rest and find the smallest one then swap
        min = x
        for y in range(x,len(arr)):
            if(arr[min]>arr[y]):
                min=y
        #We swap right here
        temp = arr[x]
        arr[x]=arr[min]
        arr[min]=temp
    return arr
#THIS IS log(n) complexity with sorted list
def binarysearch(arr:list,target:int,r:int)->int:
    ind = -1
    l = 0
    arr = sorted(arr)
    while l<=r:
        mid = l + (r - l) // 2
        if(arr[mid] == target):
            return mid
        elif(arr[mid]>target):
            r = mid -1
        elif(arr[mid]<target):
            l = mid + 1



if __name__ == "__main__":
    print("Pre Sorted Array:")
    mylis = [6, 3, 1, 8, 4, 2, 6, 3, 88, 9, 0]
    print(mylis)
    mylis = selectsort(mylis)
    myind = binarysearch(mylis,3,len(mylis))
    print(mylis)
    print(myind)