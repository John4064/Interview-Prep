#John parkhurst
class node:
    def __init__(self,data):
        self.next = None
        self.data = data
class linkedlist:
    def __init__(self):
        self.head = None

    def push(self, newdata) -> None:
        new = node(newdata)
        new.next = self.head
        self.head = new
        return

    def iterlis(self) -> None:
        temp = self.head
        while temp != None:
            print(temp.data)
            temp = temp.next

    def getmax(self)-> float:
        temp = self.head
        max = temp.data
        while temp != None:
            if(temp.data>max):
                max = temp.data
            temp = temp.next
        return(max)

    def getmin(self)-> float:
        temp = self.head
        min = temp.data
        while temp != None:
            if (temp.data < min):
                min = temp.data
            temp = temp.next
        return (min)
    def extractval(self,val)-> None:
        temp = self.head
        prev= None
        while temp != None:
            if temp.data == val:
                print("Removed"+ str(temp.data))
                prev.next = temp.next
                temp = None
                return
            prev = temp
            temp = temp.next
        #THIS ONLY REACHES IF THEY DIDNT FIND
        return
    def insertAfter(self, prev, newdata)-> None:
        if prev.next == None:
            newnode = node(newdata)
            prev.next = newnode
            return
        temp = prev.next
        newnode = node(newdata)
        prev.next= newnode
        newnode.next= temp
        return
if __name__ == '__main__':
    llist = linkedlist()
    d1 = node(36)
    llist.head = d1
    #print(llist.findmax())
    llist.push(93)
    llist.push(300)
    llist.push(441)
    llist.push(99)
    llist.push(55)

    llist.insertAfter(llist.head,91)
    llist.extractval(93)
    llist.iterlis()
    #print(llist.getmin())