namespace LinkedList
{
	struct OneDirectionListNode
	{
		int m_val;
		OneDirectionListNode* next;
		OneDirectionListNode(int val) : m_val(val), next(nullptr) {}
	}; 

	struct OneDirectionList
	{
		OneDirectionListNode* head;

		OneDirectionList() : head(nullptr) {}

		void append(int val)
		{
			OneDirectionListNode* node = new OneDirectionListNode(val);
			node->next = head;
			head = node;
		}

		void remove()
		{
			if (head)
			{
				OneDirectionListNode* newHead = head->next;
				delete head;
				head = newHead;
			}
		}

		~OneDirectionList()
		{
			while (head)
			{
				remove();
			}
		}

		struct Iterator
		{
			OneDirectionListNode* m_node;
			Iterator(OneDirectionListNode* node) : m_node(node) {}

			bool operator==(const Iterator& other) const
			{
				if (this == &other)
				{
					return true;
				}
				return m_node == other.m_node;
			}

			bool operator!=(const Iterator& other) const
			{
				return !operator==(other);
			}

			int operator*() const
			{
				if (m_node)
				{
					return m_node->m_val;
				}
				return -1;
			}

			void operator++()
			{
				if (m_node)
				{
					m_node = m_node->next;
				}
			}
		};

		Iterator begin() const
		{
			return Iterator(head);
		}

		Iterator end() const
		{
			return Iterator(nullptr);
		}
	};

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
}
