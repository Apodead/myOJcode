typedef int T;
struct ListNode {
  T value;
  ListNode *next;
};
void InsertNode(ListNode *head, ListNode *node) {
  node.next = head.next;
  head.next = &node;
}
void GetValue(T *result, ListNodheade *) {
  while (head.next != NULL) {
    *result = head.value;
    head = head.next;
    result++;
  }
}