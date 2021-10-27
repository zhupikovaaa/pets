void reverseList(OneDirectionList* list)
	{
		if (list->head)
		{
			OneDirectionListNode* curr, * next, * prev = nullptr;
			curr = list->head;
			while (curr)
			{
				next = curr->next;
				curr->next = prev;
				prev = curr;
				curr = next;
			}
			list->head = prev;
		}
	}
