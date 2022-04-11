#include <stdio.h>

//배열은 인접한 메모리 위치에 저장된 같은 type의 항목 모음이다.
//배열의 첫 번째 요소의 메모리 위치에 오프셋을 추가하기만 하면 각 요소의 위치에 더 쉽게 접근할 수 있다.
//배열의 크기는 고정이다. 메모리에 정적으로 할당된다.
//장점 : 요소에 대해 위치별로 더 빠르게 접근할 수 있다.
//캐시지역성을 갖고 있어 성능 향상에 도움이 된다.
//단일 이름으로 동일한 유형의 여러 데이터 항목을 나타낸다.
//단점 : 정적 메모리에 할당되기 때문에 크기 변경이 불가하다.
//연속적인메모리 위치에 저장되 이동 작업에 비용이 많이 든다. 
//스택 구현시 POP연산에  결함이 존재한다.
//배열 애플리케이션 : 동일한 데이터 유형의 데이터 요소를 저장한다.
//CPU스케쥴링에 사용된다
//스택.힙. 해시테이블 등과 같은 다른 데이터 구조를 구현하는 데 사용된다.
int main()
{
 
    // Creating an integer array named arr of size 10.
    int arr[10];
    // accessing element at 0 index and setting its value
    // to 5.
    arr[0] = 5;
    // access and print value at 0 index we get the output
    // as 5.
    printf("%d", arr[0]);
 
    return 0;
}