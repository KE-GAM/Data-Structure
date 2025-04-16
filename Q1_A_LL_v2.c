#include <stdio.h> // 표준 입출력 함수를 사용하기 위한 헤더파일 (printf, scanf 등)
#include <stdlib.h> // 동적 메모리 할당 함수 사용을 위한 헤더파일 (malloc, free 등)

// 연결 리스트에서 사용할 노드 구조체 정의
typedef struct _listnode {
    int item;                 // 노드에 저장할 데이터 (정수형)
    struct _listnode *next;   // 다음 노드를 가리키는 포인터
} ListNode; // 구조체 이름을 간단히 ListNode 로 사용

// 연결 리스트 전체를 관리하는 구조체 정의
typedef struct _linkedlist {
    int size;              // 연결 리스트에 저장된 노드(데이터)의 개수
    ListNode *head;        // 리스트의 첫 번째 노드를 가리키는 포인터
} LinkedList; // 구조체 이름을 간단히 LinkedList 로 사용

// 함수 선언 (프로토타입) - 함수 사용 전에 컴파일러에게 알려주는 역할
void printList(LinkedList *ll);               // 리스트 출력 함수
void removeAllItems(LinkedList *ll);          // 리스트 안의 모든 노드를 삭제하는 함수
ListNode *findNode(LinkedList *ll, int index);// 리스트에서 특정 위치의 노드를 찾는 함수
int insertNode(LinkedList *ll, int index, int value); // 특정 위치에 새 노드를 삽입하는 함수
int removeNode(LinkedList *ll, int index);    // 특정 위치의 노드를 삭제하는 함수

// 프로그램이 시작되는 메인 함수
int main() {
    LinkedList ll; // 연결 리스트 변수 선언
    int c, i, j;  // 사용자의 메뉴 선택(c), 입력값(i), 최근 삽입 인덱스(j) 저장용 변수
    c = 1; // 반복문 시작을 위해 c를 1로 초기화

    // 연결 리스트 초기화: 아무 노드도 없는 상태로 설정
    ll.head = NULL;
    ll.size = 0;

    // 사용자 메뉴 출력
    printf("1: Insert an integer to the sorted linked list:\n");
    printf("2: Print the index of the most recent input value:\n");
    printf("3: Print sorted linked list:\n");
    printf("0: Quit:");

    // 사용자가 0을 입력하기 전까지 계속 반복
    while (c != 0) {
        printf("\nPlease input your choice(1/2/3/0): ");
        scanf("%d", &c); // 사용자의 메뉴 선택 입력받기

        switch (c) {
            case 1: // 리스트에 값을 삽입하는 경우
                printf("Input an integer that you want to add to the linked list: ");
                scanf("%d", &i); // 사용자로부터 삽입할 숫자 입력 받기
                // 원래 insertSortedLL 함수 호출 부분인데, 문제는 사용자가 푸실 거라 비워둡니다!
                printf("The resulting linked list is: ");
                printList(&ll); // 현재 리스트 상태 출력
                break;
            case 2: // 가장 최근에 삽입한 값과 위치 출력
                printf("The value %d was added at index %d\n", i, j);
                break;
            case 3: // 리스트 출력 후 메모리 초기화
                printf("The resulting sorted linked list is: ");
                printList(&ll); // 현재 리스트 상태 출력
                removeAllItems(&ll); // 메모리 해제 및 리스트 초기화
                break;
            case 0: // 프로그램 종료
                removeAllItems(&ll); // 프로그램 종료 전에 메모리 정리
                break;
            default: // 잘못된 메뉴 선택 시
                printf("Choice unknown;\n");
                break;
        }
    }

    return 0; // 프로그램 정상 종료
}

//////////////////////////////////////////////////////////////////////////////////

int insertSortedLL(LinkedList *ll, int item)
{
	/* add your code here */
}

///////////////////////////////////////////////////////////////////////////////////

