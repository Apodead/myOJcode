#define MAXN (int)1e6 + 5
typedef int T;
typedef struct _ListNode{
  T value;
  struct _ListNode *next;
}ListNode;
void InsertNode(ListNode *head, ListNode *node) {
  node->next = head->next;
  
  head->next = node;
}
void GetValue(T *result, ListNode *head ) {
  while (head->next) {
    *result = head->value;
    head = head->next;
    result++;
  }
}
void BucketSort(T *array, int l, int r)
