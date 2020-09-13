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

# PriorityQueue源码解读
```
public class PriorityQueue<E> extends AbstractQueue<E> implements Serializable
{
  //默认容量。数字11不知是何来历？
  private static final int DEFAULT_CAPACITY = 11;

  /** 底层数组真正被使用的元素个数。*/
  int used;

  /**
   * 真正存储数据的是这个数组。使用了二项堆(binomial heap)来实现。
   * 下标为N的元素的左右子节点的坐标分别会是2N+1和2N+2。
   */
  E[] storage;

  Comparator<? super E> comparator;

  public PriorityQueue()
  {
    this(DEFAULT_CAPACITY, null);
  }

  public PriorityQueue(Collection<? extends E> c)
  {
    //从其它集合容器来初始化PriorityQueue，容量要乘以1.1。是预留扩展的空间？
    this(Math.max(1, (int) (1.1 * c.size())), null);

    //从SortedSet或PriorietyQueue来初始化PriorityQueue，可充分利用已有的排序结果。
    if (c instanceof SortedSet)
      {
        SortedSet<? extends E> ss = (SortedSet<? extends E>) c;
        this.comparator = (Comparator<? super E>) ss.comparator();
        // We can insert the elements directly, since they are sorted.
        int i = 0;
        for (E val : ss)
          {
            if (val == null)
              throw new NullPointerException();
            storage[i++] = val;
          }
      }
    else if (c instanceof PriorityQueue)
      {
        PriorityQueue<? extends E> pq = (PriorityQueue<? extends E>) c;
        this.comparator = (Comparator<? super E>)pq.comparator();
        // We can just copy the contents.
        System.arraycopy(pq.storage, 0, storage, 0, pq.storage.length);
      }

    addAll(c);
  }
  
  //......省略部分代码

  public void clear()
  {
    Arrays.fill(storage, null);
    used = 0;
  }

  //......省略部分代码

  public Iterator<E> iterator()
  {
    return new Iterator<E>()
    {
      int index = -1;
      int count = 0;

      public boolean hasNext()
      {
        return count < used;
      }

      /**
       * PriorityQueue中获取下一元素，只需数组下标增加，
       * 不过在数组的中间可能会有null，应该是二叉树中的空节点。
       */
      public E next()
      {
        while (storage[++index] == null)
          ;

        ++count;
        return storage[index];
      }

      public void remove()
      {
        PriorityQueue.this.remove(index);
        index--;
      }
    };
  }

  //offer是返回特定值的API中相应于add的操作，用于添加新元素。
  public boolean offer(E o)
  {
    if (o == null)
      throw new NullPointerException();

    //在数组中找位置的操作，findSlot与下面的bubbleUp应该是核心的操作。
    int slot = findSlot(-1);

    storage[slot] = o;
    ++used;
    //维护PriorityQueue元素之间的次序。
    bubbleUp(slot);

    return true;
  }

  //读取队头元素很简单，就是数组首个元素。
  public E peek()
  {
    return used == 0 ? null : storage[0];
  }

  public E poll()
  {
    if (used == 0)
      return null;
    E result = storage[0];
    //弹出元素的关键在remove那里。
    remove(0);
    return result;
  }

  public boolean remove(Object o)
  {
    if (o != null)
    {
      for (int i = 0; i < storage.length; ++i)
      {
        if (o.equals(storage[i]))
        {
          //调用参数为下标的remove
          remove(i);
          return true;
        }
      }
    }
    return false;
  }

  public int size()
  {
    return used;
  }

  //......省略部分代码

  //找到可以放入数据的位置。
  int findSlot(int start)
  {
    int slot;
    if (used == storage.length)
    {
      resize();
      slot = used;
    }
    else
    {
      //查找是从start+1开始，也就可以明白前面的代码在调用findSlot时，提供的参数是-1。
      for (slot = start + 1; slot < storage.length; ++slot)
      {
        //找到第一个非空位置即止。
        if (storage[slot] == null)
          break;
      }
      // We'll always find a slot.
    }
    return slot;
  }

  //删除指定位置的元素，比找到插入位置更复杂。
  void remove(int index)
  {
    //移除指定下标的元素的逻辑：反复从左右子节点中找出小的那一个，
    //放到当前位置，直至树的叶子节点。
    while (storage[index] != null)
    {
      //左子节点的下标。
      int child = 2 * index + 1;

      //如果不存在左子节点，那么移除当前节点只需直接在该位置放个null。
      if (child >= storage.length)
      {
        storage[index] = null;
        break;
      }

      if (child + 1 >= storage.length || storage[child + 1] == null)
      {
        // 右子节点不存在时，提升左子节点。
      }
      else if (storage[child] == null
               || (Collections.compare(storage[child], storage[child + 1],
                                       comparator) > 0))
        ++child; //左子节点不存在，或右子节点的值更大，提升右子节点。
      //所谓移除，其实是让较小的子节点来代替自己。
      storage[index] = storage[child];
      index = child;
    }
    --used;
  }

  //只在findSlot中调用过，发生在新元素加入到底层数组的第一个非null位置被放入数据之后。
  void bubbleUp(int index)
  {
    //index原为底层数组第一个非null元素，现在刚放入新元素，需要要根据新元素的值到树中找到位置。
    while (index > 0)
    {
      //找出index节点的父节点，不用管index是左子节点，还是右子节点，下面的公式都会成立。
      int parent = (index - 1) / 2;
      if (Collections.compare(storage[parent], storage[index], comparator) <= 0)
      {
        //若父节点已经比index节点要小，次序已经得到保证，无需继续循环。
        break;
      }

      //交换父节点与index节点的值。
      E temp = storage[index];
      storage[index] = storage[parent];
      storage[parent] = temp;

      //下一轮检查父节点是否需要提升。
      index = parent;
    }
  }

  void resize()
  {
    E[] new_data = (E[]) new Object[2 * storage.length];
    System.arraycopy(storage, 0, new_data, 0, storage.length);
    storage = new_data;
  }
}
```
## PriorityQueue总结
用普通的数组，做出了优先队列的功能。可见最普通的食材，也能做出最高级的菜肴，全看厨师是否高明。

