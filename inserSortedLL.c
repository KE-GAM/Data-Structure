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



// 1. insertSortedLL
//    요구사항
//   	사용자가 정수를 입력하면, 오름차순으로 연결 리스트에 삽입하는 함수
// 	    중복 값은 삽입하지 않음
//  	성공 시 삽입된 인덱스 반환
// 	    실패 시 -1 반환

int insertSortedLL(LinkedList *ll, int item) {
    ListNode *cur = ll->head; // 현재 노드를 가리키는 포인터
    int index = 0; // 삽입할 위치를 저장하는 변수

    // 리스트 순회하면서 적절한 삽입 위치 찾기
    while (cur != NULL) {
        if (cur->item == item) // 중복 값 있으면 실패
            return -1;
        if (cur->item > item) // 현재 값이 삽입할 값보다 크면 삽입 위치 발견
            break;
        cur = cur->next;
        index++;
    }

    // 찾은 위치에 새 노드 삽입
    if (insertNode(ll, index, item) == 0)
        return index; // 성공하면 삽입한 인덱스 반환
    else
        return -1; // 실패하면 -1 반환
}
