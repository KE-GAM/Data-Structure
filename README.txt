/* ============================
 * Section A – Linked Lists
 * ============================ */

/*
 * 이 섹션의 문제 중 하나를 선택하여 코드 작성
 * APAS 시스템에 있는 템플릿을 사용해야 함
 */

/* ========================================
 * 1. insertSortedLL
 * ========================================
 * 사용자가 입력한 정수를 오름차순으로 연결 리스트에 삽입
 * 중복된 값은 삽입하지 않음
 * 삽입 성공 시: 삽입된 인덱스 반환
 * 실패 시: -1 반환
 *
 * 함수 원형:
 * int insertSortedLL(LinkedList *ll, int item);
 *
 * 예시:
 * 현재 리스트: 2, 3, 5, 7, 9
 * 입력: insertSortedLL(8)
 * 결과: 2, 3, 5, 7, 8, 9 → 반환: 4
 *
 * 메뉴:
 * 1: 정수 삽입
 * 2: 가장 최근 삽입값 인덱스 출력
 * 3: 리스트 출력
 * 0: 종료
 */

/* ========================================
 * 2. alternateMergeLL
 * ========================================
 * 두 리스트를 받아서 두 번째 리스트의 노드를 첫 번째 리스트에 교차 삽입
 * 첫 번째 리스트 자리가 다 차면, 두 번째 리스트 노드는 남을 수 있음
 *
 * 함수 원형:
 * void alternateMergeLL(LinkedList *ll1, LinkedList *ll2);
 *
 * 예시:
 * LinkedList1: 1, 2, 3
 * LinkedList2: 4, 5, 6, 7
 * 결과:
 * LinkedList1: 1, 4, 2, 5, 3, 6
 * LinkedList2: 7
 *
    while (cur != NULL) {
        if (cur->item == item)
            return -1;
        if (cur->item > item)
            break;
        cur = cur->next;
        index++;
    } 
 *
 *
 *
 *
 *
 */


/* ========================================
 * 3. moveOddItemsToBackLL
 * ========================================
 * 리스트에서 홀수 노드를 모두 뒤로 이동
 * 순서를 유지하면서 홀수 노드를 뒤로 정렬
 *
 * 함수 원형:
 * void moveOddItemsToBackLL(LinkedList *ll);
 *
 * 예시:
 * 입력: 2, 3, 4, 7, 15, 18
 * 결과: 2, 4, 18, 3, 7, 15
 */

/* ========================================
 * 4. moveEvenItemsToBackLL
 * ========================================
 * 리스트에서 짝수 노드를 모두 뒤로 이동
 * 순서를 유지하면서 짝수 노드를 뒤로 정렬
 *
 * 함수 원형:
 * void moveEvenItemsToBackLL(LinkedList *ll);
 *
 * 예시:
 * 입력: 2, 3, 4, 7, 15, 18
 * 결과: 3, 7, 15, 2, 4, 18
 */

/* ========================================
 * 5. frontBackSplitLL
 * ========================================
 * 리스트를 앞/뒤 두 개로 나누기
 * 원소 수가 홀수면 앞 리스트에 더 많은 원소를 배치
 * 결과: frontList, backList 출력
 *
 * 함수 원형:
 * void frontBackSplitLL(LinkedList *ll, LinkedList *resultFrontList, LinkedList *resultBackList);
 *
 * 예시:
 * 입력: 2, 3, 5, 6, 7
 * 결과:
 * frontList: 2, 3, 5
 * backList: 6, 7
 */

/* ========================================
 * 6. moveMaxToFront
 * ========================================
 * 리스트를 최대 한 번 순회하여 가장 큰 값의 노드를 맨 앞으로 이동
 *
 * 함수 원형:
 * int moveMaxToFront(ListNode **ptrHead);
 *
 * 예시:
 * 입력: 30, 20, 40, 70, 50
 * 결과: 70, 30, 20, 40, 50
 */

/* ========================================
 * 7. recursiveReverse
 * ========================================
 * 재귀함수를 사용하여 리스트를 뒤집음
 * 노드의 next 포인터와 헤드 포인터를 재설정
 *
 * 함수 원형:
 * void recursiveReverse(ListNode **ptrHead);
 *
 * 예시:
 * 입력: 1, 2, 3, 4, 5
 * 결과: 5, 4, 3, 2, 1
 */

/* ========================================
 * 요약 정리
 * ========================================
 * 1. insertSortedLL           → 정렬 삽입, 인덱스 반환
 * 2. alternateMergeLL         → 두 리스트 교차 병합
 * 3. moveOddItemsToBackLL     → 홀수 노드 뒤로 이동
 * 4. moveEvenItemsToBackLL    → 짝수 노드 뒤로 이동
 * 5. frontBackSplitLL         → 리스트 앞/뒤 나누기
 * 6. moveMaxToFront           → 최대값 노드 맨 앞으로
 * 7. recursiveReverse         → 리스트 재귀 뒤집기
 */