// 리스트의 모든 값을 출력하는 함수
void printList(LinkedList *ll) {
    ListNode *cur;

    if (ll == NULL)
        return; // 리스트가 초기화되지 않은 경우 아무 것도 하지 않음

    cur = ll->head; // 리스트의 첫 번째 노드부터 시작

    if (cur == NULL)
        printf("Empty"); // 리스트가 비어 있으면 "Empty" 출력

    while (cur != NULL) {
        printf("%d ", cur->item); // 현재 노드의 값 출력
        cur = cur->next; // 다음 노드로 이동
    }
    printf("\n"); // 출력이 끝나면 줄바꿈
}

// 리스트 안의 모든 노드를 삭제하고 메모리를 해제하는 함수
void removeAllItems(LinkedList *ll) {
    ListNode *cur = ll->head;
    ListNode *tmp;

    while (cur != NULL) {
        tmp = cur->next; // 다음 노드를 임시 저장
        free(cur); // 현재 노드 메모리 해제
        cur = tmp; // 다음 노드로 이동
    }

    // 리스트를 초기 상태로 리셋
    ll->head = NULL;
    ll->size = 0;
}

// 리스트에서 index 번째 노드를 찾아 반환하는 함수
ListNode *findNode(LinkedList *ll, int index) {
    ListNode *temp;

    // index가 유효하지 않으면 NULL 반환
    if (ll == NULL || index < 0 || index >= ll->size)
        return NULL;

    temp = ll->head; // 첫 노드부터 시작

    while (index > 0) {
        temp = temp->next; // 다음 노드로 이동
        index--;
    }

    return temp; // 찾은 노드 반환
}

// 리스트의 index 위치에 새 노드를 삽입하는 함수
int insertNode(LinkedList *ll, int index, int value) {
    ListNode *pre, *cur;

    // index가 유효하지 않으면 실패
    if (ll == NULL || index < 0 || index > ll->size)
        return -1;

    // 리스트가 비었거나, 첫 번째 위치에 삽입하는 경우
    if (ll->head == NULL || index == 0) {
        cur = ll->head;
        ll->head = malloc(sizeof(ListNode)); // 새 노드 메모리 할당
        ll->head->item = value; // 새 노드에 값 저장
        ll->head->next = cur; // 새 노드가 원래 첫 노드를 가리키게 설정
        ll->size++;
        return 0;
    }

    // 중간 또는 끝에 삽입하는 경우
    pre = findNode(ll, index - 1); // 삽입할 위치 바로 앞 노드 찾기
    if (pre != NULL) {
        cur = pre->next; // 현재 노드는 원래 pre 노드가 가리키던 노드
        pre->next = malloc(sizeof(ListNode)); // 새 노드 메모리 할당
        pre->next->item = value; // 새 노드에 값 저장
        pre->next->next = cur; // 새 노드가 원래 노드를 가리키게 설정
        ll->size++;
        return 0;
    }

    return -1; // 실패 시 -1 반환
}

// 리스트의 index 위치에 있는 노드를 삭제하는 함수
int removeNode(LinkedList *ll, int index) {
    ListNode *pre, *cur;

    // index가 유효하지 않으면 실패
    if (ll == NULL || index < 0 || index >= ll->size)
        return -1;

    // 첫 번째 노드를 삭제하는 경우
    if (index == 0) {
        cur = ll->head->next; // head 다음 노드를 임시 저장
        free(ll->head); // head 메모리 해제
        ll->head = cur; // head 포인터를 갱신
        ll->size--;
        return 0;
    }

    // 중간 또는 끝 노드를 삭제하는 경우
    pre = findNode(ll, index - 1); // 삭제할 노드 바로 앞 노드 찾기
    if (pre != NULL && pre->next != NULL) {
        cur = pre->next; // 삭제할 노드
        pre->next = cur->next; // 삭제할 노드를 건너뛰고 다음 노드로 연결
        free(cur); // 삭제할 노드 메모리 해제
        ll->size--;
        return 0;
    }

    return -1; // 실패 시 -1 반환
}
