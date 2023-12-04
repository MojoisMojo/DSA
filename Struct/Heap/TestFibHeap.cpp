#include <bits/stdc++.h>

using namespace std;

public class TestFibHeap {
    // 共8个
    private int[] a = { 12, 7, 25, 15, 28, 33, 41, 1 };
    // 共14个
    private int[] b = { 18, 35, 20, 42,  9,
                             31, 23,  6, 48, 11,
                          24, 52, 13,  2 };

    // 验证"基本信息(斐波那契堆的结构)"
    public void testBasic() {
        FibHeap hb = new FibHeap();

        // 斐波那契堆hb
        Console.WriteLine("== 斐波那契堆(hb)中依次添加: ");
        for (int i = 0; i < b.Length; i++) {
            Console.Write("{0} ", b[i]);
            hb.insert(b[i]);
        }
        Console.WriteLine("\n");
        Console.WriteLine("== 斐波那契堆(hb)删除最小节点\n");
        hb.removeMin();
        hb.print(); // 打印斐波那契堆hb
    }

    // 验证"插入操作"
    public void testInsert() {
        FibHeap ha = new FibHeap();

        // 斐波那契堆ha
        Console.WriteLine("== 斐波那契堆(ha)中依次添加: ");
        for (int i = 0; i < a.Length; i++) {
            Console.Write("{0} ", a[i]);
            ha.insert(a[i]);
        }
        Console.WriteLine("\n");
        Console.WriteLine("== 斐波那契堆(ha)删除最小节点\n");
        ha.removeMin();
        ha.print(); // 打印斐波那契堆ha

        Console.WriteLine("== 插入50\n");
        ha.insert(50);
        ha.print();
    }

    // 验证"合并操作"
    public void testUnion() {
        FibHeap ha = new FibHeap();
        FibHeap hb = new FibHeap();

        // 斐波那契堆ha
        Console.WriteLine("== 斐波那契堆(ha)中依次添加: ");
        for (int i = 0; i < a.Length; i++) {
            Console.Write("{0} ", a[i]);
            ha.insert(a[i]);
        }
        Console.WriteLine("\n");
        Console.WriteLine("== 斐波那契堆(ha)删除最小节点\n");
        ha.removeMin();
        ha.print(); // 打印斐波那契堆ha

        // 斐波那契堆hb
        Console.WriteLine("== 斐波那契堆(hb)中依次添加: ");
        for (int i = 0; i < b.Length; i++) {
            Console.Write("{0} ", b[i]);
            hb.insert(b[i]);
        }
        Console.WriteLine("\n");
        Console.WriteLine("== 斐波那契堆(hb)删除最小节点\n");
        hb.removeMin();
        hb.print(); // 打印斐波那契堆hb

        // 将"斐波那契堆hb"合并到"斐波那契堆ha"中。
        Console.WriteLine("== 合并ha和hb\n");
        ha.union(hb);
        ha.print();
    }

    // 验证"删除最小节点"
    public void testRemoveMin() {
        FibHeap ha = new FibHeap();
        FibHeap hb = new FibHeap();

        // 斐波那契堆ha
        Console.WriteLine("== 斐波那契堆(ha)中依次添加: ");
        for (int i = 0; i < a.Length; i++) {
            Console.Write("{0} ", a[i]);
            ha.insert(a[i]);
        }
        Console.WriteLine("\n");
        Console.WriteLine("== 斐波那契堆(ha)删除最小节点\n");
        ha.removeMin();
        //ha.print(); // 打印斐波那契堆ha

        // 斐波那契堆hb
        Console.WriteLine("== 斐波那契堆(hb)中依次添加: ");
        for (int i = 0; i < b.Length; i++) {
            Console.Write("{0} ", b[i]);
            hb.insert(b[i]);
        }
        Console.WriteLine("\n");
        Console.WriteLine("== 斐波那契堆(hb)删除最小节点\n");
        hb.removeMin();
        //hb.print(); // 打印斐波那契堆hb

        // 将"斐波那契堆hb"合并到"斐波那契堆ha"中。
        Console.WriteLine("== 合并ha和hb\n");
        ha.union(hb);
        ha.print();

        Console.WriteLine("== 删除最小节点\n");
        ha.removeMin();
        ha.print();
    }

    // 验证"减小节点"
    public void testDecrease() {
        FibHeap hb = new FibHeap();

        // 斐波那契堆hb
        Console.WriteLine("== 斐波那契堆(hb)中依次添加: ");
        for (int i = 0; i < b.Length; i++) {
            Console.Write("{0} ", b[i]);
            hb.insert(b[i]);
        }
        Console.WriteLine("\n");
        Console.WriteLine("== 斐波那契堆(hb)删除最小节点\n");
        hb.removeMin();
        hb.print(); // 打印斐波那契堆hb

        Console.WriteLine("== 将20减小为2\n");
        hb.update(20, 2);
        hb.print();
    }

    // 验证"增大节点"
    public void testIncrease() {
        FibHeap hb = new FibHeap();

        // 斐波那契堆hb
        Console.WriteLine("== 斐波那契堆(hb)中依次添加: ");
        for (int i = 0; i < b.Length; i++) {
            Console.Write("{0} ", b[i]);
            hb.insert(b[i]);
        }
        Console.WriteLine("\n");
        Console.WriteLine("== 斐波那契堆(hb)删除最小节点\n");
        hb.removeMin();
        hb.print(); // 打印斐波那契堆hb

        Console.WriteLine("== 将20增加为60\n");
        hb.update(20, 60);
        hb.print();
    }

    // 验证"删除节点"
    public void testDelete() {
        FibHeap hb = new FibHeap();

        // 斐波那契堆hb
        Console.WriteLine("== 斐波那契堆(hb)中依次添加: ");
        for (int i = 0; i < b.Length; i++) {
            Console.Write("{0} ", b[i]);
            hb.insert(b[i]);
        }
        Console.WriteLine("\n");
        Console.WriteLine("== 斐波那契堆(hb)删除最小节点\n");
        hb.removeMin();
        hb.print(); // 打印斐波那契堆hb

        Console.WriteLine("== 删除节点20\n");
        hb.remove(20);
        hb.print();
    }

    public void test() {
        // 验证"基本信息(斐波那契堆的结构)"
        testBasic();
        // 验证"插入操作"
        testInsert();
        // 验证"合并操作"
        testUnion();
        // 验证"删除最小节点"
        testRemoveMin();
        // 验证"减小节点"
        testDecrease();
        // 验证"增大节点"
        testIncrease();
        // 验证"删除节点"
        testDelete();
    }
}

int main() {

    //system("pause");
    return 0;
}
