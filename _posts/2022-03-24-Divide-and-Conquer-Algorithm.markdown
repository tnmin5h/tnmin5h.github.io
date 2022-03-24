---
layout: post
title: Divide-and-Conquer Algorithm
date:   2022-03-24 23:02:22 +0900
categories: homework
---

## 분할 정복 알고리즘

`분할 정복 알고리즘`이란 주어진 문제의 입력을 **분할하여 문제를 해결 즉, 정복하는 방식의 알고리즘**을 의미한다.
분할된 입력에 대하여 동일한 알고리즘을 적용하여 해를 계산하며, 이들의 해를 취합하여 원래 문제의 해를 얻는다. 여기서 분할된 입력에 대한 문제를 부분문제라고 하고, 부분문제의 해를 부분해라고 한다. *부분 문제는 더 이상 분할할 수 없을 때까지 계속 분할한다.*

___

## 분할 정복 알고리즘의 종류
**`분할 정복 알고리즘`은 분할되는 부분문제의 수와 부분문제의 크기에 따라서 아래와 같이 분류가 가능하다.**

1. 문제가 a개로 분할되고 부분문제의 크기가 1/b로 감소하는 알고리즘 (ex. 합병정렬)
2. 문제가 2개로 분할되고, 부분문제의 크기가 일정하지 않은 크기로 감소하는 알고리즘 (ex. 퀵정렬)
3. 문제가 2개로 분할되나 그중에 1개의 부분문제는 고려할 필요가 없으며, 부분 문제의 크기가 1/2로 감소하는 알고리즘 (ex. 이진탐색)
4. 문제가 2개로 분할되나, 그중에 1개의 부분문제는 고려할 필요가 없으며, 부분 문제의 크기가 일정하지 않은 크기로 감소하는 알고리즘 (ex. 선택 문제 알고리즘)
5. 부분문제의 크기가 1, 2개씩 감소하는 알고리즘 (ex. 삽입 정렬, 피보나치 수의 계산)

---
## 분할 정복 알고리즘의 예시
```
import java.util.Random;

public class DivideAndConquer {
    private boolean isSomething(int start, int end) {
        return start >= end;
    }

    // primitive type 원시 변수 [int, char, float, double, bool, short, long]
    // instance variable
    // 객체 [String, int[], Animal]: String str = new String("hello"); //

    public void mergeSort(int[] arr, int start, int end) { // 6
        if (isSomething(start, end)) { return; }

        int mid = (start + end) / 2;        // start = 0, end = 5, mid = 2

        mergeSort(arr, 0, mid);
        mergeSort(arr, mid+1, end);

        merge(arr, start, mid, end);
    }

    private void merge(int[] arr, int start, int mid, int end) {
        int p = start;
        int q = mid + 1;
        int idx = p;

        int[] tmp = new int[arr.length];

        while(p <= mid || q <= end) {
            if (q > end || (p <= mid && arr[p] < arr[q])) {
                tmp[idx++] = arr[p++];
            } else {
                tmp[idx++] = arr[q++];
            }
        }

        if (end + 1 - start >= 0) System.arraycopy(tmp, start, arr, start, end + 1 - start);
    }

    public static void main(String[] args) {
        Random r = new Random();

        int[] arr = new int[20];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = r.nextInt(1000);   // (0, 1000]
        }

        for (int k : arr) {
            System.out.printf("%d ", k);
        }
        System.out.println();

        DivideAndConquer dac = new DivideAndConquer();
        dac.mergeSort(arr, 0, arr.length - 1);

        for (int j : arr) {
            System.out.printf("%d ", j);
        }

        System.out.println();

        System.out.println("hello world");
    }
}
```
