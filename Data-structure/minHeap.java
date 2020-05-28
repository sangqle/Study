class MinHeap{
	private int[] Heap;
	private int size;
	private int maxsize;

	private static final int FRONT = 1;
	public MinHeap(int maxsize){
		this.maxsize = maxsize;
		this.size = 0;
		Heap = new int[this.maxsize + 1];
		Heap[0] = Integer.MIN_VALUE;
	}
	// Function to return the position of
	// the parent for the node currently
	private int parent(int pos){
		return pos / 2;
	}
	private int leftChild(int pos){
		return (2 * pos);
	}
	private int rightChild(int pos){
		return (2 * pos) + 1;
	}
	private boolean isLeaf(int pos){
		if(pos >= (size/2) && pos <= size){
			return true;
		}
		return false;
	}
	private void swap(int fpos, int spos){
		int tmp;
		tmp = Heap[fpos];
		Heap[fpos] = Heap[spos];
		Heap[spos] = tmp;
	}
	// Function to heapify the node at pos
	private void minHeapify(int pos){}
	// Function to insert a node into the heap
	public void insert(int element){
		if(size >= maxsize) return;
		Heap[++size] = element;
		int current = size;
		while(Heap[current] < Heap[parent(current)]) {
			swap(current, parent(current));
			current = parent(current);
		}		
	}

	// Function to print the contents of the heap
	public void print(){
		for(int i = 1; i <= size / 2; i++){
			System.out.println(" Parent: " + Heap[i] 
												 + " Left child: " + Heap[2 * i]
												 + " Right child: " + Heap[2 * i + 1]);
			System.out.println();
		}	
	}

	// Function to remove and return the minium element of the heap

	public static void main(String[] args){
		System.out.println("The heap is: ");
		MinHeap minHeap = new MinHeap(15);
		minHeap.insert(5);
		minHeap.insert(3);
		minHeap.insert(17);
		minHeap.insert(10);
		minHeap.insert(84);
		minHeap.insert(19);
		minHeap.insert(6);
		minHeap.insert(22);
		minHeap.insert(9);
		
		minHeap.print();
		System.out.println(minHeap.isLeaf(4));
	}
}