源码注释中说是使用了binomial heap（二项堆），根据资料二项堆是由多个二叉树构成，从源码上看不出这一点。所有的操作都是针对一棵二叉树来做的，没有多个二叉树合并的逻辑，因此，PriorityQueue使用的是二叉堆，二叉堆应该是binary heap。

插入和删除操作都会涉及是否提升子节点的问题，假定元素个数为n，则树高$log(n)$，因此，插入和删除操作的时间复杂都是$log(n)$。

# 第一周学习总结
## 学习方法
覃超老师关于学习方法的讲解点中了我两个从未意识到过的问题：
1. 把有间隔的重复用于刷题。
2. 放低身段，不纠结于自己做题的能力。
初闻五毒神掌，真有醍醐灌顶的感觉。观念的束缚可以让人在黑暗的角落困惑多年，这时就见出与顶尖高手为伍的重要性。

我知道有间隔的重复，但从没想过要用到做算法题目上。经典的解题方案需要反复地玩味，语言上的技巧也得仔细琢磨。高手眼中，看到一题，或许就能从脑海中调出上百题类似的题解，于是外人看来，就成为不可思议的大神。

不纠结于解题能力，并不意味着解题会变得轻松，而是把关注的重点移到了题解本身。原先我们在看到匪夷所思的题解时，会很受打击，那是因为我们关注的是“自己”的解题能力。承认自己没有能力解题后，不再关注这个被打击的“自我”，花费的时间就移到了读懂那些题解上面。

真正折磨人的其实是在第二次、第三次，不看题解，重复做题。原本一清二楚的逻辑，在真刀实枪面前，一败涂地。此时的打击其实比初次做题时更为难堪，坚持下去的路途依旧漫漫长远。接下来的时间应该不会轻松。

## 印象最深刻的两个知识点
### 快慢指针
判断链表有没有环，最自然的思路是记下每次经过的结点，看看是否会走到相同的结点。在看题解之前，我的意识中是无法想象还可有其他的解法的。好在现在的心态比以前要好，不去纠结这样的问题：为什么别人能想出快慢指针的解法？
### 栈的使用
汇编语言中每次函数调用都得用栈，栈那是x86机器硬件层面的核心设计。用栈来解决括号匹配问题，也非常自然，但在看到接雨水一题中栈的用法以后，我又是好一阵目瞪口呆。在计算中，栈顶元素被推出后，还得再使用推出后的栈顶元素，两者的结合才能得到正确结果。这样的绕法，还是第一次接触。
