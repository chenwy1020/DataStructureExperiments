#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}
void max_heapify(int arr[], int start, int end) {
    //�������ڵ�ָ����ӽڵ�ָ��
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { //���ӽڵ�ָ���ڷ�Χ�ڲ����Ƚ�
        if (son + 1 <= end && arr[son] < arr[son + 1]) //�ȱȽ������ӽڵ��С��ѡ������
            son++;
        if (arr[dad] > arr[son]){ //������ڵ�����ӽڵ���������ϣ�ֱ����������
			printf("��\n"); 
			return;
			
		
		}
        else { //���򽻻����������ټ����ӽڵ����ڵ�Ƚ�
            swap(&arr[dad], &arr[son]);
            dad = son;
            son = dad * 2 + 1;
            printf("��\n"); 
        }
    }
    printf("��\n");
}
void heap_sort(int arr[], int len) {
    int i;
    //��ʼ����i�����һ�����ڵ㿪ʼ����
    for (i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
    //�Ƚ���һ��Ԫ�غ����ź�Ԫ��ǰһλ���������ٴ��µ�����ֱ���������
    for (i = len - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}
int main() {
    int arr[] = { 7,3,6,5,11,8,33,100 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    heap_sort(arr, len);
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
