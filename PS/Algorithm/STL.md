# 간단한 STL 사용법

## list

`<list>` 헤더파일을 사용  
`list<type> L` 비어있는 list 생성  
`list<type> L(10)` 0으로 초기화된 10칸짜리 list 생성  
`list<type> L(10, 2)` 2로 초기화된 10칸짜리 list 생성  
`list<type> L(L1)` L1을 L에 복사  
`L.assign(10, 2)` 2로 초기화된 10개의 원소 할당  
`L.insert(it, k)` it가 가리키는 위치 앞에 원소 k를 할당한다. 삽입한 원소를 가리키는 iterator를 반환  
`L.erase(it)` it가 가리키는 원소를 삭제한다. 삭제한 다음 원소를 가리키는 iterator를 반환  
`L.remove(k)` k와 같은 원소를 모두 제거  
`L.remove_if(Predicate)` 단항 조건자 Predicate에 해당하는 원소를 모두 제거  
`L.reverse()` 원소의 순서를 뒤집는다  
`L.sort()` 원소를 오름차순으로 정렬, 파라미터로 이항조건자가 올 수 있다  
`L.swap(L1)` L과 L1을 swap  
`L.splice(it, L1)` L의 it위치에 L1의 모든 원소를 잘라 붙인다. `L.splice(it, L1, it1)`, `L.splice(it, L1, it1_1, it1_2)`([it1_1, it1_2))으로 사용 가능  
`L.unique()` 인접한 원소가 같으면 하나만 빼고 모두 삭제  
`L.merge(L1)` L1을 L로 합병 정렬한다. 두번째 파라미터로 이항 조건자가 올 수 있다. L, L1은 정렬된 상태여야 한다.  

`front, back, begin, end, rbegin, rend, size`사용 가능  
`push_back, front`, `pop_back, front`사용 가능  