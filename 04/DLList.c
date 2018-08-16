void DLListDelete (DLList L) {
	DLListNode toDelete = L->curr;

	if (toDelete == NULL) {
		return;
	}

	if (toDelete->prev == NULL) {
		L->first = toDelete->next;
	} else {
		toDelete->prev->next = toDelete->next;
	}

	if (toDelete->next == NULL) {
		L->last = toDelete->prev;
		L->curr = toDelete->prev;
	} else {
		toDelete->next->prev = toDelete->prev;
		L->curr = toDelete->next;
	}

	free(toDelete->value);
	free(toDelete);
	L->nitems--;
}