class node:
    def __init__(self,data):
        self.data = data
        self.next = None
class linkedlist:

    def __init__(self,node):
        self.head = node

    def iterlis(self):
        node = self.head
        while node != None:
            print(node.data)
            node=node.next
        return

def main(var: int) -> int:
    n1 = node(32)
    ll = linkedlist(n1)
    n2 = node(342)
    n3 = node(352)
    n4 = node(362)
    n1.next = n2
    n2.next = n3
    n3.next = n4
    ll.iterlis()
    return 1

main(3)