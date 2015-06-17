import os, re

class Node:
    def __init__(self,newNama,newUmur,newAlamat,left=None,right=None,prev=None,leftRight=None):
        self.leftNode = left
        self.rightNode = right
        self.prevNode = prev
        self.nama = newNama
        self.umur = newUmur
        self.alamat = newAlamat
        self.isLeft = leftRight #left = True, right = False

    def traversal(self, currentNode):
        if currentNode.leftNode: # != None
            self.traversal( currentNode.leftNode )
            
        self.printNode( currentNode )
        
        if currentNode.rightNode: # != None
            self.traversal( currentNode.rightNode )

    def preTraversal(self, currentNode):
        self.printNode( currentNode )
        
        if currentNode.leftNode: # != None
            self.preTraversal( currentNode.leftNode )
        
        if currentNode.rightNode: # != None
            self.preTraversal( currentNode.rightNode )

    def postTraversal(self, currentNode):
        if currentNode.leftNode: # != None
            self.preTraversal( currentNode.leftNode )
        
        if currentNode.rightNode: # != None
            self.preTraversal( currentNode.rightNode )
        
        self.printNode( currentNode )

    def printNode(self, node):
        print( node.nama + "\t" + node.umur + "\t" + node.alamat)

    def addNode(self, newNode, putLeft):
        if putLeft:
            self.leftNode = newNode
        else:
            self.rightNode = newNode

class Tree:
    def __init__(self, filename):
        self.dbFile = open(".\\"+filename)
        self.lines = self.dbFile.readlines()

        line = self.lines[0][:-1]
        name, age, address = line.split("\t")
        self.root = Node( name, age, address )
        
        for i in range(1, len(self.lines)):
            line = self.lines[i][:-1]
            name, age, address = line.split("\t")
            self.insert(name, age, address)

    def insert(self, name, age, address):
        currentNode = self.root
        goLeft = True
        
        while currentNode: # != None
            prevNode = currentNode
            comparedNama = currentNode.nama
            if name < comparedNama:
                currentNode = currentNode.leftNode
                goLeft = True
            elif comparedNama < name:
                currentNode = currentNode.rightNode
                goLeft = False

        prevNode.addNode( Node(name,age,address,prev=prevNode,leftRight=goLeft), goLeft)

    def delete(self, data, dataType):
        tbd_list = self.search(data,dataType,self.root)
        if tbd_list == []:
            print(data,"not found")
            return
        if len(tbd_list) > 1:
            print("Too many possibilities. Pick a different value.")
            return
        tbd = tbd_list[0]
        if tbd.rightNode:
            replacement = tbd.rightNode
            while replacement.leftNode: # != None
                replacement = replacement.leftNode
            
##            print(replacement.nama)
##            try:
##                print(tbd.prevNode.nama)
##            except:
##                print()
##            try:
##                print(tbd.leftNode.nama)
##            except:
##                print()
##            try:
##                print(tbd.rightNode.nama)
##            except:
##                print()
##            try:
##                print(replacement.prevNode.nama)
##            except:
##                print()
##            try:
##                print(replacement.leftNode.nama)
##            except:
##                print()
##            try:
##                print(replacement.rightNode.nama)
##            except:
##                print()

            # connect tbd's left node to replacement
            if tbd.leftNode:
                if tbd.leftNode != replacement:
                    replacement.leftNode = tbd.leftNode
                else:
                    replacement.leftNode = None

            # if replacement had a rightNode
            # connect it to replacement.prevNode.leftNode
            if replacement.rightNode:
                replacement.prevNode.leftNode = replacement.rightNode
                replacement.rightNode.prevNode = replacement.prevNode
            else:
                replacement.prevNode.leftNode = None

            # replace replacement.rightNode with tbd.rightNode
            if tbd.rightNode:
                if tbd.rightNode != replacement:
                    replacement.rightNode = tbd.rightNode
                    tbd.rightNode.prevNode = replacement
                else:
                    replacement.rightNode = None

            # connect replacement to tbd's PrevNode
            if tbd != self.root:
                replacement.prevNode = tbd.prevNode
                if tbd.isLeft:
                    tbd.prevNode.leftNode = replacement
                else:
                    tbd.prevNode.rightNode = replacement
            else:
                self.root = replacement

##            try:
##                print(replacement.prevNode.nama)
##            except:
##                print()
##            try:
##                print(replacement.leftNode.nama)
##            except:
##                print()
##            try:
##                print(replacement.rightNode.nama)
##            except:
##                print()
##            print(tbd.isLeft)
##            try:
##                print(tbd.prevNode.leftNode.nama)
##            except:
##                print()
##            try:
##                print(tbd.prevNode.rightNode.nama)
##            except:
##                print()
                
        elif tbd.leftNode:
            tbd.leftNode.prevNode = tbd.prevNode
            tbd.prevNode.leftNode = tbd.leftNode
        else:
            if tbd.isLeft:
                tbd.prevNode.leftNode = None
            else:
                tbd.prevNode.rightNode = None

    def search(self, data, dataType, currentNode = None):
        if not currentNode:
            return
        results = []
        leftSearch = self.search(data, dataType, currentNode = currentNode.leftNode)
        if leftSearch:
            for i in leftSearch:
                results.append(i)
        if dataType=="nama" and currentNode.nama==data:
            results.append(currentNode)
        if dataType=="umur" and currentNode.umur==data:
            results.append(currentNode)
        if dataType=="alamat" and currentNode.alamat==data:
            results.append(currentNode)
        rightSearch = self.search(data, dataType, currentNode = currentNode.rightNode)
        if rightSearch:
            for i in rightSearch:
                results.append(i)
        return results

    def traversal(self):
        self.root.traversal(self.root)

    def preTraversal(self):
        self.root.preTraversal(self.root)

    def postTraversal(self):
        selt.root.postTraversal(self.root)

database = Tree("data.txt")
database.preTraversal()
