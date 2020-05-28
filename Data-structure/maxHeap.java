class MaxHeap{
	private int[] Heap;
	private int size;
	private int maxSize;

	public MaxHeap(int maxSize){
		this.size = -1;
		this.Heap = new int[maxSize];
		this.maxSize = maxSize;
	}
	
	public void swap(int i, int j){
		int temp = Heap[i];
		Heap[i] = Heap[j];
		Heap[j] = temp;	
	}
	
	public int parent(int pos){
		return pos/2;
	}	

	public boolean isLeaf(int pos){
		if(pos >= (size + 1)/2 && pos <= size) return true;
		return false;
	}

	public int leftChild(int pos) { 
		return (2*pos) + 1;
	}
	public int rightChild(int pos){
		 return (2*pos) + 2;
	}

	public void minHeapify(int pos){
		int r = pos;
		if(!isLeaf(pos)){
				if(Heap[pos] < Heap[leftChild(pos)] || Heap[pos] <  Heap[rightChild(pos)]){
					if(Heap[leftChild(pos)] > Heap[rightChild(pos)]) {
						swap(pos, leftChild(pos));
						minHeapify(leftChild(pos));
					}else {
						swap(pos, rightChild(pos));
						minHeapify(rightChild(pos));
					}
				}
		}
			//if(size == 2*r + 1){
			//	if(Heap[r] > Heap[size]) swap(r, size);
			//	r = size;
			//}
			//else if(Heap[r] > Heap[2*r + 1] && Heap[2*r + 1] <= Heap[2*r + 2]){
			//	swap(r, 2*r + 1);
			//	r = 2*r + 1;	
			//}
			//else if(Heap[r] > Heap[2*r + 2] && Heap[2*r + 2] < Heap[2*r + 1]){
			//	swap(r, 2*r + 2);
			//	r = 2*r + 2;
			//}
			//else r = size;
	}
	
	public void minHeap(){
		for(int pos = (size + 1)/2; pos >= 0; pos--){
			minHeapify(pos);
			System.out.println(pos);
		}
	}
	public int remove(){
		int poped = Heap[0];
		// swap Heap[0] with the last element
		if(size > 0){
			Heap[0] = Heap[size--];
			// Rebuild heap
			minHeapify(0);
		}
		return poped;
	}

	public void insert(int value){
		if(size >= maxSize) return;
		Heap[++size] = value;
		int current = size;
		while(Heap[current] < Heap[parent(current)]){
			swap(current,  parent(current));
			current = parent(current);
		}
	}

	public void print(){
		for(int i = 0; i < (size+1)/2; i++){
			System.out.println("Parent: " + Heap[i] + ", LeftChild: "
												 + Heap[2*i + 1] + ", RighChild: " + Heap[2*i + 2]);
		}
	}
	public static void main(String[] args){
		MaxHeap heap = new MaxHeap(15);
		heap.insert(5);
		heap.insert(3);
		heap.insert(17);
		heap.insert(10);
		heap.insert(84);
		heap.insert(19);
		heap.insert(6);
		heap.insert(22);
		heap.insert(9);
		heap.minHeap();
	
		heap.print();
		int n = heap.size;
		for(int i = 0; i <= n; i++)	
			System.out.println(heap.remove());
	}

}
