class Solution {
public:
    
RandomListNode *copyRandomList(RandomListNode *head) {
	RandomListNode * iter = head, * next;

	// First round: make copy of each node,
	// and link them together side-by-side in a single list.
	while (iter != nullptr) {
		next = iter->next;

		RandomListNode * copy = new RandomListNode(iter->label);
		iter->next = copy;
		copy->next = next;

		iter = next;
	}

	// Second round: assign random pointers for the copy nodes.
	iter = head;
	while (iter != nullptr) {
		if (iter->random != nullptr) {
			iter->next->random = iter->random->next;
		}
		iter = iter->next->next;
	}

	// Third round: restore the original list, and extract the copy list.
	iter = head;
	RandomListNode *pseudoHead = new RandomListNode(0);
	RandomListNode * copy, * copyIter = pseudoHead;

	while (iter != nullptr) {
		next = iter->next->next;

		// extract the copy
		copy = iter->next;
		copyIter->next = copy;
		copyIter = copy;

		// restore the original list
		iter->next = next;

		iter = next;
	}
	
	RandomListNode * temp=pseudoHead->next;
	delete pseudoHead;
	return temp;
}
};