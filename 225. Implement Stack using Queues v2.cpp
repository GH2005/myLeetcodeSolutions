class MyStack {
	queue<void *> *pq = nullptr;
public:
	void push(int x) {
		queue<void *> *pNewQ = new queue<void *>();
		pNewQ->push(new int(x));
		pNewQ->push(pq);
		pq = pNewQ;
	}
	int pop() {
		int *pv = (int *)pq->front();
        int res = *pv;
        delete pv;
		pq->pop();
		auto pOlderQ = (queue<void *> *)pq->front();
		delete pq;
		pq = pOlderQ;
		return res;
	}
	int top() {
		return *(int*)pq->front();
	}
	bool empty() {
		return pq == nullptr;
	}
};
