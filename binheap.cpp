typedef struct BinHeapNode BinNode;
typedef struct BinHeapNode *BinHeap;
typedef struct BinHeapNode *Position;

struct BinHeapNode {
int key;
int degree;
Position parent;
Position leftChild;
Position sibling;
};

BinHeap MakeBinHeap(){
 BinHeap heap=NULL;
 heap=(BinHeap)malloc(sizeof(BinNode));
 if (heap==NULL)
 {
 puts("out of the space");
 exit(1);
 }
 memset(newHeap,0,sizeof(BinNode));
 return heap;
}

BinHeap BinHeapMin(BinHeap heap){
    Position y=NULL,x=heap;
    int min=INT_MAX;
     
    while(x!=NULL){
        if (x->key<min)
        {
        min=x->key;
        y=x;
        }
        x=x->sibling;
    }
    return y;
}
