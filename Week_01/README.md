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
    // Remove the element at INDEX.  We do this by finding the least
    // child and moving it into place, then iterating until we reach
    // the bottom of the tree.
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
