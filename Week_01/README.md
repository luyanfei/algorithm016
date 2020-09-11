# 改写Deque的代码
JDK的Deque中用于操作元素的成员可分为两类，一是会抛出异常的，二是返回特殊值的。将下面使用抛出异常API的代码改写成返回特殊值的代码。
```
Deque<String> deque = new LinkedList<String>();

deque.push("a");
deque.push("b");
deque.push("c");
System.out.println(deque);

String str = deque.peek();
System.out.println(str);
System.out.println(deque);

while (deque.size() > 0) {
    System.out.println(deque.pop());
}
System.out.println(deque);
```
改写如下：
```
Deque<String> deque = new LinkedList<String>();

deque.offerFirst("a");
deque.offerFirst("b");
deque.offerFirst("c");
System.out.println(deque);

String str = deque.peekFirst();
System.out.println(str);
System.out.println(deque);

while (deque.size() > 0) {
    System.out.println(deque.pollFirst());
}
System.out.println(deque);
```
